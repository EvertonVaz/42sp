/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:55:05 by egeraldo          #+#    #+#             */
/*   Updated: 2023/08/24 10:50:22 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_F_H
# define FT_PRINT_F_H

#include <stdarg.h>
#include <unistd.h>

size_t	ft_putchar(char c);
size_t	ft_strlen(char *s);
size_t	ft_putstr(char *s);
size_t	ft_put_pointer(unsigned long num);
size_t	ft_putnbr_base(long int num, char *base);
char	*ft_strchr(const char *s, int c);
int		ft_printf(const char *format, ...);

#endif