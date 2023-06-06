#include <stdio.h>

/*
int	main(void)
{
	int	*x;
	int	valor;
	int	y;

	valor = 35; // atribui valor a variavel
	x = &valor; // atribui o endereço da memoria da variavel valor a variavel x
	y = *x; // atribui o conteudo da variavel apontada por x a variavel y
	printf("endereço da variavel comum valor: %p\n", &valor);
	printf("lendo o conteudo do ponteiro x: %p\n", x);
	printf("Endereço da variavel ponteiro x: %p\n", &x);
	printf("conteudo da variavel apontada por x: %d\n", *x);
	printf("conteudo da variavel comum y: %d\n", y);
}


void	ft_ft(int *nbr) {
	*nbr = 42; // Atribui o valor 42 ao int apontado pelo ponteiro
}

int	main(void) {
	int num = 1123;
	int num2 = 10;
	printf("Valor inicial: %d\n", num);
	printf("endereço da variavel comum valor: %p\n", &num);
	printf("Valor inicial: %d\n", num2);
	printf("endereço da variavel comum valor: %p\n", &num2);


	ft_ft(&num); // Passa o endereço de num para a função ft_ft
	num2 = 12;

	printf("Valor após chamada da função: %d\n", num);
	printf("Valor após chamada da função: %p\n", &num);
	printf("Valor inicial: %d\n", num2);
	printf("endereço da variavel comum valor: %p\n", &num2);

	return (0);
}


void	ft_ultimate_ft(int *********nbr) {
	*********nbr = 42;
		// Atribui o valor 42 ao int apontado pela cadeia de ponteiros
}

int	main(void) {
	int num = 0;
	int *ptr1 = &num;
	int **ptr2 = &ptr1;
	int ***ptr3 = &ptr2;
	int ****ptr4 = &ptr3;
	int *****ptr5 = &ptr4;
	int ******ptr6 = &ptr5;
	int *******ptr7 = &ptr6;
	int ********ptr8 = &ptr7;
	int *********ptr9 = &ptr8;

	printf("Valor inicial: %d\n", num);

	ft_ultimate_ft(ptr9);
		// Passa o endereço do ponteiro ptr9 para a função ft_ultimate_ft

	printf("Valor após chamada da função: %d\n", num);

	return (0);
}

int main ()
{
	int	a;
	int	b;

  int *p ;                       // ponteiro para inteiros
  a = 231 ;
  b = 7680 ;
  printf ("&a vale %p, esse e o endereço de a\n", &a) ;  // endereço de a
  printf ("&b vale %p, esse e o endereço de c\n", &b) ;  // endereço de b
  printf ("&p vale %p esse e o endereço de p\n", &p) ;  // endereço de p
  printf ("p vale %p, p esta apontando para\n", p) ;    // valor de p (leitura)
									// este é o endereço para o qual p aponta
  p = &a ;                       // atribuir valor a p
  printf ("atribuimos o endereço de a (&a) para p, agora p aponta para %p\n",
	p) ;    // ler valor de p
  printf ("*p vale %d\n", *p) ;  // desreferenciar p
  p = &b ;
  printf ("p vale %p\n", p) ;
  printf ("*p vale %d\n", *p) ;
  *p = 500 ;                     // desreferenciar p (a posição apontada por p)
  printf ("b vale %d\n", b) ;
  return (0);
}

int main ()
{
  int *p ;
  // na linha abaixo, qual o valor apontado por p?
  printf ("p vale %p e vale \n", p) ;
  return (0);
}

int main ()
{
	int	a;

  a = 34 ;
  int b ;
  void *p ;
  p = &a ;
  b = *p ;  // erro de compilação!
  printf ("p vale %p\n", p) ;
  p++ ;
  printf ("p vale %p\n", p) ;
  return ((0));
}

int main ()
{
	int	a;

  a = 231 ;
  int *pd ;  // ponteiro direto
  int **pi ; // ponteiro indireto, equivale a int *(*p)
  pd = &a ;  // pd recebe o endereço de um int
  pi = &pd ; // pi recebe o endereço de um ponteiro para int
  printf ("a  está em %p e vale %d\n", &a, a) ;
  printf ("pd está em %p e vale %p\n", &pd, pd) ;
  printf ("pi está em %p e vale %p\n", &pi, pi) ;
  printf ("*pd  vale %d\n", *pd) ; // acessando o valor de a,
	disreferenciando o ponteiro e acessando o valor da variavel
  printf ("*pi  vale %p\n", *pi) ;
	// disreferenciando o primeiro ponteiro de pi,
	que esta apontando para onde o ponteiro de pd esta apontando
  printf ("**pi vale %d\n", **pi) ;
	// aqui acessando o valor de a a partir do ponteiro do ponteiro
  return (0);
}

int	main(void)
{
	int	nota[5];

	nota[5] = { 45, 78, 92, 73, 87 } ;
	int *p ;
	p = nota ; // p aponta para nota[0]
	printf ("p: %p, *p: %d\n", p, *p) ;
	p++ ;      // p aponta para nota[1]
	printf ("p: %p, *p: %d\n", p, *p) ;
	p += 3 ;   // p aponta para nota[4]
	printf ("p: %p, *p: %d\n", p, *p) ;
}

// troca por valor (normal)
void	troca(int x, int y)
{
	int	temp;

	temp = x;
	x = y;
	y = temp;
	printf("valor de x em troca(): %d\n", x);
	printf("valor de y em troca(): %d\n", y);
}
// troca por referencia (ponteiro)
void	troca_ponteiro(int *x, int *y)
{
	int	temp;

	temp = *x;
	*x = *y;
	*y = temp;
	printf("valor de x em troca(): %d\n", *x);
	printf("valor de y em troca(): %d\n", *y);
}

int	main(void)
{
	int	a;
	int	b;

	a = 5;
	b = 10;
	printf("valor de a antes da troca: %d \n", a);
	printf("valor de b antes da troca: %d \n", b);
	troca(a, b);
	printf("valor de a depois da troca sem ponteiro: %d \n", a);
	printf("valor de b depois da troca sem ponteiro: %d \n", b);
	troca_ponteiro(&a, &b);
	printf("valor de a depois da troca com ponteiro: %d \n", a);
	printf("valor de b depois da troca com ponteiro: %d \n", b);
	return (0);
}
*/

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	start;
	int	end;
	int	temp;

	start = 0;
	end = size - 1;
	while (start < end)
	{
		// Troca os valores das posições start e end
		temp = tab[start];
		tab[start] = tab[end];
		tab[end] = temp;
		start++;
		end--;
	}
}

int	main(void)
{
	int	array[];
	int	size;

	array[] = {1, 2, 3, 4, 5};
	size = sizeof(array) / sizeof(int);
	printf("Array original: ");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
	ft_rev_int_tab(array, size);
	printf("\nArray invertido: ");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
	return (0);
}
