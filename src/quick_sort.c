/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:47:37 by tforster          #+#    #+#             */
/*   Updated: 2024/05/03 15:43:52 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		quick_sort_a(t_stack stk[2], size_t above[6]);
static void	quick_sort_b(t_stack stk[2], size_t above[6]);
static void	divide_small_to_b(t_stack stk[2], int pivot, size_t moves[6]);
static void	divide_big_to_a(t_stack stk[2], int pivot, size_t moves[6]);

void	init_moves(size_t len_a, size_t len_b, size_t moves[6])
{
	moves[LEN_A] = len_a;
	moves[PUSH_A] = 0;
	moves[ROT_A] = 0;
	moves[LEN_B] = len_b;
	moves[PUSH_B] = 0;
	moves[ROT_B] = 0;
}

void	quick_sort_a(t_stack stk[2], size_t above[6])
{
	size_t	current_a[6];
	size_t	current_b[6];
	int		pivot;

	init_moves(above[LEN_A], above[LEN_B], current_a);
	if (above[LEN_A] > 3)
	{
		pivot = db_mid(stk[A].head, current_a[LEN_A] / 2, current_a[LEN_A]);
		divide_small_to_b(stk, pivot, current_a);
		init_moves(0, current_a[PUSH_B], current_b);
		init_moves(current_a[LEN_A], 0, current_a);
		quick_sort_a(stk, current_a);
		quick_sort_b(stk, current_b);
	}
	else if (above[LEN_A] == 2)
		conquer_two(stk);
	else if (above[LEN_A] == 3)
		conquer_three(stk);
}

static void	quick_sort_b(t_stack stk[2], size_t above[6])
{
	size_t	current_a[6];
	size_t	current_b[6];
	int		pivot;

	init_moves(above[LEN_A], above[LEN_B], current_a);
	if (above[LEN_B] > 3)
	{
		pivot = db_mid(stk[B].head, above[LEN_B] / 2, above[LEN_B]);
		divide_big_to_a(stk, pivot, current_a);
		init_moves(0, current_a[LEN_B], current_b);
		init_moves(current_a[PUSH_A], 0, current_a);
		quick_sort_a(stk, current_a);
		quick_sort_b(stk, current_b);
	}
	else if (above[LEN_B] == 2)
	{
		push(stk, A, above[LEN_B]);
		conquer_two(stk);
	}
	else if (above[LEN_B] == 3)
		conquer_three_b(stk);
}

static void	divide_small_to_b(t_stack stk[2], int pivot, size_t moves[6])
{
	size_t	len;
	size_t	count;

	len = moves[LEN_A];
	len = (len % 2 == 0) * (len / 2) + (len % 2 != 0) * ((len + 1) / 2);
	count = moves[LEN_A];
	while (count-- && len != moves[PUSH_B])
	{
		if (stk[A].head->nbr < pivot)
		{
			push(stk, B, 1);
			moves[PUSH_B]++;
		}
		else
		{
			rotate(stk, A, 1);
			moves[ROT_A]++;
		}
	}
	len = moves[LEN_A];
	moves[LEN_A] = len - moves[PUSH_B];
	if (stk[A].len > (len - moves[PUSH_B]))
		rev_rotate(stk, A, moves[ROT_A]);
}

static void	divide_big_to_a(t_stack stk[2], int pivot, size_t moves[6])
{
	size_t	len;
	size_t	count;

	len = moves[LEN_B];
	len = (len % 2 == 0) * (len / 2) + (len % 2 != 0) * ((len - 1) / 2);
	count = moves[LEN_B];
	while (count-- && len != moves[PUSH_A])
	{
		if (stk[B].head->nbr < pivot)
		{
			rotate(stk, B, 1);
			moves[ROT_B]++;
		}
		else
		{
			push(stk, A, 1);
			moves[PUSH_A]++;
		}
	}
	len = moves[LEN_B];
	moves[LEN_B] = len - moves[PUSH_A];
	if (stk[B].len > (len - moves[PUSH_A]))
		rev_rotate(stk, B, moves[ROT_B]);
}
