/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tffuente@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 20:38:56 by tforster          #+#    #+#             */
/*   Updated: 2023/10/09 20:38:57 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t bytes)
{
	unsigned char	*uchar_str1;
	unsigned char	*uchar_str2;

	uchar_str1 = (unsigned char *) str1;
	uchar_str2 = (unsigned char *) str2;
	while (bytes--)
	{
		if (*uchar_str1 != *uchar_str2)
			return (*uchar_str1 - *uchar_str2);
		uchar_str1++;
		uchar_str2++;
	}
	return (0);
}
