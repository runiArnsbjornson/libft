/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wprinter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 00:59:13 by jdebladi          #+#    #+#             */
/*   Updated: 2017/02/24 16:39:11 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		wcharlen(wchar_t *wc)
{
	char	*bin;
	int		len;
	int		nb_bytes;

	nb_bytes = 0;
	while(*wc)
	{
		bin = ft_itoa_base(*wc, 2);
		len = ft_strlen(bin);
		if (len <= 7)
			nb_bytes += 1;
		else if (len > 7 && len <= 11)
			nb_bytes += 2;
		else if (len > 11 && len <= 16)
			nb_bytes += 3;
		else
			nb_bytes += 4;
	}
	return (nb_bytes);
}

int		wcharlen(wchar_t wc)
{
	char	*bin;
	int		bin_len;

	bin = ft_itoa_base(wc, 2);
	bin_len = ft_strlen(bin);
	if (bin_len <= 7)
		return (1);
	else if (bin_len > 7 && bin_len <= 11)
		return (2);
	else if (bin_len > 11 && bin_len <= 16)
		return (3);
	else
		return (4);
}

int		wprint_minus(char **out, const wchar_t *ls, t_flag *f, int len)
{
	int		pc;
	char	buf[8];
	char	*uchar;

	pc = 0;
	while (len)
	{
		uchar = utf8_convert(buf, 8, *ls);
		write(1, uchar, ft_strlen(uchar));
		pc++;
		ls++;
		len--;
	}
	while (f->width > pc)
	{
		printchar(out, ' ');
		pc++;
	}
	return (pc);
}

int		wprinter(char **out, const wchar_t *ls, t_flag *f, int len)
{
	int		pc;
	char	buf[8];
	char	*uchar;

	pc = 0;
	if (f->lag_minus)
		pc += wprint_minus(out, ls, f, len);
	else
	{
		while (f->width >= len)
		{
			printchar(out, ' ');
			f->width--;
			pc++;
		}
		while (len)
		{
			uchar = utf8_convert(buf, 8, *ls);
			write(1, uchar, ft_strlen(uchar));
			pc++;
			ls++;
			len--;
		}
	}
	return (pc);
}
