/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 18:27:46 by jdebladi          #+#    #+#             */
/*   Updated: 2017/09/12 16:45:47 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	const char	*ptr;
	size_t		len;
	char		*ret;

	if (!s)
		return (NULL);
	ptr = s + ft_strlen(s) - 1;
	while (ft_isspace(*ptr) && ptr >= s)
		ptr--;
	while (ft_isspace(*s))
		s++;
	len = ptr > s ? (size_t)(ptr - s + 1) : 0;
	if (!(ret = ft_memalloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_strncpy(ret, s, len);
	ret[len + 1] = '\0';
	return (ret);
}
