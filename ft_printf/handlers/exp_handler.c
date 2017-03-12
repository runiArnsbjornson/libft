/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 18:53:04 by jdebladi          #+#    #+#             */
/*   Updated: 2017/03/12 20:27:41 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		sign_exp(char *buf, int i, t_flag *f, int len)
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

int		exp_format(char *buf, int i, t_flag *f, int len)
{
	len = ft_strlen(&buf[i]);
	i = sign_exp(buf, i, f, len);
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

int		exp_mantis(char *buf, int i, t_flag *f, long double mantis)
{
	int			j;
	int			digit;
	long double	approx;

	j = 0;
	approx = -mantis * ft_pwr(10, f->preci + 1);
	mantis = -mantis * ft_pwr(10, f->preci);
	digit = (float)mantis;
	approx = approx - digit * 10;
	digit += (int)approx >= 5 ? 1 : 0;
	while (j < f->preci)
	{
		buf[--i] = digit % 10 + '0';
		digit /= 10;
		j++;
	}
	return (i);
}

char	*float_to_exp(char *buf, int i, long double n, t_flag *f)
{
	int			exp;
	long long	carac;
	long double	mantis;

	buf[--i] = 0;
	f->sign = n < 0 ? -1 : 1;
	n = n < 0 ? n : -n;
	carac = (long long)n;
	mantis = n - (long double)carac;
	exp = ft_log(n);
	f->preci = f->lag_dot == 0 ? 6 : f->preci;
	f->preci = f->preci - (exp - 1) < 0 ? 0 : f->preci;
	printf("(%d)\n", f->preci);
	if (f->preci)
		i = exp_mantis(buf, i, f, mantis);
	if (carac == 0)
	{
		if (f->preci || f->lag_htag)
			buf[--i] = '.';
		buf[--i] = '0';
	}
	while (carac)
	{
		if (-carac < 10)
			buf[--i] = '.';
		buf[--i] = -(carac % 10) + '0';
		carac /= 10;
	}
	i = zero_fill(buf, i, f, 0);
	i = exp_format(buf, i, f, 0);
	return (&buf[i]);
}
