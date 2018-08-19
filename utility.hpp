#ifndef UTILITY_HPP
#define UTILITY_HPP
/**
 * @file utility.hpp
 * @author Florian Sihler
 * @brief Diese Datei enthält Routinen die allgemein benötigt
 *              werden
 */

#include <fstream>

/**
 * @struct sort_stats
 * @brief Hält Daten zum verwendeten Algorithmus
 */
struct sort_stats {
    sort_stats(size_t el, std::string na):elements(el),name(na){}
	size_t swaps = 0, compares = 0, elements = 0;
    std::string name = "noname";
};  

/**
 * @brief Vertauscht 2 Werte
 * @returns Dieser Tausch liefert Immer Wahr zurück
 */
template <class T>
bool swap_val(T* a, T* b) {
	T tmp = *a;
	*a = *b; *b = tmp;
    return true;
}

std::streambuf* log(const std::string& path) {
	std::ofstream file;
	std::streambuf* old = std::cout.rdbuf();
	if(path != "") {
		file.open(path);
		if(file.good() && file.is_open()) {
			std::streambuf* old = std::cout.rdbuf();
			std::cout.rdbuf(file.rdbuf());
		}
	}
	return old;
}

inline 
void rs_log(std::streambuf* log_buf) {
	std::cout.rdbuf(log_buf);
}


#endif
