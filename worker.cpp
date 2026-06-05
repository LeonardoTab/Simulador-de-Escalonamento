#include "worker.h"

Worker::Worker(
    std::string nome,
    int cpu,
    int memoria,
    int disco,
    int latencia
) {

    this->nome = nome;

    cpuTotal = cpu;
    memoriaTotal = memoria;
    discoTotal = disco;

    cpuLivre = cpu;
    memoriaLivre = memoria;
    discoLivre = disco;

    this->latencia = latencia;
}

bool Worker::podeReceber(Pod pod) {

    return (
        cpuLivre >= pod.cpu &&
        memoriaLivre >= pod.memoria &&
        discoLivre >= pod.disco
    );
}

void Worker::adicionarPod(Pod pod) {

    pods.push_back(pod);

    cpuLivre -= pod.cpu;
    memoriaLivre -= pod.memoria;
    discoLivre -= pod.disco;
}

int Worker::calcularScore() {

    int cpuPercent =
        (cpuLivre * 100) / cpuTotal;

    int memoriaPercent =
        (memoriaLivre * 100) / memoriaTotal;

    int discoPercent =
        (discoLivre * 100) / discoTotal;

    return
        cpuPercent +
        memoriaPercent +
        discoPercent -
        latencia;
}
