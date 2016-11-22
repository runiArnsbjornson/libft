/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 19:53:17 by jdebladi          #+#    #+#             */
/*   Updated: 2016/09/21 23:34:50 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	**ft_fill_tab(char *str, char **tab)
{
	int	n;
	int	n_char;
	int	n_word;

	n = 0;
	n_word = 0;
	while (str[++n] != '\0')
	{
		while (str[n] == ' ' || (str[n] >= '\t' && str[n] <= '\r'))
			++n;
		if (str[n] == '\0')
			return (tab);
		n_char = -1;
		--n;
		if (n == 0)
			--n;
		while (str[++n] != ' ' && str[n] != '\t' && str[n] != '\v' && str[n]
				!= '\f' && str[n] != '\r' && str[n] != '\n' && str[n] != '\0')
			tab[n_word][++n_char] = str[n];
		tab[n_word][n_char + 1] = '\0';
		++n_word;
		if (str[n] == '\0')
			--n;
	}
	return (tab);
}

char	**ft_alloc_tab(char *str, char **tab)
{
	int	n;
	int	n_char;
	int	n_word;

	n = -1;
	n_word = 0;
	while (str[++n] != '\0')
	{
		n_char = 0;
		while (str[n] == ' ' || (str[n] >= '\t' && str[n] <= '\r'))
		{
			++n_char;
			++n;
		}
		while ((n_char != 0 || n == 0) && str[n] != '\0')
		{
			tab[n_word] = malloc((n_char + 1) * sizeof(char));
			if (tab[n_word] == NULL)
				return (NULL);
			++n_word;
		}
	}
	return (tab);
}

char	**ft_split_whitespaces(char *str)
{
	char	**tab;
	int		n;
	int		len_tab;

	len_tab = 1;
	n = -1;
	if (!str)
		return (NULL);
	while (str[++n] != '\0')
		if (str[n] == ' ' || (str[n] >= '\t' && str[n] <= '\r'))
		{
			while (str[n] == ' ' || (str[n] >= '\t' && str[n] <= '\n'))
				++n;
			if (str[n] != '\0')
				++len_tab;
		}
	if (len_tab == 1)
		return (NULL);
	if ((tab = malloc((len_tab + 1) * sizeof(char *))) == NULL)
		return (NULL);
	tab = ft_alloc_tab(str, tab);
	tab = ft_fill_tab(str, tab);
	tab[len_tab] = NULL;
	return (tab);
}
