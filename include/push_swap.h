/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 15:42:21 by tforster          #+#    #+#             */
/*   Updated: 2024/05/03 15:46:15 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

# define INT_MIN -2147483648
# define INT_MAX +2147483647

typedef struct s_dbnode	t_dbnode;
struct s_dbnode
{
	int			nbr;
	t_dbnode	*next;
	t_dbnode	*prev;
};

typedef struct s_stack	t_stack;
struct s_stack
{
	t_dbnode	*head;
	t_dbnode	*tail;
	size_t		len;
};

typedef enum e_flag		t_flag;
enum e_flag
{
	A,
	B,
	BOTH,
};

enum e_count
{
	LEN_A,
	PUSH_A,
	ROT_A,
	LEN_B,
	PUSH_B,
	ROT_B,
};

enum e_median
{
	LOW,
	MID,
	HI,
};

/* Error Functions */
void		error_exit(t_stack stacks[2]);
void		clear_stacks(t_stack stacks[2]);

/* Doubly Linked */
t_dbnode	*dblst_new(int nbr);
void		stack_add_tail(t_stack *stack, t_dbnode *new);
void		stack_free(t_stack *stack);
/* Utils */
int			db_max(t_dbnode *node, size_t len);
int			db_min(t_dbnode *node, size_t len);
int			db_mid(t_dbnode *dbnode, size_t half, size_t len);

/* Sort Functions */
void		init_sort(t_stack stacks[2]);
void		init_moves(size_t len_a, size_t len_b, size_t count[5]);
void		quick_sort_a(t_stack stk[2], size_t count[5]);
/* Utils */
void		conquer_two(t_stack stk[2]);
void		conquer_three(t_stack stk[2]);
void		conquer_three_b(t_stack stk[2]);

/* Move Functions */
void		swap(t_stack stacks[2], int flag);
void		rotate(t_stack stacks[2], int flag, int times);
void		rev_rotate(t_stack stacks[2], int flag, int times);
void		push(t_stack stk[2], int flags, int times);

#endif
