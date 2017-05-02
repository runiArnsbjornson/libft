/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 19:12:50 by jdebladi          #+#    #+#             */
/*   Updated: 2016/11/09 11:18:52 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	long *d;
	char		*cd;
	const long	*s;
	const char	*cs;
	ssize_t		i;

	if ((uintptr_t)dst % sizeof(long) == 0 && (uintptr_t)src % sizeof(long) == 0
	&& n % sizeof(long))
	{
		d = dst;
		s = src;
		i = -1; 
		while (i++ < n / sizeof(long))
			d[i] = s[i];
	}
	else
	{
		cd = dst;
		cs = src;
		i = -1;
		while (i++ < n)
			cd[i] = cs[i];
	}
	return (dst);
}
