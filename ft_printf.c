/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mtaquet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/03 11:43:48 by mtaquet      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/19 16:39:00 by mtaquet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "printf.h"

void	ft_nothingadd(t_printf *map)
{
	char	c;
	char	*fill;
	int		n;

	if (map->conv != '\0')
		ft_charadd(map, map->conv);
	else
	{
		if (map->nb_space > 0)
		{
			c = ' ';
			if (map->null == '0' && map->neg != '-')
				c = '0';
			fill = ft_memalloc(map->nb_space + 1);
			n = -1;
			while (++n < map->nb_space)
				fill[n] = c;
			write(1, fill, map->nb_space);
			free(fill);
			map->sizefinal += map->nb_space;
		}
		map->all += map->sizeflags - 1;
	}
}

void	ft_basic(t_printf *map, va_list *ap)
{
	if (map->conv == 's')
		ft_stradd(map, va_arg(*ap, char*));
	else if (map->conv == 'c')
		ft_charadd(map, va_arg(*ap, int));
	else if (map->conv == 'p')
		ft_convpadd(map, va_arg(*ap, void*));
	else if (map->conv == 'f' && (map->lenth.upl == 1 || map->lenth.l >= 1))
		ft_doubleadd(map, va_arg(*ap, long double));
	else if (map->conv == 'f')
		ft_doubleadd(map, (long double)va_arg(*ap, double));
	else if (map->conv == 'd' || map->conv == 'i')
		ft_intadd(map, (intmax_t)va_arg(*ap, int));
	else if (ft_strchr("uxXo", map->conv))
		ft_allunsigned(map, (uintmax_t)va_arg(*ap, unsigned int));
	else if (map->conv == '%')
		ft_percentadd(map);
	else
		ft_nothingadd(map);
}

void	ft_treatall(t_printf *map, char *format, va_list *ap)
{
	int n;

	n = map->all;
	ft_check(map, format);
	if (n == map->all)
		ft_longlong(map, ap);
	if (n == map->all)
		ft_long(map, ap);
	if (n == map->all)
		ft_short(map, ap);
	if (n == map->all)
		ft_basic(map, ap);
	ft_free_struct(map);
}

void	ft_init_struct(t_printf *map)
{
	map->all = 0;
	map->sizefinal = 0;
	map->sizeflags = 0;
	map->conv = 0;
	map->diez = 0;
	map->neg = 0;
	map->pos = 0;
	map->null = 0;
	map->space = 0;
	map->nb_space = 0;
	map->precision = -1;
	map->lenth.l = 0;
	map->lenth.h = 0;
	map->lenth.j = 0;
	map->lenth.z = 0;
	map->lenth.upl = 0;
}

int		ft_printf(const char *restrict format, ...)
{
	va_list		ap;
	int			n;
	t_printf	*map;

	if (!(map = malloc(sizeof(t_printf))))
		return (0);
	ft_init_struct(map);
	va_start(ap, format);
	while (format[map->all])
	{
		if (format[map->all] == '%')
			ft_treatall(map, (char*)&format[map->all], &ap);
		else
			ft_normalstr(map, (char*)&format[map->all]);
	}
	va_end(ap);
	n = map->sizefinal;
	free(map);
	return (n);
}
