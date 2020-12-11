/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"

class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PiezasTest, simpleMoveCheck)
{
	Piezas board;
  Piece piece = board.dropPiece(1);
  ASSERT_EQ(piece, X);
}

TEST(PiezasTest, simepleNegativeCheck)
{
	Piezas board;
  Piece piece = board.dropPiece(-1);
  ASSERT_EQ(piece, Invalid);
}

TEST(PiezasTest, simepleOutBoundsCheck)
{
	Piezas board;
  Piece piece = board.dropPiece(12);
  ASSERT_EQ(piece, Blank);
}

TEST(PiezasTest, xInBoundsCheck)
{
	Piezas board;
  board.dropPiece(1);
  ASSERT_EQ(board.pieceAt(0,1), X);
}

TEST(PiezasTest, oInBoundsCheck)
{
	Piezas board;
  board.dropPiece(1);
  board.dropPiece(2);
  ASSERT_EQ(board.pieceAt(0,2), O);
}

TEST(PiezasTest, xGoesFirstCheck)
{
	Piezas board;
  ASSERT_EQ(board.dropPiece(1), X);
}

TEST(PiezasTest, oGoesSecondCheck)
{
	Piezas board;
  ASSERT_EQ(board.dropPiece(1), X);
  ASSERT_EQ(board.dropPiece(2), O);
}

TEST(PiezasTest, xGoesThirdCheck)
{
	Piezas board;
  ASSERT_EQ(board.dropPiece(1), X);
  ASSERT_EQ(board.dropPiece(2), O);
  ASSERT_EQ(board.dropPiece(3), X);
}

TEST(PiezasTest, oGoesFourthCheck)
{
	Piezas board;
  ASSERT_EQ(board.dropPiece(1), X);
  ASSERT_EQ(board.dropPiece(2), O);
  ASSERT_EQ(board.dropPiece(3), X);
  ASSERT_EQ(board.dropPiece(2), O);
}

TEST(PiezasTest, resetFunctionCheck)
{
	Piezas board;
  board.dropPiece(1);
  board.reset();
  ASSERT_EQ(board.pieceAt(0, 1), Blank);
}

TEST(PiezasTest, xWins)
{
	Piezas board;
  board.dropPiece(0);//X
  board.dropPiece(0);//O
  board.dropPiece(1);
  board.dropPiece(2);
  board.dropPiece(0);
  board.dropPiece(1);
  board.dropPiece(1);
  board.dropPiece(3);
  board.dropPiece(3);
  board.dropPiece(2);
  board.dropPiece(1);
  board.dropPiece(0);
  board.dropPiece(2);
  board.dropPiece(0);
  board.dropPiece(3);
  ASSERT_EQ(board.gameState(), X);
}

TEST(PiezasTest, oWins)
{
	Piezas board;
  board.dropPiece(1);
  board.dropPiece(0);
  board.dropPiece(2);
  board.dropPiece(0);
  board.dropPiece(3);
  board.dropPiece(0);
  board.dropPiece(1);
  board.dropPiece(1);
  board.dropPiece(3);
  board.dropPiece(2);
  board.dropPiece(0);
  board.dropPiece(2);
  board.dropPiece(0);
  board.dropPiece(3);
  ASSERT_EQ(board.gameState(), O);
}
