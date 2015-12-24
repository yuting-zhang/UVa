#include <iostream>
#include <string>

using namespace std;

int main(){
    int L;
    while (scanf("%d", &L) == 1, L){
        string direction = "+x";
        for (int i = 0; i < L - 1; ++i){
            string bend;
            cin >> bend;
            if (bend == "No")
                continue;
            if (direction == "+x")
                direction = bend;
            else if (direction == "-x"){
                if (bend == "+y")
                    direction = "-y";
                else if (bend == "-y")
                    direction = "+y";
                else if (bend == "+z")
                    direction = "-z";
                else
                    direction = "+z";
            }
            else if (direction == "+y"){
                if (bend == "+y")
                    direction = "-x";
                else if (bend == "-y")
                    direction = "+x";
            }
            else if (direction == "-y"){
                if (bend == "+y")
                    direction = "+x";
                else if (bend == "-y")
                    direction = "-x";
            }
            else if (direction == "+z"){
                if (bend == "+z")
                    direction = "-x";
                else if (bend == "-z")
                    direction = "+x";
            }
            else if (direction == "-z"){
                if (bend == "+z")
                    direction = "+x";
                else if (bend == "-z")
                    direction = "-x";
            }
        }
        cout << direction << "\n";
    }
    return 0;
}
