/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnorris <lnorris@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:18:57 by lnorris           #+#    #+#             */
/*   Updated: 2024/11/24 18:45:42 by lnorris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*strrev(char *str);
static void	n_to_string(char *str, unsigned int n);
static int	char_count(unsigned int n);

char	*ft_uitoa(unsigned int n)
{
	char	*str;

	str = malloc(sizeof(char) * (char_count(n) + 1));
	if (str == NULL)
		return (NULL);
	str[char_count(n)] = '\0';
	n_to_string(str, n);
	return (strrev(str));
}

static int	char_count(unsigned int n)
{
	int		i;
	long	num;

	i = 0;
	num = n;
	while (num != 0)
	{
		num /= 10;
		i++;
	}
	return (i + 1);
}

static void	n_to_string(char *str, unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
	{
		str[i] = '0';
		return ;
	}
	while (n > 0)
	{
		str[i] = (n % 10) + 48;
		n = n / 10;
		i++;
	}
	return ;
}

static char	*strrev(char *str)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = ft_strlen(str) - 1;
	c = 0;
	str[j + 1] = '\0';
	while (j > i)
	{
		c = str[i];
		str[i] = str[j];
		str[j] = c;
		i++;
		j--;
	}
	return (str);
}
