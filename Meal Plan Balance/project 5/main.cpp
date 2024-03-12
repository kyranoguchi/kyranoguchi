//
//  main.cpp
//  project 5
//
//  Created by Kyra Noguchi on 2/27/23.
//

#include <iostream>
#include <string>
#include <cassert>

#include "Enums.h"
#include "MealPlan.h"
#include "BruinCard.h"

using namespace std;

int main(){
//    BruinCard noMealPlan;
//    assert( noMealPlan.hasPurchasedMealPlan( ) == false );
//    assert( noMealPlan.mealsLeftThisWeek() == 0 );
//    assert( noMealPlan.eat( BREAKFAST ) == false );
//
////    BruinCard c;
////    MealPlan m;
////    m.pickPlan( PREMIER11 );
////    c.purchaseMealPlan( m );
////    c.startQuarter();
////
////    assert( c.mealsLeftThisWeek() == 11*11 );
////    c.newWeek();
////    assert( c.eat( BREAKFAST ) );                 // using one meal on the plan
////    assert( c.eat( BREAKFAST ) );                 // Premier plans can use multiple meals at the same s
////
////    assert( c.mealsLeftThisWeek() == 11*11 - 2 );
////    c.newDay();
////    assert( c.mealsLeftThisWeek() == 11*11 - 2 );
////    c.newWeek();
////    assert( c.mealsLeftThisWeek() == 11*11 - 2 );
////    assert( std::to_string( m.cost() ) == "5018.280000" );
//
//    BruinCard d;
//    MealPlan n;
//    n.pickPlan( REGULAR11 );
//    d.purchaseMealPlan( n );
//    d.startQuarter();
//    d.newWeek();
//    assert( d.mealsLeftThisWeek() == 11 );  // Regular plans get their meals at the start of each week
//    assert( d.eat( BREAKFAST ) );
//    assert( d.eat( BREAKFAST ) == false );          // Regular plans cannot dine twice at the same meal
//    assert( d.mealsLeftThisWeek() == 10 );
//    d.newDay();
//    assert( d.eat( BREAKFAST ) );
//    assert( d.mealsLeftThisWeek() == 9 );
//    d.newWeek();
//    assert( d.mealsLeftThisWeek() == 11 );  // Regular plans lose any meals leftover at the start of the new week
//
//    assert( std::to_string( n.cost() ) == "4646.640000" );
//
//    BruinCard e;
//    e.startQuarter();
//    e.newWeek();
//    // without a meal plan, BruinCards cannot be used for meals
//    assert( e.eat( BREAKFAST ) == false );
//    assert( e.mealsLeftThisWeek() == 0 );
//    e.newDay();
//    assert( e.eat( LUNCH ) == false );
//    assert( e.eat( DINNER ) == false );
//    assert( e.eat( WEEKENDBRUNCH ) == false );
//
//    BruinCard p;
//    MealPlan q;
//    q.pickPlan( REGULAR19 );
//    p.purchaseMealPlan( q );
//    p.startQuarter();
//    p.newWeek();
//    p.newDay();
//    assert(p.mealsLeftThisWeek() == 19);
//    assert(p.eat( BREAKFAST ));
//    p.eat( LUNCH );
//    p.eat( DINNER );
//    assert(std::to_string( q.cost() ) == "5278.200000" );
//    assert(p.mealsLeftThisWeek() == 16);
//    p.newWeek();
//    p.newDay();
//    assert(p.mealsLeftThisWeek() == 19);
//
//    BruinCard y;
//    MealPlan z;
//    z.pickPlan( REGULAR14 );
//    y.purchaseMealPlan( z );
//    y.startQuarter();
//    y.newWeek();
//    assert( y.mealsLeftThisWeek() == 14 );
//    assert( y.eat( WEEKENDBRUNCH ) );
//    assert( y.eat( WEEKENDBRUNCH) == false );
//    assert( y.mealsLeftThisWeek() == 13 );
//    y.newDay();
//    assert( y.eat( BREAKFAST ) );
//    assert( y.eat( LUNCH ) );
//    assert( y.eat( DINNER ) );
//    assert( y.eat( WEEKENDBRUNCH ) );
//    assert( y.mealsLeftThisWeek() == 9 );
//    y.newWeek();
//    assert( y.mealsLeftThisWeek() == 14 );
//    assert( std::to_string( z.cost() ) == "5107.200000" );
//
//    BruinCard k;
//    MealPlan v;
//    v.pickPlan( PREMIER11 );
//    k.purchaseMealPlan( v );
//    k.startQuarter();
//
//    assert( k.mealsLeftThisWeek() == 11*11 );
//    assert( k.eat( BREAKFAST ) );
//    assert( k.eat( BREAKFAST ) );
//    assert( k.eat( BREAKFAST ) );
//    assert( k.eat( BREAKFAST ) );
//    assert( k.eat( BREAKFAST ) );
//    assert( k.eat( BREAKFAST ) );
//    assert( k.mealsLeftThisWeek() == 11*11 - 6 );
//    k.startQuarter();
//    assert( k.mealsLeftThisWeek() == 11*11);
//    assert( k.eat( BREAKFAST ) );
//    assert( k.eat( BREAKFAST ) );
//    assert( k.eat( BREAKFAST ) );
//    assert( k.eat( BREAKFAST ) );
//    assert( k.eat( BREAKFAST ) );
//    assert( k.eat( WEEKENDBRUNCH ) );
//    assert( k.eat( WEEKENDBRUNCH ) );
//    assert( k.eat( WEEKENDBRUNCH ) );
//    assert( k.mealsLeftThisWeek() == 11*11 - 8);
//    k.newDay();
//    k.newWeek();
//    assert( k.eat( BREAKFAST ) );
//    assert( k.eat( BREAKFAST ) );
//    assert( k.eat( BREAKFAST ) );
//    assert( k.eat( BREAKFAST ) );
//    assert( k.eat( BREAKFAST ) );
//    assert( k.eat( WEEKENDBRUNCH ) );
//    assert( k.eat( WEEKENDBRUNCH ) );
//    assert( k.eat( WEEKENDBRUNCH ) );
//    assert( k.mealsLeftThisWeek() == 11*11 - 8- 8);
//    assert( k.eat( BREAKFAST ) );
//    assert( k.eat( BREAKFAST ) );
//    assert( k.eat( BREAKFAST ) );
//    assert( k.eat( BREAKFAST ) );
//    assert( k.eat( BREAKFAST ) );
//    assert( k.mealsLeftThisWeek() == 11*11 - 8- 8-5);
//    assert( std::to_string( v.cost() ) == "5018.280000" );

    MealPlan m;
    BruinCard c;
    assert( c.hasPurchasedMealPlan() == false );
    assert( c.mealsLeftThisWeek() == 0 );
    
    cout << "Tests Passed" << endl;
    return(0);
}

