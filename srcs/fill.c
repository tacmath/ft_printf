/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fill.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mtaquet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/16 11:44:14 by mtaquet      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/19 15:59:21 by mtaquet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

void	ft_fill_space(t_printf *map, char **str, int use)
{
	char	*space;
	char	c;
	int		len;
	int		n;

	c = ' ';
	n = ft_strlen(*str);
	len = map->nb_space - n;
	if (map->null == '0' && map->neg != '-' && use == 0)
		c = '0';
	if (len > 0)
	{
		space = ft_memalloc(len + 1);
		n = -1;
		while (++n < len)
			space[n] = c;
		if (map->neg == '-')
			*str = ft_strjoin(*str, space);
		else
			*str = ft_strjoin(space, *str);
	}
}

void	ft_fill(t_printf *map, char **str, int pos)
{
	char	*zero;
	int		precision;
	int		len;
	int		n;

	n = ft_strlen(*str) - pos;
	precision = map->precision;
	if (precision == -1 && map->null == '0' && map->neg != '-')
		precision = map->nb_space - pos;
	len = precision - n;
	if (precision != -1 && n < precision)
	{
		zero = ft_memalloc(len + 1);
		n = -1;
		while (++n < len)
			zero[n] = '0';
		*str = ft_addstr(*str, zero, pos);
		ft_strdel(&zero);
	}
	ft_fill_space(map, str, 1);
}
