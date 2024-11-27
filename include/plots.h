//
// Created by JS on 26.11.2024.
//

#ifndef MPISBALLSANDBINS_PLOTS_H
#define MPISBALLSANDBINS_PLOTS_H

#include <vector>
#include "experiments.h"

void make_plot(const std::vector<int>& X, const std::vector<int>& Y, const std::vector<double>& avgX, const std::vector<double>& avgY, const std::string& title,const std::string& ylabel);
void make_plot(const std::vector<int>& X, const std::vector<double>& Y, const std::vector<double>& avgX, const std::vector<double>& avgY, const std::string& title,const std::string& ylabel);

#endif //MPISBALLSANDBINS_PLOTS_H
