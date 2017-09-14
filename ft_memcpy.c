/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 19:12:50 by jdebladi          #+#    #+#             */
/*   Updated: 2017/09/12 12:46:48 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dtmp;
	const char	*stmp;

	dtmp = dst;
	stmp = src;
	while (n-- != 0)
		*dtmp++ = *stmp++;
	return (dst);
}
