/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualbuqu <lualbuqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:14:17 by lualbuqu          #+#    #+#             */
/*   Updated: 2024/04/18 16:28:11 by lualbuqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_calloc(size_t elements, size_t size)
{
	void	*ptr;

	if (elements && size > UINT_MAX / elements)
		return (NULL);
	ptr = malloc(elements * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, (elements * size));
	return (ptr);
}
