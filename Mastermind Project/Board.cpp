#include "Board.h"
#include <stdexcept>
#include <string>
#include <iostream>

namespace cs31
{
    Board::Board() : mRoundCount( 0 )
    {
        
    }
    
    // save this Move and Score into the set of Moves and Scores
    // being managed by this Board
    void Board::endRound( Move m, Score s )
    {
        if (mRoundCount < TOTALROUNDSALLOWED)
        {
            moves[ mRoundCount ] = m;
            scores[ mRoundCount ] = s;
            // increment to the next round
            mRoundCount++;
        }
        else
        {
            // throw an error rather than walk off the edge of the array
            std::logic_error le( "invalid roundcount value" );
            throw( le );
        }
    }
    
    // print this Board
    // the Wordle object repetitively calls this operation as the game
    // play proceeds
    std::string Board::display( ) const
    {
        using namespace std;
        
        std::string s = "\t\t  CS31 Mastermind Game\nR-red B-blue G-green Y-yellow, P-purple O-orange\n";
        if (mRoundCount > 0)
        {
            int i = 0;
            while( i < mRoundCount )
            {
                s += std::to_string( i+1 );
                s += " : ";
                s += moves[ i ].to_string();
                s += " - ";
                s += scores[ i ].to_string();
                s += "\n";
                i++;
            }
        }
        
        return( s );
    }
    
    //trivial getter method
    int Board::getCurrentRound() const
    {
        return(mRoundCount); //return the member variable for round count
    }

    Move Board::getMoveForRound( int round ) const
    {
        if (round < 0 || round > TOTALROUNDSALLOWED-1) //check if round is valid or not
        {
            throw std::logic_error("Round is invalid");
        }
        else if (round >= mRoundCount) //check if round has not yet been played
        {
            throw std::logic_error("Round has not yet been played");
        }
        else
        {
            return moves[round]; //retrieves past move and returns it
        }
    }

    Score Board::getScoreForRound( int round ) const
    {
        if (round < 0 || round > TOTALROUNDSALLOWED-1) //check if round is valid or not
        {
            throw std::logic_error("Round count is invalid");
        }
        else if (round >= mRoundCount) //check if round has not yet been played
        {
            throw std::logic_error("Round has not yet been played");
        }
        else
        {
            return scores[round]; //retrieves past score and returns it
        }
    }
}
