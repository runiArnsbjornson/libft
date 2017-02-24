/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 11:33:05 by jdebladi          #+#    #+#             */
/*   Updated: 2017/02/24 05:54:24 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		zero_struct(t_flag *f)
{
	f->len = 0;
	f->lag_h = 0;
	f->lag_hh = 0;
	f->lag_l = 0;
	f->lag_ll = 0;
	f->lag_j = 0;
	f->lag_z = 0;
	f->lag_dot = 0;
	f->lag_htag = 0;
	f->lag_zero = 0;
	f->lag_minus = 0;
	f->lag_plus = 0;
	f->lag_space = 0;
	f->width = 0;
	f->preci = 0;
	f->sign = 0;
	f->pad = ' ';
	f->conv = 0;
	f->start = 'a';
}

/*static int		parse(char **out, const char *format, va_list args)
{
	int		pc;
	char	*s;
	wchar_t	*ls;
	char	scr[2];
	char	wscr[8];
	char	*uchar;
	t_flag	f;
	t_con	f;

	pc = 0;
	while (*format != 0)
	{
		if (*format == '%')
		{
			zero_struct(&f, &f);
			++format;

			if (*format == '\0')
				break ;
			while (*format == '0')
			{
				++format;
				f.lag_zero =1;
				f.pad |= 2;
			}
			if (*format == '-')
			{
				++format;
				f.lag_minus = 1;
				f.pad = 1;
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
				f.width *= 10;
				f.width += *format - '0';
				++format;
			}
			if (*format == '.')
			{
				++format;
				if (*format < '0' && *format > '9')
					f.preci = 0;
				else
				{
					while (*format >= '0' && *format <= '9')
						{
							f.preci *= 10;
							f.preci += *format - '0';
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
			f.type = (f.lag_hh + f.lag_h + f.lag_l + f.lag_ll);
			if (*format == '%')
				pc += prints(out, "%\0", &f);
			if (*format == 's')
			{
				s = (char *)va_arg(args, char *);
				pc += prints(out, s ? s : "(null)", &f);
			}
			if (*format == 'S')
			{
				ls = (wchar_t *)va_arg(args, wchar_t *);
				pc += printls(out, ls ? ls : L"(null)", &f);
			}
			if (*format == 'd' || *format == 'i')
			{
				f.sign = 1;
				pc += printi(out, va_arg(args, int), 10, &f);
			}
			if (*format == 'D')
			{
				f.sign = 1;
				pc += printl(out, va_arg(args, long), 10, &f);
			}
			if (*format == 'u')
				pc += printi(out, va_arg(args, int), 10, &f);
			if (*format == 'U')
				pc += printl(out, va_arg(args, long), 10, &f);
			if (*format == 'x')
				pc += printi(out, va_arg(args, int), 16, &f);
			if (*format == 'X')
			{
				f.start = 'A';
				pc += printi(out, va_arg(args, int), 16, &f);
			}
			if (*format == 'p')
				pc += printl(out, (long)va_arg(args, void *), 16, &f);
			if (*format == 'o')
				pc += printi(out, va_arg(args, int), 8, &f);
			if (*format == 'O')
				pc += printl(out, va_arg(args, long), 8, &f);
			if (*format == 'b')
				pc += printi(out, va_arg(args, int), 2, &f);
			if (*format == 'c')
			{
				scr[0] = (char)va_arg(args, int);
				scr[1] = '\0';
				pc += prints(out, scr, &f);
			}
			if (*format == 'C')
			{
				uchar = utf8_convert(wscr, 8, va_arg(args, wchar_t));
				pc += prints(out, uchar, &f);
			}
		}
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
}*/

int			ft_handlers(char **out, va_list args, t_flag *f, int pc)
{
	pc = 0;
	if (f->conv == 'o' || f->conv == 'O')
		pc += oct_handler(out, args, f);
	else if (f->conv == 'd' || f->conv == 'i' || f->conv == 'D')
	{
		f->sign = 1;
		pc += dec_handler(out, args, f);
	}
	else if (f->conv == 'u' || f->conv == 'U')
		pc += dec_handler(out, args, f);
	else if (f->conv == 'x' || f->conv == 'X' || f->conv == 'p')
		pc += hex_handler(out, args, f);
	else if (f->conv == 'c' || f->conv == 'C')
		pc += char_handler(out, args, f);
	else if (f->conv == 's' || f->conv == 'S')
		pc += string_handler(out, args, f);
	else if (f->conv == '%')
		pc += percent_handler(out, f);
	return (pc);
}

static int	ft_parse(char **out, const char *fmt, t_flag *f, va_list args)
{
	int pc;
	int i;

	pc = 0;
	i = 0;
	while (fmt[i] && fmt)
	{
		if (fmt[i] == '%')
		{
			zero_struct(f);
			search(&fmt[i], f, 1);
			if (f->conv != 0)
				pc += ft_handlers(out, args, f, pc);
			i += f->len + 1;
		}
		else
		{
			printchar(out, fmt[i]);
			++pc;
		}
		i++;
	}
	va_end(args);
	return (pc);
}

int			ft_printf(const char *format, ...)
{
	va_list	args;
	t_flag	f;

	zero_struct(&f);
	va_start(args, format);
	return (ft_parse(0, format, &f, args));
}
