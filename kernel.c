#include <stdio.h>
#include <string.h>

#include "shell.h"
#include "cpu.h"

void myinit(char* filename);
void main(int argc, char* argv[]) {
	
	printf("Kernel 1.0 loaded!\n");
	shellUI(argc, argv); //call shellUI inside shell.c
	//instantiate the kernel data structure
	void myinit(char* filename);	
}

void myinit(char* filename){
	int* start, end;
	struct* pcb;
	addToRAM(filename, start, end);
	pcb = makePCB(start, end);
	addToReady(pcb);

}

//called after all the programs have been loaded
void scheduler(){
	
	if(!cpuBusy){	//quanta finished or nothing is assigned to the cpu
		IP = PC;		
		
	}
//copy PC from PCB into the IP of the CPU

//

}
