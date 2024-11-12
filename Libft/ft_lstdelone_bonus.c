/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:52:26 by aahlaqqa          #+#    #+#             */
/*   Updated: 2023/11/24 20:27:28 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	t_list	*temp;

	if (del == NULL || lst == NULL)
		return ;
	(del)(lst->content);
	temp = lst;
	lst = lst->next;
	free(temp);
	temp = NULL;
}

/*static void del_content(void *content)
{
	free(content);
}*/
