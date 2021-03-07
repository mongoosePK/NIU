/*
 * By: William Pulkownik z1805341
 * Due: 10Feb2017
 * program: assignment2.cc
 * description: this program implements 2 search algorithms (binary and Linear) 
 * on random ints in a vector then displays them
*/
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <iostream>

const int DATA_SIZE = 200;
const int SEARCH_SIZE = 100;
const int DATA_SEED = 7;
const int SEARCH_SEED = 9;
// genRndNums takes a vector and populates it with random integers
// generated with a seed value using the rand() and srand() functions
void genRndNums( vector<int>& v, int seed ) {
}
// linearSearch uses the find() function to search a vector for x from start to end, stopping 
// if a match is found and returning the index, -1 otherwise
int linearSearch( const vector<int>& inputVec, int x) {
}
// binarySearch searches a vector for x, returns index if successful and -1 if not
// the search is conducted using the equal_range library function
int binarySearch( const vector<int>& inputVec, int x) {
}
// A generic search algorithm – takes a pointer to the search routine p( ), 
// and then it calls p( ) for each element of vector searchVec in vector inputVec.
// It computes the total number of successful searches and returns that value to the main ( )
// routine as an input argument to the print routine printStat ( ),
// which is used to print out the final statistics for a search algorithm. 
int search( const vector<int>& inputVec, const vector<int>& searchVec,
            int (*p)( const vector<int>&, int) ){
}
// sortVector() uses the sort() library function to arrange the vector into ascending order
void sortVector (vector<int>& inputVec) {
}
// printStat() prints the % of successful searches as a floating pt number as std output where
// totalSucCnt is the total num of successful comparisons. vec_size is inputVec size
void printStat (int totalSucCnt, int vec_size) {
}
// prints contents of vector to stdout, 12 per line max, column width of 5
void print_vec( const vector<int>& vec ){
}

int main() {
    vector<int> inputVec(DATA_SIZE);
    vector<int> searchVec(SEARCH_SIZE);
    genRndNums(inputVec, DATA_SEED);
    genRndNums(searchVec, SEARCH_SEED);

    cout << "----- Data source: " << inputVec.size() << " randomly generated numbers ------" << endl;
    print_vec( inputVec );
    cout << "----- " << searchVec.size() << " random numbers to be searched -------" << endl;
    print_vec( searchVec );

    cout << "\nConducting linear search on unsorted data source ..." << endl;
    int linear_search_count = search( inputVec, searchVec, linearSearch );
    printStat ( linear_search_count, SEARCH_SIZE );

    cout << "\nConducting binary search on unsorted data source ..." << endl;
    int binary_search_count = search( inputVec, searchVec, binarySearch );
    printStat ( binary_search_count, SEARCH_SIZE );

    sortVector( inputVec );

    cout << "\nConducting linear search on sorted data source ..." << endl;
    linear_search_count = search( inputVec, searchVec, linearSearch );
    printStat ( linear_search_count, SEARCH_SIZE );

    cout << "\nConducting binary search on sorted data source ..." << endl;
    binary_search_count = search( inputVec, searchVec, binarySearch );
    printStat ( binary_search_count, SEARCH_SIZE );

    return 0;
}
