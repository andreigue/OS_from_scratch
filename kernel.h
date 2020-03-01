int* start; 
int* end;
void myinit(char* filename);
void scheduler();
void roundRobin();
void rmPCBfromReadyQ();
void printList();
extern struct PCB* head;
extern struct PCB* tail;
