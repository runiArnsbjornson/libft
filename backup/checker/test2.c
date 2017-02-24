/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 17:22:53 by jdebladi          #+#    #+#             */
/*   Updated: 2017/02/24 14:15:21 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <locale.h>
#include <stdio.h>
#include <wchar.h>

int		ft_printf(const char *format, ...);

int main(void)
{
	// int i = 1;
	// char	*un = "hello";
	// char	*deux = NULL;
	// char	*trois = "";
	// wchar_t *n = L"Hello, Olá, ¡Hola!, Здравствуйте!, 안녕, 今日は";
	//
	// setlocale(LC_ALL, "");
	// printf("u : >%67ls<\n", n);
	// ft_printf("ft: >%67ls<\n", n);
	//
	// wprintf(L"Hello, Olá, ¡Hola!, Здравствуйте!, 안녕, 今日は<<<\n=====<\n");
	ft_printf("f>%015u<\n", "4294967295");
	printf("u>%015u<\n", "4294967295");
	ft_printf("f>@moulitest: %.5u<\n", "42");
	printf("u>@moulitest: %.5u<\n", "42");
	return 0;
}
