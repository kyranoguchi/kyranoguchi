//
//  BruinCard.h
//  project 5
//
//  Created by Kyra Noguchi on 2/27/23.
//

#ifndef BruinCard_h
#define BruinCard_h

#include "Enums.h"
#include "MealPlan.h"

class BruinCard
{
public:
    //constructor
    BruinCard();
    
    void purchaseMealPlan(MealPlan plan);
    bool hasPurchasedMealPlan();
    plan getPlan();
    
    bool eat(meal m);
    
    void startQuarter();
    void newWeek();
    void newDay();
    int mealsLeftThisWeek();
    
private:
    MealPlan mPlan;
    bool mBoughtAMealPlan;
    
    bool hasEatenBreakfast;
    bool hasEatenLunch;
    bool hasEatenDinner;
    bool hasEatenBrunch;
    
    int howManyMealsLeft;
    
};
#endif /* BruinCard_h */
