/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 18:14:00 by jdebladi          #+#    #+#             */
/*   Updated: 2016/11/21 15:13:00 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**  base == 0 is a shortcut for decimal
**  base == 1 is a shortcut for hexadecimal
*/

static int	ft_itoa_range(int n, int base)
{
	size_t	len;
	int		nb;

	base = (base == -2147483648) ? 36 : base;
	base = (base < 0) ? -base : base;
	base = (base > 36) ? 36 : base;
	base = (base == 0) ? 10 : base;
	base = (base == 1) ? 16 : base;
	if (base == 10)
		len = 1 + (n < 0);
	else
		len = 1;
	nb = (n < 0) ? n : -n;
	while ((nb = nb / base) != 0)
		len++;
	return (len);
}

char		*ft_itoa_base(int n, int base)
{
	char	*ret;
	size_t	len;

	len = ft_itoa_range(n, base);
	if ((ret = malloc(sizeof(char) * len + 1)) == NULL)
		return (NULL);
	if (base == 0)
		base = 10;
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
