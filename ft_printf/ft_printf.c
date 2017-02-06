/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 11:33:05 by jdebladi          #+#    #+#             */
/*   Updated: 2017/02/06 17:11:13 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <wchar.h>
#include "includes/Libft.h"

#define BSIZE 32

static void	ftputchar(int c)
{
	write(1, &c, 1);
}

static void	ftputwchar(int c)
{
	write(1, &c, 1);
}

static void	printchar(char **s, int c)
{
	if (s)
	{
		**s = c;
		++(*s);
	}
	else
		(void)ftputchar(c);
}

static void	printwchar(char **s, int c)
{
	if (s)
	{
		**s = c;
		++(*s);
	}
	else
		(void)ftputwchar(c);
}

static char	check_arg(const char *txt)
{
	int i;

	i = 1;
	while (txt[i])
	{
		if ((txt[i] >= 97 && txt[i] <= 'g') || txt[i] == 'i' || txt[i] == 'k' ||
			(txt[i] >= 'n' && txt[i] <= 'p') || txt[i] == 'r' || txt[i] ==
			's' || txt[i] == 'u' || txt[i] == 'x' || txt[i] == 65 || (txt[i]
			>= 67 && txt[i] <= 71) || txt[i] == 79 || txt[i] == 83 || txt[i]
			== 85 || txt[i] == 88)
			return (txt[i]);
		else if (txt[i] == '#' || txt[i] == '$' || txt[i] == '*' || txt[i] ==
				'+' || txt[i] == '-' || txt[i] == '0' || txt[i] == 'L' || txt[i]
				== 39 || txt[i] == 'h' || txt[i] == 'l' || txt[i] == 'j' || txt
				[i] == 'z' || txt[i] == ' ')
			i++;
		else
			return ('0');
	}
	return ('0');
}

char		*count_arg(const char *txt)
{
	int		i;
	int		j;
	int		arg;
	char	*t;

	i = 0;
	j = 0;
	arg = 0;
	t = ft_strnew(1);
	while (txt[i])
	{
		if (txt[i] == '%')
		{
			if (check_arg(&txt[i]) != '0')
			{
				t = ft_strrealloc(t, 1);
				t[j] = check_arg(&txt[i]);
				j++;
			}
		}
		i++;
	}
	return (t);
}

static int	wprints(char **out, const wchar_t *s, int width, int pad)
{
	int				pc;
	int				len;
	int				padchar;
	const wchar_t	*ptr;

	pc = 0;
	padchar = ' ';
	if (width > 0)
	{
		len = 0;
		ptr = s;
		while (*ptr)
		{
			++len;
			++ptr;
		}
		if (len >= width)
			width = 0;
		else
			width -= len;
		if (pad & 2)
			padchar = '0';
	}
	if (!(pad & 1))
	{
		while (width > 0)
		{
			printwchar(out, padchar);
			++pc;
			--width;
		}
	}
	while (*s)
	{
		printwchar(out, *s);
		++pc;
		++s;
	}
	while (width > 0)
	{
		printwchar(out, padchar);
		++pc;
		--width;
	}
	return (pc);
}

static int	prints(char **out, const char *s, int width, int pad)
{
	int			pc;
	int			len;
	int			padchar;
	const char	*ptr;

	pc = 0;
	padchar = ' ';
	if (width > 0)
	{
		len = 0;
		ptr = s;
		while (*ptr)
		{
			++len;
			++ptr;
		}
		if (len >= width)
			width = 0;
		else
			width -= len;
		if (pad & 2)
			padchar = '0';
	}
	if (!(pad & 1))
	{
		while (width > 0)
		{
			printchar(out, padchar);
			++pc;
			--width;
		}
	}
	while (*s)
	{
		printchar(out, *s);
		++pc;
		++s;
	}
	while (width > 0)
	{
		printchar(out, padchar);
		++pc;
		--width;
	}
	return (pc);
}

static int	printi(char **out, int i, int b, int sg, int width, int pad, int letb)
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
		buf[0] = '0';
		buf[1] = '\0';
		return (prints(out, buf, width, pad));
	}
	if (sg && b == 10 && i < 0)
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
			j += letb - '0' - 10;
		*--s = j + '0';
		u /= b;
	}
	if (neg)
	{
		if (width && (pad & 2))
		{
			printchar(out, '-');
			++pc;
			--width;
		}
		else
			*--s = '-';
	}
	return (pc + prints(out, s, width, pad));
}

static int		print(char **out, const char *format, va_list args)
{
	int		width;
	int		pad;
	int		pc;
	char	*s;
	char	scr[2];
	wchar_t	wscr[2];

	pc = 0;
	while (*format != 0)
	{
		if (*format == '%')
		{
			++format;
			width = 0;
			pad = 0;
			if (*format == '\0')
				break ;
			if (*format == '%')
				goto out;
			if (*format == '-')
			{
				++format;
				pad = 1;
			}
			while (*format == '0')
			{
				++format;
				pad |= 2;
			}
			while (*format >= '0' && *format <= '9')
			{
				width *= 10;
				width += *format - '0';
				++format;
			}
			if (*format == 's')
			{
				s = (char *)va_arg(args, char *);
				pc += prints(out, s ? s : "(null)", width, pad);
			}
			if (*format == 'd' || *format == 'i' || *format == 'D')
				pc += printi(out, va_arg(args, int), 10, 1, width, pad, 'a');
			if (*format == 'u' || *format == 'U')
				pc += printi(out, va_arg(args, int), 10, 0, width, pad, 'a');
			if (*format == 'x' || *format == 'X')
				pc += printi(out, va_arg(args, int), 16, 0, width, pad, *format - 23);
			if (*format == 'o' || *format == 'O')
				pc += printi(out, va_arg(args, int), 8, 0, width, pad, 'a');
			if (*format == 'b')
				pc += printi(out, va_arg(args, int), 2, 0, width, pad, 'a');
			if (*format == 'c')
			{
				scr[0] = (char)va_arg(args, int);
				scr[1] = '\0';
				pc += prints(out, scr, width, pad);
			}
			if (*format == 'C')
			{
				wscr[0] = (wchar_t)va_arg(args, int);
				wscr[1] = '\0';
				pc += wprints(out, wscr, width, pad);
			}
		}
		else
		{
			out:
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
	return (print(0, format, args));
}

int			s_printf(char *out, const char *format, ...)
{
	va_list args;

	va_start(args, format);
	return print(&out, format, args);
}

int			main(void)
{
	char			*ptr = "Hello world!";
	char			*np = 0;
	int				i = 5;
	unsigned int	bs = sizeof(int)*8;
	int				mi;
	char			buf[80];

	mi = (1 << (bs-1)) + 1;
	ft_printf("%s\n", ptr);
	ft_printf("printf test\n");
	ft_printf("%s is null pointer\n", np);
	printf("test\n");
	ft_printf("%d = 5\n", i);
	printf("test\n");
	ft_printf("%d = -max int\n", mi);
	ft_printf("char %c = 'a'\n", 'a');
	ft_printf("hex %x = ff\n", 0xff);
	ft_printf("hex %X = FF\n", 0xff);
	ft_printf("j'y crois tellement pas : %C = î\n", 238);
	ft_printf("oct %o = 144\n", 100);
	ft_printf("hex %02x = 00\n", 0);
	ft_printf("bin %b = 1100100\n", 100);
	ft_printf("signed %d = unsigned %u = hex %x\n", -3, -3, -3);
	ft_printf("%d %s(s)%", 0, "message");
	ft_printf("%0d\n", 0);
	ft_printf("\n");
	ft_printf("%d %s(s) with %%\n", 0, "message");
	s_printf(buf, "justif: \"%-10s\"\n", "left"); ft_printf("%s", buf);
	s_printf(buf, "justif: \"%10s\"\n", "right"); ft_printf("%s", buf);
	s_printf(buf, " 3: %04d zero padded\n", 3); ft_printf("%s", buf);
	s_printf(buf, " 3: %-4d left justif.\n", 3); ft_printf("%s", buf);
	s_printf(buf, " 3: %4d right justif.\n", 3); ft_printf("%s", buf);
	s_printf(buf, "-3: %04d zero padded\n", -3); ft_printf("%s", buf);
	s_printf(buf, "-3: %-4d left justif.\n", -3); ft_printf("%s", buf);
	s_printf(buf, "-3: %4d right justif.\n", -3); ft_printf("%s", buf);
	return (0);
}

/*int			main()
  {
  int i;

  const char *s = "%a%A %c%C %d%D %e%E %f%F %g%G %i %n %o%O %p %s%S %u%U
  \n%x%X # $ * + - 0 %L ' hh[] ha l ll j z %b %r %k";
  char *t;

  setlocale(LC_ALL, "POSIX");
  t = count_arg(s);
  i = ft_strlen(t);
  ft_putnbr(i);
  write(1, " ", 1);
  return 0;
  }
  */
