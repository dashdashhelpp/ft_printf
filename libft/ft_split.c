/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnorris <lnorris@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:34:14 by lnorris           #+#    #+#             */
/*   Updated: 2024/11/04 17:34:16 by lnorris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *str, char c);
static char	*ft_strdup_c(const char *s, char c);
static void	*ft_free_all(char **array);
static char	**ft_bananasplit(char const *s, char c, char **array);

char	**ft_split(char const *s, char c)
{
	char	**array;

	if (!s)
		return (NULL);
	array = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!array)
		return (NULL);
	return (ft_bananasplit(s, c, array));
}

static char	**ft_bananasplit(char const *s, char c, char **array)
{
	int	i;
	int	j;
	int	latch;

	i = 0;
	j = 0;
	latch = 0;
	while (s[i])
	{
		if ((s[i] != c) && latch++ == 0)
		{
			array[j] = ft_strdup_c(&s[i], c);
			if (array[j] == NULL)
				return (ft_free_all(array));
			j++;
		}
		else if (s[i] == c)
			latch = 0;
		i++;
	}
	array[ft_count_words(s, c)] = NULL;
	return (array);
}

static void	*ft_free_all(char **array)
{
	int	i;

	i = 0;
	while (*array)
	{
		free(*array++);
		i++;
	}
	free(array - i);
	return (NULL);
}

static int	ft_count_words(const char *str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*str)
	{
		if (*str != c && j == 0)
		{
			j = 1;
			i++;
		}
		else if (*str == c)
			j = 0;
		str++;
	}
	return (i);
}

static char	*ft_strdup_c(const char *s, char c)
{
	char			*copy;
	unsigned int	str_len;
	int				i;

	i = 0;
	str_len = 0;
	while (s[i] == c)
		i++;
	while (s[i + str_len] != c && s[i + str_len])
		str_len++;
	copy = malloc(sizeof(char) * str_len + 1);
	if (copy == NULL)
		return (NULL);
	ft_strlcpy(copy, &s[i], str_len + 1);
	return (copy);
}
