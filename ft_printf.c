/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapollo <aapollo@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 21:14:07 by aapollo           #+#    #+#             */
/*   Updated: 2021/01/28 06:39:11 by aapollo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_header.h"

void	ft_output_str(const char **format, t_body **body, va_list **ap)
{
	(*body)->main = va_arg(**ap, char*);
	(*body)->main = ((*body)->main == NULL) ? "(null)" : (*body)->main;
	(*body)->main = ft_strdup((*body)->main);
	(*body)->precision = ((*body)->precision < 0) ? -1 : (*body)->precision;
	(*format)++;
	(*body)->type = 's';
}

void	ft_output_chr(const char **format, t_body **body, va_list **ap)
{
	char	c[2];
	char	*str;

	c[0] = (char)va_arg(**ap, int);
	c[1] = '\0';
	str = ft_substr(c, 0, 2);
	(*body)->main = str;
	(*format)++;
	(*body)->type = 'c';
}

void	ft_output_perc(const char **format, t_body **body)
{
	char	c[2];
	char	*str;

	c[0] = '%';
	c[1] = '\0';
	str = ft_substr(c, 0, 2);
	(*body)->main = str;
	(*format)++;
	(*body)->type = '%';
}

int		ft_parser(const char **format, va_list *ap, t_body *body)
{
	while (**format != '\0')
	{
		ft_body_del(&body);
		while (**format != '%' && **format != '\0')
			body->counter += ft_putchar((char *)(*format)++);
		if (**format != '\0')
		{
			ft_pars_flag(format, &body, &ap);
			if (body->width == (int)NULL)
				ft_pars_width(format, &body, &ap);
			if (**format == '.')
				ft_pars_precision(format, &body, &ap);
			ft_pars_type(format, &body, &ap);
			if (body->error == -1)
				return ((body->counter = -1));
			ft_processing(&body);
		}
		free(body->main);
	}
	return (0);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	t_body	body;

	body.counter = 0;
	va_start(ap, format);
	ft_parser(&format, &ap, &body);
	va_end(ap);
	return (body.counter);
}
