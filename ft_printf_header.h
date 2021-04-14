/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_header.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapollo <aapollo@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 04:57:34 by aapollo           #+#    #+#             */
/*   Updated: 2021/01/28 03:01:42 by aapollo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_HEADER_H
# define FT_PRINTF_HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef	struct	s_body
{
	int			flag;
	int			width;
	int			precision;
	char		type;
	int			space_before;
	char		prefix[3];
	int			count_zero;
	char		*main;
	int			space_after;
	int			size;
	int			counter;
	int			error;
}				t_body;

int				ft_putchar(char *c);
void			ft_body_del(t_body **body);
int				ft_strlen(const char *str);
char			*ft_substr(char const *s, unsigned int start, unsigned int len);
char			*ft_strdup(const char *s1);
char			*ft_itoa_base(long long n, int base, t_body **body);
unsigned int	ft_tounsgdint(int num);
int				ft_atoi(const char **str);
int				ft_toupper(int ch);
void			ft_space_counter(t_body **body);
void			ft_zero_counter(t_body **body);
void			ft_body_size(t_body **body);
void			ft_output_upperx(const char **format,
				t_body **body, va_list **ap);
void			ft_output_x(const char **format, t_body **body, va_list **ap);
void			ft_output_p(const char **format, t_body **body, va_list **ap);
void			ft_output_udi(const char **format, t_body **body, va_list **ap);
void			ft_output_str(const char **format, t_body **body, va_list **ap);
void			ft_putarg(t_body **body);
void			ft_output_chr(const char **format, t_body **body, va_list **ap);
void			ft_output_perc(const char **format, t_body **body);
void			ft_pars_type(const char **format, t_body **body, va_list **ap);
void			ft_pars_precision(const char **format,
				t_body **body, va_list **ap);
void			ft_pars_width(const char **format, t_body **body, va_list **ap);
void			ft_pars_flag(const char **format, t_body **body, va_list **ap);
void			ft_processing(t_body **body);
int				ft_parser(const char **format, va_list *ap, t_body *body);
int				ft_printf(const char *format, ...);

#endif
