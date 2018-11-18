/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa_base.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mtaquet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/05 12:17:03 by mtaquet      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/16 14:25:26 by mtaquet     ###    #+. /#+    ###.fr     */
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

static int	ft_len(uintmax_t nb)
{
	int n;

	n = 1;
	if (nb == 0)
		n++;
	while (nb != 0)
	{
		nb = nb / 16;
		n++;
	}
	return (n);
}

void		ft_itoa_basex(char **str, uintmax_t param)
{
	int len;

	len = ft_len(param);
	if (!(*str = malloc(sizeof(char) * len)))
		return ;
	(*str)[len - 1] = '\0';
	len--;
	if (param == 0)
		(*str)[0] = '0';
	while (param != 0)
	{
		(*str)[--len] = ft_base(param % 16) + '0';
		param = param / 16;
	}
}

void		ft_itoa_baseupx(char **str, uintmax_t param)
{
	int n;

	n = -1;
	ft_itoa_basex(str, param);
	while ((*str)[++n])
		if ((*str)[n] >= 'a' && (*str)[n] <= 'f')
			(*str)[n] = (*str)[n] - 32;
}

void		ft_itoa_basep(char **str, uintmax_t param)
{
	char	*tmp;
	int		n;

	n = -1;
	ft_itoa_basex(&tmp, param);
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
