# Fila de Banco
Nome: Nícolas Kalebe

Nome: Vitor Alexandre - 202302592
## **Seção I. Introdução**

### Problema

O problema escolhido pelo nosso grupo foi desenvolver um programa em C para organizar a fila de um banco. Isso seria útil para pessoas que não têm tempo de esperar pessoalmente em filas longas enquanto têm outras atividades para realizar. Nosso objetivo não é criar um aplicativo completo com servidor próprio e todo elaborado, mas sim uma abstração do conceito. No nosso projeto o usuário seria cadastrado em uma fila já com o motivo de sua ida ao banco para assim já o encaminhar para o setor certo quando chegasse a sua vez. Na ideia completa o próprio usuário se cadastraria em um app, já a abstração que será vista no programa, será o app sendo utilizado por um administrador dessa fila, com todas as opções de adição, remoção e visão completa da fila.

### Literatura

- **Tempo na fila do banco acima do limite fixado em lei, por si só, não gera dano moral (**https://www.conjur.com.br/2024-abr-26/dano-moral-por-tempo-na-fila-do-banco-exige-demora-excessiva-fixa-stj/**)**
- **Público em fila de banco denuncia sofrimento e descaso em Marília (**https://www.giromarilia.com.br/cidades/marilia/publico-em-fila-de-banco-denuncia-sofrimento-e-descaso-em-marilia/**)**
- **Bancos têm multas ratificadas por demora em atender cliente na fila (**https://www.dmanapolis.com.br/noticia/62199/bancos-tem-multas-ratificadas-por-demora-em-atender-cliente-na-fila**)**

### Dataset

Os dados que usaremos no programa serão: nome do cliente, CPF, motivo e tentaremos aplicar também a opção de fila prioritária para idosos por exemplo.

### Métodos

Os clientes serão cadastrados informando seus dados um de cada vez, onde uma estrutura armazenará eles em fila por ordem de cadastro. De modo que seja fácil visualizar a fila, remover alguém da fila e adicionar novas pessoas na fila. 

### Avaliação

Verificaremos se a ordem da fila está sendo respeitada e todas as funções estão funcionando de maneira correta e da melhor forma. 

## **Seção II. Fundamentos Teóricos**

Os fundamentos teóricos servem para descrevermos as etápas do projeto através das ferramentas e métodos que utlizamos para o desenvolvimento do código, chegando a uma conclusão do problema proposto de melhorar e agilizar o sistema de atendimento nas filas de bancos ao redor do mundo.

Dentro do nosso programa utilizamos o sistema de:

### Estrutura de Dados

- **Fila do tipo FIFO (First In, First Out)**

Nesse tipo de fila apresentado em sala de aula, o primeiro elemento a ser inserido é o primeiro a ser removido, seguindo uma ordem dinâmica removendo o elemento mais antigo. As operações acontecem nas extremidades da fila. No código, foram criados dois tipos de fila:

 Fila normal (para clientes sem preferência ou com menos de 60 anos de idade)
 Fila preferencial (para clientes com preferência ou com idade igual ou superior a 60 anos)

- **Vantagens e Limitações:**
  Uma das vantagens no uso das filas está no processamento sequencial, uma vez que há garantia de ordem FIFO (First In, First Out).
  Essa estrutura é de fácil implementação e entendimento
  Porém, há limitações no acesso aos elementos, sendo possível apenas aos extremos (início e fim).

## Funções Utilizadas

No código foram utilizadas as seguintes funções:

- `iniciarFila`: utilizado para iniciar uma fila vazia (sem clientes);
- `adicionarCliente`: adiciona clientes na fila com base nos dados (idade e preferência);
- `atenderProximo`: remove o cliente mais antigo e atende o próximo cliente na fila;
- `exibirFila`: mostra os clientes que estão presentes na fila.

## **Seção III. Metodologia**

A metodologia consiste em uma tela inicial que terá algumas opções enumeradas que poderão ser escolhidas pelo usuário. Sendo elas: Cadastrar um novo cliente, remover um cliente da fila, ou verificar a fila. Cada uma com uma função diferente e sendo sempre possível voltar para a tela inicial no final da função. Na opção de verificar a fila terá a opção de “próximo na fila” que apagará o cliente da primeira posição e dará continuação à fila.

![diagrama](https://github.com/user-attachments/assets/9459645c-9e8b-4368-9f83-12daf09a9b9e)

## **Seção IV. Resultados e Conclusões**

Com a conclusão do projeto, é possível afirmar que aprendemos bastante sobre o desenvolvimento de um programa em C, com a utilização de novas funções e algoritmos que nos ajudaram a concluir o problema proposto, mas também sobre a estrutura de dados e como manipulá-los dentro de um programa. No nosso projeto, criamos um programa que facilita a utilização de um sistema de filas para um banco, agilizando o processo e fazendo com que o diário e cansativo processo por esperar em filas aconteça de modo mais dinâmico.

### Resultados 

- Agrupamento dos clientes do banco em duas filas diferentes, um fila normal e outra peferencial.
- Rapidez e facilidade de navegação pelo programa.
- Fácil leitura e entendimento das funções do código.
- Simplicidade que gera agilidade com o passar dos clientes pelas filas.
- Prioridade de atentimento a aqueles clientes que possuem preferência ou possuem idade mais elevada.
