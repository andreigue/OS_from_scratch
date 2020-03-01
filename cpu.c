#include <string.h>
#include <stdio.h> 
//#define DEFAULT_QUANTA 2
#include "shell.h"
#include "cpu.h"
#include "pcb.h"
#include "ram.h"
#include "kernel.h"
int cpuBusy=0;//not busy=0

struct CPU* myCPU=NULL;

void run(int quanta){
	
	int i;
	//set cpu to Busy
	cpuBusy=1; //1=busy
	//run the script by copying quanta lines of code from ram[] using IP into the IR
	while(quanta>0 && myCPU->IP<EOF){
		
		if(fgets(myCPU->IR, 999,ram[myCPU->IP])!=NULL){     //reading from IP, save in IR
		//myCPU->IR=ram[myCPU->IP];
		parse(myCPU->IR);       //from shell.h
		}///////////////////////
		if(quanta==0 && myCPU->IP<*head) roundRobin();
		else{ //(myCPU->IP==EOF)
		deletePCB(head);	//once remove pcb, break out the loop
		
		}	
		quanta--;
	}
	//set CPU to notBusy
	cpuBusy=0;//not busy	
}

