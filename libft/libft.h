/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjia <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 13:51:41 by jjia              #+#    #+#             */
/*   Updated: 2016/11/20 19:37:35 by jjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>

typedef struct			s_list
{
	char				*data;
	size_t				data_size;
	struct s_list		*next;
}						t_list;

int						ft_isspace(char c);
int						ft_digit_length(long n);
unsigned long			ft_abs(int n);
int						ft_count_words(char const *s, char c);
void					*ft_memset(void *s, int c, size_t n);
void					ft_bzero(void *s, size_t n);
double					ft_power(int n, int pow);
void					*ft_memcpy(void *dst, const void *src, size_t n);
void					*ft_memccpy(void *dest, const void *src,
						int c, size_t n);
void					*ft_memmove(void *dst, const void *src, size_t len);
void					*ft_memchr(const void *s, int c, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
size_t					ft_strlen(char const *str);
char					*ft_strdup(char *s);
char					*ft_strcpy(char *s1, char const *s2);
char					*ft_strncpy(char *dest, char const *src, size_t n);
char					*ft_strcat(char *dest, char const *src);
char					*ft_strncat(char *dest, char *src, int nb);
size_t					ft_strlcat(char *dst, char const *src, size_t size);
char					*ft_strchr(const char *s, int c);
char					*ft_strrchr(const char *s, int c);
char					*ft_strstr(char const *str, char const *to_find);
char					*ft_strnstr(const char *big, const char *little,
						size_t len);
int						ft_strcmp(const char *s1, const char *s2);
int						ft_strncmp(char const *s1, char const *s2, size_t n);
int						ft_atoi(const char *str);
int						ft_isalpha(int c);
int						ft_isdigit(int c);
int						ft_isalnum(int c);
int						ft_isascii(int c);
int						ft_isprint(int c);
int						ft_toupper(int c);
int						ft_tolower(int c);
void					*ft_memalloc(size_t size);
void					ft_memdel(void **ap);
char					*ft_strnew(size_t size);
void					ft_strdel(char **as);
void					ft_strclr(char *s);
void					ft_striter(char *s, void (*f)(char *));
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
char					*ft_strmap(char const *s, char (*f)(char));
char					*ft_strmapi(char const *s, char (*f)
						(unsigned int, char));
int						ft_strequ(char const *s1, char const *s2);
int						ft_strnequ(char const *s1, char const *s2, size_t n);
char					*ft_strsub(char const *s, unsigned int start,
						size_t len);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strtrim(char const *s);
char					**ft_strsplit(char const *s, char c);
char					*ft_itoa(int n);
void					ft_putchar(char c);
void					ft_putstr(char const *s);
void					ft_putendl(char const *s);
void					ft_putnbr(int n);
void					ft_putchar_fd(unsigned const char c, int fd);
void					ft_putstr_fd(char const *s, int fd);
void					ft_putendl_fd(char const *s, int fd);
void					ft_putnbr_fd(int n, int fd);
t_list					*ft_lstnew(void const *content, size_t content_size);
void					ft_lstdelone(t_list **alst, void (*del)
						(void *, size_t));
void					ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void					ft_lstadd(t_list **alst, t_list *new);
void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void					ft_list_push_back(t_list **begin_list, char *data);
void					ft_list_push_front(t_list **begin_list, void *data);
int						ft_list_size(t_list *begin_list);
t_list					*ft_create_elem(char *data);
char					*ft_strndup(char *s, size_t n);
void					ft_putlist(t_list *list);
int						ft_list_size(t_list *list);
void					*ft_realloc(void **ptr, size_t old, size_t new_size);

#endif
