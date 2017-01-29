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
	// if nothing is in the buffer and you get nothing from reading from the file then the file is done
	// so you should return an empty string and a return code of 0
	if (BUF_IND >= N_BYTES_READ && (N_BYTES_READ = read(file->fd, BUF, BUFF_SIZE - 1)) == 0)
	{
		*r_code = 0;
		return (result);
	}
	while (TRUE)
	{
		*r_code = 1;
		// if you've indexed to the buffer size or the number of stored bytes you need to
		// copy the buffer, statring at the buf_ind to the end of the current result
		if (++i + BUF_IND >= BUFF_SIZE || i + BUF_IND >= N_BYTES_READ)
		{
			grow_string(file, &i, &result, &result_len);
			BUF_IND = 0;
			// you need to refresh the buffer with new characters
			// if the you get back nothing then you reached the end of the file.
			if ((N_BYTES_READ = read(file->fd, BUF, BUFF_SIZE - 1)) < 0)
			{
				*r_code = -1;
				return (result);
			}
		}
		// if it's '\n' then you
		else if (BUF[i + BUF_IND] == '\n')
		{
			grow_string(file, &i, &result, &result_len);
			break;
		}
		if (N_BYTES_READ == 0)
			return (result);
	}
	// printf("%i\n", i);
	// printf("%i\n", N_BYTES_READ);
	// printf("%i\n", BUF_IND);
	// printf("%i\n", i);
	// printf("%i\n", i);
	// printf("%i\n", i);
	// printf("%i\n", i);
	// printf("%i\n", i);
	// printf("%i\n", i);
	// printf("%i\n", i);
	return (result);
}

int		get_next_line(const int fd, char **line)
{
	t_file	*file;
	char	*result;
	int		r_code;

	r_code = -1;
	if (!(file = new_file(fd)) || line == NULL)
		return (r_code);
	// if (*line == file->last_stored && *line != NULL) // WTF WON'T YOU WORK!?!?!?!?
	// 	free(*line); // double check this
	if (!(result = (char*)ft_memalloc(1)))
		return (r_code);
	if (!(result = store_line(file, result, 0, &r_code)))
		return (-1);
	file->last_stored = result;
	*line = result;
	// return (r_code);
	return (r_code);
}
