#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>		//to use isdigit(c)
#include <string.h>

#include "shell.h"
#include "shellmemory.h"
//function declarations
void run(char *words[], int wordCount);
void help(char *words[], int wordCount);
void quit(char *words[], int wordCount);
void set(char *words[], int wordCount);
void print(char *words[], int wordCount);

void interpreter(char *words[], int wordCount) {		//words[0] is cmd
	if (strcmp(words[0], "") == 0) printf("type something");		//in case need this??????????????????????

	//user wants to execute a script
	else if (strcmp(words[0], "run")==0){	
		run(words, wordCount);		
	}
	else if (strcmp(words[0], "help")==0) {
		help(words,wordCount);
	}
	else if (strcmp(words[0], "quit")==0) {
		quit(words,wordCount);
	}
	else if (strcmp(words[0], "set")==0) {
		set(words,wordCount);
	}
        else if (strcmp(words[0], "print")==0) {
                print(words,wordCount);
        }

	else {
		printf("not a valid command\n");
	}
}




/////////////////////////////////////////////////////
void run(char *words[], int wordCount){
	FILE *ptr;
	char curLine[200];

        ptr = fopen(words[1],"rt");
        if (ptr == NULL) printf("file not found\n"); 
	else{
		while(fgets(curLine,sizeof(curLine), ptr)){
        		parse(curLine);
      		 }
        fclose(ptr);
	}
}
///////////////////////////////////////////////////
void help(char *words[], int wordCount){
	if (wordCount > 1) printf("not right amount of arguments for this command. Enter 'help' for options\n");
	else{
	 printf("help\t Displays all commands\n"
          "quit\t Exits/terminates the shell\n"
          "set\t Assigns a value to shell memory (set VAR STRING)\n"
          "print\t Prints STRING assigned to VAR\t (print VAR)\n"
          "run\t Execute file SCRIPT.TXT\t (run SCRIPT.TXT)\n");
}	
}
////////////////////////////////////////////////////
void quit(char *words[], int wordCount){
  	if(wordCount > 1) printf("not right amount of arguments for this command. Enter 'help' for options\n");
	else{
  		printf("Bye!\n");
  		exit(0);
	}			
}
//////////////////////////////////////////////////
void set(char *words[], int wordCount){
if(wordCount!=3) printf("Not right amount of arguments for this command. Enter 'help' for options\n");
//check if first char of words[1] is a number
//if (isdigit(words[1][1])) printf("invalid variable name. variable must begin with a letter\n");
//printf("inside set()     words[1]: %s, words[2]: %s\n",words[1], words[2]);
else memSet(words[1], words[2]);	//set x to 10 in mem

}


////////////////////////////////////////////////
void print(char *words[], int wordCount){
	if(wordCount>2) printf("not right amount of arguments for this command. Enter 'help' for options\n");
	else{
		if(varIndex(words[1])==-1) printf("variable does not exist\n");
		else printf("%s\n",memGet(words));
	}
}
