/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:25:33 by tforster          #+#    #+#             */
/*   Updated: 2024/05/01 00:41:29 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	db_max(t_dbnode *dbnode, size_t len)
{
	t_dbnode	*temp;
	int			nb_max;

	temp = dbnode;
	nb_max = dbnode->nbr;
	while (len--)
	{
		if (temp->nbr > nb_max)
			nb_max = temp->nbr;
		temp = temp->next;
	}
	return (nb_max);
}

int	db_min(t_dbnode *dbnode, size_t len)
{
	t_dbnode	*temp;
	int			nb_min;

	temp = dbnode;
	nb_min = dbnode->nbr;
	while (len--)
	{
		if (temp->nbr < nb_min)
			nb_min = temp->nbr;
		temp = temp->next;
	}
	return (nb_min);
}

int	db_mid(t_dbnode *dbnode, size_t half, size_t len)
{
	t_dbnode	*temp;
	size_t		index;
	int			new_min;
	int			nb_max;
	int			nb_min;

	nb_max = db_max(dbnode, len);
	nb_min = db_min(dbnode, len);
	if (half < 2)
		return (nb_min);
	while (--half)
	{
		new_min = nb_min;
		temp = dbnode;
		index = 0;
		while (temp && index++ < len)
		{
			if (temp->nbr > new_min && temp->nbr < nb_max)
				new_min = temp->nbr;
			temp = temp->next;
		}
		nb_max = new_min;
	}
	return (new_min);
}
