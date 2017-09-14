/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 12:53:16 by jdebladi          #+#    #+#             */
/*   Updated: 2017/09/14 09:30:41 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	len;
	char	*str;

	len = ft_strlen(src) + 1;
	if (!(str = (char *)ft_memalloc(sizeof(char) * (len))))
		return (NULL);
	ft_memcpy(str, src, len);
	return (str);
}
