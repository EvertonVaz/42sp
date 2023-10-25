<h1 align="center"> Fract-ol </h1>

<div align="center">
	<p>
		<a href="https://github.com/EvertonVaz/42sp/tree/main/fractol" target="_blank">
			<img height=170 src="https://game.42sp.org.br/static/assets/achievements/fract-olm.png" hspace = "10">
		</a>
	</p>

# [125/100]
</div>

## Sobre o Projeto
Fractol é um projeto que me permitiu mergulhar profundamente na matemática dos fractais e na programação gráfica. Foi um desafio entender os cálculos complexos envolvidos na criação de fractais e lidar com a biblioteca gráfica minilibx da Codam. No entanto, acredito que essas dificuldades me ajudaram a crescer como programador e aprofundar minha compreensão da linguagem C.

O projeto consiste em várias implementações de fractais, incluindo o conjunto de Mandelbrot, o conjunto de Julia, o conjunto Borning Ship e o Tricorn. Cada um desses fractais é renderizado em tempo real, permitindo que você explore a beleza infinita e a complexidade dessas formas matemáticas.

## Funcionalidades

- **Exploração de Fractais**: Fractol oferece a capacidade de explorar diferentes tipos de fractais
Cada fractal oferece uma experiência visual única.

- **Interatividade**: Com o Fractol, você pode mergulhar nos detalhes dos fractais. Você pode navegar, ampliar e aplicar zoom nos fractais para explorar suas estruturas complexas.

- **Controles Personalizáveis**: Os controles do Fractol são personalizáveis para proporcionar uma experiência de usuário flexível. Você pode ajustar parâmetros como [cores](https://github.com/EvertonVaz/42sp/blob/main/fractol/src/color.c) e [iterações](https://github.com/EvertonVaz/42sp/blob/main/fractol/src/choose_fractal.c).

## Pré-Requisitos

- Para executar o Fractol, você precisa ter uma máquina com a biblioteca gráfica minilibx instalada. Eu deixei um clone dela junto com o repositorio para facilitar a execução do projeto em ambiente linux
- [Documentação](https://github.com/EvertonVaz/42sp/tree/main/fractol/.lib/MLX42) para configurar para outros ambientes

## Como Compilar e Executar
1. Clone este repositório para o seu computador.
2. Navegue até o diretório do projeto.
3. Compile o Fractol executando o comando `make` no terminal.
4. Após a compilação, você pode executar o programa com o comando `./fractol nome_do_fractal`, onde `nome_do_fractal` pode ser substituído por Mandelbrot, Julia, Burn ou Tricorn.
## Exemplo de Uso
```
	USAGE:
        ./fractol [nome_do_fractal][params]

	EXAMPLES:
			./fractol mandelbrot              Mandelbrot fractal
			./fractol julia 0.285 +0.01i      Julia fractal
			./fractol burn                    Burning ship fractal
			./fractol tricorn                 Tricorn fractal
```

## Controles
- Use o scroll do mouse dar zoom in e zoom out e navegar pelas profundezas do fractal.
- Para andar pelo fractol você pode utilizar tanto as setas como ASDW
- Você pode alterar as cores com os numeros do 1 ao 4 (acima das letras)
	o numero 5 ativa/desativa cores dinamicas conforme o movimento
- Você pode alterar pelos fractais com os numeros 1 ao 4 (teclado numerico)
- Especificamente no conjunto Julia você pode segurar o shift (esquerdo) e andar com o mouse o modificando

##