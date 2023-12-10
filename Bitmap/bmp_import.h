#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "../Configuration Of Matrices/RelationshipMethods.h"

double** import_bmp(char* path);
int get_file_size(FILE* file_pointer);
void check_bmp_unsupported(const char* bmp);
