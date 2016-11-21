/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:41:15 by jdebladi          #+#    #+#             */
/*   Updated: 2016/11/04 16:24:23 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "need.h"

void	ft_putstr(char *str, int ss)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	write(ss, str, i);
}

int		ft_display(char *file)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE + 1];

	if ((fd = open(file, O_RDONLY)) == -1)
		return (3);
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		ft_putstr(buf, 1);
	}
	if (close(fd) == -1)
		return (4);
	return (0);
}

int		main(int ac, char **av)
{
	if (ac == 1)
	{
		ft_putstr("File name missing.\n", 2);
		return (0);
	}
	if (ac > 2)
	{
		ft_putstr("Too many arguments.\n", 2);
		return (2);
	}
	else
		ft_display(av[1]);
	return (0);
}
