/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 20:27:40 by tforster          #+#    #+#             */
/*   Updated: 2024/05/03 13:10:05 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	max_bottom(t_stack stk[2], int nbr[3]);
static void	max_top(t_stack stk[2], int nbr[3]);
static void	max_middle(t_stack stk[2], int nbr[3]);

void	conquer_two(t_stack stk[2])
{
	if (stk[A].head->nbr > stk[A].head->next->nbr)
	{
		if (stk[B].len > 1 && stk[B].head->nbr < stk[B].head->next->nbr)
			swap(stk, BOTH);
		else
			swap(stk, A);
	}
}

void	conquer_three(t_stack stk[2])
{
	int			nbr[3];

	nbr[0] = stk[A].head->nbr;
	nbr[1] = stk[A].head->next->nbr;
	nbr[2] = stk[A].head->next->next->nbr;
	if (nbr[2] > nbr[0] && nbr[2] > nbr[1])
		max_bottom(stk, nbr);
	else if (nbr[0] > nbr[1] && nbr[0] > nbr[2])
		max_top(stk, nbr);
	else
		max_middle(stk, nbr);
}

static void	max_bottom(t_stack stk[2], int nbr[3])
{
	if (nbr[0] > nbr[1])
		swap(stk, A);
}

static void	max_top(t_stack stk[2], int nbr[3])
{
	swap(stk, A);
	rotate(stk, A, 1);
	swap(stk, A);
	rev_rotate(stk, A, 1);
	if (nbr[1] > nbr[2])
		swap(stk, A);
}

static void	max_middle(t_stack stk[2], int nbr[3])
{
	rotate(stk, A, 1);
	swap(stk, A);
	rev_rotate(stk, A, 1);
	if (nbr[0] > nbr[2])
		swap(stk, A);
}
