/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjia <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 15:38:42 by jjia              #+#    #+#             */
/*   Updated: 2017/01/19 19:30:53 by jjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static void move_to_front(char *buffer, int b4_nl)
{
	char *afternl;
	char *after_move;
	afternl = (buffer + b4_nl + 1);
	char *nl = ft_strchr(buffer, '\n');
	after_move = buffer + ft_strlen(afternl);
	// printf("9) Buffer is: %s\n", buffer);
	//printf("1) b4_nl is: %d\n", b4_nl);
	//printf("after_nl is: %s\n", afternl);
	if (nl)
	{
		ft_memmove(buffer, afternl, ft_strlen(afternl));
		// printf("after_nl is: %s\n", afternl);
		ft_bzero(after_move, ft_strlen(after_move));
		// printf("3) Buffer is: %s\n", buffer);
	}
	// printf("9) Buffer is: %s\n", buffer);
}

static void	read_to_nl(char *buffer, char **line, int chars_read)
{
	int i;
	int line_len = 0;

	i = 0;
	// printf("5) chars_read is: %d\n", chars_read);
	// printf("5) Buffer is: %s\n", buffer);
	// printf("b4_nl is: %d\n", b4_nl);
	// printf("buffer size is: %zu\n", ft_strlen(buffer));
	
	if (!*line)
	{
		// printf("mallocing line\n");
		if (!(*line = (char *)malloc(sizeof(char) * chars_read + 1)))
			return ;
		// printf("line malloced chars_read %i\n", chars_read);
		*(*line + chars_read) = '\0';
	}
	// printf("hello\n");

	// else
	// {
		line_len = ft_strlen(*line);
		ft_realloc((void **)line, line_len, line_len + chars_read + 1);
		//line_len = ft_strlen(*line);
		// printf("2) line size is: %zu\n", ft_strlen(*line));
	// printf("*line + chars_read is: %d\n", *(*line + chars_read));
		//ft_bzero(*line, ft_strlen(*line));
		(*line)[line_len + chars_read] = 0;
	// printf("(*line)[line_len + i] is: %d\n", line_len + i);
	// }
	while (i < chars_read)
	{
		// printf("*buffer[i] is: %c\n", (buffer)[i]);
		(*line)[line_len + i] = (buffer)[i];
		// printf("i is: %d\n", i);
		// printf("*line[line_len + i] is: %c\n", (*line)[line_len + i]);
		i++;
	}
	// printf("5) Line is: %s\n", *line);
	move_to_front(buffer, chars_read);
	// printf("7) Line is: %s\n", *line);
	// printf("2) Buffer is: %s\n", buffer);
	//return (1);
}

static int	string_to_nl(char *buffer, int fd, char **line, int chars_read)
{
	// printf("1) Buffer is: %s\n", buffer);=
	// printf("1) Chars read is: %d\n", chars_read);
	
	int		len;
	char	*nl;
	int		nllen;
	// if ((chars_read = read(fd, buffer + ft_strlen(buffer), BUFF_SIZE)) <= 0)
	// 	return (chars_read);
	int read_again = chars_read;
	// printf("1) Chars read is: %d\n", chars_read);
	// printf("8) Buffer is: %s\n", buffer);
	nl = ft_strchr(buffer, '\n');
	// if (!(*line = (char *)malloc(sizeof(char) * chars_read + 1)))
	// 	return (-1);
	//*(*line + chars_read) = '\0';
	// printf("Yes\n");
	if (!nl && chars_read < BUFF_SIZE)
	{
		// printf("Returning\n");
		read_to_nl(buffer, line, chars_read);
		// printf("yes\n");
		//return (chars_read);
	}
	
	while (!nl)
	{
		// printf("entering\n");
		// move_to_front(buffer, read_again);
		read_to_nl(buffer, line, read_again);
		ft_bzero(buffer, BUFF_SIZE);
		//move_to_front(buffer, read_again);
		// printf("buffer + read_again is: %s\n", (buffer + read_again));
		read_again = read(fd, buffer + ft_strlen(buffer), BUFF_SIZE);
		// printf("read again is: %d\n", read_again);
		chars_read = read_again;
		nl = ft_strchr(buffer, '\n');
		//ft_putstr("buffer is: "); ft_putendl(buffer);
		// printf("read_again is: %d\n", read_again);
	}
	if (nl == NULL)
		return (read_again);
	// printf("6) Buffer is: %s\n", buffer);
	len = ft_strlen(buffer);
	// printf("len is: %d\n", len);
	nllen = len - ft_strlen(nl);
	//ft_putendl("nllen is: "); ft_putnbr(nllen); ft_putchar('\n');
	return (nllen);
}

int get_next_line(int fd, char **line)
{
	static char *buffer;
	int chars_read;
	int b4_nl = 0;
	*line = NULL;
	if (fd <= 0 || !line)
		return (-1);
	if (!buffer)
	{
		if (!(buffer = (char *)malloc(sizeof(char) * BUFF_SIZE + 1)))
			return (-1);
		// printf("Buffer malloced\n");
		ft_bzero(buffer, BUFF_SIZE + 1);
		if ((chars_read = read(fd, buffer, BUFF_SIZE)) <= 0)
			return (chars_read);
	}
	// printf("0) Buffer is: %s\n", buffer);
	ft_bzero((void *)(buffer + ft_strlen(buffer)), BUFF_SIZE + 1);
	if ((chars_read = read(fd, buffer + ft_strlen(buffer), BUFF_SIZE)) <= 0)
	{
		if (ft_strlen(buffer) > 0)
		{
			chars_read = ft_strlen(buffer);
			// printf("3) chars read is: %d\n", chars_read);
		}
		else if (ft_strlen(buffer) <= 0)
		{
			// printf("2) chars read is: %d\n", chars_read);
			return (chars_read);
		}
	}
	// printf("0) chars read is: %d\n", chars_read);
	// printf("-1) Buffer is: %s\n", buffer);
	
	// printf("1) line size is: %zu\n", ft_strlen(*line));
	if (!(b4_nl = string_to_nl(buffer, fd, line, chars_read)))
		return (-1);
	
		// printf("line malloced chars_read %i\n", chars_read);
	//*(*line + b4_nl) = '\0';
	// printf("1) b4_nl is: %d\n", b4_nl);
	read_to_nl(buffer, line, b4_nl);
	// printf("6) Line is: %s\n", *line);
	if (chars_read > 0)
		return (1);
	return (0);
}
