/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tffuente@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 20:38:15 by tforster          #+#    #+#             */
/*   Updated: 2023/10/11 13:41:14 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t bytes)
{
	unsigned char	*str_dest;

	if ((!dest && !src) || !bytes)
		return (dest);
	str_dest = (unsigned char *) dest;
	while (bytes--)
		*str_dest++ = *(unsigned char *) src++;
	return (dest);
}
