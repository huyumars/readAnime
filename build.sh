#if cannot find term.h please install libcurses5-dev
g++ -std=c++14 -g -o readanimeWithColor readanimewithColor.cpp -lncurses -ltinfo
