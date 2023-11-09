/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lortega- <lortega-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 21:44:18 by lortega-          #+#    #+#             */
/*   Updated: 2023/11/08 21:44:34 by lortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	ft_putstr(char *s)
{
	int	x;

	if (!s)
		return ;
	x = 0;
	while (s[x])
	{
		write(2, &s[x], 1);
		x++;
	}
	if (x > 0)
		write (2, "\n", 1);
}

void	ft_free(char *str, void *liberty)
{
	ft_putstr(str);
	free(liberty);
}

void	ft_select_free(char *str, void *liberty, void *moreliberty)
{
	ft_free("", liberty);
	ft_free(str, moreliberty);
}

void	ft_big_free(t_list *phl)
{
	pthread_mutex_destroy(phl->philo->mutex);
	ft_free("", phl->inf);
	ft_free("", phl->philo);
	ft_free("Problems within the philosopher.", phl->clock);
}
