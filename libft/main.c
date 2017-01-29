#include "get_next_line.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int main(void)
{
	char *str1;
	char *str2;
	char *str3;
	int fd1;
	int fd2;
	int fd3;

	fd1 = open("test1", O_RDONLY);
	fd2 = open("test2", O_RDONLY);
	fd3 = open("test3", O_RDONLY);

	for (int i = 0; i < 10; ++i)
	{
		printf("fd1 run %i returned %i\n", i + 1, get_next_line(fd1, &str1));
		printf("str1: %s\n", str1);
		if (str1)
			printf("len: %zu\n", ft_strlen(str1));
		printf("\n");
		printf("fd2 run %i returned %i\n", i + 1, get_next_line(fd2, &str2));
		printf("str2: %s\n", str2);
		if (str2)
			printf("len: %zu\n", ft_strlen(str2));
		printf("\n");
		printf("fd3 run %i returned %i\n", i + 1, get_next_line(fd3, &str3));
		printf("str3: %s\n", str3);
		if (str3)
			printf("len: %zu\n", ft_strlen(str3));
		printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
		printf("\n");
		printf("\n");
	}
	close(fd1);
	close(fd2);
	return 0;
}