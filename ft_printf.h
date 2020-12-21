/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 19:34:23 by khagiwar          #+#    #+#             */
/*   Updated: 2020/11/20 19:34:25 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"
# include <stdbool.h>
# define FT_STDOUT 1

typedef	unsigned long long	t_ull;

typedef struct	s_format {
	char	flag;
	int		*width;
	int		*scale;
	char	specifer;
	bool	ign_scale;
}				t_format;

typedef enum {
	FAIL = -1,
	SUCCESS = 1
}	t_status;

char			*ft_charform(t_format tf, va_list *ap, int *len);
char			*ft_strform(t_format tf, va_list *ap, int *len);
char			*ft_pform(t_format tf, va_list *ap, int *len);
char			*ft_diform(t_format tf, va_list *ap, int *len);
char			*ft_uform(t_format tf, va_list *ap, int *len);
char			*ft_lowxform(t_format tf, va_list *ap, int *len);
char			*ft_upxform(t_format tf, va_list *ap, int *len);
char			*ft_prcntform(t_format tf, int *len);
int				ft_format_handler(t_format tf, va_list *ap, char **str);
int				ft_specifier(char **head, va_list *ap, char **str);
int				ft_printf(const char *format, ...);
char			*ft_hex(t_ull n, size_t byte);
void			ft_zerocut(char *str, size_t size);
int				ft_int_close(int val, int argc, ...);
char			*ft_close(char *val, int argc, ...);
int				ft_count_digit(t_format tf, long long n);
void			ft_setnbr(t_format tf, long long n, char *dest);
void			ft_sethex(t_format tf, char *dest, char *rawhex);
int				ft_write(char *lp, va_list *ap, int size);
int				ft_atoi_format(char **s, int **n, va_list *ap, char *flag);

#endif
