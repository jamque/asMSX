# asMSX testing guide

We use [Google Test (gtest)](https://github.com/google/googletest/blob/master/googletest/docs/primer.md)
framework for our test coverage.

Currently only one basic test for build_tape_file_name() function is implemented.
More should follow as the code is refactored into a testable state.


## Set up gtest in Windows and Visual Studio 2019

Just like the normal, we'll need flex and bison from
[winflexbison](https://sourceforge.net/projects/winflexbison/) in path.

Open solution (build\vs2019\asmsx.sln). Right click on asmsx-gtest project.
Choose `Manage NuGet Packages...`. If you don't already have it, install
`Microsoft.googletest.v140.windesktop.msvcstl.static.rt-dyn` package.

Now you should be able to rebuild solution and see test run results in `Test Explorer` panel.


## Set up gtest in Ubuntu Linux

Update/upgrade:

    sudo apt update
    sudo apt upgrade

Install prerequisite tools and libraries:

    sudo apt-get install build-essential cmake flex bison libpthread-stubs0-dev

Install gtest source package:

    sudo apt-get install libgtest-dev

Build and install gtest:

    cd /usr/src/gtest
    sudo cmake CMakeLists.txt
    sudo make
    sudo make install

Clone asMSX repository, build and run test cases:

    git clone https://github.com/Fubukimaru/asMSX
    cd asMSX/src
    make test

You should see something like this:

```
gcc -c asmsx.c -lm -O2 -Os -s -Wall -Wextra
g++ -o test asmsx.o test.cpp -L/usr/local/lib -lgtest -lpthread -lm -O2 -Os -s -Wall -Wextra
./test
[==========] Running 1 test from 1 test case.
[----------] Global test environment set-up.
[----------] 1 test from Tape
[ RUN      ] Tape.build_tape_file_name
[       OK ] Tape.build_tape_file_name (0 ms)
[----------] 1 test from Tape (1 ms total)

[----------] Global test environment tear-down
[==========] 1 test from 1 test case ran. (4 ms total)
[  PASSED  ] 1 test.
```
