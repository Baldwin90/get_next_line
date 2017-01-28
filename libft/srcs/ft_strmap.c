/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 15:45:15 by achi              #+#    #+#             */
/*   Updated: 2016/11/01 15:45:16 by achi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*ret;

	if (s && (ret = ft_strnew(ft_strlen(s))))
	{
		i = 0;
		while (s[i])
		{
			ret[i] = f(s[i]);
			i++;
		}
		return (ret);
	}
	return (0);
}
