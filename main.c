#include <stdio.h>
#include "Dijkstra's algorithm/dijkstra.h"
#include "Databehandling/userPreferences.h"
#include "Relationship Methods/RelationshipMethods.h"


int main() {
    // test af dijkstra
    int size = 4;
    int *input[size];
    int row0[] = {1,3,11,4};
    int row1[] = {7,60,40,6};
    int row2[] = {6,27,50,1};
    int row3[] = {30,6,7,5};
    input[0] = row0;
    input[1] = row1;
    input[2] = row2;
    input[3] = row3;

    int start_pos[2] = {3,0};
    int end_pos[2] = {3,3};

    result *optimal_path = dijkstra(input,size, start_pos,end_pos);

    for (int i = optimal_path->path_length-1; i >= 0; --i) {
        printf("(%d,%d)->",optimal_path->path[i][0], optimal_path->path[i][1]);
    }
    printf("Goal \n");
    printf("Path length = %d", optimal_path->path_length);


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













