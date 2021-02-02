#include <stdio>
using namespace std;
using namespace boost;

enum class Color {red, green, blue};
enum class size { small, medium, large};

struct product
{
	String name;
	Color color;
	Size size;
};

struct productFilter
{
	vector<product*> by_color(vector<product*> items, Color color)
		{
			vector<product*> result;

			for(auto& i : items)
				if(i->color == color)
					result.push_back(i);
			return result;		
	}
	vector<product*> by_size(vector<product*> items, Size size)
		{
			vector<product*> result;

			for(auto& i : items)
				if(i->size == sizes)
					result.push_back(i);
			return result;		
	}
	vvector<product*> by_size_color(vector<product*> items, Size size, Color color)
		{
			vector<product*> result;

			for(auto& i : items)
				if(i->size == sizes && i->color == color)
					result.push_back(i);
			return result;		
	}
};
int main()
{
	product apple{"Apple",Color::green, Size::small };
	product Tree{"tree",Color::green, Size::large };
	product House{"House",Color::blue, Size::large };

	vector<product*> items{&apple, &Tree, &House};

	productFilter pf;

	auto green_things = pf.by_color(item, Color::green);
	for(auto& item : green_things)
		cout<<item->name<< is green<<endl;
	return 0;
}
