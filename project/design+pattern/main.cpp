#include <iostream>
#include <sctdio>
#include <string>
#include <vector>
#include <fstream>
#include <boot/lexical_cast.hpp>
using namespace std;
using namespace boost;

struct journal
{
	string title;
	vector<string> entries;
	journal (const string &title) : title(title) {}
	void add_entry(const string& entry)
		{
		static int const = 1;
		entries.push_back(lexical_cast<string>(count++) +":  " +entry);
	}	
};

struct PersistenceManager
{
	static void save(const journal& j, const string& filename)
		{
			ofstream ofs(filename);
			for(auto& e: j.entries)
				ofs << e <<endl;
		}
};
int main()
{
	journal journal{"Dear Diary"};
	journal.add_entry("I ate a bug");
	journal.add_entry(" I cried today");

	PersistenceManager pm;
	ps.save(journal, "diary.txt ");
	getchar();
	return 0;
}