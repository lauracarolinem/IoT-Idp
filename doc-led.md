PROJETO BLINK
Na instalação do Windows, após fazer o passo-a-passo, aparecerá dois prompts de comando (um cmd e outro powershell) que já possui o PATH que precisamos para rodar os programas. 
PASSO1: Abra o terminal com o PATH e navegue até a pasta que deseja alocar o projeto, ou também abra a pasta em que tem os exemplos do próprio idf. Nesse caso, irei usar o código pronto, então entrei no seguinte PATH.
	PS C:\Espressif\frameworks\esp-idf-v5.0.1\examples\get-started>
Caso queira criar um projeto do 0, entre na pasta correspondente e digite o seguinte comando: 
	idf.py create-project [NOME PROJETO]
PASSO2: Agora entre dentro da pasta que foi criada e veja que foi criado um Makefile e um arquivo main.c
PASSO3: Entre na pasta que está o Make e o main e rode o seguinte comando: 
	 idf.py set-target esp32
	PASSO3.1: Agora, rode o seguinte comando para fazer um build: 
		idf.py build
PASSO4: A partir de agora começamos com o código. Caso utilize os exemplos do esp-idf, apenas abra o código em alguma IDE e faça algumas alterações que vão ser mostradas a seguir. Mas, se quiser escrever o próprio código, altere o arquivo main.c
	PASSO4: Caso utilize o código pronto, altere os seguintes comandos: 
Aqui, você muda a variável CONFIG_BLINK_GPIO pela gpio que é usada no esp para a entrada da led. 
PASSO5: Confira a porta de entrada USB no Device Manager do seu notebook. Após isso, precisamos fazer o flash do dispositivo, então executamos o seguinte programa: 
	idf.py -p [PORTA] flash

PASSO6: Agora usamos o seguinte comando, para rodar o programa: 
	idf.py monitor


Observações: se mudar o código, tem que repetir os comandos de build, flash e monitor. Nessa sequência. 
