#include<sys/utsname.h> 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BOLD(text) "\033[1m" text "\033[0m"

int main(int argc, char *argv[])
{
    struct utsname uname_pointer;

    uname(&uname_pointer);

    puts(
    "\n"
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
    "          ....          ....\n"                              
    );

    printf("\n\n"); 

    char *username; username = getenv("USER"); 
    char *nodename; nodename = uname_pointer.nodename; 

    for (unsigned long int i = 0; i < strlen(username) + strlen(nodename) + 1; i ++){
        putchar('='); 
    }
    
    printf("\n%s@%s\n", username, nodename);
    
    for (unsigned long int i = 0; i < strlen(username) + strlen(nodename) + 1; i ++){
        putchar('='); 
    }

    return 0;

}
