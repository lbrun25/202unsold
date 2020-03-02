/*
** EPITECH PROJECT, 2020
** 202unsold_2019
** File description:
** TODO: add description
*/

#ifndef INC_202UNSOLD_2019_PARSER_HPP_
#define INC_202UNSOLD_2019_PARSER_HPP_

#ifndef ARGS_ERROR_
#define TOO_MANY_ARGS "There are too many arguments.\n"
#define NOT_ENOUGH_ARGS "There are not enough arguments.\n"
#define CATCH_INVALID_ARGUMENTS "Catch 'invalid_argument'."
#define CATCH_OUT_OF_RANGE "Catch 'out_of_range'."
#endif

#include <iostream>

class Parser {

private:
    int _argc;
    char **_argv;
    double _a;
    double _b;

    void printHelp();

public:
    // Life cycle
    explicit Parser(int &argc, char **argv);
    ~Parser();

    // Methods
    bool check_argc();
    bool check_help_flag();
    bool check_argv();

    // Getters
    double const &getA();
    double const &getB();

};


#endif //INC_202UNSOLD_2019_PARSER_HPP
