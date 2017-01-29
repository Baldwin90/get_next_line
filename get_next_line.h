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
/*
** might not be needed
** # define BUFF_SIZE_TOTAL	(BUFF_SIZE * F_COUNT_MAX)
*/

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

// make an i to add with file->index
// loop through buffer until it either reaches '\n', EOF or i + file->index == BUFF_SIZE
	// if i + file->index == 

// you're going to be making a new string, so make it the size of the buffer
// copy everything from the buffer into the result
	// if you hit '\n' or EOF then you stop copying
	// check if file->index + 1 is BUFF_SIZE
		// if it is then you need to read from the file again
		// you also need to copy the result pointer to a temp pointer
		// assign new memory to the result pointer; it will bee the result length + BUFF_SIZE
		// memcpy the contents of tmp to result. It will be copied the result length
		// free tmp
	// always incriment result length and file->index

// if index > BUFFERSIZE
	// index = 0;
	// read in next buffer
	