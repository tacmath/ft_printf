#include <stdio.h>

int ft_printf(const char *format, ...);

int main(int ac, char **av)
{
	ft_printf("%.12f\n", 456456456456);
	printf("%.12f\n", 456456456456);
	return (0);
}
