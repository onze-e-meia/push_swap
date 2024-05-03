/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_linked.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:29:40 by tforster          #+#    #+#             */
/*   Updated: 2024/05/01 00:12:10 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dbnode	*dblst_new(int nbr)
{
	t_dbnode	*lst;

	lst = malloc(sizeof(t_dbnode));
	if (!lst)
		return (NULL);
	lst->nbr = nbr;
	lst->prev = NULL;
	lst->next = NULL;
	return (lst);
}

void	stack_add_tail(t_stack *stack, t_dbnode *new)
{
	if (stack->head == NULL && stack->tail == NULL)
	{
		stack->head = new;
		stack->tail = new;
		stack->len = 1;
	}
	else if (stack && stack->head && stack->tail && new)
	{
		stack->tail->next = new;
		new->prev = stack->tail;
		stack->tail = new;
		stack->len++;
	}
}

void	stack_free(t_stack *stack)
{
	t_dbnode	*temp;

	if (!stack)
		return ;
	while (stack->head)
	{
		temp = stack->head;
		stack->head = (stack->head)->next;
		free(temp);
	}
	stack->head = NULL;
	stack->tail = NULL;
	stack->len = 0;
}
