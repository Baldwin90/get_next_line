/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 15:42:01 by achi              #+#    #+#             */
/*   Updated: 2016/11/01 15:42:02 by achi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	ch;
	size_t			i;
	char			*str;

	ch = c;
	i = 0;
	str = (char *)b;
	while (i < len)
		str[i++] = ch;
	return (b);
}
