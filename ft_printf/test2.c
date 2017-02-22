/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 17:22:53 by jdebladi          #+#    #+#             */
/*   Updated: 2017/02/22 17:52:04 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <locale.h>
#include <stdio.h>
#include <wchar.h>

int		ft_printf(const char *format, ...);

int main(void)
{
	setlocale(LC_ALL, "");
	printf("%.05d\n", 7);
	ft_printf("  12  %12lhh3 .5  l X", 7);
	wprintf(L"Hello, Olá, ¡Hola!, Здравствуйте!, 안녕, 今日は<<\n=====\n");
	return 0;
}
