#include"headers.h"
#include"declarations.h"

int main()
{
	printf("%s: Begin.\n", __func__);

	init();


	while(1)
		(*fptr[0])(0);   //  mainMenu

	printf("%s: End.\n", __func__);
	return 0;
}
