/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapollo <aapollo@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 01:52:58 by aapollo           #+#    #+#             */
/*   Updated: 2021/01/28 03:04:28 by aapollo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_header.h"

unsigned int	ft_tounsgdint(int num)
{
	if (num < 0)
		num = 4294967296 + num;
	return (num);
}

int				ft_toupper(int ch)
{
	if ((ch > 96) && (ch < 123))
		ch = ch - 32;
	return (ch);
}

void			ft_body_del(t_body **body)
{
	(*body)->flag = (int)NULL;
	(*body)->width = (int)NULL;
	(*body)->precision = (int)NULL;
	(*body)->type = (char)NULL;
	(*body)->space_before = (int)NULL;
	(*body)->prefix[0] = (char)NULL;
	(*body)->prefix[1] = (char)NULL;
	(*body)->prefix[2] = (char)NULL;
	(*body)->count_zero = (int)NULL;
	(*body)->main = NULL;
	(*body)->space_after = (int)NULL;
	(*body)->size = (int)NULL;
	(*body)->error = (int)NULL;
}

char			*ft_strdup(const char *s1)
{
	char	*res;
	int		counter;

	res = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!res)
		return (0);
	counter = 0;
	while (*s1 != '\0')
	{
		res[counter] = *s1;
		s1++;
		counter++;
	}
	res[counter] = '\0';
	return (res);
}
