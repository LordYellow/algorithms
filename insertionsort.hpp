#ifndef INSERTIONSORT_HPP
#define INSERTIONSORT_HPP

#include "./utility.hpp"
#include <fstream>

template <class T>
sort_stats insertion_sort(T* arr, const size_t& siz, bool reverse = false,
		   void (*view)(const T*, const size_t*,
				 	   const size_t*, const size_t*
					   ) = no_viewer<T>,
           bool (*comp)(const T&, const T&) = generic_compare<T>,
		   const std::string& save_file ="") {
	T wert; size_t tmp;
	std::streambuf* logd = log(save_file);
	sort_stats ret(siz, "insertionsort");
	view(arr,&siz,&siz,nullptr);
	for(size_t idx = 1; idx < siz && ++ret.compares; idx++) {
		wert=arr[idx];
		view(arr,&siz,&idx,nullptr);
		while(idx>0&&(comp(arr[idx-1],wert)^reverse)&&++ret.swaps) {
			view(arr,&siz,&idx,&(tmp=idx-1));
			arr[idx] = arr[idx-1];
			arr[--idx] = wert;
		}
	}
	view(arr,&siz,&siz,nullptr);
	return ret;
}

#endif
