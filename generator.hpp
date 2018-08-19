#ifndef GENERATOR_HPP
#define GENERATOR_HPP

#include <type_traits>
#include <limits>
#include <vector>

#include <random>

template <class T = int, bool = std::is_integral<T>::value
							|| std::is_floating_point<T>::value>
struct gen_args {};
template <class T>
struct gen_args<T,true> {
	gen_args() {
		this->max = std::numeric_limits<T>::max(); 
		this->min = std::numeric_limits<T>::lowest();
	}
	gen_args(const T& mi, const T& ma) :min(mi),max(ma) {}
	T max, min;
};

template <class T>
struct gen_args<T,false> {
	gen_args(std::vector<T> pool, size_t len = 1) 
		: _pool(pool), _len(len)  {}
	size_t _len;
	std::vector<T> _pool;
};

std::string alpha_lo[26] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
char alpha_hi[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char specials[7]  = {'#','-','_','.','=','-','?'};

template<class T>
typename std::enable_if<!std::is_integral<T>::value &&
						!std::is_floating_point<T>::value ,void>::type generate(
			T* arr, const size_t& size, 
			const gen_args<T>& args,
			std::mt19937* r_engine) {
	std::uniform_int_distribution<size_t> d(0,args._pool.size()-1);
	for(size_t idx = 0; idx < size; idx++) {
		if(args._len == 1)
			arr[idx] = args._pool[d(*r_engine)];
		else for(size_t sub_idx = 0; sub_idx < args._len; sub_idx++)
			arr[idx] += args._pool[d(*r_engine)];
	} 
}
/* anonymous [hidden - access by gen<typename T>(...)]  */
//change so that every generator prepares diatribution and passes with random...

template<class T>
inline
typename std::enable_if<std::is_integral<T>::value
						 ,void>::type generate(
			T* arr, const size_t& size, 
			const gen_args<T>& args,
			std::mt19937* r_engine) {
	std::uniform_int_distribution<T> d(args.min,args.max); 
	for(size_t idx = 0; idx < size; idx++)
		arr[idx] = d(*r_engine) ;
	
}

template <class T>
inline
typename std::enable_if<std::is_floating_point<T>::value
						,void>::type generate (
					  T* arr, const size_t& size,
					  const gen_args<T>& args,
					  std::mt19937* r_engine) {
	std::uniform_real_distribution<T> d(args.min,args.max);
	for(size_t idx = 0; idx < size; idx++)
		arr[idx] = d(*r_engine);
			/*(rand()/((float)RAND_MAX)) * (args.max - args.min);*/
}

#endif