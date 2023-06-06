/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 15:28:30 by egeraldo          #+#    #+#             */
/*   Updated: 2023/06/05 20:17:12 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src);

char	*ft_strcpy(char *dest, char *src)
{
	char	*temp;
	int		i;

	i = 0;
	temp = dest;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	i++;
	src[i] = '\0';
	return (temp);
}
