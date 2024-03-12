//
//  innout.cpp
//  project3
//
//  Created by Kyra Noguchi on 2/5/23.
//

#include <iostream>
#include <string>
#include <cassert>
#include <cctype>
using namespace std;
//declare all functions
int extractNumber(string s, size_t& index);
bool isValidOrderString(string orders);
double cost(string orders);
int howManyCombos (string orders, int whichCombo);
int howManyShakes(string orders, string whichShake);

int main() {
    size_t i = 0;
    assert(extractNumber("123abc", i) == 123);
    assert(i == 3);
    i = 0;
    assert(extractNumber("   123abc", i) == -1);
    assert(i == 0);
    i = 0;
    assert(extractNumber("000123", i ) == -1);
    assert(i == 0);
    assert(extractNumber("12:1", i ) == 12);
    assert(i == 2);
    assert(isValidOrderString("")==false);
    assert(isValidOrderString("5:1") == true);
    assert(isValidOrderString("2:1_2:1")==true);
    assert(isValidOrderString("50:1_2:1")==false);
    assert(isValidOrderString(" 5     0:     1_2:     1      ")==false);
    assert(isValidOrderString("2:C_3:V")==true);
    assert(isValidOrderString("101:1") == false);
    assert(isValidOrderString("5:1") == true);
    assert(isValidOrderString("5:1") == true);
    assert(isValidOrderString("2") == false);
    assert(isValidOrderString("10:1_20:1_30:2") == false);
    assert(isValidOrderString("40:1_10:2_1:3") == false);
    assert(isValidOrderString("40:C_10:V_1:S") == false);
    assert(isValidOrderString("40    :    C") == false);
    assert(isValidOrderString("xyz") == false);
    assert(isValidOrderString("_2:C____3:V_") == false);
    assert(isValidOrderString("1:1_") == false);
    assert( isValidOrderString( "2:001" ) == false );
    assert(cost("xyz") == -1.00);
    assert(cost("40:1_10:2_1:3") == -1.00);
    assert(cost("0    :    C") == -1.00);
    assert(cost("1:1") == 9.45);
    assert(cost("2:1_2:1") == 37.80);
    assert(cost("2:2_2:1") == 34.80);
    assert(cost("4:1") == 37.80);
    assert(howManyCombos("2:1", 1) == 2);
    assert(howManyCombos("2:1_2:1", 1) == 4);
    assert(howManyCombos("2:2_2:2", 2) == 4);
    assert(howManyCombos("2:2_2:2", 3) == 0);
    assert(howManyCombos("2     :1      ", 1) == -1);
    assert(howManyShakes("2:C", "Chocolate") == 2);
    assert(howManyShakes("2:C", "Vanilla") == 0);
    assert(howManyShakes("2:C", "C") == -1);
    assert(howManyShakes("2:C", "Chocolate") == 2);
    assert(howManyShakes("2:C_3:V", "Chocolate") == 2);
    assert(howManyShakes("2:C_3:V", "Vanilla") == 3);
    assert(howManyShakes("2:C_3:V", "Strawberry") == 0);
    
    cout << "Tests passed" << endl;
    return 0;
}

int extractNumber( string orders, size_t & index )
{
    // track the integer value found
    int quantity( -1 );
    
    // do we have more characters to read??
    // this prevents the function from returning the default quantity value (zero)
    // when no characters are actually read from the airport string at all

    // the number should be made up of digits
    while( index < orders.length()  && orders.at(index) >= '0' && orders.at(index) <= '9' )
    {
        if( quantity == -1)
        {
            quantity = 0;
        }
        // extract one digit and add it to the cumulative value held in quantity
        int digit = orders.at( index ) - '0';
        quantity = quantity * 10 + digit;
        // if what we find is a beginning zero or many leading zero it is invalid
        if (quantity == 0)
        {
            quantity = -1;
            break;
        }
        index = index + 1;
    }

    return( quantity );
}

bool isValidOrderString(string orders) //implement the function
{
    if (orders == "") //check for empty string
    {
        return false;
    }
    size_t index = 0; //initialize index
    int total = 0; //initalize the total amount of orders
    while(index<orders.size()) //create while loop that walks through the string and repeats when there is another order
    {
        int value = extractNumber(orders, index); //call extract number function to find the amount of item ordered
        total+=value; //update total value to calculate the amount of items ordered total
        if (value == -1) //check if first item in string is a number with the return value of extractNumber
        {
            //invalid!
            return(false);
        }
        if (index<orders.size()){ //use if statement to make sure we are not at the end of the string
            if (orders.at(index) != ':') //since extractNumber is pass by reference, after we call it we are at the index that contains the colon
            {
                return (false); //return false if the index value is not a colon
            }
            else
            {
                index ++; //if there is a colon at this value, we walk the string to the next index
            }
        }
        else
        {
            return(false); //if we are at the end of the string, return false because the input would soley include the quantity and not the type of item
        }
        if(orders.at(index) != '1' && orders.at(index) != '2' && orders.at(index) != '3' && orders.at(index) != 'C' && orders.at(index) != 'V' && orders.at(index) != 'S') //check for combo number or shake flavor
        {
            return(false); //return false if there is not one of the valid combo/shake inputs
        }
        else //execute if the combo number/shake flavor input is applicable,
        {
            index++; //continue walking the string to the next index
        }
        if (index<orders.size()) //use if statement to make sure we are not at the end of the string
        {
            if (orders.at(index) != '_'){ //makes sure the next index value is a _, signifying another order
                return false;
            }
            else if (orders.at(index) == '_' && index == orders.size()-1) //checks if there is a hanging underscore without another order following it
            {
                return false;
            }
            else
            {
                index++; //walk the string to the beginning of the next order, which will go through the same while loop
            }
        }
    }
    if (total >= 50) //ensures the total quantity of items ordered does not exceed 50, inclusive
    {
        return false;
    }
    return(true);
}

double cost(string orders) //implement cost function
{
    double totalcost = 0.00; //declare and intialize total cost value to 0.00
    //declare and intialize all constant variables for the prices of the combos and shakes
    const double combo1 = 9.45;
    const double combo2 = 7.95;
    const double combo3 = 7.55;
    const double Cshake = 2.85;
    const double Vshake = 2.85;
    const double Sshake = 2.85;
    //call isValidOrderString function to ensure the inputted string is a valid order string
    bool valid = isValidOrderString(orders);
    if (valid == false)
    {
        return(-1.00); //return -1.00 if isValidOrderString function returns false
    }
    size_t index = 0; //initialize index to 0
    while(index<orders.size()) //loop through the string
    {
        int value = extractNumber(orders, index);
        index ++;
        switch(orders.at(index)) //switch statement for the orders at the proper index
            //For the item ordered, add the total cost to the price of the item multiplied by the quantity ordered and assign it back to the total cost
            {
                case '1':
                    totalcost+= value * combo1;
                    break;
                case '2':
                    totalcost+= value * combo2;
                    break;
                case '3':
                    totalcost+= value * combo3;
                    break;
                case 'C':
                    totalcost+= value * Cshake;
                    break;
                case 'V':
                    totalcost+= value * Vshake;
                    break;
                case 'S':
                    totalcost+= value * Sshake;
                    break;
            }
        index+=2; //add 2 to the index to get past the _ and to the end of the order or beginning of next order
    }
    return(totalcost); //return the total cost double variable
}

int howManyCombos (string orders, int whichCombo){ //implement the howManyCombos function
    int totalvalue = 0; //declare and initalize the totalvalue, which is the total amount of combos ordered, to 0)
    //call isValidOrder string to ensure the inputted string is a valid order string
    bool valid = isValidOrderString(orders);
    if (valid == false)
    {
        return(-1);
    }
    if (whichCombo < 1 || whichCombo > 3) //if-statement to show that the input for whichCombo must be 1,2, or 3. If not, return -1
    {
        return(-1);
    }
    size_t index = 0; //initialize index to 0
    while(index<orders.size()) //while loop that walks the string
    {
        int value = extractNumber(orders, index);
        index ++;
        if (whichCombo == orders.at(index) - '0') //checks if inputted value for whichCombo is equal to the the combo number
            //also converts the char character to an integer so it can be compared with int whichCombo
        {
            totalvalue += value; //add the totalvalue variable to the quantity of items ordered and assign it back to totalvalue
        }
        index+=2; //add 2 to the index to get past the _ and to the end of the order or beginning of next order
    }
    return (totalvalue); //returns the total amount of combo 1s, 2s, or 3s
}

int howManyShakes(string orders, string whichShake)
{
    int totalshakes = 0; //declare and initalize the totalshakes, which is the total amount of shakes ordered, to 0)
    //call isValidOrder string to ensure the inputted string is a valid order string
    bool valid = isValidOrderString(orders);
    if (valid == false)
    {
        return(-1);
    }
    if (whichShake != "Chocolate" && whichShake != "Strawberry" && whichShake != "Vanilla") //if-statement that returns -1 if whichShake input is not one of the required parameter values
    {
        return(-1);
    }
    size_t index = 0; //initialize index to 0
    while(index<orders.size()) //while loop that walks the string
    {
        int value = extractNumber(orders, index);
        index ++;
        char shakeflavor = whichShake.at(0); //extract the first character from the string input whichShake to get C, V, or S
        if (shakeflavor == orders.at(index)) //checks if the first character of the inputted flavor is equal to the character at the index where shake flavor is
        {
            totalshakes += value; //add the totalshake variable to the quantity of shakes ordered and assign it back to totalshakes
        }
        index+=2; //add 2 to the index to get past the _ and to the end of the order or beginning of next order
    }
    return (totalshakes); //return the total amount of shakes for the inputted flavor
}
