/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pform.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 12:17:55 by khagiwar          #+#    #+#             */
/*   Updated: 2020/12/11 00:06:04 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static int		ft_hex_digit(t_format tf, char *rawhex)
{
	if (!(tf.scale && *(tf.scale) == 0 && ft_strlen(rawhex) == 1
	&& *rawhex == '0'))
		return (ft_strlen(rawhex));
	return (0);
}

static int		ft_getalloclen(t_format tf, char *hexstr)
{
	if (!tf.width)
		return (ft_hex_digit(tf, hexstr) + 2);
	return (*(tf.width) > 2 + ft_hex_digit(tf, hexstr) ?
	*(tf.width) : 2 + ft_hex_digit(tf, hexstr));
}

static void		ft_setzerox(char *dest)
{
	*dest = '0';
	*(dest + 1) = 'x';
}

char			*ft_pform(t_format tf, va_list *ap, int *len)
{
	char				*hexstr;
	char				*str;

	if (!(hexstr = ft_hex((t_ull)va_arg(*ap, void *), (int)sizeof(t_ull))))
		return (NULL);
	ft_zerocut(hexstr, sizeof(t_ull));
	*len = (int)ft_getalloclen(tf, hexstr);
	if (!(str = (char *)malloc(sizeof(char) * *len)))
		return (NULL);
	if (tf.flag == '-')
	{
		ft_setzerox(str);
		ft_memcpy(&str[2], hexstr, ft_hex_digit(tf, hexstr));
		ft_memset(&str[ft_hex_digit(tf, hexstr) + 2], ' ',
		*len - (ft_hex_digit(tf, hexstr) + 2));
		return (ft_close(str, 1, hexstr));
	}
	ft_memset(str, ' ', *len - ft_hex_digit(tf, hexstr));
	ft_setzerox(&(str[*len - ft_hex_digit(tf, hexstr) - 2]));
	ft_memcpy(&str[*len - ft_hex_digit(tf, hexstr)],
	hexstr, ft_hex_digit(tf, hexstr));
	return (ft_close(str, 1, hexstr));
}
