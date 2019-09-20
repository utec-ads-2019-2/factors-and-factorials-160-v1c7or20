#include<iostream>
#include <map>
#include <iomanip>

using namespace std;

int main(){
    map<int, int> * primos;
    int nprimos[25] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
    double x;
    while (cin>>x ){
        if (x == 0)break;
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
        int n = 0;
        cout << setw(3) << x << "! =";
        for (auto i = primos->begin(); i != primos->end(); i++) {
            if (n % 15==0 and n>0) cout << endl << "      ";
            cout << setw(3) << i->second;
            n++;
        }
        cout << endl;
        primos->clear();
    }
}

