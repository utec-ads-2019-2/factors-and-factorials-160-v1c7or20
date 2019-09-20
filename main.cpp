#include<iostream>
#include <map>
#include <iomanip>

using namespace std;

int main(){
    map<int, int> * primos;
    int nprimos[25] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
    double x;
    while (cin>>x and x!=0){
        primos = new map<int, int>();
        for (int i = 2; i <= x ; i++) {
            int val = i;
            for (int j = 0; j < 25 ; ++j) {
                if (val%nprimos[j] == 0){
                    (*primos)[nprimos[j]]++;
                    val= val/nprimos[j];
                    j--;
                }else{
                    if (nprimos[j]>x){
                        j = 25;
                    }
                }
            }
        }
        cout << setw(3)<<x<<"! = ";
        int n = 0;
        for (auto k = primos->begin(); k != primos->end() ; k++) {

            if (n!=15){
                if (k->second>=10){
                    cout<<setw(0)<<(k->second)<<" ";
                }else{
                    cout<<setw(2)<<(k->second)<<" ";
                }
            } else{
                cout<<endl<<"       "<<setw(2)<<(k->second)<<" ";
                n=0;
            }
            n++;

        }cout<<endl;
        primos->clear();
    }
}

