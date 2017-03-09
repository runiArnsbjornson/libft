/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 18:47:02 by jdebladi          #+#    #+#             */
/*   Updated: 2017/03/09 17:48:23 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <float.h>
#include <stdio.h>

int		ft_pwr(int nbr, int pwr);
char	*ft_strdup(const char *s);

char	*ft_ftoa(long double n, int precision)
{
	char	buf[64];
	char	*ret;
	int		i;
	int		neg;
	int		carac;
	long long	digit;
	long double	mantis;

	i = 64;
	neg = n < 0 ? 1 : 0;
	carac = (long long)n;
	mantis = n < 0 ? n - carac : -n + carac;
	carac = n < 0 ? carac : -carac;
	buf[--i] = 0;
	if (precision != 0)
	{
		digit = mantis * ft_pwr(10, precision);
		while (digit)
		{
			buf[--i] = -(digit % 10) + '0';
			digit /= 10;
		}
		buf[--i] = '.';
	}
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
