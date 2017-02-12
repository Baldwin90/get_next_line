#include "get_next_line.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
	char	*line;
	int		fd;
	int		gnl_result;

	fd = open("test", O_RDONLY);
	while ((gnl_result = get_next_line(fd, &line))) {
		printf("returned %i\n", gnl_result);
		printf("'%s'\n\n", line);
	}
	printf("returned %i\n", gnl_result);
	printf("'%s'\n", line);
	close(fd);
	return 0;
}