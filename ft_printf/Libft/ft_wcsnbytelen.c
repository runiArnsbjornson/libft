/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcsnbytelen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 11:42:27 by jdebladi          #+#    #+#             */
/*   Updated: 2017/03/02 12:15:23 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wcsnbytelen(const wchar_t *s, size_t n)
{
	const wchar_t	*p;
	size_t			byte_size;

	p = s;
	if (n == 0)
		return (0);
	byte_size = ft_wcbytesize(*p);
	while (*p && byte_size <= n)
	{
		byte_size += ft_wcbytesize(*p);
		++p;
	}
	byte_size -= ft_wcbytesize(*--p);
	return (byte_size);
}
