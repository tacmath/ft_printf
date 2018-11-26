/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mtaquet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/05 12:16:20 by mtaquet      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/22 10:51:15 by mtaquet     ###    #+. /#+    ###.fr     */
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
