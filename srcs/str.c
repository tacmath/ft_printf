/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   str.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mtaquet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/03 11:43:48 by mtaquet      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/19 16:04:33 by mtaquet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

char	*ft_strdup(const char *src)
{
	int		n;
	char	*str;

	if (!(str = malloc(sizeof(char) * (ft_strlen((char*)src) + 1))))
		return (0);
	n = -1;
	while (src[++n])
		str[n] = src[n];
	str[n] = '\0';
	return (str);
}

char	*ft_strncpy(char *dest, char *src, int i)
{
	int n;

	n = -1;
	while (++n < i)
		dest[n] = src[n];
	return (dest);
}

void	ft_normalstr(t_printf *map, char *str)
{
	int		n;
	char	*tmp;

	n = -1;
	while (str[++n] != '\0' && str[n] != '%')
		;
	if (!(tmp = malloc(sizeof(char) * (n + 1))))
		return ;
	n = -1;
	while (str[++n] != '\0' && str[n] != '%')
		tmp[n] = str[n];
	tmp[n] = '\0';
	write(1, tmp, n);
	free(tmp);
	map->all += n;
	map->sizefinal += n;
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		n;
	int		m;
	char	*str;

	n = 0;
	m = 0;
	str = 0;
	if (!(s1 && s2))
		return (0);
	while (s1[n])
		n++;
	while (s2[m])
		m++;
	if (!(str = malloc(sizeof(char) * (m + n + 1))))
		return (0);
	n = -1;
	while (s1[++n])
		str[n] = s1[n];
	m = 0;
	while (s2[m])
		str[n++] = s2[m++];
	str[n] = '\0';
	free(s1);
	free(s2);
	return (str);
}

char	*ft_addstr(char *s1, char *s2, int i)
{
	int		n;
	int		m;
	char	*str;

	str = 0;
	if (!(s1 && s2))
		return (0);
	if (!(str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (0);
	n = -1;
	while (++n < i)
		str[n] = s1[n];
	m = 0;
	while (s2[m])
		str[n++] = s2[m++];
	n = -1;
	while (s1[++n])
	{
		str[i + m] = s1[i];
		i++;
	}
	str[i + m] = '\0';
	free(s1);
	return (str);
}
