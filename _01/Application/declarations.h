#define NOF 6

int init();
extern int fd;

extern void* mainMenu(void*);
extern void* exitApplication(void*);
extern void* openDev(void*);
extern void* releaseDev(void*);
extern void* writeDev(void*);
extern void* readDev(void*);

extern void* (*fptr[NOF])(void*);
