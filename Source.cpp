#include "Menu.h"
//#include "Class_base.h"
//#include "Class_Knight.h"
//#include "Class_Witch.h"
//#include <vector>
//void a(Class_base* p) { p->addSkill(); };
//void b(Class_base* p) { p->showSkill(); };

void printDistinctValues(int arr[], int n) {
    for (int i = 0; i < n; i++) 
    {
        int j;
        for (j = 0; j < i; j++)
        if (arr[i] == arr[j])
                break;
        if (i == j)
            std::cout << arr[i] << "  ";
    }
}
//how about add shop
int main()
{

	
	Menu set;
	set.Start();

 /*       int arr[] = { 1, 5, 7, 12, 1, 6, 10, 7, 5 };
        int n = sizeof(arr) / sizeof(arr[0]);
        std::cout << "Distinct values of the array are :\n";
        printDistinctValues(arr, n);
        return 0;*/
}

