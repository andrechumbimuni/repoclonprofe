#include <chrono>
#include <iostream>
#include <iomanip>
#include "LinearHashTable.h"
#include "RehashPolicy.h"
namespace ods {
// MOD-A8-A:Reporte uniforme de métricas
    void printHashStats(const HashStats& stats) {
        std::cout << "\nREPORTE DE METRICAS HASH\n\n"<< "Colisiones detectadas:       " << stats.collisions << "\n"<< "Sondeos totales (Probes):    " << stats.totalProbes << "\n"<< "Maximo de sondeos:           " << stats.maxProbeLength << "\n"<< "Sondeo promedio:             " << std::fixed << std::setprecision(3)<< (stats.totalProbes / 5000.0) << "\n" << "Cantidad de rehashes:        " << stats.rehashes << "\n"<< "Lapidas (Tombstones):        " << stats.tombstones << "\n"<< "\n";
    }
} // namespace ods
int main() {
    for (double maxLoad : {0.45, 0.65, 0.85}) {
        ods::RehashPolicy p;
        p.maxLoad = maxLoad;
        p.maxOccupiedLoad = std::min(0.95, maxLoad + 0.10);
        ods::LinearHashTable<int> t(8, p);

        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < 5000; ++i) t.add(i * 37);
        for (int i = 0; i < 5000; ++i) t.contains(i * 37);
        auto stop = std::chrono::high_resolution_clock::now();

        auto us = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
        std::cout << "maxLoad=" << maxLoad
                  << " capacity=" << t.capacity()
                  << " load=" << t.loadFactor()
                  << " maxProbe=" << t.stats().maxProbeLength
                  << " avgProbe=" << t.stats().averageProbeLength()
                  << " time_us=" << us << "\n";
        // MOD-A8-A:Reporte uniforme de métricas
        ods::printHashStats(t.stats());
    }
}
