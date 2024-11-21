/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnorris <lnorris@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:44:04 by lnorris           #+#    #+#             */
/*   Updated: 2024/11/18 19:44:07 by lnorris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*temp_list;

	if (!lst || !f || !del)
		return (NULL);
	temp_list = NULL;
	while (lst != NULL)
	{
		temp = ft_lstnew((*f)(lst->content));
		if (!temp)
		{
			while (temp_list)
			{
				temp = temp_list->next;
				(*del)(temp_list->content);
				free(temp_list);
				temp_list = temp;
			}
			lst = NULL;
			return (NULL);
		}
		ft_lstadd_back(&temp_list, temp);
		lst = lst->next;
	}
	return (temp_list);
}
