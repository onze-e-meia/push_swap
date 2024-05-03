/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tffuente@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:31:05 by tforster          #+#    #+#             */
/*   Updated: 2023/10/20 18:31:07 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*map_lst;
	t_list	*temp;
	void	*f_temp;

	map_lst = NULL;
	while (lst)
	{
		f_temp = f(lst->content);
		temp = ft_lstnew(f_temp);
		if (!temp)
		{
			free(f_temp);
			ft_lstclear(&map_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&map_lst, temp);
		lst = lst->next;
	}
	return (map_lst);
}
