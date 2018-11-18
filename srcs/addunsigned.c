/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   addunsigned.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mtaquet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/16 11:37:33 by mtaquet      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/16 13:48:15 by mtaquet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

void	ft_unsignedadd(t_printf *map, uintmax_t param)
{
	int		n;
	char	*str;

	str = 0;
	ft_itoa(&str, param);
	if (map->precision == 0 && param == 0)
		str[0] = '\0';
	ft_fill(map, &str, 0);
	n = ft_strlen(str);
	write(1, str, n);
	free(str);
	map->sizefinal += n;
	map->all += map->sizeflags;
}

void	ft_convpadd(t_printf *map, void *param)
{
	int		n;
	char	*str;

	str = 0;
	ft_itoa_basep(&str, (uintmax_t)param);
	if (param == 0 && map->precision == 0)
		str[2] = '\0';
	ft_fill(map, &str, 2);
	n = ft_strlen(str);
	write(1, str, n);
	free(str);
	map->sizefinal += n;
	map->all += map->sizeflags;
}

void	ft_hexadd(t_printf *map, uintmax_t param)
{
	int		n;
	int		pos;
	char	*str;

	str = 0;
	pos = 0;
	ft_itoa_basex(&str, param);
	if (map->diez == '#' && str[0] != '0')
	{
		str = ft_addstr(str, "0x", 0);
		pos = 2;
	}
	if (map->precision == 0 && param == 0)
		str[0] = '\0';
	ft_fill(map, &str, pos);
	n = ft_strlen(str);
	write(1, str, n);
	free(str);
	map->sizefinal += n;
	map->all += map->sizeflags;
}

void	ft_hexupadd(t_printf *map, uintmax_t param)
{
	int		n;
	int		pos;
	char	*str;

	str = 0;
	pos = 0;
	ft_itoa_baseupx(&str, param);
	if (map->diez == '#' && str[0] != '0')
	{
		str = ft_addstr(str, "0X", 0);
		pos = 2;
	}
	if (map->precision == 0 && param == 0)
		str[0] = '\0';
	ft_fill(map, &str, pos);
	n = ft_strlen(str);
	write(1, str, n);
	free(str);
	map->sizefinal += n;
	map->all += map->sizeflags;
}

void	ft_octaladd(t_printf *map, uintmax_t param)
{
	int		n;
	int		pos;
	char	*str;

	str = 0;
	pos = 0;
	ft_itoa_octal(&str, param);
	if (map->diez == '#')
	{
		str = ft_addstr(str, "0", 0);
		pos++;
	}
	if (map->precision == 0 && param == 0)
		str[pos] = '\0';
	ft_fill(map, &str, pos);
	n = ft_strlen(str);
	write(1, str, n);
	free(str);
	map->sizefinal += n;
	map->all += map->sizeflags;
}
