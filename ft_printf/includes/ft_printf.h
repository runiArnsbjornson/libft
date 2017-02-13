/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 13:44:10 by jdebladi          #+#    #+#             */
/*   Updated: 2017/02/13 18:58:31 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <wchar.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <fcntl.h>
#include "libft.h"

#define BUFF_SIZE2 4096
#define BSIZE 32

typedef struct  s_flag
{
	int				lag_h;
	int				lag_hh;
	int				lag_l;
	int				lag_ll;
	int				lag_j;
	int				lag_z;
	int				lag_htag;
	int				lag_zero;
	int				lag_minus;
	int				lag_plus;
	int				lag_space;
	int				lag_dot;
}               t_flag;

typedef struct	s_con
{
	int				width;
	int				pad;
	int				preci;
	int				type;
	int				sign;
	char			start;
}				t_con;

/*
**	handlers
*/
int		printi(char **out, int i, int b, t_con *version);
int		printl(char **out, long i, int b, t_con *version);
int		printll(char **out, long long i, int b, t_con *version);
int		prints(char **out, const char *s, t_con *version);
int		printls(char **out, const wchar_t *s, t_con *version);
char 	*utf8_convert(char *buf, size_t buf_size, int code);

/*
**	printers
*/

void	printchar(char **s, int c);


#endif
