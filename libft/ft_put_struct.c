/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjia <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 21:51:13 by jjia              #+#    #+#             */
/*   Updated: 2016/12/15 21:51:18 by jjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_put_struct(t_mult_fd *mult_fd)
{
	t_mult_fd *tmp;

	tmp = mult_fd;
	while (tmp != NULL)
	{
		ft_putlist(tmp->list);
		tmp = tmp->next;
	}
}
