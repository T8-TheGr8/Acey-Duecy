//******************************************************************************
// File name:   AIConservativeInBetweenPlayer.cpp
// Author:      Tate Woodward, Pacific University
// Date:        4/19/25
// Class:       CS-250
// Assignment:  Card Game
// Purpose:     AIConservativeInBetweenPlayer implementation
// Hours:       0.25
//******************************************************************************

#include "../include/AIConservativeInBetweenPlayer.h"
#include "../include/InBetweenGamePlay.h"

/*******************************************************************************
Function:     Default Constructor

Description:  Creates an AI player. Calls in between default constructor. 
              Increments the static counter for number of AI players created. 
              
Parameter:    None

Returned      n/a
*******************************************************************************/
AIConservativeInBetweenPlayer::AIConservativeInBetweenPlayer () :
  InBetweenPlayer() {
  AIPlayerCreated();
}

/*******************************************************************************
Function:     Parameterized Constructor

Description:  Creates an AI player initialized to the parameters. Increments the 
              static counter for number of AI players created. 
              
Parameter:    rcName          - the name 
              rcBank          - the bank 
              rcInBetweenHand - the hand 

Returned      n/a
*******************************************************************************/
AIConservativeInBetweenPlayer::AIConservativeInBetweenPlayer 
  (const std::string& rcName, const Bank& rcBank, 
  const InBetweenHand& rcInBetweenHand) :
  InBetweenPlayer (rcName, rcBank, rcInBetweenHand) {
  AIPlayerCreated();
}

/*******************************************************************************
Function:     Copy Constructor

Description:  Creates a copy of the object passed in as an argument
              
Parameter:    rcConservativeInBetweenPlayer - the object being copied 

Returned      n/a
*******************************************************************************/
AIConservativeInBetweenPlayer::AIConservativeInBetweenPlayer 
  (const AIConservativeInBetweenPlayer& rcConservativeInBetweenPlayer) {
    (*this) = rcConservativeInBetweenPlayer;
    AIPlayerCreated(); // increments AI player counter
}

/*******************************************************************************
Function:     Destructor 

Description:  Destructs
              
Parameter:    n/a

Returned      n/a
*******************************************************************************/
AIConservativeInBetweenPlayer::~AIConservativeInBetweenPlayer () {

}

/*******************************************************************************
Function:     getBet

Description:  Gets a bet for an AI player. If the distance between the cards in 
              their hand is equal to or greater than 10, they bet 3, otherwise 
              they bet 1. 
              
Parameter:    potSize - the current pot size

Returned      bet     - the bet
*******************************************************************************/
int AIConservativeInBetweenPlayer::getBet (int potSize) const {
  const int GREAT_DISTANCE = 10, GOOD_DISTANCE = 8;
  int bet; 
  std::cout << "Place your bet: "; 
  if (this->getInBetweenHand().getDistance() > GREAT_DISTANCE) {
    
    // Check player's balance and pot size 
    if (this->getBank().getBalance() >= InBetweenGamePlay::HIGH 
      && potSize >= InBetweenGamePlay::HIGH) {
      bet = InBetweenGamePlay::HIGH;
    } else if (this->getBank().getBalance() == InBetweenGamePlay::MEDIUM 
      && potSize >= InBetweenGamePlay::MEDIUM) {
      bet = InBetweenGamePlay::MEDIUM;
    } else {
      bet = InBetweenGamePlay::LOW;
    }
  } else if (this->getInBetweenHand().getDistance() > GOOD_DISTANCE) {
    
    // Check player's balance and pot size
    if (this->getBank().getBalance() >= InBetweenGamePlay::MEDIUM 
      && potSize >= InBetweenGamePlay::MEDIUM) {
      bet = InBetweenGamePlay::MEDIUM;
    } else {
      bet = InBetweenGamePlay::LOW;
    }
  } else {
    bet = InBetweenGamePlay::LOW;
  }
  std::cout << bet << std::endl;
  return bet; 
} 