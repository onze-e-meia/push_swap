/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:55:29 by tforster          #+#    #+#             */
/*   Updated: 2024/05/03 15:57:31 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int		ft_atoi(const char *str);
long	ft_atol(const char *str);
void	ft_bzero(void *str, size_t bytes);
void	*ft_calloc(size_t nb_elm, size_t bytes);
int		ft_is_tab(int ch);
int		ft_isalnum(int ch);
int		ft_isalpha(int ch);
int		ft_isascii(int ch);
int		ft_isdigit(int ch);
int		ft_isprint(int ch);
char	*ft_itoa(int nb);
void	*ft_memchr(const void *str, int ch, size_t bytes);
int		ft_memcmp(const void *str1, const void *str2, size_t bytes);
void	*ft_memcpy(void *dest, const void *src, size_t bytes);
void	*ft_memmove(void *dest, const void *src, size_t bytes);
void	*ft_memset(void *str, int ch, size_t bytes);
void	ft_putchar_fd(char ch, int fd);
void	ft_putendl_fd(char *str, int fd);
void	ft_putnbr_fd(int nb, int fd);
void	ft_putstr_fd(char *str, int fd);
char	**ft_split(const char *str, char ch);
char	*ft_strchr(const char *str, int ch);
char	*ft_strdup(const char *src);
void	ft_striteri(char *str, void (*f) (unsigned int, char*));
char	*ft_strjoin(const char *str1, const char *str2);
size_t	ft_strlcat(char *dest, const char *src, size_t bytes);
size_t	ft_strlcpy(char *dest, const char *src, size_t bytes);
size_t	ft_strlen(const char *s);
char	*ft_strmapi(const char *str, char (*f) (unsigned int, char));
int		ft_strncmp(const char *str1, const char *str2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *str, int ch);
char	*ft_strtrim(const char *str, const char *set);
char	*ft_substr(char const *src, unsigned int start, size_t len);
int		ft_tolower(int ch);
int		ft_toupper(int ch);

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
