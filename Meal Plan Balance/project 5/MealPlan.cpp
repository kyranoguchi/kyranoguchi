//
//  MealPlan.cpp
//  project 5
//
//  Created by Kyra Noguchi on 2/28/23.
//

#include "MealPlan.h"
#include "Enums.h"

//constructor
MealPlan::MealPlan()
{

}

//setter
void MealPlan::pickPlan(plan p)
{
    mPlan = p;
}

//getter
plan MealPlan::getPlan()
{
    return(mPlan);
}

double MealPlan::cost()
{
    double cost = 0.00; //initialize cost to 0 (would be 0 if no plan is purchased)
    //set the cost of each plan too variable cost
    switch(mPlan)
    {
        case REGULAR11:
            cost = 4646.64;
            break;
        case PREMIER11:
            cost =  5018.28;
            break;
        case REGULAR14:
            cost = 5107.20;
            break;
        case PREMIER14:
            cost = 5570.04;
            break;
        case REGULAR19:
            cost = 5278.20;
            break;
        case PREMIER19:
            cost = 5898.20;
            break;
    }
    return(cost);
}

int MealPlan::mealsEachWeek()
{
    int weekly = 0;
    //initialize the amount of meals each plan has each week
    switch(mPlan)
    {
        case REGULAR11:
            weekly = 11;
            break;
        case PREMIER11:
            weekly = 11;
            break;
        case REGULAR14:
            weekly = 14;
            break;
        case PREMIER14:
            weekly = 14;
            break;
        case REGULAR19:
            weekly = 19;
            break;
        case PREMIER19:
            weekly = 19;
            break;
    }
    return(weekly);
}

bool MealPlan::unusedMealsCarryOver()
{
    bool carryOver = false;
    //initialize whether the plan carries over the meals to the next week (true for premier plans, false for regular plans)
    switch(mPlan)
    {
        case REGULAR11:
            carryOver = false;
            break;
        case PREMIER11:
            carryOver = true;
            break;
        case REGULAR14:
            carryOver = false;
            break;
        case PREMIER14:
            carryOver = true;
            break;
        case REGULAR19:
            carryOver = false;
            break;
        case PREMIER19:
            carryOver = true;
            break;
    }
    return(carryOver);
}
