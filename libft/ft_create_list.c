/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjia <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 18:12:28 by jjia              #+#    #+#             */
/*   Updated: 2016/12/15 18:12:30 by jjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_mult_fd		*ft_create_list(t_list *list, int fd)
{
	t_mult_fd	*tmp;

	if (!(tmp = (t_mult_fd*)malloc(sizeof(t_mult_fd))))
		return (0);
	tmp->list = list;
	tmp->fd = fd;
	tmp->next = NULL;
	return (tmp);
}
