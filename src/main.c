#include<sys/utsname.h> 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BOLD(text) "\033[1m" text "\033[0m"

char* apple = "\n"
                  "                      :-==\n"                                
                  "                   .-++++-\n"                                
                  "                  :+++++=\n"                                 
                  "                 .++++=-\n"                                  
                  "                 -+=-:\n"                                    
                  "     .:==++++==-::..:-==+++++=-:\n"                          
                  "   .=+++++++++++++++++++++++++++=-\n"                        
                  "  :=============================-.\n"                        
                  " :=============================.\n"                          
                  " =============================.\n"                           
                  ".++++++++++++++++++++++++++++=\n"                            
                  ".+++++++++++++++++++++++++++++\n"                            
                  " *****************************-\n"                           
                  " +*****************************=\n"                          
                  " .*******************************=.\n"                       
                  "  :*******************************+.\n"                      
                  "   -*****************************+.\n"                       
                  "    :+++++++++++++++++++++++++++=\n"                        
                  "      -------------------------:\n"                          
                  "       .--------:::::--------:\n"                            
                  "          ....          ....";


char* penguin = "   _\n"
                  " ('v')\n"
                  "//-=-\\\\\n"
                  "(\\_=_/)\n"
                  " ^^ ^^";

void showColours() {
    printf("\033[0;30m███\033[0m\033[0;31m███\033[0m\033[0;32m███\033[0m\033[0;33m███\033[0m\033[0;34m███\033[0m\033[0;35m███\033[0m\033[0;36m███\033[0m\033[0;37m███\033[0m\n");
    printf("\033[1;30m███\033[0m\033[1;31m███\033[0m\033[1;32m███\033[0m\033[1;33m███\033[0m\033[1;34m███\033[0m\033[1;35m███\033[0m\033[1;36m███\033[0m\033[1;37m███\033[0m\n");
}

int main(int argc, char *argv[])
{
    struct utsname uname_pointer;

    uname(&uname_pointer);

    puts(penguin);


    char *username; username = getenv("USER"); 
    char *nodename; nodename = uname_pointer.nodename; 

    for (unsigned long int i = 0; i < strlen(username) + strlen(nodename) + 1; i ++){
        putchar('='); 
    }
    
    printf("\n%s@%s\n", username, nodename);

    showColours();
    
    for (unsigned long int i = 0; i < strlen(username) + strlen(nodename) + 1; i ++){
        putchar('='); 
    }

    return 0;

}
