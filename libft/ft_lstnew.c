/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjia <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:23:35 by jjia              #+#    #+#             */
/*   Updated: 2016/11/13 22:23:36 by jjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *data, size_t data_size)
{
	t_list *fresh;

	fresh = (t_list *)malloc(sizeof(t_list));
	if (fresh == 0)
		return (0);
	if (data == 0)
	{
		(fresh->data = 0);
		(fresh->data_size = 0);
	}
	else
	{
		fresh->data = (char *)malloc(data_size);
		if (data == 0)
		{
			free(fresh);
			return (0);
		}
		ft_memcpy((void *)&fresh->data, data, data_size);
		fresh->data_size = data_size;
	}
	fresh->next = 0;
	return (fresh);
}
