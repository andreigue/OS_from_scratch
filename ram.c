

char* ram[1000];

void addToRAM(FILE *p, int *start, int *end){
	//find next available cell in ram[]
	int availIndex = getEmptyRAMcell();
	if (availIndex==-1) printf("Message from ram.c: RAM full\n");
}

int getEmptyRAMcell(){
	int i;
	for(i=0;i<1000;i++){
		if(ram[i]==NULL) return i
	}
	if(i=999) return -1;	//will be error (RAM full)
}

int getRAMindex(FILE* p){
	int i;
		for(i=0; i<1000;i++){
			if(ram[i]=p) return i
		}
}

void emptyRAM(FILE* p){
	int i;
	for(i=0;i<1000;i++) ram[i]=NULL;
}

