/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tet_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 11:26:43 by cfrouin           #+#    #+#             */
/*   Updated: 2016/11/22 12:53:06 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				tet_list_pushback(t_tetriminos *list, t_tetriminos *new)
{
	if (list == NULL || new == NULL)
		return (-1);
	while (list->next)
		list = list->next;
	list->next = new;
	new->prev = list;
	new->next = NULL;
	return (1);
}

int				tet_list_popback(t_tetriminos *list)
{
	if (list == NULL)
		return (-1);
	if (list->next == NULL)
		free(list);
	else
	{
		while (list->next->next)
			list = list->next;
		free(list->next);
		list->next = NULL;
	}
	return (1);
}

void			tet_list_destroy(t_tetriminos *list)
{
	if (list == NULL)
		return ;
	if (list->next)
		tet_list_destroy(list->next);
	free(list);
}

t_tetriminos	*tet_list_index(t_tetriminos *list, size_t index)
{
	size_t		i;

	i = 0;
	if (list == NULL)
		return (NULL);
	while (i != index)
	{
		if (list->next == NULL)
			return (NULL);
		list = list->next;
		i++;
	}
	return (list);
}

size_t			tet_list_length(t_tetriminos *list)
{
	size_t		i;

	i = 0;
	while (list)
	{
		i++;
		list = list->next;
	}
	return (i);
}
