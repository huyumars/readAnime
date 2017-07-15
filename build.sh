#if cannot find term.h please install libcurses5-dev
if [ ! -d ../install ] ; then
   mkdir ../install
fi
g++ -std=c++14 -g -o ../install/readanimeWithColor readanimewithColor.cpp -lncurses 
