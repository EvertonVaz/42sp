#!/bin/bash

# Compila os programas
make

# Funções de cor
green() {
    echo -e "\033[32m$1\033[0m"
}

red() {
    echo -e "\033[0;31m$1\033[0m"
}

# Inicia o servidor em background e obtém seu PID
./server > output.txt &

# Capturar o PID do servidor a partir da saída
server_pid=$(grep "Server PID:" output.txt | awk '{print $3}')

# Aguarda o servidor iniciar
sleep 1

# Número de testes aleatórios
num_tests=10

# Tamanho máximo da mensagem
max_msg_length=20

# Gera e envia mensagens aleatórias
for ((i=1; i<=num_tests; i++))
do
    # Gera uma mensagem aleatória com tamanho variável, incluindo caracteres Unicode
    msg_length=$((1 + RANDOM % max_msg_length))
    random_msg=$(cat /dev/urandom | LC_CTYPE=C tr -dc '[:print:]' | fold -w "$msg_length" | head -n 1)

    # Limpa o arquivo de saída
    echo "" > output.txt
    sleep 1

    # Exibe a mensagem aleatória gerada
    echo "Teste $i: Enviando mensagem aleatória - $(green "$random_msg")"

    # Inicia o cliente com o PID do servidor e a mensagem aleatória
    ./client $server_pid "$random_msg"

    # Aguarda o cliente enviar a mensagem
    sleep 1

    # Exibe o conteúdo do arquivo de saída de forma legível
    echo "Conteúdo do arquivo de saída:"
    cat output.txt

    # Busca a mensagem no arquivo de saída
    output=$(grep -a "$random_msg" output.txt)
    if [[ ! -z $output ]]; then
        echo -e "$(green "Teste passou: O servidor recebeu corretamente a mensagem.")"
    else
        echo -e "$(red "Teste falhou: O servidor não recebeu a mensagem corretamente.")"
    fi

    echo "-----------------------------"
done

# Limpa
sleep 1
killall -9 server
rm server client output.txt
