/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 14:43:07 by achi              #+#    #+#             */
/*   Updated: 2016/10/11 14:43:08 by achi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_realloc(void *old_ptr, size_t old_size, size_t new_size)
{
	void *new_ptr;

	if (!(new_ptr = ft_memalloc(new_size)))
		return (NULL);
	ft_memmove(new_ptr, old_ptr, old_size);
	free(old_ptr);
	return (new_ptr);
}
