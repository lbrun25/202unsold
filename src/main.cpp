/*
** EPITECH PROJECT, 2020
** 202unsold_2019
** File description:
** main
*/

#include "Parser.hpp"
#include "Unsold.hpp"

int main(int argc, char **argv)
{
    Parser parser(argc, argv);
    if (parser.check_help_flag())
        return (0);
    if (!parser.check_argc() || !parser.check_argv())
        return 84;
    Unsold unsold(parser.getA(), parser.getB());
    unsold.printJointLaw();
    unsold.printLawZ();
    unsold.printExpectedValuesVariances();
    return 0;
}