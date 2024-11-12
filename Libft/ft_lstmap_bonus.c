/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:27:02 by aahlaqqa          #+#    #+#             */
/*   Updated: 2023/11/24 18:57:04 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*void *f(void *content)
{
    char *new_content = ft_strdup((char *)content);
    if (new_content == NULL)
        return NULL;
    if (ft_isdigit(*new_content)) {
        *new_content += 1;
    }

    return new_content;
}*/
/*static void del_content(void *content)
{
	free(content);
}*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*res;
	void	*temp;

	res = 0;
	if (lst == NULL)
		return (0);
	while (lst != NULL)
	{
		temp = f(lst->content);
		new = ft_lstnew(temp);
		if (new == NULL)
		{
			del(temp);
			ft_lstclear(&res, del);
			return (0);
		}
		ft_lstadd_back(&res, new);
		lst = lst->next;
	}
	return (res);
}
