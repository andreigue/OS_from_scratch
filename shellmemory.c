#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct shellmem{
	char *var;
	char *val;
}shellmem;


struct shellmem memArray[200];

int varIndex(char* var){
	int i;	
	for (i=0; i<200; i++){	
		
		printf("INSIDE VARINDEX(): variable = %s value: %s index: %d \n", memArray[i].var, memArray[i].val,i);
		if(memArray[i].var!=NULL){
			printf("inside if stsatemenbt \n");
			if(strcmp(memArray[i].var,var)==0) return i;
		}
	}
	return -1;
}

void memSet(char *var, char *val){
	int indexOfNULL=0;		//index of first null in the array
	int index =varIndex(var);
	int i=0;
	if(index==-1) {
		while(memArray[i].var!=NULL){
			i++;
			
		}
		memArray[i].var=var;
		memArray[i].val=val;
//		indexOfNULL++;
		printf("inside index==-1       %s , %s \n",memArray[index].var, memArray[index].val);
	}else{
		memArray[index].val=val;
		printf("Inside memSet       %s , %s\n. index of : %d\n",memArray[index].var, memArray[index].val,index);
	}
}//memSet function


char* memGet(char*words[]){
	char *zzzzzzneverwillthisbewritten;
		for (int i=0; i<200; i++){
		if(memArray[i].var!=NULL){	
			if(strcmp(words[1],memArray[i].var)==0)return memArray[i].val;
		}//if statement
	}//for loop
	return zzzzzzneverwillthisbewritten;
} 
 
