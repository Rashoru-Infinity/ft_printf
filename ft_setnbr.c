/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 20:33:13 by khagiwar          #+#    #+#             */
/*   Updated: 2020/12/11 03:23:48 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void	ft_fillchr(char **dest, char c, size_t size)
{
	ft_memset(*dest, c, size);
	*dest += size;
}

static int	ft_zero_count(t_format tf, long long n)
{
	int count;

	count = 0;
	if (tf.scale && *(tf.scale) >= 0)
		count = *(tf.scale) - ft_count_digit(tf, n);
	if (tf.flag == '0')
	{
		if (tf.width)
			count = *(tf.width) - ft_count_digit(tf, n);
	}
	if (n < 0 && tf.flag == '0')
		--count;
	if (count <= 0)
		return (0);
	return (count);
}

static int	ft_spc_count(t_format tf, long long n)
{
	int count;

	count = 0;
	if (tf.width)
		count = *(tf.width) - ft_zero_count(tf, n) - ft_count_digit(tf, n);
	if (n < 0)
		--count;
	if (count <= 0)
		count = 0;
	return (count);
}

static void	ft_fillnbr(t_format tf, long long n, char *dest)
{
	int			digit;
	int			i;
	long long	ncpy;

	ncpy = n;
	digit = n >= 0 ? ft_count_digit(tf, n) : ft_count_digit(tf, n) + 1;
	if (tf.flag && n < 0)
		*(dest++) = '-';
	if (ft_spc_count(tf, n) && tf.flag != '-')
		ft_fillchr(&dest, ' ', ft_spc_count(tf, n));
	if (!tf.flag && n < 0)
		*(dest++) = '-';
	if (ft_zero_count(tf, n))
		ft_fillchr(&dest, '0', ft_zero_count(tf, n));
	if (n < 0)
		--digit;
	i = 0;
	while (i < digit)
	{
		*(dest + digit - ++i) = n > 0 ? ncpy % 10 + '0' : (-ncpy) % 10 + '0';
		ncpy /= 10;
	}
	if (tf.flag == '-' && tf.width)
		ft_memset(dest + digit, ' ', ft_spc_count(tf, n));
}

void		ft_setnbr(t_format tf, long long n, char *dest)
{
	if (tf.flag == '0' && tf.scale && *(tf.scale) >= 0)
		tf.flag = '\0';
	ft_fillnbr(tf, n, dest);
}
