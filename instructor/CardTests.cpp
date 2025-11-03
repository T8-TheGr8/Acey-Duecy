#include <gtest/gtest.h>

// interface to unit test
#include "../include/Card.h"

TEST (CardTest, parameterizedConstructor) {
  Card cCard2("H", "A"); 

  EXPECT_EQ("A", cCard2.getDenomination());
  EXPECT_EQ("H", cCard2.getSuit());
}

TEST (CardTest, parameterizedConstructorException) {
  EXPECT_THROW(Card("X", "A"), std::invalid_argument);
  EXPECT_THROW(Card("H", "X"), std::invalid_argument);
  EXPECT_THROW(Card("X", "X"), std::invalid_argument);
}

TEST (CardTest, copyConstructor) {
  Card cCard("H", "A");
  Card cCard2(cCard);

  EXPECT_EQ("A", cCard2.getDenomination());
  EXPECT_EQ("H", cCard2.getSuit());
}

TEST (CardTest, getSuit) {
  Card cCard("H", "A");

  EXPECT_EQ("H", cCard.getSuit());
}

TEST (CardTest, getDenomination) {
  Card cCard("H", "A");

  EXPECT_EQ("A", cCard.getDenomination());
}

TEST (CardTest, getDenominationValue) {
  Card cCard("H", "A");
  Card cCard2("H", "10");
  Card cCard3("H", "J");
  Card cCard4("H", "Q");
  Card cCard5("H", "K");

  EXPECT_EQ(1, cCard.getDenominationValue());
  EXPECT_EQ(10, cCard2.getDenominationValue());
  EXPECT_EQ(11, cCard3.getDenominationValue());
  EXPECT_EQ(12, cCard4.getDenominationValue());
  EXPECT_EQ(13, cCard5.getDenominationValue());
}

TEST (CardTest, getCard) {
  Card cCard("H", "A");
  Card cCard2 = cCard.getCard();

  EXPECT_EQ("A", cCard2.getDenomination());
  EXPECT_EQ("H", cCard2.getSuit());
}

TEST (CardTest, operatorEqual) {
  Card cCard("H", "A");
  Card cCard2("H", "A");

  EXPECT_TRUE(cCard == cCard2);
}

TEST (CardTest, operatorInsertion) {
  Card cCard("H", "A");
  std::ostringstream oss;

  oss << cCard;

  EXPECT_EQ("AH", oss.str());
}
