#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cfloat>

using namespace std;

int main(){
    int n, p, case_no = 0;
    while (scanf("%d %d", &n, &p) == 2 && (n + p) != 0){
        if (case_no)
            printf("\n");
        case_no++;
        string accepted;
        double min_cost = DBL_MAX;
        int max_met = 0;
        string line;
        getline(cin, line);
        for (int i = 0; i < n; ++i)
            getline(cin, line);
        for (int i = 0; i < p; ++i){
            string name;
            getline(cin, name);
            double d;
            int r;
            scanf("%lf %d", &d, &r);
            getline(cin, line);
            for (int j = 0; j < r; ++j)
                getline(cin, line);
            if (r > max_met || r == max_met && min_cost > d){
                accepted = name;
                min_cost = d;
                max_met = r;
            }
        }
        printf("RFP #%d\n", case_no);
        cout << accepted << "\n";
    }
    return 0;
}
