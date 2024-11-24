/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnorris <lnorris@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:59:07 by lnorris           #+#    #+#             */
/*   Updated: 2024/11/24 18:57:53 by lnorris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <unistd.h>
#include <stdarg.h>
#include <limits.h>

static int	check_format(const char *c, va_list *list);

int	ft_printf(const char *format, ...)
{
	int		printed_characters;
	va_list	list;

	printed_characters = 0;
	va_start(list, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			printed_characters += check_format(format, &list);
		}
		else
			printed_characters += write(1, format, 1);
		format++;
	}
	va_end(list);
	return (printed_characters);
}

static int	check_format(const char *c, va_list *list)
{
	int	printed_from_var;

	printed_from_var = 0;
	if (*c == 'c')
		printed_from_var += print_char((char)va_arg(*list, int));
	else if (*c == 's')
		printed_from_var += print_string(va_arg(*list, char *));
	else if (*c == 'p')
		printed_from_var += print_hex(va_arg(*list, unsigned long long), 0, 1);
	else if (*c == 'd' || *c == 'i')
		printed_from_var += print_int(va_arg(*list, int));
	else if (*c == 'u')
		printed_from_var += print_uint(va_arg(*list, unsigned int));
	else if (*c == 'x')
		printed_from_var += print_hex((unsigned long long)va_arg(*list, unsigned int), 0, 0);
	else if (*c == 'X')
		printed_from_var += print_hex((unsigned long long)va_arg(*list, unsigned int), 1, 0);
	else 
		printed_from_var += write(1, "%", 1);
	return (printed_from_var);
}

int main(void)
{
	unsigned int a = UINT_MAX;
	unsigned int b = UINT_MAX + 1;
	int	c = 48;
	int d = 97;
	int e = INT_MAX;
	int f = INT_MIN;
	void	*ptr = &f;
	char	*s = NULL;
	char	*str = "Testing testing";
	char	*string = "";

	printf("printed chars from printf: %i\n\n", printf("int: %d, int: %i, hex: %x, hex: %X, char: %c, char %c, pointer: %p, uint: %u, uint: %u, string null: %s, string text: %s, string empty: %s, %%\n", e, f, a, b, c, d, ptr, a, b, s, str, string));
	printf("printed chars from ft_printf: %i\n\n", ft_printf("int: %d, int: %i, hex: %x, hex: %X, char: %c, char %c, pointer: %p, uint: %u, uint: %u, string null: %s, string text: %s, string empty: %s, %%\n", e, f, a, b, c, d, ptr, a, b, s, str, string));
	
	return (0);
}
