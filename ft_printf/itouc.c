/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itouc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 12:32:39 by jdebladi          #+#    #+#             */
/*   Updated: 2017/02/06 12:32:41 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int	main(int ac, char const **av)
{
	int i;

	i = 1;
	setlocale(LC_ALL, "");
	while (i < ac)
	{
		printf("%lc\n", atoi(av[i]));
		i++;
	}
	return 0;
}
