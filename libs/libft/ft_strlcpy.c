/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tffuente@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 20:19:08 by tforster          #+#    #+#             */
/*   Updated: 2023/10/09 20:19:10 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t bytes)
{
	size_t	len_src;
	size_t	index;

	len_src = ft_strlen(src);
	index = 0;
	if (bytes == 0)
		return (len_src);
	while (*src && (index++ < bytes - 1))
		*dest++ = *src++;
	*dest = '\0';
	return (len_src);
}
