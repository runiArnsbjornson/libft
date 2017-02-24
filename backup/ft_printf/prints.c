/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 12:22:15 by jdebladi          #+#    #+#             */
/*   Updated: 2017/02/24 00:59:32 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/ft_printf.h"

void	printchar(char **s, int c)
{
	if (s)
	{
		**s = c;
		++(*s);
	}
	else
		(void)ft_putchar(c);
}

int	prints(char **out, const char *s, t_flag *version)
{
	int			pc;
	int			len;
	int			padchar;
	const char	*ptr;

	pc = 0;
	padchar = ' ';
	if (version->width > 0)
	{
		len = 0;
		ptr = s;
		while (*ptr)
		{
			++ptr;
			++len;
		}
		if (len >= version->width)
			version->width = 0;
		else
			version->width -= len;
		if (version->pad & 2)
			padchar = '0';
	}
	if (!(version->pad & 1))
	{
		while (version->width > 0)
		{
			printchar(out, padchar);
			++pc;
			--version->width;
		}
	}
	while (*s)
	{
		printchar(out, *s);
		++pc;
		++s;
	}
	while (version->width > 0)
	{
		printchar(out, padchar);
		++pc;
		--version->width;
	}
	return (pc);
}
