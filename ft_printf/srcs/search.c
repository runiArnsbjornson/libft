/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 15:04:59 by jdebladi          #+#    #+#             */
/*   Updated: 2017/03/12 13:36:56 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	check_conv(const char c)
{
	const char	conv[28] = "%abcdefgikoprsuxABCDEFGIOSUX";
	int			i;

	i = -1;
	while (i++ <= 27)
	{
		if (c == conv[i])
			return (conv[i]);
	}
	return (0);
}

int		check_flag(const char c)
{
	const char	flag[21] = "#.-+* hlLjz0123456789";
	int			i;

	i = -1;
	while (i++ <= 20)
	{
		if (c == flag[i])
			return (1);
	}
	return (0);
}

void	search(const char *fmt, t_flag *f, va_list args, int i)
{
	while (fmt[i] && fmt && check_flag(fmt[i]) != 0)
	{
		f->len++;
		i++;
	}
	while (fmt[f->i])
		++f->i;
	f->conv = check_conv(fmt[i]);
	get(fmt, f, args, 1);
	// printf("\n>len=%d h=%d hh=%d l=%d ll=%d L=%d j=%d z=%d .=%d #=%d 0=%d -=%d +=%d ''=%d w=%d p=%d sign=%d conv=%c<\n", f->len, f->lag_h, f->lag_hh, f->lag_l, f->lag_ll, f->lag_L, f->lag_j, f->lag_z, f->lag_dot, f->lag_htag, f->lag_zero, f->lag_minus, f->lag_plus, f->lag_space, f->width, f->preci, f->sign, f->conv);
}
