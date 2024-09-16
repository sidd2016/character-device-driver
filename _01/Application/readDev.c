#include"headers.h"
#include"declarations.h"

void* readDev(void *arg)
{
	printf("%s: Begin.\n", __func__);
	int fd,ret;
//	char *buff = "Hello Kernel";
	char *buff;
 	fd = *(int*)arg;
	buff = (char*)malloc(sizeof(char)*15);
	if(!buff)
	{
		perror("malloc()");
		(*fptr[1])((void*)"failure");
	}

	
	printf("%s: Please enter the .\n", __func__);

	ret = read(fd, buff, 12);// sizeof(buff));
	if(ret == -1)
	{
		perror("pthread_create");
		(*fptr[1])((void*)"failure");
	}

	printf("%s: read %s\n", __func__, buff);

	printf("%s: read %d byte.\n", __func__, ret);


	printf("%s: End.\n", __func__);
	return 0;
}
