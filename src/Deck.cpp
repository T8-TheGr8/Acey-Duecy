//******************************************************************************
// File name:   Deck.cpp
// Author:      Tate Woodward, Pacific University
// Date:        4/7/25
// Class:       CS-250
// Assignment:  Card Game
// Purpose:     Deck implementation
// Hours:       0.5
//******************************************************************************
#include "../include/Deck.h"
#include <iostream>
#include <vector> 
#include <exception> 
#include <random>

/*******************************************************************************
Function:     Default Constructor

Description:  Creates an unshuffled deck of cards
              
Parameter:    None

Returned      n/a
*******************************************************************************/
Deck::Deck () {
  const std::map<int, std::string> NUM_TO_DENOM = {
    {1, "10"}, {2, "2"}, {3, "3"}, {4, "4"}, {5, "5"}, {6, "6"}, {7, "7"},
    {8, "8"}, {9, "9"}, {10, "A"}, {11, "J"}, {12, "K"}, {13, "Q"}
  };

  for (int suit = 0; suit < Card::SUITS.size (); suit++) {
    for (int denom = 1; denom <= Card::DENOMINATION_VALUES.size (); denom++) {
      Card cCard (Card::SUITS.at (suit), NUM_TO_DENOM.at (denom));
      addCard (cCard);
    }
  }
}

/*******************************************************************************
Function:     Copy Constructor

Description:  Creates a deck of cards, copied from the deck passed through 
              the as the argument
              
Parameter:    rcDeck - the deck being copied

Returned      n/a
*******************************************************************************/
Deck::Deck (const Deck& rcDeck) {
  for (int i = 0; i < rcDeck.size (); i++) {
    addCard (rcDeck.mcCards.at (i));
  }
}

/*******************************************************************************
Function:     Destructor 

Description:  Destructs
              
Parameter:    n/a

Returned      n/a
*******************************************************************************/
Deck::~Deck () {
  // Destructor
}

/*******************************************************************************
Function:     addCard

Description:  Adds a card to the end of the deck 
              
Parameter:    rcCard - the card being added

Returned      void
*******************************************************************************/
void Deck::addCard (const Card& rcCard) {
  mcCards.push_back (rcCard);
}

/*******************************************************************************
Function:     dealCard

Description:  Deals a card from the back of the deck (end of the vector)
              
Parameter:    None

Returned      Card - the card being dealt
*******************************************************************************/
Card Deck::dealCard () {
  const int EMPTY = 0;
  if (EMPTY == size ()) {
    throw std::out_of_range ("Deck Exception: No cards in deck");
  }
  Card cCard (mcCards.back ());
  mcCards.pop_back ();
  return cCard;
}

/*******************************************************************************
Function:     size

Description:  gets the size of the deck of cards 
              
Parameter:    None

Returned      size of vector
*******************************************************************************/
size_t Deck::size () const {
  return mcCards.size ();
}

/*******************************************************************************
Function:     shuffle

Description:  Shuffles the deck of cards 
              
Parameter:    None

Returned      n/a
*******************************************************************************/
void Deck::shuffle () {
  int cardIndex = size () - 1, randomIndex;

  while (cardIndex > 0) {
    randomIndex = rand () % cardIndex;
    Card cCard = mcCards.at (randomIndex);
    mcCards.at (randomIndex) = mcCards.at (cardIndex);
    mcCards.at (cardIndex) = cCard;
    cardIndex--;
  }
}

/*******************************************************************************
Function:     clear

Description:  Clears the vector of cards 
              
Parameter:    None

Returned      n/a
*******************************************************************************/
void Deck::clear () {
  mcCards.clear ();
}

/*******************************************************************************
Function:     operator<<

Description:  Overloads the insertion operator so it can directly output a deck
              to an output stream
              
Parameter:    rcOutStream - the output stream 
              rcDeck      - the deck being output

Returned      rcOutStream - the output stream 
*******************************************************************************/
std::ostream& operator<< (std::ostream& rcOutStream, const Deck& rcDeck) {
  bool bFirst = true;
  for (int i = 0; i < rcDeck.size (); i++) {
    if (bFirst) {
      bFirst = false;
    }
    else {
      rcOutStream << " ";
    }
    rcOutStream << rcDeck.mcCards.at (i);
  }
  return rcOutStream;
}