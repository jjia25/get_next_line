/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjia <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 23:24:52 by jjia              #+#    #+#             */
/*   Updated: 2016/12/14 23:24:57 by jjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "./libft/libft.h"
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	char *line;
	int fd;

	argc = 0;
	line = NULL;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		return (-1);
	}
	if (get_next_line(fd, &line) >= 0)
	{
		ft_putstr("Line is: "); ft_putstr(line);
		ft_putchar('\n');
	}
	if (get_next_line(fd, &line) >= 0)
	{
		ft_putstr("Line is: "); ft_putstr(line);
		ft_putchar('\n');
	}
	if (get_next_line(fd, &line) >= 0)
	{
		ft_putstr("Line is: "); ft_putstr(line);
		ft_putchar('\n');
	}
	if (get_next_line(fd, &line) >= 0)
	{
		ft_putstr("Line is: "); ft_putstr(line);
		ft_putchar('\n');
	}
	if (get_next_line(fd, &line) >= 0)
	{
		ft_putstr("Line is: "); ft_putstr(line);
		ft_putchar('\n');
	}
	// if (get_next_line(fd, &line) >= 0)
	// {
	// 	ft_putstr("Line is: "); ft_putstr(line);
	// 	ft_putchar('\n');
	// }
	// if (get_next_line(fd, &line) >= 0)
	// {
	// 	ft_putstr("Line is: "); ft_putstr(line);
	// 	ft_putchar('\n');
	// }
	// if (get_next_line(fd, &line) >= 0)
	// {
	// 	ft_putstr("Line is: "); ft_putstr(line);
	// 	ft_putchar('\n');
	// }
	// if (get_next_line(fd, &line) >= 0)
	// {
	// 	ft_putstr("Line is: "); ft_putstr(line);
	// 	ft_putchar('\n');
	// }
	// if (get_next_line(fd, &line) >= 0)
	// {
	// 	ft_putstr("Line is: "); ft_putstr(line);
	// 	ft_putchar('\n');
	// }
	// if (get_next_line(fd, &line) >= 0)
	// {
	// 	ft_putstr("Line is: "); ft_putstr(line);
	// 	ft_putchar('\n');
	// }
	close(fd);
	return (0);
}
