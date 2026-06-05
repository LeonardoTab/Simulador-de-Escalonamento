#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <vector>

#include "worker.h"
#include "pod.h"

class Scheduler {

public:

    static void alocarPod(
        Pod pod,
        std::vector<Worker>& workers
    );
};

#endif
