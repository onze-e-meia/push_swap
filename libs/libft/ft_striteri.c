/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:32:29 by tforster          #+#    #+#             */
/*   Updated: 2024/02/05 18:18:43 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *str, void (*f) (unsigned int, char*))
{
	unsigned int	index;

	if (!str || !f)
		return ;
	index = 0;
	while (*str)
		f(index++, str++);
}
