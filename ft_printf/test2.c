/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 17:22:53 by jdebladi          #+#    #+#             */
/*   Updated: 2017/02/13 18:37:09 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <locale.h>
#include <stdio.h>
#include <wchar.h>

int		ft_printf(const char *format, ...);

int main(void)
{
	int prout;

	prout = 162;

setlocale(LC_ALL, "");
	printf("%X\n", prout);
	ft_printf("%X\n\n", prout);

	printf("u= >>%ls<<\n", L"bhb∑∑`œ∑¨®˜∫");
	ft_printf("ft >>%ls<\n\n", L"bhb∑∑`œ∑¨®˜∫");

	printf("u= >>%llx<<\n", 4294967296);
	ft_printf("ft >>%llx<<\n\n", 4294967296);

	printf("u= >>%lx<<\n", -4294967296);
	ft_printf("ft >>%lx<<\n\n", -4294967296);

	printf("u= >>%jx<<\n", -4294967297);
	ft_printf("ft >>%jx<<\n\n", -4294967297);

	printf("u= >>%h -43d}<<\n", 42);
	ft_printf("ft >>%h -43d}<<\n\n", 42);

	printf("u= >>%p<<\n", printf);
	ft_printf("ft >>%p<<\n\n", printf);

	printf("u= >>%C<<\n", L'é');
	ft_printf("ft >>%C<<\n\n", L'é');

	printf("u= >>%S<<\n", L"∑n¬été");
	ft_printf("ft >>%S<<\n\n", L"∑n¬été");

	printf("u= >>%hhld<<\n", "128");
	ft_printf("ft >>%hhld<<\n\n", "128");

	wprintf(L"Hello, Olá, ¡Hola!, Здравствуйте!, 안녕, 今日は<<\n=====================================\n");
	return 0;
}
