/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 16:38:40 by jdebladi          #+#    #+#             */
/*   Updated: 2016/09/20 16:53:44 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

# define BUFF_SIZE 16384

typedef struct	s_bsq
{
	char	*grid;
	char	*first_line;
	int		sqr_max;
	int		sqr_row;
	int		sqr_col;
	int		nb_line;
}				t_bsq;

int				ft_strlen(char *str);
int				ft_is_numeric(int c);
int				ft_gnl(int fd, char **grid);
int				ft_atoi(char *str);
char			*ft_stralloc(unsigned int size);
char			*ft_strcut(const char *str, int begin, int len);
char			*ft_strdup(char *src);
char			*ft_strunion(char *str1, char *str2);
void			ft_putstr(char *str);
void			ft_puterror(char *str);
void			ft_putchar(char c);
void			ft_display_grid(int *grid, t_bsq *data);
void			ft_resolve(t_bsq *data, int fd);

#endif
