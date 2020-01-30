#include <stdlib.h>
#include <string.h>

struct shellmem{
	char *var;
	char *val;
	struct shellmem *next;
}shellmem;


struct shellmem memArray[200];

void initShellMemory(){
	
}


