//
// Created by thoma on 05/12/2023.
//

#include "../Databehandling/userPreferences.h"

#ifndef P1_PROJECT_CONFIGUREMATRICES_H
#define P1_PROJECT_CONFIGUREMATRICES_H

typedef enum {mine, road, soil, steepness, vegetation, water} matrix_type;

typedef struct{
    matrix_type type;
    double** matrix;
    double weight;
} WeightedMatrix;

/// Checks for impassable slopes
///
/// Parameters:
/// slopeMap (struct) is a matrix pointer and dimension values.
/// settings (struct) is only used for the passable value in question with the map.
void ConfigureSlopeMap(int** slopeMap, userSettings *settings);

/// Checks for impassable water depth
///
/// Parameters:
/// waterMap (struct) is a matrix pointer and dimension values.
/// settings (struct) is only used for the passable value in question with the map.
void ConfigureWaterMap(int** waterMap, userSettings *settings);

/// Checks for unacceptable mine chances
///
/// Parameters:
/// mineMap (struct) is a matrix pointer and dimension values.
/// settings (struct) is only used for the acceptable value in question with the map.
void ConfigureMineMap(int** mineMap, userSettings *settings);

/// Checks for acceptable amount of vegitation
///
/// Parameters:
/// vegetationMap (struct) is a matrix pointer and dimension values.
/// settings (struct) is only used for the acceptable value in question with the map.
void ConfigureSoilMap(int** soilMap, userSettings *settings);

/// Checks for acceptable road quality
///
/// Parameters:
/// roadQualityMap (struct) is a matrix pointer and dimension values.
/// settings (struct) is only used for the acceptable value in question with the map.
void ConfigureVegetationMap(int** vegetationMap, userSettings *settings);

/// Configures matrix for acceptable road traversal
///
/// \param roadQualityMap pointer to roadQuality matrix
/// \param settings pointer to primary settings structs
void ConfigureRoadQualityMap(int** roadQualityMap, userSettings *settings);

/// Configures matrix for known enemy activity
///
/// \param enemyActivityMap pointer to matrix containing enemy activity values
/// \param settings pointer to settings struct
void ConfigureEnemyActivityMap(int** enemyActivityMap, userSettings *settings);


#endif //P1_PROJECT_CONFIGUREMATRICES_H
