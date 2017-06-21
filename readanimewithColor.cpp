#include<string>
#include<iostream>
#include<fstream>
#include<unistd.h>
#include<term.h>
#include<curses.h>

//clean the screen
void ClearScreen()
{
    if(!cur_term)
    {
        int result;
        setupterm(NULL, STDOUT_FILENO, &result);
        if (result <=0) return;
    }
    putp( tigetstr((char*) "clear"));
}

void printwithcolor( char ch, unsigned char color ){
    std::cout<<"\x1b[38;5;"<<(int)color<<"m"<<ch;
}


int main (int narg, char ** args){
    if(narg<2)
        return 1;
    std::string filename = args[1];
    std::string colorfilename = args[2];
    bool if_auto = false;
    if (narg>3)
        if_auto = std::string(args[3])=="auto" ? true: false;
    std::ifstream file(filename);
    std::ifstream colorfile(colorfilename);
    colorfile.seekg(0);

    std::string line;
    ClearScreen();
    while(!file.eof()){
        std::getline (file, line);
        if(line == "----"){
            if(if_auto)
                usleep(50*1000);
            else
                std::cin.ignore(); //wait key
            ClearScreen();
        }
        else{
            static std::string linecolor(line.size(),'0');
            colorfile.read(&linecolor[0], line.size());
            for(unsigned int i =0; i< line.size(); i++){
                printwithcolor(line[i],linecolor[i]);
            }
            //clear the color
            std::cout<<"\e[0m"<<std::endl;
        }
    }
    return 0;
}
