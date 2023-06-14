/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_c04.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 19:52:00 by egeraldo          #+#    #+#             */
/*   Updated: 2023/06/12 13:24:09 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../C04/ex00/ft_strlen.c"
// #include "../C04/ex01/ft_putstr.c"
// #include "../C04/ex02/ft_putnbr.c"
// #include "../C04/ex03/ft_atoi.c"
// #include "../C04/ex04/ft_putnbr_base.c"

int		ft_strlen(char *str);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
int		ft_atoi(char *str);
void	ft_putnbr_base(int nbr, char *base);

#include <stdio.h>
#include<unistd.h>

int	main(void)
{
	printf("EXERCICIO 00\n");
	printf("%i", ft_strlen("Escreva qualquer coisa"));
	
	printf("\n\nEXERCICIO 01\n");
	ft_putstr("Escreva qualquer coisa\n");
	
	printf("\nEXERCICIO 02\n");
	ft_putnbr(-2147483648);
	printf("\n");
	ft_putnbr(2147483647);
	
	printf("\n\nEXERCICIO 03\n");
    char *str = "    \v   \n   +-+-++-8415a64546";
    char str2[] = "   ---+--+1234ab567";
    printf("%d\n", ft_atoi(str));
    printf("%d\n", ft_atoi(str2));
	
	printf("\nEXERCICIO 04\n");
	printf("\nBINARIO\n");
	ft_putnbr_base(12345, "01");
	printf("\n");
	ft_putnbr_base(-12345, "01");
	printf("\nOCTAL\n");
	ft_putnbr_base(12345, "poneyvif");
	printf("\n");
	ft_putnbr_base(-2147483648, "ev rton!");
	printf("\nDECIMAL\n");
	ft_putnbr_base(-2147483648, "0123456789");
	printf("\n");
	ft_putnbr_base(12345, "0123456789");
	printf("\n");
	ft_putnbr_base(2147483647, "abcdefghij");
	printf("\n");
	ft_putnbr_base(-12345, "abcdefghij");
	printf("\nHEXADECIMAL\n");
	ft_putnbr_base(-12345, "0123456789ABCDEF");
	printf("\n");
	ft_putnbr_base(12345, "0123456789ABCDEF");

	printf("\nTESTE DE ERROS");
	printf("\nBINARIO\n");
	ft_putnbr_base(12345, "0");
	printf("\nOCTAL\n");
	ft_putnbr_base(12345, "pone+vif");
	printf("\nDECIMAL\n");
	ft_putnbr_base(-2147483648, "0123\n56789");
	printf("\nHEXADECIMAL\n");
	ft_putnbr_base(-12345, "0123456779ABCDEF");
	return (0);
}