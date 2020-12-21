/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charform.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 11:16:59 by khagiwar          #+#    #+#             */
/*   Updated: 2020/12/11 03:50:28 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <stdio.h>

static void	ft_fillchr(char **dest, char c, size_t size)
{
	ft_memset(*dest, c, size);
	*dest += size;
}

char		*ft_charform(t_format tf, va_list *ap, int *len)
{
	char	*str;
	char	*rdp;
	char	content;

	*len = 1;
	if (tf.width)
		*len = *(tf.width) > *len ? *(tf.width) : *len;
	content = va_arg(*ap, unsigned int);
	if (!(str = (char *)malloc(sizeof(char) * *len)))
		return (NULL);
	rdp = str;
	if (!tf.flag)
	{
		ft_fillchr(&rdp, ' ', *len - 1);
		ft_fillchr(&rdp, content, 1);
	}
	if (tf.flag == '-')
	{
		ft_fillchr(&rdp, content, 1);
		ft_fillchr(&rdp, ' ', *len - 1);
	}
	return (str);
}
