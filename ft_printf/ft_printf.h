/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etovaz <etovaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:55:05 by egeraldo          #+#    #+#             */
/*   Updated: 2023/08/26 03:44:48 by etovaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

# define HEXALOW	"0123456789abcdef"
# define HEXAUPP	"0123456789ABCDEF"
# define FORMATS	"cspdiuxX"
# define FLAGS		"#0+- ."
# define DECIMAL	"0123456789"

size_t	ft_putchar(char c);
size_t	ft_strlen(const char *s);
size_t	ft_putstr(char *s);
size_t	ft_put_pointer(unsigned long num);
size_t	ft_putnbr_base(long int num, char *base);
char	*ft_strchr(const char *s, int c);
char	find_type(const char *str);
int		put_flag(char flag, char type);
int		invalid_flag(const char *format);
int		ft_printf(const char *format, ...);

#endif