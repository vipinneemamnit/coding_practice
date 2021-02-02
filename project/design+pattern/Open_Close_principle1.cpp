#include <stdio>
#include <vector>
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
template <typename T> struct Specification
{
	virtual bool is_satishfied(T * item) = 0;
};
template <typename T> struct Filter
{
	virtual vector<T*> filter(vector<T*> items, Specification<T>& spec) = 0;
	
};

struct BetterFilter : Filter<Product>
{
vector<Product *> Filter(vector<Product*> items, Specification<Product> &spec) override
	{
		vector<Product* > result;
		for(auto& item : items)
		if(spec.is_satishfied(item))
			result.push_back(item);
		return result;
	} 	
};

struct ColorSpecification : specification<Product>
{
	Color color;
	ColorSpecification(Color color) : color(color){}
	
	bool is_satishfied(Product* item) override{return item->color==color;}
	
};