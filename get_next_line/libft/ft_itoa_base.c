/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 18:14:00 by jdebladi          #+#    #+#             */
/*   Updated: 2016/11/16 18:14:02 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_itoa_range(int n, unsigned int base)
{
	size_t	len;
	int		nb;

	if (base == 10)
		len = 1 + (n < 0);
	else
		len = 1;
	nb = (n < 0) ? n : -n;
	while ((nb = nb / base) != 0)
		len++;
	return (len);
}

char		*ft_itoa_base(int n, unsigned int base)
{
	char	*ret;
	size_t	len;

	len = ft_itoa_range(n, base);
	if ((ret = malloc(sizeof(char) * len + 1)) == NULL)
		return (NULL);
	if (n >= 0)
		n = -n;
	else
	{
		if (base == 10)
			ret[0] = '-';
	}
	if (n == 0)
		ret[0] = '0';
	ret[len] = '\0';
	while (n < 0)
	{
		len--;
		ret[len] = (-(n % base) >= 10) ? -(n % base) + '7' : -(n % base) + '0';
		n = n / base;
	}
	return (ret);
}
