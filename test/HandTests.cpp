//****************************************************************************** 
// File name:		HandTests.cpp
// Author:			Tate Woodward, Pacific University
// Date:				4/8/25
// Class:				CS 250
// Assignment:  Card Game
// Purpose:			This file is written to unit test all functions that are part
//              of the included interface.
// Hours:       0.5
//******************************************************************************

#include <gtest/gtest.h>

// interface to unit test
#include "../include/Hand.h"

// Each unit test for a given function is added below
TEST (HandTest, DefaultConstructor) {
  Hand cHand;

  EXPECT_EQ (0, cHand.size ());
}

TEST (HandTest, CopyConstructor) {
  Hand cHand;
  Card cCard ("S", "A");
  cHand.addCard (cCard);

  EXPECT_EQ (1, Hand (cHand).size ());
  EXPECT_EQ ("S", Hand (cHand).getCard (0).getSuit ());
}

TEST (HandTest, addCard) {
  Hand cHand;
  Card cCard ("S", "A");
  cHand.addCard (cCard);

  EXPECT_EQ (1, cHand.size ());
  EXPECT_EQ ("S", cHand.getCard (0).getSuit ());
}

TEST (HandTest, addCardWithIndex) {
  Hand cHand;
  cHand.addCard(Card("H", "A"), 0);
  cHand.addCard(Card("C", "2"), 0);

  
  EXPECT_EQ(2, cHand.size());
  EXPECT_EQ("C", cHand.getCard(0).getSuit());
  EXPECT_EQ("2", cHand.getCard(0).getDenomination());
  EXPECT_EQ("H", cHand.getCard(1).getSuit());
  EXPECT_EQ("A", cHand.getCard(1).getDenomination());
  
  cHand.addCard(Card("D", "3"), 1);
  
  EXPECT_EQ(3, cHand.size());
  EXPECT_EQ("C", cHand.getCard(0).getSuit());
  EXPECT_EQ("2", cHand.getCard(0).getDenomination());
  EXPECT_EQ("D", cHand.getCard(1).getSuit());
  EXPECT_EQ("3", cHand.getCard(1).getDenomination());
  EXPECT_EQ("H", cHand.getCard(2).getSuit());
  EXPECT_EQ("A", cHand.getCard(2).getDenomination());
  
  
  cHand.addCard(Card("S", "4"), 3);
  
  EXPECT_EQ(4, cHand.size());
  EXPECT_EQ("C", cHand.getCard(0).getSuit());
  EXPECT_EQ("2", cHand.getCard(0).getDenomination());
  EXPECT_EQ("D", cHand.getCard(1).getSuit());
  EXPECT_EQ("3", cHand.getCard(1).getDenomination());
  EXPECT_EQ("H", cHand.getCard(2).getSuit());
  EXPECT_EQ("A", cHand.getCard(2).getDenomination());
  EXPECT_EQ("S", cHand.getCard(3).getSuit());
  EXPECT_EQ("4", cHand.getCard(3).getDenomination());
  
}

TEST (HandTest, addCardWithIndexExceptions) {
  Hand cHand;
  Card cCard ("S", "A");

  EXPECT_THROW (cHand.addCard (cCard, 1), std::out_of_range);
  EXPECT_THROW (cHand.addCard (cCard, -1), std::out_of_range);
}

TEST (HandTest, removeCard) {
  Hand cHand;
  Card cCard ("S", "A"), cCard2 ("H", "10");
  cHand.addCard (cCard);
  cHand.addCard (cCard2, 0);

  EXPECT_EQ (2, cHand.size ());

  cHand.removeCard (0);
  EXPECT_EQ ("S", cHand.getCard (0).getSuit ());
  EXPECT_EQ (1, cHand.size ());
}

TEST (HandTest, removeCardExceptions) {
  Hand cHand;
  Card cCard ("S", "A"), cCard2 ("H", "10");

  cHand.addCard (cCard);
  EXPECT_THROW (cHand.removeCard (1), std::out_of_range);
  EXPECT_THROW (cHand.removeCard (-1), std::out_of_range);
}

TEST (HandTest, size) {
  Hand cHand;
  Card cCard ("S", "A"), cCard2 ("H", "10");

  cHand.addCard (cCard);
  EXPECT_EQ (1, cHand.size ());
  cHand.addCard (cCard2, 0);
  EXPECT_EQ (2, cHand.size ());
  cHand.removeCard (0);
  EXPECT_EQ (1, cHand.size ());
}

TEST (HandTest, getCard) {
  Hand cHand;
  Card cCard ("S", "A"), cCard2 ("H", "10");

  cHand.addCard (cCard);
  cHand.addCard (cCard2, 0);

  EXPECT_EQ ("H", cHand.getCard (0).getSuit ());
  EXPECT_EQ (2, cHand.size ());
}

TEST (HandTest, getCardExceptions) {
  Hand cHand;
  Card cCard ("S", "A"), cCard2 ("H", "10");

  cHand.addCard (cCard);

  EXPECT_THROW (cHand.getCard (1), std::out_of_range);
  EXPECT_THROW (cHand.getCard (-1), std::out_of_range);
}

TEST (HandTest, clear) {
  Hand cHand;
  Card cCard ("S", "A"), cCard2 ("H", "10");

  cHand.addCard (cCard);
  cHand.addCard (cCard2, 0);
  EXPECT_EQ (2, cHand.size ());
  cHand.clear ();
  EXPECT_EQ (0, cHand.size ());
}

TEST (HandTest, insertionOperator) {
  Hand cHand, cHand2;
  Card cCard ("S", "A"), cCard2 ("H", "10");
  std::ostringstream cOut, cOut2;

  cHand.addCard (cCard);
  cHand.addCard (cCard2, 0);
  cOut << cHand;
  cOut2 << cHand2;
  EXPECT_EQ ("10H AS", cOut.str ());
  EXPECT_EQ ("", cOut2.str ());

}
