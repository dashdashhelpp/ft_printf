/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnorris <lnorris@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 02:31:37 by lnorris           #+#    #+#             */
/*   Updated: 2024/11/24 18:46:32 by lnorris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

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
int print_uint(unsigned int n)
{
    char    *s;
    int     length;

    s = ft_uitoa(n);
    length = ft_strlen(s);
    write(1, s, length);
    free(s);
    return (length);
    
}
