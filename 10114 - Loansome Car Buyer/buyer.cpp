#include <iostream>
#include <vector>

using namespace std;

int main(){
    int loan_duration, records;
    double down_payment, loan_total;
    while (scanf("%d %lf %lf %d", &loan_duration, &down_payment, &loan_total, &records) == 4 && loan_duration >= 0){
        vector<double> depreciation(loan_duration + 1, -1);
        for (int i = 0; i < records; ++i){
            int month;
            scanf("%d", &month);
            if (month > loan_duration)
                continue;
            scanf("%lf",&depreciation[month]);
        }

        for (int i = 0; i <= loan_duration; ++i)
            if (depreciation[i] == -1)
                depreciation[i] = depreciation[i - 1];

        int month = 0;
        double value = (down_payment + loan_total) * (1.0 - depreciation[0]), pay_month = loan_total / loan_duration;

        while (value <= loan_total){
            ++month;
            value *= (1.0 - depreciation[month]);
            loan_total -= pay_month;
        }

        printf("%d month", month);
        if (month >= 2 || month == 0)
            printf("s\n");
        else
            printf("\n");
    }

    return 0;
}
