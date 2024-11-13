/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualbuqu <lualbuqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:46:59 by lualbuqu          #+#    #+#             */
/*   Updated: 2024/10/16 16:37:34 by lualbuqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

// Timer for animation cooldown
bool	fps(float milliseconds)
{
	static clock_t	last_frame = 0;
	clock_t			current_time;
	double			time_diff;

	current_time = clock();
	time_diff = (double)(current_time - last_frame) / CLOCKS_PER_SEC;
	if (time_diff < milliseconds)
		return (false);
	last_frame = current_time;
	return (true);
}
