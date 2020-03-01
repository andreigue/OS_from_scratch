#include <stdio.h>
#include <string.h>
#include "kernel.h"
#include <stdlib.h>
#include "pcb.h"
int getEmptyRAMcell();

char* ram[10];
void addToRAM(FILE *p, int *start, int *end){
	//while(ram[*start]!=NULL) {*start=*start+1;}
	printf("Passing to addToRAM *start = %d, *end = %d\n",*start, *end);
	int ii;
	printf("From addToRAM(): Contents of ram before the call:\n");
	for(ii=0;ii<10;ii++)printf("%d - %s\n",ii,ram[ii]);
	
	char buffer[1000];
	int numberOfLines=0;
	//find next available cell in ram[]
	int availIndex = getEmptyRAMcell();
	printf("From ram.c: availIndex=%d\n", availIndex);
	if (availIndex==-1) printf("From ram.c: RAM full!!!!!!!!!!\n");
	else{
		while(fgets(buffer, sizeof(buffer), p)!=NULL){
			ram[availIndex]= strdup(buffer);		//copy pasting into ram
			numberOfLines++;	//keep track of number of lines per program
			printf("From addToRam(): Storing %s inside ram[%d]\n", buffer, availIndex);
			availIndex++;
			*start=availIndex;			
			*end = *start+numberOfLines;
		}
		//update PCB
		
	}
	int y;
	printf("From addToRAM(): Contents of ram after the call:\n");
        for(y=0;y<10;y++)printf("%d - %s\n",y,ram[y]);
}

int getEmptyRAMcell(){
	int i;
	for(i=0;i<1000;i++){
		if(ram[i]==NULL){
		// printf("First empty RAM cell is %d!!!!!!!!!!!!!\n", i); 
		return i;
		}
	}
	if(i=999) return -1;	//will be error (RAM full)
}
/*
int getRAMindex(FILE* p){
	int i;
		for(i=0; i<1000;i++){
			if(ram[i]=p) return i
		}
}
*/
void emptyRAM(FILE* p){
	int i;
	for(i=0;i<1000;i++) ram[i]=NULL;
}

char* getCellFromRAM(int i){
	return ram[i];
	
}

void removeFromRAM(struct PCB *pcb){
	int i;
	for (i=pcb->start;i<pcb->end;i++){
		ram[i]=NULL;
	}
}

