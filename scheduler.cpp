#include <iostream>

#include "scheduler.h"

using namespace std;

void Scheduler::alocarPod(
    Pod pod,
    vector<Worker>& workers
) {

    int melhor = -1;
    int melhorScore = -999999;

    for (int i = 0;
         i < workers.size();
         i++) {

        if (workers[i].podeReceber(pod)) {

            int score =
                workers[i].calcularScore();

            if (score > melhorScore) {

                melhorScore = score;
                melhor = i;
            }
        }
    }

    if (melhor != -1) {

        workers[melhor].adicionarPod(pod);

        cout
            << pod.nome
            << " -> "
            << workers[melhor].nome
            << endl;
    }
    else {

        cout
            << pod.nome
            << " nao pode ser alocado."
            << endl;
    }
}
