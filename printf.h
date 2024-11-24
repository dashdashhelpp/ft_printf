/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnorris <lnorris@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:56:16 by lnorris           #+#    #+#             */
/*   Updated: 2024/11/24 19:27:09 by lnorris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdio.h>

typedef unsigned long long	t_ull;
int		print_hex(unsigned long long n, int is_capital, int is_pointer);
int		print_char(char c);
int		print_int(int n);
int		print_uint(unsigned int n);
char	*ft_uitoa(unsigned int n);
int		print_string(char *s);

#endif
