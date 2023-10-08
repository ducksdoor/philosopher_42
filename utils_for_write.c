/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_write.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lortega- <lortega-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 23:37:06 by lortega-          #+#    #+#             */
/*   Updated: 2023/09/25 23:37:08 by lortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_strlen(char *s)
{
	int	x;

	x = 0;
	while (s[x] != '\0')
		x++;
	return (x);
}

void	ft_exit(char *texto, int fd)
{
	write(fd, texto, ft_strlen(texto));
	exit(fd);
}

long	ft_time(struct timeval start, struct timeval end)
{
	long	x;
	long seconds_elapsed = end.tv_sec - start.tv_sec;
	long microseconds_elapsed = end.tv_usec - start.tv_usec;


	x = (seconds_elapsed * 1000) + (microseconds_elapsed / 1000);
	return (x);
}
