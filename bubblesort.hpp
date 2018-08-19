#ifndef BUBBLESORT_HPP
#define BUBBLESORT_HPP

#include "./utility.hpp"
#include <fstream>

/**
 * @brief teiloptimaler bubblesort algorithmus sortiert ein array des typs T
 * 
 * Bubblesort vergleicht immer zwei neebneinanderliegende Elemenete und vertauscht diese, sofern
 * das linke "größer" als das rechte ist.
 * Für ein Array der Länge n gilt für die Laufzeit:
 * best: O(n) 
 * avg:  O(n²)
 * wrst: O(n²) 
 * Dabei werden maximal (n*(n-1))/2 Vertauschungen durchgeführt, das Verfahren ist stabil 
 * 
 * @param arr das zu sortierende array, es wird in-place sortiert
 * @param siz die Länge des zu sortierenden arrays ermöglicht mithilfe von arr eine teilsortierung
 * <i> optional </i>
 * @param reverse [=false] invertiert für true die Sortierregel
 * @param view    [=no_viewer] der Viewer zum Anzeigen der einzelnen Schritte
 * @param comp    [=generic_compare] die Sortierregel für den datentyp T
 * @param save_file [=""] eine Datei in die der Viewergeschrieben werden kann bei "" wird cout
 *                        genutzt
 * @returns ein sort_stats objekt was benötigte Vertauschungen, Vergleiche, die Anzahl der
 *          Elemente und den Namen des Algorithmus zurückgibt.
 */
template <class T>
sort_stats bubble_sort(T* arr, const size_t& siz, bool reverse = false,
		   void (*view)(const T*, const size_t*,
				 	   const size_t*, const size_t*
					   ) = no_viewer<T>,
           bool (*comp)(const T&, const T&) = generic_compare<T>,
		   const std::string& save_file ="") {
	std::streambuf* logd = log(save_file);
	view(arr,&siz,&siz,nullptr);
	sort_stats ret(siz,"bubblesort"); size_t tmp, idx, s = siz;
	do {
		idx = 1;
		for(size_t i = 0; i < s-1 && ++ret.compares; ++i) {
			view(arr, &siz, &i, nullptr);
			if(comp(arr[i],arr[i+1]) ^ reverse && ++ret.swaps) {
				view(arr, &siz, &i, &(tmp=i+1));
				swap_val<T>(&arr[i],&arr[(idx=i+1)]);
			}
		}
		s = idx;
	} while(s > 1);
	view(arr,&siz,&siz,nullptr);
	rs_log(logd);
	return ret;
}

#endif
