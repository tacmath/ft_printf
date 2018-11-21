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

static long double	ft_decimal(long double param, int precision)
{
	if (param < 0)
		param = -param;
	param = param - (uintmax_t)(param);
	while (--precision >= 0)
		param = 10 * param;
	return (param);
}

static int		ft_len(long double nb)
{
	int len;

	len = 1;
	if (nb == 0)
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

static void			ft_dtoa_int(char **str, long double param, int precision, int neg)
{
	long double	nb;
	int		len;

	len = ft_len(param) + neg;
	nb = param;
	if (precision != 0)
		len += precision;
	if (!(*str = malloc(sizeof(char) * len)))
		return ;
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
}

void			ft_dtoa(char **str, long double param, int precision)
{
	int			len;
	int			neg;
	long double		nb;
	long double		decimal;

	neg = 0;
	if (param < 0)
		neg = 1;
	if (param < 0)
		param = -param;
	decimal = ft_decimal(param, precision); 
	if ((uintmax_t)decimal != (uintmax_t)(decimal + 0.5))
		param++;
	ft_dtoa_int(str, param, precision, neg);
	nb = (uintmax_t)decimal;
	if ((uintmax_t)decimal != (uintmax_t)(decimal + 0.5))
		nb++;
	len = ft_len(param) + precision + neg;
	while (--precision >= 0)
	{
		(*str)[--len] = ft_dmod(nb, 10) + '0';
		nb = nb / 10;
	}
	if (neg == 1)
		(*str)[0] = '-';
}
