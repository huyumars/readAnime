solution "hello"
location ("../build")

configurations {'Debug','Release'}

project "readAnime"
kind "ConsoleApp"
language "C++"
buildoptions { "-std=c++11", "-Wall" }
files {"cpp/*.H",{"cpp/*.cpp"}}
links ("ncurses")

configuration "Debug"
defines { "DEBUG" }
flags { "Symbols" }
targetdir "../install"

configuration "Release"
defines { "NDEBUG" }
flags { "Optimize" }
targetdir "../install"
