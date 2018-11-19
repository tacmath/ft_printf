/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mtaquet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/05 11:53:24 by mtaquet      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/19 15:59:59 by mtaquet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

void	*ft_memalloc(size_t size)
{
	char	*mem;
	size_t	n;

	mem = 0;
	n = -1;
	if (!(mem = (char*)malloc(sizeof(void) * size)))
		return (0);
	while (size > ++n)
		mem[n] = '\0';
	return (mem);
}

void	ft_free_struct(t_printf *map)
{
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

int		ft_strchr(char *str, char c)
{
	int n;

	n = -1;
	while (str[++n])
		if (str[n] == c)
			return (1);
	return (0);
}

int		ft_strlen(char *str)
{
	int n;

	n = -1;
	while (str[++n])
		;
	return (n);
}

void	ft_strdel(char **str)
{
	if (!(str && *str))
		return ;
	free(*str);
	*str = 0;
}
