#include "bmp_import.h"
#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "../Configuration Of Matrices/RelationshipMethods.h"


double** import_bmp(char* path) {
    FILE* fp = fopen(path, "rb");
    //If path is wrong
    if (fp == NULL) {
        exit(EXIT_FAILURE);
    }

    fseek(fp, 0, SEEK_END);
    int size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char bmp[size];
    fread(&bmp, size, 1, fp);

    //If not bitmap, then it's problematic
    if (bmp[0] != 'B' && bmp[1] != 'M') {
        exit(EXIT_FAILURE);
    }

    int pixel_data_offset = (int)bmp[10];

    //If bitmap header size is not 40 then it's a different kind of bitmap
    if (bmp[14] != 40) {
        exit(EXIT_FAILURE);
    }

    int width = *(int*)&bmp[18];
    int height = *(int*)&bmp[22];
    int bits_per_pixel = (short)bmp[28];
    //If bitmap is not uncompressed then its problematic
    if (bmp[30] != 0) {
        exit(EXIT_FAILURE);
    }

    //Fills array of pixels
    double** pixels = CreateDynamicMatrix(width);

    int row_size = (int)ceil(((double)(bits_per_pixel * width) / 32)) * 4;
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            char value = bmp[pixel_data_offset + i * row_size + j/2];
            char masked_value = value & 0b00001111;
            double final_value = (double)masked_value / 15;
            pixels[j][i] = final_value;
        }
    }

    return pixels;
}