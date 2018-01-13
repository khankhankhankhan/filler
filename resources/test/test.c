#include <stdio.h>
#include <unistd.h>

int		main(void)
{
//	printf("test test test \n");
	while(1)
	{
		write(1, "4 14\n", 5);
	}
	return (0);
}
