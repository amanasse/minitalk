/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:50:05 by amanasse          #+#    #+#             */
/*   Updated: 2022/05/13 16:57:23 by amanasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))

{
	t_list	*tmp;

	if (!del)
		return ;
	while (*lst)
	{
		tmp = *lst;
		del((*lst)->content);
		*lst = tmp->next;
		free(tmp);
	}
	*lst = NULL;
}
