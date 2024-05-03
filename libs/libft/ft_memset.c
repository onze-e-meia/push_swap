/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 20:35:05 by tforster          #+#    #+#             */
/*   Updated: 2024/02/24 14:55:24 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int ch, size_t bytes)
{
	unsigned char	*uchar_str;

	uchar_str = (unsigned char *) str;
	while (bytes--)
		*uchar_str++ = ch;
	return (str);
}
