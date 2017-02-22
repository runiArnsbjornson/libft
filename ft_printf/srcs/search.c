/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 15:04:59 by jdebladi          #+#    #+#             */
/*   Updated: 2017/02/22 17:54:01 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	precision(const char *fmt, t_flag *f, int i)
{
	while (fmt[i] && fmt && i < f->len)
	{
		if (ft_isdigit(fmt[i]) == 1)
		{
			if (fmt[i] == '0' && f->width == 0)
				f->lag_zero = 1;
			f->width *= 10;
			f->width += fmt[i] - '0';
		}
		if (ft_isdigit(fmt[i]) == 0)
			break ;
		i++;
	}
}

char		check_conv(const char c)
{
	const char conv[27] = "%abcdefgikoprsuxACDEFGIOSUX";
	int i;

	i = 0;
	while (i++ <= 27)
		{
			if (c == conv[i])
				return (conv[i]);
		}
	return (0);
}

int		check_flag(const char c)
{
	const char flag[19] = "#.-+ hljz0123456789";
	int i;

	i = 0;
	while (i++ <= 19)
		{
			if (c == flag[i])
				return (1);
		}
	return (0);
}

void	search(const char *fmt, t_flag *f, int i)
{
	while (fmt[i] && fmt && check_flag(fmt[i]) != 0)
	{
		f->len++;
		i++;
	}
	f->conv = check_conv(fmt[i]);
	if (f->conv != 0)
		get(fmt, f, 1);
	precision(fmt, f, 1);
	printf("[%s] len=%d i=%d conv=%c w=%d p=%d\n", fmt, f->len, i, f->conv, f->width, f->preci);
}
