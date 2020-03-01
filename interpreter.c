//interpreter.c
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>		//to use isdigit(c)
#include <string.h>
#include "pcb.h"
#include "ram.h"
#include "kernel.h"
#include "shell.h"
#include "shellmemory.h"
//function declarations
static void run(char *words[], int wordCount);
void help(char *words[], int wordCount);
void quit(char *words[], int wordCount);
void set(char *words[], int wordCount);
void print(char *words[], int wordCount);
void exec(char *words[], int wordCount);

void interpreter(char *words[], int wordCount) {		//words[0] is cmd
	if (strcmp(words[0], "") == 0) printf("");		//in case need this??????????????????????

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
	else if (strcmp(words[0], "exec")==0){
		exec(words, wordCount);
	}
	else {
		printf("not a valid command\n");
	}
}

/////////////////////////////////////////////////////
void exec(char *words[], int wordCount){
	//check if more than 3 files
	if(wordCount>4) printf("Too many files! Calm down junior!\n");
	else if (wordCount == 1) printf("Tip: add some file(s) you want executed.\n");
	else{
		FILE* fp;
		//call myinit in kernel.c for each program
		for (int i=1; i<wordCount; i++){
			fp = fopen(words[i], "rt");
			printf("From exec(): Opening file %s\n",words[i]);
			if(fp==NULL) printf("Error: File %s cannot be loaded! (inside exec())\n", words[i]);
			else {myinit(words[i]);//kernel.c
			printf("Entering myinit() in exec()@@@@@@@@@@@@@@@@@@@@@@@@@\n");
			}
			fclose(fp);
		}
		printList(); //print the ready queue (function from kernel.c)
		//call scheduler() in kernel.c to run the loaded programs
		printf("Entering scheduler!@@@@@@@@@@@@@@@@@@@@@@@@@\n");
		scheduler();
		printf("Finished with scheduler@@@@@@@@@@@@@@@@@@@@");			
	}	

}
/////////////////////////////////////////////////////
static void run(char *words[], int wordCount){		//set to static bcz dont want to overshadow void run(quanta) in cpu.c
	FILE *ptr;
	char curLine[200];

        ptr = fopen(words[1],"rt");
        if (ptr == NULL) printf("File not found (inside run())\n"); 
	else{
		while(fgets(curLine,sizeof(curLine), ptr)){
        		parse(curLine);
      		 }
        fclose(ptr);
	}
}
///////////////////////////////////////////////////
void help(char *words[], int wordCount){
	if (wordCount > 1) printf("not right amount of arguments for this command (help). Enter 'help' for options\n");
	else{
	 printf("help\t Displays all commands\n"
          "quit\t Exits/terminates the shell\n"
          "set\t Assigns a value to shell memory (set VAR STRING)\n"
          "print\t Prints STRING assigned to VAR\t (print VAR)\n"
          "run\t Execute file SCRIPT.TXT\t (run SCRIPT.TXT)\n"
	  "exec\tExecutes concurrent programs\t exec p1 p2 p3\n");
}	
}
////////////////////////////////////////////////////
void quit(char *words[], int wordCount){
  	if(wordCount > 1) printf("not right amount of arguments for this command (quit). Enter 'help' for options\n");
	else{
  		printf("Bye!\n");
  		exit(0);
	}			
}
//////////////////////////////////////////////////
void set(char *words[], int wordCount){
	if(wordCount!=3) printf("Not right amount of arguments for this command (set). Enter 'help' for options (from set() (interpreter.c)\n");
	//check if first char of words[1] is a number
	//printf("inside set()     words[1]: %s, words[2]: %s\n",words[1], words[2]);
	else memSet(words[1], words[2]);	//set x to 10 in mem

}


////////////////////////////////////////////////
void print(char *words[], int wordCount){
	if(wordCount>2) printf("not right amount of arguments for this command (print). Enter 'help' for options\n");
	else{
		if(varIndex(words[1])==-1) printf("variable does not exist\n");
		else printf("%s\n",memGet(words));
	}
}
