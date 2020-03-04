/*
** EPITECH PROJECT, 2020
** 202unsold_2019
** File description:
** TODO: add description
*/

#ifndef INC_202UNSOLD_2019_ALGORITHM_HPP_
#define INC_202UNSOLD_2019_ALGORITHM_HPP_

#include <vector>
#include <iostream>
#include <iomanip>
#include <numeric>

#ifndef NB_DASHES_
#define NB_DASHES 100
#endif

#ifndef PROBABILITY_
#define INCREMENT_PRICE 10
#define MAX_PRICE 50
#define NB_PRICES 5
#define PRECISION 3
#define START_Z 20
#define MAX_Z 100
#define INCREMENT_Z 10
#endif

class Unsold {

private:
    // Properties
    int const _a;
    int const _b;
    std::vector<int> suitPrices;

    // Methods
    double computeProbability(int x, int y);

public:
    // Life cycle
    Unsold(int const &a, int const &b);
    ~Unsold();

    // Methods
    void printJointLaw();
    void printLawZ();
    void printExpectedValuesVariances();

};


#endif //INC_202UNSOLD_2019_ALGORITHM_HPP
