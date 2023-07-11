/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 21:27:12 by egeraldo          #+#    #+#             */
/*   Updated: 2023/06/08 17:13:17 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Reproduzir de forma idêntica o funcionamento da função strncat (man strncat).
// A strncat()função acrescenta os primeiros n caracteres 
// da string terminada em nulo apontada pela origem
// à string terminada em nulo apontada para o destino
// O primeiro caractere da origem substitui o terminador nulo do destino. 
// A função retorna o ponteiro para a string de destino.

// A origem não deve se sobrepor ao destino, 
// e o destino deve ser grande o suficiente
// para conter a string resultante concatenada, 
// incluindo o caractere nulo adicional.

char	*ft_strncat(char *dest, char *src, unsigned int nb);

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char	*temp;

	temp = dest;
	while (*dest != '\0')
	{
		dest++;
	}
	while (*src != '\0' && nb > 0)
	{
		*dest = *src;
		dest++;
		src++;
		nb--;
	}
	*dest = '\0';
	return (temp);
}
