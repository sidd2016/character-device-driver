#include"headers.h"
#include"declarations.h"
 
void* mainMenu(void*);
void* exitApplication(void*);
void* openDev(void*);
void* releaseDev(void*);
void* writeDev(void*);
void* readDev(void*);

void* (*fptr[NOF])(void*);

int init()
{
	printf("%s: Begin.\n", __func__);

	fptr[0] = mainMenu;
	fptr[1] = exitApplication;
	fptr[2] = openDev;
	fptr[3] = releaseDev;
	fptr[4] = writeDev;
	fptr[5] = readDev;

	printf("%s: End.\n", __func__);
	return 0;
}            
