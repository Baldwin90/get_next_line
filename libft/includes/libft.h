/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 15:47:15 by achi              #+#    #+#             */
/*   Updated: 2016/12/15 11:10:20 by pbaldwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <unistd.h>
# include <wchar.h>
# include <stdint.h>

# define TRUE	1
# define FALSE	0

typedef struct	s_l
{
	void		*content;
	size_t		content_size;
	struct s_l	*next;
}				t_list;

/*
** LIBFT
** V V V
*/
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_strtrim(char const *s);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strstr(const char *big, const char *little);
char			**ft_strsplit(char const *s, char c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strnstr(const char *big, const char *little, size_t n);
char			*ft_strnew(size_t size);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strncpy(char *dst, const char *src, size_t len);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strncat(char *s1, const char *s2, size_t n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strmap(char const *s, char (*f)(char));
size_t			ft_strlen(const char *s);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strjoin(char const *s1, const char *s2);
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
void			ft_striter(char *s, void (*f)(char *));
int				ft_strequ(char const *s1, char const *s2);
char			*ft_strdup(const char *s);
void			ft_strdel(char **as);
char			*ft_strcpy(char *dst, const char *src);
int				ft_strcmp(const char *s1, const char *s2);
void			ft_strclr(char *s);
char			*ft_strchr(const char *s, int c);
char			*ft_strcat(char *s1, const char *s2);
void			ft_putstr(char const *s);
void			ft_putstr_fd(char const *s, int fd);

/*
** prints an int to standard out
*/
void			ft_putnbr(int n);

/*
** prints an into to the file descriptor
*/
void			ft_putnbr_fd(int n, int fd);
void			ft_putendl(char const *s);
void			ft_putendl_fd(char const *s, int fd);

/*
** prints a char to standard out
*/
void			ft_putchar(char c);

/*
** prints a char to the file descriptor
*/
void			ft_putchar_fd(char c, int fd);
void			*ft_memset(void *b, int c, size_t len);

/*
** copies n number of byets of memory from the source to the desination
** this will check for collisions.
** if the memory being copied ever matches the address of the dest then...
** ...copying will stop, even if the number of bytes copied is less than n.
** to indescrimiently copy memory, use memcpy.
*/
void			*ft_memmove(void *dst, const void *src, size_t len);
void			ft_memdel(void **ap);

/*
** copies n number of bytes memory from the source to the destination
** this will not check for collisions.
** if the memory being copied is the starting point of the dest.
** to prevent collisions use memmove.
*/
char			*ft_memcpy(void *dst, const void *src, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memalloc(size_t size);
char			*ft_itoa(int n);
int				ft_isprint(int c);
int				ft_isdigit(int c);
int				ft_isascii(int c);
int				ft_isalpha(int c);
int				ft_isalnum(int c);
int				ft_isnumeric(char *str);
void			ft_bzero(void *s, size_t n);
int				ft_atoi(const char *nptr);
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list			*ft_lstnew(void const *content, size_t content_size);
double			ft_sqrt(double n);
int				ft_ceil(double n);
char			*ft_strndup(const char *s1, size_t n);
int				ft_strcontains(char const *s, char c);
size_t			ft_strclen(const char *s, char c);
size_t			ft_strsplice(char **head, size_t tgt, size_t amt, char *src);
void			*ft_memjoin(void const *s1, void const *s2, int dlen, int slen);
char			*ft_llutoa_base(unsigned long long n, int base);

/*
** converts all alphabetical characters in a string to uppercase.
** this should ONLY be used on writeable strings.
*/
void			ft_strupcase(char *str);

/*
** converts all alphabetical characters in a string to lowercase.
** this should ONLY be used on writeable strings.
*/
void			ft_strlowcase(char *str);

/*
** do ft_memmove first
*/
void			*ft_realloc(void *old_ptr, size_t old_size, size_t new_size);

/*
** returns an int that is the index of the first occurance of the char c
** if the char is not in the string then -1 is returned
*/
int				ft_indexof(char c, char const *str);

/*
** returns 1 if the char passed in is considered whitespace (specifically...
** ...9-13 and 32 on the ascii table as that is what atoi considers...
** ...whitespace) and returns 0 if it's not whitespace.
*/
int				ft_isws(char c);

/*
** returns the index of the first char that isn't whitespace in a string
*/
int				ft_first_nws_ind(char *str);

/*
** returns the index of the last char that isn't whitespace in a string
*/
int				ft_last_nws_ind(char *str);

/*
** prints the contents of a two dimentional array with a /n separating elements
*/
void			ft_print_matrix(char **matrix);

/*
** prints the contents of a two dimentional array to the file descriptor...
** ...with a/n separating elements
*/
void			ft_print_matrix_fd(char **matrix, int fd);
#endif
