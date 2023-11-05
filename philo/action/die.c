/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lortega- <lortega-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 23:39:01 by lortega-          #+#    #+#             */
/*   Updated: 2023/11/02 23:39:04 by lortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	die(t_list *phl)
{
	if (phl->inf->death == 0)
	{
		printf("\n \033[1;34m [[%ld]] \033[0m", phl->philo->t_real);
		printf("	\033[1;33m%d\033[0m", phl->philo->name);
		printf("\033[1;31m died\n\033[0m");
		phl->inf->death++;
	}
	return ;
}
