#include <stdio.h>
//#include "Dijkstra's algorithm/dijkstra.h"
//#include "Databehandling/userPreferences.h"
//#include "Configuration Of Matrices/RelationshipMethods.h"
#include "Visualization/exportMatrixToFile.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {

    // double number = 0x9d;
    //printf("%lf", number);
    // userSettings settings = obtain_user_settings();
    double terrain[50][50];
    srand((unsigned int)time(NULL)); // Seed for random numbers

    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 50; j++) {
            terrain[i][j] = ((double)rand() / RAND_MAX); // values between 0 and 1
        }
    }

    exportMatrixToFile(terrain);

    return 0;
}













