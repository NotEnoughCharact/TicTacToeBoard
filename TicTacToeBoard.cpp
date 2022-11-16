#include "TicTacToeBoard.h"
#include <iostream>
/**
 * Class for representing a 3x3 Tic-Tac-Toe game board, using the Piece enum
 * to represent the spaces on the board.
**/

//Constructor sets an empty board and specifies it is X's turn first
TicTacToeBoard::TicTacToeBoard()
{
  turn = X;
  for(int i=0; i<BOARDSIZE; i++)
    for(int j=0; j<BOARDSIZE; j++)
      board[i][j] = Blank;
}

/**
 * Switches turn member variable to represent whether it's X's or O's turn
 * and returns whose turn it is
**/
Piece TicTacToeBoard::toggleTurn()
{
  if(turn == X)
  {
    turn = O;
    return O;
  }
  else
  {
    turn = X;
    return X;
  }
}

/**
 * Places the piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. placePiece does
 * NOT allow to place a piece in a location where there is already a piece.
 * In that case, placePiece just returns what is already at that location.
 * Out of bounds coordinates return the Piece Invalid value. When the game
 * is over, no more pieces can be placed so attempting to place a piece
 * should neither change the board nor change whose turn it is.
**/
Piece TicTacToeBoard::placePiece(int row, int column)
{
  if(row < 0 || row > 2 || column < 0 || column > 2)
  {
    return Invalid;
  }
  else if(board[row][column] == X || board[row][column] == O || getWinner() != Invalid)
  {
    return board[row][column];
  }
  else
  {
    board[row][column] = turn;
    toggleTurn();
    return board[row][column];
  }

}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece TicTacToeBoard::getPiece(int row, int column)
{
  if(row < 0 || row > 2 || column < 0 || column > 2)
  {
    return Invalid;
  }
  return board[row][column];;
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won.
**/
Piece TicTacToeBoard::getWinner()
{
  int bl = 0;
  Piece winner, temp;
  for(int i = 0; i < BOARDSIZE; i++)
  {
    temp = board[i][0];
    if(temp == Blank)
    {
      bl++;
      winner = Invalid;
    }
    else
      winner = temp;
    for(int j = 1; j < BOARDSIZE; j++)
    {
      if(board[i][j] == Blank)
      {
        bl++;
      }
      if(board[i][j] != temp)
      {
        winner = Invalid;
      }
    }
    if(winner != Invalid)
      return winner;
  }
  for(int i = 0; i < BOARDSIZE; i++)
  {
    temp = board[0][i];
    if(temp == Blank)
      winner == Invalid;
    else
      winner = temp;
    for(int j = 1; j < BOARDSIZE; j++)
    {
      if(board[j][i] != temp)
      {
        winner = Invalid;
        break;
      }
    }
    if(winner != Invalid)
      return winner;
  }
  temp = board[0][0];
  if(temp == Blank)
    winner == Invalid;
  else
    winner = temp;
  for(int i = 1; i < BOARDSIZE; i++)
  {
    if(board[i][i] != temp)
    {
      winner = Invalid;
      break;
    }
  }
  if(winner != Invalid)
    return winner;
  temp = board[2][0];
  if(temp == Blank)
    winner == Invalid;
  else
    winner = temp;
  for(int i = 0; i < BOARDSIZE; i++)
  {
    if(board[2-i][i] != temp)
    {
      winner = Invalid;
      break;
    }
  }
  if(winner != Invalid)
    return winner;
  if(bl == 0)
    return Blank;
  else
    return Invalid;
}
