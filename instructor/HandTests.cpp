#include <gtest/gtest.h>

// interface to unit test
#include "../include/Card.h"
#include "../include/Hand.h"

// Each unit test for a given function is added below

TEST(HandTest, defaultConstructor) {
  Hand cHand;
  EXPECT_EQ(0, cHand.size());
}

TEST(HandTest, copyConstructor) {
  Hand cHand;
  cHand.addCard(Card("H", "A"));
  Hand cHand2(cHand);

  EXPECT_EQ(1, cHand2.size());
  EXPECT_EQ("H", cHand2.getCard(0).getSuit());
  EXPECT_EQ("A", cHand2.getCard(0).getDenomination());
}

TEST(HandTest, addCard) {
  Hand cHand;
  cHand.addCard(Card("H", "A"));

  EXPECT_EQ(1, cHand.size());
  EXPECT_EQ("H", cHand.getCard(0).getSuit());
  EXPECT_EQ("A", cHand.getCard(0).getDenomination());
}

TEST(HandTest, addCardIndex) {
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

TEST(HandTest, addCardException) {
  Hand cHand;
  cHand.addCard(Card("H", "A"));

  EXPECT_THROW(cHand.addCard(Card("C", "2"), 2), std::out_of_range);
  EXPECT_THROW(cHand.addCard(Card("C", "2"), 10), std::out_of_range);
}

TEST(HandTest, removeCard) {
  Hand cHand;
  cHand.addCard(Card("H", "A"));
  cHand.addCard(Card("C", "2"));
  
  Card cCard2 = cHand.removeCard(0);
  EXPECT_EQ(1, cHand.size());
  EXPECT_EQ("H", cCard2.getSuit());
  EXPECT_EQ("A", cCard2.getDenomination());

  cCard2 = cHand.removeCard(0);
  EXPECT_EQ("C", cCard2.getSuit());
  EXPECT_EQ("2", cCard2.getDenomination());
  EXPECT_EQ(0, cHand.size());
}

TEST(HandTest, removeCardException) {
  Hand cHand;
  cHand.addCard(Card("H", "A"));

  EXPECT_THROW(cHand.removeCard(1), std::out_of_range);
  EXPECT_NO_THROW(cHand.removeCard(0));
  EXPECT_THROW(cHand.removeCard(0), std::out_of_range);
}

TEST(HandTest, size) {
  Hand cHand;
  cHand.addCard(Card("H", "A"));
  cHand.addCard(Card("C", "2"));

  EXPECT_EQ(2, cHand.size());
}

TEST(HandTest, getCard) {
  Hand cHand;
  cHand.addCard(Card("H", "A"));
  cHand.addCard(Card("C", "2"));

  EXPECT_EQ("H", cHand.getCard(0).getSuit());
  EXPECT_EQ("A", cHand.getCard(0).getDenomination());
  EXPECT_EQ("C", cHand.getCard(1).getSuit());
  EXPECT_EQ("2", cHand.getCard(1).getDenomination());
}

TEST(HandTest, getCardException) {
  Hand cHand;
  cHand.addCard(Card("H", "A"));

  EXPECT_THROW(cHand.getCard(1), std::out_of_range);
  EXPECT_NO_THROW(cHand.removeCard(0));
  EXPECT_THROW(cHand.getCard(0), std::out_of_range);
}

TEST(HandTest, clear) {
  Hand cHand;
  cHand.addCard(Card("H", "A"));
  cHand.addCard(Card("C", "2"));
  cHand.clear();

  cHand.addCard(Card("D", "3"));
  cHand.addCard(Card("S", "4"));
  EXPECT_EQ(2, cHand.size());

  cHand.clear();
  EXPECT_EQ(0, cHand.size());
}

TEST(HandTest, operatorInsertion) {
  Hand cHand;
  cHand.addCard(Card("H", "A"));
  cHand.addCard(Card("C", "2"));
  cHand.addCard(Card("D", "3"));
  cHand.addCard(Card("S", "4"));

  std::ostringstream oss;
  oss << cHand;
  EXPECT_EQ("AH 2C 3D 4S", oss.str());
}
