/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:13:59 by cfrouin           #+#    #+#             */
/*   Updated: 2016/11/28 13:14:00 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int					main(int ac, char **av)
{
	t_tetriminos	*list;

	list = NULL;
	if (ac != 2)
		ft_putstr("error\n");
	else
	{
		if ((list = check_file(av[1])) == NULL)
		{
			ft_putstr("error\n");
			return (-1);
		}
		solve(list);
		tet_list_destroy(list);
	}
	return (0);
}
