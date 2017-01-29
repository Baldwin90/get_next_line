#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include "libft/includes/libft.h"

# define TRUE			1
# define FALSE			0
# define BUFF_SIZE		2048
# define F_COUNT_MAX	64
# define I	static
# define GNL_V I int total = 0; int i = 0; int j = 0;
# define GNL_1 if (fd < 0) {return (NULL);}
# define GNL_2 GNL_V GNL_1
# define LET file->buf[file->index + ind]
# define FD file->fd
# define BUF_IND file->buf_ind
# define N_BYTES_READ file->n_bytes_read
# define BUF file->buf

typedef struct	s_file
{
	int			fd;
	int			buf_ind;
	char		*last_stored;
	int			n_bytes_read;
	char		buf[BUFF_SIZE];
}				t_file;

int		get_next_line(const int fd, char **line);
#endif
