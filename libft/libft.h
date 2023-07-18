/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 20:16:53 by egeraldo          #+#    #+#             */
/*   Updated: 2023/07/18 14:37:42 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>

int				ft_atoi(char *str);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
size_t			ft_strlen(char *str);
size_t			ft_strlcpy(char *dest, char *src, size_t size);
int				ft_tolower(int c);
int				ft_toupper(int c);
void			*ft_memset(void *s, int c, size_t n);
void			ft_bzero(void *buff, size_t n);

#endif