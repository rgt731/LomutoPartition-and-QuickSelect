#include <iostream>
#include <cmath> //for the ceil() function

using namespace std;

const int SIZE = 9;

//Using variable names from the book
//A is the array being partitioned
//l is the low (left) index of the area being partitioned
//r is the high (right) index of the area being partitioned
//p is the pivot of the area being partitioned
//s is the highest index holding a number known to be less than p

int LomutoPartition(int A[], int l, int r);
int QuickSelect(int A[], int l, int r, int k);
void printArray(int A[]);

int main()
{
  //int median = 0;
  int s = 0;
  int k = static_cast<int>(ceil(SIZE / 2.0)); //This will give the median value
                                              //  of the list
  int A[SIZE] = {4, 1, 10, 8, 7, 12, 9, 2, 15}; //change SIZE to 9
  //int A[SIZE] = {12, 10, 20, 9, 7};           //change SIZE to 5
  //int A[SIZE] = {5,4,3,2,1};                  //change SIZE to 5    
  
  cout << "The median value of the list: " << endl;
  printArray(A);
  //s will hold the index of the kth least value in the list
  //if you choose the middle element as k, s will be the index of the median val
  s = QuickSelect(A, 0, SIZE - 1, k);
  cout << "is " << s << endl;  
}

//Recursive algorithm to find the position in an array (A) of the kth least
//  element
int QuickSelect(int A[], int l, int r, int k)
{
  //s is the pivot determined and put in its correct position by
  //  LomutoPartition
  int s = LomutoPartition(A, l, r);

  //If the pivot is the element we are looking for return its index
  if (s == k - 1)
  {
    return A[s];//return the value of the element;
  }

  //If the pivot is to the right of the element we are looking for
  else if (s >= (l + k - 1))
  {
    s = QuickSelect(A, l, s - 1, k);
  }

  //If the pivot is to the left of the element we are looking for
  else
  {
    s = QuickSelect(A, s + 1 , r, k);
  }
  //return the location of the new pivot
  //NOTE that this is the position of the pivot. The only time to return the
  //  value rather than the position is when you have found the value that 
  //  goes with the position you are looking for
  return s;
}

//Chooses the first element of the array/subarray as a pivot
//Only works with elements l...r of array A
//When it returns the array has been adjusted so that every value to the left
//  of the pivot is < the pivot and every value to the right of the pivot is
//  > the pivot
//Returns the index of the pivot
int LomutoPartition(int A[], int l, int r)
{
  //p is the pivot which is the first element of the array/subarray
  int p = A[l];
  int s = l; //we start with A[s] at the first position which is also p
  for (int i = l + 1; i <= r; i++)
  {
    //If the element we are looking at is less than the pivot
    if (A[i] < p)
    {
      //move the marker between the < and > pivot elements one to the right
      //then swap the < element with first element in what was the > section
      s += 1;
      swap(A[s], A[i]);
    }
  }
  //before you return put the pivot in the appropriate place between
  //  the <'s and >'s
  swap(A[l], A[s]);
  return s;
}

void printArray(int A[])
{
  for (int m = 0; m < SIZE; m++)
  {
    cout << A[m] << " ";
  }
  cout << endl;
}