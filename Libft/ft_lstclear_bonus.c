/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:47:28 by aahlaqqa          #+#    #+#             */
/*   Updated: 2023/11/24 20:43:06 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	if (del == NULL || *lst == NULL)
		return ;
	temp = *lst;
	while (temp != NULL)
	{
		temp = temp->next;
		(*del)((*lst)->content);
		free(*lst);
		*lst = temp;
	}
	*lst = NULL;
}

/*static void del_content(void *content)
{
	free(content);
}*/
