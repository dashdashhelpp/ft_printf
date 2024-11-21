/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnorris <lnorris@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:00:41 by lnorris           #+#    #+#             */
/*   Updated: 2024/11/04 18:00:43 by lnorris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*strrev(char *str);
static int	n_to_string(char *str, int n);
static int	char_count(int n);

char	*ft_itoa(int n)
{
	char	*str;
	int		is_neg;
	int		i;

	is_neg = 0;
	i = 0;
	str = malloc(sizeof(char) * (char_count(n) + 1));
	if (str == NULL)
		return (NULL);
	str[char_count(n)] = '\0';
	if (n == -2147483648)
	{
		ft_strlcpy(str, "-2147483648", 100);
		return (str);
	}
	if (n < 0)
	{
		is_neg = 8008;
		n = -n;
	}
	i = n_to_string(str, n);
	if (is_neg != 0)
		str[i] = '-';
	return (strrev(str));
}

static int	char_count(int n)
{
	int		i;
	long	num;

	i = 0;
	num = n;
	if (num < 0)
	{
		num = -num;
		i++;
	}
	if (num <= 9 && num >= 0)
		return (i + 1);
	while (num > 9)
	{
		num /= 10;
		i++;
	}
	return (i + 1);
}

static int	n_to_string(char *str, int n)
{
	int	i;

	i = 0;
	if (n == 0)
	{
		str[i] = '0';
		return (1);
	}
	while (n > 0)
	{
		str[i] = (n % 10) + 48;
		n = n / 10;
		i++;
	}
	return (i);
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
