/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnorris <lnorris@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 05:31:53 by lnorris           #+#    #+#             */
/*   Updated: 2024/11/24 02:30:44 by lnorris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int print_char(char c)
{  
    return (write(1, &c, 1));
}
