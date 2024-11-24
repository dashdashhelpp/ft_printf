/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnorris <lnorris@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:29:28 by lnorris           #+#    #+#             */
/*   Updated: 2024/11/24 18:07:58 by lnorris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

static int  hexlen(unsigned long long n, int *is_pointer);

int print_hex(unsigned long long n, int is_capital, int is_pointer)
{
    int i;

    i = hexlen(n, &is_pointer);
    if (n == 0)
        return (write(1, "0", 1));
    if (n >= 16)
    {
        print_hex(n / 16, is_capital, is_pointer);
        print_hex(n % 16, is_capital, is_pointer);
    }
    else 
    {
        if (n <= 9)
        {
            ft_putchar_fd((n + 48), 1);
        }
        else
        {
            if (is_capital)
                ft_putchar_fd((n + 55), 1);
            else
                ft_putchar_fd((n + 87), 1);
        }
    }
    return (i);
}
static int  hexlen(unsigned long long n, int *is_pointer)
{
    int length;

    length = 0;
    if (*is_pointer)
    {
        length += write(1, "0x", 2);
        *is_pointer = 0;
    }
    if (n == 0)
        return (1);
    while (n != 0)
    {
        n /= 16;
        length++;
    }
    return (length);
}
