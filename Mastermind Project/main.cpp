#include <iostream>
#include "Random.h"
#include "Piece.h"
#include "Board.h"
#include "Score.h"
#include "Settings.h"
#include "Enums.h"
#include "Mastermind.h"


int main( ) {
    using namespace cs31;
    using namespace std;

//  Choose a random answer...
    Mastermind game;
    bool forceEnd = false;
    std::string action, turn, message = "(p)lay (q)uit: ";
    cout << game.display( message ) << endl;

    do
    {
        getline( cin, action );
        while (action.size() == 0)
        {
            getline( cin, action );  // no blank entries allowed....
        }
        switch (action[0])
        {
            default:   // if bad move, nobody moves
                cout << '\a' << endl;  // beep
                continue;
            case 'Q':
            case 'q':
                forceEnd = true;
                break;
            case 'p':
            case 'P':
                if (game.determineGameOutcome() == GAMENOTOVER)
                {
                    getline( cin, turn );
                    Move m = game.play( turn );

                    if (m.isValid())
                    {
                        Score s = game.endRound(m);
                        s.isExactMatch();  // just to avoid warning...
                    }
                    else
                    {
                        // turn was not a valid word
                        cout << turn << " was not a Mastermind game entry!" << endl;
                    }
                }
                break;
        }
        if (!game.gameIsOver())
        {
            cout << game.display( message ) << endl;
        }
        else
        {
            cout << game.display( game.gameOutcomeAsString() ) << endl;
            cout << "The winning Mastermind game entry was: " << game.answer() << endl;
        }
    } while( !game.gameIsOver() && !forceEnd );
    
//    Piece p;
//    assert( p.getColor() == NOTVALID );
//    p = Piece( "R" );
//    assert( p.getColor() == RED );
//    assert( p.getColorAsString() == "R" );
//
//    Move m;
//    p = m.getPiece( 0 );
//    assert( p.getColor() == NOTVALID );
//    m.setPieces( "RBRB" );
//    p = m.getPiece( 2 );
//    assert( p.getColor() == RED );
//    m.setPiece( 2, 'y' );
//    p = m.getPiece( 2 );
//    assert( p.getColor() == YELLOW );
//
//    Score s;
//    assert( s.isExactMatch()  == false );
//    assert( s.getAnswer( 2 ) == WRONG );
//    m.setPieces( "RBRB" );
//    Move theAnswer;
//    theAnswer.setPieces( "YOYO" );
//    s = Score( m, theAnswer );
//    assert( s.isExactMatch() == false );
//    assert( s.to_string() == "____" );
//    theAnswer.setPieces( "rbrb" );
//    s = Score( m, theAnswer );
//    assert( s.isExactMatch() == true );
//    assert( s.to_string() == "RRRR" );
//
//    Board b;
//    assert( b.getCurrentRound() == 0 );
//    m.setPieces( "POPO" );
//    theAnswer.setPieces( "YYOP" );
//    s = Score( m, theAnswer );
//    b.endRound( m, s );
//    assert( b.getCurrentRound() == 1 );
//    assert( b.getMoveForRound( 0 ).to_string() == "POPO" );
//    assert( b.getScoreForRound( 0 ).to_string() == "MM__" );
//
//    Mastermind game( "rbyo" );
//    assert( game.answer() == "RBYO" );
//    assert( game.gameIsOver() == false );
//    m = game.play( "BBBB" );
//    s = game.endRound( m );
//    assert( s.to_string() == "_R__" );
    

//        Move m;
//        m.setPieces( "GGPP" );
//
//        Score s;
//        Move theAnswer;
//        theAnswer.setPieces( "GGPP" );
//        s = Score( m, theAnswer );
//        assert( s.isExactMatch() == true );
//        assert( s.to_string() == "RRRR" );
    
//    Move m;
//    m.setPieces( "GPOB" );
//
//    Score s;
//    Move theAnswer;
//    theAnswer.setPieces( "GOPB" );
//    s = Score( m, theAnswer );
//    assert( s.isExactMatch() == false );
//    assert( s.to_string() == "RMMR" );
//
//        Move m;
//        m.setPieces( "GGOP" );
//
//        Score s;
//        Move theAnswer;
//        theAnswer.setPieces( "OPGG" );
//        s = Score( m, theAnswer );
//        assert( s.isExactMatch() == false );
//        assert( s.to_string() == "MMMM" );

    
//        Move m;
//        m.setPieces( "GGYY" );
//
//        Score s;
//        Move theAnswer;
//        theAnswer.setPieces( "YGGB" );
//        s = Score( m, theAnswer );
//        assert( s.isExactMatch() == false );
//        assert( s.to_string() == "MRM_" );
//
//    Move m;
//    m.setPieces( "GGGY" );
//
//    Score s;
//    Move theAnswer;
//    theAnswer.setPieces( "YGGB" );
//    s = Score( m, theAnswer );
//    assert( s.isExactMatch() == false );
//    assert( s.to_string() == "_RRM" );
    
    
//    Move m;
//    m.setPieces( "GGOP" );
//
//    Score s;
//    Move theAnswer;
//    theAnswer.setPieces( "BYBY" );
//    s = Score( m, theAnswer );
//    assert( s.isExactMatch() == false );
//    assert( s.to_string() == "____" );
    
//    Move m;
//    m.setPieces( "GGOP" );
//
//    Score s;
//    Move theAnswer;
//    theAnswer.setPieces( "OPGY" );
//    s = Score( m, theAnswer );
//    assert( s.isExactMatch() == false );
//    assert( s.to_string() == "M_MM" );
//
//    Move m;
//    m.setPieces( "GGOP" );
//
//    Score s;
//    Move theAnswer;
//    theAnswer.setPieces( "POGB" );
//    s = Score( m, theAnswer );
//    assert( s.isExactMatch() == false );
//    assert( s.to_string() == "M_MM" );
//    
//    Move m;
//    m.setPieces( "GGYY" );
//
//    Score s;
//    Move theAnswer;
//    theAnswer.setPieces( "YBGB" );
//    s = Score( m, theAnswer );
//    assert( s.isExactMatch() == false );
//    assert( s.to_string() == "M_M_" );
    
//    Move m;
//    m.setPieces( "GGGY" );
//
//    Score s;
//    Move theAnswer;
//    theAnswer.setPieces( "YGGB" );
//    s = Score( m, theAnswer );
//    assert( s.isExactMatch() == false );
//    assert( s.to_string() == "_RRM" );
    

//    cout << "all tests passed!" << endl;
    
    return( 0 );
}
