#include "libft/includes/libft.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "get_next_line.h"

#include <stdio.h> // DELETE ME!!!

t_file 	*new_file(const int fd)
{
	static t_file file[F_COUNT_MAX];

	GNL_2;
	while (i <= total)
	{
		if (i == total && total < F_COUNT_MAX)
		{
			total += 1;
			file[i].fd = fd;
			file[i].buf_ind = 0;
			file[i].last_stored = NULL;
			file[i].n_bytes_read = 0;
			while (j < BUFF_SIZE)
			{
				file[i].buf[j] = 0;
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

void	grow_string(t_file *file, int *i, char **result, int *result_len)
{
	char *tmp;

	tmp = *result;
	if (!(*result = (char*)ft_memalloc(*result_len + *i + 1)))
	{
		return ;
	}
	ft_memcpy(*result, tmp, *result_len);
	ft_memcpy(&(*result)[*result_len], &(BUF[BUF_IND]), *i);
	if (tmp)
		free(tmp);
	BUF_IND += *i + 1;
	*result_len += *i;
	*i = -1;
}

char	*store_line(t_file *file, char *result, int result_len, int *r_code)
{
	int i;

	i = -1;
	if (N_BYTES_READ == 0 && (N_BYTES_READ =\
		read(file->fd, BUF, BUFF_SIZE - 1)) == 0)
		return (result);
	while (TRUE)
	{
		if (++i + BUF_IND >= BUFF_SIZE || i + BUF_IND >= N_BYTES_READ)
		{
			grow_string(file, &i, &result, &result_len);
			BUF_IND = 0;
			if ((N_BYTES_READ = read(file->fd, BUF, BUFF_SIZE - 1)) < 1)
			{
				*r_code = N_BYTES_READ == 0 ? 0 : -1;
				// printf("file descriptor: %i\n", FD);
				// printf("N_BYTES_READ: %i\n", N_BYTES_READ);
				return (NULL);
			}
		}
		else if (BUF[i + BUF_IND] == '\n')
		{
			// printf("RAN!!!\n");
			grow_string(file, &i, &result, &result_len);
			break;
		}
	}
	return (result);
}

int		get_next_line(const int fd, char **line)
{
	t_file	*file;
	char	*result;
	int		r_code;

	r_code = 0;
	if (!(file = new_file(fd)))
		return (-1); // I think this means it wasnt able to read from the file
	// if (*line == file->last_stored && *line != NULL)
	// 	free(*line); // double check this
	if (!(result = (char*)ft_memalloc(1)))
		return (-1);
	if (!(result = store_line(file, result, 0, &r_code)))
		return (-1);
	file->last_stored = result;
	*line = result;
	// return (r_code);
	return (r_code);
}
