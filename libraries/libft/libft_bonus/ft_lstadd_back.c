/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualbuqu <lualbuqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 21:48:21 by lualbuqu          #+#    #+#             */
/*   Updated: 2024/04/15 10:54:56 by lualbuqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	while (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}
/* int main()
{
	int a = 4;
	int b = 2;

	t_list *node1;
	node1 = ft_lstnew((void *)&a);
	t_list *node2;
	node2 = ft_lstnew((void *)&b);

	ft_lstadd_back(&node1, node2);

	printf("Result is: %i\n", *(int *)node1->next->content);
	free(node1->next);
	free(node1);
	return (0);
} */
