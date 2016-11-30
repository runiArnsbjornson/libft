/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetriminos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 16:42:30 by cfrouin           #+#    #+#             */
/*   Updated: 2016/11/30 17:28:11 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			tet_size(t_tetriminos *tetr)
{
	int			i;
	int			j;
	int			maxi;
	int			maxj;

	tet_trim(tetr);
	j = 3;
	maxi = 0;
	maxj = 0;
	while (j >= 0)
	{
		i = 3;
		while (i >= 0 && tetr->shape[j][i] == '.')
			i--;
		if (i >= 0 && tetr->shape[j][i] != '.' && maxj == 0)
			maxj = j;
		if (i > maxi)
			maxi = i;
		j--;
	}
	tetr->length = maxi + 1;
	tetr->height = maxj + 1;
}

void			tet_trim(t_tetriminos *tetr)
{
	if (ft_strncmp("....", tetr->shape[0], 4) == 0)
	{
		ft_strncpy(tetr->shape[0], tetr->shape[1], 4);
		ft_strncpy(tetr->shape[1], tetr->shape[2], 4);
		ft_strncpy(tetr->shape[2], tetr->shape[3], 4);
		ft_strncpy(tetr->shape[3], "....", 4);
		tet_trim(tetr);
	}
	else if (tetr->shape[0][0] == '.' && tetr->shape[1][0] == '.'
			&& tetr->shape[2][0] == '.' && tetr->shape[3][0] == '.')
	{
		ft_strncpy(tetr->shape[0], &(tetr->shape[0][1]), 3);
		ft_strncpy(tetr->shape[1], &(tetr->shape[1][1]), 3);
		ft_strncpy(tetr->shape[2], &(tetr->shape[2][1]), 3);
		ft_strncpy(tetr->shape[3], &(tetr->shape[3][1]), 3);
		tetr->shape[0][3] = '.';
		tetr->shape[1][3] = '.';
		tetr->shape[2][3] = '.';
		tetr->shape[3][3] = '.';
		tet_trim(tetr);
	}
}

int				check_around(t_tetriminos *tetr, int x, int y)
{
	int count;

	count = 0;
	if (x == 0 || (x > 0 && tetr->shape[y][x - 1] == '.'))
		count++;
	if (x == 3 || (x < 3 && tetr->shape[y][x + 1] == '.'))
		count++;
	if (y == 0 || (y > 0 && tetr->shape[y - 1][x] == '.'))
		count++;
	if (y == 3 || (y < 3 && tetr->shape[y + 1][x] == '.'))
		count++;
	return (count);
}

int				check_tetriminos(t_tetriminos *tetr)
{
	int		i;
	int		j;
	int		around;
	int		count;

	j = -1;
	count = 0;
	around = 0;
	while (++j < 4)
	{
		i = -1;
		while (++i < 4)
		{
			if (tetr->shape[j][i] != '.' && tetr->shape[j][i] != '#')
				return (-1);
			if (tetr->shape[j][i] == '#')
			{
				count++;
				around += check_around(tetr, i, j);
			}
		}
	}
	if (count == 4 && around <= 10)
		return (1);
	return (-1);
}
