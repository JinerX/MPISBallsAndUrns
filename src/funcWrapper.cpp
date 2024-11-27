//
// Created by JS on 27.11.2024.
//

#include <vector>
#include <string>
#include <algorithm>
#include "plots.h"
#include <cmath>

void createPlotn(std::vector<int> main_vector, std::vector<int> X, std::vector<double> avg_main_vec, std::vector<double> avg_X, std::string title, std::string ylabel) {
    std::vector<double> generic;
    std::transform(
            main_vector.begin(),
            main_vector.end(),
            X.begin(),
            std::back_inserter(generic),
            [](auto& first,auto& n){return ((double)first)/n;}
    );

    std::vector<double> avgGeneric;
    std::transform(
            avg_main_vec.begin(),
            avg_main_vec.end(),
            avg_X.begin(),
            std::back_inserter(avgGeneric),
            [](auto& first,auto& n){return ((double)first)/n;}
    );

    make_plot(X,generic,avg_X,avgGeneric,title,ylabel);
};


void createPlotn2(std::vector<int> main_vector, std::vector<int> X, std::vector<double> avg_main_vec, std::vector<double> avg_X, std::string title, std::string ylabel) {
    std::vector<double> generic;
    std::transform(
            main_vector.begin(),
            main_vector.end(),
            X.begin(),
            std::back_inserter(generic),
            [](auto& first,auto& n){return ((double)first)/((double)n*n);}
    );

    std::vector<double> avgGeneric;
    std::transform(
            avg_main_vec.begin(),
            avg_main_vec.end(),
            avg_X.begin(),
            std::back_inserter(avgGeneric),
            [](auto& first,auto& n){return ((double)first)/((double)n*n);}
    );

    make_plot(X,generic,avg_X,avgGeneric,title,ylabel);
};


void createPlotnlnn(std::vector<int> main_vector, std::vector<int> X, std::vector<double> avg_main_vec, std::vector<double> avg_X, std::string title, std::string ylabel) {
    std::vector<double> generic;
    std::transform(
            main_vector.begin(),
            main_vector.end(),
            X.begin(),
            std::back_inserter(generic),
            [](auto& first,auto& n){return ((double)first)/((double)n*std::log(n));}
    );

    std::vector<double> avgGeneric;
    std::transform(
            avg_main_vec.begin(),
            avg_main_vec.end(),
            avg_X.begin(),
            std::back_inserter(avgGeneric),
            [](auto& first,auto& n){return ((double)first)/((double)n*std::log(n));}
    );

    make_plot(X,generic,avg_X,avgGeneric,title,ylabel);
};

void createPlotnsqrtn(std::vector<int> main_vector, std::vector<int> X, std::vector<double> avg_main_vec, std::vector<double> avg_X, std::string title, std::string ylabel) {
    std::vector<double> generic;
    std::transform(
            main_vector.begin(),
            main_vector.end(),
            X.begin(),
            std::back_inserter(generic),
            [](auto& first,auto& n){return ((double)first)/(std::sqrt((double)n));}
    );

    std::vector<double> avgGeneric;
    std::transform(
            avg_main_vec.begin(),
            avg_main_vec.end(),
            avg_X.begin(),
            std::back_inserter(avgGeneric),
            [](auto& first,auto& n){return ((double)first)/(std::sqrt((double)n));}
    );

    make_plot(X,generic,avg_X,avgGeneric,title,ylabel);
};


void createPlotnln2(std::vector<int> main_vector, std::vector<int> X, std::vector<double> avg_main_vec, std::vector<double> avg_X, std::string title, std::string ylabel) {
    std::vector<double> generic;
    std::transform(
            main_vector.begin(),
            main_vector.end(),
            X.begin(),
            std::back_inserter(generic),
            [](auto& first,auto& n){return ((double)first)/((double)n*std::log(std::log(n)));}
    );

    std::vector<double> avgGeneric;
    std::transform(
            avg_main_vec.begin(),
            avg_main_vec.end(),
            avg_X.begin(),
            std::back_inserter(avgGeneric),
            [](auto& first,auto& n){return ((double)first)/((double)n*std::log(std::log(n)));}
    );

    make_plot(X,generic,avg_X,avgGeneric,title,ylabel);
};