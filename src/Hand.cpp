//******************************************************************************
// File name:   Hand.cpp
// Author:      Tate Woodward, Pacific University
// Date:        4/7/25
// Class:       CS-250
// Assignment:  Card Game
// Purpose:     Hand implementation
// Hours:       0.5
//******************************************************************************
#include "../include/Hand.h"
#include <exception>

/*******************************************************************************
Function:     Default Constructor

Description:  Does nothing

Parameter:    n/a

Returned      n/a
*******************************************************************************/
Hand::Hand () {

}

/*******************************************************************************
Function:     Copy Constructor

Description:  Creates a copy of the hand passed through as an argument

Parameter:    rcHand - the and being copied

Returned      n/a
*******************************************************************************/
Hand::Hand (const Hand& rcHand) {
  mcCards = rcHand.mcCards;
}

/*******************************************************************************
Function:     Destructor

Description:  Destructs

Parameter:    n/a

Returned      n/a
*******************************************************************************/
Hand::~Hand () {

}

/*******************************************************************************
Function:     addCard

Description:  Adds a card to the hand

Parameter:    rcCard - the card being added

Returned      the object that called this function
*******************************************************************************/
Hand Hand::addCard (const Card& rcCard) {
  mcCards.push_back (rcCard);
  return *this;
}

/*******************************************************************************
Function:     addCard

Description:  Adds a card to a specific index

Parameter:    rcCard - the card being added
              index  - the index being added to

Returned      n/a
*******************************************************************************/
Hand Hand::addCard (const Card& rcCard, size_t index) {
  const int EMPTY = 0;
  if (EMPTY == size () && 0 == index) {
    mcCards.push_back (rcCard);
  }
  else {
    if (index > size ()) {
      throw std::out_of_range ("Hand Exception: Invalid hand index");
    }
    else if (index == size ()) {
      mcCards.push_back (rcCard);
    }
    else {
      mcCards.insert (mcCards.begin () + index, rcCard);
    }
  }
  return *this;
}

/*******************************************************************************
Function:     removeCard

Description:  Removes the card from a specific index

Parameter:    index - the index being removed

Returned      The card being removed
*******************************************************************************/
Card Hand::removeCard (size_t index) {
  if (index >= size ()) {
    throw std::out_of_range ("Hand Exception: Invalid hand index");
  }
  Card cCard = mcCards.at (index);
  mcCards.erase (mcCards.begin () + index);
  return cCard;
}

/*******************************************************************************
Function:     size

Description:  Returns the size of the hand

Parameter:    None

Returned      the size of the hand
*******************************************************************************/
size_t Hand::size () const {
  return mcCards.size ();
}

/*******************************************************************************
Function:     getCard

Description:  Returns a card from a specific index

Parameter:    index - the index being returned

Returned      The card at the passed in index
*******************************************************************************/
Card Hand::getCard (size_t index) const {
  if (index >= size ()) {
    throw std::out_of_range ("Hand Exception: Invalid hand index");
  }
  return mcCards.at (index);
}

/*******************************************************************************
Function:     clear

Description:  Clears the hand of cards

Parameter:    None

Returned      void
*******************************************************************************/
void Hand::clear () {
  mcCards.clear ();
}

/*******************************************************************************
Function:     operator<<

Description:  Overloads the insertion operator so that a hand can directly be
              output to an output stream

Parameter:    rcOut  - output stream
              rcHand - the hand being output

Returned      Output stream
*******************************************************************************/
std::ostream& operator<< (std::ostream& rcOut, const Hand& rcHand) {
  bool bFirst = true;
  for (int i = 0; i < rcHand.size (); i++) {
    if (bFirst) {
      bFirst = false;
    }
    else {
      rcOut << " ";
    }
    rcOut << rcHand.mcCards.at (i);
  }
  return rcOut;
}