/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualbuqu <lualbuqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 21:42:59 by lualbuqu          #+#    #+#             */
/*   Updated: 2024/04/15 10:56:08 by lualbuqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

/* int main()
{
	int a = 4;
	int b = 2;

	t_list *node1 = ft_lstnew((void *)&a);
	t_list *node2 = ft_lstnew((void *)&b);

	ft_lstadd_front(&node1, node2);

	printf("Result is: %i\n", *(int *)node1->content);
	printf("Result is: %i\n", *(int *)node1->next->content);

	free(node1->next);
	free(node1);

	return (0);
} */
