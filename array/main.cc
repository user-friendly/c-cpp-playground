/*
 * @file
 * Main program file.
 */

#include "config.h"

#include <vector>
#include <unordered_set>

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
void sort_insertion(list&);

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

	if (argc < 2) {
	    cerr << "error: no sorting algorithm supplied" << endl;
	    return EXIT_FAILURE;
	}

	// TODO Implement a custom struct, members: sort function and label.
	unordered_set<string> algos {
	    "select"s,
	    "insert"s
	};

	auto al = algos.find(argv[1]);
	if (al == algos.end()) {
	    cerr << "error: sorting algorithm `" << argv[1] << "` not found" << endl;
        return EXIT_FAILURE;
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

		if (*al == "select"s) {
		    sort_selection(lst);
		} else if (*al == "insert"s) {
		    sort_insertion(lst);
		}
		else {
		    cerr << "error: algorithm `" << *al << "` not found, this should not be the case at this point" << endl;
		    return EXIT_FAILURE;
		}

		cout << lst << endl;
	}

	return EXIT_SUCCESS;
}

/**
 * Selection sort.
 *
 * O(n^2)
 * Not stable.
 *
 * Goes through 1/2(n^2 - n) comparisons and n-1 swaps.
 */
void sort_selection(list& lst) {
	if (lst.size() < 2) {
		return;
	}

	// Index of minimum.
	list::value_type m;
	// Outer iteration loop.
	for (list::size_type i = 0; i < lst.size(); i++) {
		m = i;
		// Find the minimum in the rest of the array.
		for (list::size_type j = i+1; j < lst.size(); j++) {
			if (lst[m] > lst[j]) {
				m = j;
			}
		}
		// Swap current element with minimum on positive index change.
		if (m > i) {
		    swap(lst[i], lst[m]);
		}
	}
};

/**
 * Insertion sort.
 *
 * O(n^2)
 * Stable.
 */
void sort_insertion(list& lst) {
    if (lst.size() < 2) {
        return;
    }

    list::value_type x;
    list::size_type j;

    // Begin iteration at the second element onwards.
    for (list::size_type i = 1; i < lst.size(); i++) {
        // Capture current element's value.
        x = lst[i];
        j = i-1;
        // Iterate backwards, shifting elements that are greater than the current.
        for (; j >= 0 && lst[j] > x; j--) {
            lst[j+1] = lst[j];
        }
        lst[j+1] = x;
    }
};
