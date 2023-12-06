//
// Created by thoma on 05/12/2023.
//

#include "../Databehandling/userPreferences.h"

#ifndef P1_PROJECT_CONFIGUREMATRICES_H
#define P1_PROJECT_CONFIGUREMATRICES_H

typedef struct{
    double** matrix;
    double weight;
} WeightedMatrix;

typedef struct {
    double altitude;
    double northward_slope;
    double eastward_slope;
    double southward_slope;
    double westward_slope;
} slope_struct;

/// Creates slope values from heightmap
///
/// \param heightMap pointer to a 2D matrix containing altitude values
/// \param settings pointer to struct containing user settings
/// \return returns a 2d array of slope structs, featuring the slope in each cardinal direction
slope_struct* CreateSlopeMap(int** heightMap, userSettings *settings);

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
