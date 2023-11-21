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

blue() {
    echo -e "\033[0;34m$1\033[0m"
}

# Função para gerar um emoji aleatório da tabela Unicode
gerar_emoji_aleatorio() {
    emojis=("🎉" "😊" "🚀" "🌈" "🍕" "🐧" "🔥" "💻" "👾" "🌟" "😀" "😂" "❤️" "😍" "🤔" "👍" "👏" "👌" "🙌" "😊" "🎉" "🌟" "🚀" "💯" "🙏" "😎" "👀" "🍕" "🍔" "🍦" "🎈" "🎁" "📚" "🎮" "🎤" "🎬" "🏆" "🚗" "🚲" "🌈" "🌺" "🌍" "🍀" "🍁" "🍓" "🍇" "🍍" "🍩" "🍹" "🏖️" "🏠" "🏰" "🛫" "🛒" "⏰" "⚽" "🎸" "🎨" "🎯" "🎃" )
    random_index=$((RANDOM % ${#emojis[@]}))
    echo "${emojis[$random_index]}"
}

# Inicia o servidor em background e obtém seu PID
./server > output.txt &
sleep 1

# Capturar o PID do servidor a partir da saída
server_pid=$(grep "Server PID:" output.txt | awk '{print $3}')
echo "server pid number is $server_pid"
echo ""
echo "-----------------------------"

# Número de testes aleatórios
num_tests=10

# Tamanho máximo da mensagem
max_msg_length=50

# Gera e envia mensagens aleatórias
for ((i=1; i<=num_tests; i++))
do
    # Gera uma mensagem aleatória com tamanho variável, incluindo caracteres Unicode
    msg_length=$((1 + RANDOM % max_msg_length))
    random_msg=$(cat /dev/urandom | LC_CTYPE=C tr -dc '[:print:]' | tr -d '\000' | fold -w "$msg_length" | head -n 1)

    # verifica se há argumentos bonus e quantidade de emojis
    # exemplo: bonus 5
    if [[ $# -eq 2 && $1 == "bonus" ]]; then
    quantidade_emojis=$2
    emojis=""
    for ((emos=0; emos<quantidade_emojis; emos++)); do
        emojis+="$(gerar_emoji_aleatorio)"
    done
    else
        emojis=""  # Se a condição não for verdadeira, não adicionamos emojis
    fi
    # concatena a msg com os emojis
    random_msg=$random_msg$emojis
    # Limpa o arquivo de saída
    echo -n "" > output.txt

    # Exibe a mensagem aleatória gerada
    echo -e "$(blue "Teste $i: Enviando mensagem aleatória:")"
    echo "$random_msg"

    # Inicia o cliente com o PID do servidor e a mensagem aleatória
    ./client $server_pid "$random_msg"

    # Aguarda o cliente enviar a mensagem e o servidor escrever no arquivo
    sleep 1

    # Exibe o conteúdo do arquivo de saída de forma legível
    echo -e "$(blue "Conteúdo do arquivo de saída:")"
    cat output.txt
    echo ""

    # Busca a mensagem no arquivo de saída
    output=$(grep -aF "$random_msg" output.txt 2>/dev/null)
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
