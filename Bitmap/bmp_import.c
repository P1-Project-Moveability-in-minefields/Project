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
    int pixelDataOffset = (int)bmp[OFFSET_OF_PIXEL_DATA];
    int width = (int)bmp[OFFSET_OF_WIDTH];
    int height = (int)bmp[OFFSET_OF_HEIGHT];
    int bitsPerPixel = (short)bmp[OFFSET_OF_BITS_PER_PIXEL];
    int colorTableSize = (int)bmp[OFFSET_OF_COLOR_TABLE_SIZE] * 4; //Because 4 bytes for each color

    //Uses other function to create a matrix that follows the standard for this project, which will store the 0-1 values
    //given the strength of the color for each pixel in the bitmap
    double** pixelColorStrengthNormalizedArray = create_dynamic_matrix(width);

    //Calculates the size of the rows in the pixel storage part of the bitmap, there is often padding at the end of rows
    int rowSize = (int)ceil(((double)(bitsPerPixel * width) / 32)) * 4;

    //Get color table
    unsigned char colorTable[colorTableSize]; //16 times 4 bytes for red, green, blue and alpha
    for (int i = 0; i < colorTableSize; ++i) {
        colorTable[i] = bmp[OFFSET_OF_COLOR_TABLE + i]; //Byte 54 is the start of color table
    }

    //Loop over each pixel
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            //Gets a byte from the specific pixel location
            char indexValue = bmp[pixelDataOffset + i * rowSize + j/2];

            //Gets the index of the pixel, so we can map it to the correct color
            int maskedIndexValue = indexValue & NIBBLE_MASK;

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
    if ((short)bmp[OFFSET_OF_FILETYPE_VALUE] == SUPPORTED_FILETYPE_VALUE) {
        printf("\nUnsupported filetype");
        exit(EXIT_FAILURE);
    }

    //Exit with failure if bitmap header is not 40 bytes and therefore a bmp we don't support
    if (bmp[OFFSET_OF_HEADER_SIZE] != SUPPORTED_HEADER_SIZE) {
        printf("\nUnsupported header size");
        exit(EXIT_FAILURE);
    }

    //Exit with failure if bitmap is not stored with 4 bits per pixel, because we don't support that
    if ((short)bmp[OFFSET_OF_BITS_PER_PIXEL] != SUPPORTED_BITS_PER_PIXEL) {
        printf("\nUnsupported bpp");
        exit(EXIT_FAILURE);
    }

    //Exit with failure if bitmap is not uncompressed, because we don't support that
    if (bmp[OFFSET_OF_COMPRESSION] != SUPPORTED_COMPRESSION_TYPE) {
        printf("\nUnsupported compression");
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