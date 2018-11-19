#include <stdio.h>

int ft_printf(const char *format, ...);

int main(int ac, char **av)
{
	ft_printf("%.3o\n", 1);
	printf("%.3o\n", 1);
	return (0);
}
