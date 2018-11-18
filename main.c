#include <stdio.h>

int ft_printf(const char *format, ...);

int main(int ac, char **av)
{
	ft_printf("ok%d%%%hhd\n", 20, 1000);
	printf("ok%d%%%hhd\n", 20, 1000);
	return (0);
}
