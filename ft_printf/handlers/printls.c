/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printls.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 12:59:40 by jdebladi          #+#    #+#             */
/*   Updated: 2017/02/13 18:58:15 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/ft_printf.h"

int printls(char **out, const wchar_t *s, t_con *version)
{
	int				pc;
	int				len;
	int				padchar;
	const wchar_t	*ptr;
	char			*uchar;
	char			scr[8];

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
		version->width = (len >= version->width) ? 0 : version->width - len;
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
		uchar = utf8_convert(scr, 8, *s);
		pc += prints(out, uchar, version);
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
