/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lowxform.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 21:50:25 by khagiwar          #+#    #+#             */
/*   Updated: 2020/12/11 16:25:35 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <stdio.h>

static int	ft_getalloclen(t_format tf, const char *rawhex)
{
	int	size;

	size = ft_strlen(rawhex);
	if (tf.scale)
		size = (long long)*(tf.scale) > (long long)size ? *(tf.scale) : size;
	if (tf.scale && *(tf.scale) == 0 && !tf.ign_scale
	&& ft_strlen(rawhex) == 1 && *rawhex == '0')
		size = 0;
	if (tf.width)
		size = *(tf.width) > size ? *(tf.width) : size;
	return (size);
}

char		*ft_lowxform(t_format tf, va_list *ap, int *len)
{
	char			*rawhex;
	char			*str;

	if (!(rawhex = ft_hex((t_ull)va_arg(*ap, unsigned int),
	sizeof(unsigned int))))
		return (NULL);
	ft_zerocut(rawhex, sizeof(unsigned int));
	*len = ft_getalloclen(tf, rawhex);
	if (!(str = (char *)malloc(sizeof(char) * *len)))
		return (NULL);
	ft_sethex(tf, str, rawhex);
	return (ft_close(str, 1, rawhex));
}
