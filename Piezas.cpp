#include "Piezas.h"
#include <vector>
/** CLASS Piezas
 * Class for representing a Piezas vertical board, which is roughly based
 * on the game "Connect Four" where pieces are placed in a column and
 * fall to the bottom of the column, or on top of other pieces already in
 * that column. For an illustration of the board, see:
 *  https://en.wikipedia.org/wiki/Connect_Four
 *
 * Board coordinates [row,col] should match with:
 * [2,0][2,1][2,2][2,3]
 * [1,0][1,1][1,2][1,3]
 * [0,0][0,1][0,2][0,3]
 * So that a piece dropped in column 2 should take [0,2] and the next one
 * dropped in column 2 should take [1,2].
**/


/**
 * Constructor sets an empty board (default 3 rows, 4 columns) and
 * specifies it is X's turn first
**/
Piezas::Piezas()
{
  board.resize(BOARD_ROWS);
  for(int row = 0; row < BOARD_ROWS; row++){
    board[row].resize(BOARD_COLS);
    for(int column = 0; column < BOARD_COLS; column++){
      board[row][column] = Blank;
    }
  }
  //X's turn first
  turn = X;
}

/**
 * Resets each board location to the Blank Piece value, with a board of the
 * same size as previously specified
**/

//The board should already be the same size so just set every spot to Blank.
void Piezas::reset()
{
  for(int row = 0; row < BOARD_ROWS; row++){
    for(int column = 0; column < BOARD_COLS; column++){
      board[row][column] = Blank;
    }
  }
}

/**
 * Places a piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. dropPiece does
 * NOT allow to place a piece in a location where a column is full.
 * In that case, placePiece returns Piece Blank value
 * Out of bounds coordinates return the Piece Invalid value
 * Trying to drop a piece where it cannot be placed loses the player's turn
**/
Piece Piezas::dropPiece(int column)
{
    Piece curPiece = turn;

//Check to make sure X goes first and switch after
  if(turn == O){
    turn = X;
  }
  else if(turn == X){
    turn = O;
  }

//Check for out of bounds and loses the player's turn
  if(column < 0)
  {
    return Invalid;
  }

//Place curPiece and return it
    for(int row = 0; row < BOARD_ROWS; row++){
      if(board[row][column] == Blank){
        board[row][column] = curPiece;
        return curPiece;
      }
    }

    return Blank;

}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece Piezas::pieceAt(int row, int column)
{
//Checking to see if pieceAt is out of bounds.
  if(row < 0 || row > BOARD_ROWS || row > 4 || column < 0 || column > BOARD_COLS || column > 4){
    return Invalid;
  }
  else{
    return board[row][column];
  }
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won ("tie").
 * For a game to be over, all locations on the board must be filled with X's
 * and O's (i.e. no remaining Blank spaces). The winner is which player has
 * the most adjacent pieces in a single line. Lines can go either vertically
 * or horizontally. If both X's and O's have the same max number of pieces in a
 * line, it is a tie.
**/
Piece Piezas::gameState()
{
    int xCurPiece = 0;
    int oCurPiece = 0;
    int xHighPiece = 0;
    int oHighPiece = 0;
    bool isOver = true;

    //Check if game is over
  for(int row = 0; row < BOARD_ROWS; row++){
    for(int column = 0; column < BOARD_COLS; column++){
      if(board[row][column] == Blank){
        isOver = false;
      }
    }
  }
  if(isOver == false){
    return Invalid;
  }

  for(int row = 0; row < BOARD_ROWS; row++){
    for(int column = 0; column < BOARD_COLS; column++){
      if(board[row][column] == X){
        xCurPiece += 1;
        if(xCurPiece > xHighPiece){
          xHighPiece = xCurPiece;
        }
        oHighPiece = 0;
      }
      else if(board[row][column] == O){
        oCurPiece += 1;
        if(oCurPiece > oHighPiece){
          oHighPiece = oCurPiece;
        }
        xHighPiece = 0;
      }
    }
  }

  if(xHighPiece > oHighPiece){
    return X;
  }
  else if(oHighPiece > xHighPiece){
    return O;
  }
  else{
    return Blank;
  }
}
