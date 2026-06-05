#include <iostream>
#include <vector>

// Classes do projeto
#include "pod.h"
#include "worker.h"
#include "scheduler.h"

using namespace std;

int main() {

    // =====================================================
    // CRIAÇÃO DOS WORKERS (nós do cluster)
    // =====================================================

    vector<Worker> workers;

    workers.push_back(
        Worker(
            "Worker01",
            16,
            32,
            500,
            5
        )
    );

    workers.push_back(
        Worker(
            "Worker02",
            8,
            16,
            250,
            15
        )
    );

    workers.push_back(
        Worker(
            "Worker03",
            12,
            24,
            300,
            8
        )
    );

    // =====================================================
    // CRIAÇÃO DOS PODS
    // =====================================================

    vector<Pod> pods;

    for (int i = 1; i <= 20; i++) {

        string nome =
            "POD" + to_string(i);

        int cpu = (i % 4) + 1;
        int memoria = (i % 8) + 2;
        int disco = (i % 40) + 10;

        pods.push_back(
            Pod(
                nome,
                cpu,
                memoria,
                disco
            )
        );
    }

    cout
        << "Iniciando escalonamento..."
        << endl
        << endl;

    // =====================================================
    // ESCALONAMENTO DOS PODS
    // =====================================================

    for (Pod pod : pods) {

        Scheduler::alocarPod(
            pod,
            workers
        );
    }

    // =====================================================
    // RELATÓRIO DETALHADO DOS WORKERS
    // =====================================================

    cout
        << "\n===== RELATORIO FINAL =====\n";

    for (Worker& w : workers) {

        cout
            << "\n=====================\n";

        cout
            << w.nome
            << endl;

        cout
            << "=====================\n";

        cout
            << "Pods alocados: "
            << w.pods.size()
            << endl;

        cout
            << "\nLista de Pods:\n";

        for (Pod& p : w.pods) {

            cout
                << " - "
                << p.nome
                << endl;
        }

        cout
            << "\nCPU livre: "
            << w.cpuLivre
            << "/"
            << w.cpuTotal
            << endl;

        cout
            << "RAM livre: "
            << w.memoriaLivre
            << "/"
            << w.memoriaTotal
            << endl;

        cout
            << "Disco livre: "
            << w.discoLivre
            << "/"
            << w.discoTotal
            << endl;
    }

    // =====================================================
    // ESTATÍSTICAS DO CLUSTER
    // =====================================================

    int totalPods = pods.size();

    int podsAlocados = 0;

    int cpuTotal = 0;
    int cpuLivre = 0;

    int memoriaTotal = 0;
    int memoriaLivre = 0;

    int discoTotal = 0;
    int discoLivre = 0;

    for (Worker& w : workers) {

        podsAlocados += w.pods.size();

        cpuTotal += w.cpuTotal;
        cpuLivre += w.cpuLivre;

        memoriaTotal += w.memoriaTotal;
        memoriaLivre += w.memoriaLivre;

        discoTotal += w.discoTotal;
        discoLivre += w.discoLivre;
    }

    int podsRejeitados =
        totalPods - podsAlocados;

    int cpuUsada =
        cpuTotal - cpuLivre;

    int memoriaUsada =
        memoriaTotal - memoriaLivre;

    int discoUsado =
        discoTotal - discoLivre;

    cout
        << "\n===== ESTATISTICAS DO CLUSTER =====\n";

    cout
        << "Pods criados: "
        << totalPods
        << endl;

    cout
        << "Pods alocados: "
        << podsAlocados
        << endl;

    cout
        << "Pods rejeitados: "
        << podsRejeitados
        << endl;

    cout
        << endl;

    cout
        << "CPU utilizada: "
        << cpuUsada
        << "/"
        << cpuTotal
        << " ("
        << (cpuUsada * 100 / cpuTotal)
        << "%)"
        << endl;

    cout
        << "RAM utilizada: "
        << memoriaUsada
        << "/"
        << memoriaTotal
        << " ("
        << (memoriaUsada * 100 / memoriaTotal)
        << "%)"
        << endl;

    cout
        << "Disco utilizado: "
        << discoUsado
        << "/"
        << discoTotal
        << " ("
        << (discoUsado * 100 / discoTotal)
        << "%)"
        << endl;

    return 0;
}
