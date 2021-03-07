///////////////////////////////////////////////////
// vector3.cc : Capacity of vector
//
// Author: Minmei Hou
// Date: 08/29/2011
//
// Note how capacity increases
// Note the difference between resize() and reserve()
//
// compilation:
//      g++ -g -Wall vector2.cc -o vector2.exe
// run:
//      ./vector2.exe
///////////////////////////////////////////////////

#include <vector>
#include <iostream>
using namespace std;

template <class T>
void showCont(const T &cont) {
  typename T::const_iterator it;  // note the use of typename in front
  for(it = cont.begin(); it != cont.end(); it++)
    cout << *it << " ";
  cout << endl;
}

template <class T>
void showRevCont(const T &cont) {
  typename T::const_reverse_iterator it;  // note the use of typename in front
  for(it = cont.rbegin(); it != cont.rend(); it++)
    cout << *it << " ";
  cout << endl;
}

int main() {
  vector<int> defVec;
  cout << "A default vector is created ...\n";
  cout << "Capacity of default vector: " << defVec.capacity() << endl;
  cout << "max_size of default vector: " << defVec.max_size() << endl;
  cout << "size of default vector: " << defVec.size() << endl;

  defVec.push_back(1);
  cout << "\nOne element is added to the vector ...\n";
  cout << "Capacity of vector: " << defVec.capacity() << endl;
  cout << "max_size of vector: " << defVec.max_size() << endl;
  cout << "size of vector: " << defVec.size() << endl;

  defVec.push_back(2);
  cout << "\nOne more element is added to the vector ...\n";
  cout << "Capacity of vector: " << defVec.capacity() << endl;
  cout << "max_size of vector: " << defVec.max_size() << endl;
  cout << "size of vector: " << defVec.size() << endl;

  defVec.push_back(3);
  cout << "\nOne more element is added to the vector ...\n";
  cout << "Capacity of vector: " << defVec.capacity() << endl;
  cout << "max_size of vector: " << defVec.max_size() << endl;
  cout << "size of vector: " << defVec.size() << endl;

  defVec.push_back(4);
  cout << "\nOne more element is added to the vector ...\n";
  cout << "Capacity of vector: " << defVec.capacity() << endl;
  cout << "max_size of vector: " << defVec.max_size() << endl;
  cout << "size of vector: " << defVec.size() << endl;

  defVec.push_back(5);
  cout << "\nOne more element is added to the vector ...\n";
  cout << "Capacity of vector: " << defVec.capacity() << endl;
  cout << "max_size of vector: " << defVec.max_size() << endl;
  cout << "size of vector: " << defVec.size() << endl;

  cout << "\nCurrently the vector has: ";
  showCont(defVec);

  defVec.resize(10);
  cout << "\nCalling resize(10) ...\n";
  cout << "\nCurrently the vector has: ";
  showCont(defVec);
  cout << "Capacity of vector: " << defVec.capacity() << endl;
  cout << "max_size of vector: " << defVec.max_size() << endl;
  cout << "size of vector: " << defVec.size() << endl;

  defVec.reserve(15);
  cout << "\nCalling reserve(15) ...\n";
  cout << "\nCurrently the vector has: ";
  showCont(defVec);
  cout << "Capacity of vector: " << defVec.capacity() << endl;
  cout << "max_size of vector: " << defVec.max_size() << endl;
  cout << "size of vector: " << defVec.size() << endl;

  cout << "\nReversing traverse the vector: \n";
  showRevCont(defVec);

  cout << "\nAccessing elements via [ ] ...\n";
  int size = defVec.size(), i;
  for (i=0; i<size; i++)
    cout << defVec[i] << " ";
  cout << endl;

  cout << "\nAccessing elements by at ...\n";
  for (i=0; i<size; i++)
    cout << defVec.at(i) << " ";
  cout << endl;

  cout << "\nAccessing first element by front: ";
  cout << defVec.front();
  
  cout << "\n\nAccessing last element by back: ";
  cout << defVec.back();

  cout << "\n\nRemove an element from the end ...\n";
  defVec.pop_back();
  cout << "\nCurrently the vector has: ";
  showCont(defVec);
  cout << "Capacity of vector: " << defVec.capacity() << endl;
  cout << "max_size of vector: " << defVec.max_size() << endl;
  cout << "size of vector: " << defVec.size() << endl;
 
  cout << "\nRemove all elements from the vector ...\n";
  defVec.clear();
  cout << "\nCurrently the vector has: ";
  showCont(defVec);
  cout << "Capacity of vector: " << defVec.capacity() << endl;
  cout << "max_size of vector: " << defVec.max_size() << endl;
  cout << "size of vector: " << defVec.size() << endl;

  return 0;
}
