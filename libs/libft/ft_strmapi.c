/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:32:16 by tforster          #+#    #+#             */
/*   Updated: 2024/02/05 18:22:26 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *str, char (*f) (unsigned int, char))
{
	unsigned int	len_str;
	unsigned int	index;
	char			*mpd_str;

	if (!str || !f)
		return (NULL);
	len_str = ft_strlen(str);
	mpd_str = (char *) malloc((len_str + 1) * sizeof(char));
	if (!mpd_str)
		return (NULL);
	index = 0;
	while (*str)
	{
		*(mpd_str + index) = f(index, *str++);
		index++;
	}
	*(mpd_str + index) = '\0';
	return (mpd_str);
}
