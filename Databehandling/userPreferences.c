#include <stdio.h>
#include "userPreferences.h"

// Strings matching to enum values
const char* stringIsWaterPassable[] = {"False", "True"};
const char* stringTroopType[] = {"Squad unit", "Company unit", "Logistic unit", "Armor unit"};
const char* stringRiskLevel[] = {"Low", "Medium", "High"};
const char* stringPrioritizeCover[] = {"False", "True"};
const char* stringClearanceType[] = {"none","MICLIC","Plow","Rafael"};

double SQUAD_UNIT_SETTINGS[NUMBER_OF_TROOP_SETTINGS] = {0.5, 0.9, 0.2, 0.1, 0.5};
double COMPANY_UNIT[NUMBER_OF_TROOP_SETTINGS]        = {0.5, 0.9, 0.2, 0.1, 0.5};
double LOGISTIC_UNIT[NUMBER_OF_TROOP_SETTINGS]       = {0.5, 0.9, 0.2, 0.1, 0.5};
double ARMOR_UNIT[NUMBER_OF_TROOP_SETTINGS]          = {0.5, 0.9, 0.2, 0.1, 0.5};


// Ask user to decide settings, then return the settings.
userSettings obtain_user_settings() {
    userSettings chosenSettings;

    printf("\nPlease decide setup parameters");
    printf("\nDecide the following 4 settings:\n");
    printf("\n1. Which troop type should maneuver?");
    printf("\n2. How much risk is acceptable?");
    /*printf("\n3. Priority of roads");
    printf("\n4. Priority of terrain");
    printf("\n5. Should cover be prioritized?");*/
    printf("\n6. Which kinds of clearance implements are desired for usage?");
    printf("\n7. Size of matrices?\n");

    //1st setting
    printf("\n1. Which troop type should maneuver? ('0' = Squad  |  '1' = Company  |  '2' = Logistic unit  |  '3' = Armor unit )\n");
    int troop_type;
    scanf("%d", &troop_type);
    add_troop_settings(&chosenSettings, troop_type);
    printf("You have choosen %s as the troop type", stringTroopType[troop_type]);

    //2nd setting
    printf("\n2. How much risk is acceptable? ('0' = Low risk  |  '1' = Medium risk  |  '2' = High risk )\n");
    scanf("%d", &chosenSettings.weights.mine_weight);
    printf("You have chosen a %s risk level", stringRiskLevel[chosenSettings.weights.mine_weight]);

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
    */

    //6th setting
    printf("\n6. Specify available and desired clearance method: ('0' = None '1' = MICLIC, '2' = Vehicle mounted plow, '3' = Rafael Missile Carpet System");
    scanf("%d",&chosenSettings.additional_settings.clearing_implement);
    printf("You have specified the availability of clearance method %s\n", stringClearanceType[chosenSettings.additional_settings.clearing_implement]);

    printf("\n7. What is the size of the input matrices?\n");
    scanf("%d",&chosenSettings.additional_settings.size);

    printf("\nYour chosen settings are: \n");
    printf("1. Troop type:          %s\n", stringTroopType[troop_type]);
    printf("2. Risk level:          %s\n", stringRiskLevel[chosenSettings.weights.mine_weight]);
    // printf("3. Road priority:       %s\n", stringRiskLevel[chosenSettings.additional_settings.is_cover_prioritized]);
    // printf("4. Terrain priority:    %s\n", stringRiskLevel[chosenSettings.weights.vegetation_weight]);
    // printf("5. Prioritize cover:    %s\n", stringPrioritizeCover[chosenSettings.additional_settings.is_cover_prioritized]);
    printf("6. Clearance method:    %s\n", stringClearanceType[chosenSettings.additional_settings.clearing_implement]);
    printf("7. Size of matrices:    %dx%d\n", chosenSettings.additional_settings.size,chosenSettings.additional_settings.size);
    return (chosenSettings);
}

void add_troop_settings(userSettings *settings, int troop_type){
    double *current_troop_settings = NULL;
    if(troop_type == Squad_Unit){
        current_troop_settings = SQUAD_UNIT_SETTINGS;
    } else if(troop_type == Company_Unit){
        current_troop_settings = COMPANY_UNIT;
    } else if(troop_type == Logistic_Unit){
        current_troop_settings = LOGISTIC_UNIT;
    } else if(troop_type == Armor_Unit){
        current_troop_settings = ARMOR_UNIT;
    } else printf("Invalid troop type!");

    settings->troop_settings.max_water_depth = current_troop_settings[0];
    settings->troop_settings.max_mine_risk = current_troop_settings[1];
    settings->troop_settings.max_road = current_troop_settings[2];
    settings->troop_settings.max_slope = current_troop_settings[3];
    settings->troop_settings.max_terrain_difficulty = current_troop_settings[4];
}