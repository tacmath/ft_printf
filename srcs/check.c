/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mtaquet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/03 11:43:48 by mtaquet      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/19 15:58:22 by mtaquet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

static void	ft_check_flags(t_printf *map, char c)
{
	if (c == '#')
		map->diez = '#';
	if (c == '-')
		map->neg = '-';
	if (c == '+')
		map->pos = '+';
	if (c == '0')
		map->null = '0';
	if (c == ' ')
		map->space = ' ';
}

static void	ft_get_lenth(t_printf *map, char c)
{
	if (c == 'l')
		map->lenth.l += 1;
	else if (c == 'h')
		map->lenth.h += 1;
	else if (c == 'j')
		map->lenth.j = 1;
	else if (c == 'z')
		map->lenth.z = 1;
	else if (c == 'L')
		map->lenth.upl = 1;
}

void		ft_check(t_printf *map, char *str)
{
	int n;

	n = 0;
	while (ft_strchr("#+- lhjzL.0123456789", str[++n]) && str[n] != '\0')
	{
		if (ft_strchr("#+-0 ", str[n]))
			ft_check_flags(map, str[n]);
		if (str[n] >= '1' && str[n] <= '9')
		{
			map->nb_space = ft_atoi(&(str[n]));
			while (str[++n] >= '0' && str[n] <= '9')
				;
			n--;
		}
		if (str[n] == '.')
		{
			map->precision = ft_atoi(&(str[n + 1]));
			while (str[++n] >= '0' && str[n] <= '9')
				;
			n--;
		}
		ft_get_lenth(map, str[n]);
	}
	map->conv = str[n];
	map->sizeflags = n + 1;
}
