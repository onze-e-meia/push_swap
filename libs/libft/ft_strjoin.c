/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tffuente@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:30:58 by tforster          #+#    #+#             */
/*   Updated: 2023/10/13 17:30:59 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *str1, const char *str2)
{
	size_t	len_str1;
	size_t	len_str2;
	char	*cat_str;

	if (!str1 || !str2)
		return (NULL);
	len_str1 = ft_strlen(str1) + 1;
	len_str2 = len_str1 + ft_strlen(str2);
	cat_str = (char *) malloc(len_str2 * sizeof(char));
	if (!cat_str)
		return (NULL);
	ft_strlcpy(cat_str, str1, len_str1);
	ft_strlcat(cat_str, str2, len_str2);
	return (cat_str);
}
