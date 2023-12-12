<h1 align="center"> Minitalk </h1>

<div align="center">
	<p>
		<a href="https://github.com/EvertonVaz/42sp/tree/main/minitalk" target="_blank">
			<img height=170 src="https://game.42sp.org.br/static/assets/achievements/minitalkm.png" hspace = "10">
		</a>
	</p>

# [125/100]
</div>

# **Resumo**

O Minitalk é um projeto da 42 São Paulo que consiste em criar dois programas que se comunicam entre si usando um protocolo simples. O primeiro programa, o **server**, fica esperando por uma mensagem do segundo programa, o **client**. O **client** envia a mensagem digitada pelo usuário para o **server**, que a imprime na tela.

# **Requisitos**

Para completar o projeto Minitalk, você deve atender aos seguintes requisitos:

* Os programas **client** e **server** devem ser escritos em C.
* Os programas devem usar apenas os sinais SIGUSR1 e SIGUSR2 para se comunicar.
* O servidor deve imprimir seu PID após ser iniciado.
* O cliente deve aceitar dois parâmetros: o PID do servidor e a mensagem a ser enviada.
* O cliente deve enviar a mensagem para o servidor usando os sinais SIGUSR1 e SIGUSR2.
* O servidor deve receber a mensagem do cliente e imprimi-la na tela.
* O servidor deve poder receber mensagens de vários clientes ao mesmo tempo.

# **Instruções**

Para executar o minitalk, basta compilar os dois programas e executá-los em duas janelas diferentes.

```
make
```

Em uma janela, execute o **server** com o seguinte comando:

```
./server
```

Em outra janela, execute o **client** com o seguinte comando:

```
./client SERVER_PID <mensagem>
```

Onde **<mensagem>** é a mensagem que você deseja enviar para o **server**.

# **Exemplo**

Para enviar a mensagem "Olá, mundo!" para o **server**, execute o seguinte comando:

```
./client Olá, mundo!
```

O **server** imprimirá a mensagem na tela:

```
Olá, mundo!
```

# **Tester**
Também criei um tester para o minitalk, ele testa caracteres e emojis de forma aleatoria
você pode editar as variaveis dentro do arquivo chamadas num_tests=X e max_msg_length=Y
pelos valores que vc desejar

```
./tests.sh
ou
./tests.sh bonus N (onde N é a quantidade de emojis que vc deseja)
```

# **Protocolo de comunicação do Minitalk**

O protocolo Minitalk é um protocolo simples e eficiente para comunicação entre processos. Apesar de suas limitações, ele é uma boa opção para projetos educacionais e serve como uma base para entender outros protocolos de comunicação mais complexos.

### Sincronização

O Minitalk utiliza um mecanismo de sincronização simples para garantir que os bits sejam enviados e recebidos corretamente.

1. **Sinal de Confirmação:** Após cada envio de bit, o cliente espera o servidor enviar um sinal SIGUSR1 para confirmar o recebimento do bit.
2. **Variável de Sincronização:** A função `sync_client_server` no cliente define uma variável global `g_sync_signal` para indicar se o sinal de confirmação foi recebido.
3. **Loop de Espera:** A função `send_bit` no cliente entra em um loop de espera até que a variável `g_sync_signal` seja definida como `TRUE`, indicando que o sinal de confirmação foi recebido.

Este mecanismo de sincronização garante que o cliente não envie o próximo bit até que o servidor confirme o recebimento do bit anterior, prevenindo a perda de dados e garantindo a integridade da comunicação.

### Vantagens do Protocolo Minitalk

* **Simples:** O protocolo é fácil de entender e implementar.
* **Eficiente:** O protocolo utiliza apenas dois sinais, o que o torna eficiente em termos de recursos.
* **Robusto:** O mecanismo de sincronização garante a integridade da comunicação.
* **Flexível:** O protocolo pode ser facilmente adaptado para transmitir diferentes tipos de dados.

**Créditos**

Este projeto foi desenvolvido por Everton Vaz como parte do currículo da 42 São Paulo.