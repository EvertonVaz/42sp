<h1 align="center"> ft_printf </h1>

<div align="center">
<p>
<a href="https://github.com/EvertonVaz/42sp/tree/main/ft_printf" target="_blank">
	<img height=170 src="https://game.42sp.org.br/static/assets/achievements/ft_printfm.png" hspace = "10">
</a>
</p>
<p>
<a href="https://github.com/JaeSeoKim/badge42">
<img src="https://badge42.vercel.app/api/v2/clk1frjdc004908mhk2togjaz/project/3227385" alt="egeraldo's 42 ft_printf Score" />
</a>
	</p>
</div>

## Resumo

Bem-vindo ao projeto **ft_printf**! Neste desafio, você terá a oportunidade única de mergulhar nos detalhes da linguagem C, explorando a função `printf` de uma maneira totalmente nova. O projeto consiste em recriar a função `printf` a partir do zero, permitindo que você compreenda o funcionamento interno de uma das funções mais icônicas da biblioteca padrão C.

## Uso

Para utilizar a função `ft_printf`, basta incluir o arquivo de cabeçalho `ft_printf.h` em seu programa e chamar a função `ft_printf` conforme necessário.

Exemplo:

```c
#include "ft_printf.h"

int main() {
    ft_printf("Hello, World! %d", 42);
    return 0;
}
```

Neste exemplo, a função `ft_printf` imprimirá "Hello, World! 42" na saída.

## Motivação

O objetivo deste projeto é ir além do uso básico da função `printf` e realmente entender como ela é implementada. Isso envolve trabalhar com argumentos variáveis, formatação de strings, conversões de tipos e até mesmo interações com o sistema operacional. A recriação da função `printf` é uma tarefa desafiadora, mas altamente recompensadora, que aumentará sua compreensão da linguagem C e programação de forma geral.

## O que você aprende neste projeto?

- **Manipulação de Argumentos Variáveis**: Você explorará como lidar com argumentos de diferentes tipos e quantidades usando a biblioteca `stdarg.h`. Isso o ajudará a entender como a função `printf` é capaz de aceitar um número variável de argumentos.

- **Funcionamento Interno do I/O**: Ao recodificar a função `printf`, você ganhará insights sobre como os sistemas operacionais gerenciam a entrada e saída de dados. Isso é crucial para entender como a função `printf` consegue exibir informações formatadas no console.

- **Organização e Modularização**: Ao criar a sua versão da função `printf`, você será desafiado a estruturar seu código de forma clara e modular. Isso o ajudará a melhorar suas habilidades de organização em projetos maiores.

## Referências e Recursos Adicionais

- [printf - C++ Reference](https://en.cppreference.com/w/c/io/fprintf)
- [Variadic Arguments in C](https://www.tutorialspoint.com/cprogramming/c_variable_arguments.htm)
- [Materiais sobre Acelera Printf](https://www.notion.so/Acelera-Printf-9b57272e356c45968455fe31b47952fc)
