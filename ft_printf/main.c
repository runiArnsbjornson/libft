/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 11:33:05 by jdebladi          #+#    #+#             */
/*   Updated: 2017/02/13 18:59:50 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "includes/Libft.h"
#include "includes/ft_printf.h"

int				check_conv(const char c)
{
	const char flag[23] = "#.-+ hl*$L'jz0123456789";
	const char conv[22] = "%abcdefgikoprsuxAEFGIX";
	const char lconv[5] = "CDOSU";
	int i;

	i = 0;
	while (i < 23)
		{
			if (i < 23 && c == flag[i])
				return (-1);
			if (i < 22 && c == conv[i])
				return (1);
			if (i < 5 && c == lconv[i])
				return (2);
			i++;
		}
	return (0);
}

void			zero_struct(t_flag *f, t_con *version)
{
	f->lag_h = 0;
	f->lag_hh = 0;
	f->lag_l = 0;
	f->lag_ll = 0;
	f->lag_j = 0;
	f->lag_z = 0;
	f->lag_htag = 0;
	f->lag_zero = 0;
	f->lag_minus = 0;
	f->lag_plus = 0;
	f->lag_space = 0;
	f->lag_dot = 0;
	version->width = 0;
	version->pad = 0;
	version->preci = 0;
	version->type = 0;
	version->sign = 0;
	version->start = 'a';
}

static int		parse(char **out, const char *format, va_list args)
{
	int		width;
	int		pad;
	int		pc;
	char	*s;
	wchar_t	*ls;
	char	scr[2];
	char	wscr[8];
	char	*uchar;
	t_flag	f;
	t_con	version;

	pc = 0;
	while (*format != 0)
	{
		if (*format == '%')
		{
			zero_struct(&f, &version);
			++format;
			width = 0;
			pad = 0;
			if (*format == '\0')
				break ;
			while (*format == '0')
			{
				++format;
				f.lag_zero =1;
				version.pad |= 2;
			}
			if (*format == '-')
			{
				++format;
				f.lag_minus = 1;
				version.pad = 1;
			}
			if (*format == '+')
			{
				++format;
				f.lag_plus = 1;
			}
			while (*format == ' ')
			{
				++format;
				f.lag_space = 1;
			}
			while (*format >= '0' && *format <= '9')
			{
				version.width *= 10;
				version.width += *format - '0';
				++format;
			}
			if (*format == '.')
			{
				++format;
				if (*format < '0' && *format > '9')
					version.preci = 0;
				else
				{
					while (*format >= '0' && *format <= '9')
						{
							version.preci *= 10;
							version.preci += *format - '0';
							++format;
						}
				}
			}
			if (*format == 'z')
			{
				++format;
				f.lag_z = 1;
			}
			if (*format == 'j')
			{
				++format;
				f.lag_j = 1;
			}
			if (*format == 'l')
			{
				++format;
				f.lag_l = 1;
				if (*format == 'l')
				{
					f.lag_ll = 1;
					++format;
				}
			}
			if (*format == 'h')
			{
				++format;
				f.lag_h = -1;
				if (*format == 'h')
				{
					f.lag_hh = -1;
					++format;
				}
			}
			if (*format == '#')
			{
				++format;
				f.lag_htag = 1;
			}
			//printf("check_conv(%c) = %d\n", *format, check_conv(*format));
			version.type = (f.lag_hh + f.lag_h + f.lag_l + f.lag_ll);
			//printf("version.type = %d\n", version.type);
/*
**	end of flags &&
**	start of conversion
*/
			if (*format == '%')
			{
				scr[0] = '%';
				scr[1] = '\0';
				pc += prints(out, scr, &version);
			}
			if (*format == 's')
			{
				s = (char *)va_arg(args, char *);
				pc += prints(out, s ? s : "(null)", &version);
			}
			if (*format == 'S')
			{
				ls = (wchar_t *)va_arg(args, wchar_t *);
				pc += printls(out, ls ? ls : L"(null)", &version);
			}
			if (*format == 'd' || *format == 'i')
			{
				version.sign = 1;
				pc += printi(out, va_arg(args, int), 10, &version);
			}
			if (*format == 'D')
			{
				version.sign = 1;
				pc += printl(out, va_arg(args, long), 10, &version);
			}
			if (*format == 'u')
				pc += printi(out, va_arg(args, int), 10, &version);
			if (*format == 'U')
				pc += printl(out, va_arg(args, long), 10, &version);
			if (*format == 'x')
				pc += printi(out, va_arg(args, int), 16, &version);
			if (*format == 'X')
			{
				version.start = 'A';
				pc += printi(out, va_arg(args, int), 16, &version);
			}
			if (*format == 'p')
				pc += printl(out, (long)va_arg(args, void *), 16, &version);
			if (*format == 'o')
				pc += printi(out, va_arg(args, int), 8, &version);
			if (*format == 'O')
				pc += printl(out, va_arg(args, long), 8, &version);
			if (*format == 'b')
				pc += printi(out, va_arg(args, int), 2, &version);
			if (*format == 'c')
			{
				scr[0] = (char)va_arg(args, int);
				scr[1] = '\0';
				pc += prints(out, scr, &version);
			}
			if (*format == 'C')
			{
				uchar = utf8_convert(wscr, 8, va_arg(args, wchar_t));
				pc += prints(out, uchar, &version);
			}
		}
/*
**	other char
*/
		else
		{
			printchar(out, *format);
			++pc;
		}
		format++;
	}
	if (out)
		**out = '\0';
	va_end(args);
	return (pc);
}

int			ft_printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);
	return (parse(0, format, args));
}
