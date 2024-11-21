/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnorris <lnorris@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 19:12:58 by lnorris           #+#    #+#             */
/*   Updated: 2024/10/30 19:13:01 by lnorris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	subs(char *big, char *little)
{
	int	i;

	i = 0;
	while (little[i] && big[i])
	{
		if (little[i] != big[i])
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	rem_len;

	i = 0;
	rem_len = 0;
	if ((big == NULL || little == NULL) && len == 0)
		return (NULL);
	if (big == little)
		return ((char *)(big + i));
	if (ft_strlen(little) == 0)
		return ((char *)big);
	rem_len = ft_strlen(little);
	while (big[i] && (i < len) && ((len - i) >= rem_len))
	{
		if (big[i] == little[0])
		{
			if (subs((char *)(big + i), (char *)little) == 1)
				return ((char *)(big + i));
		}
		i++;
	}
	return (NULL);
}
