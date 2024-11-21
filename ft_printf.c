/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnorris <lnorris@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:59:07 by lnorris           #+#    #+#             */
/*   Updated: 2024/11/21 18:13:13 by lnorris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

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
			printed_characters += func_call();
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

int	check_format(unsigned char *c, va_list *ap)
{
	int	printed_from_var;

	printed_from_var = 0;
	if (*c == 'c')
		printed_from_var += 0;
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
		printed_from_var += 0;
	else if (*c == 'X')
		printed_from_var += 0;
	else 
		printed_from_var += write(1, "%", 1);
	return (printed_from_var);
}
