//
//  Mastermind.cpp
//  Mastermind
//
//  Created by Howard Stahl on 2/21/22.
//  Copyright © 2022 Howard Stahl. All rights reserved.
//

#include "Mastermind.h"
#include <string>
#include <iostream>

namespace cs31
{

// by default, select a random word
Mastermind::Mastermind() : mRound( 0 )
{
    // pick a random move as the answer
    Move m;
    m.random();
    // save this Move as the winning Move
    mWinningMove = m;
}

// cheating approach
// save the passed Move parameter as the winning Move
Mastermind::Mastermind( Move m ) : mRound( 0 )
{
    mWinningMove = m;
}

// cheating approach
// save the passed string parameter as the winning Move
Mastermind::Mastermind( std::string s ) : mRound( 0  )
{
    Move m;
    m.setPieces(s);
    mWinningMove = m;
}


// stringify this game by printing this game's Board
std::string Mastermind::display( std::string msg ) const
{
    return( mBoard.display() + msg );
}

// convert the entered word into a Move object
Move  Mastermind::play(std::string turn)
{
    Move m;
    int i;
    for( i = 0; i < turn.length(); i++ )
    {
        char c = turn.at( i );
        Piece p( c );
        m.setPiece(i, c);
    }
    // if not enough letters are entered, pad with NOTVALID
    while( i < REQUIREDLENGTH)
    {
        m.setPiece( i, ' ' );
        i++;
    }
    return( m );
}

Score Mastermind::endRound( Move m )
{
    Score s = Score(m, mWinningMove); //creating score object and using the Move parameter and the answer
    mCurrentScore=s; //save score as current score value
    mBoard.endRound(m,s); //supply the score to the booard
    mRound++; //incremement the round value
    return( s );
}

GAMEOUTCOME  Mastermind::determineGameOutcome( ) const
{
    GAMEOUTCOME outcome = GAMENOTOVER;
    if (mCurrentScore.isExactMatch())
    {
        outcome = GAMEWON;
    }
    if (mRound >= TOTALROUNDSALLOWED)
    {
        outcome=GAMELOST;
    }
    return( outcome ); //return the proper GAMEOUTCOME value
}

// stringify the current GAMEOUTCOME value
std::string  Mastermind::gameOutcomeAsString( ) const
{
    std::string result;
    GAMEOUTCOME outcome = determineGameOutcome();
    switch( outcome )
    {
        case GAMEWON:
            result = "You won the game!";
            break;
        case GAMELOST:
            result = "You lost the game!";
            break;
        case GAMENOTOVER:
            result = "The game is not over!";
            break;
    }
    return( result );
}

// is the game over?
bool Mastermind::gameIsOver() const
{
    return( determineGameOutcome() != GAMENOTOVER );
}

// trivial getter
Board  Mastermind::getBoard() const
{
    return( mBoard );
}

// what is the winning word?
std::string Mastermind::answer() const
{
    std::string s = mWinningMove.to_string();
    return( s );
}

}
