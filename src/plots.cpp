//
// Created by JS on 26.11.2024.
//

#include "../include/plots.h"
#include "../include/experiments.h"
#include "../include/matplotlibcpp.h"
namespace plt=matplotlibcpp;

void make_plot(const std::vector<int>& X, const std::vector<int>& Y, const std::vector<double>& avgX, const std::vector<double>& avgY, const std::string& title, const std::string& ylabel) {
    plt::scatter(X,Y,2);
    plt::title(title);
    plt::xlabel("n");
    plt::ylabel(ylabel);
    plt::plot(avgX,avgY,{{"c","red"}});
    plt::save("../plots/"+title);
    plt::clf();
}

void make_plot(const std::vector<int>& X, const std::vector<double>& Y, const std::vector<double>& avgX, const std::vector<double>& avgY, const std::string& title, const std::string& ylabel) {
    plt::scatter(X,Y,2);
    plt::title(title);
    plt::xlabel("n");
    plt::ylabel(ylabel);
    plt::plot(avgX,avgY,{{"c","red"}});
    plt::save("../plots/"+title);
    plt::clf();
}
