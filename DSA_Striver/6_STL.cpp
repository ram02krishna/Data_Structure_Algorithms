// STL -> Standard Template Library

#include <bits/stdc++.h>
using namespace std;

// STL is divided into 4 parts tha are :
// Algorithms
// Containers
// Functions
// Iterators

// Pairs
void explainPair()
{
    pair<int, int> p = {1, 3};                  // this stores everything into the variable p.the datatype can be anything such int,char,float,long,long long and double
    cout << p.first << " " << p.second << endl; // This will access the data of p
    // for more than two,we will use nested property of pair.for example we need to store 1,3 and 4 which can be stored such as {1,{3,4}}
    pair<int, pair<int, int>> p1 = {1, {3, 4}};
    // {3, 4} will be considered as the second element of the pair 'p'
    cout << p1.first << " " << p1.second.second << " " << p1.second.first << endl;

    pair<int, int> arr[] = {{1, 2}, {2, 5}, {5, 1}};
    cout << arr[1].second << endl; // prints 5
}

// Vectors
void explainVector()
{
    vector<int> v;     // presently,empty container -> {}
    v.push_back(1);    // now container becomes -> {1}
    v.emplace_back(2); // emplace_back dynamically increases the size and insert the element.here container becomes -> {1,2} ,emplace_back is faster than push_back

    vector<pair<int, int>> vec;
    vec.push_back({1, 3});
    vec.emplace_back(5, 7);

    vector<int> v1(5, 100); // here vector -> v1(size,element already defined,size times) that is v1(5,100) -> means {100,100,100,100,100}

    vector<int> v2(5); // here vector v2 is defined as v2(size) that is {0,0,0,0,0} or {any garbage value 5 times} depends on the compiler

    vector<int> v3(4, 9); // container -> {9,9,9,9}
    vector<int> v4(v3);   // this will copy container v3 into the container v4

    // we can access the vector elements same as the array.
    // for access we use v[index of the element of the container] or v.at(index of the element of the container)
    cout << v2[0] << " " << v2.at(1) << endl;
    cout << vec[0].first << " " << vec.at(1).second << endl;

    vector<int> k;
    k.push_back(1);
    k.emplace_back(5);
    k.emplace_back(3);
    k.emplace_back(21);
    k.emplace_back(56);
    k.emplace_back(16);
    k.emplace_back(15);

    // Iterators
    vector<int>::iterator it = k.begin(); // the container elements are stored into the memory.
    // v.begin() -> it actually points directly to the memory with the help of memory adddress not the element
    it++;
    cout << *(it) << " " << endl; // v.begin() -> will give you the address and the moment u write * infront of it will give you the data or element at that memory.
    it = it + 2;
    cout << *(it) << " " << endl;

    vector<int>::iterator new_it = k.end(); // k.end() will point to the memory adddress of the next element present at the the end/last of the element present in the container not the last element of the container that is in this case of vector k,k.end() will go the memory address of the element of next to the 15.
    // And to access the 15 we need to first decrease it by 1 that is by it-- or it = it-1

    // ANOTHER EXPLAINATION ::
    // Why new_it Causes Problems
    // When you try to dereference new_it:
    // cout << *(new_it) << endl; // This will cause undefined behavior
    // Since new_it is pointing past the last element, there's no valid data to access, and dereferencing it can result in a runtime error or garbage value.

    // SOLUTION ::
    new_it--;
    cout << *(new_it) << endl;

    // Correct use of reverse iterator
    vector<int>::reverse_iterator rev_it = k.rbegin(); // Start from rbegin() to get last element
    cout << *(rev_it) << endl;                         // Output: 15 (last element)

    rev_it++;
    cout << *(rev_it) << endl; // Output: 16 (second-to-last element)

    vector<int>::reverse_iterator rev_it1 = k.rend(); // this will point to memory address of the next element of the element at the index 0(remember that we are travelling from the end)
    cout << *(rev_it1) << endl;                       // Output: some garbage value

    rev_it1--;                  // why not rev_it1++; -> bcz rend() is traversing from the end element of the container  and will access the address of the element present before the first index element which we don't know so will show some garbage value. and to access the first element address of the container we need to decrease the rev_it1 by 1 as it is accessing from the reverse not rev_it1++,which will point the previous element address of the garbage value so which will show another garbage value.
    cout << *(rev_it1) << endl; // Output: 1

    cout << k.back() << endl; // this will point to the last element not the address of the last element. so will give 15 as output.

    // To print the entire vector
    // method -> 1

    for (vector<int>::iterator any = k.begin(); any != k.end(); any++)
    {
        cout << *(any) << " ";
    }
    cout << endl;

    // method -> 2

    // no one want to write this long syntax vector<int>::iterator.STL means standard template library.so STL gives you auto,which automatically assigns the vector iteration u do not need to assign all those datatypes or no need to write vector<int>::iteration for example
    for (auto any = k.begin(); any != k.end(); any++)
    {
        cout << *(any) << " ";
    }
    cout << endl;

    // method -> 3

    for (auto any : k)
    {
        cout << any << " ";
    }
    cout << endl;

    // Iterating from end to begin using reverse iterators
    for (auto rev = k.rbegin(); rev != k.rend(); ++rev)
    {
        cout << *rev << " ";
    }
    cout << endl;
    // Deletion in the vector -> vector_name.erase(address of the vector elements)
    k.erase(k.begin() + 1); // for delete element at index 1
    // this above thing is for deleting one element at a time

    for (auto any_new : k)
    {
        cout << any_new << " ";
    }
    cout << endl;

    // for deleting more than one element consecutiveluy then we will use below method
    k.erase(k.begin() + 1, k.begin() + 3);
    for (auto any_1 : k)
    {
        cout << any_1 << " ";
    }
    cout << endl;

    vector<int> s(2, 100);          //{100,100}
    s.insert(s.begin(), 300);       //{300,100,100}
    s.insert(s.begin() + 1, 2, 10); //{300,10,10,100,100}

    vector<int> copy(2, 50);                       //{50,50}
    s.insert(s.begin(), copy.begin(), copy.end()); //{50,50,300,10,10,100,100}

    cout << copy.size() << endl; // This will give u how much size is of the vector.

    copy.pop_back(); // this will pop the last element from the vector

    vector<int> vec1;
    vec1.push_back(56);
    vec1.emplace_back(18);

    vector<int> vec2;
    vec2.push_back(45);
    vec2.emplace_back(89);

    vec1.swap(vec2); // vec1 -> {45,89} , vec2 -> {56,18}

    for (auto print : vec1)
    {
        cout << print << " ";
    }
    cout << endl;

    vec1.clear();         // erases the entire vector
    cout << vec1.empty(); // true or false
}

// List -> it gives u front operation also.
void explainList()
{
    list<int> ls;
    ls.push_back(2);    // {2}
    ls.emplace_back(4); //{2,4}

    ls.push_front(5);   //{5,2,4}
    ls.emplace_front(); //{2,4};

    // rest functions same as vector
    // begin,end,rbegin,rend,clear,insert,size,swap
}

// stacks //LIFO
void explainStack()
{
    stack<int> st;
    st.push(1);    //{1}
    st.push(3);    //{1,3}
    st.push(3);    //{1,3,3}
    st.push(11);   //{1,3,3,11}
    st.push(7);    //{1,3,3,11,,7}
    st.emplace(5); //{5,1,3,3,11,7}
    // emplace is similar to push

    cout << st.top(); // prints 5.As the last guy that pushed into stack is 5 "** st[2] is not valid **"

    st.pop(); // st looks like {1,3,3,11,7}

    cout << st.top();   // 3
    cout << st.size();  // 4
    cout << st.empty(); // False

    stack<int> st1, st2;
    st1.swap(st2);
}

// Queue -> FIFO
void explainQueue()
{
    queue<int> q;
    q.push(1);    //{1}
    q.push(7);    //{1,7}
    q.emplace(4); //{1,7,4}
    cout << q.back() << endl;
    q.back() += 5; //{1,7,9}
    // q.back points to the 4 which now becomes 9 (4+5)
    cout << q.back() << endl;
    cout << q.front() << endl; // prints 1
    q.pop();                   //{7,9}
    cout << q.front() << endl; // prints 7

    // size,swap,empty same as stack
}

// Priority Queue -> Largest value stays at the top
void explainPQ()
{
    priority_queue<int> pqMax;   // Max Heap
    pqMax.push(5);               // {5}
    pqMax.push(2);               // {5,2}
    pqMax.push(8);               // {8,5,2}
    pqMax.emplace(10);           // {10,8,5,2}
    cout << pqMax.top() << endl; // prints 10
    pqMax.pop();                 // {8,5,2}
    cout << pqMax.top() << endl; // prints 8

    // Minimum Heap
    priority_queue<int, vector<int>, greater<int>> pqMin;
    pqMin.push(5);               // {5}
    pqMin.push(2);               // {2,5}
    pqMin.push(8);               // {2,5,8}
    pqMin.emplace(10);           // {2,5,8,10}
    cout << pqMin.top() << endl; // prints 2

    // size,swap,empty functions same as others
    // time complexity -> push = O(log(n)) ,top = O(1) ,pop = O(log(n))
}
// Set -> stores everything in the sorted sort order and stores unique element not same element
void explainSet()
{
    set<int> st;
    st.insert(1);  //{1}
    st.emplace(2); //{1,2}
    st.insert(2);  //{1,2}
    st.insert(4);  //{1,2,4}
    st.insert(3);  //{1,2,3,4}
    // Functionality of insert in vector
    // can be used also,that only increases
    // efficiency

    // begin(),end(),rbegin(),rend(),size(),empty(),swap() are same as those of above

    auto it = st.find(3); // {1,2,3,4,5}
    // iterator -> this will point to the memory
    cout << *(it) << endl; // prints 3

    auto it1 = st.find(6); // if element is not there in the set then it will always return st.end() which points right after the end

    st.erase(5); // removes 5 and takes logarithmic time

    int count = st.count(3); // if it exists which unique and can be one time in the set so will 1 as output and if does not exist then 0

    // {1,2,3,4,5}
    auto it2 = st.find(2);
    auto it3 = st.find(4);
    st.erase(it2, it3); // after erase {1,4,5} {first,last}

    // lower_bound() and upper_bound() function works in the same way
    // as in vector it does.

    auto it4 = st.lower_bound(2);
    auto it5 = st.upper_bound(3);
    // prefer https://www.youtube.com/watch?v=edJ19qIL8WQ&t=0s for lower_bound and upper_bound

    // Everything happens in O(log(n))
}

// MultiSet -> this only stores the elements in the sorted order and there is no restriction of unique element
void explainMultiSet()
// Everything is same as set
// only stores duplicate elements also
{
    multiset<int> ms;
    ms.insert(1); //{1}
    ms.insert(1); //{1,1}
    ms.insert(1); //{1,1,1}

    ms.erase(1); // all 1's erased

    int cnt = ms.count(1);

    // only a single one erased others two will remains there
    ms.erase(ms.find(1));

    // If you want to erase two elements, use the range version of erase.
    // This erases the range from the first occurrence to the position after the next two occurrences.
    auto it = ms.find(1);      // Points to the first '1'
    ms.erase(it, next(it, 2)); // ms becomes empty {}

    // The rest of the functions (like find, lower_bound, upper_bound) work the same as in a set.
}

// UnorderedSet -> this stores only unique elements no matter in what order means do not store in sorted order
void explainUSet()
{
    unordered_set<int> st;
    // Lower_bound and Upper_bound function
    // does not works,rest all functons are same
    // as above,it does not stores in any
    // particular order it has a better complexity
    // than set in most cases,except some when collision happens

    // Time complexity of all operations -> O(1) except lower_bound and upper_bound as they do not work
}

// Map -> container which stores everything in the respect of {key,value},this key can be of any datatype (int,char,double,float etc.) similarly value can be of any datatype
// map stores unique keys in sorted order
void explainMap()
{
    map<int, int> mpp;             // map<key data_type, value data_type> mpp;
    map<int, pair<int, int>> mpp1; // Not used but declared
    map<pair<int, int>, int> mpp2; // Not used but declared

    mpp[1] = 2;         // {1,2}
    mpp.emplace(3, 1);  // {1,2}, {3,1}
    mpp.insert({2, 4}); // {1,2}, {2,4}, {3,1}

    for (auto it : mpp)
    {
        cout << it.first << " " << it.second << endl; // Expected output: 1 2, 2 4, 3 1
    }

    cout << mpp[1] << endl; // prints 2
    cout << mpp[5] << endl; // prints 0, because accessing a key that doesn't exist inserts it with a default value (0 for int)

    auto it = mpp.find(3);
    if (it != mpp.end()) // Check if the key was found
    {
        cout << it->second << endl; // Correctly access the value
    }
    else
    {
        cout << "Key not found!" << endl;
    }
    cout << endl;
    // same operations (lower_bound,upper_bound,erase,swap,size,empty) works here also.

    // Takes O(log(n)) time for the operations
}

// MultiMap -> similar to map,only thing is it can store multiple keys
// Elements are stored in the sorted order by the keys.
// mpp[key] can not be used here
void explainMultimap()
{
    multimap<int, string> mmp;

    // Inserting elements into the multimap
    mmp.insert({1, "apple"});
    mmp.insert({2, "banana"});
    mmp.insert({1, "orange"});
    mmp.insert({3, "grape"});
    mmp.insert({2, "pear"});

    // Printing elements in the multimap
    cout << "Elements in the multimap:" << endl;
    for (auto it : mmp)
    {
        cout << it.first << " -> " << it.second << endl;
    }

    // Finding elements with a specific key
    auto it = mmp.find(1);
    if (it != mmp.end())
    {
        cout << "\nFound key 1: " << it->second << endl;
    }

    // Getting the range of elements with a specific key
    cout << "\nElements with key 2:" << endl;
    auto range = mmp.equal_range(2);
    for (auto it = range.first; it != range.second; ++it)
    {
        cout << it->first << " -> " << it->second << endl;
    }

    // Counting elements with a specific key
    cout << "\nNumber of elements with key 1: " << mmp.count(1) << endl;

    // Erasing elements with a specific key
    mmp.erase(2); // Removes all elements with key 2

    cout << "\nElements in the multimap after erasing key 2:" << endl;
    for (auto it : mmp)
    {
        cout << it.first << " -> " << it.second << endl;
    }
}

// UnorderedMap -> An unordered_map is an associative container that stores key-value pairs with unique keys, similar to a map. However, unlike a map, the elements in an unordered_map are not stored in any particular order. Instead, it uses a hash table as its underlying data structure, which provides average constant time complexity, O(1), for insertion, deletion, and access operations.
void explainUnorderedMap()
{
    unordered_map<string, int> umap;

    // Inserting elements into the unordered_map
    umap["apple"] = 5;
    umap["banana"] = 3;
    umap["orange"] = 8;

    // Another way to insert elements
    umap.insert({"grape", 10});
    umap.emplace("pear", 4);

    // Accessing elements
    cout << "The price of apple is: " << umap["apple"] << endl;

    // Iterating over the unordered_map
    cout << "\nElements in the unordered_map:" << endl;
    for (auto it : umap)
    {
        cout << it.first << " -> " << it.second << endl;
    }

    // Finding elements
    auto it = umap.find("banana");
    if (it != umap.end())
    {
        cout << "\nFound banana: " << it->second << endl;
    }
    else
    {
        cout << "\nBanana not found." << endl;
    }

    // Checking existence with count (returns 0 or 1)
    if (umap.count("pear") > 0)
    {
        cout << "\nPear is in the map." << endl;
    }

    // Erasing an element by key
    umap.erase("orange");

    cout << "\nElements in the unordered_map after erasing 'orange':" << endl;
    for (auto it : umap)
    {
        cout << it.first << " -> " << it.second << endl;
    }
}

// Use map when you need sorted elements and can tolerate O(logn) operations.
// Use multimap when you need sorted elements but also need to handle duplicate keys, with O(logn) operations.
// Use unordered_map when you need the fastest possible average-time operations, do not care about order, and are okay with the potential for rare worst-case performance.

// We have completed Containers and Iterators
// Functions we already know
// Now we will learn Algorithms
// Time complexity for storing and fetching in the unorderde map is O(1) for the best and average case,and O(n) for the worst case where n is no of elements in map.

void explainAlgo()
{
    // sort -> using sort will give you sorted version.You do not need to using any sorted alogorithm such as bucket sort or bubble sort or count sort or anyother sorting technique.
    // Array to be sorted
    int arr[] = {45, 12, 96, 14, 2, 7, 56, 23};
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the number of elements in the array

    // Sorting the array in ascending order
    sort(arr, arr + n);
    /* other ways ::
    sort(arr.begin(),arr.end());
    sort(arr+2,arr+4);
    sort(arr,arr+n,greater<int>); -> This will sort the array in the descending order
    */
    // Printing the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    pair<int, int> a[] = {{1, 2}, {2, 1}, {4, 1}};
    // // sort it according to second element
    // // if second element is same,then sort it according to first element but in descending
    int n1 = sizeof(a) / sizeof(a[0]); // Calculate the number of elements

    // Custom comparator function
    auto comp = [](const pair<int, int> &p1, const pair<int, int> &p2)
    {
        if (p1.second == p2.second)
        {
            // If second elements are the same, sort by first element in descending order
            return p1.first > p2.first;
        }
        // Otherwise, sort by second element in ascending order
        return p1.second < p2.second;
    };

    // Sort the array using the custom comparator
    sort(a, a + n1, comp);

    // Output the sorted array
    cout << "Sorted array a[] :: " << endl;
    for (int i = 0; i < n1; ++i)
    {
        cout << "(" << a[i].first << ", " << a[i].second << ") ";
    }
    cout << endl;
}

/*

// THIS IS THE ANOTHER WAY TO USE COMPARATOR WHERE WE HAVE DEFINED COMPARATOR WITH THE HELP OF BOOL.

#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

// Custom comparator function
bool comp(const pair<int, int>& p1, const pair<int, int>& p2) {
    if (p1.second == p2.second) {
        // If second elements are the same, sort by first element in descending order
        return p1.first > p2.first;
    }
    // Otherwise, sort by second element in ascending order
    return p1.second < p2.second;
}

int main() {
    // Define and initialize the array of pairs
    pair<int, int> a[] = {{1,2},{2,1},{4,1}};
    int n = sizeof(a) / sizeof(a[0]); // Calculate the number of elements

    // Sort the array using the custom comparator
    sort(a, a + n, comp);

    // Output the sorted array
    for (int i = 0; i < n; ++i) {
        cout << "(" << a[i].first << ", " << a[i].second << ") ";
    }
    cout << endl;

    return 0;
}
*/

// Hash Map is not part of STL by the way
// Hash Map (unordered_map) -> Stores key-value pairs with fast access using hashing
void explainHashMap()
{
    unordered_map<string, int> hashMap;

    // Inserting key-value pairs
    hashMap["apple"] = 10;
    hashMap["banana"] = 5;
    hashMap["orange"] = 7;
    hashMap.emplace("grapes", 12);

    // Accessing elements
    cout << "Apple count: " << hashMap["apple"] << endl;

    // Iterating over the hash map
    cout << "\nHash map contents:\n";
    for (auto &pair : hashMap)
    {
        cout << pair.first << " -> " << pair.second << endl;
    }

    // Finding a key
    if (hashMap.find("banana") != hashMap.end())
    {
        cout << "\nBanana found with value: " << hashMap["banana"] << endl;
    }
    else
    {
        cout << "\nBanana not found.\n";
    }

    // Erasing a key
    hashMap.erase("orange");

    cout << "\nHash map after deleting 'orange':\n";
    for (auto &pair : hashMap)
    {
        cout << pair.first << " -> " << pair.second << endl;
    }

    // Check existence using count
    if (hashMap.count("grapes"))
    {
        cout << "\nGrapes exist in the map.\n";
    }

    // Time Complexity:
    // insert -> O(1) avg, O(n) worst
    // find -> O(1) avg, O(n) worst
    // erase -> O(1) avg, O(n) worst
}

// Yes, unordered_map (or historically hash_map) is widely used to store frequencies of elements due to its constant average time complexity (O(1)) for insertions and lookups. This makes it ideal for:

// Use Cases of Hash Map for Frequency Counting
// Counting character or word frequencies in a string
// Counting number frequencies in an array
// Finding duplicates
// Mode calculation (most frequent element)
// Grouping elements by count

void explainAlgo1()
{
    int num = 7;
    int cnt = __builtin_popcount(num);
    // __builtin_popcout -> Binary of num = 7 is 111.There are 32 bits inside the PC which is 0*29timesthen111.So,Basically this operation will count the set bits that is how many 1's are there.Here no of 1's is 3.So int cnt = __builtin_popcount(num); will print 3
    cout << cnt << endl;

    int num1 = 6; // 110 in binary
    int count = __builtin_popcount(num1);
    cout << count << endl;

    long long k = 154785864859525;
    int count_1 = __builtin_popcountll(k);
    cout << count_1 << endl;

    string s = "143";
    sort(s.begin(), s.end());
    do
    {
        cout << s << endl;
    } while (next_permutation(s.begin(), s.end()));

    int a[] = {12, 5, 7, 31, 2, 1};
    int n = sizeof(a) / sizeof(a[0]);
    int maxi = *max_element(a, a + n);
    cout << maxi << endl;
}

int main()
{
    // explainPair();
    // explainVector();
    // explainList();
    // explainStack();
    // explainQueue();
    // explainPQ();
    // explainSet();
    // explainMultiSet();
    // explainMap();
    // explainMultimap();
    // explainUnorderedMap();
    // explainAlgo();
    // explainHashMap();

    explainAlgo1();
    cout << "\n*************String Manipulation***************" << endl;
    string s = "Hello, world!";
    // substr(): Get a substring
    string sub = s.substr(7, 5);
    cout << "Substring: " << sub << std::endl;
    // find(): Find a substring
    size_t pos = s.find("world");
    if (pos != string::npos)
    {
        cout << "Found at position: " << pos << std::endl;
    }
    // replace(): Replace part of the string
    s.replace(7, 5, "C++");
    cout << "After replace: " << s << endl;

    /*
    Explanation:
    First Search (s.find("world")):

    We search for the substring "world" in the string "Hello, world!".
    The find() function returns the starting position of the substring "world", which is 7 (because "world" starts at index 7 in "Hello, world!").
    Since 7 != std::string::npos, the condition is true and we print the found position.
    Second Search (s.find("goodbye")):

    We search for the substring "goodbye", which does not exist in "Hello, world!".
    The find() function returns std::string::npos because the substring is not found.
    Since std::string::npos represents a failure to find the substring, the condition becomes false, and we print "goodbye" not found.


    npos: A special value that indicates "not found."
    size()/length(): Returns the length of the string.
    empty(): Checks if a string is empty.
    at(): Accesses a character with bounds checking.
    substr(): Extracts a substring.
    replace(): Replaces a portion of a string.
    find()/rfind(): Finds the first/last occurrence of a substring.
    append()/push_back(): Adds content to a string.
    c_str(): Converts a string to a C-style string (char array).
    find_first_of()/find_last_of(): Finds the first/last occurrence of any character from a set.
    insert(): Insert a substring at a specific position.
    erase(): Remove part of a string.
    compare(): Compare two strings lexicographically.
    to_string(): Convert numeric values to strings.
    find_first_not_of()/find_last_not_of(): Find the first/last character not in a set.
    replace() (iterator): Replace part of a string using iterators.
    swap(): Swap two strings.
    resize(): Change the size of a string.
    c_str()/data(): Get the C-string representation of a string.
    reverse(): Reverse a string (using std::reverse).
    operator[]: Access individual characters of a string.

    These all are used as string::________  or string._______
    here string is used,it can have the name of the string such as defined - String s; so s.______
    */

    cout << "\n************Accumulate***************" << endl;

    // Accumulate
    // Syntax :: accumulate(start_iterator, end_iterator, initial_value);
    // start_iterator: The beginning of the range
    // end_iterator: The end of the range
    // initial_value: The initial value for the accumulation (e.g., 0L for a long integer).
    vector<int> numbers = {1, 2, 3, 4, 5};

    // Calculate the sum of all elements in the vector
    int sum = accumulate(numbers.begin(), numbers.end(), 0);

    cout << "Sum: " << sum << endl;

    return 0;
}

/*
1. What is map?
map in C++ is an ordered associative container that stores key–value pairs (key must be unique).
Keys are sorted automatically (by default in ascending order using < operator).
Internally implemented as a balanced binary search tree (Red-Black Tree).
Syntax:
#include <map>
map<int, string> m;

Key Features:
Stores elements in order of keys.
Searching, insertion, and deletion take O(log n) time because of tree operations.
Keys must be comparable (operator < should be defined).


2. What is unordered_map?
unordered_map is an unordered associative container that stores key–value pairs but does NOT keep them sorted.
Internally implemented as a hash table.
Keys are placed into buckets based on their hash value.
Syntax:
#include <unordered_map>
unordered_map<int, string> um;

Key Features:
No ordering of keys.
Searching, insertion, and deletion take average O(1) time, but worst case O(n) (if too many collisions).
Keys must be hashable (a hash function must exist).


MAP VS UNORDERED_MAP IN NOTION 
LINK:
https://www.notion.so/map-vs-unordered_map-1-24f251d6f0d480ada3e6c0ca2005b905?source=copy_link
*/
