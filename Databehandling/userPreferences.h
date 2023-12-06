//
// Created by Andreas Lynnerup on 27/11/2023.
//

#ifndef PROJECT_USERPREFERENCES_H
#define PROJECT_USERPREFERENCES_H
#define NUMBER_OF_TROOP_SETTINGS 5

typedef enum {
    Squad_Unit,     // 7-14 soldiers
    Company_Unit,   // 100-250 soldiers
    Logistic_Unit,  // Vehicles transporting troops, supplies and equipment
    Armor_Unit,     // Armored vehicles such as tanks
} troop;

typedef enum {
    Low,
    Medium,
    High
} risk;

typedef enum {
    none,
    MICLIC,
    Plow,
    Rafael,
} clearing_implement;

typedef struct {
    double max_water_depth;
    double max_mine_risk;
    double max_slope;
    double max_road;
    double max_terrain_difficulty;
}troop_settings;

typedef struct {
    int is_cover_prioritized;
    clearing_implement clearing_implement;
    int size;
}additional_settings;

typedef struct {
    // risk road_weight;
    risk mine_risk;
    // risk vegetation_weight;
} priorities;

typedef struct {
    troop_settings troop_settings;
    priorities priority_level;
    additional_settings additional_settings;
} userSettings;

userSettings obtain_user_settings();

void add_troop_settings(userSettings *chosenSettings, int troop_type);

#endif //PROJECT_USERPREFERENCES_H
