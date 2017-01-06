/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjia <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 15:38:42 by jjia              #+#    #+#             */
/*   Updated: 2016/12/06 15:38:43 by jjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	read_list(t_list **list, int *fd, char **buffer)
{
	int index;
	int chars_read;
	char *tmp_buff;

	index = 0;
	if (!(tmp_buff = (char *)malloc(sizeof(char) * BUFF_SIZE)))
		return (-1);
	chars_read = read(*fd, tmp_buff, BUFF_SIZE);
	if (chars_read < 0)
		return (-1);
	*buffer = tmp_buff;
	while (index < chars_read)
	{
		ft_list_push_back(list, buffer[0][index]);
		index++;
	}
	ft_putstr("List read\n");
	free (tmp_buff);
	return (chars_read);
}

//static int list_new_line(t_mult_fd **mult_fd, int *fd, char **buffer)
static int list_new_line(t_list **list, int *fd, char **buffer)
{
	int count;
	t_list *tmp;
	//t_list *tmp_list;
	int chars_read;

	count = 0;
	tmp = *list;
	ft_putstr("Is this working?\n");
	while (tmp && tmp->data != '\n' && tmp->data != 0)
	{
		count++;
		//ft_putstr("Count is: "); ft_putnbr(count); ft_putchar('\n');
		tmp = tmp->next;
	}
	//ft_putstr("List: "); ft_putlist(*list); ft_putchar('\n');
	//ft_putstr("List size is: "); ft_putnbr(ft_list_size((*mult_fd)->list)); ft_putchar('\n');
	while (count == ft_list_size(*list))
	{
		if ((chars_read = read_list(list, fd, buffer)) == 0)
		{
			ft_putstr("Hello again\n");
			break ;
		}
		tmp = *list;
		count = 0;
		while (tmp && tmp->data != '\n' && tmp->data != 0)
		{
			count++;
			//ft_putstr("2) Count is: "); ft_putnbr(count); ft_putchar('\n');
			tmp = tmp->next;
		}
	}
	ft_putstr("Count is: "); ft_putnbr(count); ft_putchar('\n');
	return (count);
}

static void list_to_line(t_mult_fd *mult_fd, int *b4_nl, char **line)
{
	int i;
	t_list *tmp;

	i = 0;
	ft_putstr("0) List is: "); ft_putlist(mult_fd->list); ft_putchar('\n');
	while (mult_fd->list && i < *b4_nl && (mult_fd->list)->data != 0)
	{
		tmp = mult_fd->list;
		*(*line + i) = (mult_fd->list)->data;
		i++;
		mult_fd->list = (mult_fd->list)->next;
		free(tmp);
	}
	ft_putstr("1) List is: "); ft_putlist(mult_fd->list); ft_putchar('\n');
	if (mult_fd->list && (mult_fd->list)->data == '\n' && (mult_fd->list)->data != 0)
	{
		tmp = mult_fd->list;
		mult_fd->list = (mult_fd->list)->next;
		free(tmp);
	}
	ft_putstr("2) List is: "); ft_putlist(mult_fd->list); ft_putchar('\n');
}

static void	mult_fd_list(int fd, t_mult_fd *mult_fd, t_list **newlist)
{
	//ft_putstr("tmp is: "); ft_putlist(tmp->list); ft_putchar('\n');
	*newlist = NULL;
	while (mult_fd)
	{
		ft_putstr("Entering loop \n");
		//ft_putstr("fd is: "); ft_putnbr(fd); ft_putchar('\n');
		//ft_putstr("tmp->fd is: "); ft_putnbr(tmp->fd); ft_putchar('\n');
		if (mult_fd->fd == fd)
		{
			*newlist = mult_fd->list;
			ft_putstr("fd is: "); ft_putnbr(fd); ft_putchar('\n');
			//ft_putstr("tmp is: "); ft_putlist(tmp->list); ft_putchar('\n');
			return ;
		}
		//ft_putstr("tmp is: "); ft_putlist(tmp->list); ft_putchar('\n');
		mult_fd = mult_fd->next;
	}
	ft_putstr("Out of loop\n");
	//*newlist = NULL;
}

int	get_next_line(int fd, char **line)
{
	t_list *newlist;
	static t_mult_fd *mult_fd;
	char *buffer;
	int b4_nl;
	int chars_read;

	mult_fd_list(fd, mult_fd, &newlist);
	//ft_putstr("List is: "); ft_putlist(list); ft_putchar('\n');
	if (!newlist)
	{
		//ft_putstr("Hello\n");
		if ((chars_read = read_list(&newlist, &fd, &buffer)) == 0)
			return (0);
		if (chars_read < 0)
			return (-1);
		//ft_putstr("yes\n");
		ft_struct_push_back(&mult_fd, &newlist, fd);
		ft_putstr("Struct is: "); ft_put_struct(mult_fd); ft_putchar('\n');
	}
	ft_putstr("Entering b4_nl\n");
	b4_nl = list_new_line(&newlist, &fd, &buffer);
	//ft_putstr("b4_nl is: "); ft_putnbr(b4_nl); ft_putchar('\n');
	if (b4_nl == 0 && !newlist)
		return (0);
	//ft_putstr("List is: "); ft_putlist(newlist); ft_putchar('\n');
	if (!(*line = (char *)malloc(sizeof(char) * (b4_nl + 1))))
		return (-1);
	*(*line + b4_nl) = '\0';
	list_to_line(mult_fd, &b4_nl, line);
	if (chars_read > 0)
		return (1);
	return (0);
}