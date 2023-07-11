#exercicio de criptografia
#export FT_NBR1=\\\'\?\"\\\"\'\\
#export FT_NBR2=rcrdmddd
#export FT_NBR1=\\\"\\\"\!\\\"\\\"\!\\\"\\\"\!\\\"\\\"\!\\\"\\\"\!\\\"\\\"
#export FT_NBR2=dcrcmcmooododmrrrmorcmcrmomo

echo $FT_NBR1 + $FT_NBR2 | 
	tr \'\\\\\"\?\! "01234" | 			#base '\"?!
	tr "mrdoc" "01234" | 				#base mrdoc
	xargs echo "ibase=5; obase=23;" | 	#definem a base de conversão para números de entrada e saída. O padrão é a base 10
	bc | 								#para fazer os calculos, bc significa basic calculator.
	tr "0123456789ABC" "gtaio luSnemf"	#retornando o resultado criptografado