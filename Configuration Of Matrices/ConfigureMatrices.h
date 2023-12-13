//
// Created by thoma on 05/12/2023.
//

#include "../Databehandling/userPreferences.h"

#ifndef P1_PROJECT_CONFIGUREMATRICES_H
#define P1_PROJECT_CONFIGUREMATRICES_H

/// What type is the matrix? (mine, road, soil, steepness, vegetation, water)
typedef enum {mine, road, soil, steepness, vegetation, water} matrix_type;

/// A data container, with a matrix, the matrix type and its weight
typedef struct{
    matrix_type type;
    double** matrix;
    double weight;
} weighted_matrix;

/// A data container,
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
void create_slope_map(slope_struct** slopeMap, double** heightMap, userSettings *settings);

/// Pre-analysis configuration of watermap to account for user parameters
///
/// Parameters:
/// \param waterMap (struct) is a matrix pointer and dimension values.
/// \param settings (struct) is only used for the passable value in question with the map.
void configure_depth_map(double** waterMap, double** road_map, userSettings *settings);

/// Checks for unacceptable mine chances
///
/// Parameters:
/// \param mineMap (struct) is a matrix pointer and dimension values.
/// \param settings (struct) is only used for the acceptable value in question with the map.
void configure_mine_map(double** mineMap, userSettings *settings);

/// Combines technical mine maps from multiple sources.
/// Exclusively for use with high reliability sources.
/// \param mineMap Pointer to array for outputting the final combined values
/// \param mineMaps Array containing pointers to all relevant mine arrays
/// \param map_count Amount of maps, for iteration
/// \param settings Pointer to struct with global user settings
void combine_mine_maps(double** mineMap, double*** mineMaps, int map_count, userSettings *settings);

/// Checks for acceptable amount of vegitation
///
/// Parameters:
/// \param vegetationMap (struct) is a matrix pointer and dimension values.
/// \param settings (struct) is only used for the acceptable value in question with the map.
void configure_soil_map(double** soilMap, userSettings *settings);

/// Checks for acceptable road quality
///
/// Parameters:
/// \param roadQualityMap (struct) is a matrix pointer and dimension values.
/// \param settings (struct) is only used for the acceptable value in question with the map.
void configure_vegetation_map(double** vegetationMap, userSettings *settings);

/// Configures matrix for acceptable road traversal
///
/// \param roadQualityMap pointer to roadQuality matrix
/// \param settings pointer to primary settings structs
void configure_road_quality_map(double** roadQualityMap, userSettings *settings);

/// Configures matrix for known enemy activity
///
/// \param enemyActivityMap pointer to matrix containing enemy activity values
/// \param settings pointer to settings struct
void configure_enemy_activity_map(double** enemyActivityMap, userSettings *settings);

/// Parent function to configure all matrices assuming they were formed using the appropriate function.
/// \param list_of_matrices (double***), the list of matrices.
/// \param settings (struct*), a reference to access the settings.
/// \return (struct*), a reference to the configured matrices.
weighted_matrix* configure_list_of_matrices(double*** list_of_matrices, userSettings *settings);


#endif //P1_PROJECT_CONFIGUREMATRICES_H
