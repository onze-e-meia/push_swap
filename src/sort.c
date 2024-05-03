/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:39:42 by tforster          #+#    #+#             */
/*   Updated: 2024/05/03 11:32:44 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	order_check(t_stack stacks[2]);
static void	sort_three(t_stack stk[2]);
static void	sort_four(t_stack stk[2]);
static void	sort_five(t_stack stk[2]);

void	init_sort(t_stack stk[2])
{
	size_t	count[6];

	if (order_check(stk))
		return ;
	if (stk[A].len == 2)
		swap(stk, A);
	else if (stk[A].len == 3)
		sort_three(stk);
	else if (stk[A].len == 4)
		sort_four(stk);
	else if (stk[A].len == 5)
		sort_five(stk);
	else
	{
		init_moves(stk[A].len, stk[B].len, count);
		quick_sort_a(stk, count);
	}
}

int	order_check(t_stack stacks[2])
{
	t_dbnode	*temp;

	if (stacks[1].len > 0)
		return (0);
	temp = stacks[0].head;
	while (temp)
	{
		if (temp->next && temp->nbr > temp->next->nbr)
			return (0);
		temp = temp->next;
	}
	return (1);
}

static void	sort_three(t_stack stk[2])
{
	int	max_nb;

	max_nb = db_max(stk[A].head, stk[A].len);
	if (stk[A].head->nbr == max_nb)
		rotate(stk, A, 1);
	else if (stk[A].head->next->nbr == max_nb)
		rev_rotate(stk, A, 1);
	if (stk->head->nbr > stk->head->next->nbr)
		swap(stk, A);
}

static void	sort_four(t_stack stk[2])
{
	int	min_nb;

	min_nb = db_min(stk[A].head, stk[A].len);
	if (stk[A].head->next->nbr == min_nb)
		swap(stk, A);
	else if (stk[A].head->next->next->nbr == min_nb)
		rotate(stk, A, 2);
	else if (stk[A].tail->nbr == min_nb)
		rev_rotate(stk, A, 1);
	order_check(stk);
	push(stk, B, 1);
	sort_three(stk);
	push(stk, A, 1);
}

static void	sort_five(t_stack stk[2])
{
	int	min_nb;

	min_nb = db_min(stk[A].head, stk[A].len);
	if (stk[A].head->next->nbr == min_nb)
		swap(stk, A);
	else if (stk[A].head->next->next->nbr == min_nb)
		rotate(stk, A, 2);
	else if (stk[A].head->next->next->next->nbr == min_nb)
		rev_rotate(stk, A, 2);
	else if (stk[A].tail->nbr == min_nb)
		rev_rotate(stk, A, 1);
	order_check(stk);
	push(stk, B, 1);
	sort_four(stk);
	push(stk, A, 1);
}
