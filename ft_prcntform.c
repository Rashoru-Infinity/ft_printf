/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prcntform.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 03:29:57 by khagiwar          #+#    #+#             */
/*   Updated: 2020/11/29 03:29:59 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static void	ft_setprcnt(char *dest, t_format tf)
{
	if (tf.width && *(tf.width) >= 1)
	{
		if (tf.flag == '0')
		{
			ft_memset(dest, '0', *(tf.width) - 1);
			dest[*(tf.width) - 1] = '%';
		}
		else if (tf.flag == '-')
		{
			*(dest++) = '%';
			ft_memset(dest, ' ', *(tf.width) - 1);
		}
		else
		{
			ft_memset(dest, ' ', *(tf.width) - 1);
			dest[*(tf.width) - 1] = '%';
		}
	}
	else
		*dest = '%';
}

char		*ft_prcntform(t_format tf, int *len)
{
	char	*str;

	*len = 1;
	if (tf.width)
		*len = *(tf.width);
	if (!(str = (char *)malloc(sizeof(char) * *len)))
		return (NULL);
	ft_setprcnt(str, tf);
	return (str);
}
