#include"headers.h"
#include"declarations.h"

void* exitApplication(void *arg)
{
	printf("%s: Begin.\n", __func__);

	if( strncmp((char*)arg, "success", 7) == 0 )
		exit(EXIT_SUCCESS);
	else if( strncmp((char*)arg, "failure", 7) == 0 )
		exit(EXIT_FAILURE);


	printf("%s: End.\n", __func__);
	return 0;
}
