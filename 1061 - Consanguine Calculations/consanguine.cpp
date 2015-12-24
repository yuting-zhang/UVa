#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <set>
#include <cstring>
#include <cstdio>

using namespace std;

typedef pair<string, string> ds;

vector<ds> get_type(string p){
	vector<ds> ret;
	if (p == "A+"){
		ret.push_back({"AA", "++"});
		ret.push_back({"AA", "+-"});
		ret.push_back({"AO", "++"});
		ret.push_back({"AO", "+-"});
	}
	else if (p == "A-"){
		ret.push_back({"AA", "--"});
		ret.push_back({"AO", "--"});
	}
	else if (p == "AB+"){
		ret.push_back({"AB", "++"});
		ret.push_back({"AB", "+-"});
	}
	else if (p == "AB-")
		ret.push_back({"AB", "--"});
	else if (p == "B+"){
		ret.push_back({"BB", "++"});
		ret.push_back({"BB", "+-"});
		ret.push_back({"BO", "++"});
		ret.push_back({"BO", "+-"});
	}
	else if (p == "B-"){
		ret.push_back({"BB", "--"});
		ret.push_back({"BO", "--"});
	}
	else if (p == "O+"){
		ret.push_back({"OO", "++"});
		ret.push_back({"OO", "+-"});
	}
	else if (p == "O-")
		ret.push_back({"OO", "--"});
	return ret;
}

string get_child(char t1, char t2, char t3, char t4){
	string ret;
	if (t1 == 'A' && t3 == 'A')
		ret = "A";
	else if (t1 == 'A' && t3 == 'B' || t1 == 'B' && t3 == 'A')
		ret = "AB";
	else if (t1 == 'A' && t3 == 'O' || t1 == 'O' && t3 == 'A')
		ret = "A";
	else if (t1 == 'B' && t3 == 'B')
		ret = "B";
	else if (t1 == 'B' && t3 == 'O' || t1 == 'O' && t3 == 'B')
		ret = "B";
	else if (t1 == 'O' && t3 == 'O')
		ret = "O";
	if (t2 == '-' && t4 == '-')
		ret += "-";
	else
		ret += "+";
	return ret;
}

vector<string> combine(string p1, string p2){
	vector<ds> p1_type = get_type(p1);
	vector<ds> p2_type = get_type(p2);
	set<string> ret;

	for (int i = 0; i < p1_type.size(); i++)
		for (int j = 0; j < p2_type.size(); j++)
			for (int t1 = 0; t1 < 2; t1++)
				for (int t2 = 0; t2 < 2; t2++)
					for (int t3 = 0; t3 < 2; t3++)
						for (int t4 = 0; t4 < 2; t4++)
							ret.insert(get_child(p1_type[i].first[t1], p1_type[i].second[t2],
												 p2_type[j].first[t3], p2_type[j].second[t4]));
	return vector<string>(ret.begin(), ret.end());
}

bool is_child(vector<string> result, string child){
	for (const auto& it: result)
		if (it == child)
			return true;
	return false;
}

string get_print(vector<string> st){
	if (st.size() == 0)
		return "IMPOSSIBLE";
	if (st.size() == 1)
		return st[0];
	string ret = "{";
	ret += st[0];
	for (int i = 1; i < st.size(); i++)
		ret += ", " + st[i];
	ret += "}";
	return ret;
}

void print(int case_no, vector<string> p1, vector<string> p2, vector<string> c){
	string parent1, parent2, child;
	parent1 = get_print(p1);
	parent2 = get_print(p2);
	child = get_print(c);
	printf("Case %d: %s %s %s\n", case_no, parent1.c_str(), parent2.c_str(), child.c_str());
}

int main(){
	string parent1, parent2, child;
	int case_no = 0;
	while (cin >> parent1 >> parent2 >> child){
		string type;
		vector<string> result;
		case_no++;

		if (parent1 == "?"){
			if (is_child(combine("A+", parent2), child))
				result.push_back("A+");
			if (is_child(combine("A-", parent2), child))
				result.push_back("A-");
			if (is_child(combine("B+", parent2), child))
				result.push_back("B+");
			if (is_child(combine("B-", parent2), child))
				result.push_back("B-");
			if (is_child(combine("AB+", parent2), child))
				result.push_back("AB+");
			if (is_child(combine("AB-", parent2), child))
				result.push_back("AB-");
			if (is_child(combine("O+", parent2), child))
				result.push_back("O+");
			if (is_child(combine("O-", parent2), child))
				result.push_back("O-");
			print(case_no, result, {parent2}, {child});
		}
		if (parent2 == "?"){
			if (is_child(combine("A+", parent1), child))
				result.push_back("A+");
			if (is_child(combine("A-", parent1), child))
				result.push_back("A-");
			if (is_child(combine("B+", parent1), child))
				result.push_back("B+");
			if (is_child(combine("B-", parent1), child))
				result.push_back("B-");
			if (is_child(combine("AB+", parent1), child))
				result.push_back("AB+");
			if (is_child(combine("AB-", parent1), child))
				result.push_back("AB-");
			if (is_child(combine("O+", parent1), child))
				result.push_back("O+");
			if (is_child(combine("O-", parent1), child))
				result.push_back("O-");
			print(case_no, {parent1}, result, {child});
		}
		if (child == "?")
			print(case_no, {parent1}, {parent2}, combine(parent1, parent2));
	}
	return 0;
}
