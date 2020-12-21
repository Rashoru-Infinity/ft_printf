/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_diform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 17:05:41 by khagiwar          #+#    #+#             */
/*   Updated: 2020/11/28 17:05:43 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include <limits.h>

static int	ft_getalloclen(t_format tf, long long n)
{
	int	size;

	size = ft_count_digit(tf, n);
	if (tf.scale && *(tf.scale) >= 0)
		size = *(tf.scale) > size ? *(tf.scale) : size;
	if (n < 0)
		++size;
	if (tf.width)
		size = *(tf.width) > size ? *(tf.width) : size;
	return (size);
}

char		*ft_diform(t_format tf, va_list *ap, int *len)
{
	long long	n;
	char		*str;

	n = (long long)va_arg(*ap, int);
	if (n < INT_MIN || n > INT_MAX)
		return (NULL);
	*len = ft_getalloclen(tf, n);
	if (!(str = (char *)malloc(sizeof(char) * *len)))
		return (NULL);
	ft_setnbr(tf, n, str);
	return (str);
}
