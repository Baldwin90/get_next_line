#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include "libft/includes/libft.h"

# define TRUE			1
# define FALSE			0
# define BUFF_SIZE		2048
# define F_COUNT_MAX	64
# define I	static
# define V	I t_file file[F_COUNT_MAX]; I int total = 0; int i = 0; int j = 0;
/*
** might not be needed
** # define BUFF_SIZE_TOTAL	(BUFF_SIZE * F_COUNT_MAX)
*/

typedef		s_file
{
	int		fd;
	int		index;
	char	buff[BUFF_SIZE];
}			t_file;

int		get_next_line(const int fd, char **line);
#endif