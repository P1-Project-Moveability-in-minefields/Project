#include <stdio.h>
#include "userPreferences.h"

// Strings matching to enum values
const char* stringIsWaterPassable[] = {"False", "True"};
const char* stringTroopType[] = {"Squad unit", "Company unit", "Logistic unit", "Armor unit"};
const char* stringRiskLevel[] = {"Low", "Medium", "High"};
const char* stringPrioritizeCover[] = {"False", "True"};
const char* stringClearanceType[] = {"none","MICLIC","Plow","Rafael"};

double squadUnitSettings[NUMBER_OF_TROOP_SETTINGS] = {0.5, 0, 1, 1, 1};
double companyUnitSettings[NUMBER_OF_TROOP_SETTINGS]        = {0.95, 1, 1, 1, 0.9};
double logisticUnitSettings[NUMBER_OF_TROOP_SETTINGS]       = {1, 1, 1, 1, 1};
double armorUnitSettings[NUMBER_OF_TROOP_SETTINGS]          = {1, 1, 1, 1, 1};


// Ask user to decide settings, then return the settings.
userSettings obtain_user_settings() {
    userSettings chosenSettings;

    printf("\nPlease decide setup parameters");
    printf("\nDecide the following 3 settings:\n");
    printf("\n1. Which troop type should maneuver?");
    printf("\n2. How much risk is acceptable?");
    /*printf("\n3. Priority of roads");
    printf("\n4. Priority of terrain");
    printf("\n5. Should cover be prioritized?");
    printf("\n6. Which kinds of clearance implements are desired for usage?");*/
    printf("\n3. Size of matrices?\n");

    //1st setting
    printf("\n1. Which troop type should maneuver? ('0' = Squad  |  '1' = Company  |  '2' = Logistic unit  |  '3' = Armor unit )\n");
    int troopType;
    scanf("%d", &troopType);
    add_troop_settings(&chosenSettings, troopType);
    printf("You have choosen %s as the troop type", stringTroopType[troopType]);

    //2nd setting
    printf("\n2. How much risk is acceptable? ('0' = Low risk  |  '1' = Medium risk  |  '2' = High risk )\n");
    scanf("%d", &chosenSettings.priorityLevel.mineRisk);
    printf("You have chosen a %s risk level", stringRiskLevel[chosenSettings.priorityLevel.mineRisk]);

    /*3rd setting
    printf("\n3. Road priority? ('0' = Low  |  '1' = Medium  |  '2' = High )\n");
    scanf("%d", &chosenSettings.weights.road_weight);
    printf("You have chosen %s road priority",stringRiskLevel[chosenSettings.weights.road_weight]);

    //4th setting
    printf("\n4. Terrain priority? ('0' = Low |  '1' = Medium  |  '2' = High )\n");
    scanf("%d", &chosenSettings.weights.vegetation_weight);
    printf("You have chosen %s road priority",stringRiskLevel[chosenSettings.weights.vegetation_weight]);

    //5th setting
    printf("\n5. Should cover be prioritized? ('1' = yes  |  '0' = no )\n");
    scanf("%d", &chosenSettings.additional_settings.is_cover_prioritized);
    printf("You have chosen to make cover prioritization %s\n", stringPrioritizeCover[chosenSettings.additional_settings.is_cover_prioritized]);


    //6th setting
    printf("\n6. Specify available and desired clearance method: ('0' = None '1' = MICLIC, '2' = Vehicle mounted plow, '3' = Rafael Missile Carpet System\n");
    scanf("%d",&chosenSettings.additionalSettings.clearingImplement);
    printf("You have specified the availability of clearance method %s\n", stringClearanceType[chosenSettings.additionalSettings.clearingImplement]);
    */
    printf("\n3. What is the size of the input matrices?\n");
    scanf("%d",&chosenSettings.additionalSettings.size);

    printf("\nYour chosen settings are: \n");
    printf("1. Troop type:          %s\n", stringTroopType[troopType]);
    printf("2. Risk level:          %s\n", stringRiskLevel[chosenSettings.priorityLevel.mineRisk]);
    // printf("3. Road priority:       %s\n", stringRiskLevel[chosenSettings.additional_settings.is_cover_prioritized]);
    // printf("4. Terrain priority:    %s\n", stringRiskLevel[chosenSettings.weights.vegetation_weight]);
    // printf("5. Prioritize cover:    %s\n", stringPrioritizeCover[chosenSettings.additional_settings.is_cover_prioritized]);
    // printf("6. Clearance method:    %s\n", stringClearanceType[chosenSettings.additionalSettings.clearingImplement]);
    printf("3. Size of matrices:    %dx%d\n", chosenSettings.additionalSettings.size,chosenSettings.additionalSettings.size);
    return (chosenSettings);
}

void add_troop_settings(userSettings *settings, int troopType){
    double *currentTroopSettings = NULL;
    if(troopType == SquadUnit){
        currentTroopSettings = squadUnitSettings;
    } else if(troopType == CompanyUnit){
        currentTroopSettings = companyUnitSettings;
    } else if(troopType == LogisticUnit){
        currentTroopSettings = logisticUnitSettings;
    } else if(troopType == ArmorUnit){
        currentTroopSettings = armorUnitSettings;
    } else printf("Invalid troop type!");

    settings->troopSettings.maxWaterDepth = currentTroopSettings[0];
    settings->troopSettings.maxMineRisk = currentTroopSettings[1];
    settings->troopSettings.maxRoad = currentTroopSettings[2];
    settings->troopSettings.maxSlope = currentTroopSettings[3];
    settings->troopSettings.maxTerrainDifficulty = currentTroopSettings[4];
}