/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:40:57 by cfrouin           #+#    #+#             */
/*   Updated: 2016/11/28 13:41:11 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**new_map(int size)
{
	int		i;
	int		j;
	char	**tab;

	i = 0;
	if ((tab = malloc(sizeof(char*) * (size + 1))) == NULL)
		return (NULL);
	while (i < size)
	{
		j = 0;
		if ((tab[i] = malloc(sizeof(char) * (size + 1))) == NULL)
			return (NULL);
		while (j < size)
			tab[i][j++] = '.';
		tab[i++][j] = 0;
	}
	tab[i] = NULL;
	return (tab);
}

void		delete_map(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}
