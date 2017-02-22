/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 12:16:10 by jdebladi          #+#    #+#             */
/*   Updated: 2017/02/22 15:18:14 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/ft_printf.h"

int	printi(char **out, int i, int base, t_flag *vert)
{
	char			buf[BSIZE];
	char			*s;
	int				pc;
	unsigned int	u;

	u = i;
	pc = 0;
	if (i == 0)
		return (prints(out, "0", vert));
	if (vert->sign && base == 10 && i < 0)
		u = -i;
	s = buf + BUFF_SIZE - 1;
	*s = '\0';
	while (u)
	{
		*--s = (u % base >= 10) ? u % base + vert->start - 10 : u % base + '0';
		u /= base;
	}
	if (vert->sign && base == 10 && i < 0)
	{
		if (vert->width && (vert->pad & 2))
		{
			printchar(out, '-');
			++pc;
			--vert->width;
		}
		else
			*--s = '-';
	}
	return (pc + prints(out, s, vert));
}
