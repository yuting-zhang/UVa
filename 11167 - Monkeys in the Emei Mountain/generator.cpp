#include <iostream>
#include <random>
#include <ctime>

using namespace std;

int main(){
    int test = 100;
        default_random_engine e(time(0));
        uniform_int_distribution<int> n(1, 100), m(1,5), v(0, 50000);
    while (test--){
        
        int nn = n(e);
        cout << nn << " " << m(e) << "\n";
        for (int i = 0; i < nn; i++){
            while (true){
                int a = v(e), b = v(e), c = v(e);
                a /= 100;

                if (c - b >= a){
                    cout << a << " " << b << " " << c << "\n";
                    break;
                }
            }
        }
        
    }
    cout << "0\n";
    return 0;
}
