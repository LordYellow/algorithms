#ifndef WRAPPER_HPP
#define WRAPPER_HPP


/// @todo seq control and 0 range check etc.

#include <vector>
#include <fstream>

#include "./generator.hpp"
#include "./bubblesort.hpp"

// ------------------------------------------------------------------
template <class T> 
inline void gen(T* arr, const size_t& size, 
		 const gen_args<T>& args = gen_args<T>()) {
	std::mt19937 re(std::random_device{}());
	generate<T>(arr,size,args,&re);
}

template <class T>
inline void gen(T* arr, const size_t& size,
		 T min, T max) {
	gen(arr,size,gen_args<T>(min,max));
}

template <class T>
inline void gen(T* arr, const size_t& size,
		 std::vector<T> pool, const size_t& len) {
	gen(arr,size,gen_args<T>(pool, len));
}

template <class T>
inline std::vector<T> gen(const size_t& size, const gen_args<T>& args = gen_args<T>()) {
	std::mt19937 re(std::random_device{}());
	T arr[size];
	generate<T>(arr,size,args,&re);
	return std::vector<T>(arr,arr+size);
}
template <class T>
inline std::vector<T> gen(const size_t& size,
		 T min, T max) {
	return gen(size,gen_args<T>(min,max));
}

template <class T>
inline std::vector<T> gen( const size_t& size,
		 std::vector<T> pool, const size_t& len) {
	return gen(size,gen_args<T>(pool, len));
}

// ------------------------------------------------------------------

template <class T>
sort_stats bubble_sort(std::vector<T> vec, bool reverse = false,
		   void (*view)(const T*, const size_t*,
				 const size_t*, const size_t*
				) = no_viewer<T>,
           bool (*comp)(const T&, const T&) = generic_compare<T>,
		   const std::string& file_path = "" ) {
	return bubble_sort<T>(&vec[0],vec.size(),reverse, view, comp, file_path);
}

#endif
