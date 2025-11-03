# CMakeLists.txt for test directory

cmake_minimum_required(VERSION 3.5)

set(This InstructorTests) # this name must be unique

# Add unit test .cpp files which are in directory test
set(Sources
   CardTests.cpp           # Unit Test
   ../src/Card.cpp         # Source files
   HandTests.cpp 
    ../src/Hand.cpp        
    DeckTests.cpp 
    ../src/Deck.cpp
    InBetweenHandTests.cpp
    ../src/InBetweenHand.cpp
)

add_executable(${This} ${Sources})

# Name SampleClass name comes from the name set(This SampleClass) 
# in the root CMakeLists.txt. Nothing else to add here even if you add
# additional classes for testing.
target_link_libraries(${This} PUBLIC
    gtest_main
)

add_test(
    NAME ${This}
    COMMAND ${This} 
)