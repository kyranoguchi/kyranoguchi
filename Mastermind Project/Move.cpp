//
//  Move.cpp
//

#include "Move.h"
#include "Random.h"
#include <stdexcept>

namespace cs31
{

// by default, a move is invalid
Move::Move()
{
    // this code is really not needed since the default constructor
    // will do all this work but I am explicitly showing it for CS 31
    // students
    Piece p;  // invalid piece
    array[ 0 ] = p;
    array[ 1 ] = p;
    array[ 2 ] = p;
    array[ 3 ] = p;
}

// trivial getter
// but throw logic_error if the index is out of range
Piece Move::getPiece( int i )
{
    if (i >= 0 && i < REQUIREDLENGTH)
        return( array[ i ] );
    else
        throw std::logic_error( "invalid i value" );
}

// construct a Piece for the Move from the character parameter
// but throw logic_error if the index is out of range
void  Move::setPiece( int i, char c )
{
    if (i >= 0 && i < REQUIREDLENGTH)
    {
        Piece p( c );
        array[ i ] = p;
    }
    else
        throw std::logic_error( "invalid i value" );
}

// construct a Piece for the Move from the Piece parameter
// but throw logic_error if the index is out of range
void  Move::setPiece( int i, Piece p )
{
    if (i >= 0 && i < REQUIREDLENGTH)
        array[ i ] = p;
    else
        throw std::logic_error( "invalid i value" );
}

// construct a Piece for the Move from the first letter
// of the string parameter
// but throw logic_error if the index is out of range
void  Move::setPiece( int i, std::string s )
{
    if (i >= 0 && i < REQUIREDLENGTH)
        setPiece( i, s.at( 0 ) );
    else
        throw std::logic_error( "invalid i value" );
}

void  Move::setPieces( std::string s )
{
    if (s.length()!=REQUIREDLENGTH) //check if the length of the move is valid
    {
        throw std::logic_error("Pieces in move is too short or too long"); //throw error if the string parameter is too short or long
    }
    for(int index = 0; index<s.length(); index++) //loop through string and set each piece of the move
    {
        setPiece(index, s.at(index)); //set each piece of Move object to the associated COLOR provided in the string parameter.
    }
}

// stringify this Move
std::string Move::to_string() const
{
    std::string s;
    for (int i = 0; i < REQUIREDLENGTH; i++)
    {
        s += array[ i ].getColorAsString();
    }
    return( s );
}

bool  Move::isValid( ) const
{
    bool result( true );
    for (int i = 0; i < REQUIREDLENGTH; i++)
    {
        if (array[i].getColor() == NOTVALID)
        {
            result = false;
        }
    }
    return( result );
}

void  Move::random()
{
    for (int i = 0; i < REQUIREDLENGTH; i++)
    {
        Random r( VALIDCOLORCOUNT - 1 );
        r.random();
        COLOR c = static_cast< COLOR > ( r.getValue() );
        Piece p( c );
        array[ i ] = p;
    }
}

}

