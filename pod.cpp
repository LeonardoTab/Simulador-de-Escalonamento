#include "pod.h"

Pod::Pod(
    std::string nome,
    int cpu,
    int memoria,
    int disco
) {

    this->nome = nome;
    this->cpu = cpu;
    this->memoria = memoria;
    this->disco = disco;
}
