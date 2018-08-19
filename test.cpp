#include <iostream>
/* Todo include utility. Including swap, debug and swap */
/* Todo generator.h */
/* Todo viewer.h */

#include "./utility.hpp"
#include "./viewer.hpp"
#include "./sorting_rules.hpp"
#include "./generator.hpp"
#include "./wrapper.hpp"
#include "./insertionsort.hpp"
#include <string>


// make wrapper to create e.g. pairs of random number string pairs
int main() {
	sort_stats needed = bubble_sort<int>(gen<int>(300, -300,  300));
	std::cout << "needed: "      << needed.swaps
			  << " swaps and "   << needed.compares 
			  << " compares on " << needed.elements 
			  << " elements"     << std::endl;
	int arstr[9];
	for(int i = 0; i < 9; i++)
		arstr[i] = i;
	needed = insertion_sort<int>(arstr,9,true);
	std::cout << "needed: "      << needed.swaps
			  << " swaps and "   << needed.compares 
			  << " compares on " << needed.elements 
			  << " elements"     << std::endl;
	for(int i = 0; i < 9; i++)
		arstr[i] = i;
	//std::vector<std::string> str_pool(alpha_lo,alpha_lo+26);
	//gen<int>(arstr, 9 , 0, 20);
	needed = bubble_sort<int>(arstr,9,true,generic_viewer);
	std::cout << "needed: "      << needed.swaps
			  << " swaps and "   << needed.compares 
			  << " compares on " << needed.elements 
			  << " elements"     << std::endl;
	return 0;
}
