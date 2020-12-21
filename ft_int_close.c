/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_close.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 17:47:45 by khagiwar          #+#    #+#             */
/*   Updated: 2020/12/11 17:47:46 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int	ft_int_close(int val, int argc, ...)
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
