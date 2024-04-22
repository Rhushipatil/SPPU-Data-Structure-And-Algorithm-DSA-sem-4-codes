
#include <iostream>
#include <iomanip>
using namespace std;
const int MAX = 30;
class FlightClass
{
    FlightClass *link;
    string city_name;
    int duration;

public:
    friend class graph_class;
    FlightClass()
    {
        link = NULL;
        city_name = " ";
        duration = -1;
    }
    FlightClass(string city_name, int weight)
    {
        link = NULL;
        this->city_name = city_name;
        duration = weight;
    }
};
class graph_class
{
    FlightClass *head[MAX];
    int n;

public:
    graph_class(int num)
    {
        n = num;
        for (int i = 0; i < n; i++)
            head[i] = NULL;
    }
    void insert(string first_city, string second_city, int time);
    void readdata();
    int getindex(string s1);
    void display();
};
int graph_class::getindex(string s1)
{
    for (int i = 0; i < n; i++)
    {
        if (head[i]->city_name == s1)
            return i;
    }
    return -1;
}
void graph_class::insert(string first_city, string second_city, int time)
{
    FlightClass *from;
    FlightClass *to = new FlightClass(second_city, time);
    int ind = getindex(first_city);
    from = head[ind];
    while (from->link != NULL)
        from = from->link;
    from->link = to;
}
void graph_class::display()
{
    FlightClass *from;
    for (int i = 0; i < n; i++)
    {
        from = head[i];
        while (from != NULL)
        {
            cout << from->city_name << "->";
            from = from->link;
        }
        cout << "NULL" << endl;
    }
}
void graph_class::readdata()
{
    string first_city, second_city, tmpcity;
    int flight, fcost;
    cout << "\nEnter Details of City:\n";
    for (int i = 0; i < n; i++)
    {
        head[i] = new FlightClass;
        cout << "\nEnter name of city " << i + 1 << ":";
        cin >> head[i]->city_name;
    }
    cout << "\nEnter Number of Flights : ";
    cin >> flight;
    for (int i = 0; i < flight; i++)
    {
        cout << "\nEnter Source :";
        cin >> first_city;
        cout << "\nEnter Destination :";
        cin >> second_city;
        cout << "\nEnter Time :";
        cin >> fcost,
            insert(first_city, second_city, fcost);
    }
}
int main()
{
    int number, choice;
    cout << "\nEnter Number of Airport Stations : ";
    cin >> number;
    graph_class gl(number);
    do
    {
        cout << "\n****Menu*****\nl.Insert Flight detail\n2.Display\n3.Exit\nSelect your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            gl.readdata();
            break;
        case 2:
            cout << "\n*Adjacency List*" << endl;
            gl.display();
            break;
        default:
            cout << "\nInvalid Choice";
        }
    } while (choice != 3);
    return 0;
}

