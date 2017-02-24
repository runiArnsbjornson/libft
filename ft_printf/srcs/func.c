/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 15:22:14 by jdebladi          #+#    #+#             */
/*   Updated: 2017/02/24 14:04:35 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void				printchar(char **s, int c)
{
	if (s)
	{
		**s = c;
		++(*s);
	}
	else
		(void)ft_putchar(c);
}

int					zero_fill(char *buf, int i, t_flag *f, int len)
{
	len = ft_strlen(&buf[i]);
	if (f->lag_zero && f->width > 0 && !f->lag_minus && !f->preci)
	{
		while (len < f->width)
		{
			buf[--i] = '0';
			f->width--;
		}
	}
	while (f->preci > len)
	{
		buf[--i] = '0';
		len++;
	}
	return (i);
}

long long			int_size(long long n, va_list args, t_flag *f)
{
	if (f->lag_ll == 1)
		n = va_arg(args, long long);
	else if (f->lag_l == 1)
		n = va_arg(args, long);
	else if (f->lag_hh == 1)
		n = (signed char)va_arg(args, int);
	else if (f->lag_h == 1)
		n = (short)va_arg(args, int);
	else if (f->lag_j == 1)
		n = (intmax_t)va_arg(args, long long);
	else if (f->lag_z == 1)
		n = va_arg(args, ssize_t);
	else
		n = va_arg(args, int);
	return (n);
}

unsigned long long	uint_size(unsigned long long n, va_list args, t_flag *f)
{
	if (f->conv == 'p')
		n = (long)va_arg(args, void *);
	else if (f->lag_ll == 1)
		n = va_arg(args, unsigned long long);
	else if (f->lag_l == 1)
		n = va_arg(args, unsigned long);
	else if (f->lag_hh == 1)
		n = (unsigned char)va_arg(args, unsigned int);
	else if (f->lag_h == 1)
		n = (unsigned short)va_arg(args, unsigned int);
	else if (f->lag_j == 1)
		n = (uintmax_t)va_arg(args, unsigned long long);
	else if (f->lag_z == 1)
		n = va_arg(args, size_t);
	else
		n = va_arg(args, unsigned int);
	return (n);
}
