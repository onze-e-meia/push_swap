/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tffuente@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 20:20:22 by tforster          #+#    #+#             */
/*   Updated: 2023/10/09 20:20:23 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	len_needle;

	if (!*needle)
		return ((char *) haystack);
	if (!haystack && !len)
		return (NULL);
	len_needle = ft_strlen(needle);
	while (*haystack && len_needle <= len--)
	{
		if (!ft_memcmp(haystack, needle, len_needle))
			return ((char *) haystack);
		haystack++;
	}
	return (NULL);
}
