/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 15:25:32 by jdebladi          #+#    #+#             */
/*   Updated: 2017/09/12 13:49:56 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *s)
{
	char *start;
	char *t;
	char tmp;

	start = s;
	t = ft_strchr(s, '\0');
	while (s < --t)
	{
		tmp = *s;
		*s++ = *t;
		*t = tmp;
	}
	return (start);
}
