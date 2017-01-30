/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjia <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 15:36:36 by jjia              #+#    #+#             */
/*   Updated: 2016/12/06 15:36:43 by jjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GET_NEXT_LINE_H

# define _GET_NEXT_LINE_H
# include <stdlib.h>
# include "./libft/libft.h"
# include <fcntl.h>
# define BUFF_SIZE 5


int							get_next_line(int fd, char **line);

#endif
