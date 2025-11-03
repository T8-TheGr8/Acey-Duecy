//******************************************************************************
// File name:   InBetweenHand.cpp
// Author:      Tate Woodward, Pacific University
// Date:        4/7/25
// Class:       CS-250
// Assignment:  Card Game
// Purpose:     InBetweenHand implementation
// Hours:       1
//******************************************************************************
#include "../include/InBetweenHand.h"

/*******************************************************************************
Function:     Default constructor

Description:  Calls default constructor of hand

Parameter:    n/a

Returned      n/a
*******************************************************************************/
InBetweenHand::InBetweenHand () : Hand () {

}

/*******************************************************************************
Function:     Copy constructor

Description:  Creates a new hand that's a copy of the hand passed in

Parameter:    rcHand - the hand being copied

Returned      n/a
*******************************************************************************/
InBetweenHand::InBetweenHand (const InBetweenHand& rcHand) : Hand (rcHand) {

}

/*******************************************************************************
Function:     Destructor

Description:  Destructs

Parameter:    n/a

Returned      n/a
*******************************************************************************/
InBetweenHand::~InBetweenHand () {

}

/*******************************************************************************
Function:     addCard

Description:  Adds a card to the InBetweenHand, won't go over 2 cards.

Parameter:    rcCard - the card being added

Returned      Hand   - a copy of the hand
*******************************************************************************/
Hand InBetweenHand::addCard (const Card& rcCard) {
  // extra hand object is created and copies the cards in the inBetweenHand
  // because I couldn't figure out any other way to return a Hand object
  const int MAX_HAND_SIZE = 2, EMPTY = 0;
  Hand cHand;
  
  if (size() >= MAX_HAND_SIZE) {
    throw std::runtime_error
    ("InBetweenHand Exception: Hand cannot have more than 2 cards");
  }
  if (EMPTY == size ()) {
    Hand::addCard (rcCard);
    cHand.addCard (rcCard);
  }
  // checks if card being added is larger or equal to  card already in the hand 
  else if (int(rcCard.getDenominationValue ()) - 
    int(getCard (0).getDenominationValue ()) >= 0) {
    Hand::addCard (rcCard);
    cHand.addCard (getCard (0));
    cHand.addCard (rcCard);
  }
  else {
    Hand::addCard (rcCard, 0); 
    cHand.addCard (rcCard);
    cHand.addCard (getCard(0));
  }
  return cHand;
}

/*******************************************************************************
Function:     getDistance

Description:  Finds the distance between the two cards in the hand

Parameter:    None

Returned      the distance between the two cards in the hand.
*******************************************************************************/
size_t InBetweenHand::getDistance () const {
  const int BIG_CARD = 1, SMALL_CARD = 0, SIZE_REQ = 2;
  if (SIZE_REQ != size ()) {
    throw std::runtime_error
      ("InBetweenHand Exception: Hand must have exactly 2 cards");
  }
  return  getCard (BIG_CARD).getDenominationValue ()
  - getCard (SMALL_CARD).getDenominationValue ();
}