//****************************************************************************** 
// File name:		DeckTests.cpp
// Author:			Tate Woodward, Pacific University
// Date:				4/7/25
// Class:				CS 250
// Assignment:  Card Game
// Purpose:			This file is written to unit test all functions that are part
//              of the included interface.
// Hours:       0.5
//******************************************************************************

#include <gtest/gtest.h>

// interface to unit test
#include "../include/Deck.h"

// Each unit test for a given function is added below
TEST (DeckTest, DefaultConstructor) {
  Deck cDeck;
  // checks if deck is correct size 
  EXPECT_EQ (52, cDeck.size ());

  // checks if deck is ordered correctly
  Card cCard = cDeck.dealCard ();
  EXPECT_EQ ("S", cCard.getSuit ());
  EXPECT_EQ ("Q", cCard.getDenomination ());
  cCard = cDeck.dealCard ();
  EXPECT_EQ ("S", cCard.getSuit ());
  EXPECT_EQ ("K", cCard.getDenomination ());
}

TEST (DeckTest, CopyConstructor) {
  Deck cDeck, cDeck2 (cDeck);
  // checks if deck is correct size 
  EXPECT_EQ (52, cDeck2.size ());

  // checks if deck is ordered correctly
  Card cCard = cDeck2.dealCard ();
  EXPECT_EQ ("S", cCard.getSuit ());
  EXPECT_EQ ("Q", cCard.getDenomination ());
  cCard = cDeck2.dealCard ();
  EXPECT_EQ ("S", cCard.getSuit ());
  EXPECT_EQ ("K", cCard.getDenomination ());
}

TEST (DeckTest, addCard) {
  Deck cDeck;
  Card cCard ("S", "A");

  cDeck.addCard (cCard);
  EXPECT_EQ (53, cDeck.size ());

  cCard = cDeck.dealCard ();
  EXPECT_EQ ("S", cCard.getSuit ());
  EXPECT_EQ ("A", cCard.getDenomination ());
}

TEST (DeckTest, dealCard) {
  Deck cDeck;
  Card cCard = cDeck.dealCard ();

  EXPECT_EQ ("S", cCard.getSuit ());
  EXPECT_EQ ("Q", cCard.getDenomination ());

  cCard = cDeck.dealCard ();
  EXPECT_EQ ("S", cCard.getSuit ());
  EXPECT_EQ ("K", cCard.getDenomination ());
}

TEST (DeckTest, dealCardExceptions) {
  Deck cDeck;
  cDeck.clear ();

  EXPECT_THROW (cDeck.dealCard (), std::out_of_range);
}

TEST (DeckTest, size) {
  Deck cDeck;

  EXPECT_EQ (52, cDeck.size ());
  cDeck.dealCard ();
  EXPECT_EQ (51, cDeck.size ());
}

TEST (DeckTest, shuffle) {
  const std::string SHUFFLED_DECK = "QS JS 10D 8D KD 3D 4C 9S 7D 2D AS 5S 10H "
    "KH 3C QC 2H 6D 3S 4D AC 7C 2C 9H 5C JH JD 4S 7H JC 7S QD 8H 10C 10S 9D AH "
    "5D 9C 4H 5H 8S 6S 3H 2S QH 8C 6H KC KS AD 6C";
  Deck cDeck;
  std::ostringstream cOut;

  srand (3);
  cDeck.shuffle ();
  cOut << cDeck;
  EXPECT_EQ (SHUFFLED_DECK, cOut.str ());
}

TEST (DeckTest, clear) {
  Deck cDeck;

  EXPECT_EQ (52, cDeck.size ());
  cDeck.clear ();
  EXPECT_EQ (0, cDeck.size ());
}

TEST (DeckTest, insertionOperator) {
  const std::string UNSHUFFLED_DECK = "10H 2H 3H 4H 5H 6H 7H 8H 9H AH JH KH QH "
    "10C 2C 3C 4C 5C 6C 7C 8C 9C AC JC KC QC "
    "10D 2D 3D 4D 5D 6D 7D 8D 9D AD JD KD QD "
    "10S 2S 3S 4S 5S 6S 7S 8S 9S AS JS KS QS";
  Deck cDeck;
  std::ostringstream cOut;
  cOut << cDeck;
  EXPECT_EQ (UNSHUFFLED_DECK, cOut.str ());
}