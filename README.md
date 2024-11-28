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

### Algoritmos

## **Seção III. Metodologia**

A metodologia consiste em uma tela inicial que terá algumas opções enumeradas que poderão ser escolhidas pelo usuário. Sendo elas: Cadastrar um novo cliente, remover um cliente da fila, ou verificar a fila. Cada uma com uma função diferente e sendo sempre possível voltar para a tela inicial no final da função. Na opção de verificar a fila terá a opção de “próximo na fila” que apagará o cliente da primeira posição e dará continuação à fila.

![diagrama](https://github.com/user-attachments/assets/9459645c-9e8b-4368-9f83-12daf09a9b9e)
