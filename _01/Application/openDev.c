#include"headers.h"
#include"declarations.h"

int fd;

void* openDev(void *arg)
{
	pthread_t thid;
	int ret;

	printf("%s: Begin.\n", __func__);
	
//	fd = open("../mydev", O_WRONLY);
//	if(!fd)
//	{
//		perror("open");
//		(*fptr[1])((void*)"failure");
//	}
//	printf("fd:%d\n", fd);

	if( strncmp((char*)arg,"writing",7) ==0 )
	{
		fd = open("../mydev", O_WRONLY);
		ret = pthread_create(&thid, 0, fptr[4], (void*)&fd);
			if(ret == -1)
			{
				perror("pthread_create");
				(*fptr[1])((void*)"failure");
			}
		printf("fd:%d\n", fd);
	}

	else if( strncmp((char*)arg,"reading",7) ==0 )
	{
		fd = open("../mydev", O_RDONLY);
		ret = pthread_create(&thid, 0, fptr[5], (void*)&fd);
			if(ret == -1)
			{
				perror("pthread_create");
				(*fptr[1])((void*)"failure");
			}
		printf("fd:%d\n", fd);
	}

	printf("%s: End.\n", __func__);
	return 0;
}
