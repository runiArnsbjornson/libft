/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 16:57:12 by jdebladi          #+#    #+#             */
/*   Updated: 2017/02/24 12:57:15 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			hex_format(char *buf, int i, t_flag *f, int len)
{
	i = zero_fill(buf, i, f, len);
	if (f->lag_htag && buf[i] != '0')
	{
		buf[--i] = f->start == 'a' ? 'x' : 'X';
		buf[--i] = '0';
	}
	if (f->lag_htag && f->preci != 0 && buf[i] == '0')
	{
		buf[i] = f->start == 'a' ? 'x' : 'X';
		buf[--i] = '0';
	}
	if (f->lag_htag && buf[i] == '0' && buf[i + 1] != 0)
	{
		buf[i + 1] = f->start == 'a' ? 'x' : 'X';
		buf[i] = '0';
	}
	return (i);
}

char		*hex_to_string(char *buf, int i, unsigned long long n, t_flag *f)
{
	buf[--i] = 0;
	if (n == 0)
	{
		if (f->lag_dot == 1 && f->preci == 0)
			return (&buf[i]);
		buf[--i] = '0';
		if (f->conv == 'p')
		{
			buf[--i] = f->start == 'a' ? 'x' : 'X';
			buf[--i] = '0';
			return (&buf[i]);
		}
	}
	while (n)
	{
		buf[--i] = n % 16 >= 10 ? n % 16 + f->start - 10 : n % 16 + '0';
		n /= 16;
	}
	i = hex_format(buf, i, f, ft_strlen(&buf[i]));
	return (&buf[i]);
}

int			hex_handler(char **out, va_list args, t_flag *f)
{
	long long	n;
	char		*s;
	char		buf[32 + f->width];

	if (f->conv == 'X')
		f->start = 'A';
	if (f->conv == 'p')
		f->lag_htag = 1;
	n = uint_size(0, args, f);
	s = hex_to_string(buf, 32 + f->width, n, f);
	return (printer(out, s, f, ft_strlen(s)));
}
