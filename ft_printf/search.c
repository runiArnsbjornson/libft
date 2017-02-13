#include <locale.h>
#include "includes/libft.h"

static char	check_arg(const char *txt)
{
	int i;

	i = 1;
	while (txt[i])
	{
		if ((txt[i] >= 97 && txt[i] <= 'g') || txt[i] == 'i' || txt[i] == 'k' ||
				(txt[i] >= 'n' && txt[i] <= 'p') || txt[i] == 'r' || txt[i] ==
				's' || txt[i] == 'u' || txt[i] == 'x' || txt[i] == 65 || (txt[i]
					>= 67 && txt[i] <= 71) || txt[i] == 79 || txt[i] == 83 || txt[i]
				== 85 || txt[i] == 88)
			return (txt[i]);
		else if (txt[i] == '#' || txt[i] == '$' || txt[i] == '*' || txt[i] ==
				'+' || txt[i] == '-' || txt[i] == '0' || txt[i] == 'L' || txt[i]
				== 39 || txt[i] == 'h' || txt[i] == 'l' || txt[i] == 'j' || txt
				[i] == 'z' || txt[i] == ' ')
			i++;
		else
			return ('0');
	}
	return ('0');
}

char		*count_arg(const char *txt)
{
	int		i;
	int		j;
	int		arg;
	char	*t;

	i = 0;
	j = 0;
	arg = 0;
	t = ft_strnew(1);
	while (txt[i])
	{
		if (txt[i] == '%')
		{
			if (check_arg(&txt[i]) != '0')
			{
				t = ft_strrealloc(t, 1);
				t[j] = check_arg(&txt[i]);
				j++;
			}
		}
		i++;
	}
	return (t);
}

int			main()
{
	int		i;
	const char *s = "%a%A %c%C %d%D %e%E %f%F %g%G %i %n %o%O %p %s%S %u%U \n%x%X # $ * + - 0 %L ' hh[] ha l ll j z %b %r %k";
	char	*t;

	setlocale(LC_ALL, "POSIX");
	t = count_arg(s);
	i = ft_strlen(t);
	ft_putnbr(i);
	write(1, " ", 1);
	write(1, t, i);
	return 0;
}
