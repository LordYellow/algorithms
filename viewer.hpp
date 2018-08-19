#ifndef VIEWER_HPP
#define VIEWER_HPP
/**
 * @file viewer.hpp
 * @author Florian Sihler
 * @brief Enthält verschiedene Viewer für die graphische Darstellung der Algorithmen
 */

#include <iostream>
#include <iomanip>
#include <fstream>

/* make typetraits for nbr viewer */
/**
 * @brief Wenn man mal keinen Viewer braucht -> MAGIEEEE
 */
template<class T>
inline
void no_viewer(const T* arr, const size_t* siz,
			const size_t * a, const size_t* b = nullptr) {}

/**
 * @brief einfacher Text-viewer markiert betrachtete Elemente farbig
 * @param arr das Array
 * @param siz die Größe des Arrays
 * @param a element 1
 * <i> optional </i>
 * @param b [=nullptr] element 2
 */
template <class T>
void generic_viewer(const T* arr, const size_t* siz,
		    const size_t * a, const size_t* b = nullptr) {
	std::cout << "Array: [";
	for(size_t d = 0; d < *siz; ++d)
		std::cout << (b!=nullptr &&
			      (d==*a||d==*b)?"\033[38;2;180;190;50m"
			      :((d==*a)?"\033[38;2;20;230;20m":"\033[m"))
			 << std::setw(3) << arr[d] << "\033[m" << ",";
	std::cout << "\033[D]" << std::endl;
}

/**
 * @brief einfacher Balken viewer, nur für Integrale Typen verfügbar
 * @param arr das Array
 * @param siz die Größe des Arrays
 * @param a element 1
 * <i> optional </i>
 * @param b [=nullptr] element 2
 */
template <typename T>
typename std::enable_if<std::is_integral<T>::value,void>::type 
col_bar_viewer(const T* arr, const size_t* siz,
		    const size_t * a, const size_t* b = nullptr) {
	T max = abs(arr[*siz-1]);
	for(size_t f = 0; f < *siz; f++)
		if (abs(arr[f])>max) max = abs(arr[f]);
	for(size_t d = 0; d<*siz;d++)
		std::cout << (b!=nullptr &&
			      (d==*a||d==*b)?"\033[38;2;180;190;50m"
			      :((d==*a)?"\033[38;2;20;230;20m":"\033[m")) 
				  << std::string(abs(arr[d]),((arr[d]<0)?'#':'+')) << "\033[m"
				  << std::endl;
	std::cout << std::string(max,'-')<<std::endl;
}

/**
 * @brief einfacher Säulen viewer, nur für Integrale Typen verfügbar
 * @param arr das Array
 * @param siz die Größe des Arrays
 * @param a element 1
 * <i> optional </i>
 * @param b [=nullptr] element 2
 */
template <typename T>
typename std::enable_if<std::is_integral<T>::value,void>::type
col_pile_viewer(const T* arr, const size_t* siz,
		    const size_t * a, const size_t* b = nullptr) {
	/* Get max Element to map this isn't efficient but portable */
	T max = abs(arr[*siz-1]);
	for(size_t f = 0; f < *siz; f++)
		if (abs(arr[f])>max) max = abs(arr[f]);
	for(int i = 0; i <= max; i++) {
		for(size_t d = 0; d < *siz; d++) {
			std::cout << (b!=nullptr &&
			      (d==*a||d==*b)?"\033[38;2;180;190;50m"
			      :((d==*a)?"\033[38;2;20;230;20m":"\033[m")) 
				  << ((abs(arr[d])>=(max-i))?((arr[d]<0)?"▒":"█"):" ") << "\033[m";
		}
		std::cout << "\n";
	} 
	std::cout << std::string(*siz,'-')<<std::endl;
}

/**
 * @brief einfacher prozentualer Säulen viewer, nur für Integrale Typen verfügbar
 * @param arr das Array
 * @param siz die Größe des Arrays
 * @param a element 1
 * <i> optional </i>
 * @param b [=nullptr] element 2
 */
template <typename T>
typename std::enable_if<std::is_integral<T>::value,void>::type
perc_pile_viewer(const T* arr, const size_t* siz,
		    const size_t * a, const size_t* b = nullptr) {
	/* Get max Element to map this isn't efficient but portable */
	T max = abs(arr[*siz-1]);
	for(size_t f = 0; f < *siz; f++)
		if (abs(arr[f])>max) max = abs(arr[f]);
	for(int i = 0; i <= 100; i++) {
		for(size_t d = 0; d < *siz; d++) {
			std::cout << (b!=nullptr &&
			      (d==*a||d==*b)?"\033[38;2;180;190;50m"
			      :((d==*a)?"\033[38;2;20;230;20m":"\033[m")) 
				  << (((abs(arr[d])/(float)max * 100)>=(100-i))?((arr[d]<0)?"\033[3m▌":"▌"):" ") << "\033[m";
		}
		std::cout << "\n";
	} 
	std::cout << std::string(*siz,'-')<<std::endl;
}
#endif
