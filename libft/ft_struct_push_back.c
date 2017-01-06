/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_push_back.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjia <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 18:10:07 by jjia              #+#    #+#             */
/*   Updated: 2016/12/15 18:10:09 by jjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_struct_push_back(t_mult_fd **begin_struct, t_list **list, int fd)
{
	t_mult_fd *temp;
	t_mult_fd *new_node;

	if (!(new_node = ft_create_list(*list, fd)))
		return ;
	temp = *begin_struct;
	if (temp != NULL)
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_node;
	}
	else
		*begin_struct = new_node;
	*list = new_node->list;
}
