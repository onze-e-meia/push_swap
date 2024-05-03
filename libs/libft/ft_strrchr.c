/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tffuente@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 20:19:45 by tforster          #+#    #+#             */
/*   Updated: 2023/10/09 20:19:47 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strrchr(const char *str, int ch)
{
	int		len_str;
	int		count;

	len_str = ft_strlen(str);
	if (len_str <= 0 && ch)
		return (NULL);
	else
		str = (char *)(str + len_str);
	count = 0;
	while (*(str - count) != (unsigned char) ch)
		if (count++ >= len_str)
			return (NULL);
	return ((char *) str - count);
}
