#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Sorting
{
public:
    void selectionSort(T arr1[], int n1) {
        for (int i = 0; i < n1 - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < n1; j++) {
                if (arr1[j] < arr1[minIndex]) {
                    minIndex = j;
                }
            }
            swap(arr1[i], arr1[minIndex]);
        }
    }

    void insertionSort(T arr1[], int n1)
    {
        for (int i = 1; i < n1; i++)
        {
            int key = arr1[i];
            int j = i - 1;

            while (j >= 0 && arr1[j] > key)
            {
                arr1[j + 1] = arr1[j];
                j--;
            }

            arr1[j + 1] = key;
        }
    }
};

int main()
{
    int choice;

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Using Integer : \n\ta.SelectionSort\n\tb.InsertionSort \n";
        cout << "2. Using Float : \n\ta.SelectionSort\n\tb.InsertionSort \n";
        cout << "3. Using Char : \n\ta.SelectionSort\n\tb.InsertionSort \n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {   cout<<"a : selectionSort\nb : insertionSort\n";
            char x;
            cin >> x;

            int n1;
            cout<<"Enter the size of array :";
            cin >> n1;
            int arr1[n1];
            for (int i = 0; i < n1; i++)
            {
                cin >> arr1[i];
            }
            Sorting<int> A;
            A.selectionSort(arr1, n1);
            for (int i = 0; i < n1; i++){
                cout << arr1[i] << " ";
            }    
        }
        else if (choice == 2)
        {   
            int n1;
            cout<<"Enter the size of array :";
            cin >> n1;
            float arr1[n1];
            for (int i = 0; i < n1; i++)
            {
                cin >> arr1[i];
            }
            Sorting<float> A;
            A.selectionSort(arr1, n1);
            for (int i = 0; i < n1; i++)
            {
                cout << arr1[i] << " ";
            }
            
        }
        else if (choice == 4)
        {
            cout << "Exiting program." << endl;
        }
        else
        {
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}