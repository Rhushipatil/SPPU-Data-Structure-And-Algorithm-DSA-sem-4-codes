#include <iostream>
using namespace std;
class student
{
    int first_heap[20], second_heap[20], x, n1, i;

public:
    student()
    {
        first_heap[0] = 0, second_heap[0] = 0;
    }
    void getdata();
    void insert1(int first_heap[], int);
    void upadjust1(int first_heap[], int);
    void insert2(int second_heap[], int);
    void upadjust2(int second_heap[], int);
    void minmax();
};
void student::getdata()
{
    cout << "\nEnter the no. of students: ";
    cin >> n1;
    cout << "\nEnter the marks: ";
    for (i = 0; i < n1; i++)
    {
        cin >> x;
        insert1(first_heap, x);
        insert2(second_heap, x);
    }
}
void student::insert1(int first_heap[20], int x)
{
    int n;
    n = first_heap[0];
    first_heap[n + 1] = x;
    first_heap[0] = n + 1;
    upadjust1(first_heap, n + 1);
}
void student::upadjust1(int first_heap[20], int i)
{
    int temp;
    while (i > 1 && first_heap[i] > first_heap[i / 2])
    {
        temp = first_heap[i];
        first_heap[i] = first_heap[i / 2];
        first_heap[i / 2] = temp;
        i = i / 2;
    }
}
void student::insert2(int second_heap[20], int x)
{
    int n;
    n = second_heap[0];
    second_heap[n + 1] = x;
    second_heap[0] = n + 1;
    upadjust2(second_heap, n + 1);
}
void student::upadjust2(int second_heap[20], int i)
{
    int temp1;
    while (i > 1 && second_heap[i] < second_heap[i / 2])
    {
        temp1 = second_heap[i];
        second_heap[i] = second_heap[i / 2];
        second_heap[i / 2] = temp1;
        i = i / 2;
    }
}
void student::minmax()
{
    cout << "\n Maximum Marks :" << first_heap[1];
    cout << "\nFirst Heap:";
    for (i = 0; i <= n1; i++)
    {
        cout << "\n"
             << first_heap[i];
    }
    cout << "\n Minimum Marks:" << second_heap[1];
    for (i = 0; i <= n1; i++)
    {
        cout << "\n"
             << second_heap[i];
    }
}
int main()
{
    student h;
    h.getdata();
    h.minmax();
    return 0;
}
