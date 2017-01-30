/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 11:33:05 by jdebladi          #+#    #+#             */
/*   Updated: 2017/01/30 17:51:52 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <locale.h>

static int  check_next(const char *txt)
{
    int i;

    i = 0;
    if (txt[i] == '%' && txt[i + 1])
    {
        i++;
        if (txt[i] == 's' || txt[i] == 'S' || txt[i] == 'p' || txt[i] == 'd' \
        || txt[i] == 'D' || txt[i] == 'i' || txt[i] == 'o' || txt[i] == 'O' || \
        txt[i] == 'u' || txt[i] == 'U' || txt[i] == 'x' || txt[i] == 'X' || \
        txt[i] == 'c' || txt[i] == 'C')
            return (1);
        return (0);
    }
    return (0);
}

int          ft_printf(const char *txt, ... )
{
    int i;
    int arg;

    i = 0;
    arg = 0;
    while (txt[i])
    {
        if (txt[i] == '%')
        {
            if (check_next(&txt[i]) == 1)
                arg++;
        }
        i++;
    }
    return (arg);
}

int main()
{
    int a;
    int i;
    int c;
    const char *s = "%a%A %c%C %d%D %e%E %f%F %g%G %i %n %o%O %p %s%S %u%U \
    \n%x%X # $ * + - 0 L ' hh h l ll j z %b %r %k";

    setlocale(LC_ALL, "");
    c = 0;
    i = 0;
    while (s[i])
    {
        if (s[i] == '%')
            c++;
        i++;
    }
    a = ft_printf(s);
    printf("%d = %d\n", a, c);
    printf("%s\n", s);
    return 0;
}
