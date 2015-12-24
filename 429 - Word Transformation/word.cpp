#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <set>
#include <queue>

using namespace std;

struct stage_type
{
	// constructor is just for fun
	stage_type(const string& n_word, int n_step)
	{
		word = n_word;
		step = n_step;
	}

	string word;
	int step = 0;
};

int transformation(string begin, string end, const vector<string>& old_dic)
{
	// special case test
	if (begin == end)
		return 0;
	vector<string> dic;

	// we only want words with the same length
	for (const auto& it : old_dic)
		if (it.length() == begin.length())
			dic.push_back(it);

	// queue for BFS
	queue<stage_type> word_queue;

	// set to store used words
	set<string> used;

	// initiate
	word_queue.push(stage_type(begin, 0));
	used.insert(begin);

	while (true)
	{
		// get the front value from queue and pop the queue
		stage_type stage = word_queue.front();
		word_queue.pop();

		// iterate through every word in the dictionary
		for (auto const& it : dic)
		{
			// if the word has already been processed, skip it
			if (used.find(it) == used.end())
			{
				// we only want words which differ with the current word
				// in processing by only one letter
				int cnt = 0;
				for (size_t i = 0; i != it.length(); ++i)
					if (stage.word[i] != it[i])
					{
						++cnt;
						if (cnt >= 2)
							break;
					}

				// this word is qualified
				if (cnt == 1)
				{
					// fount it
					if (it == end)
						return stage.step + 1;

					// add this new word to queue
					word_queue.push(stage_type(it, stage.step + 1));
					used.insert(it);
				}
			}
		}
	}
}

int main()
{
	int N;
	cin >> N;
	string line;

	// skip the empty line
	getline(cin, line);

	for (int i = 0; i < N; ++i)
	{
		// print new line between test sets
		if (i != 0)
			cout << "\n";

		// get the dictionary
		vector<string> dic;
		while (getline(cin, line) && line != "*")
			dic.push_back(line);

		// get begin and end words
		while (getline(cin, line) && !line.empty())
		{
			// doing some little string manipulation to seperate the two words
			string begin, end;
			size_t space = line.find(' ');
			begin = line.substr(0, space);
			end = line.substr(space + 1);

			// do the work
			cout << begin << " " << end << " " << transformation(begin, end, dic) << "\n";
		}
	}
	return 0;
}
