#include "bmp_import.h"
#include "stdio.h"
#include "stdlib.h"

int main() {
    return import_bmp();
}

int import_bmp() {
    FILE* fp = fopen("C:\\Users\\payth\\CLionProjects\\Project\\Bitmap\\Files\\roads_and_infrastructure.bmp", "r");

    fseek(fp, 0, SEEK_END);
    int size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char bmp[size];
    fread(&bmp, size, 1, fp);

    //If not bitmap, then it's problematic
    if (bmp[0] != 'B' && bmp[1] != 'M') {
        return EXIT_FAILURE;
    }

    //If bitmap header size is not 40 then it's a different kind of bitmap
    if (bmp[14] != 40) {
        return EXIT_FAILURE;
    }

    int width = (int)bmp[18];
    int height = (int)bmp[22];
    int bits_per_pixel = (short)bmp[28];

    //If bitmap is not uncompressed then its problematic
    if (bmp[30] != 0) {
        return EXIT_FAILURE;
    }

    //TODO: Get colors

    int size_of_pixel_data =
    for (int i = 0; i < ; ++i) {
        
    }

    return EXIT_SUCCESS;
}