//
// Created by JS on 24.11.2024.
//
#include <tuple>
#include <string>
#include <vector>

#ifndef MPISBALLSANDBINS_EXPERIMENTS_H
#define MPISBALLSANDBINS_EXPERIMENTS_H

//char* getHello();
//std::tuple<int, std::string>  getVals();

template <typename T>
struct GenericSimulation {
    T first_collision;
    T all_non_empty;
    T all_two;
    T empty_after_n;
    int numBins;

    GenericSimulation(T first_collision, T all_non_empty,T all_two,T empty_after_n,int numBins) {
        this->first_collision=first_collision;
        this->all_non_empty=all_non_empty;
        this->numBins=numBins;
        this->all_two=all_two;
        this->empty_after_n=empty_after_n;
    }
};

using Simulation = GenericSimulation<int>;
using AvgSimulation = GenericSimulation<double>;

Simulation single_simulation(int binNumber);
std::vector<Simulation> k_simulations(int k,int binNumber);
std::tuple<std::vector<Simulation>,std::vector<AvgSimulation>> batch_simulation(int n_max,int n_min,int n_int,int k);


#endif //MPISBALLSANDBINS_EXPERIMENTS_H
