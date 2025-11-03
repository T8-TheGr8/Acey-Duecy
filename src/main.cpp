//******************************************************************************
// File name:   main.cpp
// Author:      Tate Woodward, Pacific University
// Date:        4/8/25
// Class:       CS-250
// Assignment:  Card Game
// Purpose:     Simple driver to execute SampleClass class
// Hours:       0.5
//******************************************************************************

#include <iostream>
#include "../include/SampleClass.h"
#include "../include/Deck.h"
#include "../include/InBetweenHand.h"
#include "../include/InBetweenGamePlay.h"
#include "../include/AIConservativeInBetweenPlayer.h"
#include "../include/HumanInBetweenPlayer.h"

void addPlayers (InBetweenGamePlay&);
InBetweenPlayer* setupHuman (InBetweenPlayer*);
InBetweenPlayer* setupAI (InBetweenPlayer*);

int main () {
  int seed = 3; 
  srand (seed);
  InBetweenGamePlay cGame (InBetweenGamePlay::LOW);

  std::cout << "Welcome to InBetween!" << std::endl << std::endl;
  std::cout << "*** Adding players ***" << std::endl << std::endl;

  addPlayers(cGame);

  while (cGame.playAgain()) {
    cGame.playRound();
  }

  std::cout << "*** Final Bank Values ***" << std::endl << std::endl;
  cGame.printBanks(); 

  return EXIT_SUCCESS;
}

/*******************************************************************************
Function:     addPlayers

Description:  Loops through asking the user to add players to the game
              
Parameter:    cGame - the game players are being added to 

Returned      void
*******************************************************************************/
void addPlayers (InBetweenGamePlay& cGame) {
  const char AI = 'A', HUMAN = 'H', DONE = 'D';
  char userChoice;
  InBetweenPlayer* pcPlayer = nullptr;

  do {
    std::cout << "A)I player add" << std::endl
      << "H)uman player add" << std::endl
      << "D)one adding players" << std::endl << std::endl;
    std::cout << "Enter your choice: ";
    std::cin >> userChoice;
    std::cout << std::endl;
    if (userChoice == AI) {
      cGame.addPlayer (setupAI (pcPlayer));
    }
    else if (userChoice == HUMAN) {
      cGame.addPlayer (setupHuman (pcPlayer));
    }
  } while (userChoice != DONE);
}

/*******************************************************************************
Function:     setupHuman

Description:  Initializes a new human player to user input
              
Parameter:    pcPlayer - pointer to a player

Returned      InBetweenPlayer* - pointer to player 
*******************************************************************************/
InBetweenPlayer* setupHuman (InBetweenPlayer* pcPlayer) {
  std::string name;
  int amount;
  Bank cBank;
  std::cout << "*** Adding Human Player ***" << std::endl << std::endl;
  std::cout << "Enter name: ";
  std::cin >> name;
  std::cout << "Enter starting bank: $";
  std::cin >> amount;
  std::cout << std::endl;
  cBank.add (amount);
  return pcPlayer = new HumanInBetweenPlayer (name, cBank, InBetweenHand ());
}

/*******************************************************************************
Function:     setupAI

Description:  Initializes and outputs a new AI player 
              
Parameter:    pcPlayer - pointer to a player

Returned      InBetweenPlayer* - pointer to player 
*******************************************************************************/
InBetweenPlayer* setupAI (InBetweenPlayer* pcPlayer) {
  pcPlayer = new AIConservativeInBetweenPlayer ();
  pcPlayer->addToBank (10);

  std::cout << "*** Adding Conservative AI Player ***" 
    << std::endl << std::endl;
  std::cout << "Enter name: " << pcPlayer->getName() << std::endl; 
  std::cout << "Enter starting bank: $" << pcPlayer->getBank().getBalance()
    << std::endl << std::endl;

  return pcPlayer;
}