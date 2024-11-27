//
// Created by JS on 24.11.2024.
//

#include <tuple>
#include <vector>
#include <random>
#include "../include/experiments.h"


Simulation single_simulation(int binNumber) {

    std::vector<int> bins(binNumber,0);
    int num_empty_bins = binNumber;
    int one_ball_bins = 0;
    int two_ball_bins = 0;

    int counter = 0;
    int first_collision = 0;
    int all_non_empty = 0;
    int all_two = 0;
    int empty_after_n = 0;


    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> dist(0,binNumber-1);

    while (all_two==0) {
        counter++;
        int bin_num = dist(gen);
        bins[bin_num]++;

        if (bins[bin_num] == 1) {
            num_empty_bins--;
            one_ball_bins++;
        }
        else if (bins[bin_num] == 2) {
            two_ball_bins++;
            one_ball_bins--;
            if (first_collision == 0) {
                first_collision=counter;
            }
        }
        if (all_non_empty == 0 ) {
            if (num_empty_bins == 0) {
                all_non_empty = counter;
            }
        }
        if ((all_two == 0)&&(two_ball_bins == binNumber)) {
            all_two = counter;
        }
        if (counter==binNumber) {
            empty_after_n=num_empty_bins;
        }
    }
    Simulation sim(first_collision, all_non_empty,all_two,empty_after_n,binNumber);
    return sim;
}

std::tuple<std::vector<Simulation>,std::vector<AvgSimulation>> batch_simulation(int n_max,int n_min,int n_int,int k) {
    std::vector<Simulation> sims;
    std::vector<AvgSimulation> avgSims;

    for(int n=n_min; n<=n_max; n=n+n_int) {

        double avg_first_collision = 0;
        double avg_all_non_empty = 0;
        double avg_all_two = 0;
        double avg_empty_after_n = 0;

        for(int i=0;i<k;i++) {
            Simulation sim = single_simulation(n);
            avg_first_collision += sim.first_collision;
            avg_all_non_empty += sim.all_non_empty;
            avg_all_two += sim.all_two;
            avg_empty_after_n += sim.empty_after_n;
            sims.push_back(sim);
        }

        avg_first_collision = avg_first_collision/k;
        avg_all_non_empty = avg_all_non_empty/k;
        avg_all_two = avg_all_two/k;
        avg_empty_after_n = avg_empty_after_n/k;
        AvgSimulation avgSim(avg_first_collision,avg_all_non_empty,avg_all_two,avg_empty_after_n,n);
        avgSims.push_back(avgSim);
    }
    return {sims,avgSims};
}

std::vector<Simulation> k_simulations(int k,int binNumber) {
    std::vector<Simulation> sims;
    for(int i=0;i<k;i++){
        sims.push_back(single_simulation(binNumber));
    }
    return sims;
}


