#include <iostream>
#include <sstream>
#include <vector>
#include <string>

#include "BankSimulation.h"

struct Escenario {
    int nWin;
    int servTime;
    unsigned int seed;
    std::string observacion;
};

int main() {
    std::vector<Escenario> escenarios = {
        {1, 30, 12345U, "Pocas ventanas (1). Colapso inminente por acumulación."},
        {3, 30, 12345U, "Mismo tiempo/semilla, pero más ventanas. Fluidez notable."},
        {3, 100, 12345U, "Mayor duración. Permite ver el comportamiento a largo plazo."},
        {3, 30, 99999U, "Mismas ventanas/tiempo que el Caso 2, pero diferente semilla."},
        {3, 30, 12345U, "Réplica exacta del Caso 2 para demostrar determinismo."},
        {5, 30, 55555U, "Muchas ventanas. Alta probabilidad de colas vacías."}
    };
    std::cout << "| `nWin` | `servTime` | `seed` | `totalArrivals` | `totalServed` | `tamaño final` | `Observación` |\n";
    std::cout << "| :---: | :---: | :---: | :--- | :--- | :---: | :--- |\n";
    for (const auto& esc : escenarios) {
        const auto result = ods::simulate(esc.nWin, esc.servTime, esc.seed);

        std::stringstream ss;
        if (!result.timeline.empty()) {
            const auto& finalqueues = result.timeline.back().queues;
            ss << "[";
            for (size_t i = 0; i < finalqueues.size(); ++i) {
                if (i > 0) ss << ", ";
                ss << finalqueues[i].size();
            }
            ss << "]";
        } else {
            ss << "[]";
        }
        const auto& lastStep = result.timeline.back();
        std::cout << "| " << esc.nWin << " | " << esc.servTime << " | " << esc.seed << " | " << result.totalArrivals << " | " << result.totalServed << " | " << ss.str() << "`" << " | " << esc.observacion << " |\n";
    }
    return 0;
}