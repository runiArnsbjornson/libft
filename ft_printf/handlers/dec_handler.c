/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dec_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 12:40:12 by jdebladi          #+#    #+#             */
/*   Updated: 2017/02/24 14:04:01 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		space_dec(char *buf, int i, t_flag *f)
{
	if (f->lag_space && f->sign == 1 && !f->preci && !f->lag_plus)
	{
		i = buf[i] == '0' ? i : --i;
		buf[i] = ' ';
	}
	return (i);
}

int		dec_format(char *buf, int i, t_flag *f, int len)
{
	len = ft_strlen(&buf[i]);
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
	i = space_dec(buf, i, f);
	return (i);
}

char	*dec_to_string(char *buf, int i, long long n, t_flag *f)
{
	buf[--i] = 0;
	if (n == 0)
	{
		if (f->lag_dot == 1 && f->preci == 0)
			return (&buf[i]);
		buf[--i] = '0';
		i = zero_fill(buf, i, f, 0);
		if (f->lag_plus)
			buf[--i] = '+';
		if (f->lag_space && f->sign == 1 && !f->preci && !f->lag_plus)
			buf[--i] = ' ';
		return (&buf[i]);
	}
	f->sign = n < 0 ? -1 : 1;
	if (n > 0)
		n = -n;
	while (n)
	{
		buf[--i] = -(n % 10) + '0';
		n /= 10;
	}
	i = zero_fill(buf, i, f, 0);
	i = dec_format(buf, i, f, 0);
	return (&buf[i]);
}

char	*udec_to_string(char *buf, int i, unsigned long long n, t_flag *f)
{
	buf[--i] = 0;
	if (n == 0)
		buf[--i] = '0';
	while (n)
	{
		buf[--i] = n % 10 + '0';
		n /= 10;
	}
	i = zero_fill(buf, i, f, 0);
	i = dec_format(buf, i, f, 0);
	return (&buf[i]);
}

int		dec_handler(char **out, va_list args, t_flag *f)
{
	long long	n;
	char		*s;
	char		buf[32 + f->width];

	ft_strclr(buf);
	if (ft_isupper(f->conv) == 1)
	{
		f->lag_ll = f->lag_l ? 1 : 0;
		f->lag_l = 1;
	}
	if (f->sign)
	{
		n = int_size(0, args, f);
		s = dec_to_string(buf, 32 + f->width, n, f);
	}
	else
	{
		n = uint_size(0, args, f);
		s = udec_to_string(buf, 32 + f->width, n, f);
	}
	return (printer(out, s, f, ft_strlen(s)));
}
