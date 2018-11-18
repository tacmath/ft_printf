/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mtaquet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/06 09:56:51 by mtaquet      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/15 14:04:05 by mtaquet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int negatif;
	int resultat;
	int n;

	resultat = 0;
	negatif = 0;
	n = 0;
	while (str[n] == '\t' || str[n] == ' ' || str[n] == '\r'
			|| str[n] == '\n' || str[n] == '\v' || str[n] == '\f')
		n++;
	if (str[n] == '-')
		negatif = 1;
	if (str[n] == '-' || str[n] == '+')
		n++;
	while (str[n] >= '0' && str[n] <= '9')
	{
		resultat = resultat * 10 + (str[n] - 48);
		n++;
	}
	if (negatif == 1)
		resultat = -resultat;
	return (resultat);
}
