/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 19:24:50 by jdebladi          #+#    #+#             */
/*   Updated: 2017/02/24 06:37:54 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		char_handler(char **out, va_list args, t_flag *f)
{
	char	scr[2];
	char	wscr[8];
	char	*uchar;
	int		zero;

	if (ft_isupper(f->conv) == 1)
		f->lag_l = 1;
	if (f->lag_l == 1)
	{
		uchar = utf8_convert(wscr, 8, va_arg(args, wchar_t));
		return (printer(out, uchar, f, ft_strlen(uchar)));
	}
	else
	{
		scr[0] = (char)va_arg(args, int);
		scr[1] = 0;
		zero = scr[0] == 0 ? 1 : 0;
		return (printer(out, scr, f, 1) + zero);
	}
}
