#ifndef WORKER_H
#define WORKER_H

#include <string>
#include <vector>

#include "pod.h"

class Worker {

public:

    std::string nome;

    int cpuTotal;
    int memoriaTotal;
    int discoTotal;

    int cpuLivre;
    int memoriaLivre;
    int discoLivre;

    int latencia;

    std::vector<Pod> pods;

    Worker(
        std::string nome,
        int cpu,
        int memoria,
        int disco,
        int latencia
    );

    bool podeReceber(Pod pod);

    void adicionarPod(Pod pod);

    int calcularScore();
};

#endif
