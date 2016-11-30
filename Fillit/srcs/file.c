/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:14:08 by cfrouin           #+#    #+#             */
/*   Updated: 2016/11/28 13:16:35 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void				open_error_display(void)
{
	if (errno == EACCES)
		ft_putstr("Access denied\n");
	else if (errno == EFAULT)
		ft_putstr("Path not accessible\n");
	else if (errno == ENAMETOOLONG)
		ft_putstr("Pathname too long\n");
	else if (errno == ENOENT)
		ft_putstr("File does not exist\n");
	else
		ft_putstr("Error while opening file at path\n");
}

t_tetriminos		*new_content(int fd, int i)
{
	int				j;
	t_tetriminos	*tetr;
	char			buf[5];

	j = 0;
	if ((tetr = malloc(sizeof(t_tetriminos))) == NULL)
		return (NULL);
	tetr->next = NULL;
	j = 0;
	while (j < 4)
	{
		if (read(fd, buf, 5) == 0 || buf[4] != '\n')
		{
			free(tetr);
			return (NULL);
		}
		ft_strncpy(tetr->shape[j++], buf, 4);
	}
	if (check_tetriminos(tetr) == -1)
	{
		free(tetr);
		return (NULL);
	}
	tetr->letter = (char)i + 'A';
	return (tetr);
}

t_tetriminos		*check_content(int fd)
{
	int				i;
	char			buf[5];
	t_tetriminos	*tetr;
	t_tetriminos	*list;

	list = NULL;
	i = -1;
	while (++i < 26)
	{
		if ((tetr = new_content(fd, i)) == NULL)
		{
			tet_list_destroy(list);
			return (NULL);
		}
		tet_size(tetr);
		if (i == 0)
			list = tetr;
		else
			tet_list_pushback(list, tetr);
		if (read(fd, buf, 1) == 0)
			return (list);
		if (i >= 25 || buf[0] != '\n')
			return (NULL);
	}
	return (list);
}

int					open_file(char *filename)
{
	int				fd;

	if ((fd = open(filename, O_RDONLY)) == -1)
	{
		open_error_display();
		return (-1);
	}
	return (fd);
}

t_tetriminos		*check_file(char *filename)
{
	int				fd;
	t_tetriminos	*list;

	if ((fd = open(filename, O_RDONLY)) == -1)
	{
		open_error_display();
		return (NULL);
	}
	if ((list = check_content(fd)) == NULL)
	{
		close(fd);
		tet_list_destroy(list);
		return (NULL);
	}
	close(fd);
	return (list);
}
