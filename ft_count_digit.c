/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs_digit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 20:32:53 by khagiwar          #+#    #+#             */
/*   Updated: 2020/12/10 18:17:24 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_digit(t_format tf, long long n)
{
	int digit;

	if (tf.scale && *(tf.scale) <= 0
	&& ((!tf.ign_scale || !tf.width) && n == 0))
		return (0);
	digit = 1;
	if (n < 0)
		n *= -1;
	while (n >= 10)
	{
		++digit;
		n /= 10;
	}
	return (digit);
}
