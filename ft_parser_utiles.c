/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_utiles.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapollo <aapollo@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 01:58:38 by aapollo           #+#    #+#             */
/*   Updated: 2021/01/28 02:49:21 by aapollo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_header.h"

void	ft_pars_type(const char **format, t_body **body, va_list **ap)
{
	if (**format == 'x')
		ft_output_x(format, body, ap);
	else if (**format == 'X')
		ft_output_upperx(format, body, ap);
	else if (**format == 's')
		ft_output_str(format, body, ap);
	else if (**format == 'c')
		ft_output_chr(format, body, ap);
	else if ((**format == 'd') || (**format == 'i') || (**format == 'u'))
		ft_output_udi(format, body, ap);
	else if (**format == 'p')
		ft_output_p(format, body, ap);
	else if (**format == '%')
		ft_output_perc(format, body);
	else
		(*body)->error = -1;
}

void	ft_pars_precision(const char **format, t_body **body, va_list **ap)
{
	if (**format == '.')
	{
		(*format)++;
		(*body)->precision = 0;
	}
	else
		(*body)->precision = -1;
	if ((**format <= '9') && (**format >= '0'))
		(*body)->precision = ft_atoi(format);
	if (**format == '*')
	{
		(*body)->precision = va_arg(**ap, int);
		(*format)++;
	}
	if (((*body)->width == (int)NULL) && ((*body)->precision > 0))
		(*body)->flag = 1;
}

void	ft_pars_width(const char **format, t_body **body, va_list **ap)
{
	int	isneg;
	int argm;

	isneg = 1;
	argm = (int)NULL;
	if (**format == '-')
		isneg = -isneg;
	if (((**format <= '9') && (**format >= '0')) || (**format == '-'))
		(*body)->width = ft_atoi(format);
	if (**format == '*')
	{
		if ((argm = va_arg(**ap, int)) >= 0)
			(*body)->width = isneg * argm;
		else
			(*body)->width = argm;
		(*format)++;
	}
}

void	ft_pars_flag(const char **format, t_body **body, va_list **ap)
{
	if (**format == '%')
		(*format)++;
	if (**format == '-')
		ft_pars_width(format, body, ap);
	if (**format == '0')
	{
		(*body)->flag = 1;
		(*format)++;
	}
	while (**format == '0')
		(*format)++;
	if (**format == '.')
		ft_pars_precision(format, body, ap);
	else if (**format != '\0')
		(*body)->precision = -1;
}
