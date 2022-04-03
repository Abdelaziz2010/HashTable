#include <iostream>
#include<vector>
#include<map>
using namespace std;
template <class K, class V>
struct keyvalue   //node of hashtable
{
	K key;
	V value;
};
template<class K,class V>
class Hashtable
{
private:
	vector<keyvalue<K, V>> internalList[100];
	unsigned int GetHashCode(K key)
	{
		std::hash<K>hashFn;
		return (unsigned int)hashFn(key);
	}
	V Search(K key, vector<keyvalue<K, V>> v)
	{
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i].key == key)
				return v[i].value;
		}

		return 0;
	}
public:
	void Add(K key, V value)
	{
		unsigned int hash = GetHashCode(key);
		unsigned int location = hash % 100;
		keyvalue<K, V>item;
		item.key = key;
		item.value = value;
		internalList[location].push_back(item);
	}
	V findItem(K key)
	{
		unsigned int hash = GetHashCode(key);
		unsigned int location = hash % 100;
		return Search(key, internalList[location]);
	}

   
};
int main()
{
	Hashtable<int,int> table;
	table.Add(1, 10);
	table.Add(2, 20);
	table.Add(3, 30);
	table.Add(4, 40);
	table.Add(5, 50);
	 
	cout << table.findItem(5) << endl;

	map<int, int> m;
	m[6] = 60;
	return 0;
}
