#include <stdio.h>
#include <string.h>
#include "interpreter.h"

//function declaration
int parse(char ui[]);
void interpretResult(int errCode);

int main(int argc, char* argv[]) {
	int result = 0;		//no result initially
	char userInput[1000];	
	
	printf("Welcome to the Andrei Guevorkian shell!\n");
        printf("Version 1.0 Created January 2020\n");
	

	while(1){
		printf("$ ");
		fgets(userInput, 999, stdin);
		result = parse(userInput);
		interpretResult(result);	//gives error message if needed
	}
	
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//parser's job is to clean up the user's input
int parse(char ui[]) {
	char tmp[200];
	char* words[100];
	int a, b;
	int w = 0; //word index

	for (a = 0; ui[a] = ' ' && a < 1000; a++) {		//skip white spaces
		while (ui[a] != '\0' && a < 1000) {
			for (b = 0; ui[a] != '\0' && ui[a] != ' ' && a < 1000; a++, b++) {
				tmp[b] = ui[a];		//copying char by char into tmp until reach space/EOL
			}
			tmp[b] = '\0'; //append "end of string" character (null) when finished copying
			words[w] = strdup(tmp);
			a++;
			if (strcmp(words[w],"") != 0)
			w++;	//if w>2, too many commands
		}
		return(interpreter(words,w));	//passing word count as well so it is taken care of in interpreter()
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void interpretResult(int errCode){
	if(errCode = '0') printf("good command");
	if(errCode = '1') printf("not right amount of arguments for this command. Enter 'help' to see possibilities");		
}


