/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   addother.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mtaquet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/16 11:31:40 by mtaquet      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/19 16:03:09 by mtaquet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

void	ft_stradd(t_printf *map, char *param)
{
	char	*str;
	char	*tmp;
	int		n;

	str = 0;
	if (!param)
		str = ft_strdup("(null)");
	else
		str = ft_strdup(param);
	if (map->precision != -1 && ft_strlen(str) > map->precision)
	{
		tmp = ft_memalloc(map->precision + 1);
		tmp = ft_strncpy(tmp, str, map->precision);
		free(str);
		str = tmp;
	}
	ft_fill_space(map, &str, 0);
	n = ft_strlen(str);
	write(1, str, n);
	free(str);
	map->sizefinal += n;
	map->all += map->sizeflags;
}

void	ft_intadd(t_printf *map, intmax_t param)
{
	int		n;
	int		pos;
	char	*str;

	str = 0;
	pos = 0;
	ft_itoa(&str, param);
	if (param >= 0 && map->pos == '+')
		str = ft_addstr(str, "+", 0);
	else if (param >= 0 && map->space == ' ')
		str = ft_addstr(str, " ", 0);
	if (str[0] == '-' || str[0] == '+' || str[0] == ' ')
		pos++;
	if (map->precision == 0 && param == 0)
		str[pos] = 0;
	ft_fill(map, &str, pos);
	n = ft_strlen(str);
	write(1, str, n);
	free(str);
	map->sizefinal += n;
	map->all += map->sizeflags;
}

void	ft_doubleadd(t_printf *map, long double param)
{
	int		n;
	int		pos;
	int		precision;
	char	*str;

	str = 0;
	pos = 0;
	precision = map->precision;
	if (precision == -1)
		precision = 6;
	ft_dtoa(&str, param, precision);
	if (param >= 0 && map->pos == '+')
		str = ft_addstr(str, "+", 0);
	else if (param >= 0 && map->space == ' ')
		str = ft_addstr(str, " ", 0);
	if (str[0] == '-' || str[0] == '+' || str[0] == ' ')
		pos++;
	if (map->precision == 0 && param == 0)
		str[pos] = '\0';
	ft_fill_space(map, &str, 0);
	n = ft_strlen(str);
	write(1, str, n);
	free(str);
	map->sizefinal += n;
	map->all += map->sizeflags;
}

void	ft_percentadd(t_printf *map)
{
	int		n;
	char	*str;

	str = ft_memalloc(2);
	str[0] = '%';
	ft_fill_space(map, &str, 0);
	n = ft_strlen(str);
	write(1, str, n);
	free(str);
	map->sizefinal += n;
	map->all += map->sizeflags;
}

void	ft_charadd(t_printf *map, int param)
{
	char	c;
	char	*fill;
	int		n;

	c = ' ';
	if (map->null == '0' && map->neg != '-')
		c = '0';
	if (map->nb_space > 1)
		fill = ft_memalloc(map->nb_space);
	n = -1;
	while (++n < map->nb_space - 1)
		fill[n] = c;
	if (map->neg != '-' && map->nb_space > 1)
		write(1, fill, map->nb_space - 1);
	c = (unsigned char)param;
	write(1, &c, 1);
	if (map->neg == '-' && map->nb_space > 1)
		write(1, fill, map->nb_space - 1);
	if (map->nb_space > 1)
		free(fill);
	map->sizefinal += 1;
	if (map->nb_space > 0)
		map->sizefinal += map->nb_space - 1;
	map->all += map->sizeflags;
}
