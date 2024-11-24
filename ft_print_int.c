/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnorris <lnorris@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 02:31:37 by lnorris           #+#    #+#             */
/*   Updated: 2024/11/24 03:04:31 by lnorris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int print_int(int n)
{
    char    *s;
    int     i;

    s = ft_itoa(n);
    i = ft_strlen(s);
    write(1, s, i);
    free(s);
    return (i);
}
