/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 13:57:15 by jdebladi          #+#    #+#             */
/*   Updated: 2016/11/04 14:23:57 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int i;
	int *ret;

	if (min >= max)
		return (NULL);
	else
	{
		i = 0;
		if ((ret = malloc(sizeof(int) * (max - min))) == NULL)
			return (NULL);
		while (i < max - min)
		{
			ret[i] = min + i;
			i++;
		}
	}
	return (ret);
}
