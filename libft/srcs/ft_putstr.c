/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 19:51:51 by achi              #+#    #+#             */
/*   Updated: 2016/11/02 19:51:57 by achi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putstr(char const *s)
{
	int	i;

	if (s)
	{
		i = 0;
		while (s[i])
		{
			ft_putchar(s[i++]);
		}
	}
}