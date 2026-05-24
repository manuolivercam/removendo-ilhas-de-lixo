# Removendo ilhas de lixo 🌊🗑️

Este repositório contém a solução do **Primeiro Exercício-Programa (EP1)** da disciplina **ACH2002 - Introdução à Análise de Algoritmos** (2025), ministrada pelo Prof. Marcos Lordello Chaim na **Escola de Artes, Ciências e Humanidades (EACH-USP)**.

O projeto consiste em um sistema inteligente em linguagem C projetado para otimizar a coleta e o transporte de resíduos acumulados nos oceanos com base em dados escaneados por drones.

---

## 📋 O Problema

A partir de uma matriz que representa uma região escaneada do oceano (onde cada célula indica a altura do lixo acumulado por metro quadrado), o programa deve realizar três tarefas principais:

1. **Identificar e contar** as ilhas de lixo distintas (células adjacentes conectadas horizontal ou verticalmente).
2. **Calcular a profundidade de transporte** necessária para cada ilha em contêineres padronizados de $2\times3$ metros de base, aplicando regras específicas de compactação e arredondamento.
3. **Encontrar uma combinação exata** de ilhas cujas profundidades somadas preencham perfeitamente a capacidade total de um contêiner disponível.

---

## 🛠️ Tecnologias e conceitos utilizados

* **Linguagem C**: Implementação limpa com manipulação dinâmica de memória (`malloc`/`free`) e leitura de arquivos (`fscanf`).
* **Busca em Matrizes / Grafos (Flood Fill)**: Algoritmo recursivo para explorar e delimitar os componentes conexos (as ilhas) na matriz do oceano.
* **Programação Dinâmica**: Abordagem baseada na variação do *Problema da Mochila (Knapsack) / Soma dos Subconjuntos (Subset Sum)* para determinar e rastrear a combinação exata que preenche o contêiner.

---

## 🚀 Como compilar e executar

Certifique-se de ter um compilador GCC instalado no seu ambiente.

### 1. Compilação
No terminal, execute o comando para compilar o código:
```bash
gcc ep1_iaa.c -o EP1
