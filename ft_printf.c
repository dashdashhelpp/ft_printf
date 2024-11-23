/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnorris <lnorris@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:59:07 by lnorris           #+#    #+#             */
/*   Updated: 2024/11/23 20:40:52 by lnorris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <unistd.h>

static int	check_format(const char *c, va_list ap);

int	ft_printf(const char *format, ...)
{
	int		printed_characters;
	va_list	ap;

	printed_characters = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			printed_characters += check_format(format, ap);
		}
		else
		{
			write(1, format, 1);
			printed_characters += 1;
		}
		format++;
	}
	va_end(ap);
	return (printed_characters);
}

static int	check_format(const char *c, va_list ap)
{
	int	printed_from_var;

	printed_from_var = 0;
	if (*c == 'c')
		printed_from_var += print_char((unsigned char)va_arg(ap, int));
	else if (*c == 's')
		printed_from_var += 0;
	else if (*c == 'p')
		printed_from_var += 0;
	else if (*c == 'd')
		printed_from_var += 0;
	else if (*c == 'i')
		printed_from_var += 0;
	else if (*c == 'u')
		printed_from_var += 0;
	else if (*c == 'x')
		printed_from_var += print_hex(va_arg(ap, unsigned int), 0);
	else if (*c == 'X')
		printed_from_var += print_hex(va_arg(ap, unsigned int), 1);
	else 
		printed_from_var += write(1, "%", 1);
	return (printed_from_var);
}

int main(void)
{
	unsigned int n = 300;
	int c = 48;
	printf("%d, %i, %c, %x, %X\n\n", c, c, c, n, n);

	ft_printf("\nnon capital: %x\n\nchar: %c\n", n, c);
	return (0);
}
