//
// Created by Andreas Lynnerup on 27/11/2023.
//

#ifndef PROJECT_USERPREFERENCES_H
#define PROJECT_USERPREFERENCES_H
#define NUMBER_OF_TROOP_SETTINGS 5

typedef enum {
    SquadUnit,     // 7-14 soldiers
    CompanyUnit,   // 100-250 soldiers
    LogisticUnit,  // Vehicles transporting troops, supplies and equipment
    ArmorUnit,     // Armored vehicles such as tanks
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
    double maxWaterDepth;
    double maxMineRisk;
    double maxSlope;
    double maxRoad;
    double maxTerrainDifficulty;
}troop_settings;

typedef struct {
    // other settings
    int size;
}additional_settings;

typedef struct {
    // risk road_weight;
    risk mineRisk;
    // risk vegetation_weight;
} priorities;

typedef struct {
    troop_settings troopSettings;
    priorities priorityLevel;
    additional_settings additionalSettings;
} userSettings;

userSettings obtain_user_settings();

void add_troop_settings(userSettings *chosenSettings, int troopType);

#endif //PROJECT_USERPREFERENCES_H
