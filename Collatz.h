// --------------------------
// projects/collatz/Collatz.h
// Copyright (C) 2013
// Glenn P. Downing
// --------------------------

#ifndef Collatz_h
#define Collatz_h

// --------
// includes
// --------

#include <iostream> // istream, ostream

// ------------
// collatz_read
// ------------

/**
 * reads two ints into i and j
 * @param r a  std::istream
 * @param i an int by reference
 * @param j an int by reference
 * @return true if that succeeds, false otherwise
 */
bool collatz_read (std::istream&r, int&i, int&j){
	r>>i;
	if(!r)
		return false;
	r>>j; 
	assert(i>0);
	assert(j>0);
	return true;

}

// ------------
// collatz_eval
// ------------

/**
 * @param i the beginning of the range, inclusive
 * @param j the end       of the range, inclusive
 * @return the max cycle length in the range [i, j]
 */
int collatz_eval (int i, int j){
	assert(i > 0);
    assert(j > 0);
	cache.clear();
    cache[1]=1;
    
    int bignum;
    int smallnum;
    int v;
    while(1){
    	v=0;
    if(i>j){
        bignum=i;
        smallnum=j;
     }

    else {
       bignum=j;
       smallnum=i;
    }

    while(smallnum<=bignum){
        int tokenv=cycleCalc(smallnum);
        if(tokenv>v)
            v=tokenv;
            smallnum++;
    }

    assert(v > 0);
    return v;}
	
}

// -------------
// collatz_print
// -------------

/**
 * prints the values of i, j, and v
 * @param w a std::ostream
 * @param i the beginning of the range, inclusive
 * @param j the end       of the range, inclusive
 * @param v the max cycle length
 */
void collatz_print (std::ostream& w, int i, int j, int v);
assert(i > 0);
    assert(j > 0);
    assert(v > 0);
    w << i << " " << j << " " << v << std::endl;
// -------------
// collatz_solve
// -------------

/**
 * read, eval, print loop
 * @param r a std::istream
 * @param w a std::ostream
 */
void collatz_solve (std::istream&, std::ostream&);

#endif // Collatz_h
