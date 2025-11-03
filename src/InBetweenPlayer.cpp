//******************************************************************************
// File name:   InBetweenPlayer.cpp
// Author:      Tate Woodward, Pacific University
// Date:        4/19/25
// Class:       CS-250
// Assignment:  Card Game
// Purpose:     InBetweenPlayer implementation
// Hours:       0.50
//******************************************************************************

#include "../include/InBetweenPlayer.h"

std::string InBetweenPlayer::defaultName = "Player";
int InBetweenPlayer::counter = 0;

/*******************************************************************************
Function:     Default Constructor

Description:  Sets the player's name to player_ + however many AI players
              there are.

Parameter:    None

Returned      n/a
*******************************************************************************/
InBetweenPlayer::InBetweenPlayer () {
  this->setName (InBetweenPlayer::defaultName + "_" + std::to_string (counter));
}

/*******************************************************************************
Function:     Parameterized Constructor

Description:  Initialies the player to the parameters

Parameter:    rcName - the name
              rcBank - the bank
              rcHand - the hand

Returned      n/a
*******************************************************************************/
InBetweenPlayer::InBetweenPlayer (const std::string& rcName, const Bank& rcBank,
  const InBetweenHand& rcHand) {
  this->setName (rcName);
  this->setBank (rcBank);
  this->setHand (rcHand);
}

/*******************************************************************************
Function:     Copy Constructor

Description:  Copies the passed in object

Parameter:    rcInBetweenPlayer - the object being copied

Returned      n/a
*******************************************************************************/
InBetweenPlayer::InBetweenPlayer (const InBetweenPlayer& rcInBetweenPlayer) {
  this->setName (rcInBetweenPlayer.getName ());
  this->setBank (rcInBetweenPlayer.getBank ());
  this->setHand (rcInBetweenPlayer.getInBetweenHand ());
}

/*******************************************************************************
Function:     Destructor

Description:  Destructs

Parameter:    n/a

Returned      n/a
*******************************************************************************/
InBetweenPlayer::~InBetweenPlayer () {

}

/*******************************************************************************
Function:     getName

Description:  Returns the name of the player

Parameter:    None

Returned      string - the name
*******************************************************************************/
std::string InBetweenPlayer::getName () const {
  return this->mcName;
}

/*******************************************************************************
Function:     getBank

Description:  Returns the bank of the player

Parameter:    None

Returned      Bank - the players bank
*******************************************************************************/
Bank InBetweenPlayer::getBank () const {
  return this->mcBank;
}

/*******************************************************************************
Function:     addToBank

Description:  Adds the passed in amount to the player's balance

Parameter:    amount - the amount being added

Returned      Bank   - returns the updated bank
*******************************************************************************/
Bank InBetweenPlayer::addToBank (int amount) {
  if (amount < 0) {
    throw std::invalid_argument
    ("InBetweenPlayer Exception::addToBank: amount must be positive");
  }
  mcBank.add (amount);
  return mcBank;
}

/*******************************************************************************
Function:     subtractFromBank

Description:  Subtracts the passed in amount from the player's balance

Parameter:    amount - the amount being subtracted

Returned      Bank   - the updated bank
*******************************************************************************/
Bank InBetweenPlayer::subtractFromBank (int amount) {
  if (amount < 0) {
    throw std::invalid_argument
    ("InBetweenPlayer Exception::subtractFromBank: amount must be positive");
  }
  mcBank.subtract (amount);
  return mcBank;
}

/*******************************************************************************
Function:     getInBetweenHand

Description:  Returns the player's inBetweenHand

Parameter:    None

Returned      InBetweenHand - the player's InBetweenHand
*******************************************************************************/
InBetweenHand InBetweenPlayer::getInBetweenHand () const {
  return this->mcInBetweenHand;
}

/*******************************************************************************
Function:     addToInBetweenHand

Description:  Adds a card to the player's hand

Parameter:    rcCard - the card being added

Returned      InBetweenHand - the updated hand
*******************************************************************************/
InBetweenHand InBetweenPlayer::addToInBetweenHand (const Card& rcCard) {
  mcInBetweenHand.addCard (rcCard);
  return this->getInBetweenHand ();
}

/*******************************************************************************
Function:     clearInBetweenHand

Description:  Clear's the player's hand

Parameter:    None

Returned      void
*******************************************************************************/
void InBetweenPlayer::clearInBetweenHand () {
  mcInBetweenHand.clear ();
}

/*******************************************************************************
Function:     clearBank

Description:  Clears the player's bank

Parameter:    None

Returned      void
*******************************************************************************/
void InBetweenPlayer::clearBank () {
  mcBank.clear ();
}

/*******************************************************************************
Function:     setName

Description:  Sets the player's name

Parameter:    rcName - the name

Returned      void
*******************************************************************************/
void InBetweenPlayer::setName (const std::string& rcName) {
  const std::string EMPTY = "";
  if (EMPTY == rcName) {
    throw std::invalid_argument
    ("InBetweenPlayer Exception::setName: name is empty");
  }
  mcName = rcName;
}

/*******************************************************************************
Function:     setBank

Description:  Set's a player's bank

Parameter:    rcBank - the bank being set

Returned      void
*******************************************************************************/
void InBetweenPlayer::setBank (const Bank& rcBank) {
  if (rcBank.getBalance () < 0) {
    throw std::invalid_argument
    ("InBetweenPlayer Exception::setBank: amount must be positive");
  }
  mcBank = rcBank;
}

/*******************************************************************************
Function:     setHand

Description:  sets a player's hand

Parameter:    rcHand - the hand being set

Returned      void
*******************************************************************************/
void InBetweenPlayer::setHand (const InBetweenHand& rcHand) {
  mcInBetweenHand = rcHand;
}

/*******************************************************************************
Function:     AIPlayerCreated

Description:  Increments the AI player counter

Parameter:    None

Returned      void
*******************************************************************************/
void InBetweenPlayer::AIPlayerCreated () {
  InBetweenPlayer::counter++;
}