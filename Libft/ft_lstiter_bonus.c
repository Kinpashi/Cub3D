/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlaqqa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:52:45 by aahlaqqa          #+#    #+#             */
/*   Updated: 2023/11/16 17:21:02 by aahlaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

/*void f(void *content)
{
	*(int *)content += 1;
}*/

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*temp;

	if (lst == NULL || f == NULL)
		return ;
	temp = lst;
	while (temp != NULL)
	{
		f(temp->content);
		temp = temp->next;
	}
}

/*void write_content(t_list *lst)
{
	while (lst)
	{
 		printf("the content is : %d\n", *(int*)(lst->content));
		lst = lst->next;
	}
}

int main()
{
	int arr[] = {1, 2, 3};
	t_list *node = (t_list *)malloc(sizeof(t_list));
	t_list *node1 = (t_list *)malloc(sizeof(t_list));
	t_list *node2 = (t_list *)malloc(sizeof(t_list));

	node->content = arr;
	node->next = node1;

	node1->content = arr + 1;
	node1->next = node2;

	node2->content = arr + 2;
	node2->next = NULL;

	t_list *list = node;
	ft_lstiter(list, &f);
	write_content (list);
}*/
