/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:55:05 by egeraldo          #+#    #+#             */
/*   Updated: 2023/08/28 14:27:52 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# define HEXALOW	"0123456789abcdef"
# define HEXAUPP	"0123456789ABCDEF"
# define FORMATS	"cspdiuxX"
# define DECIMAL	"0123456789"

size_t	ft_putchar(char c);
size_t	ft_strlen(const char *s);
size_t	ft_putstr(char *s);
size_t	ft_put_pointer(unsigned long num);
size_t	ft_putnbr_base(long int num, char *base);
char	*ft_strchr(const char *s, int c);
int		ft_printf(const char *format, ...);

#endif