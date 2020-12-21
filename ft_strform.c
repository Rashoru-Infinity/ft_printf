/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strform.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 01:35:16 by khagiwar          #+#    #+#             */
/*   Updated: 2020/12/11 16:56:58 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static int		ft_arglen(t_format tf, const char *content)
{
	int arglen;

	if (content)
		arglen = (int)ft_strlen(content);
	else
		arglen = (int)ft_strlen("null");
	if (tf.scale && (*(tf.scale) >= 0 || !tf.ign_scale))
		arglen = arglen > *(tf.scale) ? *(tf.scale) : arglen;
	return (arglen);
}

static	int		ft_getalloclen(t_format tf, const char *content)
{
	int len;

	if (!content)
	{
		if (tf.width)
		{
			return (*(tf.width) > ft_arglen(tf, "(null)") ?
			*(tf.width) : ft_arglen(tf, "(null)"));
		}
		return (ft_arglen(tf, "(null)"));
	}
	len = ft_arglen(tf, content);
	if (tf.width)
		len = *(tf.width) > len ?
		*(tf.width) : len;
	return (len);
}

static void		ft_setstr(char *s, t_format tf, char *content, size_t arglen)
{
	if (tf.flag == '-')
	{
		ft_memcpy(s, content, arglen);
		s += arglen;
	}
	if (tf.flag == '0')
		ft_memset(s, '0', ft_getalloclen(tf, content) - arglen);
	else
		ft_memset(s, ' ', ft_getalloclen(tf, content) - arglen);
	s += (ft_getalloclen(tf, content) - arglen);
	if (tf.flag != '-')
		ft_memcpy(s, content, arglen);
}

char			*ft_strform(t_format tf, va_list *ap, int *len)
{
	char *arg;
	char *str;

	arg = va_arg(*ap, char *);
	*len = ft_getalloclen(tf, arg);
	if (!(str = (char *)malloc(sizeof(char) * *len)))
		return (NULL);
	if (!arg)
		arg = "(null)";
	ft_setstr(str, tf, arg, ft_arglen(tf, arg));
	return (str);
}
