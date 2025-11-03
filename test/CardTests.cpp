//****************************************************************************** 
// File name:		DeckTests.cpp
// Author:			Tate Woodward, Pacific University
// Date:				4/7/25
// Class:				CS 250
// Assignment:  Card Game
// Purpose:			This file is written to unit test all functions that are part
//              of the included interface.
// Hours:       1
//******************************************************************************

#include <gtest/gtest.h>

// interface to unit test
#include "../include/Card.h"

// Each unit test for a given function is added below
TEST (CardTest, ParameterizedConstructor) {
  EXPECT_EQ ("H", Card ("H", "10").getSuit ());
  EXPECT_EQ ("10", Card ("H", "10").getDenomination ());
  EXPECT_EQ (10, Card ("H", "10").getDenominationValue ());
  EXPECT_EQ (1, Card ("H", "A").getDenominationValue ());
}

TEST (CardTest, CopyConstructor) {
  Card cCard ("H", "A");

  EXPECT_EQ ("H", Card (cCard).getSuit ());
  EXPECT_EQ ("A", Card (cCard).getDenomination ());
  EXPECT_EQ (1, Card (cCard).getDenominationValue ());
}

TEST (CardTest, getSuit) {
  EXPECT_EQ ("H", Card ("H", "10").getSuit ());
}

TEST (CardTest, getDenomination) {
  EXPECT_EQ ("10", Card ("H", "10").getDenomination ());
}

TEST (CardTest, getDenominationValue) {
  EXPECT_EQ (10, Card ("H", "10").getDenominationValue ());
  EXPECT_EQ (1, Card ("H", "A").getDenominationValue ());
}

TEST (CardTest, getCard) {
  Card cCard ("H", "10");

  EXPECT_EQ ("H", Card (cCard).getCard ().getSuit ());
  EXPECT_EQ ("10", Card (cCard).getCard ().getDenomination ());
}

TEST (CardTest, operatorDoubleEquals) {
  Card cCard ("H", "10");

  EXPECT_EQ (true, Card (cCard) == cCard);
  EXPECT_EQ (false, Card ("H", "9") == cCard);
  EXPECT_EQ (false, Card ("S", "10") == cCard);
}

TEST (CardTest, insertionOperator) {
  Card cCard ("H", "10");

  std::ostringstream cOut;
  cOut << cCard;

  EXPECT_EQ ("10H", cOut.str ());
}

TEST (CardTest, setSuit) {
  // setSuit called in constructor 
  EXPECT_EQ ("H", Card ("H", "10").getSuit ());
}

TEST (CardTest, setSuitExceptions) {
  // setSuit called in constructor 
  EXPECT_THROW (Card ("A", "10"), std::invalid_argument);
  EXPECT_THROW (Card ("h", "10"), std::invalid_argument);
  EXPECT_THROW (Card ("2", "10"), std::invalid_argument);
}

TEST (CardTest, setDenomination) {
  // setDenomination called in constructor 
  EXPECT_EQ ("10", Card ("H", "10").getDenomination ());
}

TEST (CardTest, setDenominationExceptions) {
  // setDenomination called in constructor 
  EXPECT_THROW (Card ("H", "14"), std::invalid_argument);
  EXPECT_THROW (Card ("H", "0"), std::invalid_argument);
  EXPECT_THROW (Card ("H", "a"), std::invalid_argument);
}