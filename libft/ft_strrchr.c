/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnorris <lnorris@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:14:44 by lnorris           #+#    #+#             */
/*   Updated: 2024/10/30 18:17:27 by lnorris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	char			*temp;
	unsigned char	a;

	i = 0;
	a = (unsigned char)(c);
	temp = (char *)s;
	while (s[i])
	{
		if (s[i] == a)
			temp = &((char *)s)[i];
		i++;
	}
	if (s[i] == a)
		return (&((char *)s)[i]);
	else if (*temp == a)
		return (temp);
	return (NULL);
}
