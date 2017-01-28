/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 15:44:13 by achi              #+#    #+#             */
/*   Updated: 2016/11/01 15:44:14 by achi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strdup(const char *s)
{
	int		i;
	int		length;
	char	*ret;

	length = ft_strlen(s);
	if (!(ret = (char *)malloc(sizeof(char) * (length + 1))))
		return (0);
	i = 0;
	while (i <= length)
	{
		ret[i] = s[i];
		i++;
	}
	return (ret);
}
