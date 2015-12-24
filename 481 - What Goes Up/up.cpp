#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int bi_search(const vector<int>& tail_table, int left, int right, int target){
    while (left < right)    {
        int middle = (left + right) / 2;
        if (tail_table[middle] == target)
            return middle;
        if (tail_table[middle] > target)
            right = middle;
        else
            left = middle + 1;
    }
    return left;
}

int main(){
    //ifstream fin("up.in");
    istream& in(cin);

    vector<int> seq;
    vector<int> tail_table;
    int value;
    while (in >> value)
        seq.push_back(value);

    vector<int> max_length(seq);
    tail_table.push_back(seq[0]);
    max_length[0] = 1;
    for (int i = 1; i < seq.size(); ++i)    {
        if (seq[i] < tail_table[0]){
            tail_table[0] = seq[i];
            max_length[i] = 1;
        }
        else if (seq[i] > tail_table.back()){
            tail_table.push_back(seq[i]);
            max_length[i] = tail_table.size();
        }
        else{
            int pos = bi_search(tail_table, 0, tail_table.size(), seq[i]);
            tail_table[pos] = seq[i];
            max_length[i] = pos + 1;
        }


    }
    cout << tail_table.size() << "\n";

    // reconstruct
    cout << "-\n";
    int curr_length = tail_table.size();
    int next_number = tail_table.back();

    vector<int> result;
    for (int i = seq.size() - 1; i >= 0; --i){
        if (max_length[i] == curr_length)
            if (curr_length == tail_table.size() || seq[i] < next_number){
                result.push_back(seq[i]);
                --curr_length;
                next_number = seq[i];
                if (curr_length == 0)
                    break;
            }
    }

    for (int i = result.size() - 1; i >= 0; --i)
        cout << result[i] << "\n";
    return 0;
}
