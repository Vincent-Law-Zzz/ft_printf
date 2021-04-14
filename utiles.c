/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapollo <aapollo@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 01:33:11 by aapollo           #+#    #+#             */
/*   Updated: 2021/01/28 03:04:07 by aapollo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_header.h"

int		ft_strlen(const char *str)
{
	int		counter;
	int		i;

	counter = 0;
	i = 0;
	while (str[i] != '\0')
	{
		counter++;
		i++;
	}
	return (counter);
}

char	*ft_substr(char const *s, unsigned int start, unsigned int len)
{
	char			*p;
	unsigned int	slen;
	unsigned int	counter;

	slen = (s) ? (ft_strlen(s)) : 0;
	counter = 0;
	p = ((start + len <= slen)) ? (char *)malloc((len + 1)) : 0;
	if ((p == 0) && !(p = ((start < slen) && (slen > 0) && (p == 0)) ?
		((char *)malloc((slen - start + 1))) : (char *)malloc(sizeof(char))))
		return (0);
	while ((counter++ < start) && (*s != '\0'))
		s++;
	counter = 0;
	while ((counter < len) && (start <= slen) && (slen) && (len) && (*s))
	{
		p[counter] = *s;
		counter++;
		s++;
	}
	p[counter] = '\0';
	return (p);
}

char	*ft_itoa_base(long long n, int base, t_body **body)
{
	int			counter;
	long long	num[2];
	char		*res;

	if (n < 0)
	{
		(*body)->prefix[0] = '-';
		(*body)->prefix[1] = '\0';
	}
	counter = 0;
	num[0] = (n < 0) ? -n : n;
	num[1] = (n < 0) ? -n : n;
	while (num[0] /= base)
		counter++;
	counter++;
	if (!(res = (char*)malloc((counter + 1) * sizeof(char))))
		return (NULL);
	res[counter] = '\0';
	while (counter-- > 0)
	{
		res[counter] = ((num[1] % base) <= 9) ? (num[1] % base + '0') :
			(int)(87 + (num[1] % base));
		num[1] = num[1] / base;
	}
	return (res);
}

int		ft_atoi(const char **str)
{
	long long	max;
	int			isneg;
	long long	res;

	res = 0;
	isneg = 1;
	max = 0;
	if ((**str == '-') || (**str == '+'))
		if (*(*str)++ == '-')
			isneg = -1;
	while ((**str >= '0') && (**str <= '9'))
	{
		res = res * 10 + (**str - '0');
		(*str)++;
		if ((max > res) && (isneg == 1))
			return (-1);
		if ((max > res) && (isneg == -1))
			return (0);
		max = res;
	}
	return (res * isneg);
}

int		ft_putchar(char *c)
{
	write(1, c, 1);
	return (1);
}
