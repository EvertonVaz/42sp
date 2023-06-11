/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:24:28 by egeraldo          #+#    #+#             */
/*   Updated: 2023/06/10 18:58:32 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Reproduzir de forma idêntica o funcionamento da função strncmp (man strncmp).

// A função strncmp compara os primeiros n caracteres das strings str1 e str2. 
// Ela retorna um valor inteiro que indica a relação entre as duas strings, 
// seguindo a mesma convenção da função strcmp:
// Um valor menor que zero, se os primeiros n caracteres de str1 
// são menores que os primeiros n caracteres de str2
// Zero, se os primeiros n caracteres de str1 são iguais n caracteres de str2.
// Um valor maior que zero, 
// Se os primeiros n caracteres de str1  são maiores n caracteres de str2

int	ft_strncmp(char *s1, char *s2, unsigned int n);

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	while (n > 0 && (*s1 != '\0' || *s2 != '\0'))
	{
		if (*s1 != *s2)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		s1++;
		s2++;
		n--;
	}
	return (0);
}
