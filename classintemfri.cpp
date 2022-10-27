#include <iostream>

template<typename T>
class ManyFriend
{
private:
	T item;
public:
	ManyFriend(const T& i) : item(i) {}
	template<typename C, typename D> friend void show(C&, D&);
};

template<typename C, typename D> void show(C& c, D& d)
{
	std::cout << c.item << ", " << d.item << std::endl;
}

int main(void)
{
	ManyFriend<int> hfi1(10);
	ManyFriend<int> hfi2(20);
	ManyFriend<double> hfi3(10.5);
	std::cout << "hfi1, hfi3: ";
	show(hfi1, hfi2);
	std::cout << "hfi3, hfi2: ";
	show(hfi3, hfi2);
	return 0;
}	
