# readAnime
read ascii-style anime 

USAGE:

  readanimeWithcolor   animeFile   colorFile  [auto]

animeFile:
a file contains frames of ascii text which repesent the a frame of image. Every two frame have a '----' as a gap, and each line has a '\n' at the end

colorFile:
a binary file contains the color information. 1 byte holds a 0-255 value which repesents the color of one charactor in animeFile. animeFile has no delimiter.

auto [option]
if add auto the program will automatically switch to the next frame at a specific frequence 
