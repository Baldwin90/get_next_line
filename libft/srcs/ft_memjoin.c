/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 15:41:26 by achi              #+#    #+#             */
/*   Updated: 2016/11/01 15:41:27 by achi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memjoin(void const *s1, void const *s2, int dlen, int slen)
{
	int		i;
	char	*ret;

	if ((ret = ft_strnew(slen + dlen)))
	{
		i = -1;
		while (++i < dlen)
			ret[i] = ((char *)s1)[i];
		i = -1;
		while (++i < slen)
			ret[dlen + i] = ((char *)s2)[i];
		return (ret);
	}
	return (0);
}
