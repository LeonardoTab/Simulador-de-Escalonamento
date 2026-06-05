# Simulador de Escalonamento de Containers

## Descrição

Este projeto implementa um simulador simplificado de escalonamento de containers inspirado no Kubernetes.

O sistema possui:

- Pods
- Workers
- Scheduler

O Scheduler é responsável por decidir em qual Worker cada Pod será executado, considerando recursos disponíveis.

---

## Recursos considerados

- CPU
- Memória RAM
- Disco
- Latência

---

## Estrutura do Projeto

- pod.h / pod.cpp
  - Representação dos Pods

- worker.h / worker.cpp
  - Representação dos Workers

- scheduler.h / scheduler.cpp
  - Implementação do algoritmo de escalonamento

- main.cpp
  - Simulação do cluster

---

## Compilação

```bash
g++ *.cpp -o scheduler


./scheduler
rm README.md


cat > README.md << 'EOF'
# Simulador de Escalonamento de Containers

## Descrição

Este projeto implementa um simulador simplificado de escalonamento de containers inspirado no Kubernetes.

O sistema é composto por:

- Pods
- Workers
- Scheduler

O Scheduler é responsável por decidir em qual Worker cada Pod será executado, considerando os recursos disponíveis em cada nó do cluster.

---

## Recursos Considerados

O algoritmo de escalonamento utiliza:

- CPU
- Memória RAM
- Disco
- Latência

A decisão de alocação é realizada através de uma pontuação (score), calculada com base na disponibilidade dos recursos de cada Worker.

---

## Estrutura do Projeto

### pod.h / pod.cpp

Representam os Pods (containers) que serão executados no cluster.

Cada Pod possui:

- Nome
- CPU necessária
- Memória necessária
- Espaço em disco necessário

### worker.h / worker.cpp

Representam os Workers do cluster.

Cada Worker possui:

- CPU total
- Memória total
- Disco total
- Latência
- Lista de Pods alocados

### scheduler.h / scheduler.cpp

Implementam o algoritmo de escalonamento responsável por selecionar o melhor Worker para cada Pod.

### main.cpp

Responsável pela criação do cluster, geração dos Pods, execução do escalonamento e exibição dos relatórios.

---

## Compilação

Execute:

g++ *.cpp -o scheduler

---

## Execução

Execute:

./scheduler

---

## Funcionalidades Implementadas

- Criação de múltiplos Workers
- Criação automática de Pods
- Escalonamento baseado em múltiplos recursos
- Controle de capacidade dos Workers
- Rejeição de Pods quando não há recursos suficientes
- Relatório detalhado de alocação
- Estatísticas globais do cluster

---

## Exemplo de Saída

O programa exibe:

- Alocação de cada Pod
- Lista de Pods por Worker
- Recursos livres de cada Worker
- Estatísticas globais do cluster

Exemplo:

POD1 -> Worker01
POD2 -> Worker03
POD3 -> Worker02

---

## Resultados Obtidos

Execução realizada com:

- 3 Workers
- 20 Pods

Resultado:

- 13 Pods alocados
- 7 Pods rejeitados

Utilização do cluster:

- CPU: 88%
- RAM: 95%
- Disco: 21%

---

## Autor

Leonardo Taborda

Disciplina de Sistemas Operacionais
