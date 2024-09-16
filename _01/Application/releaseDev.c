#include"headers.h"
#include"declarations.h"

void* releaseDev(void *arg)
{
	printf("%s: Begin.\n", __func__);

	close(fd);

	printf("%s: End.\n", __func__);
	return 0;
}
