/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapollo <aapollo@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 02:05:00 by aapollo           #+#    #+#             */
/*   Updated: 2021/01/28 02:51:02 by aapollo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_header.h"

void	ft_output_upperx(const char **format, t_body **body, va_list **ap)
{
	int				i;
	char			*str;
	unsigned int	argm;

	i = 0;
	argm = va_arg(**ap, unsigned int);
	if ((*body)->precision != 0)
	{
		str = ft_itoa_base(argm, 16, body);
		(*body)->main = str;
	}
	else
		(*body)->main = ft_strdup("");
	while ((*body)->main[i] != '\0')
	{
		(*body)->main[i] = ft_toupper((*body)->main[i]);
		i++;
	}
	(*format)++;
	(*body)->type = 'X';
}

void	ft_output_x(const char **format, t_body **body, va_list **ap)
{
	unsigned int	argm;
	char			*str;

	argm = va_arg(**ap, unsigned int);
	if ((*body)->precision != 0)
	{
		str = ft_itoa_base(argm, 16, body);
		(*body)->main = str;
	}
	else
		(*body)->main = ft_strdup("");
	(*format)++;
	(*body)->type = 'x';
}

void	ft_output_p(const char **format, t_body **body, va_list **ap)
{
	char	*str;

	(*body)->prefix[0] = '0';
	(*body)->prefix[1] = 'x';
	(*body)->prefix[2] = '\0';
	str = ft_itoa_base(va_arg(**ap, unsigned long), 16, body);
	(*body)->main = str;
	if ((*body)->precision == 0)
		(*body)->main[0] = '\0';
	(*format)++;
	(*body)->type = 'p';
}

void	ft_output_udi(const char **format, t_body **body, va_list **ap)
{
	char	*str;

	str = 0;
	if (**format == 'u' && ((*body)->precision != 0))
	{
		str = ft_itoa_base(va_arg(**ap, unsigned int), 10, body);
		if ((str[0] == '0') && (*body)->precision > -1)
			str[0] = '\0';
		(*body)->type = 'u';
	}
	else if ((*body)->precision != 0)
	{
		str = ft_itoa_base(va_arg(**ap, int), 10, body);
		(*body)->type = (**format == 'i') ? 'i' : 'd';
	}
	(*format)++;
	(*body)->main = str;
	if ((*body)->precision == 0)
		(*body)->main = ft_strdup("");
}
