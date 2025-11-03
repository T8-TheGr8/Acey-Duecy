//******************************************************************************
// File name:   HumanInBetweenPlayer.cpp
// Author:      Tate Woodward, Pacific University
// Date:        4/19/25
// Class:       CS-250
// Assignment:  Card Game
// Purpose:     HumanInBetweenPlayer implementation
// Hours:       0.50
//******************************************************************************

#include "../include/HumanInBetweenPlayer.h"

/*******************************************************************************
Function:     Default Constructor

Description:  Creates a humanInBetweenPlayer, calls default constructor of 
              InBetweenPlayer
              
Parameter:    none

Returned      n/a
*******************************************************************************/
HumanInBetweenPlayer::HumanInBetweenPlayer () : InBetweenPlayer() {

}

/*******************************************************************************
Function:     Parameterized Constructor

Description:  Creates a HIBP initialized to the parameters. 
              
Parameter:    rcName - the name 
              rcBank - the bank

Returned      n/a
*******************************************************************************/
HumanInBetweenPlayer::HumanInBetweenPlayer (const std::string& rcName, 
  const Bank& rcBank, const InBetweenHand& rcInBetweenHand) : 
  InBetweenPlayer(rcName, rcBank, rcInBetweenHand) {
}

/*******************************************************************************
Function:     Copy Constructor

Description:  Creates a copy of the parameter 
              
Parameter:    rcHumanInBetweenPlayer - the object being copied

Returned      n/a
*******************************************************************************/
HumanInBetweenPlayer::HumanInBetweenPlayer (const HumanInBetweenPlayer& 
  rcHumanInBetweenPlayer) {
  (*this) = rcHumanInBetweenPlayer;
}

/*******************************************************************************
Function:     Destructor

Description:  Destructs
              
Parameter:    n/a

Returned      n/a
*******************************************************************************/
HumanInBetweenPlayer::~HumanInBetweenPlayer () {

}

/*******************************************************************************
Function:     getBet

Description:  Gets a bet from the user, error checked to be positive, less than 
              or equal to the pot size, and less than or equal to their balance
              
Parameter:    potSize - the current pot size

Returned      int     - the users bet 
*******************************************************************************/
int HumanInBetweenPlayer::getBet (int potSize) const {
  const int PROPER_HAND_SIZE = 2;
  int betAmount; 

  if (this->getInBetweenHand().size() != PROPER_HAND_SIZE) {
    throw std::runtime_error
      ("HumanInBetweenPlayer Exception::getBet: Invalid hand size");
  }

  std::cout << "Place your bet: "; 
  std::cin >> betAmount; 

  if (betAmount <= 0 || betAmount > this->getBank().getBalance()) {
    throw std::runtime_error
      ("HumanInBetweenPlayer Exception::getBet: Invalid bet amount");
  }
  if (betAmount > potSize) {
    throw std::runtime_error
      ("HumanInBetweenPlayer Exception::getBet: Bet cannot exceed pot size");
  }

  return betAmount; 
}