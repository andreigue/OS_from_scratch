typedef struct PCB{
	int start;
	int end; 
  	int PC;
	struct PCB *next;
}PCB;

PCB* makePCB(int start, int end);
