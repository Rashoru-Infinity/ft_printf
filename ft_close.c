/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 02:51:37 by khagiwar          #+#    #+#             */
/*   Updated: 2020/11/28 02:51:39 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

char	*ft_close(char *val, int argc, ...)
{
	va_list	args;
	int		i;

	va_start(args, argc);
	i = 0;
	while (i++ < argc)
		free(va_arg(args, void *));
	va_end(args);
	return (val);
}
