/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"

class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){}
		virtual ~TicTacToeBoardTest(){}
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};


TEST(TicTacToeBoardTest, toggle_turn)
{
  TicTacToeBoard b;
  Piece p = b.toggleTurn();
  if(p == O)
    ASSERT_TRUE(true);
  else
    ASSERT_TRUE(false);
}

TEST(TicTacToeBoard, row_winner)
{
	TicTacToeBoard b;
	b.placePiece(0,0);
	b.placePiece(1,1);
	b.placePiece(0,1);
	b.placePiece(2,2);
	b.placePiece(0,2);
	Piece p = b.getWinner();
	if(p == X)
	{
    ASSERT_TRUE(true);
	}
  else
	{
    ASSERT_TRUE(false);
	}
}

TEST(TicTacToeBoard, col_winner)
{
	TicTacToeBoard b;
	b.placePiece(0,0);
	b.placePiece(1,1);
	b.placePiece(1,0);
	b.placePiece(2,2);
	b.placePiece(2,0);
	Piece p = b.getWinner();
	if(p == X)
	{
    ASSERT_TRUE(true);
	}
  else
	{
    ASSERT_TRUE(false);
	}
}

TEST(TicTacToeBoard, downward_diag_winner)
{
	TicTacToeBoard b;
	b.placePiece(0,0);
	b.placePiece(2,0);
	b.placePiece(1,1);
	b.placePiece(1,0);
	b.placePiece(2,2);
	Piece p = b.getWinner();
	if(p == X)
	{
    ASSERT_TRUE(true);
	}
  else
	{
    ASSERT_TRUE(false);
	}
}

TEST(TicTacToeBoard, upward_diag_winner)
{
	TicTacToeBoard b;
	b.placePiece(2,0);
	b.placePiece(1,0);
	b.placePiece(1,1);
	b.placePiece(2,2);
	b.placePiece(0,2);
	Piece p = b.getWinner();
	if(p == X)
	{
    ASSERT_TRUE(true);
	}
  else
	{
    ASSERT_TRUE(false);
	}
}
