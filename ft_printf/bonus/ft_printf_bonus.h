/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:55:05 by egeraldo          #+#    #+#             */
/*   Updated: 2023/08/28 21:06:47 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define HEXALOW "0123456789abcdef"
# define HEXAUPP "0123456789ABCDEF"
# define FORMATS "cspdiuxX%"
# define FLAGS "#0+- ."
# define DECIMAL "0123456789"

size_t	ft_putchar(char c);
size_t	ft_putstr(char *s);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	find_type(const char *str);
char	get_flag(char flag);
int		ft_atoi(const char *str);
size_t	ft_putwidth(int width);
size_t	ft_intlen(int n);
size_t	ft_putnbr_base(long int num, char flag, char type, int time);
size_t	ft_putnbr_hex(unsigned long num, char type, char flag, int time);
size_t	ft_put_pointer(unsigned long num);
size_t	put_porcent(char flag);
int		ft_printf(const char *format, ...);

#endif