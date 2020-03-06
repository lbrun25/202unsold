/*
** EPITECH PROJECT, 2020
** 202unsold_2019
** File description:
** TODO: add description
*/

#include "Unsold.hpp"

// Life cycle

Unsold::Unsold(int const &a, const int &b):
_a(a), _b(b), _expectedX(0.0), _varianceX(0.0), _expectedY(0.0), _varianceY(0.0), _expectedZ(0.0), _varianceZ(0.0)
{
    this->_suitPrices.emplace_back(10);
    this->_suitPrices.emplace_back(20);
    this->_suitPrices.emplace_back(30);
    this->_suitPrices.emplace_back(40);
    this->_suitPrices.emplace_back(50);
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
    double xLaw = 0.0;
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
        this->_yLaws.emplace_back(yLaw);
        ++i;
    }
    // X law
    std::cout << "X law\t";
    for (int x = 0; x < NB_PRICES; ++x) {
        double sum = 0.0;
        for (int y = 0; y < NB_PRICES; ++y)
            sum += arrProbs[y][x];
        xLaw += sum;
        std::cout << std::fixed << std::setprecision(PRECISION) << sum << "\t";
        this->_xLaws.emplace_back(sum);
        ++i;
    }
    std::cout << std::fixed << std::setprecision(PRECISION) << xLaw << std::endl;
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
                zLaw = computeProbability(x * COEFF, y * COEFF);
                if (x + y == z && y < 6)
                    sum += zLaw;
            }
        }
        std::cout << std::fixed << std::setprecision(PRECISION) << sum;
    }
    std::cout << "\n" << std::setfill('-') << std::setw(NB_DASHES) << "\n";
}

void Unsold::computeExpectedValues() {
    for (int i = 0; i < NB_PRICES; ++i) {
        this->_expectedX += this->_xLaws.at(i) * ((i + 1) * COEFF);
        this->_expectedY += this->_yLaws.at(i) * ((i + 1) * COEFF);
    }
    this->_expectedZ = this->_expectedX + this->_expectedY;
}

void Unsold::computeVariances() {
    for (int i = 0; i < NB_PRICES; ++i) {
        // Do pow 2
        this->_varianceX += ((i + 1) * COEFF - this->getExpectedX()) * ((i + 1) * COEFF - this->getExpectedX()) * this->_xLaws.at(i);
        this->_varianceY += ((i + 1) * COEFF - this->getExpectedY()) * ((i + 1) * COEFF - this->getExpectedY()) * this->_yLaws.at(i);
    }
    this->_varianceZ = this->_varianceX + this->_varianceY;
}

void Unsold::printExpectedValuesVariances() {
    this->computeExpectedValues();
    this->computeVariances();

    std::cout << "expected value of X:\t" << std::fixed << std::setprecision(PRECISION_EXPECTED_VARIANCE)
              << this->getExpectedX() << std::endl;
    std::cout << "variance of X:\t\t" << std::fixed << std::setprecision(PRECISION_EXPECTED_VARIANCE)
              << this->getVarianceX() << std::endl;
    std::cout << "expected value of Y:\t" << std::fixed << std::setprecision(PRECISION_EXPECTED_VARIANCE)
              << this->getExpectedY() << std::endl;
    std::cout << "variance of Y:\t\t" << std::fixed << std::setprecision(PRECISION_EXPECTED_VARIANCE)
              << this->getVarianceY() << std::endl;
    std::cout << "expected value of Z:\t" << std::fixed << std::setprecision(PRECISION_EXPECTED_VARIANCE)
              << this->getExpectedZ() << std::endl;
    std::cout << "variance of Z:\t\t" << std::fixed << std::setprecision(PRECISION_EXPECTED_VARIANCE)
              << this->getVarianceZ() << std::endl;

    std::cout << std::setfill('-') << std::setw(NB_DASHES) << "\n";
}

// Getters

double const& Unsold::getExpectedX() {
    return this->_expectedX;
}

double const& Unsold::getVarianceX() {
    return this->_varianceX;
}

double const& Unsold::getExpectedY() {
    return this->_expectedY;
}

double const& Unsold::getVarianceY() {
    return this->_varianceY;
}

double const& Unsold::getExpectedZ() {
    return this->_expectedZ;
}

double const& Unsold::getVarianceZ() {
    return this->_varianceZ;
}