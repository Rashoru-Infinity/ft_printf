/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 22:47:47 by khagiwar          #+#    #+#             */
/*   Updated: 2020/12/16 22:47:48 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <limits.h>

static int	ft_format(char *head, va_list *ap, t_format *tf)
{
	*tf = (t_format){'\0', NULL, NULL, '\0', false};
	++head;
	while (*head == '0' || *head == '-')
	{
		if (*head == '0' && tf->flag == '-')
			++head;
		else
			tf->flag = *(head++);
	}
	if ((ft_isdigit(*head) || *head == '*')
	&& ft_atoi_format(&head, &(tf->width), ap, &(tf->flag)) == FAIL)
		return (FAIL);
	if (*head == '.')
	{
		while (*head == '.')
			head++;
		if (ft_atoi_format(&head, &(tf->scale), ap, NULL) == FAIL)
			return (ft_int_close(FAIL, 1, tf->width));
	}
	tf->specifer = *(head++);
	return (SUCCESS);
}

static int	ft_estimate(char *spec, va_list *ap, int out, size_t presize)
{
	t_format	tf;
	va_list		ap2;
	char		specf;

	va_copy(ap2, *ap);
	if (ft_format(spec, &ap2, &tf) == FAIL)
		return (FAIL);
	va_end(ap2);
	specf = tf.specifer;
	if (tf.width)
	{
		if ((long long)presize + (long long)out + (long long)*(tf.width)
		> (long long)INT_MAX - 1)
			return (ft_int_close(FAIL, 2, tf.width, tf.scale));
	}
	if (tf.scale && specf != 's' && specf != 'c' && specf != '%')
	{
		if (specf == 'p' && presize + (long long)out + (long long)*(tf.scale)
		>= (long long)INT_MAX - 3)
			return (ft_int_close(FAIL, 2, tf.width, tf.scale));
		if ((long long)presize + (long long)out + (long long)*(tf.scale)
		> (long long)INT_MAX - 1)
			return (ft_int_close(FAIL, 2, tf.width, tf.scale));
	}
	return (ft_int_close(SUCCESS, 2, tf.width, tf.scale));
}

int			ft_write(char *lastp, va_list *ap, int out_size)
{
	char	*str;
	size_t	presize;
	int		tmp;
	char	*last_cpy;
	char	*specifier;

	while ((specifier = ft_strchr(lastp, '%')))
	{
		last_cpy = lastp;
		presize = specifier - lastp;
		if (presize >= (size_t)INT_MAX
		|| ft_estimate(specifier, ap, out_size, presize) == FAIL)
			return (FAIL);
		if ((tmp = ft_specifier(&specifier, ap, &str)) == FAIL)
			return (FAIL);
		if (presize + (size_t)tmp + (size_t)out_size >= (size_t)INT_MAX)
			return (ft_int_close(FAIL, 1, str));
		out_size += write(FT_STDOUT, last_cpy, presize);
		out_size += write(FT_STDOUT, str, tmp);
		free(str);
		lastp = specifier;
	}
	if (ft_strlen(lastp) + (size_t)out_size >= (size_t)INT_MAX)
		return (FAIL);
	return (out_size + write(FT_STDOUT, lastp, ft_strlen(lastp)));
}
