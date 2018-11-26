/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   treatlenth.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mtaquet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/03 11:43:48 by mtaquet      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/22 11:21:21 by mtaquet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"
#include <sys/types.h>

void	ft_allunsigned(t_printf *map, uintmax_t arg)
{
	if (map->conv == 'u')
		ft_unsignedadd(map, arg);
	if (map->conv == 'x')
		ft_hexadd(map, arg);
	if (map->conv == 'X')
		ft_hexupadd(map, arg);
	if (map->conv == 'o')
		ft_octaladd(map, arg);
	if (map->conv == 'b')
		ft_binaireadd(map, arg);
}

void	ft_longlong(t_printf *map, va_list *ap)
{
	if (map->lenth.j == 1)
	{
		if (map->conv == 'd' || map->conv == 'i')
			ft_intadd(map, va_arg(*ap, intmax_t));
		if (ft_strchr("uxXob", map->conv))
			ft_allunsigned(map, va_arg(*ap, uintmax_t));
	}
	else if (map->lenth.l >= 2)
	{
		if (map->conv == 'd' || map->conv == 'i')
			ft_intadd(map, (intmax_t)va_arg(*ap, long long));
		if (ft_strchr("uxXob", map->conv))
			ft_allunsigned(map, (uintmax_t)va_arg(*ap, unsigned long long));
	}
}

void	ft_long(t_printf *map, va_list *ap)
{
	if (map->lenth.z == 1)
	{
		if (map->conv == 'd' || map->conv == 'i')
			ft_intadd(map, (intmax_t)va_arg(*ap, ssize_t));
		if (ft_strchr("uxXob", map->conv))
			ft_allunsigned(map, (uintmax_t)va_arg(*ap, size_t));
	}
	else if (map->lenth.l == 1)
	{
		if (map->conv == 'd' || map->conv == 'i')
			ft_intadd(map, (intmax_t)va_arg(*ap, long));
		if (ft_strchr("uxXob", map->conv))
			ft_allunsigned(map, (uintmax_t)va_arg(*ap, unsigned long));
	}
}

void	ft_short(t_printf *map, va_list *ap)
{
	if (map->lenth.h >= 2)
	{
		if (map->conv == 'd' || map->conv == 'i')
			ft_intadd(map, (intmax_t)((signed char)va_arg(*ap, int)));
		if (ft_strchr("uxXob", map->conv))
			ft_allunsigned(map, (uintmax_t)((unsigned char)va_arg(*ap, int)));
	}
	else if (map->lenth.h == 1)
	{
		if (map->conv == 'd' || map->conv == 'i')
			ft_intadd(map, (intmax_t)((short int)va_arg(*ap, int)));
		if (ft_strchr("uxXob", map->conv))
			ft_allunsigned(map,
			(uintmax_t)((unsigned short int)va_arg(*ap, int)));
	}
}
