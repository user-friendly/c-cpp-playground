/*
 * @file
 * Main program file.
 */

#include "config.h"

#include <vector>

// C11 standard headers.
//#include <cstdlib>
//#include <cstdio>
//#include <cstddef>
//#include <cstdint>

// GNU C Library headers.
//#include <unistd.h>

#include <iostream>
#include <iterator>
#include <sstream>

#include "utility.h"

using namespace std;

void sort_selection(list&);

/**
 * Program entry point.
 *
 * @see https://en.cppreference.com/w/c/language/main_function
 */
int main (int argc, char *argv[]) {
	if (print_command_help(argc, argv)) {
		return EXIT_SUCCESS;
	}

	if (print_generate_lists(argc, argv)) {
		return EXIT_SUCCESS;
	}

	vector<list> v;

	using ii_type = istream_iterator<int>;
	ii_type it_end = ii_type();

	int ignore_lines = 2;
	string line;
	while (getline(cin, line)) {
	    if (ignore_lines-- > 0) {
	        continue;
	    }

		istringstream ss {line};
		ii_type it {ss};

		list lst;

		while (it != it_end) {
			lst.push_back(*it);
			it++;
		}

		sort_selection(lst);

		cout << lst << endl;
	}

	return EXIT_SUCCESS;
}

void sort_selection(list& lst) {
	if (lst.size() < 2) {
		return;
	}

	// Index of minimum.
	int min_i;
	// Holds the temporary value, used for the swap.
	int tmp;
	// Outer iteration loop.
	for (int i = 0; i < lst.size(); i++) {
		min_i = i;
		// Find the minimum in the rest of the array.
		for (int j = i+1; j < lst.size(); j++) {
			if (lst[min_i] > lst[j]) {
				min_i = j;
			}
		}
		// Swap current element with minimum on positive index change.
		if (min_i > i) {
			tmp = lst[i];
			lst[i] = lst[min_i];
			lst[min_i] = tmp;
		}
	}
};
