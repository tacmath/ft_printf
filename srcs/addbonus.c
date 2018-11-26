/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   addbonus.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mtaquet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/22 11:15:14 by mtaquet      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/22 11:23:57 by mtaquet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

void	ft_binaireadd(t_printf *map, uintmax_t param)
{
	int		n;
	char	*str;

	str = 0;
	ft_uitoa_base(&str, param, 2);
	if (map->precision == 0 && param == 0)
		str[0] = '\0';
	ft_fill(map, &str, 0);
	n = ft_strlen(str);
	write(1, str, n);
	free(str);
	map->sizefinal += n;
	map->all += map->sizeflags;
}
