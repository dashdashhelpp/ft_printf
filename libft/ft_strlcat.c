/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnorris <lnorris@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:13:00 by lnorris           #+#    #+#             */
/*   Updated: 2024/10/29 19:53:48 by lnorris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_len;
	size_t	src_len;

	i = 0;
	dest_len = 0;
	if (!*src)
		return (ft_strlen(dst));
	src_len = ft_strlen(src);
	if (size == 0)
		return (dest_len + src_len);
	dest_len = ft_strlen(dst);
	while (((i + dest_len) < (size - 1)) && (src[i]))
	{
		dst[i + dest_len] = (char)src[i];
		i++;
	}
	if ((dest_len + i) >= size)
		return (size + src_len);
	dst[i + dest_len] = '\0';
	return (dest_len + src_len);
}
