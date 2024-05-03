/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:47:37 by tforster          #+#    #+#             */
/*   Updated: 2024/05/03 11:26:08 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void		quick_sort_a(t_stack stk[2], size_t above[6]);
static void	quick_sort_b(t_stack stk[2], size_t above[6]);
static void	divide_small_to_b(t_stack stk[2], int pivot, size_t count[6]);
static void	divide_big_to_a(t_stack stk[2], int pivot, size_t count[6]);

void	init_count(size_t len_a, size_t len_b, size_t count[6])
{
	count[LEN_A] = len_a;
	count[PUSH_A] = 0;
	count[ROT_A] = 0;
	count[LEN_B] = len_b;
	count[PUSH_B] = 0;
	count[ROT_B] = 0;
}

void	quick_sort_a(t_stack stk[2], size_t above[6])
{
	size_t	current_a[6];
	size_t	current_b[6];
	int		pivot;

	init_count(above[LEN_A], above[LEN_B], current_a);
	if (above[LEN_A] > 3)
	{
		pivot = db_mid(stk[A].head, current_a[LEN_A] / 2, current_a[LEN_A]);
		divide_small_to_b(stk, pivot, current_a);
		init_count(0, current_a[PUSH_B], current_b);
		init_count(current_a[LEN_A], 0, current_a);
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

	init_count(above[LEN_A], above[LEN_B], current_a);
	if (above[LEN_B] > 3)
	{
		pivot = db_mid(stk[B].head, above[LEN_B] / 2, above[LEN_B]);
		divide_big_to_a(stk, pivot, current_a);
		// init_count(0, current_a[ROT_B], current_b);
		init_count(0, current_a[LEN_B], current_b);
		init_count(current_a[PUSH_A], 0, current_a);
		quick_sort_a(stk, current_a);
		quick_sort_b(stk, current_b);
	}
	else if (above[LEN_B] == 2)
	{
		push(stk, A, above[LEN_B]);
		conquer_two(stk);
	}
	else if (above[LEN_B] == 3)
	{
		// push(stk, A, above[LEN_B]);
		conquer_three_b(stk);
	}
}

static void	divide_small_to_b(t_stack stk[2], int pivot, size_t count[6])
{
	size_t	len;

	len = count[LEN_A];

	size_t len_a = count[LEN_A];
	size_t	new = 0;
	if (count[LEN_A] % 2 == 0)
		new = count[LEN_A];
	else
		new = count[LEN_A] + 1;

	while (len--)
	{
		if (stk[A].head->nbr < pivot)
		{
			push(stk, B, 1);
			count[PUSH_B]++;
		}
		else
		{
			rotate(stk, A, 1);
			count[ROT_A]++;
		}
		if (new / 2 == count[PUSH_B])
			break;
	}
	count[LEN_A] = stk[A].len;
	count[LEN_B] = 0;

	// if (count[LEN_A] > count[ROT_A])
	if (count[LEN_A] > (len_a - count[PUSH_B]))
	{
		rev_rotate(stk, A, count[ROT_A]);
		// count[LEN_A] = count[ROT_A];
		count[LEN_A] = len_a - count[PUSH_B];
	}
}

static void	divide_big_to_a(t_stack stk[2], int pivot, size_t count[6])
{
	size_t	len;

	len = count[LEN_B];

	size_t len_b = count[LEN_B];
	size_t	new = 0;
	if (count[LEN_B] % 2 == 0)
		new = count[LEN_B];
	else
		new = count[LEN_B] - 1;

	while (len--)
	{
		if (stk[B].head->nbr < pivot)
		{
			rotate(stk, B, 1);
			count[ROT_B]++;
		}
		else
		{
			push(stk, A, 1);
			count[PUSH_A]++;
		}
		if (new / 2 == count[PUSH_A])
			break;

	}

	count[LEN_A] = stk[A].len;
	count[LEN_B] = stk[B].len;
	// printf("lenb = %zu\n", len_b);
	// printf("LEM_A[%zu] PUSH_A[%zu] LEM_B[%zu] ROT_b[%zu]\n",
	// 	count[LEN_A], count[PUSH_A], count[LEN_B], count[ROT_B]);

	// if (count[LEN_B] > count[ROT_B])
	if (count[LEN_B] > (len_b - count[PUSH_A]))
	{
		// printf("IF LEM_A[%zu] PUSH_A[%zu] LEM_B[%zu] ROT_b[%zu]\n",
		// 	count[LEN_A], count[PUSH_A], count[LEN_B], count[ROT_B]);
		rev_rotate(stk, B, count[ROT_B]);
		count[LEN_B] = len_b - count[PUSH_A];
	}
}
