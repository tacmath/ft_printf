/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa_binaire.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mtaquet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/05 12:17:50 by mtaquet      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/16 14:26:38 by mtaquet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

void	ft_itoa_binaire(char **str, uintmax_t param)
{
	int			len;
	uintmax_t	nb;

	nb = param;
	len = 1;
	if (param == 0)
		len++;
	while (param != 0)
	{
		param = param / 2;
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
		(*str)[--len] = nb % 2 + '0';
		nb = nb / 2;
	}
}
