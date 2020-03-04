/*
** EPITECH PROJECT, 2020
** 202unsold_2019
** File description:
** TODO: add description
*/

#include "Unsold.hpp"

// Life cycle

Unsold::Unsold(int const &a, const int &b):
_a(a), _b(b)
{
    this->suitPrices.emplace_back(10);
    this->suitPrices.emplace_back(20);
    this->suitPrices.emplace_back(30);
    this->suitPrices.emplace_back(40);
    this->suitPrices.emplace_back(50);
}

Unsold::~Unsold() = default;

// Methods

void printFirstRowJointLaw()
{
    std::cout << std::setfill('-') << std::setw(NB_DASHES) << "\n";
    std::cout << "\t";
    for (int x = INCREMENT_PRICE; x <= MAX_PRICE; x += INCREMENT_PRICE)
        std::cout << "X=" << x << "\t";
    std::cout << "Y law" << std::endl;
}

double Unsold::computeProbability(int x, int y) {
    double res = ((this->_a - x) * (this->_b - y)) / ((5.0 * this->_a - 150.0) * (5.0 * this->_b - 150.0));
    return res;
}

void Unsold::printJointLaw() {
    double yLaw;
    double arrProbs[NB_PRICES][NB_PRICES];
    int i = 0;
    int j = 0;

    printFirstRowJointLaw();
    for (int y = INCREMENT_PRICE; y <= MAX_PRICE; y += INCREMENT_PRICE) {
        std::cout << "Y=" << y << "\t";
        yLaw = 0.0;
        j = 0;
        for (int x = INCREMENT_PRICE; x <= MAX_PRICE; x += INCREMENT_PRICE) {
            double prob = computeProbability(x, y);
            std::cout << std::fixed << std::setprecision(PRECISION) << prob << "\t";
            yLaw += prob;
            arrProbs[i][j++] = prob;
        }
        std::cout << std::fixed << std::setprecision(PRECISION) << yLaw << std::endl;
        ++i;
    }
    // X law
    std::cout << "X law\t";
    yLaw = 0.0;
    for (int x = 0; x < NB_PRICES; ++x) {
        double sum = 0.0;
        for (int y = 0; y < NB_PRICES; ++y)
            sum += arrProbs[y][x];
        yLaw += sum;
        std::cout << std::fixed << std::setprecision(PRECISION) << sum << "\t";
        ++i;
    }
    std::cout << std::fixed << std::setprecision(PRECISION) << yLaw << std::endl;
    std::cout << std::setfill('-') << std::setw(NB_DASHES) << "\n";
}

void Unsold::printLawZ() {
    std::cout << "z\t";
    for (int z = START_Z; z <= MAX_Z; z += INCREMENT_Z)
        std::cout << z << "\t";
    std::cout << "\np(Z=z)";
    for (int z = 2; z < 11; ++z) {
        std::cout << "\t";
        double sum = 0.0;
        double zLaw;
        for (int y = 1; y < 6; ++y) {
            for (int x = 1; x < 6; ++x) {
                zLaw = computeProbability(x * 10, y * 10);
                if (x + y == z && y < 6)
                    sum += zLaw;
            }
        }
        std::cout << std::fixed << std::setprecision(PRECISION) << sum;
    }
    std::cout << "\n" << std::setfill('-') << std::setw(NB_DASHES) << "\n";
}

void Unsold::printExpectedValuesVariances() {

    std::cout << "\n" << std::setfill('-') << std::setw(NB_DASHES) << "\n";
}