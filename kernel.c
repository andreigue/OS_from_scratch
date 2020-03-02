//kernel.c
#include <stdio.h>
#include <string.h>
#include <stdlib.h> //for malloc
#include <stdbool.h> 
#include "pcb.h"
#include "shell.h"
#include "cpu.h"
#include "ram.h"

PCB* head = NULL;
PCB* tail=NULL;
void myinit(char* filename);
void scheduler();
void addToReady(PCB* pcb);
void printList();
void roundRobin();
void rmPCBfromReadyQ();
int i=0;
int y=0;

void main(int argc, char* argv[]) {
	
	printf("Kernel 1.0 loaded!\n");
	shellUI(argc, argv); //inside shell.c
//	void myinit(char* filename);	//instantiate the kernel data structure
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
	addToRAM(fp, start, end);//ram.c
	pcb = makePCB(*start, *end);//pcb.c
	addToReady(pcb);//kernel.c
	printList();
}

//called after all the programs have been loaded
void scheduler(){
	printf("Inside scheduler()@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");	
//	struct CPU* myCPU;
//	myCPU = (struct CPU*)malloc(sizeof(struct CPU));
	int quanta =2; //not sure how to make this into a constant
	while(head!=NULL){
		if(!cpuBusy){	//quanta finished or nothing is assigned to the cpu
		//copy PC from PCB into IP of CPU
			//PCB* curPCB=head;
			//myCPU->IP = curPCB->PC; 		
			run(quanta);
		//	curPCB->PC=myCPU->IP;
		//	roundRobin();
			
		}else{	//CPU is busy
			printf("Could not run program because the CPU is currently busy.\n");
		}
	}
	
}

void roundRobin(){
	PCB* PCBtoMove = head;
	head=PCBtoMove->next;
	tail->next=PCBtoMove;
	tail= PCBtoMove;	
}

//add PCB to tail of ready queue
void addToReady(PCB* newPcb){
	if(newPcb==NULL) printf("Unable to add newPCB to the readyQueue.\n");
	
	if (head==NULL){
                head=newPcb;
		tail=newPcb;
        }else{
		tail->next=newPcb;
		tail=newPcb;
	}
}

//print the ready queue
void printList(){
	printf("from printLst()!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
	PCB* current1;
	current1 = head;
	int j =1;
	while(current1!=NULL){
		printf("Node %d: start: %d, end: %d, PC: %d\n",j,current1->start, current1->end, current1->PC);
		current1=current1->next;
		j++;
	}
}


void rmPCBfromReadyQ(){
	if(head->next!=NULL){
		PCB* tmp=head->next;//need temp in order to rm previous head
		free(head);
		head=tmp;
		tmp==NULL;
	}
	else{//head->next==NULL
		free(head);
		head==NULL;
	}
}
