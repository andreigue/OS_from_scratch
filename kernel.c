//kernel.c
#include <stdio.h>
#include <string.h>
#include <stdlib.h> //for malloc
#include <stdbool.h> 
#include "shell.h"
#include "cpu.h"
#include "ram.h"
#include "pcb.h"

PCB* head = NULL;
PCB* tail=NULL;
void myinit(char* filename);
void scheduler();
void addToReady(PCB* pcb);
	int i=0;
        int y=0;

void main(int argc, char* argv[]) {
	
	printf("Kernel 1.0 loaded!\n");
	shellUI(argc, argv); //inside shell.c
	void myinit(char* filename);	//instantiate the kernel data structure
}

void myinit(char* filename){
	int* start;
	int* end;
	//start=(int*)malloc(sizeof(int));
	//end=(int*)malloc(sizeof(int));
	start=&i;//random initialization
	end=&y;
	PCB* pcb;
	FILE* fp;
	fp = fopen(filename, "r");
	addToRAM(fp, start, end);
	pcb = makePCB(*start, *end);
	addToReady(pcb);
//	printList();	//from pcb.c
}

//called after all the programs have been loaded
void scheduler(){
	//myCPU = (struct CPU*)malloc(sizeof(struct CPU));
	//myCPU -> quanta =2; //not sure how to make this into a constant

	if(!cpuBusy){	//quanta finished or nothing is assigned to the cpu
	//	IP = PC;		
	//	runCPU(myCPU->quanta);
	}
//copy PC from PCB into the IP of the CPU

}
int ii=1;
//add PCB to tail of ready queue
void addToReady(PCB* newPcb){
	if(newPcb==NULL) printf("Unable to add newPCB to the readyQueue (kernel.c)\n");
	PCB* current;
	newPcb->next=NULL;
	
	if (head==NULL){
                head=newPcb;
               // head->next=NULL;
                printf("From addToReady(): Added first node to beginning\nIts contents are:!!!!!!!!!!!!!!!!!!!!!!1\n");
		printf("start: %d, end: %d, PC: %d\n",head->start, head->end, head->PC);
        }
	
	while(true){
		if(current->next==NULL){
			current=current->next;
			//printf("looping: now at pcb %d\n",i);
			printf("current PCB info:!!!!!!!!!!!!!!!!\n");
			printf("start: %d, end: %d, PC: %d\n",head->start, head->end, head->PC);
			ii++;
			break;
		}
	current->next=newPcb;
	//printf("From addToReady(): newPcb added to end of list\n");
	};
}

