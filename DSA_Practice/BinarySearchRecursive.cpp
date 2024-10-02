#include <iostream>
using namespace std;
#include <vector>
#include <cstdlib>//for rand() and srand()
#include <ctime> // for time()
#include <algorithm>

int RecursiveSearch(const vector<int>& A, int left, int right, int target){
    int iterations = 0;
    int middle = (left + right) / 2;
    
    if(left > right) return -1;//target not found

    if (target == A[middle]) return middle;//target found

    if(left == right) return -1;// target not found   

    if(target < A[middle]){
        iterations++;
        return RecursiveSearch(A, left, middle - 1, target);
    }else{ 
        iterations++;
        return RecursiveSearch(A, middle + 1, right, target);
    }
}

int main(){

    cout << "\nWelcome to my Recursive Binary Search testing Program.\n";
    cout << "Enter the size of you array and we will generate random numbers\n";
    cout << "for said array\n";

    int arrSize = 0;
    cout <<"Array Size: ";
    cin >> arrSize;

    //seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    vector<int> CustomArr(arrSize);

    for(int i = 0; i < CustomArr.size(); i++){
        CustomArr[i] = rand() % 100; //Random variables from 1-99
    }
    
    //sort the array
    sort(CustomArr.begin(), CustomArr.end());

    cout << "Sorted Array, since binary search only works\n";
    cout << "With Sorted Arrays:";
    for(int i = 0; i < CustomArr.size(); i++){
        cout << "Elem[" << i << "] " << CustomArr[i] << "\n";
    }

    int input = 0;
    do
    {
        cout << "Now that we have a sorted array\n";
        cout << "we can start searching for numbers\n\n";

        cout << "What number would you like to search for\n";
        cout << "Enter a number to search, enter -1 to exit program: ";

        cin >> input;
        if(input != -1){
            int result = RecursiveSearch(CustomArr, 0 ,CustomArr.size() - 1 , input);
            if(result != -1){
                cout << "\nElement found at index " << result << "\n\n";
            }else{
                cout << "Element not found\n";
            }
        }
        
    } while (input != -1);

    cout << "Thanks for testing!";
    
}