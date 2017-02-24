/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 19:52:03 by jdebladi          #+#    #+#             */
/*   Updated: 2017/02/24 16:36:58 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t	ft_wcslen(const wchar_t *s)
{
	const wchar_t *p;

	p = s;
	while (*p)
		p++;
	return (p - s);
}

int		wstrlen(wchar_t *ws)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (ws[i] != '\0')
	{
		len += wcharlen(ws[i]);
		i++;
	}
	return (len);
}

int		string_handler(char **out, va_list args, t_flag *f)
{
	char	*s;
	wchar_t	*ls;

	if (ft_isupper(f->conv) == 1)
		f->lag_l = 1;
	if (f->lag_l)
	{
		ls = va_arg(args, wchar_t *);
		if (ls != NULL)
			return (wprinter(out, ls, f, ft_wcslen(ls)));
	}
	else
	{
		s = (char *)va_arg(args, char *);
		if (s != NULL)
			return (printer(out, s, f, ft_strlen(s)));
	}
	f->width += f->lag_space == 1 ? 1 : 0;
	return (printer(out, "(null)", f, 6));
}
