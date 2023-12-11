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

typedef struct {
    double altitude;
    double northward_slope;
    double eastward_slope;
    double southward_slope;
    double westward_slope;
    double steepest_slope;
} slope_struct;

/// Creates slope values from heightmap
///
/// \param slopeMap pointer to 2D array to be filled by function
/// \param heightMap pointer to 2D array containing altitude values
/// \param settings pointer to struct array containing global user settings
/// \return returns a 1 on success
void CreateSlopeMap(slope_struct** slopeMap, double** heightMap, userSettings *settings);

/// Pre-analysis configuration of watermap to account for user parameters
///
/// Parameters:
/// \param waterMap (struct) is a matrix pointer and dimension values.
/// \param settings (struct) is only used for the passable value in question with the map.
/// \return returns a 1 on success
void ConfigureDepthMap(double** waterMap, double** road_map, userSettings *settings);

/// Checks for unacceptable mine chances
///
/// Parameters:
/// \param mineMap (struct) is a matrix pointer and dimension values.
/// \param settings (struct) is only used for the acceptable value in question with the map.
void ConfigureMineMap(double** mineMap, userSettings *settings);

/// Combines technical mine maps from multiple sources.
/// Exclusively for use with high reliability sources.
/// \param mineMap Pointer to array for outputting the final combined values
/// \param mineMaps Array containing pointers to all relevant mine arrays
/// \param map_count Amount of maps, for iteration
/// \param settings Pointer to struct with global user settings
/// \return Returns 1 on success
void CombineMineMaps(double** mineMap, double*** mineMaps, int map_count, userSettings *settings);

/// Checks for acceptable amount of vegitation
///
/// Parameters:
/// \param vegetationMap (struct) is a matrix pointer and dimension values.
/// \param settings (struct) is only used for the acceptable value in question with the map.
void ConfigureSoilMap(double** soilMap, userSettings *settings);

/// Checks for acceptable road quality
///
/// Parameters:
/// \param roadQualityMap (struct) is a matrix pointer and dimension values.
/// \param settings (struct) is only used for the acceptable value in question with the map.
void ConfigureVegetationMap(double** vegetationMap, userSettings *settings);

/// Configures matrix for acceptable road traversal
///
/// \param roadQualityMap pointer to roadQuality matrix
/// \param settings pointer to primary settings structs
void ConfigureRoadQualityMap(double** roadQualityMap, userSettings *settings);

/// Configures matrix for known enemy activity
///
/// \param enemyActivityMap pointer to matrix containing enemy activity values
/// \param settings pointer to settings struct
void ConfigureEnemyActivityMap(double** enemyActivityMap, userSettings *settings);


WeightedMatrix* ConfigureListOfMatrices(double*** list_of_matrices, userSettings *settings);


#endif //P1_PROJECT_CONFIGUREMATRICES_H
