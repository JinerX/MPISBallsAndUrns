//
// Created by JS on 27.11.2024.
//

#ifndef MPISBALLSANDBINS_FUNCWRAPPER_H
#define MPISBALLSANDBINS_FUNCWRAPPER_H

#include <vector>
#include <string>

void createPlotn(std::vector<int> main_vector,std::vector<int> X,std::vector<double> avg_main_vec, std::vector<double> avg_X, std::string title, std::string ylabel);
void createPlotn2(std::vector<int> main_vector, std::vector<int> X, std::vector<double> avg_main_vec, std::vector<double> avg_X, std::string title, std::string ylabel);
void createPlotnlnn(std::vector<int> main_vector, std::vector<int> X, std::vector<double> avg_main_vec, std::vector<double> avg_X, std::string title, std::string ylabel);
void createPlotnsqrtn(std::vector<int> main_vector, std::vector<int> X, std::vector<double> avg_main_vec, std::vector<double> avg_X, std::string title, std::string ylabel);
void createPlotnln2(std::vector<int> main_vector, std::vector<int> X, std::vector<double> avg_main_vec, std::vector<double> avg_X, std::string title, std::string ylabel);

#endif //MPISBALLSANDBINS_FUNCWRAPPER_H
