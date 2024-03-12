//
//  MealPlan.h
//  project 5
//
//  Created by Kyra Noguchi on 2/27/23.
//

#ifndef MealPlan_h
#define MealPlan_h
#include "Enums.h"

// define the class MealPlan

class MealPlan
{
public:
    //constructor
    MealPlan();
    
    void pickPlan(plan p);
    plan getPlan();
    double cost();
    int mealsEachWeek();
    bool unusedMealsCarryOver();

private:
    plan mPlan;
};



#endif /* MealPlan_h */
