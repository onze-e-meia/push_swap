/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tffuente@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:33:37 by tforster          #+#    #+#             */
/*   Updated: 2023/10/13 17:33:39 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_dgtlen(int value)
{
	int		digits;

	digits = 1;
	while (value > 9)
	{
		value = value / 10;
		digits *= 10;
	}
	return (digits);
}

void	ft_putnbr_fd(int nb, int fd)
{
	int	value;
	int	digits;

	if (nb == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (nb < 0)
	{
		nb = -1 * nb;
		ft_putchar_fd('-', fd);
	}
	value = nb;
	digits = ft_dgtlen(value);
	while (digits > 0)
	{
		value = nb / digits + '0';
		ft_putchar_fd(value, fd);
		nb %= digits;
		digits /= 10;
	}
}
