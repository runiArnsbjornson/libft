/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 03:50:16 by jdebladi          #+#    #+#             */
/*   Updated: 2017/02/24 05:18:33 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		percent_handler(char **out, t_flag *f)
{
	int		i;
	char	buf[2 + f->width];

	i = 2 + f->width;
	buf[--i] = 0;
	buf[--i] = '%';
	f->preci = 0;
	i = zero_fill(buf, i, f, ft_strlen(&buf[i]));
	return (printer(out, &buf[i], f, ft_strlen(&buf[i])));
}
