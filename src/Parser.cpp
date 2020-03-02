/*
** EPITECH PROJECT, 2020
** 202unsold_2019
** File description:
** TODO: add description
*/

#include "Parser.hpp"

// Life cycle

Parser::Parser(int &argc, char **argv):
_argc(argc), _argv(argv), _a(0.0), _b(0.0)
{}

Parser::~Parser() = default;

// Methods

void Parser::printHelp() {
    std::cout << "USAGE\n";
    std::cout << "\t./202unsold a b\n\n";
    std::cout << "DESCRIPTION\n";
    std::cout << "\ta\t\tconstant computed from past results\n";
    std::cout << "\tb\t\tconstant computed from past results" << std::endl;
}

bool Parser::check_argc() {
    if (_argc > 3) {
        std::cerr << TOO_MANY_ARGS << std::endl;
        this->printHelp();
        return false;
    }
    if (_argc < 3) {
        std::cerr << NOT_ENOUGH_ARGS << std::endl;
        this->printHelp();
        return false;
    }
    return true;
}

bool Parser::check_help_flag() {
    for (int i = 0; this->_argv[i]; ++i) {
        if (std::string(this->_argv[i]) == "-h") {
            this->printHelp();
            return true;
        }
    }
    return false;
}

bool Parser::check_argv() {
    try {
        this->_a = std::stod(this->_argv[1]);
        this->_b = std::stod(this->_argv[2]);
    } catch (std::invalid_argument const &e) {
        std::cerr << CATCH_INVALID_ARGUMENTS << std::endl;
        return false;
    } catch (std::out_of_range const &e) {
        std::cerr << CATCH_OUT_OF_RANGE << std::endl;
        return false;
    }
    return true;
}

// Getters

double const& Parser::getA() {
    return this->_a;
}

double const& Parser::getB() {
    return this->_b;
}

