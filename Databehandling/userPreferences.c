//
// Created by Andreas Lynnerup on 27/11/2023.
//

#include <stdio.h>
#include "userPreferences.h"

userSettings chosenSettings;

// Ask user to decide settings, then return the settings.
userSettings obtain_user_settings() {
    printf("\nPlease decide setup parameters");
    printf("\nDecide the following 4 settings:\n");
    printf("\n1. Should water be passable?");
    printf("\n2. Which troop type should maneuver?");
    printf("\n3. How much risk is acceptable?");
    printf("\n4. Should cover be prioritized?\n");

    printf("\n1. Should water be passable? ('1' = yes  |  '0' = no )\n");
    scanf("%d", &chosenSettings.isWaterPassable);
    printf("You have chosen to make isWaterPassable %s", stringIsWaterPassable[chosenSettings.isWaterPassable]);

    printf("\n2. Which troop type should maneuver? ('0' = Squad  |  '1' = Company  |  '2' = Logistic unit  |  '3' = Armor unit )\n");
    scanf("%d", &chosenSettings.troopType);
    printf("You have choosen %s as the troop type", stringTroopType[chosenSettings.troopType]);

    printf("\n3. How much risk is acceptable? ('0' = Low risk  |  '1' = Medium risk  |  '2' = High risk )\n");
    scanf("%d", &chosenSettings.riskLevel);
    printf("You have chosen a %s risk level", stringRiskLevel[chosenSettings.riskLevel]);

    printf("\n4. Should cover be prioritized? ('1' = yes  |  '0' = no )\n");
    scanf("%d", &chosenSettings.prioritizeCover);
    printf("You have chosen to make cover prioritization %s\n", stringPrioritizeCover[chosenSettings.prioritizeCover]);

    printf("\nYour chosen settings are: \n");
    printf("1. Is water passable:   %s\n", stringIsWaterPassable[chosenSettings.isWaterPassable]);
    printf("2. Troop type:      :   %s\n", stringTroopType[chosenSettings.troopType]);
    printf("3. Risk level:          %s\n", stringRiskLevel[chosenSettings.riskLevel]);
    printf("4. Prioritize cover:    %s\n", stringPrioritizeCover[chosenSettings.prioritizeCover]);

    return (chosenSettings);
}