#include <string.h>
#include <stdio.h> 
#define DEFAULT_QUANTA 2
#include "shell.h"
#include "cpu.h"


_Bool cpuBusy=false;


struct CPU* myCPU=NULL;

void run(int quanta){
	int i;
	//set cpu to Busy
	cpuBusy=true; 
	//run the script by copying quanta lines of code from ram[] using IP into the IR
	for(i=DEFAULT_QUANTA; i>0; i--){
		if(fgets(myCPU->IR, 999, myCPU->IP)!=NULL){	//reading from IP, save in IR
			parse(myCPU->IR);	//from shell.h
		}	
	}
	//set CPU to notBusy
	cpuBusy=false;	
}

