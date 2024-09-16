#include"headers.h"
#include"declarations.h"

void* writeDev(void *arg)
{
	printf("%s: Begin.\n", __func__);

	int fd,ret;
	char *buff = "Hello Kernel";
	fd = *(int*)arg;
	ret = write(fd, buff, strlen(buff));
	if(ret == -1)
	{
		perror("pthread_create");
		(*fptr[1])((void*)"failure");
	}
	printf("%s: wrote %d bytes.\n", __func__, ret);


	printf("%s: End.\n", __func__);
	return 0;
}
