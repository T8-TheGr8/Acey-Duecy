//******************************************************************************
// File name:   Bank.cpp
// Author:      Tate Woodward, Pacific University
// Date:        4/19/25
// Class:       CS-250
// Assignment:  Card Game
// Purpose:     Bank implementation
// Hours:       0.10
//******************************************************************************

#include "../include/Bank.h"

/*******************************************************************************
Function:     Default Constructor

Description:  Creates a bank with a balance of 0
              
Parameter:    None

Returned      n/a
*******************************************************************************/
Bank::Bank () {
  mBalance = 0;
}

/*******************************************************************************
Function:     Parametrized Constructor

Description:  Creates a bank with the passed in value 
              
Parameter:    amount - the amount the bank will store

Returned      n/a
*******************************************************************************/
Bank::Bank (int amount) {
  if (amount < 0) {
    throw std::invalid_argument
    ("Bank Exception::Bank: amount must be positive");
  }
  mBalance = amount;
}

/*******************************************************************************
Function:     Copy Constructor

Description:  Creates a bank that's a copy of the parameter
              
Parameter:    rcBank - the bank being copied

Returned      n/a
*******************************************************************************/
Bank::Bank (const Bank& rcBank) {
  mBalance = rcBank.getBalance ();
}

/*******************************************************************************
Function:     Destructor

Description:  Destructs
              
Parameter:    n/a

Returned      n/a
*******************************************************************************/
Bank::~Bank () {

}

/*******************************************************************************
Function:     getBalance

Description:  returns the balance of the bank 
              
Parameter:    None

Returned      the balance
*******************************************************************************/
int Bank::getBalance () const {
  return mBalance;
}

/*******************************************************************************
Function:     add

Description:  Adds the passed in parameter to the bank's balance
              
Parameter:    amount - the amount being added

Returned      void 
*******************************************************************************/
void Bank::add (int amount) {
  if (amount < 0) {
    throw std::invalid_argument
    ("Bank Exception::add: amount must be positive");
  }
  mBalance += amount;
}

/*******************************************************************************
Function:     subtract

Description:  Subtracts the passed in parameter from the bank's balance
              
Parameter:    amount - the amount being subtracted

Returned      void
*******************************************************************************/
void Bank::subtract (int amount) {
  if (amount < 0) {
    throw std::invalid_argument
    ("Bank Exception::subtract: amount must be positive");
  }
  if (amount > mBalance) {
    throw std::invalid_argument
    ("Bank Exception::subtract: insufficient funds");
  }
  mBalance -= amount;
}

/*******************************************************************************
Function:     clear

Description:  Sets the bank's balance to zero 
              
Parameter:    None

Returned      n/a
*******************************************************************************/
void Bank::clear () {
  mBalance = 0;
}

/*******************************************************************************
Function:     operator<<

Description:  Overloads the insertion operator to output a bank. Just outputs 
              the bank's balance.
              
Parameter:    rcOutStream - the output stream 
              rcBank      - the bank being output. 

Returned      ostream&    - output stream 
*******************************************************************************/
std::ostream& operator<< (std::ostream& rcOutStream, const Bank& rcBank) {
  rcOutStream << rcBank.getBalance ();

  return rcOutStream;
}

/*******************************************************************************
Function:     setBalance

Description:  Sets the balance of the bank
              
Parameter:    iAmount - the amount being set

Returned      void
*******************************************************************************/
void Bank::setBalance (int iAmount) {
  mBalance = iAmount;
}