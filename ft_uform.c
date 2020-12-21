/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uform.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 20:20:48 by khagiwar          #+#    #+#             */
/*   Updated: 2020/11/28 20:20:49 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include <limits.h>

static int	ft_getalloclen(t_format tf, unsigned int n)
{
	int	size;

	size = ft_count_digit(tf, (long long)n);
	if (tf.scale)
		size = *(tf.scale) > size ? *(tf.scale) : size;
	if (tf.width)
		size = *(tf.width) > size ? *(tf.width) : size;
	return (size);
}

char		*ft_uform(t_format tf, va_list *ap, int *len)
{
	unsigned int	n;
	char			*str;

	n = va_arg(*ap, unsigned int);
	*len = ft_getalloclen(tf, n);
	if (!(str = (char *)malloc(sizeof(char) * *len)))
		return (NULL);
	ft_setnbr(tf, (long long)n, str);
	return (str);
}
