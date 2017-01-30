/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 17:22:59 by jdebladi          #+#    #+#             */
/*   Updated: 2017/01/30 17:23:54 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>

int	main(void)
{
	wchar_t test;

	setlocale(LC_ALL, "");
	wprintf(L"Caract%lcre : ", 232);
	fgetws(&test, 2, stdin);
	wprintf(L"Caract%lcre %lc = %d\n", 232, test, test);
	return (0);
}
