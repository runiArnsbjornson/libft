/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 13:44:10 by jdebladi          #+#    #+#             */
/*   Updated: 2017/02/24 15:48:08 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <locale.h>
# include <stdlib.h>
# include <wchar.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include "libft.h"

# define BUFF_SIZE2 4096
# define BSIZE 32

typedef struct		s_flag
{
	int				len;
	int				lag_h;
	int				lag_hh;
	int				lag_l;
	int				lag_ll;
	int				lag_j;
	int				lag_z;
	int				lag_dot;
	int				lag_htag;
	int				lag_zero;
	int				lag_minus;
	int				lag_plus;
	int				lag_space;
	int				width;
	int				preci;
	int				sign;
	int				i;
	char			conv;
	char			start;
}					t_flag;

int					char_handler(char **out, va_list args, t_flag *f);
int					dec_handler(char **out, va_list args, t_flag *f);
int					oct_handler(char **out, va_list args, t_flag *f);
int					hex_handler(char **out, va_list args, t_flag *f);
int					percent_handler(char **out, t_flag *f);
int					string_handler(char **out, va_list args, t_flag *f);
char				*utf8_convert(char *buf, size_t buf_size, int code);
int					zero_fill(char *buf, int i, t_flag *f, int len);
long long			int_size(long long n, va_list args, t_flag *f);
unsigned long long	uint_size(unsigned long long n, va_list args, t_flag *f);
int					printer(char **out, const char *s, t_flag *f, int len);
int					wprinter(char **out, const wchar_t *ls, t_flag *f, int len);
void				printchar(char **s, int c);
void				wprintchar(char **s, int c);
void				search(const char *fmt, t_flag *f, int i);
void				get(const char *fmt, t_flag *f, int i);

#endif
