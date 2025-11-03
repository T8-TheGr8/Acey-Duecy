#include <gtest/gtest.h>

// interface to unit test
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include "../include/Card.h"
#include "../include/Deck.h"

// Each unit test for a given function is added below

TEST (DeckTest, defaultConstructor) {
  Deck cDeck;

  EXPECT_EQ(52, cDeck.size());
  Card cCard = cDeck.dealCard();
  EXPECT_EQ("Q", cCard.getDenomination());
  EXPECT_EQ("S", cCard.getSuit());
  EXPECT_EQ(51, cDeck.size());

  while (cDeck.size() > 0) {
    cCard = cDeck.dealCard();
  }

  EXPECT_EQ(0, cDeck.size());
  EXPECT_EQ("10", cCard.getDenomination());
  EXPECT_EQ("H", cCard.getSuit());
}

TEST (DeckTest, copyConstructor) {
  Deck cDeck;
  Deck cDeck2(cDeck);

  EXPECT_EQ(52, cDeck2.size());
  Card cCard = cDeck2.dealCard();
  EXPECT_EQ("Q", cCard.getDenomination());
  EXPECT_EQ("S", cCard.getSuit());
  EXPECT_EQ(51, cDeck2.size());
  EXPECT_EQ(52, cDeck.size());

  while (cDeck2.size() > 0) {
    cCard = cDeck2.dealCard();
  }
  EXPECT_EQ(0, cDeck2.size());
  EXPECT_EQ("10", cCard.getDenomination());
  EXPECT_EQ("H", cCard.getSuit());
  EXPECT_EQ(52, cDeck.size());
}

TEST (DeckTest, addCard) {
  Deck cDeck;
  Card cCard("H", "A");  // swapped
  cDeck.addCard(cCard);

  EXPECT_EQ(53, cDeck.size());
  Card cCard2 = cDeck.dealCard();
  EXPECT_EQ("A", cCard2.getDenomination());
  EXPECT_EQ("H", cCard2.getSuit());
  EXPECT_EQ(1, cCard2.getDenominationValue());
  EXPECT_EQ(52, cDeck.size());

  while (cDeck.size() > 0) {
    cCard = cDeck.dealCard();
  }

  EXPECT_EQ(0, cDeck.size());
  Card cCard3("H", "K");  // swapped
  cDeck.addCard(cCard3);
  EXPECT_EQ(1, cDeck.size());
  cCard2 = cDeck.dealCard();
  EXPECT_EQ("K", cCard2.getDenomination());
  EXPECT_EQ("H", cCard2.getSuit());

  Card cCard4 = cCard2.getCard();
  EXPECT_EQ("K", cCard4.getDenomination());
  EXPECT_EQ("H", cCard4.getSuit());
  EXPECT_EQ(13, cCard2.getDenominationValue());

  EXPECT_EQ(0, cDeck.size());
  EXPECT_TRUE(cCard2 == cCard4);
  EXPECT_FALSE(cCard2 == cCard);
}

TEST (DeckTest, dealCard) {
  Deck cDeck;

  Card cCard = cDeck.dealCard();
  EXPECT_EQ("Q", cCard.getDenomination());
  EXPECT_EQ("S", cCard.getSuit());
  EXPECT_EQ(51, cDeck.size());
  cCard = cDeck.dealCard();
  EXPECT_EQ("K", cCard.getDenomination());
  EXPECT_EQ("S", cCard.getSuit());
  EXPECT_EQ(50, cDeck.size());

  while (cDeck.size() > 0) {
    cCard = cDeck.dealCard();
  }
  EXPECT_EQ(0, cDeck.size());
  EXPECT_EQ("10", cCard.getDenomination());
  EXPECT_EQ("H", cCard.getSuit());
}

TEST (DeckTest, dealCardException) {
  Deck cDeck;

  while (cDeck.size() > 0) {
    cDeck.dealCard();
  }

  EXPECT_THROW(cDeck.dealCard(), std::out_of_range);
}

TEST (DeckTest, size) {
  Deck cDeck;

  // delete 1 card at a time checking size each time. do this in a loop
  for (size_t i = 0; i < 52; ++i) {
    EXPECT_EQ(52 - i, cDeck.size());
    cDeck.dealCard();
  }

  EXPECT_EQ(0, cDeck.size());

  // add a card and check size
  Card cCard("H", "A");  // swapped
  cDeck.addCard(cCard);
  EXPECT_EQ(1, cDeck.size());

  // delete the card and check size
  cDeck.dealCard();
  EXPECT_EQ(0, cDeck.size());
}

TEST (DeckTest, shuffle) {
  srand(3);

  Deck cDeck;

  cDeck.shuffle();

  // write results to a stringstream
  std::ostringstream oss;

  oss << cDeck;
  EXPECT_EQ("QS JS 10D 8D KD 3D 4C 9S 7D 2D AS 5S 10H KH 3C QC 2H 6D 3S 4D AC 7C 2C 9H 5C JH JD 4S 7H JC 7S QD 8H 10C 10S 9D AH 5D 9C 4H 5H 8S 6S 3H 2S QH 8C 6H KC KS AD 6C", oss.str());

  srand(0);
  Deck cDeck2;
  cDeck2.shuffle();
  oss.str("");
  oss.clear();
  oss << cDeck2;
  EXPECT_EQ("9D KS JS 8C 3C 10S 7S 7D 4S QD 4H 8S AD 6S 10H 8D 8H 7H QC 2S 3H 6H 9C 4C AS QH 6C 9S 5S 2C 9H KH KC 10C 5D QS AC 5H 4D 10D 3S 2D 6D AH 3D 2H JC 5C 7C KD JD JH", oss.str());
}

TEST (DeckTest, clear) {
  Deck cDeck;

  EXPECT_EQ(52, cDeck.size());

  cDeck.clear();

  EXPECT_EQ(0, cDeck.size());

  Card cCard("H", "A");  // swapped
  cDeck.addCard(cCard);
  EXPECT_EQ(1, cDeck.size());

  // delete the card and check size
  cDeck.clear();
  EXPECT_EQ(0, cDeck.size());

  cDeck.clear();
}

TEST (DeckTest, operatorInsertion) {
  Deck cDeck;
  std::ostringstream oss;
  oss << cDeck;
  EXPECT_EQ("10H 2H 3H 4H 5H 6H 7H 8H 9H AH JH KH QH 10C 2C 3C 4C 5C 6C 7C 8C 9C AC JC KC QC 10D 2D 3D 4D 5D 6D 7D 8D 9D AD JD KD QD 10S 2S 3S 4S 5S 6S 7S 8S 9S AS JS KS QS", oss.str());
  oss.str("");
  oss.clear();
  cDeck.clear();
  oss << cDeck;
  EXPECT_EQ("", oss.str());
  cDeck.addCard(Card("H", "A"));  // swapped
  oss.str("");
  oss.clear();
  oss << cDeck;
  EXPECT_EQ("AH", oss.str());
  cDeck.addCard(Card("H", "2"));  // swapped
  oss.str("");
  oss.clear();
  oss << cDeck;
  EXPECT_EQ("AH 2H", oss.str());
}
