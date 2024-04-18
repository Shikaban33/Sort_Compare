#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <time.h>

using namespace std;

long length = 50;
const long max_length = 200000;

int list[max_length];

void read()
{
    ifstream fin("random_sort_maz5.dat", ios::binary);//write down file names here to test different sequences of numbers
    for (long i = 0; i < length; i++)
    {
        fin.read((char*)&list[i], sizeof(int));
    }
    fin.close();
}
void bubbleSort()
{
    int temp;
    for (long i = 0; i < length; i++)
    {
        for (long j = 0; j < length - i - 1; j++)
        {
            if (list[j] > list[j + 1])
            {
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}
void insertionSort()
{
    int temp;
    for (long i = 1; i < length; i++)
    {
        temp = list[i];
        long j;
        for (j = i - 1; j >= 0; j--)
        {
            if (list[j] > temp)
            {
            list[j + 1] = list[j];
            }
        }
        list[j + 1] = temp;
    }
}
int main()
{
    double t1, t2;
    for (length = 50; length <= max_length; )
    {
        cout << "\nLength\t: " << length << '\n';
        read();
        t1 = clock();
        bubbleSort();
        t2 = clock();
        cout << "Bubble Sort\t: " << (t2 - t1) / CLOCKS_PER_SEC << " sec\n";
        read();
        t1 = clock();
        insertionSort();
        t2 = clock();
        cout << "Insertion Sort\t: " << (t2 - t1) / CLOCKS_PER_SEC << " sec\n";
        switch (length)
        {
        case 50:
            length = 100;
            break;
        case 100:
            length = 200;
            break;
        case 200:
            length = 400;
            break;
        case 400:
            length = 25000;
            break;
        case 25000:
            length = 50000;
            break;
        case 50000:
            length = 100000;
            break;
        case 100000:
            length = 200000;
            break;
        case 200000:
            length = 300000;
            break;
        }
    }
    return 0;
}