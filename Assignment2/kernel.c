#include <stdio.h>
#include <string.h>

#include "shell.h"

void myinit(char* filename);
void main(int argc, char* argv[]) {
	
	printf("Kernel 1.0 loaded!\n");
	shellUI(argc, argv); //call shellUI inside shell.c
	//instantiate the kernel data structure
	void myinit(char* filename);	
}

void myinit(char* filename){


}

//called after all the programs have been loaded
void scheduler(){


//check to see if the CPU is available (quanta is finished or nothing is assigned to the CPU)

//copy PC from PCB into the IP of the CPU

//

}
