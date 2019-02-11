// tempProj.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "HashLinearProb.h"
#include "LinkedHashing.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <string>
#include <stack> 

using namespace std;

void climbingLeaderboard() {
	vector<int> scores = { 295, 294, 291, 287, 287, 285, 285, 284, 283, 279, 277, 274, 274, 271, 270, 268 };
	vector<int> alice = { 269, 271, 271, 275, 276, 281, 282, 283, 284, 285, 287, 289, 289, 295, 296 };
	vector <int> rank(alice.size(), 0);
	int rk, j, index = alice.size() - 1, scores_size = scores.size() - 1;
	rk = 1;
	j = 0;
	for (; index >= 0; index--) {
		if (alice[index] >= scores[0]) {
			rank[index] = rk;
			continue;
		}

		for (; j < scores.size(); j++) {
			if (!j && (alice[index] < scores[j]))
				rk++;
			if (j && (scores.at(j) != scores.at(j - 1)) && (alice[index] < scores[j]))
				rk++;
			if (alice[index] >= scores[j]) {
				break;
			}
		}
		if (j == scores.size()) {
			for (; index >= 0; index--)
				rank[index] = rk;
		}
		else
			rank[index] = rk;
	}
	for(auto it:rank) {
		cout << it << " ";
	}
}

int minimumSwaps(vector<int> arr) {
	int swaps = 0;
	unsigned int i, j;

	for (i = 0; i < arr.size(); i++) {
		if (arr.at(i) == i + 1) {
			continue;
		}
		else {
			for (j = i + 1; j < arr.size(); j++) {
				if (arr.at(j) == i + 1) {
					arr.at(j) = arr.at(i);
					arr.at(i) = i + 1;
					swaps++;
					break;
				}
			}
		}
	}
	return swaps;
}

long substrCount(int n, string s) {
	long substr_count = 1, temp1 = 1, temp2;
	bool other_side = false;

	for (int i = 1; i < n; i++) {
		if (s[i - 1] == s[i]) {
			temp1++;
			substr_count += temp1;
		}

		if (s[i - 1] != s[i]) {
			substr_count++;
			if (other_side) {
				substr_count++;
				if (i + 1 < n && s[i] != s[i + 1])
					other_side = false;
			}
			if (i - 1 >= 0 && i + 1 < n && s[i - 1] == s[i + 1]) {
				other_side = true;
			}
			temp1 = 1;
		}
	}
	return substr_count;
}

void minimumBribes(vector<int> q) {
	int bribes = 0;
	int t1;
	bool flag_chaotic = false;
	for (int i = 0; i < q.size(); i++) {
		if (((q.at(i) - i - 1) <= 0)/*||((q.at(i) - i - 1) == -1)||((q.at(i) - i - 1) == -2)*/) {}

		else if ((q.at(i) - i - 1) == 1) {
			bribes++;
		}

		else if ((q.at(i) - i - 1) == 2) {
			bribes += 2;
			if ((q[i + 1] - i - 2) == 0) {
				bribes++; i++;
			}
		}

		else {
			flag_chaotic = true;
			break;
		}
	}

	if (flag_chaotic)
		cout << "Too chaotic" << endl;
	else
		cout << bribes << endl;
}

int main()
{
    cout << "Hello World!\n"; 
	//climbingLeaderboard();
	//initializes a string from a vector<char>
	vector<int> v_int1 = { 6, 9, 1, 2, 8, 3, 7, 4, 5 };
//	cout << minimumSwaps(v_int1) << endl;
//	cout << "swipe ends" << endl;
//	cout <<"\nsunbstring count" << substrCount(5, "asasd") <<endl;
//	vector<char> v_str = { 'a', 'b', 'c', 'd' };
//	vector<int> v_int = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 4, 5 };
	int result = 0;
//	result = count(v_int.begin(), v_int.end(), 1);
//	cout << result << endl;
	// Empty stack 
/*	stack<string> mystack;
	mystack.push("Hello");
	mystack.push("Hi");

	cout << mystack.top() << endl;
	string temp = mystack.top();
	string temp1 = mystack.pop();

	cout << temp << endl;
*/
//	list <string> l_str = {"qw", "as", "zx", "qw"};
//	result = count(l_str.begin(), l_str.end(), "qw");
//	cout << result << endl;

/*	HashMap *linear_hash_table = new HashMap();
	for (size_t i = 0; i < 10; i++)
		linear_hash_table->put(1, 10);
	//for (size_t i = 0; i < 10; i++)
	//	linear_hash_table->put(i, i * 100);
	cout << endl;
	for (size_t i = 0; i < 10; i++)
		cout << "key: " << i << "--> value: " << linear_hash_table->get(i) <<endl;
*/
	LinkedHashMap *linked_hash_table = new LinkedHashMap();
	for (size_t i = 0; i < 10; i++)
	{
		linked_hash_table->put(i, i * 10);
		linked_hash_table->put(i, i * 100);
	}
	cout << endl;
	for (size_t i = 0; i < 10; i++)
	{
		cout << "Key: " << i << "--> Value: " << linked_hash_table->get(i) << endl;
	}


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
