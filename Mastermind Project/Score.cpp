//
//  Score.cpp
//

#include "Score.h"
#include <stdexcept>

namespace cs31
{

// setup a default score - all WRONG ANSWER's
Score::Score()
{
    for( int i = 0; i < REQUIREDLENGTH; i++ )
    {
        array[ i ] = WRONG;
    }
}

Score::Score( Move move, Move answer ) : Score() //use intitialization list to set all indexes to wrong initially
{
    bool storeArray[REQUIREDLENGTH]; //create array that stores if a right, wrong, or maybe value has been assigned
    for(int k = 0; k<REQUIREDLENGTH; k++) //for loop that assigns values in storeArray to false to show that no values have been set yet for array[]
        storeArray[k] = false;
    for( int i = 0; i < REQUIREDLENGTH; i++ ) //loop through the move and the answer
    {
        if (move.getPiece(i).getColor() == answer.getPiece(i).getColor()) //check if the pieces at the indexes are all equal
        {
            array[i] = RIGHT;
            storeArray[i] = true; //store true in storeArray since something has been assigned to array[]
        }
    }
        
    for( int i = 0; i < REQUIREDLENGTH; i++ ) //loop through the move and the answer
    {
        if (array[i] == RIGHT)
        {
            continue; //restart the loop if the array has already been set to right
        }
        for (int j = 0; j<REQUIREDLENGTH; j++) //loop through the same index for move, but move through the indexes for answer
        {
            if (array[j] == RIGHT ||storeArray[j] == true) //check if the index of right move and answer correspond OR if the answer and move are set already
            {
                continue; //restart loop if the if statement runs
            }
            if(move.getPiece(i).getColor() == answer.getPiece(j).getColor()) //check if index of move is equal to index of the answer at all of its indexes
            {
                array[i] = MAYBE; //set index of the array to maybe
                storeArray[j] = true; //set to true because maybe is stored in the array
                break; //break out of loop so that multiple elements are not marked true on same iteration of the outer loop
            }
        }
    }
}

// trivial getter but throw logic_error if the index is out of range
ANSWER Score::getAnswer( int i )
{
    if (i >= 0 && i < REQUIREDLENGTH)
        return( array[ i ] );
    else
        throw std::logic_error( "invalid i value" );
}

// stringify this Score
std::string Score::to_string() const
{
    std::string s = "";
    int mCount = 0;
    int rCount = 0;
    for (int i = 0; i < REQUIREDLENGTH; i++)
    {
        switch( array[i] )
        {
            case WRONG:
                // wrongs should not be printed at all
                s += "_";
                break;
            case RIGHT:
                rCount++;
                s += "R";
                break;
            case MAYBE:
                mCount++;
                s += "M";
                break;
        }
    }
    return( s );
}

bool Score::isExactMatch() const
{
    bool retvalue = true; //declare and intiialize variable for return value
    for (int i = 0; i < REQUIREDLENGTH; i++) //for loop that loops through the move
    {
        if (array[i]!=RIGHT) //checck if the piece at each index is right
        retvalue = false; //return false if any pieces are not an exact match to the answere
    }
    return(retvalue); //return the return value
}

}
