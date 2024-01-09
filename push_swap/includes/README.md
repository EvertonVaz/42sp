<h1 align="center"> PUSH_SWAP </h1>

<div align="center">
	<p>
		<a href="https://github.com/EvertonVaz/42sp/tree/main/push_swap" target="_blank">
			<img height=170 src="https://game.42sp.org.br/static/assets/achievements/push_swapm.png" hspace = "10">
		</a>
	</p>

# [125/100]

</div>

## Resumo

O projeto Push Swap é um desafio que envolve a implementação de um algoritmo eficiente para ordenar uma lista de números usando duas pilhas e um conjunto de instruções específicas da linguagem Push Swap.

## Breve Explicação de Como o Push Swap Funciona

O Push Swap opera usando duas pilhas, A e B, e um conjunto limitado de instruções para manipular essas pilhas. O objetivo é ordenar os números na pilha A usando a menor quantidade possível de instruções.

O algoritmo desenvolvido neste projeto explora diversas formas de ordenação e utiliza técnicas eficientes para minimizar a quantidade de instruções necessárias para ordenar a lista.

Durante o desenvolvimento deste projeto, optei por utilizar a estrutura de dados de lista duplamente encadeada para representar as listas.
Essa escolha proporcionou uma manipulação eficiente dos elementos, essencial para o sucesso do algoritmo.

## Instruções

1. Compile o programa utilizando o Makefile:
   ```bash
   make && make bonus
   ```

2. Execute o programa com a lista de números desordenados como argumentos:
   ```bash
   ./push_swap 4 2 7 1 3
   ```

## Exemplo

Suponha que temos a seguinte lista desordenada: 4 2 7 1 3. O programa Push Swap gerará um conjunto mínimo de instruções para ordenar essa lista, como:
   ```
   ra
   pb
   ra
   pb
   pa
   ra
   pa
   rra
   ```
Verificar se a lista realmente foi ordenada
   ```bash
   ./push_swap 4 2 7 1 3 | ./checker 4 2 7 1 3
   ```
O resultado deve ser OK


## Minha Experiência Construindo Este Projeto

Desenvolver o projeto Push Swap foi um desafio estimulante. Ao enfrentar a tarefa de ordenar uma lista, tive que explorar diferentes abordagens e ler diversos artigos para chegar a uma solução eficiente. A jornada foi incrível e proporcionou um aprofundamento nos conceitos de algoritmos e complexidade.

---
