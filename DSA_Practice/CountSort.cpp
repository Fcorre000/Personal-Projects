#include <iostream>
#include <vector>
using namespace std;

void countSort(vector<int>& arr, int k){
    vector<int> counts(k + 1, 0);//initialize counts array with zeros
    vector<int> sorted_copy(arr.size());
    int j;
    int t;

    
    for(t = 0; t < arr.size(); t++){
        counts[arr[t]]++;//updates counts
    }

    //cumulative sum
    for(j = 1; j <= k; j++){
        counts[j] = counts[j] + counts[j - 1];
    }
    //copy data into sorted order in the sorted array
    for(t = arr.size() - 1; t >= 0; t--){
        counts[arr[t]]--;
        sorted_copy[counts[arr[t]]] = arr[t];
        /*counts[arr[t]] holds the index (+1) where arr[t] will be
        in the sorted array*/
    }
    
    //copy back into original array
    for(t = 0; t < arr.size(); t++){
        arr[t] = sorted_copy[t];
    }
}