#include <iostream>

template<typename V> void counts(); // V-----> T
template<typename W> void reports(W&); // W----> HasFriend<T>

template<typename T>
class HasFriend
{
private:
	T item;
	static int ct;
public:
	HasFriend(const T& i) : item(i) {ct++;}
	~HasFriend() {ct--;}
	friend void counts<T>();
	friend void reports< HasFriend<T> >(HasFriend<T>& hf); 
};

template<typename T>
int HasFriend<T>::ct = 0;

template<typename V>
void counts()
{
	std::cout << "template size: " << sizeof(HasFriend<V>) << "; ";
	std::cout << "template counts(): " << HasFriend<V>::ct << std::endl;
}

template<typename W>
void reports(W& hf)
{
	std::cout << hf.item << std::endl;
}

//////////////////////////////////////////////
int main(void)
{
	counts<int>();
	HasFriend<int> hfi1(10);	
	HasFriend<int> hfi2(20);	
	HasFriend<double> hfi3(10.5);
	reports< HasFriend<int> >(hfi1);	
	reports< HasFriend<int> >(hfi2);	
	reports< HasFriend<double> >(hfi3);
	std::cout << "counts<int>() output:\n";
	counts<int>();
	std::cout << "counts<double>() output:\n";
	counts<double>();	
	return 0;
}
