#include <iostream>

using namespace std;

int COMPCOUNT = 0;

bool SMALLER(int *array, int i, int j) {
    if (array[i] < array[j]) {
        COMPCOUNT++;
        return 1;
    }
    
    COMPCOUNT++;
    return 0;    
}

void display(int *array, int size) {
   for(int i = 0; i<size; i++)
      cout << array[i] << " ";
   cout << endl;
}

void insertionSort(int *array, int size) {
   int key, j;
   for(int i = 1; i<size; i++) {
      key = array[i];//take value
      j = i;
      while(j > 0 && array[j-1]>key) {
         SMALLER(array, i, j);
         array[j] = array[j-1];
         j--;         
      }
      //SMALLER(array, i, j);
      array[j] = key;   //insert in right place
   }
}

int main() { 
   int worstArray[] = {32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,
   15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
   
   int bestArray[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,
   21,22,23,24,25,26,27,28,29,30,31,32}; 
   
   int randArray32[31] = {};
   int randArray100[99] = {};
   int randArray1000[999] = {};
   int randArray10000[9999] = {};
   
   for(int i = 0; i < sizeof(randArray32)/sizeof(randArray32[0]); i++) {
        randArray32[i] = rand() % sizeof(randArray32)/sizeof(randArray32[0]);
   }
   
   for(int i = 0; i < sizeof(randArray100)/sizeof(randArray100[0]); i++) {
        randArray100[i] = rand() % sizeof(randArray100)/sizeof(randArray100[0]);
   }
   
   for(int i = 0; i < sizeof(randArray1000)/sizeof(randArray1000[0]); i++) {
        randArray1000[i] = rand() % sizeof(randArray1000)/sizeof(randArray1000[0]);
   }
   
   for(int i = 0; i < sizeof(randArray10000)/sizeof(randArray10000[0]); i++) {
        randArray10000[i] = rand() % sizeof(randArray10000)/sizeof(randArray10000[0]);
   }
    
   cout << "Worst case array size 32 before Sorting: ";
   display(worstArray, sizeof(worstArray)/sizeof(worstArray[0]));
   insertionSort(worstArray, sizeof(worstArray)/sizeof(worstArray[0]));
   cout << "Worst case array after Sorting: ";
   display(worstArray, sizeof(worstArray)/sizeof(worstArray[0]));
   cout << "Worst case array COMPCOUNT = " << COMPCOUNT << "\n\n";
   COMPCOUNT = 0;
   
   cout << "Best case array size 32 before Sorting: ";
   display(bestArray, sizeof(bestArray)/sizeof(bestArray[0]));
   insertionSort(bestArray, sizeof(bestArray)/sizeof(bestArray[0]));
   cout << "Best case array after Sorting: ";
   display(bestArray, sizeof(bestArray)/sizeof(bestArray[0]));
   cout << "Best case array COMPCOUNT = " << COMPCOUNT << "\n\n";
   COMPCOUNT = 0;
   
   cout << "Random array size 32 before Sorting: ";
   display(randArray32, sizeof(randArray32)/sizeof(randArray32[0]));
   insertionSort(randArray32, sizeof(randArray32)/sizeof(randArray32[0]));
   cout << "Random array size 32 after Sorting: ";
   display(randArray32, sizeof(randArray32)/sizeof(randArray32[0]));
   cout << "Random array size 32 COMPCOUNT = " << COMPCOUNT << "\n\n";
   COMPCOUNT = 0;
   
   cout << "Random array size 100 before Sorting: ";
   display(randArray100, sizeof(randArray100)/sizeof(randArray100[0]));
   insertionSort(randArray100, sizeof(randArray100)/sizeof(randArray100[0]));
   cout << "Random array size 100 after Sorting: ";
   display(randArray100, sizeof(randArray100)/sizeof(randArray100[0]));
   cout << "Random array size 100 COMPCOUNT = " << COMPCOUNT << "\n\n";
   COMPCOUNT = 0;
   
   cout << "Random array size 1000 before Sorting: ";
   display(randArray1000, sizeof(randArray1000)/sizeof(randArray1000[0]));
   insertionSort(randArray1000, sizeof(randArray1000)/sizeof(randArray1000[0]));
   cout << "Random array size 1000 after Sorting: ";
   display(randArray1000, sizeof(randArray1000)/sizeof(randArray1000));
   cout << "Random array size 1000 COMPCOUNT = " << COMPCOUNT << "\n\n";
   COMPCOUNT = 0;
   
      cout << "Random array size 10000 before Sorting: ";
   display(randArray10000, sizeof(randArray10000)/sizeof(randArray10000[0]));
   insertionSort(randArray10000, sizeof(randArray10000)/sizeof(randArray10000[0]));
   cout << "Random array size 10000 after Sorting: ";
   display(randArray10000, sizeof(randArray10000)/sizeof(randArray10000[0]));
   cout << "Random array size 10000 COMPCOUNT = " << COMPCOUNT << endl;
   COMPCOUNT = 0;
}