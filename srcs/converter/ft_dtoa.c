/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_dtoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mtaquet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/05 12:17:50 by mtaquet      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/19 16:05:14 by mtaquet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

static uintmax_t	ft_get_nb_decimal(long double param, int precision)
{
	if (param < 0)
		param = -param;
	param = param - (uintmax_t)(param);
	precision++;
	while (--precision >= 0)
		param = 10 * param;
	param = (uintmax_t)param;
	return (param);
}

static int		ft_len(long double nb)
{
	int len;

	len = 1;
	if (nb <= 0)
		len++;
	while (nb >= 1 || nb <= -1)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

static int		ft_dmod(long double nb, int mod)
{
	if (nb < 0)
		nb = -nb;
	return ((int)(nb - ((uintmax_t)(nb / mod) * mod)));
}

void			ft_dtoa(char **str, long double param, int precision)
{
	int			len;
	long double		nb;

	len = ft_len(param);
	if (precision != 0)
		len += precision;
	if (!(*str = malloc(sizeof(char) * len)))
		return ;
	if (param < 0)
		nb = param * -1;
	else
		nb = param;
	if (precision != 0)
		(*str)[len - precision - 1] = '.';
	(*str)[len - 1] = '\0';
	if (nb == 0)
		(*str)[0] = '0';
	len = len - precision - 1;
	while (--len >= 0)
	{
		(*str)[len] = ft_dmod(nb, 10) + '0';
		nb = nb / 10;
	}
	nb = ft_get_nb_decimal(param, precision);
	len = ft_len(param) + precision;
	if (ft_dmod(nb, 10) >= 5)
		nb += 10;
	nb = nb / 10;
	while (--precision >= 0)
	{
		(*str)[--len] = ft_dmod(nb, 10) + '0';
		nb = nb / 10;
	}
	if (param < 0)
		(*str)[0] = '-';
}
