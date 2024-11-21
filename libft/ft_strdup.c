/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnorris <lnorris@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 21:21:28 by lnorris           #+#    #+#             */
/*   Updated: 2024/11/02 21:21:41 by lnorris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char			*copy;
	unsigned int	str_len;

	str_len = ft_strlen(s) + 1;
	copy = malloc(str_len * sizeof(char));
	if (copy == NULL)
		return (0);
	ft_strlcpy(copy, s, str_len);
	return (copy);
}
