/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 18:05:05 by jdebladi          #+#    #+#             */
/*   Updated: 2017/03/09 18:29:22 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		sign_float(char *buf, int i, t_flag *f, int len)
{
	if (f->sign == -1)
	{
		if (f->preci == len)
			buf[--i] = '-';
		else
		{
			i = buf[i] == '0' ? i : --i;
			buf[i] = '-';
		}
	}
	return (i);
}

int		float_format(char *buf, int i, t_flag *f, int len)
{
	len = ft_strlen(&buf[i]);
	i = sign_float(buf, i, f, len);
	if (f->lag_plus && f->sign == 1)
	{
		if (f->preci == len)
			buf[--i] = '+';
		else
		{
			i = buf[i] == '0' ? i : --i;
			buf[i] = '+';
		}
	}
	if (f->lag_space && f->sign == 1 && !f->preci && !f->lag_plus)
	{
		i = buf[i] == '0' ? i : --i;
		buf[i] = ' ';
	}
	return (i);
}

int		float_mantis(char *buf, int i, t_flag *f, long double mantis)
{
	int j;
	int digit;

	j = 0;
	mantis = -mantis * (float)ft_pwr(10, f->preci);
	digit = (float)mantis;
	while (j < f->preci)
	{
		buf[--i] = digit % 10 + '0';
		digit /= 10;
		j++;
	}
	return (i);
}

char	*float_to_string(char *buf, int i, long double n, t_flag *f)
{
	long long	carac;
	long double	mantis;

	buf[--i] = 0;
	f->sign = n < 0 ? -1 : 1;
	n = n < 0 ? n : -n;
	carac = (long long)n;
	mantis = n - (long double)carac;
	f->preci = f->lag_dot == 0 ? 6 : f->preci;
	if (f->preci)
		i = float_mantis(buf, i, f, mantis);
	if (f->preci || f->lag_htag)
		buf[--i] = '.';
	if (carac == 0)
		buf[--i] = '0';
	while (carac)
	{
		buf[--i] = -(carac % 10) + '0';
		carac /= 10;
	}
	i = zero_fill(buf, i, f, 0);
	i = float_format(buf, i, f, 0);
	return (&buf[i]);
}

int		float_handler(va_list args, t_flag *f)
{
	long double	n;
	char		*s;
	char		buf[32 + f->width];

	// if (ft_isupper(f->conv) == 1)
	// {
	// }
	n = float_size(0, args, f);
	s = float_to_string(buf, 32 + f->width, n, f);
	return (printer(s, f, ft_strlen(s)));
}
