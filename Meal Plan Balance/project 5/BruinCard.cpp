//
//  BruinCard.cpp
//  project 5
//
//  Created by Kyra Noguchi on 2/28/23.
//

#include "BruinCard.h"
#include "Enums.h"
#include "MealPlan.h"

//constructor
BruinCard::BruinCard()
{
    mBoughtAMealPlan = false;
}


//modifiers
//setter
void BruinCard::purchaseMealPlan(MealPlan plan)
{
    mPlan = plan;
    //check if a meal plan was selected
    switch(mPlan.getPlan())
    {
            case REGULAR11:
                mBoughtAMealPlan = true;
                break;
            case PREMIER11:
                mBoughtAMealPlan = true;
                break;
            case REGULAR14:
                mBoughtAMealPlan = true;
                break;
            case PREMIER14:
                mBoughtAMealPlan = true;
                break;
            case REGULAR19:
                mBoughtAMealPlan = true;
                break;
            case PREMIER19:
                mBoughtAMealPlan = true;
                break;
            default:
                mBoughtAMealPlan=false;
                break;
    }
}

//getter function that returns a boolean value based on if a meal plan was purchased or not
bool BruinCard::hasPurchasedMealPlan()
{
    return(mBoughtAMealPlan);
}

//getter function that returns the meal plan that was chosen with the bruin card
plan BruinCard::getPlan()
{
    return(mPlan.getPlan());
}

bool BruinCard::eat(meal m)
{
    bool retvalue = false;
    //returns false if no meal plan was bought since there is nothing to eat
    if (mBoughtAMealPlan == false)
    {
        return(retvalue);
    }
   //for regular plans, checks if a meal was eaten twice in the same period (which regular plans prohibit). returns false if this is true
switch(mPlan.getPlan())
    {
        case REGULAR11:
            if (hasEatenBreakfast==true && m == BREAKFAST)
                return(retvalue);
            else if (hasEatenLunch == true && m == LUNCH)
                return(retvalue);
            else if (hasEatenDinner == true && m == DINNER)
                return(retvalue);
            else if (hasEatenBrunch==true && m == WEEKENDBRUNCH)
                return(retvalue);
            else
                retvalue=true; //CHECK LATER
            break;
        case PREMIER11:
            retvalue= true;
            break;
        case REGULAR14:
            if (hasEatenBreakfast==true && m == BREAKFAST)
                return(retvalue);
            else if (hasEatenLunch == true && m == LUNCH)
                return(retvalue);
            else if (hasEatenDinner == true && m == DINNER)
                return(retvalue);
            else if (hasEatenBrunch==true && m == WEEKENDBRUNCH)
                return(retvalue);
            else
                retvalue=true;
            break;
        case PREMIER14:
            retvalue= true;
            break;
        case REGULAR19:
            if (hasEatenBreakfast==true && m == BREAKFAST)
                return(retvalue);
            else if (hasEatenLunch == true && m == LUNCH)
                return(retvalue);
            else if (hasEatenDinner == true && m == DINNER)
                return(retvalue);
            else if (hasEatenBrunch==true && m == WEEKENDBRUNCH)
                return(retvalue);
            else
                retvalue=true;
            break;
        case PREMIER19:
            retvalue= true;
            break;
    }
    
    //use boolean data members hasEatenBreakfast, hasEatenLunch, hasEatenDinner and hasEatenBrunch to track which meals have been eaten so far each day
    switch(m)
    {
            case BREAKFAST:
                hasEatenBreakfast = true;
                break;
            case LUNCH:
                hasEatenLunch = true;
                break;
            case DINNER:
                hasEatenDinner = true;
                break;
            case WEEKENDBRUNCH:
                hasEatenBrunch = true;
                break;
    }
    //check which meals have been eaten and subtracts that meal from the number of meals the plan has left
    switch(mPlan.getPlan())
    {
        case REGULAR11:
            if (hasEatenBreakfast==true || hasEatenLunch==true || hasEatenDinner==true || hasEatenBrunch==true)
                howManyMealsLeft--;
            break;
        case REGULAR14:
            if (hasEatenBreakfast==true || hasEatenLunch==true || hasEatenDinner==true || hasEatenBrunch==true)
                howManyMealsLeft--;
            break;
        case REGULAR19:
            if (hasEatenBreakfast==true || hasEatenLunch==true || hasEatenDinner==true || hasEatenBrunch==true)
                howManyMealsLeft--;
            break;
        case PREMIER11:
            if (hasEatenBreakfast==true || hasEatenLunch==true || hasEatenDinner==true || hasEatenBrunch==true)
                howManyMealsLeft--;
            break;
        case PREMIER14:
            if (hasEatenBreakfast==true || hasEatenLunch==true || hasEatenDinner==true || hasEatenBrunch==true)
                howManyMealsLeft--;
            break;
        case PREMIER19:
            if (hasEatenBreakfast==true || hasEatenLunch==true || hasEatenDinner==true || hasEatenBrunch==true)
                howManyMealsLeft--;
            break;
    }
    return(retvalue);
}

void BruinCard::startQuarter()
{
    //establish how many meals a plan gets at the beginning of the quarter (same as weekly for regular meal plans)
    switch(mPlan.getPlan())
    {
        case REGULAR11:
            howManyMealsLeft=11;
            break;
        case REGULAR14:
            howManyMealsLeft=14;
            break;
        case REGULAR19:
            howManyMealsLeft=19;
        case PREMIER11:
            howManyMealsLeft=11*11;
            break;
        case PREMIER14:
            howManyMealsLeft=11*14;
            break;
        case PREMIER19:
            howManyMealsLeft=11*19;
            break;
    }
}

void BruinCard::newWeek()
{
    //establish how many meals a plan gets at the beginning of the week (calling this function does not change the number of meals for premier plans)
    switch(mPlan.getPlan())
    {
        case REGULAR11:
            howManyMealsLeft=11;
            break;
        case REGULAR14:
            howManyMealsLeft=14;
            break;
        case REGULAR19:
            howManyMealsLeft=19;
            break;
        case PREMIER11:
            break;
        case PREMIER14:
            break;
        case PREMIER19:
            break;
            
    }
    hasEatenBreakfast=false;
    hasEatenLunch=false;
    hasEatenDinner=false;
    hasEatenBrunch=false;
}

void BruinCard::newDay()
{
    hasEatenBreakfast=false;
    hasEatenLunch=false;
    hasEatenDinner=false;
    hasEatenBrunch=false;
}

int BruinCard::mealsLeftThisWeek()
{
    //returns the member variable for the number of meals left for each plan depending on what is eaten each day
    return(howManyMealsLeft);
}
