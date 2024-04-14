#include<iostream>
#include<cstring>
using namespace std;

class dictionary{
	private:
		typedef struct obj{
			long key;
			char clnt_name[10];
		} obj;
		obj h[10];
		
		public:
			dictionary();
			void add_record();
			void show();
			int search(long);
			void delete_record(long);
};

dictionary::dictionary(){
	   for (int i = 0; i < 10; i++) {
		h[i].key = -1;
		strcpy(h[i].clnt_name, "NULL");
	}
}

void dictionary::delete_record(long k){
	int index = search(k);
	if (index == -1){
		cout <<"\n\tkey not found";
		
	}else {
		h[index].key = -1;
		strcpy(h[index].clnt_name,"NULL");
		cout << "\n key is deleted";
	  }
}

void dictionary::show(){
	cout <<"\n\t\tkey\t\tclnt_name";
	for(int i = 0; i < 10; i++){
	
	cout << "\n\th[" << i << "]\t" << h[i].key << "\t\t" << h[i].clnt_name;
}
}

int dictionary::search(long k){
	for (int i = 0; i < 10; i++){
		if (h[i].key == k){
			 cout << "\n\t" << h[i].key << " is Found at " << i << " Location With Client " << h[i].clnt_name;
            return i;
		}
	}
	return -1;
	
}

void dictionary::add_record(){
	char ans, n[10];
	long k;
	int hi, cnt = 0;
	
	 do {
        if (cnt >= 10) {
            cout << "\n\tHash Table is FULL";
            break;
        }
        cout << "\n\tEnter a Telephone No: ";
        cin >> k;
        cout << "\n\tEnter a Client name: ";
        cin >> n;
        hi = k % 10; // hash function
        if (h[hi].key == -1) {
            h[hi].key = k;
            strcpy(h[hi].clnt_name, n);
        } else {
            cout << "\n\tCollision Detected, Key " << k << " at Index " << hi << endl;
        }
        cnt++;
        cout << "\n\t... Do You Want to Insert More Key: y/n ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');
}

int main() {
    long k;
    int ch, index;
    char ans;
    dictionary obj;

    do {
        cout << "\n\tTelephone (ADT)  ";
        cout << "\n\t1. Insert\n\t2. Display\n\t3. Find\n\t4. Delete\n\t5. Exit";
        cout << "\n\t-----Select Your Choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                obj.add_record();
                break;
            case 2:
                obj.show();
                break;
            case 3:
                cout << "\n\tEnter Key to Search: ";
                cin >> k;
                index = obj.search(k);
                if (index == -1) {
                    cout << "\n\tKey Not Found";
                }
                break;
            case 4:
                cout << "\n\tEnter Key to Delete: ";
                cin >> k;
                obj.delete_record(k);
                break;
            case 5:
                return 0; // Exit the program
            default:
                cout << "\n\tInvalid Choice";
        }

        cout << "\n\t... Do You Want to Continue in Main Menu: y/n ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');

    return 0;
}


