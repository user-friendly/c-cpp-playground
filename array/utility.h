/*
 * utility.h
 *
 *  Created on: Feb 12, 2021
 *      Author: pivanov
 */

#ifndef SRC_UTILITY_H_
#define SRC_UTILITY_H_

#include <vector>
#include <ostream>

using list = std::vector<int>;

const char* format_size_t(size_t size);

/**
 * Generate a list of integers.
 *
 * Arguments:
 *  n           - number of elements
 *  min, max    - integer range for each element, [min, max]
 *
 * Returns a `list` of random integers.
 */
list generate_random_number_list(std::size_t n, int min = 1, int max = 100);

void print_list(const list&);

std::ostream& operator<<(std::ostream& os, const list& lst);

#define COMMAND_HELP "Usage: ary [OPTIONS]" \
	"\nTest various array sorting algorithms." \
	"\n" \
	"\nIf the option `-g` is used, generate lists of random numbers." \
      /*----------------------------------------------------------------------------*/ \
	"\n -g NUM_LIST MIN MAX SIZE_MIN SIZE_MAX" \
	"\n     Generates NUM_LIST of lists, each having an integer value in the range" \
	"\n     [MIN, MAX], each list having a variable number of elements in the range" \
	"\n     [SIZE_MIN, SIZE_MAX]. NUM_LIST and SIZE_* arguments must be positive" \
	"\n     integers." \
	"\n     The first line of output is (meta) a list of all lists' number of" \
	"\n     elements, followed by a blank line, followed by each list (according" \
	"\n     to the meta order)." \
	"\n" \
	"\n -h, --help" \
	"\n     Prints this help message." \
	"\n"

/**
 * Prints the command's help.
 *
 * Returns true the help option was supplied. False otherwise.
 */
bool print_command_help(int& argc, char *argv[]);

/**
 * Prints lists of numbers.
 *
 * Returns true the generate option was supplied. False otherwise.
 */
bool print_generate_lists(int& argc, char *argv[]);

#endif /* SRC_UTILITY_H_ */
