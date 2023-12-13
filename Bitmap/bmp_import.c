#include "bmp_import.h"

//The specific locations of values in the bitmap can be found at: (https://en.wikipedia.org/wiki/BMP_file_format)
double** import_bmp(char* path) {
    //Opens the file, with read binary parameter
    FILE* filePointer = fopen(path, "rb");
    
    //Exit with failure if the file opening failed
    if (filePointer == NULL) {
        exit(EXIT_FAILURE);
    }
    
    //Get the size of the file
    int fileSize = get_file_size(filePointer);
    
    //Make char(size of 1 byte) array to store the file and write the file into the array
    char bmp[fileSize];
    fread(&bmp, fileSize, 1, filePointer);

    //Checks that the bitmap is supported for the function
    check_bmp_supported(bmp);

    //Get the pixel data offset from the 10-14 bytes in the bmp and the width, height and bits per pixel from the
    //different locations in the bmp
    int pixelDataOffset = (int)bmp[10];
    int width = (int)bmp[18];
    int height = (int)bmp[22];
    int bitsPerPixel = (short)bmp[28];

    //Uses other function to create a matrix that follows the standard for this project, which will store the 0-1 values
    //given the strength of the color for each pixel in the bitmap
    double** pixelColorStrengthNormalizedArray = create_dynamic_matrix(width);

    //Calculates the size of the rows in the pixel storage part of the bitmap, there is often padding at the end of rows
    int rowSize = (int)ceil(((double)(bitsPerPixel * width) / 32)) * 4;

    //Get color table
    unsigned char colorTable[64]; //16 times 4 bytes for red, green, blue and alpha
    for (int i = 0; i < 64; ++i) {
        colorTable[i] = bmp[54 + i]; //Byte 54 is the start of color table
    }

    //Loop over each pixel
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            //Gets a byte from the specific pixel location
            char indexValue = bmp[pixelDataOffset + i * rowSize + j/2];

            //Gets the index of the pixel, so we can map it to the correct color
            int maskedIndexValue = indexValue & 0x0F;

            //Calculate normalised value from one of the color chanels of the pixel, given by the index
            //(only one chanel is needed since input is black and white so RGB are all the same)
            double finalValue = (double)colorTable[maskedIndexValue*4] / 255;

            //Save the value in the array
            pixelColorStrengthNormalizedArray[j][i] = finalValue;
        }
    }

    //Returns the extracted matrix from the bitmap
    return pixelColorStrengthNormalizedArray;
}

//Checks whether the bitmap is supported or not
void check_bmp_supported(const char* bmp) {
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

//Get the size of a file and reset the file pointer to the beginning of the file
int get_file_size(FILE* filePointer) {
    //Sets the positions to the end of the file
    fseek(filePointer, 0, SEEK_END);

    //Gets the position of the end of the file, which also is the total size
    int size = ftell(filePointer);

    //Sets the reading position back to the beginning of the file
    fseek(filePointer, 0, SEEK_SET);

    //Returns the size of the file
    return size;
}