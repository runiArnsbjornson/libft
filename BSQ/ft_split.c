/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 11:25:32 by jdebladi          #+#    #+#             */
/*   Updated: 2016/09/09 13:59:34 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen1(char *str)
{
	int n;

	n = 0;
	while (*str != ' ' && *str <= '\t' && *str >= '\r' && *str != '\0')
	{
		n++;
		str++;
	}
	return (n);
}

int		ft_n_words(char *str)
{
	int n;

	n = 0;
	if (*str == '\0')
		return (0);
	while (*str == ' ' && *str >= '\t' && *str <= '\r' && *str != '\0')
		str++;
	while (*str != '\0')
	{
		while (*str != ' ' && *str <= '\t' && *str >= '\r' && *str != '\0')
			str++;
		while (*str == ' ' && *str >= '\t' && *str <= '\r' && *str != '\0')
			str++;
		n++;
	}
	return (n);
}

char	**ft_split_whitespaces(char *str)
{
	int		l;
	int		j;
	int		n;
	char	**tab;
	char	**paragraphe;

	n = ft_n_words(str);
	paragraphe = malloc(sizeof(char*) * n + 1);
	tab = paragraphe;
	while (str)
	{
		while (*str != '\0' && *str != ' ' && *str <= '\t' && *str >= '\r')
			str++;
		l = ft_strlen1(str);
		paragraphe = malloc(sizeof(char) * (l + 1));
		j = 0;
		if (*str != '\0')
		{
			while (j < l)
				(*paragraphe)[j++] = *str++;
			(*paragraphe++)[l] = '\0';
		}
	}
	*paragraphe = 0;
	return (tab);
}
