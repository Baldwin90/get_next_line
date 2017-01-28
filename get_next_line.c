#include <libft.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "get_next_line.h"

int				get_next_line(const int fd, char **line)
{
	t_file *file;

	if (!(file = new_file(fd)))
	{
		return (-1); // I think this means it wasnt able to read from the file
	}
	file 
}

t_file *new_file(const int fd)
{
	V;
	if (fd < 0)
		return (NULL);
	while (i <= total)
	{
		if (i == total && total < F_COUNT_MAX)
		{
			total += 1;
			file[i].fd = fd;
			file[i].index = 0;
			while (j < BUFF_SIZE)
			{
				file[i].buff[j] = 0;
				j += 1;
			}
			return (&file[i]);
		}
		else if (file[i].fd == fd)
			return (&file[i]);
		i += 1;
	}
	return (NULL);
}
