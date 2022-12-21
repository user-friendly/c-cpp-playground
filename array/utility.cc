/*
 * utility.c
 *
 *  Created on: Feb 12, 2021
 *      Author: pivanov
 */

#include <cstdio>
#include <cstring>

#include <iostream>
#include <string>
#include <sstream>
#include <iterator>
#include <random>
#include <algorithm>

#include "utility.h"

#define TEXT_FORMAT "%zu %s"
#define TEXT_FORMAT_EXT "%zu.%zu %s"
#define TEXT_BUFFER_SZ 128

using namespace std;

char text_buffer[TEXT_BUFFER_SZ];
const char* units[] = {"B", "kB", "MB", "GB", "TB", "PB", "EB", "ZB", "YB"};

const char* format_size_t(size_t size) {
    int i = 0;
    size_t remainder = 0;
    while (size > 1024) {
    	remainder %= 1024;
        size /= 1024;
        i++;
    }
    if (remainder > 0) {
    	snprintf(text_buffer, TEXT_BUFFER_SZ, TEXT_FORMAT, size, units[i]);
    }
    else {
    	snprintf(text_buffer, TEXT_BUFFER_SZ, TEXT_FORMAT_EXT, size, remainder, units[i]);
    }
    return text_buffer;
}

list generate_random_number_list(std::size_t n, int min, int max) {
	std::random_device 	r;
	std::seed_seq		seed ({r(), r(), r(), r(), r(), r(), r(), r()});
	std::mt19937		eng (seed);

	std::uniform_int_distribution<int> dist (min, max);
	list v(n);
	generate(begin(v), end(v), [&]() {return dist(eng);});

	return v;
}

void print_list(const list& lst) {
    if (lst.size() == 0) {
        return;
    }
    list::const_iterator lit = lst.end()-1;
    for (list::const_iterator it = lst.begin(); it != lit; it++) {
        cout << *it << " ";
    }
    cout << *lit;
}

ostream& operator<<(ostream& os, const list& lst) {
    if (lst.size() > 0) {
        print_list(lst);
    }
    return os;
}

bool print_command_help(int& argc, char *argv[]) {
	if (argc > 1 && (0 == strcmp(argv[1], "-h") || 0 == strcmp(argv[1], "--help"))) {
		cout << COMMAND_HELP << endl;
		return true;
	}
	return false;
}

bool print_generate_lists(int& argc, char *argv[]) {
	// Generates and outputs a list of numbers, one per line.
	if (argc > 1 && 0 == strcmp(argv[1], "-g")) {
		unsigned int    num_list = 10;
		int             elem_min = 1, elem_max = 100;
        unsigned int    size_min = 10, size_max = 100;

		if (argc > 2) {
			num_list = atoi(argv[2]);
		}
		if (num_list == 0) {
		    return true;
		}
		if (argc > 3) {
			elem_min = atoi(argv[3]);
		}
		if (argc > 4) {
			elem_max = atoi(argv[4]);
		}
		if (argc > 5) {
			size_min = atoi(argv[5]);
		}
		if (argc > 6) {
            size_max = atoi(argv[6]);
        }
		else {
		    size_max = size_min;
		}
		if (size_min == 0) {
		    return true;
		}

		// Bounds correction.
		if (size_min > size_max) {
		    size_min = size_max;
		}

		// Generate a list of random numbers, within the SIZE_* range.
		// Needed for the variation of elements per list. The size_* variables
		// are supplied at program invocation.
		list el_lst = generate_random_number_list(num_list, size_min, size_max);
		sort(el_lst.begin(), el_lst.end());

		// Prints (meta) the number of elements each list has.
		cout << el_lst << endl << endl;

		// Prints all lists, in order as printed by the meta.
		list::const_iterator lit = el_lst.end()-1;
		for (list::const_iterator it = el_lst.begin(); it != lit; it++) {
		    cout << generate_random_number_list(*it, elem_min, elem_max) << endl;
		}
		cout << generate_random_number_list(*lit, elem_min, elem_max);
		return true;
	}
	return false;
};
