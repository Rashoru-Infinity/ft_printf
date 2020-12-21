/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sethex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 23:30:07 by khagiwar          #+#    #+#             */
/*   Updated: 2020/12/11 01:46:02 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_fillchr(char **dest, char c, size_t size)
{
	ft_memset(*dest, c, size);
	*dest += size;
}

static int	ft_count_zero(t_format tf, char *rawhex)
{
	int digit;

	digit = ft_strlen(rawhex);
	if (tf.flag == '0' && tf.width)
		return (*(tf.width) - digit >= 0 ? *(tf.width) - digit : 0);
	if (tf.scale && *(tf.scale) > digit)
		digit = *(tf.scale);
	if (tf.scale && *(tf.scale) == 0)
		digit = 0;
	if ((size_t)digit < (size_t)ft_strlen(rawhex))
		return (0);
	return (digit - ft_strlen(rawhex));
}

static int	ft_count_spc(t_format tf, char *rawhex)
{
	int digit;
	int width;

	digit = ft_strlen(rawhex);
	if (tf.scale && *(tf.scale) == 0
	&& ft_strlen(rawhex) == 1 && *rawhex == '0')
		digit = 0;
	width = tf.width && *(tf.width) > digit ? *(tf.width) : digit;
	if (width - digit - ft_count_zero(tf, rawhex) < 0)
		return (0);
	return (width - digit - ft_count_zero(tf, rawhex));
}

void		ft_sethex(t_format tf, char *dest, char *rawhex)
{
	if (tf.flag == '0' && tf.scale)
		tf.flag = '\0';
	if (tf.flag == '-')
	{
		ft_fillchr(&dest, '0', ft_count_zero(tf, rawhex));
		if (!(tf.scale && *(tf.scale) == 0
		&& ft_strlen(rawhex) == 1 && *rawhex == '0'))
		{
			ft_memcpy(dest, rawhex, ft_strlen(rawhex));
			dest += ft_strlen(rawhex);
		}
	}
	ft_fillchr(&dest, ' ', ft_count_spc(tf, rawhex));
	if (tf.flag != '-')
	{
		ft_fillchr(&dest, '0', ft_count_zero(tf, rawhex));
		if (!(tf.scale && *(tf.scale) == 0
		&& ft_strlen(rawhex) == 1 && *rawhex == '0'))
		{
			ft_memcpy(dest, rawhex, ft_strlen(rawhex));
			dest += ft_strlen(rawhex);
		}
	}
}
