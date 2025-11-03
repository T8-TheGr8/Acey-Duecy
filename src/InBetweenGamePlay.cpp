//******************************************************************************
// File name:   InBetweenGamePlay.cpp
// Author:      Tate Woodward, Pacific University
// Date:        4/19/25
// Class:       CS-250
// Assignment:  Card Game
// Purpose:     InBetweenGamePlay implementation
// Hours:       2
//******************************************************************************

#include "../include/InBetweenGamePlay.h"

int InBetweenGamePlay::roundCounter = 1;

/*******************************************************************************
Function:     Parameterized Constructor

Description:  Creates a game object with the passed in risk level 
              
Parameter:    rcRiskLevel - the risk level 

Returned      n/a
*******************************************************************************/
InBetweenGamePlay::InBetweenGamePlay (const RiskLevel& rcRiskLevel) {
  mcRiskLevel = rcRiskLevel;
  mcDeck.shuffle();
}

/*******************************************************************************
Function:     Destructor 

Description:  Deletes the dyanmically allocated players in the vector before
              destructing the object
              
Parameter:    n/a

Returned      n/a
*******************************************************************************/
InBetweenGamePlay::~InBetweenGamePlay () {
  for (auto& player : mcInBetweenPlayers) {
    delete player;
  }
}

/*******************************************************************************
Function:     addPlayer 

Description:  Adds a pointer to a player to the vector of pointers to players
              
Parameter:    pcInBetweenPlayer - a pointer to a player

Returned      void
*******************************************************************************/
void InBetweenGamePlay::addPlayer (InBetweenPlayer* pcInBetweenPlayer) {
  mcInBetweenPlayers.push_back (pcInBetweenPlayer);
}

/*******************************************************************************
Function:     printBanks

Description:  Prints the balance of each player
              
Parameter:    None

Returned      void
*******************************************************************************/
void InBetweenGamePlay::printBanks () const {
  for (auto player : mcInBetweenPlayers) {
    std::cout << player->getName () << "'s Bank: $" << player->getBank ()
      << std::endl;
  }
}

/*******************************************************************************
Function:     addAntesToPot

Description:  Takes away a dollar from each player and adds it to the pot 
              
Parameter:    None

Returned      void
*******************************************************************************/
void InBetweenGamePlay::addAntesToPot () {
  for (auto& player : mcInBetweenPlayers) {
    player->subtractFromBank (mcRiskLevel);
    mcPot.add (mcRiskLevel);
  }
}

/*******************************************************************************
Function:     dealCards

Description:  Deals each player a card, then deals each player another card. 
              
Parameter:    None

Returned      void
*******************************************************************************/
void InBetweenGamePlay::dealCards () {
  const int CARDS_DEALT = 2;
  for (size_t i = 0; i < CARDS_DEALT; i++) {
    for (auto& player : mcInBetweenPlayers) {
      player->addToInBetweenHand (mcDeck.dealCard ());
    }
  }
}

/*******************************************************************************
Function:     isInBetween 

Description:  Returns t/f if the third card is in between the first two 
              
Parameter:    rcCard1         - first card (part of player's hand)   
              rcCard2         - the second card (part of player's hand) 
              rcInBetweenCard - third card, checked if it is in between the 
                                other two 

Returned      t/f
*******************************************************************************/
bool InBetweenGamePlay::isInBetween (const Card& rcCard1,
  const Card& rcCard2, const Card& rcInBetweenCard) const {
  return rcCard1.getDenominationValue () < 
    rcInBetweenCard.getDenominationValue () && 
    rcInBetweenCard.getDenominationValue () < rcCard2.getDenominationValue ();
}

/*******************************************************************************
Function:     playRound 

Description:  Plays a round of acey duecy. Cards are dealt, each player pays an
              ante, each player bets and gets dealt a third card. 
              
Parameter:    None

Returned      void
*******************************************************************************/
void InBetweenGamePlay::playRound () {
  const int MISINPUT_PUNISHMENT = 1, SAME_CARD_WINNINGS = 2, 
    CONSECUTIVE_CARD_WINNINGS = 1; 
  int bet;
  std::cout << "*** ROUND #" << InBetweenGamePlay::roundCounter << " ***"
    << std::endl << std::endl;
  InBetweenGamePlay::roundCounter++;

  this->dealCards ();

  for (auto player : mcInBetweenPlayers) {
    player->subtractFromBank (mcRiskLevel);
    mcPot.add (mcRiskLevel);
  }

  for (auto player : mcInBetweenPlayers) {
    writeRoundHeading (player);

    // checks if the player was dealt the same card 
    if (player->getInBetweenHand().getDistance() == 0) {
      this->playerWin (player, SAME_CARD_WINNINGS);
      if (mcPot.getBalance() == 0) {
        // stops gameplay if the pot is empty 
        break; 
      }
      continue; 
    }

    // checks if the players cards are consecutive 
    if (player->getInBetweenHand().getDistance() == 1) {
      this->playerLose (player, CONSECUTIVE_CARD_WINNINGS); 
      continue; 
    }

    try {
      bet = player->getBet (mcPot.getBalance ());
    } catch (const std::runtime_error&) {
      std::cout << "Invalid bet amount. You lose your turn and 1 chip" 
        << std::endl;
      player->subtractFromBank(MISINPUT_PUNISHMENT);
      continue;
    }

    Card cCardDealt = this->mcDeck.dealCard ();
    std::cout << "InBetween Card: " << cCardDealt << std::endl << std::endl;

    // checks if the third card is in between the players hand 
    if (this->isInBetween (player->getInBetweenHand ().getCard (0),
      player->getInBetweenHand ().getCard (1), cCardDealt)) {
      this->playerWin (player, bet);
    }
    else {
      this->playerLose (player, bet);
    }
    if (mcPot.getBalance() == 0) {
      // stops gameplay if the pot is empty
      break;
    }
  }
  std::cout << std::endl << "Pot Size: $" << mcPot.getBalance () << std::endl 
    << std::endl;
}

/*******************************************************************************
Function:     playAgain

Description:  Asksk the user if they would like to play another round
              
Parameter:    None

Returned      t/f - true for play again, false for quit
*******************************************************************************/
bool InBetweenGamePlay::playAgain () const {
  const char QUIT = 'Q', PLAY = 'P';
  char choice;
  do {
    std::cout << "P)lay game" << std::endl << "Q)uit" << std::endl << std::endl;
    std::cout << "Enter your choice: ";
    std::cin >> choice;
  } while (choice != QUIT && choice != PLAY);

  std::cout << std::endl;

  if (choice == QUIT) {
    return false;
  }
  else {
    return true;
  }
}

/*******************************************************************************
Function:     writeRoundHeading

Description:  Takes the passed in player argument and outputs relevant info 
              before they are asked to make their bet
              
Parameter:    *pcPlayer - pointer to a player

Returned      void
*******************************************************************************/
void InBetweenGamePlay::writeRoundHeading (const InBetweenPlayer* pcPlayer) 
  const {
  std::cout << std::endl;
  std::cout << "Pot Size: $" << mcPot.getBalance () << std::endl << std::endl;
  std::cout << pcPlayer->getName () << "'s Turn" << std::endl;
  std::cout << pcPlayer->getName () << "'s Bank: "
    << pcPlayer->getBank ().getBalance () << std::endl;
  std::cout << "Cards: " << pcPlayer->getInBetweenHand () << std::endl;
}

/*******************************************************************************
Function:     playerWin

Description:  Adds the player's bet to their balance, subtracts their bet from 
              the pot 
              
Parameter:    *pcPlayer - pointer to a player 
              bet       - the player's bet

Returned      void
*******************************************************************************/
void InBetweenGamePlay::playerWin (InBetweenPlayer* pcPlayer, int bet) {
  pcPlayer->addToBank (bet);
  mcPot.subtract (bet);
  std::cout << pcPlayer->getName () << " wins!" << std::endl;
  std::cout << pcPlayer->getName () << "'s Bank: "
    << pcPlayer->getBank ().getBalance () << std::endl;
}

/*******************************************************************************
Function:     playerLose

Description:  Subtracts the player's bet to their balance, adds their bet to 
              the pot 
              
Parameter:    *pcPlayer - pointer to a player 
              bet       - the player's bet

Returned      void
*******************************************************************************/
void InBetweenGamePlay::playerLose (InBetweenPlayer* pcPlayer, int bet) {
  pcPlayer->subtractFromBank (bet);
  mcPot.add (bet);
  std::cout << pcPlayer->getName () << " loses." << std::endl;
  std::cout << pcPlayer->getName () << "'s Bank: "
    << pcPlayer->getBank ().getBalance () << std::endl;
}

/*******************************************************************************
Function:     betError

Description:  Handles user punishment if they misinput a bet 
              
Parameter:    *pcPlayer  - pointer to a player 
              amoutnLost - the amount the player loses

Returned      void
*******************************************************************************/
void InBetweenGamePlay::betError (int amountLost, InBetweenPlayer* pcPlayer) {
  std::cout << "Invalid bet amount. You lose your turn and " << amountLost;

  // grammar  
  if (amountLost > 1) {
    std::cout << "chips" << std::endl;
  } else {
    std::cout << "chip" << std::endl;
  }
  playerLose(pcPlayer, amountLost);
}