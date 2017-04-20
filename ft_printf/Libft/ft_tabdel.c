/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 09:19:16 by jdebladi          #+#    #+#             */
/*   Updated: 2017/04/14 17:12:06 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_tabdel(char **tab)
{
	int i;

	if (tab != NULL)
	{
		i = -1;
		while (tab[++i])
			free(tab[i]);
		free(tab[i]);
		free(tab);
	}
}
