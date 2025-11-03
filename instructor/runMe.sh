# runMe.sh is an executable script to run the instructor's unit tests and the
# student's unit tests. This file needs to be executable.

# An instructor directory is used to test the student's code based on the 
# instructor's unit tests. If the directory exists, then skip adding it
# to the CMakeLists.txt file; otherwise, add it to the file.

if ! grep -Fxq "add_subdirectory(instructor)" CMakeLists.txt; then
    printf "\nadd_subdirectory(instructor)" >> CMakeLists.txt
fi

# Get a consistent version of the Google Test framework

wget https://github.com/google/googletest/archive/refs/tags/v1.15.2.tar.gz;
tar zxf v1.15.2.tar.gz;
mv googletest-1.15.2/ googletest;
rm v1.15.2.tar.gz;

# Build the instructor's unit tests and the student's unit tests

rm -Rf build;
export CXX=`which clang++-16`;
export CXX="${CXX} -fstandalone-debug -g";
cmake -S . -B ./build;
cmake --build build --target clean;
cmake --build build;
   
# Run the instructor's unit tests

printf "Running the instructor's unit tests ......\n\n";
build/instructor/InstructorTests 
printf "Instructor's unit tests completed.\n\n";

# Run the student's unit tests

printf "Running the student's unit tests ......\n\n";
build/test/TestsToRun
printf "Student's unit tests completed.\n\n";