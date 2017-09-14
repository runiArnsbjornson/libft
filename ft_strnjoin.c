/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 11:00:07 by jdebladi          #+#    #+#             */
/*   Updated: 2017/09/12 15:29:03 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(int nbr, ...)
{
	int		i;
	va_list	args;
	char	*ret;
	char	*tmp;

	i = 0;
	va_start(args, nbr);
	ret = ft_memalloc(sizeof(char));
	while (i < nbr)
	{
		tmp = ret;
		free(tmp);
		if (!(tmp = va_arg(args, char *)))
		{
			ft_putendl_fd("Error: nbr too big", 2);
			exit(0);
		}
		ret = ft_strjoin(ret, tmp);
		i++;
	}
	va_end(args);
	return (ret);
}
