/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tffuente@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 20:20:08 by tforster          #+#    #+#             */
/*   Updated: 2023/10/09 20:20:10 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t bytes)
{
	unsigned char	*uchar_str1;
	unsigned char	*uchar_str2;

	uchar_str1 = (unsigned char *) str1;
	uchar_str2 = (unsigned char *) str2;
	while ((*uchar_str1 || *uchar_str2) && bytes--)
	{
		if (*uchar_str1 != *uchar_str2)
			return (*uchar_str1 - *uchar_str2);
		uchar_str1++;
		uchar_str2++;
	}
	return (0);
}
