/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tffuente@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:31:16 by tforster          #+#    #+#             */
/*   Updated: 2023/10/13 17:31:18 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_isinset(char ch, const char *set)
{
	while (*set)
	{
		if (*set++ == ch)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(const char *str, const char *set)
{
	char	*start;
	char	*end;
	char	*trim_str;

	if (!str || !set)
		return (NULL);
	start = (char *) str;
	end = start + ft_strlen(str);
	while (*start && ft_isinset(*start, set))
		start++;
	while (end > start && ft_isinset(*(end - 1), set))
		end--;
	trim_str = ft_substr(start, 0, end - start);
	return (trim_str);
}
