/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjia <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 21:34:35 by jjia              #+#    #+#             */
/*   Updated: 2016/12/08 21:34:37 by jjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putlist(t_list *list)
{
	t_list	*tmp;

	tmp = list;
	while (tmp)
	{
		ft_putstr(tmp->data);
		tmp = tmp->next;
	}
}
