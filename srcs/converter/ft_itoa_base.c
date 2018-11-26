/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa_base.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mtaquet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/05 12:17:03 by mtaquet      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/22 11:00:24 by mtaquet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

static int	ft_base(int n)
{
	if (n > 9)
		n += 39;
	return (n);
}

void		ft_uitoa_base(char **str, uintmax_t param, int base)
{
	int			len;
	uintmax_t	nb;

	nb = param;
	len = 1;
	if (nb == 0)
		len++;
	while (nb != 0)
	{
		nb = nb / base;
		len++;
	}
	if (!(*str = malloc(sizeof(char) * len)))
		return ;
	(*str)[len - 1] = '\0';
	len--;
	if (param == 0)
		(*str)[0] = '0';
	while (param != 0)
	{
		(*str)[--len] = ft_base(param % base) + '0';
		param = param / base;
	}
}

void		ft_itoa_hex(char **str, uintmax_t param)
{
	int n;

	n = -1;
	ft_uitoa_base(str, param, 16);
	while ((*str)[++n])
		if ((*str)[n] >= 'a' && (*str)[n] <= 'f')
			(*str)[n] = (*str)[n] - 32;
}

void		ft_itoa_p(char **str, uintmax_t param)
{
	char	*tmp;
	int		n;

	n = -1;
	ft_uitoa_base(&tmp, param, 16);
	while (tmp[++n])
		;
	if (!(*str = malloc(sizeof(char) * (n + 2))))
		return ;
	(*str)[0] = '0';
	(*str)[1] = 'x';
	n = -1;
	while (tmp[++n])
		(*str)[n + 2] = tmp[n];
	(*str)[n + 2] = '\0';
	free(tmp);
}
