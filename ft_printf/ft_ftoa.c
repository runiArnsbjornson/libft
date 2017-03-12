/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 18:47:02 by jdebladi          #+#    #+#             */
/*   Updated: 2017/03/12 12:33:01 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <float.h>
#include <stdio.h>

int		ft_pwr(int nbr, int pwr);
char	*ft_strdup(const char *s);

int		ft_ftoa_dependancy(char *buf, int i, long double mantis, int precision)
{
	int j;
	int digit;
	long double approx;

	j = 0;
	approx = (float)(-mantis * ft_pwr(10, precision + 1));
	mantis = -mantis * ft_pwr(10, precision);
	digit = (float)mantis;
	approx = (float)approx - digit * 10;
	digit += (int)approx >= 5 ? 1 : 0;
	while (j++ < precision)
	{
		buf[--i] = digit % 10 + '0';
		digit /= 10;
	}
	buf[--i] = '.';
	return (i);
}

char	*ft_ftoa(long double n, int precision)
{
	char	buf[64];
	char	*ret;
	int		i;
	int		neg;
	long long	carac;
	long double	mantis;

	i = 64;
	buf[--i] = 0;
	neg = n < 0 ? 1 : 0;
	n = n < 0 ? n : -n;
	carac = (long long)n;
	mantis = n - (long double)carac;
	if (precision)
		i = ft_ftoa_dependancy(buf, i, mantis, precision);
	if (carac == 0)
		buf[--i] = '0';
	while (carac)
	{
		buf[--i] = -(carac % 10) + '0';
		carac /= 10;
	}
	if (neg)
		buf[--i] = '-';
	ret = ft_strdup(&buf[i]);
	return (ret);
}
