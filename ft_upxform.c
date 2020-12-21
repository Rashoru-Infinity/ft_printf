/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_upxform.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 17:11:56 by khagiwar          #+#    #+#             */
/*   Updated: 2020/11/29 17:11:57 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_strup(char *str)
{
	while (*str)
	{
		*str = ft_toupper(*str);
		++str;
	}
}

char		*ft_upxform(t_format tf, va_list *ap, int *len)
{
	char *str;

	if (!(str = ft_lowxform(tf, ap, len)))
		return (NULL);
	ft_strup(str);
	return (str);
}
