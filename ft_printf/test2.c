/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 17:22:53 by jdebladi          #+#    #+#             */
/*   Updated: 2017/02/24 16:09:28 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <locale.h>
#include <stdio.h>
#include <wchar.h>

int		ft_printf(const char *format, ...);

int		main(void)
{
	int i;
	setlocale(LC_ALL, "");
	// i = printf("%S", L"Á±≥");
	i = ft_printf("%S", L"Á±≥");
	printf("\n>%d<\n", i);
	return 0;
}
