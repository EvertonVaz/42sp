/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 21:41:58 by egeraldo          #+#    #+#             */
/*   Updated: 2023/06/06 11:12:50 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// • Reproduzir de forma idêntica o funcionamento da função strcmp (man strcmp).
// • Ela deverá ser prototipada da seguinte maneira:
// Essa função compara duas strings, str1 e str2, 
// retorna um valor inteiro que indica a relação entre as duas strings. 
// Os possíveis valores de retorno são:
// Um valor menor que zero, se str1 é menor que str2
// Zero, se str1 é igual a str2.
// Um valor maior que zero, se str1 é maior que str2

int	ft_strcmp(char *s1, char *s2);

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
