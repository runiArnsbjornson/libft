/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 18:03:52 by jdebladi          #+#    #+#             */
/*   Updated: 2017/09/12 16:54:00 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n-- != 0)
	{
		if (*s1 != *s2)
			return (*(unsigned char *)(uintptr_t)s1 -
			*(unsigned char *)(uintptr_t)s2);
		else if (*s1 == 0)
			return (0);
		s1++;
		s2++;
	}
	return (0);
}
