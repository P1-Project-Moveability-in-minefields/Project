//
// Created by Andreas Lynnerup on 27/11/2023.
//

#ifndef PROJECT_USERPREFERENCES_H
#define PROJECT_USERPREFERENCES_H

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

typedef struct {
    int isWaterPassable; // 1 = yes, 0 = no
    troop troopType;
    risk riskLevel;
    int prioritizeCover; // 1 = yes, 0 = no

} userSettings;

// Strings matching to enum values
const char* stringIsWaterPassable[] = {"False", "True"};
const char* stringTroopType[] = {"Squad unit", "Company unit", "Logistic unit", "Armor unit"};
const char* stringRiskLevel[] = {"Low", "Medium", "High"};
const char* stringPrioritizeCover[] = {"False", "True"};



#endif //PROJECT_USERPREFERENCES_H
