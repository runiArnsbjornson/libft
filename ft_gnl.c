/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 12:39:20 by jdebladi          #+#    #+#             */
/*   Updated: 2017/05/08 12:53:32 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_lst	*find_init(t_lst *lst, int fd)
{
	t_lst	*temp2;

	if (lst == NULL)
	{
		lst = malloc(sizeof(t_lst));
		lst->temp = NULL;
		lst->deb = lst;
		lst->next = NULL;
		lst->fd = fd;
		return (lst);
	}
	lst = lst->deb;
	while (lst != NULL && lst->fd != fd)
	{
		temp2 = lst;
		lst = lst->next;
	}
	if (lst == NULL)
	{
		lst = find_init(lst, fd);
		temp2->next = lst;
	}
	return (lst);
}

static int		sup_lst(t_lst *lst)
{
	t_lst *tmp;

	tmp = lst->deb;
	if (tmp->next == lst)
		tmp->next = lst->next;
	while (tmp->next != lst && tmp->next != NULL)
		tmp = tmp->next;
	if (tmp->next == lst)
		tmp->next = lst->next;
	free(lst->temp);
	free(lst);
	return (1);
}

static	int		condition(t_lst *lst, char **line, char buff[BUFF_SIZE + 1])
{
	char	*cara;
	char	*tempo;

	if (lst->temp)
	{
		cara = ft_strchr(lst->temp, '\n');
		if (cara != NULL)
		{
			*line = ft_strsub(lst->temp, 0, cara - lst->temp);
			tempo = ft_strdup(cara + 1);
			free(lst->temp);
			lst->temp = tempo;
			return (1);
		}
		else
		{
			tempo = ft_strjoin(lst->temp, buff);
			free(lst->temp);
			lst->temp = tempo;
		}
	}
	if (lst->temp == NULL)
		lst->temp = ft_strdup(buff);
	return (0);
}

static int		end_file(t_lst *lst, char **line)
{
	*line = lst->temp;
	if (lst->temp[0] == '\0')
		return (0);
	lst->temp = NULL;
	return (1);
}

int				ft_gnl(const int fd, char **line)
{
	int				r;
	char			buff[BUFF_SIZE + 1];
	static t_lst	*lst_first;
	t_lst			*lst;

	if (read(fd, &buff, 0) == -1 || line == NULL)
		return (-1);
	if (lst_first == NULL)
		lst_first = find_init(lst_first, (int)fd);
	lst = find_init(lst_first, (int)fd);
	r = 1;
	while (r)
	{
		ft_bzero((void*)&buff, BUFF_SIZE + 1);
		if (condition(lst, line, buff) == 1)
			return (1);
		r = read(fd, &buff, BUFF_SIZE);
		if (r == -1)
			return (-1);
		condition(lst, line, buff);
	}
	if ((r == 0 && lst->temp))
		return (end_file(lst, line));
	sup_lst(lst);
	return (0);
}
