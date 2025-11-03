# Acey-Ducey (In-Between) Card Game – C++

A command-line implementation of **Acey-Ducey (also called In-Between)** written in modern C++ (C++23).  
This project was created to practice object-oriented design, class hierarchies, polymorphism, and game logic.

## 🚀 Features

- Full gameplay loop: place bets, draw cards, win/lose based on in-between logic  
- Card, Deck, Hand classes using proper encapsulation and abstraction  
- Shuffling, copying decks, and re-dealing functionality  
- Input validation and error handling using `try/catch` and exceptions  
- Modular code structure across multiple `.cpp` and `.h` files
- Unit tests and memory leak protection via valgrind 

## Build and run the game 

Terminal Commands: 
1. make
2. bin/main.exe

## How to Play 

1. You begin with a starting balance.
2. Two cards are dealt face up.
3. You place a bet whether the next card will fall between the first two.
4. If correct, you win the bet.
5. If incorrect or identical, you lose the bet.

Game continues until you quit or run out of money.



--- 
# Class project README  
## CS250 C++ Template

## Commands

1. Execute without debugging

    * Open a Terminal session
    * Make sure you are in the directory where the Makefile is located
    * Type the command <b>make</b>. If all goes well, you will see something similar to 

      ```
        @ryan2135 ➜ /workspaces/CPPTemplateS25 (main) $ make
        mkdir -p bin
        clang++-16 -g -Wall -fstandalone-debug -std=c++2b  -o bin/main.exe src/*.cpp -Iinclude
        @ryan2135 ➜ /workspaces/CPPTemplateS25 (main) $ 
      ```
    * Type bin/main.exe

2. Create and run GoogleTest

    * You will be asked to select a Kit. Select the Kit that says **unspecified**. Further, this only needs to be done once. Once you select the Kit, you will see an attempt to build the unit tests which will fail because the GoogleTest test suite is not installed yet. Proceed to the next bullet point.

    * From the **TERMINAL**, type in the following command (or copy and paste all 4 statements at once)
      ```
        wget https://github.com/google/googletest/archive/refs/tags/v1.15.2.tar.gz;
        tar zxf v1.15.2.tar.gz;
        mv googletest-1.15.2/ googletest;
        rm v1.15.2.tar.gz;
      ```

    * In the lower left of the Explorer window you will see Codespaces: and the name of your running codespace which is two words. At the far right you will see a triangle pointing right. Click that icon which will run the unit tests in SampleClassTests.cpp which will unit test the factorial program in class SampleClass.

    * A GoogleTest should run that tests a function called factorial that is a member of a class called SampleClass. You should see the function factorial tested and passed in green text.