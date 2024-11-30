
#include<iostream>
#include<string>

using namespace std;

int main() {
    string name;
    
    cout << "Enter your name: ";
    cin >> name;
    int size=name.length();
    
    for(int i=0; i<size-1; i++){
        for(int j=0;j<size-i-1;j++){
             if(name[j] > name[j+1] ){
            char temp=name[j];
            name[j]=name[j+1];
            name[j+1]=temp;

        }
       
        }
    }
    cout << "Expected Output : " << name <<endl;
    return 0;
}