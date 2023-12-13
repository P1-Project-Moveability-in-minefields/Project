#include "bmp_import.h"

//The specific locations of values in the bitmap can be found at: (https://en.wikipedia.org/wiki/BMP_file_format)
double** import_bmp(char* path) {
    //Opens the file, with read binary parameter
    FILE* file_pointer = fopen(path, "rb");
    
    //Exit with failure if the file opening failed
    if (file_pointer == NULL) {
        exit(EXIT_FAILURE);
    }
    
    //Get the size of the file
    int file_size = get_file_size(file_pointer);
    
    //Make char(size of 1 byte) array to store the file and write the file into the array
    char bmp[file_size];
    fread(&bmp, file_size, 1, file_pointer);

    //Checks that the bitmap is supported for the function
    check_bmp_unsupported(bmp);

    //Get the pixel data offset from the 10-14 bytes in the bmp
    int pixel_data_offset = (int)bmp[10];

    //Get the width, height and bits per pixel from the different locations in the bmp
    int width = *(int*)&bmp[18];
    int height = *(int*)&bmp[22];
    int bits_per_pixel = (short)bmp[28];

    //Uses other function to create a matrix that follows the standard for this project, which will store the 0-1 values
    //given the strength of the color for each pixel in the bitmap
    double** pixel_color_strength_normalised_array = create_dynamic_matrix(width);

    //Calculates the size of the rows in the pixel storage part of the bitmap, there is often padding at the end of rows
    int row_size = (int)ceil(((double)(bits_per_pixel * width) / 32)) * 4;

    //Get color table
    unsigned char color_table[64]; //16 times 4 bytes for red, green, blue and alpha
    for (int i = 0; i < 64; ++i) {
        color_table[i] = bmp[54 + i]; //Byte 54 is the start of color table
    }

    //Loop over each pixel
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            //Gets a byte from the specific pixel location
            char index_value = bmp[pixel_data_offset + i * row_size + j/2];
            //Gets the index of the pixel, so we can map it to the correct color
            int masked_index_value = index_value & 0x0F;
            //Calculate normalised value from one of the color chanels of the pixel, given by the index
            //(only one chanel is needed since input is black and white so RGB are all the same)
            double final_value = (double)color_table[masked_index_value*4] / 255;
            //Save the value in the array
            pixel_color_strength_normalised_array[j][i] = final_value;
        }
    }

    //Returns the extracted matrix from the bitmap
    return pixel_color_strength_normalised_array;
}

void check_bmp_unsupported(const char* bmp) {
    //Exit with failure if not a bitmap file
    if (bmp[0] != 'B' && bmp[1] != 'M') {
        exit(EXIT_FAILURE);
    }

    //Exit with failure if bitmap header is not 40 bytes and therefore a bmp we don't support
    if (bmp[14] != 40) {
        exit(EXIT_FAILURE);
    }

    //Exit with failure if bitmap is not stored with 4 bits per pixel, because we don't support that
    if ((short)bmp[28] != 4) {
        exit(EXIT_FAILURE);
    }

    //Exit with failure if bitmap is not uncompressed, because we don't support that
    if (bmp[30] != 0) {
        exit(EXIT_FAILURE);
    }
}

int get_file_size(FILE* file_pointer) {
    //Sets the positions to the end of the file
    fseek(file_pointer, 0, SEEK_END);

    //Gets the position of the end of the file, which also is the total size
    int size = ftell(file_pointer);

    //Sets the reading position back to the beginning of the file
    fseek(file_pointer, 0, SEEK_SET);

    //Returns the size of the file
    return size;
}