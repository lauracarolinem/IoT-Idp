# PROJETO ULTRASONIC COM LED

Neste Projeto iremos utilizar um sensor ultrassônico para captar as distancias dos objetos que estão dispostos em seu raio. E para aqueles que chegarem 10 cm perto do sensor, a led irá acender. 

Na instalação do Windows, após fazer o passo-a-passo, aparecerá dois prompts de comando (um cmd e outro powershell) que já possui o PATH que precisamos para rodar os programas. Abra um deles.

**Passo 1:** Abra o terminal com o PATH e navegue até a pasta que deseja alocar o projeto. Após isso, digite o comando abaixo para criar um novo projeto.

obs: Não precisa colocar os colchetes "[ ]" 
```bash
idf.py create-project [NOME_PROJETO]
```

**Passo 2:** Agora entre dentro da pasta que foi criada e veja que foi criado um Makefile e um arquivo main.c
  
**Passo 3:** Entre no diretório que possui o Makefile e uma pasta main. Digite o comando abaixo: 

```bash
 idf.py set-target esp32
```

**Passo 4:** Utilize o código de exemplo "main-ultra" para se basear na sua aplicação, ou crie um codigo C do zero no seu arquivo main.
  **OBS:** Veja que existe uma pasta de componentes. Esta pasta é essencial pois adiciona headers que possuem funções que nos ajudam a criar o código com o ultrassônico. Ou seja, quando utilizar as funções do ultrassonico, a pasta "components" precisa estar dentro do seu projeto.

**Passo 5:** Monte sua protoboard usando os circuitos de exemplo disponíveis.

**Passo 6:** Rode o seguinte comando para fazer um build do seu código na sua máquina: 
 
```bash
 idf.py build
```

**Passo 7:** Confira a porta de entrada USB no Device Manager do seu notebook. Após isso, fazemos o flash no dispositivo, então executamos o seguinte programa: 

obs: Não precisa colocar os colchetes "[ ]" 
```bash
 idf.py -p [PORTA] flash
```

**Passo 8:** Pronto, sua aplicação já está rodando no seu dispositivo esp32. Caso tenha colocado algo escrito para provar se sua aplicação está correta (como um printf por exemplo), utilize o código abaixo para ver no terminal: 
```bash
 idf.py monitor
```

**Observação importante**: Sempre que mudar o código, precisa repetir os passos do BUILD E FLASH, respectivamente.
