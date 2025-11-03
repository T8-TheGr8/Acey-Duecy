#include <gtest/gtest.h>

// interface to unit test
#include "../include/Card.h"
#include "../include/Hand.h"
#include "../include/InBetweenHand.h"

// Each unit test for a given function is added below
TEST(InBetweenHandTest, defaultConstructor) {
  InBetweenHand cHand;
  EXPECT_EQ(0, cHand.size());
}

TEST(InBetweenHandTest, copyConstructor) {
  InBetweenHand cHand;
  cHand.addCard(Card("H", "A"));
  InBetweenHand cHand2(cHand);

  EXPECT_EQ(1, cHand2.size());
  EXPECT_EQ("H", cHand2.getCard(0).getSuit());
  EXPECT_EQ("A", cHand2.getCard(0).getDenomination());
}

TEST(InBetweenHandTest, addCard) {
  InBetweenHand cHand;
  cHand.addCard(Card("H", "10"));

  EXPECT_EQ(1, cHand.size());
  EXPECT_EQ("H", cHand.getCard(0).getSuit());
  EXPECT_EQ("10", cHand.getCard(0).getDenomination());

  // add 9
  cHand.addCard(Card("C", "9"));
  EXPECT_EQ(2, cHand.size());
  EXPECT_EQ("C", cHand.getCard(0).getSuit());
  EXPECT_EQ("9", cHand.getCard(0).getDenomination());

  // New hand: 10S, AC
  InBetweenHand cHand2;
  cHand2.addCard(Card("S", "10"));
  cHand2.addCard(Card("C", "A"));
  EXPECT_EQ(2, cHand2.size());
  EXPECT_EQ("C", cHand2.getCard(0).getSuit());
  EXPECT_EQ("A", cHand2.getCard(0).getDenomination());
  EXPECT_EQ("S", cHand2.getCard(1).getSuit());
  EXPECT_EQ("10", cHand2.getCard(1).getDenomination());

  // New hand: AC, AS
  InBetweenHand cHand3;
  cHand3.addCard(Card("C", "A"));
  cHand3.addCard(Card("S", "A"));
  EXPECT_EQ(2, cHand3.size());
  EXPECT_EQ("C", cHand3.getCard(0).getSuit());
  EXPECT_EQ("A", cHand3.getCard(0).getDenomination());
  EXPECT_EQ("S", cHand3.getCard(1).getSuit());
  EXPECT_EQ("A", cHand3.getCard(1).getDenomination());
}

TEST (InBetweenHandTest, addCardException) {
  InBetweenHand cHand;
  Card cCard ("H", "A");
  cHand.addCard (cCard);
  cHand.addCard (Card ("C", "2"));

  EXPECT_THROW (cHand.addCard (Card ("C", "3")), std::runtime_error);
  EXPECT_THROW (cHand.addCard (Card ("C", "4")), std::runtime_error);
}

TEST(InBetweenHandTest, getDistance) {
  InBetweenHand cHand;
  cHand.addCard(Card("C", "8"));
  cHand.addCard(Card("S", "J"));

  EXPECT_EQ(2, cHand.getDistance());
}

TEST(InBetweenHandTest, getDistanceException) {
  InBetweenHand cInBetweenHand;

  EXPECT_THROW (cInBetweenHand.getDistance (), std::runtime_error);
  cInBetweenHand.addCard (Card ("H", "A"));
  EXPECT_THROW (cInBetweenHand.getDistance (), std::runtime_error);
}
