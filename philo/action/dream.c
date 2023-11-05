/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dream.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lortega- <lortega-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:35:39 by lortega-          #+#    #+#             */
/*   Updated: 2023/11/05 15:35:46 by lortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	dream(int time, t_list *phl)
{
	struct timeval	start_to_dream;
	struct timeval	time_to_dream;
	int				t_process;

	gettimeofday(&start_to_dream, NULL);
	time_to_dream = start_to_dream;
	t_process = ft_time(start_to_dream, time_to_dream);
	while (t_process < time)
	{
		usleep(1600);
		gettimeofday(&time_to_dream, NULL);
		t_process = ft_time(start_to_dream, time_to_dream);
		realtime(phl, "normal");
	}
	return ;
}
