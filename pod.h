#ifndef POD_H
#define POD_H

#include <string>

class Pod {

public:

    std::string nome;

    int cpu;
    int memoria;
    int disco;

    Pod(
        std::string nome,
        int cpu,
        int memoria,
        int disco
    );
};

#endif
