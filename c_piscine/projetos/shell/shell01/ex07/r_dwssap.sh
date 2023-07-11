#sed -stream editor para filtrar e transformar textos
	#flag 'p' é para imprimir as linhas filtradas
	#-n é para não haver duplicação da saida 
	#flag s significa saida padrao "stdout"
	#flag 'g' todas ocorrencias

cat /etc/passwd |
	grep -v "^#" |				#se o texto começa com '#', remove!
	awk "NR%2==0" | 			#mostra somente as linhas pares
	cut -d':' -f1 | 			#separa a string em colunas e pega somente a primeira (-f1)
	rev | 						#inverte a ordem dos caracteres
	sort -r | 					#classifica os dados, -r reverse
	sed -n "$FT_LINE1,${FT_LINE2}p" | #filtra os dados a partir das variaveis
	paste -s -d"," | 			    #remove a quebra de linha, coloca virgula, -s um por vez
	sed 's/,/, /g' | 			#troca a virgula por virgula e espaço
	sed 's/$/./'  				#coloca ponto final no fim da linha