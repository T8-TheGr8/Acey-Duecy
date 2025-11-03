//******************************************************************************
// File name:   Card.cpp
// Author:      Tate Woodward, Pacific University
// Date:        4/7/25
// Class:       CS-250
// Assignment:  Card Game
// Purpose:     Card implementation
// Hours:       0.75
//******************************************************************************
#include "../include/Card.h"
#include <string>
#include <ostream>
#include <vector>
#include <map>
#include <exception>

const std::vector<std::string> Card::SUITS = {
  "H", "C", "D", "S"
};

const std::map<std::string, int> Card::DENOMINATION_VALUES = {
  {"A", 1},{"2", 2},{"3", 3},{"4", 4},{"5", 5},{"6", 6}, {"7", 7},
  {"8", 8}, {"9", 9}, {"10", 10}, {"J", 11}, {"Q", 12}, {"K", 13}
};

/*******************************************************************************
Function:     Parameterized Constructor

Description:  Creates a card with a suit and denomination
              
Parameter:    rcSuit         - the suit
              rcDenomination - the denomination 

Returned      n/a
*******************************************************************************/
Card::Card (const std::string& rcSuit, const std::string& rcDenomination) {
  setDenomination (rcDenomination);
  setSuit (rcSuit);
}

/*******************************************************************************
Function:     Copy Constructor

Description:  Creates a copy of the card passed through as an argument
              
Parameter:    rcCard - the card being copied

Returned      n/a
*******************************************************************************/
Card::Card (const Card& rcCard) {
  setDenomination (rcCard.getDenomination ());
  setSuit (rcCard.getSuit ());
}

/*******************************************************************************
Function:     Destructor

Description:  Destructs
              
Parameter:    None

Returned      n/a
*******************************************************************************/
Card::~Card () {
  // Destructor
}

/*******************************************************************************
Function:     getSuit

Description:  Gets the suit of the card
              
Parameter:    None

Returned      The suit
*******************************************************************************/
std::string Card::getSuit () const {
  return mcSuit;
}

/*******************************************************************************
Function:     getDenomination

Description:  Gets the denomination of the card
              
Parameter:    None

Returned      The denomination
*******************************************************************************/
std::string Card::getDenomination () const {
  return mcDenomination;
}

/*******************************************************************************
Function:     getDenominationValue

Description:  Returns the int value of the card denomination
              
Parameter:    None

Returned      The int value of the card denomination
*******************************************************************************/
size_t Card::getDenominationValue () const {
  return DENOMINATION_VALUES.at (mcDenomination);
}

/*******************************************************************************
Function:     getCard

Description:  Returns the card that called this function
              
Parameter:    None

Returned      A pointer to the object that called this function
*******************************************************************************/
Card Card::getCard () const {
  return *this;
}

/*******************************************************************************
Function:     operator==

Description:  Checks if a card is equal to another card 
              
Parameter:    rcCard - the card being checked for equality

Returned      t/f
*******************************************************************************/
bool Card::operator== (const Card& rcCard) const {
  return rcCard.getDenomination () == mcDenomination
    && rcCard.getSuit () == mcSuit;
}

/*******************************************************************************
Function:     operator<< 

Description:  rcOutStream - the output stream 
              rcCard      - the card being output 
              
Parameter:    None

Returned      the output stream 
*******************************************************************************/
std::ostream& operator<< (std::ostream& rcOutStream, const Card& rcCard) {
  rcOutStream << rcCard.getDenomination () << rcCard.getSuit ();
  return rcOutStream;
}

/*******************************************************************************
Function:     setSuit

Description:  Sets the suit of the card
              
Parameter:    rcSuit - the suit being set 

Returned      void
*******************************************************************************/
void Card::setSuit (const std::string& rcSuit) {
  bool bIsIn = false;
  for (size_t i = 0; i < SUITS.size (); i++) {
    if (SUITS.at (i) == rcSuit) {
      bIsIn = true;
    }
  }
  if (!bIsIn) {
    throw std::invalid_argument ("Card Exception: Invalid suit");
  }
  mcSuit = rcSuit;
}

/*******************************************************************************
Function:     setDenomination

Description:  sets the denomination of the card
              
Parameter:    rcDenomination - the denomination

Returned      void
*******************************************************************************/
void Card::setDenomination (const std::string& rcDenomination) {
  if (DENOMINATION_VALUES.find (rcDenomination) == DENOMINATION_VALUES.end ()) {
    throw std::invalid_argument ("Card Exception: Invalid denomination");
  }
  mcDenomination = rcDenomination;
}