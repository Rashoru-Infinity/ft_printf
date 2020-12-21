/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zerocut.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 00:50:02 by khagiwar          #+#    #+#             */
/*   Updated: 2020/11/28 00:50:04 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

void	ft_zerocut(char *str, size_t size)
{
	size_t	offset;

	offset = 0;
	while (str[offset] && str[offset] == '0')
		++offset;
	if (!str[offset])
	{
		*str = '0';
		ft_bzero(&str[1], offset - 1);
		return ;
	}
	ft_memmove(str, &str[offset], size * 2 - offset);
	str[size * 2 - offset] = '\0';
}
