// Fig. 15.10: Fig15_10.cpp
// Standard Library vector class template.
#include <iostream>
#include <vector> // vector class-template definition
using namespace std;

// prototype for function template printVector
template <typename T> void printVector(const vector<T>& integers2);

class A
{

private:

   int a;
   int b;

public:

   void setA(int a)
   {
      this->a=a;
   }
   
   void setB(int b)
   {
      this->b=b;
   }

   A(int a, int b)
   {
      this->a=a;
      this->b=b;
   }

   A(const A& obj)
   {
      this->a = obj.a;
      this->b = obj.b;
      cout << "Constructor copia" << endl;

   }  // Constructor copia

   int operator[](int i)
   {
      if(i == 0)
         return a;
      else
         return b;
   }

   friend ostream& operator<<(ostream& out, const A& obj)
   {
      out << "Un objeto de tipo A" << endl;
      out << "a = " << obj.a << ",b = " << obj.b << endl;
      return out;
   }

};

/*int main() {
   vector<int> integers; // create vector of ints

   cout << "The initial size of integers is: " << integers.size()
      << "\nThe initial capacity of integers is: " << integers.capacity();

   // function push_back is in vector, deque and list
   integers.push_back(2);                            
   integers.push_back(3);                            
   integers.push_back(4); 


   vector<A> vectorA;
   vectorA.push_back(A(0,0));                           
   vectorA.push_back(A(1,5));                           
   vectorA.push_back(A(2,3));
   printVector(vectorA);
   cout << vectorA[1][1] << endl;     
   cout << vectorA.operator[](2).operator[](0) << endl;    
   cout << vectorA[2] << endl;                  

   cout << "\nThe size of integers is: " << integers.size()
      << "\nThe capacity of integers is: " << integers.capacity();
   cout << "\n\nOutput built-in array using pointer notation: ";
   const size_t SIZE{6}; // define array size
   int values[SIZE]{1, 2, 3, 4, 5, 6}; // initialize values

   // display array using pointer notation
   for (const int* ptr = cbegin(values); ptr != cend(values); ++ptr) {
      cout << *ptr << ' ';
   }

   cout << "\nOutput vector using iterator notation: ";
   printVector(integers);
   cout << "\nReversed contents of vector integers: ";

   // display vector in reverse order using const_reverse_iterator
   for (auto reverseIterator = integers.crbegin();               
      reverseIterator != integers.crend(); ++reverseIterator) {    
      cout << *reverseIterator << ' ';                            
   }                                                              

   cout << endl;
}

// function template for outputting vector elements  
template <typename T> void printVector(const vector<T>& integers2) {
   // display vector elements using const_iterator         
   for (auto constIterator = integers2.cbegin();            
      constIterator != integers2.cend(); ++constIterator) {
      cout << *constIterator << ' ';                       
   }                                                       
}
*/
