/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnorris <lnorris@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:36:51 by lnorris           #+#    #+#             */
/*   Updated: 2024/10/29 19:35:59 by lnorris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	l;

	i = 0;
	l = ft_strlen(src);
	if (size == 0 || (src == NULL) || (dest == NULL))
		return (l);
	while ((i < size - 1) && (src[i]))
	{
		dest[i] = src[i];
		i++;
	}
	if (i != 0)
		dest[i] = '\0';
	else
		*dest = '\0';
	return (l);
}
