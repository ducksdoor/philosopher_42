/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segurity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lortega- <lortega-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 20:57:12 by lortega-          #+#    #+#             */
/*   Updated: 2023/09/28 20:57:22 by lortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	segurity(int argc, char **argv)
{
	int	x;

	x = 1;
	if (argc != 5 && argc != 6)
		ft_exit("Número incorrecto de argumentos", 2);
	while (x < argc)
	{
		if (ft_atoi(argv[x]) <= 0)
			ft_exit("Valor incorrecto", 2);
		x++;
	}
}

		/* if (argc == 6 && argv[5] <= 0) */