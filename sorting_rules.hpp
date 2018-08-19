#ifndef SORTINGRULES_HPP
#define SORTINGRULES_HPP
#include <string>

template <class T>
inline
bool generic_compare(const T& a, const T& b) {
	return (a>b);
}
template <class T>
inline
bool generic_compare_inv(const T& a, const T& b) {
	return (a<b);
}
template <>
inline
bool generic_compare<std::string>(const std::string& a,
					const std::string& b) {
	for(size_t i=0;i<b.size()&&i<a.size();i++) {
		if(a[i]!=b[i]) return (a[i]>b[i]);
	} 
	return true;
} 
#endif