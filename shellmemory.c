#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct shellmem{
	char *var;
	char *val;
	struct shellmem *next;
}shellmem;


struct shellmem memArray[200];

// void initShellMemory(){}		don't need cuz already every elements points to NULL
	
//int firstNULLindex(){		//no time rn, but add  this and have memSet count 
//	for 
//}	
	
int memSet(char *var, char *val){
int indexOfNULL=0;		//index of first null in the array
for(int i=0; i<200; i++){
	if(memArray[i].var!=NULL){ 
	
	if(strcmp(memArray[i].var,var)){	//replace existing value
		memArray[i].val=val;		//set old val to new val
		return 0;
	}
}//if statement	
}//for loop
	memArray[indexOfNULL].var=var;		//else at first NULL, set var and val
	memArray[indexOfNULL].val=val;
	return 0;
}//memSet function
/*
int getVal(char *var){	//find variable being called, and return it, along with its index. if can't find, return NULL

	for (int i=0; i<200; i++){
		if(memArray[i].var==var) return 0;	//variable found
	}
	
return 0;
}
*/
char* memGet(char*words[]){
	char *zzzzzzneverwillthisbewritten;
		for (int i=0; i<200; i++){
		if(memArray[i].var!=NULL){	
			if(strcmp(words[1],memArray[i].var))return memArray[i].val;
		}//if statement
	}//for loop
	return zzzzzzneverwillthisbewritten;
} 

