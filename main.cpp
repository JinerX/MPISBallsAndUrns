#include <iostream>
#include <chrono>
#include <algorithm>
#include <cmath>
#include "experiments.h"
#include "plots.h"
#include "funcWrapper.h"


int main() {
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    auto [sims,avg_sims] = batch_simulation(100000,1000,1000,50);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::seconds >(end - begin).count() << "[s]" << std::endl;

    std::chrono::steady_clock::time_point begin2 = std::chrono::steady_clock::now();

    //Split by values
    std::vector<int> first_collisions;
    std::vector<int> all_non_emptys;
    std::vector<int> all_twos;
    std::vector<int> empty_after_ns;
    std::vector<int> numBinss;

    for(Simulation sim : sims) {
        first_collisions.push_back(sim.first_collision);
        all_non_emptys.push_back(sim.all_non_empty);
        all_twos.push_back(sim.all_two);
        empty_after_ns.push_back(sim.empty_after_n);
        numBinss.push_back(sim.numBins);
    }

    std::vector<double> avgFirst_collisions;
    std::vector<double> avgAll_non_emptys;
    std::vector<double> avgAll_twos;
    std::vector<double> avgEmpty_after_ns;
    std::vector<double> avgNumBinss;
    for(AvgSimulation avgSim : avg_sims){
        avgFirst_collisions.push_back(avgSim.first_collision);
        avgAll_non_emptys.push_back(avgSim.all_non_empty);
        avgAll_twos.push_back(avgSim.all_two);
        avgEmpty_after_ns.push_back(avgSim.empty_after_n);
        avgNumBinss.push_back(avgSim.numBins);
    }

    //B
    make_plot(numBinss,first_collisions,avgNumBinss,avgFirst_collisions,"B_n","B_n");

    //U
    make_plot(numBinss,empty_after_ns,avgNumBinss,avgEmpty_after_ns,"U_n","U_n");

    //C
    make_plot(numBinss,all_non_emptys,avgNumBinss,avgAll_non_emptys,"C_n","C_n");

    //D
    make_plot(numBinss,all_twos,avgNumBinss,avgAll_twos,"D_n","D_n");


    //D-C
    std::vector<int> D_C_Y;
    std::transform(
            all_twos.begin(),
            all_twos.end(),
            all_non_emptys.begin(),
            std::back_inserter(D_C_Y),
            [](auto& d, auto& c){return d - c;}
            );

    std::vector<double> avgD_C_Y;

    std::transform(
            avgAll_twos.begin(),
            avgAll_twos.end(),
            avgAll_non_emptys.begin(),
            std::back_inserter(avgD_C_Y),
            [](auto& ad, auto& ac){return ad - ac;}
            );
    make_plot(numBinss,D_C_Y,avgNumBinss,avgD_C_Y,"D-C","D-C");

    //b(n)
    createPlotn(first_collisions,numBinss,avgFirst_collisions,avgNumBinss,"b(n)_n","b(n)_n");
    createPlotnsqrtn(first_collisions,numBinss,avgFirst_collisions,avgNumBinss,"b(n)_sqrt(n)","b(n)_sqrt(n)");

    //u(n)
    createPlotn(empty_after_ns,numBinss,avgEmpty_after_ns,avgNumBinss,"u(n)_n","u(n)_n");

    //c(n)
    createPlotn(all_non_emptys,numBinss,avgAll_non_emptys,avgNumBinss,"c(n)_n","c(n)_n");
    createPlotnlnn(all_non_emptys,numBinss,avgAll_non_emptys,avgNumBinss,"c(n)_(nln(n))","c(n)_nln(n)");
    createPlotn2(all_non_emptys,numBinss,avgAll_non_emptys,avgNumBinss,"c(n)_n2","c(n)_n2");

    //d(n)
    createPlotn(all_twos,numBinss,avgAll_twos,avgNumBinss,"d(n)_n","d(n)_n");
    createPlotnlnn(all_twos,numBinss,avgAll_twos,avgNumBinss,"d(n)_ln(n)n","d(n)_ln(n)n");
    createPlotn2(all_twos,numBinss,avgAll_twos,avgNumBinss,"d(n)_n2","d(n)_n2");

    //d(n)-c(n)
    createPlotn(D_C_Y,numBinss,avgD_C_Y,avgNumBinss,"(d(n)-c(n))_n","(d(n)-c(n))_n");
    createPlotnlnn(D_C_Y,numBinss,avgD_C_Y,avgNumBinss,"(d(n)-c(n))_ln(n)n","(d(n)-c(n))_ln(n)n");
    createPlotnln2(D_C_Y,numBinss,avgD_C_Y,avgNumBinss,"(d(n)-c(n))_ln(n)ln(n)","(d(n)-c(n))_ln(n)ln(n)");


    return 0;
}
