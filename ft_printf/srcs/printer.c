/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 12:22:15 by jdebladi          #+#    #+#             */
/*   Updated: 2017/02/24 11:57:09 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		string_width(char **out, const char *s, t_flag *f, int len)
{
	int pc;

	pc = 0;
	f->preci = len > f->preci ? f->preci : len;
	while (f->width > f->preci)
	{
		printchar(out, ' ');
		--f->width;
		++pc;
	}
	while (*s)
	{
		if (f->preci > 0)
		{
			printchar(out, *s);
			--f->preci;
			++pc;
		}
		s++;
	}
	return (pc);
}

int		string_printer(char **out, const char *s, t_flag *f, int len)
{
	int pc;

	pc = 0;
	if (f->lag_minus)
	{
		while (*s)
		{
			if (f->preci > pc)
			{
				printchar(out, *s);
				++pc;
			}
			s++;
		}
		while (f->width > pc)
		{
			printchar(out, ' ');
			++pc;
		}
	}
	else
		pc += string_width(out, s, f, len);
	return (pc);
}

int		print_width(char **out, const char *s, t_flag *f, int len)
{
	int pc;

	pc = 0;
	while (f->width && f->width > len)
	{
		printchar(out, ' ');
		--f->width;
		pc++;
	}
	while (*s)
	{
		printchar(out, *s++);
		pc++;
	}
	return (pc);
}

int		printer(char **out, const char *s, t_flag *f, int len)
{
	int pc;

	pc = 0;
	if (f->preci != 0 && (f->conv == 's' || f->conv == 'S'))
		pc += string_printer(out, s, f, len);
	else
	{
		if (f->lag_minus)
		{
			while (*s)
			{
				printchar(out, *s++);
				pc++;
			}
			while (f->width > pc)
			{
				printchar(out, ' ');
				++pc;
			}
		}
		else
			pc += print_width(out, s, f, len);
	}
	return (pc);
}
