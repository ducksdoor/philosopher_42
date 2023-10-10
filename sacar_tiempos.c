/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sacar_tiempos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lortega- <lortega-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 22:17:35 by lortega-          #+#    #+#             */
/*   Updated: 2023/10/09 22:17:40 by lortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	ft_time(struct timeval start, struct timeval end)
{
	long	x;
	long seconds_elapsed = end.tv_sec - start.tv_sec;
	long microseconds_elapsed = end.tv_usec - start.tv_usec;


	x = (seconds_elapsed * 1000) + (microseconds_elapsed / 1000);
	return (x);
}

long int	realtime(t_list *phl)
{
	long int	t_real;

	gettimeofday(&phl->clock->end, NULL);
	gettimeofday(&phl->clock->aux, NULL);
	t_real = ft_time(phl->clock->start, phl->clock->end);
	phl->clock->t_juego = ft_time(phl->clock->aux, phl->clock->end);
	return (t_real);
}
