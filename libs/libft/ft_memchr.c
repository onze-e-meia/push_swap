/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tffuente@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 20:38:48 by tforster          #+#    #+#             */
/*   Updated: 2023/10/09 20:38:49 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int ch, size_t bytes)
{
	unsigned char	*uchar_str;

	uchar_str = (unsigned char *) str;
	while (bytes--)
	{
		if (*uchar_str == (unsigned char) ch)
			return (uchar_str);
		uchar_str++;
	}
	return (NULL);
}
