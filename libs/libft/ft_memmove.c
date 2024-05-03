/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tffuente@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 20:38:29 by tforster          #+#    #+#             */
/*   Updated: 2023/10/09 20:38:31 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t bytes)
{
	if ((!dest && !src) || !bytes)
		return (dest);
	if (dest > src)
		while (bytes--)
			*(unsigned char *)(dest + bytes) = *(unsigned char *)(src + bytes);
	else
		ft_memcpy(dest, src, bytes);
	return (dest);
}
