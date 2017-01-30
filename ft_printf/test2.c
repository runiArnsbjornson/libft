/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 17:22:53 by jdebladi          #+#    #+#             */
/*   Updated: 2017/01/30 17:48:23 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <locale.h>
#include <stdio.h>
#include <wchar.h>

int     main(void)
{
    setlocale(LC_ALL, "");
    wprintf(L"Hello, Olá, ¡Hola!, Здравствуйте!, 안녕, 今日は\n");
    return 0;
}
