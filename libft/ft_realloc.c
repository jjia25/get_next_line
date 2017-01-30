/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjia <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 12:31:04 by jjia              #+#    #+#             */
/*   Updated: 2017/01/12 12:31:08 by jjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_realloc(void **ptr, size_t old, size_t new_size)
{
	void	*new;

	if (!ptr && !old)
		return (NULL);
	if (new_size == 0)
		new = (void *)ft_memalloc(sizeof(char));
	else
	{
		if (!(new = (void *)malloc(new_size)))
		return (NULL);
	}
	ft_bzero(new, (new_size) ? new_size : sizeof(char));
	if (new_size == 0)
		ft_memcpy(new, ptr, sizeof(char));
	else
		ft_memcpy(new, ptr, new_size);
	//free(&ptr);
	return (new);
}
