/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 18:13:00 by jdebladi          #+#    #+#             */
/*   Updated: 2017/09/14 09:32:25 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char *ret;

	if (size == 0)
		return (NULL);
	if (size > LONG_MAX || !(ret = malloc(size)))
		return (NULL);
	ft_bzero(ret, size);
	return ((void *)ret);
}
