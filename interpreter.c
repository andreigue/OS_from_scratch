#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "shell.h"

//function declarations
int run(char *words[], int wordCount);
int help(char *words[], int wordCount);
int quit(char *words[], int wordCount);
int set(char *words[], int wordCount);
int print(char *words[], int wordCount);

int interpreter(char *words[], int wordCount) {		//words[0] is cmd
	int errCode = 0;

	//user wants to execute a script
	if (strcmp(words[0], "run")){	
		errCode = run(words, wordCount);		
	}
	else if (strcmp(words[0], "help")) {
		errCode = help(words,wordCount);
	}
	else if (strcmp(words[0], "quit")) {
		errCode = quit(words,wordCount);
	}
	else if (strcmp(words[0], "set")) {
		errCode = set(words,wordCount);
	}
        else if (strcmp(words[0], "print")) {
                errCode = print(words,wordCount);
        }

	else {
		errCode = 1;
	}

	return errCode;
}




/////////////////////////////////////////////////////
int run(char *words[], int wordCount){

int errCode = 0;	//assuming it is correct for now
char line[1000];
FILE *p = fopen(words[0] + 2, "rt");	//+2 to skip .\ (execution)

fgets(line, 999, p);
while(!feof(p)){
	errCode = parse(line);

	}
return 0;
}
///////////////////////////////////////////////////
int help(char *words[], int wordCount){
	if (wordCount > 1) return 2;		//2="not right amount of arguments for this command. Enter "help" to see possibilities"
	 printf("help\t Displays all commands\n"
          "quit\t Exits/terminates the shell\n"
          "set\t Assigns a value to shell memory (set VAR STRING)\n"
          "print\t Prints STRING assigned to VAR\t (print VAR)\n"
          "run\t Execute file SCRIPT.TXT\t (run SCRIPT.TXT)\n");

  return 0;

}
////////////////////////////////////////////////////
int quit(char *words[], int wordCount){
  if(wordCount > 1) return 2;		//2="not right amount of arguments for this command. Enter "help" to see possibilities"
  printf("Bye!\n");
  exit(0);			
}
//////////////////////////////////////////////////
int set(char *words[], int wordCount){
return 0;
}


////////////////////////////////////////////////
int print(char *words[], int wordCount){
return 0;
}


