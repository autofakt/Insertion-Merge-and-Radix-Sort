#include <iostream>
#include <ctime>
#include <chrono>
#include <queue>
#include <cstdlib>
#include <sys/time.h>
using namespace std;

void
insertionSort (int arr[], int n)
{
  for (int i = 1; i < n; i++)
    {
      int elem = arr[i];
      int j = i;
      while (j > 0 && arr[j - 1] > elem)
	{
	  arr[j] = arr[j - 1];
	  j--;
	}
      arr[j] = elem;
    }
}


void
merge (int arr[], int low, int high, int mid)
{
  int i, j, k, temp[100000];
  i = low;
  k = low;
  j = mid + 1;
  while (i <= mid && j <= high)
    {
      if (arr[i] < arr[j])
	{
	  temp[k] = arr[i];
	  k++;
	  i++;
	}
      else
	{
	  temp[k] = arr[j];
	  k++;
	  j++;
	}
    }
  while (i <= mid)
    {
      temp[k] = arr[i];
      k++;
      i++;
    }
  while (j <= high)
    {
      temp[k] = arr[j];
      k++;
      j++;
    }
  for (i = low; i < k; i++)
    {
      arr[i] = temp[i];
    }
}

void
mergesort (int a[], int low, int high)
{
  int mid;
  if (low < high)
    {
      mid = (low + high) / 2;
      mergesort (a, low, mid);
      mergesort (a, mid + 1, high);
      merge (a, low, high, mid);
    }
}

void
radixSort (int arr[], int num_digits, int num_items)
{
  queue < int >container[10];
  int modValue = 10;
  int divideValue = 1;
  int digitsTotal = num_digits;


  for (int i = 0; i < digitsTotal; i++)
    {
      int counter = 0;
      for (int i = 0; i < num_items; i++)
	{
	  int temp = (arr[i] % modValue) / divideValue;
	  container[temp].push (arr[i]);
	}

      for (int j = 0; j < 10; j++)
	{
	  while (!container[j].empty ())
	    {
	      arr[counter] = container[j].front ();
	      container[j].pop ();
	      counter++;
	    }
	}

      modValue = modValue * 10;
      divideValue = divideValue * 10;
    }

}

void
arrayPrint (int arr[])
{
  for (int i = 0; i < 25; i++)
    cout << arr[i] << " ";
  cout << endl;
}

void
randomArrayPrint (int arr[])
{
  for (int i = 0; i < 100000; i++)
    cout << arr[i] << " ";
  cout << endl;
}

void
shuffle (int *arr, size_t n)
{
  if (n > 1)
    {
      size_t i;
      srand (time (NULL));
      for (i = 0; i < n - 1; i++)
	{
	  size_t j = i + rand () / (RAND_MAX / (n - i) + 1);
	  int t = arr[j];
	  arr[j] = arr[i];
	  arr[i] = t;
	}
    }
}

int
main ()
{
  int arr[25] = {
    34, 10, 33, 11, 32, 12, 31, 13, 30, 14, 29, 15, 28, 16, 27, 17, 26, 18,
    25, 19, 24, 20, 23, 21, 22
  };
  cout << "Insertion Sort Before: " << endl;
  arrayPrint (arr);
  cout << endl;
  insertionSort (arr, 25);
  cout << "Insertion Sort After: " << endl;
  arrayPrint (arr);

  cout << endl;
  cout << endl;

  int arr2[25] = {
    34, 10, 33, 11, 32, 12, 31, 13, 30, 14, 29, 15, 28, 16, 27, 17, 26, 18,
    25, 19, 24, 20, 23, 21, 22
  };
  cout << "Merge Sort Before: " << endl;
  arrayPrint (arr2);
  cout << endl;
  mergesort (arr2, 0, 24);
  cout << "Merge Sort After: " << endl;
  arrayPrint (arr2);

  cout << endl;
  cout << endl;

  int arr3[25] = {
    34, 10, 33, 11, 32, 12, 31, 13, 30, 14, 29, 15, 28, 16, 27, 17, 26, 18,
    25, 19, 24, 20, 23, 21, 22
  };
  cout << "Radix Sort Before: " << endl;
  arrayPrint (arr3);
  cout << endl;
  radixSort (arr3, 2, 25);
  cout << "Radix Sort After: " << endl;
  arrayPrint (arr3);

  cout << endl;
  cout << endl;

  srand (time (NULL));		// Seed the time

  struct timeval start, stop;
  double secs;

  secs = 0;

  cout << "Insertion Sort Times" << endl;
  cout << "----------------------------------" << endl;
  cout << "100,000 element array created" << endl;

  gettimeofday (&start, NULL);
  int randomArray[100000];
  for (int i = 0; i < 100000; i++)
    {
      randomArray[i] = i + 123456;
    }
  shuffle (randomArray, 100000);
  gettimeofday (&stop, NULL);
  secs =
    (double) (stop.tv_usec - start.tv_usec) / 1000000 +
    (double) (stop.tv_sec - start.tv_sec);
  cout << "time taken: " << secs << endl;
//-----------------------------------------------------------
  secs = 0;

  cout << "100,000 elements sorted" << endl;
  gettimeofday (&start, NULL);
  insertionSort (randomArray, 100000);
  gettimeofday (&stop, NULL);
  secs =
    (double) (stop.tv_usec - start.tv_usec) / 1000000 +
    (double) (stop.tv_sec - start.tv_sec);
  cout << "time taken: " << secs << endl;
  cout << endl;
  secs = 0;

  cout << "Radix Sort Times" << endl;
  cout << "----------------------------------" << endl;
  cout << "100,000 element array created" << endl;

  gettimeofday (&start, NULL);
  int randomArray2[100000];
  for (int i = 0; i < 100000; i++)
    {
      randomArray2[i] = i + 123456;
    }
  shuffle (randomArray2, 100000);
  gettimeofday (&stop, NULL);
  secs =
    (double) (stop.tv_usec - start.tv_usec) / 1000000 +
    (double) (stop.tv_sec - start.tv_sec);
  cout << "time taken: " << secs << endl;
//------------------------------------------------------------
  secs = 0;

  cout << "100,000 elements sorted" << endl;
  gettimeofday (&start, NULL);
  radixSort (randomArray2, 6, 100000);
  gettimeofday (&stop, NULL);
  secs =
    (double) (stop.tv_usec - start.tv_usec) / 1000000 +
    (double) (stop.tv_sec - start.tv_sec);
  cout << "time taken: " << secs << endl;
  cout << endl;
  secs = 0;

  cout << "Merge Sort Times" << endl;
  cout << "----------------------------------" << endl;
  cout << "100,000 element array created" << endl;

  gettimeofday (&start, NULL);
  int randomArray3[100000];
  for (int i = 0; i < 100000; i++)
    {
      randomArray3[i] = i + 123456;
    }
  shuffle (randomArray3, 100000);
  gettimeofday (&stop, NULL);
  secs =
    (double) (stop.tv_usec - start.tv_usec) / 1000000 +
    (double) (stop.tv_sec - start.tv_sec);
  cout << "time taken: " << secs << endl;
//-----------------------------------------------------------
  secs = 0;

  cout << "100,000 elements sorted" << endl;
  gettimeofday (&start, NULL);
  mergesort (randomArray3, 0, 99999);
  gettimeofday (&stop, NULL);
  secs =
    (double) (stop.tv_usec - start.tv_usec) / 1000000 +
    (double) (stop.tv_sec - start.tv_sec);
  cout << "time taken: " << secs << endl;


  return 0;
}


