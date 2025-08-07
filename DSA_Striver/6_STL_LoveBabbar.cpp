#include <bits/stdc++.h>
using namespace std;

int main()
{
  /*
    // Array
    array<int, 5> a = {1, 2, 3, 4, 5}; // Array is static that is once the array size is defined then you can not add element after the array is full.
    int size = a.size();
    for (int i = 0; i < size; i++)
    {
      cout << a[i] << endl;
    }
    cout << "Element at index 2 : " << a.at(2) << endl;
    cout << "Empty or not : " << a.empty() << endl;
    cout << "First Element : " << a.front() << endl;
    cout << "Last Element : " << a.back() << endl;
  */

  /*
    // Vector
    vector<int> v;
    cout << "Capacity of the vector at this moment : " << v.capacity() << endl;
    v.push_back(1); // To insert the elements in the vector
    cout << "Capacity of the vector at this moment : " << v.capacity() << endl;
    v.push_back(12);
    cout << "Capacity of the vector at this moment : " << v.capacity() << endl;
    cout << "Size of the vector v : " << v.size() << endl;
    // There is a difference between size and capacity. The capacity of a vector is the total number of elements it can hold or we can say how much memory is assigned. The total amount of storage is what capacity is, but how much content (elements) are there inside the vector is what the size of a vector represents.
    cout << "Element at the index 1 : " << v.at(1) << endl;
    cout << "Front element : " << v.front() << endl;
    cout << "Last element : " << v.back() << endl;
    cout << "Before pop : " << endl;
    for (int i : v) // Range-based for loop
    {
      cout << i << " ";
    }
    cout << endl;
    v.pop_back();
    cout << "After pop : " << endl;
    for (int i : v)
    {
      cout << i << " ";
    }
    cout << endl;
    v.clear();
    cout << "After clear,Size of the vector v : " << v.size() << endl;
    // After using clear,the size of the vector will become 0 as no elements will be there but it's capacity will remain be the same.
    vector<int> a(5, 1); // This will assign a vector a of size 5 where each of the index will have 1 as element.
    cout << "print a : " << endl;
    for (int i : a)
    {
      cout << i << " ";
    }
    vector<int> last(a); // this will copy the vector a in the vector last.
  */

  /*
   // Deque -> Double ended queue
   deque<int> d;
   d.push_back(1);
   d.push_back(14);
   d.push_back(21);
   d.push_back(71);
   d.push_front(53);
   d.push_front(93);
   d.push_front(69);

   d.pop_back();
   d.pop_front();
   cout << "Element at the first index : " << d.at(1) << endl;
   cout << "Whether Empty or not : " << d.empty() << endl;
   cout << "Before Erase : " << d.size() << endl;
   d.erase(d.begin(), d.begin() + 1);
   cout << "After Erase : " << d.size() << endl;
   for (int i : d)
   {
     cout << i << " ";
   }
   cout << endl;
 */

  /*
    // List
    list<int> l;
    l.push_back(25);
    l.push_front(12);
    for (int i : l)
    {
      cout << i << " ";
    }
    cout << endl;
    l.erase(l.begin());
    cout << "After Erase : " << endl;
    for (int i : l)
    {
      cout << i << " ";
    }
    cout << endl;
    cout << "Size of the list : " << l.size() << endl;
    list<int> n(l); // list l copies to the newly created list n
    n.push_back(56);
    n.push_front(36);
    for (int i : n)
    {
      cout << i << " ";
    }
    cout << endl;
  */

  /*
    // Stack -> LIFO(Last In First Out)
    stack<string> s;
    s.push("I");
    s.push("love");
    s.push("you"); // This is the last one who places into the stack

    cout << "Top Element : " << s.top() << endl;
    s.pop();
    cout<<"Size of Stack : "<<s.size()<<endl;
    cout<<"Empty or not : "<<s.empty();
    */

  /*
    //  Queue
    queue<string> q;
    q.push("I");
    q.push("love");
    q.push("you");

    cout << "Size of the queue before pop : " << q.size() << endl;
    // cout<<"Capacity of the queue before pop : "<<q.capacity(); // this will not work as the capacity of the queue is not defined.
    q.pop();
    cout << "Size of the queue after pop : " << q.size() << endl;
    ;

    // Priority Queue -> this is related to max heap and min heap

    priority_queue<int> max_heap; // This will create a max heap

    priority_queue<int, vector<int>, greater<int>> min_heap; // This will create a min heap

    max_heap.push(94);
    max_heap.push(25);
    max_heap.push(52);
    max_heap.push(85);
    max_heap.push(72);

    cout << "Size of the max heap : " << max_heap.size() << endl;

    // for (int i = 0; i < max_heap.size(); i++) //This will print only first 3 elements in this case even having 5 elements bcz in the loop max_heap size is decreasing which is creating a issue so first define a variable which contains the size of the max_heap.

    int n = max_heap.size();
    for (int i = 0; i < n; i++)
    {
      cout << max_heap.top() << endl;
      max_heap.pop();
    }
    cout << endl;

    min_heap.push(94);
    min_heap.push(25);
    min_heap.push(52);
    min_heap.push(85);
    min_heap.push(72);

    cout << "Size of the min heap : " << min_heap.size() << endl;

    int k = min_heap.size();
    for (int i = 0; i < k; i++)
    {
      cout << min_heap.top() << endl;
      min_heap.pop();
    }
    cout << endl;
    cout<<"Is min_heap empty? : "<<min_heap.empty()<<endl;
  */

  /*
    //  Set -> In Set,only unique elements store,there can not be any duplicate elements.

  set<int> s;
  s.insert(45);
  s.insert(14);
  s.insert(75);
  s.insert(45);
  s.insert(12);
  s.insert(14);
  s.insert(37);
  s.insert(14);

  for (auto i : s)
  {
    cout << i << endl;
  }
  cout << endl;

  set<int>::iterator it = s.begin();
  it++;

  cout << "5 is present or not in the set : " << s.count(5);
  cout << endl;
  cout << "14 is present or not in the set : " << s.count(14);
  cout << endl;

  s.erase(it);

  for (auto i : s)
  {
    cout << i << endl;
  }
  cout << endl;

  set<int>::iterator itr = s.find(5);

  for (auto it = itr; it != s.end(); it++)
  {
    cout << *it << " ";
  }
  cout << endl;
  // Time complexity of insert,erase,find,count is O(log n)
  // Time complexity of size,begin,end and empty is o(1)
  */

  // Map -> Map is a data structure where data stores in the form <key,value> pairs
  // Same keys can not point to the same values where as same keys can point to different values.

  /*
  map<int, string> mpp;
  mpp[1] = "babbar";
  mpp[2] = "love";
  mpp[13] = "kumar";

  for (auto i : mpp)
  {
    cout << i.first << endl;
  }

  // In case of map,the printing sequence is in sorted order whereas in the unordered_map it is in random order.

  mpp.insert({5, "bheem"});

  for (auto i : mpp)
  {
    cout << i.first << " " << i.second << endl;
  }

  cout << "Is 13 present or not : " << mpp.count(13) << endl;
  cout << "Is 13 present or not : " << mpp.count(11) << endl;

  mpp.erase(13); // This will erase the key 13 and the value it contains in it.

  for (auto i : mpp)
  {
    cout << i.first << " " << i.second << endl;
  }
  // Time complexity for insert,erase,find,count is O(log n) by using red black tree or balanced tree.
  // Whereas in unordered map the time complexity for all these case is O(1) using hash table

  auto it = mpp.find(5);
  for (auto i = it; i != mpp.end(); i++)
  {
    cout << (*it).first << endl;
  }
  */

  // Algorithms
  vector<int> v;
  v.push_back(1);
  v.push_back(3);
  v.push_back(5);
  v.push_back(7);
  v.push_back(10);
  v.push_back(15);
  v.push_back(21);

  cout << "Is 6 present or not (using binary search) :: " << binary_search(v.begin(), v.end(), 6) << endl;
  cout << "Is 7 present or not (using binary search) :: " << binary_search(v.begin(), v.end(), 7) << endl;
  cout << "Lower_Bound (using binary search) :: " << lower_bound(v.begin(), v.end(), 7) - v.begin() << endl;
  cout << "Upper_Bound (using binary search) :: " << upper_bound(v.begin(), v.end(), 10) - v.begin() << endl;

  rotate(v.begin(), v.begin() + 2, v.end());
  cout << "After using rotate : " << endl;
  for (int i : v)
  {
    cout << i << " ";
  }
}