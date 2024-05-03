/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tffuente@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:28:10 by tforster          #+#    #+#             */
/*   Updated: 2023/10/13 17:28:13 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *src, unsigned int start, size_t len)
{
	char	*dest;
	size_t	len_src;

	if (!src)
		return (NULL);
	len_src = ft_strlen(src);
	if (len_src <= start)
	{
		start = len_src;
		len = 1;
	}
	else if (len > len_src - start)
		len = len_src - start + 1;
	else
		len++;
	dest = malloc(len * sizeof(char));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, src + start, len);
	return (dest);
}
