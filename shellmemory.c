#include <stdlib.h>
#include <string.h>

typedef struct shellmem{
	char *var;
	char *val;
	struct shellmem *next;
}shellmem;

