/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapollo <aapollo@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 01:55:49 by aapollo           #+#    #+#             */
/*   Updated: 2021/01/28 03:00:40 by aapollo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_header.h"

void	ft_space_counter(t_body **body)
{
	int		width;
	int		size;
	int		zero;
	int		space_before;
	int		space_after;

	width = (*body)->width;
	size = (*body)->size;
	zero = (*body)->count_zero;
	if ((*body)->prefix[0] == '-')
		size++;
	if ((*body)->prefix[1] == 'x')
		size += 2;
	space_before = (width > 0) ? (width - size - zero) : 0;
	space_after = (width < 0) ? (-width - size - zero) : 0;
	(*body)->space_before = (space_before > 0) ? space_before : 0;
	(*body)->space_after = (space_after > 0) ? space_after : 0;
}

void	ft_zero_counter(t_body **body)
{
	int		i;
	char	type;

	i = 0;
	type = (*body)->type;
	if (type != 's')
	{
		if ((*body)->size < (*body)->precision)
		{
			while (i++ < (*body)->precision - (*body)->size)
				(*body)->count_zero++;
		}
		else if (((*body)->flag == 1) && ((*body)->precision == -1))
		{
			i = 0;
			while (i++ < (*body)->width - (*body)->size
				- ft_strlen((*body)->prefix))
				(*body)->count_zero++;
		}
	}
}

void	ft_body_size(t_body **body)
{
	int		size;
	int		i;
	char	*str;

	str = (*body)->main;
	size = ((*body)->type == 'c') ? 1 : ft_strlen(str);
	i = 0;
	if ((*body)->type == 's' && ((*body)->precision != -1))
	{
		while ((i < ((*body)->precision)) && (i < size))
			i++;
		str = ft_substr(str, 0, i);
		(*body)->main = str;
		size = ft_strlen((*body)->main);
	}
	(*body)->size = size;
}

void	ft_putarg(t_body **body)
{
	int		i;

	i = 0;
	while (i++ < (*body)->space_before)
		(*body)->counter += ft_putchar(" ");
	i = 0;
	while ((*body)->prefix[i] != '\0')
		(*body)->counter += ft_putchar(&(*body)->prefix[i++]);
	i = 0;
	while (i++ < (*body)->count_zero)
		(*body)->counter += ft_putchar("0");
	i = 0;
	while ((*body)->main[i] != '\0')
		(*body)->counter += ft_putchar(&(*body)->main[i++]);
	i = 0;
	while (i++ < (*body)->space_after)
		(*body)->counter += ft_putchar(" ");
}

void	ft_processing(t_body **body)
{
	int	i;

	i = 0;
	ft_body_size(body);
	ft_zero_counter(body);
	ft_space_counter(body);
	if ((*body)->type == 'c')
	{
		while (i < (*body)->space_before)
		{
			(*body)->counter += ft_putchar(" ");
			i++;
		}
		i = 0;
		(*body)->counter += ft_putchar(&(*body)->main[0]);
		while (i < (*body)->space_after)
		{
			(*body)->counter += ft_putchar(" ");
			i++;
		}
		return ;
	}
	ft_putarg(body);
}
