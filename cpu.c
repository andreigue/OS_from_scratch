#include <string.h>
bool cpuBusy=false;

struct CPU{
	char IR[1000];	//instruction register (currently executing instruction)
	int IP;		//points to next instruction to be executed from ram
	int quanta=2;	//quanta is 2 lines of code for each program
}

struct CPU* myCPU=NULL;

void run(int quanta){
	//set cpu to Busy
	cpuBusy=true; 
	//run the script by copying quanta lines of code from ram[] using IP into the IR
	
	//which then calls interpreter(IR)
	parse(myCPU->IR);
	//set CPU to notBusy
	cpuBusy=false;	
}

