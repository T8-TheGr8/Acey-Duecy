//****************************************************************************** 
// File name:		InBetweenHandTests.cpp
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
#include "../include/InBetweenHand.h"

// Each unit test for a given function is added below
TEST (InBetweenHandTests, DefaultConstructor) {
  InBetweenHand cBetwHand;

  EXPECT_EQ (0, cBetwHand.size ());
}

TEST (InBetweenHandTests, CopyConstructor) {
  InBetweenHand cBetwHand;

  cBetwHand.addCard (Card ("S", "A"));

  EXPECT_EQ (1, InBetweenHand (cBetwHand).size ());
  EXPECT_EQ ("S", InBetweenHand (cBetwHand).getCard (0).getSuit ());
  EXPECT_EQ ("A", InBetweenHand (cBetwHand).getCard (0).getDenomination ());
}

TEST (InBetweenHandTests, addCard) {
  InBetweenHand cBetwHand;

  cBetwHand.addCard (Card ("S", "10"));
  EXPECT_EQ (1, cBetwHand.size ());
  EXPECT_EQ ("S", cBetwHand.getCard (0).getSuit ());
  EXPECT_EQ ("10", cBetwHand.getCard (0).getDenomination ());
  cBetwHand.addCard (Card ("H", "2"));
  EXPECT_EQ (2, cBetwHand.size ());
  EXPECT_EQ ("H", cBetwHand.getCard (0).getSuit ());
  EXPECT_EQ ("2", cBetwHand.getCard (0).getDenomination ());
}

TEST (InBetweenHandTests, addCardExceptions) {
  InBetweenHand cBetwHand;

  cBetwHand.addCard (Card ("S", "A"));
  cBetwHand.addCard (Card ("H", "2"));

  EXPECT_THROW (cBetwHand.addCard (Card ("H", "A")), std::runtime_error);
}

TEST (InBetweenHandTests, getDistance) {
  InBetweenHand cBetwHand, cBetwHand2, cBetwHand3;

  cBetwHand.addCard (Card ("S", "A"));
  cBetwHand.addCard (Card ("H", "2"));
  cBetwHand2.addCard (Card ("S", "3"));
  cBetwHand2.addCard (Card ("H", "K"));
  cBetwHand3.addCard (Card ("H", "K"));
  cBetwHand3.addCard (Card ("H", "K"));

  EXPECT_EQ (1, cBetwHand.getDistance ());
  EXPECT_EQ (10, cBetwHand2.getDistance ());
  EXPECT_EQ (0, cBetwHand3.getDistance ());
}

TEST (InBetweenHandTests, getDistanceExceptions) {
  InBetweenHand cBetwHand;
  EXPECT_THROW (cBetwHand.getDistance(), std::runtime_error);
  cBetwHand.addCard (Card ("S", "A"));
  EXPECT_THROW (cBetwHand.getDistance(), std::runtime_error);
}