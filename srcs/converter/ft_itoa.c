/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mtaquet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/05 12:16:20 by mtaquet      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/16 14:29:20 by mtaquet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

static int	ft_abs(int n)
{
	if (n < 0)
		n = -n;
	return (n);
}

static int	ft_len(intmax_t nb)
{
	int n;

	n = 1;
	if (nb <= 0)
		n++;
	while (nb != 0)
	{
		nb = nb / 10;
		n++;
	}
	return (n);
}

void		ft_itoa(char **str, intmax_t param)
{
	int len;

	len = ft_len(param);
	if (!(*str = malloc(sizeof(char) * len)))
		return ;
	(*str)[len - 1] = '\0';
	len--;
	if (param < 0)
		(*str)[0] = '-';
	if (param == 0)
		(*str)[0] = '0';
	while (param != 0)
	{
		(*str)[--len] = ft_abs(param % 10) + '0';
		param = param / 10;
	}
}

void		ft_uitoa(char **str, uintmax_t param)
{
	int			len;
	uintmax_t	nb;

	nb = param;
	len = 1;
	if (param == 0)
		len++;
	while (param != 0)
	{
		param = param / 10;
		len++;
	}
	if (!(*str = malloc(sizeof(char) * len)))
		return ;
	(*str)[len - 1] = '\0';
	len--;
	if (nb == 0)
		(*str)[0] = '0';
	while (nb != 0)
	{
		(*str)[--len] = nb % 10 + '0';
		nb = nb / 10;
	}
}
