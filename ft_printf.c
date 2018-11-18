/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mtaquet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/03 11:43:48 by mtaquet      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/16 11:18:03 by mtaquet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "printf.h"

void	ft_basic(t_printf *map, va_list *ap)
{
	if (map->conv == 's')
		ft_stradd(map, va_arg(*ap, char*));
	else if (map->conv == 'c')
		ft_charadd(map, va_arg(*ap, int));
	else if (map->conv == 'p')
		ft_convpadd(map, va_arg(*ap, void*));
	else if (map->conv == 'f')
		ft_doubleadd(map, (long double)va_arg(*ap, double));
	else if (map->conv == 'd' || map->conv == 'i')
		ft_intadd(map, (intmax_t)va_arg(*ap, int));
	else if (ft_strchr("uxXo", map->conv))
		ft_allunsigned(map, (uintmax_t)va_arg(*ap, unsigned int));
	else if (map->conv == '%')
		ft_percentadd(map);
}

void	ft_treatall(t_printf *map, char *format, va_list *ap)
{
	int n;

	n = map->all;
	ft_check(map, format);
	if (n == map->all)
		ft_long(map, ap);
	if (n == map->all)
		ft_short(map, ap);
	if (n == map->all)
		ft_othersize(map, ap);
	if (n == map->all)
		ft_basic(map, ap);
	ft_free_struct(map);
}

int	ft_printf(const char *restrict format, ...)
{
	va_list	ap;
	int		m;
	t_printf	*map;

	if (!(map = malloc(sizeof(t_printf))))
		return (0);
	map->all = 0;
	map->sizefinal = 0;
	va_start(ap, format);
	while (format[map->all])
	{
		if (format[map->all] == '%')
		{
			m = map->all;
			ft_treatall(map, (char*)&format[map->all], &ap);
			if (map->all == m)
			{
				write(1, "%", 1);
				map->all += 1;
			}
		}
		else
			ft_normalstr(map, (char*)&format[map->all]);
	}
	va_end(ap);					//faire un free map
	return (map->sizefinal);
}
