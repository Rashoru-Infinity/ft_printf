/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 22:45:22 by khagiwar          #+#    #+#             */
/*   Updated: 2020/11/24 22:45:23 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

char	*ft_hex(t_ull n, size_t byte)
{
	char	*hexinfo;
	int		size;
	char	hexchar[16];
	int		i;

	i = 0;
	while (i < 16)
	{
		if (i < 10)
			hexchar[i] = '0' + i;
		else
			hexchar[i] = 'a' + i - 10;
		++i;
	}
	size = byte * 2;
	if (!(hexinfo = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	hexinfo[size] = '\0';
	while (--size >= 0)
	{
		hexinfo[size] = hexchar[n % 16];
		n /= 16;
	}
	return (hexinfo);
}
