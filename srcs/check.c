/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mtaquet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/03 11:43:48 by mtaquet      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/16 11:28:08 by mtaquet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"


static void	ft_check_flags(t_printf *map, char c)
{
	if (c == '#')
		map->diez = '#';
	if (c == '-')
		map->diez = '-';
	if (c == '+')
		map->diez = '+';
	if (c == '0')
		map->diez = '0';
	if (c == ' ')
		map->diez = ' ';
}

static void	ft_get_lenth(t_printf *map, char *str)
{
	if (str[0] == 'l' && str[1] == 'l')	
		map->lenth = ft_strdup("ll");
	else if(str[0] == 'l')	
		map->lenth = ft_strdup("l");
	else if(str[0] == 'h' && str[1] == 'h')	
		map->lenth = ft_strdup("hh");
	else if(str[0] == 'h')	
		map->lenth = ft_strdup("h");
	else if(str[0] == 'j')	
		map->lenth = ft_strdup("j");
	else if(str[0] == 'z')	
		map->lenth = ft_strdup("z");
	else 
		map->lenth = ft_memalloc(1);
}

void	ft_check(t_printf *map, char *str)
{
	int n;

	n = 0;
	while (str[++n] == '#' || str[n] == '+' || str[n] == '-'
			|| str[n] == '0' || str[n] == ' ')
		ft_check_flags(map, str[n]);
	if (str[n] >= '1' && str[n] <= '9')
	{
		map->nb_space = ft_atoi(&(str[n]));
		while (str[++n] >= '0' && str[n] <= '9')
			;
	}
	if (str[n] == '.')
	{
		map->precision = ft_atoi(&(str[n + 1]));
		while (str[++n] >= '0' && str[n] <= '9')
			;
	}
	else
		map->precision = -1;
	ft_get_lenth(map, &(str[n]));
	n += ft_strlen(map->lenth);
	map->conv = str[n];
	map->sizeflags = n + 1;
}
