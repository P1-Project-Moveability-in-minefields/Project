#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "../Configuration Of Matrices/RelationshipMethods.h"

//The offset of values in the bitmap file type
#define OFFSET_OF_FILETYPE_VALUE 0
#define OFFSET_OF_PIXEL_DATA 10
#define OFFSET_OF_HEADER_SIZE 14
#define OFFSET_OF_WIDTH 18
#define OFFSET_OF_HEIGHT 22
#define OFFSET_OF_BITS_PER_PIXEL 28
#define OFFSET_OF_COMPRESSION 30
#define OFFSET_OF_COLOR_TABLE_SIZE 46
#define OFFSET_OF_COLOR_TABLE 54

//Values we support
#define SUPPORTED_FILETYPE_VALUE 0x424D
#define SUPPORTED_HEADER_SIZE 40
#define SUPPORTED_BITS_PER_PIXEL 4
#define SUPPORTED_COMPRESSION_TYPE 0

//Mask
#define NIBBLE_MASK 0x0F

//Prototypes
double** import_bmp(char* path);
int get_file_size(FILE* file_pointer);
void check_bmp_supported(const char* bmp);
