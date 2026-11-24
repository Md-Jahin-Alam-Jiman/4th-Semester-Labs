#include<iostream>
#include <fstream>
#include <ctime>
#include <vector>
using namespace std;

int selectionSort(vector<int>arr) {
    int count = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            count++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
    return count;
}

int main(){

    ofstream file("selection_sort.csv");
    file << "InputSize,Count\n";

    srand(time(0));

    for (int n=100; n<=5000;n+=100){
        vector<int> arr(n);
        for (int i=0;i<arr.size();i++){
            arr[i]=rand();
        }
        int count = selectionSort(arr);
        file << n << "," << count << "\n";
        cout << "n = " << n
             << "  Count = " << count << endl;
    }
    file.close();

}