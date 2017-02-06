/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 11:59:52 by jdebladi          #+#    #+#             */
/*   Updated: 2017/01/30 11:14:57 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/fdf.h"

int main(int ac, char const **av)
{
    int     i;
    int     fd;
    int     line_len;
    char    **tab;
    char    **line = NULL;
    t_line  *tmp;

    i = 1;
    while (i < ac)
    {
        if ((fd = open(av[i], O_RDONLY)) < 0)
            return (0);
        read(fd, line, BUFF_SIZE2 + 1);
        tmp = malloc(sizeof(t_line));
        while (get_next_line(fd, line))
        {
            line_len = ft_strlen(line);
            while (line_len)
            {
                t_line->line = ft_atoi()
                tab[i] = ft_strsplit(line, ' ');
            }
        }
    }
    return (0);
}
