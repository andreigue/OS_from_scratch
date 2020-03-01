#include <string.h>
#include <stdio.h> 
#include <stdlib.h>
#include "shell.h"
#include "cpu.h"
#include "pcb.h"
#include "ram.h"
#include "kernel.h"
int cpuBusy=0;//not busy=0

void run(int quanta){
	int i;
        struct CPU* myCPU=(struct CPU*)malloc(sizeof(struct CPU));
        int endOfFile=head->end;	//end of the currently executed PCB
	//set cpu to Busy
	cpuBusy=1; //1=busy
	//run the script by copying quanta lines of code from ram[] using IP into the IR
	
	while(myCPU->quanta>0 && myCPU->IP<endOfFile){
		if(ram[myCPU->IP]!=NULL){
			strcpy(myCPU->IR, ram[myCPU->IP]);
			parse(myCPU->IR);
			myCPU->IP++;//point to next instruction in RAM
			myCPU->quanta--;
		}
		else{
			if(myCPU->quanta<=0){
				head->PC=myCPU->IP;//update PCB IP to continue where left off
				roundRobin();//kernel.c
			}
			else if(myCPU->IP>=endOfFile){
				removeFromRAM(head);//ram.c
				rmPCBfromReadyQ();//kernel.c
			} 

		}
	}

	//set CPU to notBusy
	cpuBusy=0;//not busy
}

