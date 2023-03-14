#include <iostream>
#include <map>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void get_frequencies(double arr[], int n);
double most_frequent(double arr[], int n);

int heap_sort_comparisons_count(int arr[], int n); 
int build_heap(int arr[], int n);
int heapify(int arr[], int n, int i);

int main()
{
    
  //  double arr[] = {0,4.0,2.3,2.3,2.3,4.0,4.0,6,6,8};
    double arr[1000];
 //   most_frequent(arr,10);
  //  get_frequencies(arr,10);
  
ifstream numfreq("numfreq");
 string line;
  if (numfreq.is_open())
  {
    int a = 0;
    while ( getline (numfreq,line) )
    {
    arr[a] = stod(line);
      a++;
    }
    numfreq.close();
  }

  else 
  cout << "Unable to open file"; 

 most_frequent(arr,1000);
}

void heapify(double arr[], int n, int i) {


    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;


    if (l < n) 
    {
       
        if (arr[l] > arr[largest])
            largest = l;
    }


    if (r < n) 
    {
   
        if ( arr[r] > arr[largest])
            largest = r;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
       heapify(arr, n, largest);
    }

   
}

void build_heap(double arr[], int n) {

  
    for (int i = n / 2 - 1; i > 0; i--)
        heapify(arr, n, i);


}

void heap_sort_comparisons_count(double arr[], int n) 
{
   

 build_heap(arr, n);

    for (int i = n - 1; i > 0; i--) 
    {
        swap(arr[0], arr[i]);
         heapify(arr, i, 0);
    }


}


void get_frequencies(double arr[], int n)
{

cout<<"Arr: ";
for(int i=0; i<n; i++)
{
    cout<< arr[i]<<" ";
}

cout<<" \n \n";
heap_sort_comparisons_count(arr,n);
map <double, int> freq;

int count = 1;
for (int i=0; i<n-1; i++)
{
    
    if (arr[i]==arr[i+1])
    {
        count++;
       
    }
    else
    { 
        freq[arr[i]]=count;
        count=1;
    }
    freq[arr[n-1]] = count;
}

cout<< "Val  | Freq  \n";
for(auto it = freq.cbegin(); it != freq.cend(); ++it)
{
    cout << setw(3)<< it->first << "  |  " << setw(3) << it->second << "\n";
}

}

double most_frequent(double arr[], int n)
{
heap_sort_comparisons_count(arr,n);
map <double, int> freq;

int count = 1;
for (int i=0; i<n-1; i++)
{
    
    if (arr[i]==arr[i+1])
    {
        count++;
       
    }
    else
    { 
        freq[arr[i]]=count;
        count=1;
    }
    freq[arr[n-1]] = count;
}

cout<< "Val  | Freq  \n";
int max = -1;
double valmax;
for(auto it = freq.cbegin(); it != freq.cend(); ++it)
{
    if (it->second>max)
    {
        valmax = it->first;
        max = it->second;
    }
}
cout<<setw(3)<<valmax<<" | "<<setw(3)<<max;

}