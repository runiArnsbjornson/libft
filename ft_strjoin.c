/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 18:26:45 by jdebladi          #+#    #+#             */
/*   Updated: 2017/09/12 13:36:02 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	char	*ret;

	if (!(s1))
		return ((char *)(uintptr_t)s2);
	if (!(s2))
		return ((char *)(uintptr_t)s1);
	if ((ret = ft_memalloc(ft_strlen(s1) + ft_strlen(s2) + 1)) == NULL)
		return (NULL);
	ptr = ret;
	while (*s1 != '\0')
		*ptr++ = *s1++;
	while (*s2)
		*ptr++ = *s2++;
	return (ret);
}
