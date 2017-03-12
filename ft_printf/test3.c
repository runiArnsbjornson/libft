#include <stdio.h>

int	ft_printf(const char *fmt, ...);

int	main()
{
	int i;
	int j;

	i = printf("u>%e %.3E %.3e %E\n", 2.0, 2.0, 256.0, 256.0);
	j = ft_printf("f>%e %.3E %.e %E\n", 2.0, 2.0, 256.0, 256.0);
	printf("ret u =%d\n", i);
	printf("ret f =%d\n", j);

	printf("log(25678965)=%d\n", ft_log(25678965));
	return (0);

}
