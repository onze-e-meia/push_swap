/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tffuente@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 20:19:20 by tforster          #+#    #+#             */
/*   Updated: 2023/10/09 20:19:22 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t bytes)
{
	size_t	len_dest;
	size_t	len_src;

	len_dest = 0;
	if (dest)
		len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	if (len_dest >= bytes)
		return (len_src + bytes);
	return (len_dest + ft_strlcpy(dest + len_dest, src, bytes - len_dest));
}
