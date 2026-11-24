#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Insertion Sort
int insertionSort(vector<int> arr)
{
    int count = 0;

    for (long long i = 1; i < arr.size(); i++)
    {
        int key = arr[i];
        int  j = i - 1;

        while (j >= 0)
        {
            count++;

            if (arr[j] <= key)
                break;

            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }

    return count;
}

int main()
{
    // Create CSV file
    ofstream file("insertion_sort.csv");

    file << "InputSize,Count\n";

    // Seed the rand function
    srand(time(0));

    // Test different input sizes
    for (int n = 100; n <= 5000; n += 100)
    {
        vector<int> arr(n);

        // Generate random numbers
        for (int i = 0; i < arr.size(); i++)
        {
            arr[i] = rand();
        }

        // Run insertion sort
        int count = insertionSort(arr);

        // Save result to CSV
        file << n << "," << count << "\n";

        // Display result
        cout << "n = " << n
             << "  Count = " << count << endl;
    }

    // Close file
    file.close();

    cout << "\nData saved to insertion_sort.csv\n";

    return 0;
}