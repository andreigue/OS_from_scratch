#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "interpreter.h"
#include "shellmemory.h"

void parse(char ui[]);

void shellUI(int argc, char* argv[]){
	int result = 0;         //no result initially
        char userInput[1000];

        printf("Welcome to the Andrei Guevorkian shell!\n");
        printf("Version 2.0 Created February 2020\n");


        while(1){
                printf("$ ");
                fgets(userInput, 999, stdin);
                parse(userInput);
        }

}

void parse(char ui[]){

  char temp[200];
  int a,b; // input index
  char *words[100];
  int w = 0; // wordsIndex

  for(a = 0; ui[a] == ' ' && a < 200; a++); // skip leading white spaces

  while(ui[a] != '\0' && a < 200){ // until end of input

    for(b = 0; ui[a] != '\0' && ui[a] != '\n' && ui[a] != ' ' && ui[a] != '\r' && a < 200; a++, b++){
      temp[b] = ui[a]; //copying char by char into tmp until reach space/EOL
    }

    temp[b] = '\0'; //append "end of string" character (null) when finished copying

    words[w] = strdup(temp); // store input word by word, without spaces

    a++;
    if (strcmp(words[w],"") != 0)
      w++;

  }

  interpreter(words, w);//passing word count as well so it is taken care of in interpreter()

}


