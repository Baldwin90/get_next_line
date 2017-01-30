#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
	char	*result;
	char	*disrupt;
	int		fd;

	disrupt = "test";
	fd = open("test", O_RDONLY);
	for (int i = 0; i < 5; ++i)
	{
		printf("return value: %i\n", get_next_line(fd, &result));
		printf("%s\n", result);
		printf("length: %lu\n", strlen(result));
		printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	}
	printf("%s\n", disrupt);
	printf("length: %lu\n", strlen(disrupt));
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("return value: %i\n", get_next_line(fd, &disrupt));
	printf("%s\n", disrupt);
	printf("length: %lu\n", strlen(disrupt));
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("return value: %i\n", get_next_line(fd, &disrupt));
	printf("%s\n", disrupt);
	printf("length: %lu\n", strlen(disrupt));
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	close(fd);
	return 0;
}