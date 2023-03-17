#include <iostream>
#include <vector>
#include <unordered_map>
#include <map> // ordered map
#include <set> // ordered set
using namespace std;

// you will rarely use ordered
// map can do everything set can, but set can't do everything that map can (freq)

// unordered map

void unordered()
{
	unordered_map<string, int> mp;
	// inserting methods
	mp.insert(make_pair("Samit", 19));
	mp["Mohan"] = 20;
	mp.insert({"Sam", 18});
	mp["Mohan"] = 23; // will over ride 20

	// remove
	mp.erase("Samit");

	// find till end (mp.find("Samit") == mp.end())
	string key = "Samit";
	if (mp.find(key) == mp.end())
	{
		cout << key << " is not found" << endl;
	}
	else
	{
		cout << key << " is found" << endl;
	}

	// // print
	// for (auto x : mp)
	// {
	// 	cout << x.first << " " << x.second << endl;
	// }

	vector<int> arr = {65, 76, 56, 65, 81, 76, 65};
	// frequency
	unordered_map<int, int> mp2;
	for (auto x : arr)
	{
		// count++
		// 65 -> 1
		// 76 -> 1
		// 56 -> 1
		// 65 -> 2
		// 81 -> 1
		// 76 -> 2
		// 65 -> 3
		mp2[x]++;
	}

	// print
	for (auto x : mp2)
	{
		cout << x.first << " " << x.second << endl;
	}
}

// ordered map (follows BST -> logN)

ordered()
{
	map<string, int> om;
	om.insert(make_pair("Samit", 19));
	om["Samit"] = 20;
	om.insert({"Samit", 18});
	om["Mohan"] = 23;
	om["Mohan"] = 100; // over ride

	// find
	string key = "Samit";
	for (auto x : om)
	{
		cout << x.first << " " << x.second << endl;
	}
}

// set

set()
{
	set<int> s;
	s.insert(87);
	s.insert(98);
	s.insert(77);
	s.insert(87);
	s.insert(100);

	for (auto x : s)
	{
		cout << x << endl;
	}
}

int main()
{
	// unordered()
	// ordered();
	// set();

	return 0;
}
