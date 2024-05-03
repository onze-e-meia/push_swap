/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tffuente@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 20:47:07 by tforster          #+#    #+#             */
/*   Updated: 2023/10/09 20:47:09 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nb_elm, size_t bytes)
{
	void	*dest;
	size_t	rslt;

	dest = NULL;
	rslt = nb_elm * bytes;
	if (!nb_elm || !bytes || nb_elm == rslt / bytes)
		dest = malloc (rslt);
	if (dest)
		ft_bzero (dest, nb_elm * bytes);
	return (dest);
}
