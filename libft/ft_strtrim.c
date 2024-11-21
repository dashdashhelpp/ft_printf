/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnorris <lnorris@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:52:52 by lnorris           #+#    #+#             */
/*   Updated: 2024/11/04 16:52:55 by lnorris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	l_strip;
	unsigned int	r_strip;
	char			*trimmed_string;

	if (!set || !s1)
		return (NULL);
	l_strip = 0;
	r_strip = ft_strlen(s1) - 1;
	if (*s1 == '\0')
		return (ft_strdup(""));
	while (ft_strchr(set, s1[l_strip]) && l_strip <= r_strip)
		l_strip++;
	if (l_strip > r_strip)
		return (ft_strdup(s1 + r_strip + 1));
	while (ft_strchr(set, s1[r_strip]))
		r_strip--;
	trimmed_string = ft_calloc(r_strip - l_strip + 2, sizeof(char));
	if (trimmed_string == NULL)
		return (NULL);
	ft_strlcpy(trimmed_string, &s1[l_strip], r_strip - l_strip + 2);
	return (trimmed_string);
}
