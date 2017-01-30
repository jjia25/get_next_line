/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 12:30:39 by aphan             #+#    #+#             */
/*   Updated: 2016/10/21 21:05:40 by aphan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	int		i;
	int		fd[argc];
	int		fdcount;
	int		printcount;
	int		ret;
	char	*line;

	if (argc > 2)
	{
		printcount = atoi(argv[1]);
		if (printcount < 1)
			printf("USAGE: ./gnl_test [number of lines] [filename1] [filename2] ...\n");
		else
		{
			i = 0;
			while(i < argc)
			{
				fd[i] = open(argv[i + 2], O_RDONLY);
				i++;
			}
			i = 0;
			line = "ORIGINAL MAIN LINE";
			fdcount = argc - 2;
			while (i < printcount)
			{
				ret = get_next_line(fd[i % fdcount], &line);
				printf("i:%3i, fd[%i], Ret:%2i, Line:%s\n", i, i % fdcount, ret, line);
				if (ret != -1)
					free(line);
				i++;
			}
		}
	}
	else
		printf("USAGE: ./gnl_test [number of lines] [filename1] [filename2] ...\n");
	return (0);
}
