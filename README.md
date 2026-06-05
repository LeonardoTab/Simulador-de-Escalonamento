# Simulador de Escalonamento de Containers

## Descrição

Este projeto implementa um simulador simplificado de escalonamento de containers inspirado no Kubernetes.

O sistema é composto por:

- Pods
- Workers
- Scheduler

O Scheduler é responsável por decidir em qual Worker cada Pod será executado, considerando os recursos disponíveis em cada nó do cluster.

---

## Objetivo

Simular o processo de escalonamento de containers em um cluster, considerando limitações de CPU, memória e disco.

---

## Recursos Considerados

- CPU
- Memória RAM
- Disco

Cada Pod possui requisitos específicos e cada Worker possui capacidade limitada.

---

## Estrutura do Projeto

### main.cpp

Responsável por:

- Criar os Workers
- Criar os Pods
- Executar o escalonamento
- Exibir relatórios

### pod.h / pod.cpp

Implementação da classe Pod.

### worker.h / worker.cpp

Implementação da classe Worker.

### scheduler.h / scheduler.cpp

Implementação do algoritmo de escalonamento.

---

## Compilação

g++ *.cpp -o scheduler

---

## Execução

./scheduler

---

## Funcionalidades

- Criação de múltiplos Workers
- Criação automática de Pods
- Escalonamento baseado em recursos
- Controle de capacidade dos Workers
- Rejeição de Pods sem recursos disponíveis
- Relatórios detalhados
- Estatísticas do cluster

---

## Resultados Obtidos

Cluster utilizado:

- 3 Workers
- 20 Pods

Resultado:

- 13 Pods alocados
- 7 Pods rejeitados

Utilização:

- CPU: 88%
- RAM: 95%
- Disco: 21%

---

## Tecnologias

- C++
- Linux (Ubuntu WSL)
- Git
- GitHub

---

## Autor

Leonardo Taborda

Disciplina de Sistemas Operacionais
