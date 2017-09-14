/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 17:30:44 by jdebladi          #+#    #+#             */
/*   Updated: 2017/09/14 10:14:14 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoll(const char *ptr)
{
	int			sign;
	long long	ret;
	char		comp;

	sign = 1;
	ret = 0;
	if (ptr == NULL)
		ft_put_error("read NULL");
	while (ft_isspace(*ptr))
		ptr++;
	if (*ptr == '-' || *ptr == '+')
		sign = *ptr++ == '-' ? -1 : 1;
	while (ft_isdigit(*ptr))
	{
		ret = ret * 10 + FT_TODIGIT(*ptr++);
		if (ret >= FT_ABS(LLONG_MAX / 10))
		{
			comp = *ptr;
			if (sign == 1 && comp >= '8')
				return (LLONG_MAX);
			if (sign == -1 && comp >= '7')
				return (LLONG_MIN);
		}
	}
	return (ret * sign);
}
