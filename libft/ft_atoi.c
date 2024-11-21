/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnorris <lnorris@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 20:19:38 by lnorris           #+#    #+#             */
/*   Updated: 2024/10/29 20:19:43 by lnorris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_atoi_calc(int sum, unsigned char *nptr);
static int	ft_is_whitespace(unsigned char *c);
static int	ft_str_isnegative(unsigned char *nptr);

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sum;

	i = 0;
	sum = 0;
	if (!*nptr)
		return (0);
	while (ft_is_whitespace(&(((unsigned char *)nptr)[i])))
		i++;
	if ((nptr[i] == '-') || ((nptr[i] == '+') && (ft_isdigit(nptr[i + 1]))))
		i++;
	while (nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		sum = ft_atoi_calc(sum, (unsigned char *)(nptr + i));
		i++;
	}
	if (ft_str_isnegative((unsigned char *)nptr))
		return (-sum);
	return (sum);
}

static int	ft_atoi_calc(int sum, unsigned char *nptr)
{
	sum *= 10;
	sum += *nptr - 48;
	return (sum);
}

static int	ft_is_whitespace(unsigned char *c)
{
	if ((*c >= 9 && *c <= 13) || *c == 32)
		return (1);
	return (0);
}

static int	ft_str_isnegative(unsigned char *nptr)
{
	int	i;

	i = 0;
	while (ft_is_whitespace(&nptr[i]))
		i++;
	if ((nptr[i] == '-') || ((nptr[i] == '+') && (ft_isdigit(nptr[i + 1]))))
	{
		if (nptr[i] == '-')
			return (1);
	}
	return (0);
}
