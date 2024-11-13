/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualbuqu <lualbuqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 21:49:09 by lualbuqu          #+#    #+#             */
/*   Updated: 2024/04/15 14:09:27 by lualbuqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
/* int	main(void)
{
	t_list *head = NULL;
	t_list *second = NULL;
	t_list *third = NULL;

	head = malloc(sizeof(t_list));
	second = malloc(sizeof(t_list));
	third = malloc(sizeof(t_list));

	head->content = "First";
	head->next = second;

	second->content = "Second";
	second->next = third;

	third->content = "Third";
	third->next = NULL;

	int size = ft_lstsize(head);
	printf("Size of the linked list: %d\n", size);

	free(head);
	free(second);
	free(third);

	return (0);
} */