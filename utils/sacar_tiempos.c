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

#include "../philosophers.h"

long	ft_time(struct timeval start, struct timeval end)
{
	long	x;
	long	seconds_elapsed;
	long	microseconds_elapsed;

	seconds_elapsed = end.tv_sec - start.tv_sec;
	microseconds_elapsed = end.tv_usec - start.tv_usec;
	x = (seconds_elapsed * 1000) + (microseconds_elapsed / 1000);
	return (x);
}

long	realtime(t_list *phl, char *status)
{
	long	t_real;

	if (0 == ft_strcmp("restore", status))
		gettimeofday(&phl->clock->aux, NULL);
	if (0 == ft_strcmp("normal", status))
	{
		gettimeofday(&phl->clock->end, NULL);
		phl->clock->t_juego = ft_time(phl->clock->aux, phl->clock->end);
	}
	t_real = ft_time(phl->inf->start, phl->clock->end);
	if (phl->clock->t_juego >= phl->inf->t_die)
		die(phl, t_real);
	return (t_real);
}
