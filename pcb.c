//pcb.c

struct pcb{
	int PC; //program counter: update when quanta is over, point to instruction in ram to be executed
	int* start;
	int* end;
	struct pcb *next;
}

struct pcb *head=NULL;
struct pcb *current =NULL;

//display the list
void printList(){
	struct pcb *ptr = head;
	printf("\n[ ");

	while(ptr!=NULL){
		printf("(%d, %d) ", ptr->key, ptr->data);
		ptr=ptr->next;
	}
	printf(" ]");
}


void insert 



PCB* makePCB(int start, int end){

	

}

//add PCB to tail of ready queue
void addToReady(PCB* pcb){
	
}
