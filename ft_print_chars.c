/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnorris <lnorris@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 05:31:53 by lnorris           #+#    #+#             */
/*   Updated: 2024/11/24 19:00:06 by lnorris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int print_char(char c)
{  
    return (write(1, &c, 1));
}
int print_string(char *s)
{
    int length;

    if (s == NULL)
        return (write(1, "(null)", 6));
    length = ft_strlen(s);
    return (write(1, s, length));
}
