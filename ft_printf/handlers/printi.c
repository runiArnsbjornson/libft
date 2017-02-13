/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 12:16:10 by jdebladi          #+#    #+#             */
/*   Updated: 2017/02/13 19:02:20 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/ft_printf.h"

int	printi(char **out, int i, int b, t_con *version)
{
	char			buf[BSIZE];
	char			*s;
	int				j;
	int				pc;
	int				neg;
	unsigned int	u;

	u = i;
	pc = 0;
	neg = 0;
	if (i == 0)
	{
		return (prints(out, "0", version));
	}
	if (version->sign && b == 10 && i < 0)
	{
		neg = 1;
		u = -i;
	}
	s = buf + BUFF_SIZE - 1;
	*s = '\0';
	while (u)
	{
		j = u % b;
		if (j >= 10)
			j += version->start - '0' - 10;
		*--s = j + '0';
		u /= b;
	}
	if (neg)
	{
		if (version->width && (version->pad & 2))
		{
			printchar(out, '-');
			++pc;
			--version->width;
		}
		else
			*--s = '-';
	}
	return (pc + prints(out, s, version));
}
