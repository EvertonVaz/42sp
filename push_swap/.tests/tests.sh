#!/bin/bash

# Função para encontrar o caminho do executável push_swap
find_push_swap() {
    local executable="push_swap"

    # Verifica se o executável push_swap está no diretório atual
    if [ -x "$executable" ]; then
        echo "./$executable"
        return 0
    fi

    # Verifica se o executável push_swap está no diretório pai
    if [ -x "../$executable" ]; then
        echo "../$executable"
        return 0
    fi

    # Se não encontrar o executável, retorna uma string vazia
    echo ""
    return 1
}

# Encontrar o caminho do executável push_swap
push_swap=$(find_push_swap)

red() {
    echo -e "\033[0;31m$1\033[0m"
}

# Função para exibir mensagens em verde
green() {
    echo -e "\033[0;32m$1\033[0m"
}

# Teste sem argumentos
$push_swap
if [ $? -eq 0 ]; then
    red "Teste falhou: Sem argumentos - Deveria exibir 'Error' e sair com status de falha\n"
else
    green "Teste passou: Sem argumentos, não deveria exibir nada acima\n"
fi

# Teste com argumentos não inteiros
$push_swap arg1 arg2 arg3
if [ $? -eq 1 ]; then
    green "Teste passou: Argumentos não inteiros\n"
else
    red "Teste falhou: Argumentos não inteiros - Deveria exibir 'Error' e sair com status de falha\n"
fi

# Teste com argumentos fora do intervalo de inteiros
$push_swap 2147483648 -2147483649
if [ $? -eq 1 ]; then
    green "Teste passou: Argumentos fora do intervalo de inteiros\n"
else
    red "Teste falhou: Argumentos fora do intervalo de inteiros - Deveria exibir 'Error' e sair com status de falha\n"
fi

# Teste com argumentos duplicados
$push_swap 0 1 2 4 1 9
if [ $? -eq 1 ]; then
    green "Teste passou: Argumentos duplicados\n"
else
    red "Teste falhou: Argumentos duplicados - Deveria exibir 'Error' e sair com status de falha\n"
fi

# Teste com argumentos duplicados
$push_swap -1 +1 -+10
if [ $? -eq 1 ]; then
    green "Teste passou: Argumentos invalidos (-+10)\n"
else
    red "Teste falhou: Argumentos invalidos (-+10) - Deveria exibir 'Error' e sair com status de falha\n"
fi

# Teste com argumentos válidos
$push_swap 1 5 55
if [ $? -eq 0 ]; then
    green "Teste passou: lista ordenada, não deveria exibir nada acima\n"
else
    red "Teste falhou: Argumentos válidos - Não deveria exibir 'Error'\n"
fi

# Teste com argumentos válidos
$push_swap 3 1 4 6 5
if [ $? -eq 0 ]; then
    green "Teste passou: printa os movimentos\n"
else
    red "Teste falhou: Argumentos válidos - Não deveria exibir 'Error'\n"
fi

