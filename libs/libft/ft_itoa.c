/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tffuente@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:31:48 by tforster          #+#    #+#             */
/*   Updated: 2023/10/13 17:31:50 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_dgtlen(int nb)
{
	int	digits;

	digits = 0;
	if (nb < 0)
		digits++;
	while (nb)
	{
		nb /= 10;
		digits++;
	}
	return (digits);
}

static void	ft_nbchr(int nb, int digits, char *str)
{
	*(str + digits) = '\0';
	while (nb)
	{
		*(str + --digits) = nb % 10 + '0';
		nb /= 10;
	}
}

char	*ft_itoa(int nb)
{
	int		digits;
	char	*str;

	if (nb == 0)
		return (ft_strdup("0"));
	if (nb == -2147483648)
		return (ft_strdup("-2147483648"));
	digits = ft_dgtlen(nb);
	str = (char *)malloc((digits + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (nb < 0)
	{
		*str = '-';
		nb *= -1;
	}
	ft_nbchr(nb, digits, str);
	return (str);
}
