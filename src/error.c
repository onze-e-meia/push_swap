/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:44:32 by tforster          #+#    #+#             */
/*   Updated: 2024/05/01 00:09:41 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(t_stack stk[2])
{
	clear_stacks(stk);
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	clear_stacks(t_stack stk[2])
{
	if (stk[A].len > 0)
		stack_free(&stk[A]);
	if (stk[B].len > 0)
		stack_free(&stk[B]);
}
