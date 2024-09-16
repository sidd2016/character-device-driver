#include"headers.h"
#include"declarations.h"

void* mainMenu(void *arg)
{
	int i, ret, j;
	pthread_t thid;

	printf("%s: Begin.\n", __func__);

	printf("%s: Device Menu\n", __func__);
	printf("%s: 1: Open Device\n", __func__);
	printf("%s: 2: Close Device\n", __func__);
	printf("%s: 0: Exit Application\n", __func__);
	printf("%s: Please Enter Your Choice:\n", __func__);
	scanf("%d", &i);

	if(i == 0)
	{
		ret = pthread_create(&thid, 0, fptr[i+1], (void*)"success");   // 0);// (void*)"success");
		if(ret == -1)
		{
			perror("pthread_create");
			(*fptr[1])((void*)"failure");	
		}
	}

	//(*fptr[i+1])((void*)"success");

	//if( (i >= 1) && (i <= 2) )
	if(i == 1)
	{
		printf("%s: 1: Open Device In Write Mode\n", __func__);
		printf("%s: 2: Open Device In Read Mode\n", __func__);
		printf("%s: Please Enter Your Choice:\n", __func__);
		scanf("%d", &j);

		if(j == 1)
		{
			ret = pthread_create(&thid, 0, fptr[i+1], (void*)"writing");
			if(ret == -1)
			{
				perror("pthread_create");
				(*fptr[1])((void*)"failure");
			}
		}

		else
		{
			ret = pthread_create(&thid, 0, fptr[i+1], (void*)"reading");
			if(ret == -1)
			{
				perror("pthread_create");
				(*fptr[1])((void*)"failure");
			}
		}
	}

	//if( (i >= 1) && (i <= 2) )
	if(i == 2)
	{
		ret = pthread_create(&thid, 0, fptr[i+1], (void*)"writing");
		if(ret == -1)
		{
			perror("pthread_create");
			(*fptr[1])((void*)"failure");
		}
	}

	printf("%s: End.\n", __func__);
	return 0;
}
