/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 19:26:58 by khagiwar          #+#    #+#             */
/*   Updated: 2020/12/11 16:44:07 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

int			ft_atoi_format(char **s, int **n, va_list *ap, char *flag)
{
	char	atoistr[2];

	if (!(*n = (int *)ft_calloc(1, sizeof(int))))
		return (FAIL);
	if (**s == '*')
	{
		**n = va_arg(*ap, int);
		(*s)++;
		if (**n < 0 && flag)
		{
			*flag = '-';
			**n *= -1;
		}
		return (SUCCESS);
	}
	atoistr[1] = '\0';
	while (ft_isdigit(**s))
	{
		atoistr[0] = *((*s)++);
		if (INT_MAX / 10 < **n || **n * 10 > INT_MAX - ft_atoi(atoistr))
			return (ft_int_close(FAIL, 1, *n));
		**n *= 10;
		**n += ft_atoi(atoistr);
	}
	return (SUCCESS);
}

int			ft_format_handler(t_format tf, va_list *ap, char **str)
{
	int		alloc_len;

	*str = NULL;
	if (tf.specifer == 'c')
		*str = ft_charform(tf, ap, &alloc_len);
	if (tf.specifer == 's')
		*str = ft_strform(tf, ap, &alloc_len);
	if (tf.specifer == 'p')
		*str = ft_pform(tf, ap, &alloc_len);
	if (tf.specifer == 'd' || tf.specifer == 'i')
		*str = ft_diform(tf, ap, &alloc_len);
	if (tf.specifer == 'u')
		*str = ft_uform(tf, ap, &alloc_len);
	if (tf.specifer == 'x')
		*str = ft_lowxform(tf, ap, &alloc_len);
	if (tf.specifer == 'X')
		*str = ft_upxform(tf, ap, &alloc_len);
	if (tf.specifer == '%')
		*str = ft_prcntform(tf, &alloc_len);
	if (!(*str) && alloc_len != 0)
		return (FAIL);
	return (alloc_len);
}

int			ft_specifier(char **head, va_list *ap, char **s)
{
	t_format	tf;

	tf = (t_format){'\0', NULL, NULL, '\0', false};
	++(*head);
	while (**head == '0' || **head == '-')
	{
		if (**head == '0' && tf.flag == '-')
			++(*head);
		else
			tf.flag = *(*head)++;
	}
	if ((ft_isdigit(**head) || **head == '*')
	&& ft_atoi_format(head, &tf.width, ap, &tf.flag) == FAIL)
		return (FAIL);
	if (**head == '.')
	{
		while (**head == '.')
			(*head)++;
		tf.ign_scale = (**(head) == '*') ? true : false;
		if (ft_atoi_format(head, &tf.scale, ap, NULL) == FAIL)
			return (ft_int_close(FAIL, 1, tf.width));
	}
	tf.specifer = *((*head)++);
	return (ft_int_close(ft_format_handler(tf, ap, s), 2, tf.width, tf.scale));
}

int			ft_printf(const char *format, ...)
{
	char	*lastp;
	int		out_size;
	va_list	argp;

	out_size = 0;
	lastp = (char *)format;
	va_start(argp, format);
	if ((out_size = ft_write(lastp, &argp, out_size)) == FAIL)
		return (FAIL);
	va_end(argp);
	return (out_size);
}
