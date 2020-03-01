//pcb.c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "pcb.h"

//typedef struct PCB{int start; int end; int PC; struct PCB *next;}PCB;

//struct pcb *head=NULL;
//struct pcb *current =NULL;

PCB* makePCB(int start, int end){
	PCB* newPCB= (PCB*)malloc(sizeof(PCB));
	newPCB->PC= start;
	newPCB->start = start;
	newPCB->end = end;
	newPCB->next=NULL;
	return newPCB;
}


/*
//display the list
void printList(){
	struct PCB *ptr = head;
	printf("\n[ ");

	while(ptr!=NULL){
		printf("(%d, %d) ", ptr->key, ptr->data);
		ptr=ptr->next;
	}
	printf(" ]");
}
*/

