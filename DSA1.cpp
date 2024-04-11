#include<iostream>
using namespace std;
struct RP{
	int value;
	RP *link;
} *HT[10];

class Telephone
{
	public:
		Telephone()
		{
			for(int i = 0; i < 10; i++)
			{
				HT[i] = NULL;
			}
		}
		int Fn_hash(int value)
		{
			return (value % 10);
		}
		RP *create_RP(int x)
		{
			RP *temp = new RP;
			temp->link = NULL;
			temp->value = x;
			return temp;
		}
		void print()
		{
			for (int i = 0; i < 10; i++)
			{
				RP *temp = new RP;
				temp = HT[i];
				cout<<"a[" << i << "]:";
				while (temp != NULL)
				{
					cout<< "->" <<temp->value;
					temp = temp->link;
				}
				cout<<"endl";
			}
			
		}
		int searchdata(int value)
		{
			bool flag = false;
			int hash_val = Fn_hash(value);
			RP *entry = HT[hash_val];
			while (entry !=NULL)
			{
				if(entry->value == value)
				{
					cout << "\nelement not found";
					cout << hash_val <<":" <<entry->value<<endl;
					flag = true;
				}
				entry = entry->link;
			}
			if (!flag)
			return -1;
		}
		void deleteElement(int value)
		{
			int hash_val = Fn_hash(value);
			RP *entry = HT[hash_val];
			if(entry == NULL)
			{
				cout <<"element not found";
				return;
			}
			if ( entry->value == value)
			{
				HT[hash_val] = entry-> link;
				return;
			}
			while ((entry->link)->value != value)
			{
				entry = entry->link;
			}
			entry->link = (entry->link)->link;
		}
		void insertElement(int value)
		{
			int hash_val = Fn_hash(value);
			RP *temp = new RP;
			RP *head = new RP;
			head = create_RP(value);
			temp = HT[hash_val];
			if(temp == NULL)
			{
				HT[hash_val] = head;
			}
			else
			{
				while (temp->link !=NULL)
			{
				temp = temp->link;
			}
			
		
			{
				temp->link = head;
			
			}
}
		}	
		
};
int main(){
	 int ch = 1, data, search, del;
    Telephone h;
    while (ch < 5 && ch != 0)
    {
        cout << "\nTelephone :\n1.Insert\n2.Display\n3.Search\n4.Delete\n5.Exit";
        cout << "\nSelect your choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "\nEnter phone number to be inserted:";
            cin >> data;
            h.insertElement(data);
            break;
        case 2:
            h.print();
            break;
        case 3:
            cout << "\nEnter number to be searched :";
            cin >> search;
            if (h.searchdata(search) == -1)
            {
                cout << "\nNo element found at key ";
                continue;
            }
            break;
        case 4:
            cout << "\nEnter number to be deleted :";
            cin >> del;
            h.deleteElement(del);
            cout << "\nContact deleted ";
            break;
        }
    }
    return 0;
}


    
