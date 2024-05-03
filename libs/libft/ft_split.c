/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tffuente@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:31:33 by tforster          #+#    #+#             */
/*   Updated: 2023/10/13 17:31:35 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_chr(const char *str, char ch)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		if ((*str != ch && *(str + 1) == ch) || (*str != ch && !*(str + 1)))
			count++;
		str++;
	}
	return (count);
}

static void	ft_clear(char **split, int *flag)
{
	*flag = -1;
	while (*split)
	{
		free(*split);
		*split = NULL;
		split++;
	}
}

static void	ft_alloc_str(char **split, const char *str, char ch, int *flag)
{
	size_t	size_word;
	char	*sinlge_str;
	char	**ptr_split;

	size_word = 0;
	ptr_split = split;
	while (*str)
	{
		if (*str && *str != ch)
		{
			if (size_word++ == 0)
				sinlge_str = (char *) str;
		}
		if (size_word > 0 && ((*(str + 1) == ch) || (*(str + 1) == '\0')))
		{
			*ptr_split = ft_substr(sinlge_str, 0, size_word);
			size_word = 0;
			if (!*ptr_split++)
				return (ft_clear(split, flag));
		}
		str++;
	}
	*ptr_split = NULL;
}

char	**ft_split(const char *str, char ch)
{
	size_t	count;
	char	**split;
	int		flag;

	if (!str)
		return (NULL);
	flag = 0;
	count = ft_count_chr(str, ch);
	split = malloc((count + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	ft_alloc_str(split, str, ch, &flag);
	if (flag == -1)
	{
		free(split);
		split = NULL;
	}
	return (split);
}
