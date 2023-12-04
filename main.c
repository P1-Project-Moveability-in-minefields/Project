#include <stdio.h>
#include "Dijkstra's algorithm/dijkstra.h"
#include "Databehandling/userPreferences.h"
#include "Relationship Methods/RelationshipMethods.h"


int main() {

    obtain_user_settings();





    // En matrix (3x3) som et eksempel, bare et for at teste jeg satte den her ind.
    int myMatrix[ROWS][COLS] = {
            {1, 2, 2},
            {2, 4, 1},
            {1, 4, 2}
    };

    printf("Originale matrix:\n");
    printMatrix(myMatrix);

    processMatrix(myMatrix);

    printf("\nDen nye Matrix:\n");
    printMatrix(myMatrix);

    return 0;
}













