/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualbuqu <lualbuqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:05:11 by lualbuqu          #+#    #+#             */
/*   Updated: 2024/04/15 16:19:04 by lualbuqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*head;
	t_list	*node;

	head = *lst;
	if (!lst || !del)
		return ;
	while (head != NULL)
	{
		node = head->next;
		del(head->content);
		free(head);
		head = node;
	}
	*lst = NULL;
}
