// find the midpoint
#include <iostream>
using namespace std;
#include <list>
#include <vector>
// random access iterator
template <typename ptr_t>
ptr_t my_mid_(ptr_t first, ptr_t last, random_access_iterator_tag)
{
    cout << "random access\n";
    return first + (last - first) / 2;
}

// bidirectional iterator
template <typename ptr_t>
ptr_t my_mid_(ptr_t first, ptr_t last, bidirectional_iterator_tag)
{
    cout << "bidirectional iterator\n";
    while (first != last && first != --last)
    {
        ++first;
    }
    return first;
}
// input iterator
template <typename ptr_t>
ptr_t my_mid_(ptr_t first, ptr_t last, input_iterator_tag)
{
    cout << "input iterator\n";
    ptr_t temp(*first);
    while (first != last && ++first != last)
    {
        ++temp;
        ++first;
    }
    return temp;
}
template <typename ptr_t> ptr_t my_mid(ptr_t first, ptr_t last)
{
    return my_mid_(first, last,
                   typename iterator_traits<ptr_t>::iterator_category());
}

int main()
{
    vector<int> v{11, 22, 33, 44, 55};
    vector<int>::iterator it_v;

    it_v = my_mid(begin(v), end(v));
    cout << "val : " << *it_v << "\n";

    list<int> l{11, 22, 33, 44, 55};
    list<int>::iterator it_l;

    it_l = my_mid(begin(l), end(l));
    cout << "val : " << *it_l << "\n";
}

#if 0
// input iterator
template<typename ptr_t>
ptr_t my_mid(ptr_t first, ptr_t last)
{

	ptr_t temp(*first);
	while(first != last)
	{
		++temp;
		++first;
		if(first != last)
		{
			++first;
		}
	}
	return temp;

}
#endif
