// STL -> Standard Template Library
// Enhanced Complete Guide with Detailed Side-by-Side Comments and Explanations

#include <bits/stdc++.h>
using namespace std;

/* ====================================================================
   STL is divided into 4 main components:
   1. Algorithms - Functions for searching, sorting, manipulating data
   2. Containers - Data structures like vector, list, map, set etc.
   3. Functions - Function objects and lambda expressions
   4. Iterators - Objects that point to elements in containers
   ==================================================================== */

// ====================================================================
// 1. PAIRS - Utility to store two values together
// ====================================================================
void explainPair()
{
    cout << "\n========== PAIRS ==========\n";

    // Basic pair creation and access
    pair<int, int> p = {1, 3};                                    // Creates pair p with first=1, second=3 -> {1,3}
    cout << "Basic pair: " << p.first << " " << p.second << endl; // Accesses first and second elements -> prints "1 3"

    // Different ways to create pairs
    pair<int, string> p1(10, "Hello");             // Constructor method -> {10, "Hello"}
    pair<int, string> p2 = make_pair(20, "World"); // Using make_pair function -> {20, "World"}

    cout << "Constructor pair: " << p1.first << " " << p1.second << endl; // prints "10 Hello"
    cout << "make_pair: " << p2.first << " " << p2.second << endl;        // prints "20 World"

    // Nested pairs for storing more than 2 values
    pair<int, pair<int, int>> nested = {1, {3, 4}};                     // Stores 3 values: 1, 3, 4 as {1, {3,4}}
    cout << "Nested pair: " << nested.first << " "                      // Access first element -> 1
         << nested.second.first << " " << nested.second.second << endl; // Access nested pair -> 3 4

    // Array of pairs
    pair<int, int> arr[] = {{1, 2}, {2, 5}, {5, 1}};                    // Array containing 3 pairs
    cout << "Array of pairs, arr[1].second: " << arr[1].second << endl; // arr[1] = {2,5}, so .second = 5

    // Pair comparison (lexicographical order)
    pair<int, int> a = {1, 3};                              // First pair -> {1,3}
    pair<int, int> b = {1, 2};                              // Second pair -> {1,2}
    cout << "Pair comparison (a > b): " << (a > b) << endl; // Compares lexicographically: since first elements equal, compares second -> 3 > 2, so true

    // Swapping pairs
    pair<int, string> x = {1, "First"};                               // x -> {1, "First"}
    pair<int, string> y = {2, "Second"};                              // y -> {2, "Second"}
    x.swap(y);                                                        // After swap: x -> {2, "Second"}, y -> {1, "First"}
    cout << "After swap - x: " << x.first << " " << x.second << endl; // prints "2 Second"
}

// ====================================================================
// 2. VECTORS - Dynamic arrays that can grow/shrink
// ====================================================================
void explainVector()
{
    cout << "\n========== VECTORS ==========\n";

    // Vector creation and initialization
    vector<int> v;                 // Empty vector -> {}
    vector<int> v1(5, 100);        // Vector of size 5, all elements = 100 -> {100,100,100,100,100}
    vector<int> v2(5);             // Vector of size 5, all elements = 0 -> {0,0,0,0,0}
    vector<int> v3{1, 2, 3, 4, 5}; // Direct initialization -> {1,2,3,4,5}
    vector<int> v4(v3);            // Copy constructor, v4 becomes copy of v3 -> {1,2,3,4,5}

    // Adding elements
    v.push_back(1);                 // v becomes -> {1}
    v.emplace_back(2);              // v becomes -> {1,2} (emplace_back is faster than push_back)
    v.insert(v.begin(), 0);         // Insert 0 at beginning -> {0,1,2}
    v.insert(v.begin() + 1, 3, 10); // Insert 3 copies of 10 at position 1 -> {0,10,10,10,1,2}

    // Accessing elements
    cout << "First element: " << v[0] << " or " << v.at(0) << endl; // Both access first element, at() does bounds checking
    cout << "Last element: " << v.back() << endl;                   // Returns reference to last element
    cout << "Front element: " << v.front() << endl;                 // Returns reference to first element

    // Vector with pairs
    vector<pair<int, int>> vec_pairs; // Empty vector of pairs -> {}
    vec_pairs.push_back({1, 3});      // vec_pairs becomes -> {{1,3}}
    vec_pairs.emplace_back(5, 7);     // vec_pairs becomes -> {{1,3}, {5,7}} (emplace constructs in place)

    // Size and capacity operations
    cout << "Size: " << v.size() << endl;         // Current number of elements
    cout << "Capacity: " << v.capacity() << endl; // Current allocated memory capacity
    cout << "Max size: " << v.max_size() << endl; // Maximum possible size
    cout << "Is empty: " << v.empty() << endl;    // Returns true if size() == 0, false otherwise

    // ITERATORS - Detailed explanation
    vector<int> demo = {1, 5, 3, 21, 56, 16, 15}; // demo -> {1,5,3,21,56,16,15}

    // Forward iterators
    vector<int>::iterator it = demo.begin();               // Iterator pointing to first element (memory address of first element)
    cout << "First element via iterator: " << *it << endl; // Dereference iterator to get value -> 1

    it++;                                      // Move iterator to next element
    cout << "Second element: " << *it << endl; // Now points to second element -> 5

    it = it + 2;                               // Move iterator 2 positions forward
    cout << "Fourth element: " << *it << endl; // Now points to fourth element -> 21

    // End iterator
    vector<int>::iterator end_it = demo.end();   // Points to one position PAST the last element (not to last element)
    end_it--;                                    // Move back one position to point to actual last element
    cout << "Last element: " << *end_it << endl; // Now points to last element -> 15

    // Reverse iterators
    vector<int>::reverse_iterator rev_it = demo.rbegin();             // Points to last element when iterating in reverse
    cout << "Last element via reverse iterator: " << *rev_it << endl; // Prints last element -> 15

    rev_it++;                                           // In reverse iteration, ++ moves to previous element
    cout << "Second last element: " << *rev_it << endl; // Now points to 16

    // Auto keyword simplifies iterator declarations
    for (auto it = demo.begin(); it != demo.end(); it++) // auto automatically deduces type as vector<int>::iterator
    {
        cout << *it << " "; // Dereference each iterator to print value
    }
    cout << endl;

    // Range-based for loop (C++11 feature)
    cout << "Range-based loop: ";
    for (auto element : demo) // auto deduces type as int, element gets copy of each value
    {
        cout << element << " "; // Prints each element
    }
    cout << endl;

    // Enhanced range-based loop with references
    cout << "Modifying elements: ";
    for (auto &element : demo) // auto& gets reference to actual elements (not copies)
    {
        element *= 2;           // Modifies actual elements in vector
        cout << element << " "; // Prints modified values
    }
    cout << endl; // demo is now {2,10,6,42,112,32,30}

    // DELETION operations
    demo.pop_back();                                // Removes last element -> {2,10,6,42,112,32}
    demo.erase(demo.begin() + 1);                   // Removes element at index 1 -> {2,6,42,112,32}
    demo.erase(demo.begin() + 1, demo.begin() + 3); // Removes elements from index 1 to 2 (3 not included) -> {2,112,32}

    cout << "After deletions: ";
    for (auto x : demo) // Print remaining elements
        cout << x << " ";
    cout << endl;

    // Vector operations
    vector<int> vec1 = {56, 18};                                   // vec1 -> {56,18}
    vector<int> vec2 = {45, 89};                                   // vec2 -> {45,89}
    vec1.swap(vec2);                                               // After swap: vec1 -> {45,89}, vec2 -> {56,18}
    vec1.clear();                                                  // Removes all elements, vec1 becomes -> {}
    cout << "Is vec1 empty after clear: " << vec1.empty() << endl; // Returns true since size is 0

    // 2D Vector (Vector of vectors)
    vector<vector<int>> matrix(3, vector<int>(4, 0));             // Creates 3x4 matrix, all elements initialized to 0
    matrix[1][2] = 5;                                             // Sets element at row 1, column 2 to 5
    cout << "2D Vector element [1][2]: " << matrix[1][2] << endl; // Prints 5

    // Vector algorithms
    vector<int> algo_demo = {3, 1, 4, 1, 5, 9, 2, 6}; // algo_demo -> {3,1,4,1,5,9,2,6}
    sort(algo_demo.begin(), algo_demo.end());         // Sorts in ascending order -> {1,1,2,3,4,5,6,9}
    reverse(algo_demo.begin(), algo_demo.end());      // Reverses the order -> {9,6,5,4,3,2,1,1}

    cout << "Sorted and reversed: ";
    for (int x : algo_demo) // Print final result
        cout << x << " ";
    cout << endl;
}

// ====================================================================
// 3. LISTS - Doubly linked lists
// ====================================================================
void explainList()
{
    cout << "\n========== LISTS ==========\n";

    list<int> ls; // Empty doubly linked list -> {}

    // Adding elements
    ls.push_back(2);     // Add at end -> {2}
    ls.emplace_back(4);  // Add at end (faster) -> {2,4}
    ls.push_front(5);    // Add at beginning -> {5,2,4}
    ls.emplace_front(1); // Add at beginning (faster) -> {1,5,2,4}

    // Accessing elements (no random access like vector)
    cout << "Front: " << ls.front() << ", Back: " << ls.back() << endl; // front() = 1, back() = 4

    // Size operations
    cout << "Size: " << ls.size() << endl;   // Returns number of elements -> 4
    cout << "Empty: " << ls.empty() << endl; // Returns false since list is not empty

    // Removing elements
    ls.pop_front(); // Remove first element -> {5,2,4}
    ls.pop_back();  // Remove last element -> {5,2}

    // List-specific operations
    list<int> ls2 = {10, 20, 30}; // Second list -> {10,20,30}
    ls.splice(ls.begin(), ls2);   // Move all elements of ls2 to beginning of ls -> {10,20,30,5,2}, ls2 becomes empty

    ls.push_back(5); // ls -> {10,20,30,5,2,5}
    ls.push_back(5); // ls -> {10,20,30,5,2,5,5}
    ls.push_back(3); // ls -> {10,20,30,5,2,5,5,3}
    ls.remove(5);    // Remove all occurrences of 5 -> {10,20,30,2,3}
    ls.unique();     // Remove consecutive duplicates (none in this case)

    cout << "List after operations: ";
    for (auto x : ls) // Print all elements
        cout << x << " ";
    cout << endl;

    // Sorting and reversing
    ls.sort();    // Sort in ascending order -> {2,3,10,20,30}
    ls.reverse(); // Reverse the order -> {30,20,10,3,2}

    cout << "Sorted and reversed: ";
    for (auto x : ls) // Print final result
        cout << x << " ";
    cout << endl;
}

// ====================================================================
// 4. STACKS - LIFO (Last In First Out) container
// ====================================================================
void explainStack()
{
    cout << "\n========== STACKS ==========\n";

    stack<int> st; // Empty stack -> {} (bottom to top)

    // Adding elements (LIFO - Last In First Out)
    st.push(1);     // Stack -> {1} (1 at top)
    st.push(3);     // Stack -> {1,3} (3 at top, 1 at bottom)
    st.push(7);     // Stack -> {1,3,7} (7 at top)
    st.emplace(11); // Stack -> {1,3,7,11} (11 at top, emplace is faster)

    cout << "Stack size: " << st.size() << endl; // Returns number of elements -> 4
    cout << "Top element: " << st.top() << endl; // Returns reference to top element -> 11 (doesn't remove it)

    // Removing elements
    st.pop();                                       // Remove top element -> Stack becomes {1,3,7}
    cout << "After pop, top: " << st.top() << endl; // New top element -> 7

    // Stack operations demonstration
    cout << "Stack contents (top to bottom): ";
    stack<int> temp_stack = st; // Create copy to avoid destroying original
    while (!temp_stack.empty()) // While stack is not empty
    {
        cout << temp_stack.top() << " "; // Print top element
        temp_stack.pop();                // Remove top element
    }
    cout << endl; // Output: 7 3 1 (top to bottom)

    cout << "Is stack empty: " << st.empty() << endl; // Returns false since original stack still has elements

    // Stack with different data types
    stack<string> str_stack;  // Empty string stack
    str_stack.push("First");  // Stack -> {"First"}
    str_stack.push("Second"); // Stack -> {"First", "Second"}
    str_stack.push("Third");  // Stack -> {"First", "Second", "Third"}

    cout << "String stack top: " << str_stack.top() << endl; // Prints "Third" (top element)
}

// ====================================================================
// 5. QUEUES - FIFO (First In First Out) container
// ====================================================================
void explainQueue()
{
    cout << "\n========== QUEUES ==========\n";

    queue<int> q; // Empty queue -> {} (front to back)

    // Adding elements (FIFO - First In First Out)
    q.push(1);    // Queue -> {1} (1 at both front and back)
    q.push(7);    // Queue -> {1,7} (1 at front, 7 at back)
    q.emplace(4); // Queue -> {1,7,4} (1 at front, 4 at back, emplace is faster)

    cout << "Queue size: " << q.size() << endl;     // Returns number of elements -> 3
    cout << "Front element: " << q.front() << endl; // Returns reference to front element -> 1
    cout << "Back element: " << q.back() << endl;   // Returns reference to back element -> 4

    // Modifying back element
    q.back() += 5;                                        // Modify back element: 4 + 5 = 9, Queue -> {1,7,9}
    cout << "After modifying back: " << q.back() << endl; // Prints 9

    // Removing elements
    q.pop();                                           // Remove front element -> Queue becomes {7,9}
    cout << "After pop, front: " << q.front() << endl; // New front element -> 7

    // Queue operations demonstration
    cout << "Queue contents (front to back): ";
    queue<int> temp_queue = q;  // Create copy to avoid destroying original
    while (!temp_queue.empty()) // While queue is not empty
    {
        cout << temp_queue.front() << " "; // Print front element
        temp_queue.pop();                  // Remove front element
    }
    cout << endl; // Output: 7 9 (front to back)

    cout << "Is queue empty: " << q.empty() << endl; // Returns false since original queue still has elements

    // Queue with custom data types
    queue<pair<int, string>> custom_queue; // Empty queue of pairs
    custom_queue.push({1, "First"});       // Queue -> {{1,"First"}}
    custom_queue.push({2, "Second"});      // Queue -> {{1,"First"}, {2,"Second"}}

    cout << "Custom queue front: " << custom_queue.front().first // Access first element of front pair -> 1
         << " " << custom_queue.front().second << endl;          // Access second element of front pair -> "First"
}

// ====================================================================
// 6. PRIORITY QUEUES - Heap-based container (Max-Heap by default)
// ====================================================================
void explainPQ()
{
    cout << "\n========== PRIORITY QUEUES ==========\n";

    // MAX HEAP (default behavior - largest element has highest priority)
    priority_queue<int> pq_max; // Empty max heap -> {} (largest element at top)
    pq_max.push(5);             // Heap -> {5}
    pq_max.push(2);             // Heap -> {5,2} (5 at top since 5 > 2)
    pq_max.push(8);             // Heap -> {8,2,5} (8 at top since 8 > 5 > 2)
    pq_max.emplace(10);         // Heap -> {10,8,5,2} (10 at top, emplace is faster)

    cout << "Max heap top: " << pq_max.top() << endl;            // Returns largest element -> 10
    pq_max.pop();                                                // Remove largest element -> {8,5,2}
    cout << "After pop, max heap top: " << pq_max.top() << endl; // New largest element -> 8

    // MIN HEAP (smallest element has highest priority)
    priority_queue<int, vector<int>, greater<int>> pq_min; // Explicitly specify min heap using greater<int> comparator
    pq_min.push(5);                                        // Heap -> {5}
    pq_min.push(2);                                        // Heap -> {2,5} (2 at top since 2 < 5)
    pq_min.push(8);                                        // Heap -> {2,5,8} (2 at top since 2 < 5 < 8)
    pq_min.emplace(10);                                    // Heap -> {2,5,8,10} (2 at top)

    cout << "Min heap top: " << pq_min.top() << endl;            // Returns smallest element -> 2
    pq_min.pop();                                                // Remove smallest element -> {5,8,10}
    cout << "After pop, min heap top: " << pq_min.top() << endl; // New smallest element -> 5

    // Priority queue with pairs (compares by first element by default)
    priority_queue<pair<int, int>> pq_pairs; // Max heap of pairs
    pq_pairs.push({3, 100});                 // Heap -> {{3,100}}
    pq_pairs.push({1, 200});                 // Heap -> {{3,100}, {1,200}} (3 > 1, so {3,100} at top)
    pq_pairs.push({5, 50});                  // Heap -> {{5,50}, {1,200}, {3,100}} (5 > 3 > 1, so {5,50} at top)

    cout << "Pair priority queue (max by first): "
         << pq_pairs.top().first << " " << pq_pairs.top().second << endl; // Prints "5 50"

    // Min heap for pairs
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq_pairs_min;
    pq_pairs_min.push({3, 100}); // Heap -> {{3,100}}
    pq_pairs_min.push({1, 200}); // Heap -> {{1,200}, {3,100}} (1 < 3, so {1,200} at top)
    pq_pairs_min.push({5, 50});  // Heap -> {{1,200}, {3,100}, {5,50}} (1 < 3 < 5)

    cout << "Pair priority queue (min by first): "
         << pq_pairs_min.top().first << " " << pq_pairs_min.top().second << endl; // Prints "1 200"

    cout << "Priority queue size: " << pq_max.size() << endl; // Number of elements in max heap
    cout << "Is empty: " << pq_max.empty() << endl;           // Returns false if heap has elements

    // Time Complexity: push = O(log n), pop = O(log n), top = O(1)
}

// ====================================================================
// 7. SETS - Sorted container with unique elements (Red-Black Tree implementation)
// ====================================================================
void explainSet()
{
    cout << "\n========== SETS ==========\n";

    set<int> st; // Empty set -> {} (automatically maintains sorted order)

    // Inserting elements (duplicates are ignored)
    st.insert(1);  // Set -> {1}
    st.emplace(2); // Set -> {1,2} (emplace is faster than insert)
    st.insert(2);  // Set -> {1,2} (duplicate 2 ignored)
    st.insert(4);  // Set -> {1,2,4} (inserted in sorted position)
    st.insert(3);  // Set -> {1,2,3,4} (inserted in sorted position)
    st.emplace(0); // Set -> {0,1,2,3,4} (inserted at beginning to maintain order)

    cout << "Set contents: ";
    for (auto x : st)     // Prints elements in sorted order
        cout << x << " "; // Output: 0 1 2 3 4
    cout << endl;

    // Finding elements
    auto it = st.find(3); // Returns iterator pointing to element 3
    if (it != st.end())   // Check if element was found (find returns end() if not found)
    {
        cout << "Found element: " << *it << endl; // Dereference iterator to get value -> 3
    }

    // Count function (returns 1 if element exists, 0 if not - since set stores unique elements)
    cout << "Count of 3: " << st.count(3) << endl;   // Returns 1 (element exists)
    cout << "Count of 10: " << st.count(10) << endl; // Returns 0 (element doesn't exist)

    // Erasing elements
    st.erase(2);                // Remove element 2 -> Set becomes {0,1,3,4}
    auto erase_it = st.find(3); // Find element 3
    if (erase_it != st.end())   // Check if found
    {
        st.erase(erase_it); // Remove using iterator -> Set becomes {0,1,4}
    }

    cout << "Set after erasures: ";
    for (auto x : st)     // Print remaining elements
        cout << x << " "; // Output: 0 1 4
    cout << endl;

    // Lower bound and upper bound (useful for range queries)
    set<int> bound_demo = {1, 2, 4, 5, 6, 8, 9}; // Sorted set

    auto lb = bound_demo.lower_bound(5); // Returns iterator to first element >= 5 (points to 5)
    auto ub = bound_demo.upper_bound(5); // Returns iterator to first element > 5 (points to 6)

    cout << "Lower bound of 5: " << *lb << endl; // Prints 5
    cout << "Upper bound of 5: " << *ub << endl; // Prints 6

    cout << "Set size: " << bound_demo.size() << endl;   // Number of elements -> 7
    cout << "Set empty: " << bound_demo.empty() << endl; // Returns false (set has elements)

    // All operations have O(log n) time complexity
}

// ====================================================================
// 8. MULTISETS - Sorted container allowing duplicates
// ====================================================================
void explainMultiSet()
{
    cout << "\n========== MULTISETS ==========\n";

    multiset<int> ms; // Empty multiset -> {} (like set but allows duplicates)

    // Inserting elements (duplicates are allowed)
    ms.insert(1);  // Multiset -> {1}
    ms.insert(1);  // Multiset -> {1,1} (duplicate allowed)
    ms.insert(3);  // Multiset -> {1,1,3}
    ms.insert(2);  // Multiset -> {1,1,2,3} (inserted in sorted position)
    ms.insert(1);  // Multiset -> {1,1,1,2,3}
    ms.emplace(2); // Multiset -> {1,1,1,2,2,3}

    cout << "Multiset contents: ";
    for (auto x : ms)     // Prints all elements including duplicates in sorted order
        cout << x << " "; // Output: 1 1 1 2 2 3
    cout << endl;

    // Count function (returns number of occurrences)
    cout << "Count of 1: " << ms.count(1) << endl; // Returns 3 (three 1's present)
    cout << "Count of 2: " << ms.count(2) << endl; // Returns 2 (two 2's present)

    // Finding elements
    auto it = ms.find(2);             // Returns iterator to first occurrence of 2
    cout << "Found: " << *it << endl; // Prints 2

    // Erasing all occurrences of an element
    ms.erase(1); // Remove ALL occurrences of 1 -> {2,2,3}
    cout << "After erasing all 1's: ";
    for (auto x : ms)
        cout << x << " "; // Output: 2 2 3
    cout << endl;

    // Erasing single occurrence
    ms.insert(2);                // Multiset -> {2,2,2,3}
    auto single_it = ms.find(2); // Find first occurrence of 2
    ms.erase(single_it);         // Remove only that single occurrence -> {2,2,3}

    cout << "After erasing single 2: ";
    for (auto x : ms)
        cout << x << " "; // Output: 2 2 3
    cout << endl;

    // All operations have O(log n) time complexity
}

// ====================================================================
// 9. MAPS - Key-Value pairs in sorted order (Red-Black Tree implementation)
// ====================================================================
void explainMap()
{
    cout << "\n========== MAPS ==========\n";

    map<int, string> mp; // Empty map -> {} (keys sorted automatically)

    // Inserting key-value pairs
    mp[1] = "One";                   // Map -> {1: "One"} (subscript operator)
    mp[3] = "Three";                 // Map -> {1: "One", 3: "Three"}
    mp.insert({2, "Two"});           // Map -> {1: "One", 2: "Two", 3: "Three"} (inserted in sorted order by key)
    mp.emplace(4, "Four");           // Map -> {1: "One", 2: "Two", 3: "Three", 4: "Four"} (emplace is faster)
    mp.insert(make_pair(5, "Five")); // Map -> {1: "One", 2: "Two", 3: "Three", 4: "Four", 5: "Five"}

    cout << "Map contents (sorted by key): " << endl;
    for (auto &pair : mp) // auto& avoids copying pairs
    {
        cout << pair.first << " -> " << pair.second << endl; // pair.first = key, pair.second = value
    }

    // Accessing elements
    cout << "Value at key 2: " << mp[2] << endl;               // Prints "Two" (subscript operator)
    cout << "Value at key 2 (using at): " << mp.at(2) << endl; // Prints "Two" (at() throws exception if key doesn't exist)

    // Safe access using find (recommended way)
    auto it = mp.find(7); // Returns iterator to key 7 (or end() if not found)
    if (it != mp.end())   // Check if key was found
    {
        cout << "Key 7 found: " << it->second << endl; // it->second accesses the value
    }
    else
    {
        cout << "Key 7 not found" << endl; // This will be printed since key 7 doesn't exist
    }

    // Count function (returns 1 if key exists, 0 if not - since map stores unique keys)
    cout << "Count of key 3: " << mp.count(3) << endl;   // Returns 1 (key exists)
    cout << "Count of key 10: " << mp.count(10) << endl; // Returns 0 (key doesn't exist)

    // Erasing elements
    mp.erase(5);          // Remove key 5 and its value -> Map becomes {1: "One", 2: "Two", 3: "Three", 4: "Four"}
    mp.erase(mp.find(4)); // Remove using iterator -> Map becomes {1: "One", 2: "Two", 3: "Three"}

    cout << "Map after erasures: " << endl;
    for (auto &pair : mp) // Print remaining key-value pairs
    {
        cout << pair.first << " -> " << pair.second << endl;
    }

    cout << "Map size: " << mp.size() << endl;   // Number of key-value pairs -> 3
    cout << "Map empty: " << mp.empty() << endl; // Returns false (map has elements)

    // All operations have O(log n) time complexity
}

// ====================================================================
// 9.1 COMPREHENSIVE MAP TYPES - All four map variants with comparisons
// ====================================================================
void explainAllMapTypes()
{
    cout << "\n========== COMPREHENSIVE MAP TYPES ==========\n";

    /* ====================================================================
       There are four main map types in STL:
       1. map               - Ordered unique keys (Red-Black Tree)
       2. unordered_map     - Hashed unique keys (Hash Table)
       3. multimap         - Ordered non-unique keys (Red-Black Tree)
       4. unordered_multimap - Hashed non-unique keys (Hash Table)
       ==================================================================== */

    // 1. map - Ordered unique keys (Red-Black Tree implementation)
    cout << "\n--- 1. map (Ordered Unique Keys) ---\n";
    map<int, string> ordered_map;
    ordered_map[1] = "One";
    ordered_map[3] = "Three";
    ordered_map[2] = "Two";
    ordered_map[1] = "One-modified"; // Overwrites existing key 1

    cout << "map contents (sorted order, unique keys):\n";
    for (auto &pair : ordered_map)
    {
        cout << pair.first << ": " << pair.second << endl; // 1: One-modified, 2: Two, 3: Three
    }
    cout << "Duplicate key 1 was overwritten\n";

    // 2. unordered_map - Hashed unique keys (Hash Table implementation)
    cout << "\n--- 2. unordered_map (Hashed Unique Keys) ---\n";
    unordered_map<int, string> unordered_map_ex;
    unordered_map_ex[1] = "One";
    unordered_map_ex[3] = "Three";
    unordered_map_ex[2] = "Two";
    unordered_map_ex[1] = "One-modified"; // Overwrites existing key 1

    cout << "unordered_map contents (unsorted order, unique keys):\n";
    for (auto &pair : unordered_map_ex)
    {
        cout << pair.first << ": " << pair.second << endl; // Order not guaranteed
    }
    cout << "Average O(1) operations, worst case O(n)\n";

    // 3. multimap - Ordered non-unique keys (Red-Black Tree implementation)
    cout << "\n--- 3. multimap (Ordered Non-Unique Keys) ---\n";
    multimap<int, string> multi_map;
    multi_map.insert({1, "One"});
    multi_map.insert({3, "Three"});
    multi_map.insert({2, "Two"});
    multi_map.insert({1, "One-again"}); // Keeps both entries for key 1

    cout << "multimap contents (sorted order, duplicate keys allowed):\n";
    for (auto &pair : multi_map)
    {
        cout << pair.first << ": " << pair.second << endl; // 1: One, 1: One-again, 2: Two, 3: Three
    }
    cout << "Count of key 1: " << multi_map.count(1) << endl; // Returns 2

    // 4. unordered_multimap - Hashed non-unique keys (Hash Table implementation)
    cout << "\n--- 4. unordered_multimap (Hashed Non-Unique Keys) ---\n";
    unordered_multimap<int, string> unordered_multi;
    unordered_multi.insert({1, "One"});
    unordered_multi.insert({3, "Three"});
    unordered_multi.insert({2, "Two"});
    unordered_multi.insert({1, "One-duplicate"});

    cout << "unordered_multimap contents (unsorted order, duplicates allowed):\n";
    for (auto &pair : unordered_multi)
    {
        cout << pair.first << ": " << pair.second << endl; // Order not guaranteed
    }
    cout << "Count of key 1: " << unordered_multi.count(1) << endl; // Returns 2

    /* ====================================================================
       KEY DIFFERENCES AND WHEN TO USE EACH:

       1. map (ordered, unique keys):
          - Keys are sorted automatically
          - No duplicate keys allowed (inserting same key overwrites value)
          - O(log n) operations
          - Use when you need ordered traversal or predecessor/successor lookups

       2. unordered_map (hashed, unique keys):
          - Keys are not ordered
          - No duplicate keys allowed
          - Average O(1) operations, worst case O(n)
          - Use when order doesn't matter and you need fastest access
          - Requires hash function for key type

       3. multimap (ordered, non-unique keys):
          - Keys are sorted automatically
          - Allows duplicate keys (multiple values for same key)
          - O(log n) operations
          - Use when you need ordered traversal with duplicate keys

       4. unordered_multimap (hashed, non-unique keys):
          - Keys are not ordered
          - Allows duplicate keys
          - Average O(1) operations, worst case O(n)
          - Use when order doesn't matter but duplicates are needed
          - Requires hash function for key type

       DUPLICATE KEY BEHAVIOR:
       - map/unordered_map: Inserting same key overwrites existing value
       - multimap/unordered_multimap: Inserting same key adds new entry

       MEMORY USAGE:
       - Ordered versions (map/multimap) use more memory per element
       - Unordered versions have memory overhead for hash table

       ITERATOR VALIDITY:
       - Ordered versions: Iterators remain valid unless element is erased
       - Unordered versions: Rehashing may invalidate iterators
       ==================================================================== */

    // Practical example showing lookup differences
    cout << "\n--- Practical Lookup Example ---\n";

    // Ordered map lookup
    auto map_it = ordered_map.lower_bound(2);
    cout << "map lower_bound(2): " << map_it->first << "->" << map_it->second << endl;

    // Unordered map lookup (no ordered operations)
    auto unordered_it = unordered_map_ex.find(2);
    if (unordered_it != unordered_map_ex.end())
    {
        cout << "unordered_map find(2): " << unordered_it->first << "->" << unordered_it->second << endl;
    }

    // Multimap equal range (handling duplicates)
    auto range = multi_map.equal_range(1);
    cout << "multimap values for key 1: ";
    for (auto it = range.first; it != range.second; ++it)
    {
        cout << it->second << " ";
    }
    cout << endl;

    // Performance comparison
    cout << "\n--- Performance Characteristics ---\n";
    cout << "Ordered maps (map/multimap):\n";
    cout << "- Insert: O(log n)\n";
    cout << "- Lookup: O(log n)\n";
    cout << "- Ordered operations: Yes\n";
    cout << "- Memory: Higher\n\n";

    cout << "Unordered maps (unordered_map/unordered_multimap):\n";
    cout << "- Insert: O(1) avg, O(n) worst\n";
    cout << "- Lookup: O(1) avg, O(n) worst\n";
    cout << "- Ordered operations: No\n";
    cout << "- Memory: Lower (but has overhead)\n";
}

// ====================================================================
// 10. STRING OPERATIONS - Comprehensive string manipulation
// ====================================================================
void explainStringOperations()
{
    cout << "\n========== STRING OPERATIONS ==========\n";

    string s = "Hello, World!"; // Initialize string -> "Hello, World!"
    cout << "Original string: " << s << endl;

    // Basic properties
    cout << "Length: " << s.length() << " or " << s.size() << endl; // Both return same value -> 13
    cout << "Capacity: " << s.capacity() << endl;                   // Current allocated memory capacity
    cout << "Empty: " << s.empty() << endl;                         // Returns false (string has characters)

    // Character access
    cout << "First char: " << s[0] << " or " << s.at(0) << endl; // Both access first character -> 'H'
    cout << "Last char: " << s.back() << endl;                   // Returns reference to last character -> '!'
    cout << "Front char: " << s.front() << endl;                 // Returns reference to first character -> 'H'

    // Substring operations
    string sub = s.substr(7, 5); // Extract 5 characters starting from index 7 -> "World"
    cout << "Substring(7, 5): " << sub << endl;

    string sub2 = s.substr(7); // Extract from index 7 to end -> "World!"
    cout << "Substring(7): " << sub2 << endl;

    // Finding substrings
    size_t pos = s.find("World"); // Find first occurrence of "World" -> returns position 7
    if (pos != string::npos)      // string::npos means "not found"
    {
        cout << "Found 'World' at position: " << pos << endl;
    }

    size_t last_pos = s.rfind("l"); // Find last occurrence of 'l' -> returns position 10
    cout << "Last 'l' at position: " << last_pos << endl;

    // String modification
    string modify = "Hello, World!"; // Create copy for modification -> "Hello, World!"
    modify.replace(7, 5, "C++");     // Replace 5 characters starting at position 7 with "C++" -> "Hello, C++!"
    cout << "After replace: " << modify << endl;

    modify.insert(10, " Programming"); // Insert " Programming" at position 10 -> "Hello, C++ Programming!"
    cout << "After insert: " << modify << endl;

    modify.erase(10, 12); // Remove 12 characters starting at position 10 -> "Hello, C++!"
    cout << "After erase: " << modify << endl;

    // Append operations
    modify.append(" Language"); // Add " Language" to end -> "Hello, C++! Language"
    modify += " Rocks";         // Append using += operator -> "Hello, C++! Language Rocks"
    modify.push_back('!');      // Add single character to end -> "Hello, C++! Language Rocks!"
    cout << "After appends: " << modify << endl;

    // String comparison
    string a = "apple", b = "banana";                                // Two strings for comparison
    cout << "Compare 'apple' vs 'banana': " << a.compare(b) << endl; // Returns negative value since "apple" < "banana" lexicographically
    cout << "a < b: " << (a < b) << endl;                            // Returns true (lexicographical comparison)
    cout << "a == b: " << (a == b) << endl;                          // Returns false (strings are different)

    // Case conversion (requires algorithm header)
    string case_demo = "Hello World";                                            // Original string -> "Hello World"
    transform(case_demo.begin(), case_demo.end(), case_demo.begin(), ::tolower); // Convert all to lowercase -> "hello world"
    cout << "Lowercase: " << case_demo << endl;

    transform(case_demo.begin(), case_demo.end(), case_demo.begin(), ::toupper); // Convert all to uppercase -> "HELLO WORLD"
    cout << "Uppercase: " << case_demo << endl;

    // String to number conversions
    string num_str = "12345"; // String containing digits
    int num = stoi(num_str);  // Convert string to integer -> 12345
    cout << "String to int: " << num << endl;

    string float_str = "123.45";        // String containing decimal number
    double num_float = stod(float_str); // Convert string to double -> 123.45
    cout << "String to double: " << num_float << endl;

    // Number to string
    string from_num = to_string(num); // Convert integer to string -> "12345"
    cout << "Int to string: " << from_num << endl;

    // Check if string is palindrome
    string palindrome = "racecar";                                                    // Test string
    string temp = palindrome;                                                         // Create copy
    reverse(temp.begin(), temp.end());                                                // Reverse the copy -> "racecar"
    cout << "Is '" << palindrome << "' palindrome: " << (palindrome == temp) << endl; // Compare original with reversed -> true
}

// ====================================================================
// 11. ALGORITHMS - Comprehensive algorithm demonstrations
// ====================================================================
void explainAlgorithms()
{
    cout << "\n========== ALGORITHMS ==========\n";

    // SORTING ALGORITHMS
    vector<int> v = {45, 12, 96, 14, 2, 7, 56, 23}; // Unsorted vector
    cout << "Original vector: ";
    for (int x : v)
        cout << x << " "; // Output: 45 12 96 14 2 7 56 23
    cout << endl;

    // Basic sorting
    sort(v.begin(), v.end()); // Sort in ascending order using quicksort (average O(n log n))
    cout << "Sorted ascending: ";
    for (int x : v)
        cout << x << " "; // Output: 2 7 12 14 23 45 56 96
    cout << endl;

    // Descending sort
    sort(v.begin(), v.end(), greater<int>()); // Sort in descending order using custom comparator
    cout << "Sorted descending: ";
    for (int x : v)
        cout << x << " "; // Output: 96 56 45 23 14 12 7 2
    cout << endl;

    // SEARCHING ALGORITHMS (require sorted array)
    vector<int> search_demo = {1, 3, 5, 7, 9, 11, 13}; // Sorted array for binary search

    // Binary search (O(log n) time complexity)
    bool found = binary_search(search_demo.begin(), search_demo.end(), 7);      // Search for element 7
    cout << "Binary search for 7: " << (found ? "Found" : "Not found") << endl; // Returns true

    // Lower bound and upper bound
    auto lb = lower_bound(search_demo.begin(), search_demo.end(), 7);   // First position where 7 can be inserted to maintain sorted order
    auto ub = upper_bound(search_demo.begin(), search_demo.end(), 7);   // First position after 7 where element can be inserted
    cout << "Lower bound of 7: " << (lb - search_demo.begin()) << endl; // Returns index 3 (position of 7)
    cout << "Upper bound of 7: " << (ub - search_demo.begin()) << endl; // Returns index 4 (position after 7)

    // PERMUTATION ALGORITHMS
    string perm = "ABC"; // String to generate permutations
    cout << "All permutations of " << perm << ":" << endl;
    sort(perm.begin(), perm.end()); // Ensure string is in lexicographically smallest order first
    do
    {
        cout << perm << " "; // Print current permutation
    } while (next_permutation(perm.begin(), perm.end())); // Generate next lexicographically greater permutation
    cout << endl; // Output: ABC ACB BAC BCA CAB CBA

    // MIN/MAX ALGORITHMS
    vector<int> minmax_demo = {12, 5, 7, 31, 2, 1, 45}; // Test vector

    auto min_it = min_element(minmax_demo.begin(), minmax_demo.end()); // Iterator to minimum element
    auto max_it = max_element(minmax_demo.begin(), minmax_demo.end()); // Iterator to maximum element

    cout << "Min element: " << *min_it << " at index " << (min_it - minmax_demo.begin()) << endl; // Min: 1 at index 5
    cout << "Max element: " << *max_it << " at index " << (max_it - minmax_demo.begin()) << endl; // Max: 45 at index 6

    // Reverse algorithm
    vector<int> algo_demo = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // Original: 1 2 3 4 5 6 7 8 9 10
    reverse(algo_demo.begin(), algo_demo.end());             // Reverse entire vector -> 10 9 8 7 6 5 4 3 2 1
    cout << "Reversed: ";
    for (int x : algo_demo)
        cout << x << " ";
    cout << endl;

    // Count occurrences
    vector<int> count_demo = {1, 2, 3, 2, 2, 4, 5, 2};            // Vector with duplicates
    int count_2 = count(count_demo.begin(), count_demo.end(), 2); // Count occurrences of 2 -> 4
    cout << "Count of 2's: " << count_2 << endl;

    // Count with condition using lambda
    int count_even = count_if(count_demo.begin(), count_demo.end(),
                              [](int x)
                              { return x % 2 == 0; });       // Count even numbers
    cout << "Count of even numbers: " << count_even << endl; // Count: 5 (2,2,2,4,2)
}

// ====================================================================
// 12. PRACTICAL EXAMPLES - Real-world problem solving
// ====================================================================
void explainPracticalExamples()
{
    cout << "\n========== PRACTICAL EXAMPLES ==========\n";

    // 1. TWO SUM PROBLEM - Find two numbers that add up to target
    cout << "--- Two Sum Problem ---" << endl;
    vector<int> nums = {2, 7, 11, 15}; // Input array
    int target = 9;                    // Target sum
    unordered_map<int, int> num_map;   // Map to store {value -> index}

    cout << "Array: ";
    for (int x : nums)
        cout << x << " ";
    cout << ", Target: " << target << endl;

    for (int i = 0; i < nums.size(); i++) // Iterate through array
    {
        int complement = target - nums[i];             // Calculate required complement
        if (num_map.find(complement) != num_map.end()) // Check if complement exists in map
        {
            cout << "Two sum indices: " << num_map[complement] << ", " << i << endl;         // Indices: 0, 1
            cout << "Values: " << complement << " + " << nums[i] << " = " << target << endl; // Values: 2 + 7 = 9
            break;
        }
        num_map[nums[i]] = i; // Store current number and its index
    }

    // 2. FREQUENCY COUNTING - Count frequency of each character
    cout << "\n--- Frequency Analysis ---" << endl;
    string text = "hello world programming"; // Input text

    unordered_map<char, int> char_freq; // Map to store character frequencies
    for (char c : text)                 // Iterate through each character
    {
        if (c != ' ') // Skip spaces
        {
            char_freq[c]++; // Increment frequency count
        }
    }

    cout << "Character frequencies:" << endl;
    for (auto &pair : char_freq) // Print frequency of each character
    {
        cout << "'" << pair.first << "': " << pair.second << endl;
    }

    // 3. ADJACENCY LIST - Graph representation
    cout << "\n--- Graph Adjacency List ---" << endl;
    int vertices = 5;                       // Number of vertices in graph
    vector<vector<int>> adj_list(vertices); // Create adjacency list (vector of vectors)

    // Add edges: 0-1, 0-2, 1-3, 2-4, 3-4
    adj_list[0] = {1, 2}; // Vertex 0 connected to vertices 1 and 2
    adj_list[1] = {0, 3}; // Vertex 1 connected to vertices 0 and 3
    adj_list[2] = {0, 4}; // Vertex 2 connected to vertices 0 and 4
    adj_list[3] = {1, 4}; // Vertex 3 connected to vertices 1 and 4
    adj_list[4] = {2, 3}; // Vertex 4 connected to vertices 2 and 3

    cout << "Adjacency List:" << endl;
    for (int i = 0; i < vertices; i++) // Print adjacency list for each vertex
    {
        cout << i << " -> ";
        for (int neighbor : adj_list[i]) // Print all neighbors of vertex i
        {
            cout << neighbor << " ";
        }
        cout << endl;
    }

    // 4. PRIORITY QUEUE APPLICATION - Find top K frequent elements
    cout << "\n--- Top K Elements ---" << endl;
    vector<int> elements = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5}; // Input array
    unordered_map<int, int> freq_map;                         // Map to store element frequencies

    for (int num : elements) // Count frequency of each element
    {
        freq_map[num]++;
    }

    priority_queue<pair<int, int>> freq_pq; // Max heap to store {frequency, element}
    for (auto &entry : freq_map)            // Add all {frequency, element} pairs to heap
    {
        freq_pq.push({entry.second, entry.first}); // Push {frequency, element}
    }

    int k = 3; // Find top 3 frequent elements
    cout << "Top " << k << " frequent elements:" << endl;
    while (k-- && !freq_pq.empty()) // Extract top k elements
    {
        auto top = freq_pq.top(); // Get element with highest frequency
        cout << "Element " << top.second << " appears " << top.first << " times" << endl;
        freq_pq.pop(); // Remove from heap
    }
}

// ====================================================================
// 13. PERFORMANCE TIPS - Best practices and optimization guidelines
// ====================================================================
void explainPerformanceTips()
{
    cout << "\n========== PERFORMANCE TIPS ==========\n";

    cout << "CONTAINER SELECTION GUIDE:" << endl;
    cout << "- Random access needed: vector, deque, array" << endl;             // O(1) access by index
    cout << "- Frequent front/back insertion: deque" << endl;                   // O(1) insertion at both ends
    cout << "- Frequent middle insertion: list" << endl;                        // O(1) insertion anywhere if iterator available
    cout << "- Unique sorted elements: set" << endl;                            // Automatic sorting + uniqueness
    cout << "- Key-value with sorted keys: map" << endl;                        // Sorted key-value pairs
    cout << "- Fast lookup, don't care about order: unordered_set/map" << endl; // Average O(1) operations
    cout << "- LIFO operations: stack" << endl;                                 // Last In First Out
    cout << "- FIFO operations: queue" << endl;                                 // First In First Out
    cout << "- Priority-based access: priority_queue" << endl;                  // Heap-based priority access

    cout << "\nTIME COMPLEXITY REFERENCE:" << endl;
    cout << "vector: access O(1), insert/erase O(n), push_back O(1) amortized" << endl;
    cout << "list: insert/erase O(1), access O(n)" << endl;
    cout << "deque: access O(1), front/back insert O(1), middle insert O(n)" << endl;
    cout << "map/set: all operations O(log n)" << endl;
    cout << "unordered_map/set: all operations O(1) average, O(n) worst" << endl;
    cout << "priority_queue: push/pop O(log n), top O(1)" << endl;

    cout << "\nBEST PRACTICES:" << endl;
    cout << "1. Use const auto& in range-based loops to avoid copying" << endl; // Avoids unnecessary copying of objects
    cout << "2. Reserve memory for vectors when size is known" << endl;         // Prevents multiple reallocations
    cout << "3. Use emplace instead of push for better performance" << endl;    // Constructs objects in place
    cout << "4. Prefer algorithms over manual loops" << endl;                   // Often more optimized and readable
    cout << "5. Use appropriate container for your use case" << endl;           // Different containers excel at different operations
    cout << "6. Be aware of iterator invalidation rules" << endl;               // Operations that invalidate iterators
}

// ====================================================================
// 14. ADVANCED STL CONTAINERS - Less commonly used but powerful
// ====================================================================
void explainAdvancedContainers()
{
    cout << "\n========== ADVANCED CONTAINERS ==========\n";

    // UNORDERED_MAP - Hash table implementation
    cout << "--- Unordered Map ---" << endl;
    unordered_map<string, int> umap; // Hash table with string keys, int values
    umap["apple"] = 10;              // Insert using subscript -> {"apple": 10}
    umap["banana"] = 5;              // umap -> {"apple": 10, "banana": 5}
    umap["orange"] = 7;              // umap -> {"apple": 10, "banana": 5, "orange": 7}
    umap.insert({"grape", 12});      // Insert using pair -> adds {"grape": 12}
    umap.emplace("mango", 8);        // Emplace (faster) -> adds {"mango": 8}

    cout << "Unordered map contents:" << endl; // Order is not guaranteed (hash table)
    for (auto &pair : umap)
    {
        cout << pair.first << " -> " << pair.second << endl;
    }

    // UNORDERED_SET - Hash table for unique elements
    cout << "\n--- Unordered Set ---" << endl;
    unordered_set<int> uset; // Hash table storing unique integers
    uset.insert(1);          // uset -> {1}
    uset.insert(4);          // uset -> {1, 4} (order not guaranteed)
    uset.insert(2);          // uset -> {1, 4, 2}
    uset.insert(3);          // uset -> {1, 4, 2, 3}
    uset.insert(2);          // uset -> {1, 4, 2, 3} (duplicate ignored)

    cout << "Unordered set contents: ";
    for (int x : uset) // Order is not guaranteed
        cout << x << " ";
    cout << endl;

    // DEQUE - Double-ended queue
    cout << "\n--- Deque ---" << endl;
    deque<int> dq;    // Empty deque -> {}
    dq.push_back(2);  // Add to back -> {2}
    dq.push_front(1); // Add to front -> {1, 2}
    dq.push_back(3);  // Add to back -> {1, 2, 3}
    dq.push_front(0); // Add to front -> {0, 1, 2, 3}

    cout << "Deque contents: ";
    for (auto x : dq)
        cout << x << " "; // Output: 0 1 2 3
    cout << endl;

    cout << "Element at index 2: " << dq[2] << endl;                    // Random access like vector -> 2
    cout << "Front: " << dq.front() << ", Back: " << dq.back() << endl; // front: 0, back: 3

    // MULTIMAP - Map allowing duplicate keys
    cout << "\n--- Multimap ---" << endl;
    multimap<int, string> mmp; // Map that allows duplicate keys
    mmp.insert({1, "apple"});  // mmp -> {1: "apple"}
    mmp.insert({2, "banana"}); // mmp -> {1: "apple", 2: "banana"}
    mmp.insert({1, "orange"}); // mmp -> {1: "apple", 1: "orange", 2: "banana"} (duplicate key allowed)
    mmp.insert({3, "grape"});  // mmp -> {1: "apple", 1: "orange", 2: "banana", 3: "grape"}
    mmp.insert({2, "pear"});   // mmp -> {1: "apple", 1: "orange", 2: "banana", 2: "pear", 3: "grape"}

    cout << "Multimap contents:" << endl;
    for (auto &pair : mmp) // Sorted by key, duplicates allowed
    {
        cout << pair.first << " -> " << pair.second << endl;
    }

    cout << "Count of key 1: " << mmp.count(1) << endl; // Returns 2 (two entries with key 1)

    // Get all elements with a specific key
    cout << "All elements with key 1:" << endl;
    auto range = mmp.equal_range(1);                      // Returns pair of iterators defining range of elements with key 1
    for (auto it = range.first; it != range.second; ++it) // Iterate through all elements with key 1
    {
        cout << it->first << " -> " << it->second << endl;
    }
}

// ====================================================================
// 15. BIT MANIPULATION - Working with individual bits
// ====================================================================
void explainBitManipulation()
{
    cout << "\n========== BIT MANIPULATION ==========\n";

    // Count set bits (number of 1's in binary representation)
    int num = 7;                         // Binary: 111
    int count = __builtin_popcount(num); // GCC builtin function to count 1's -> returns 3
    cout << "Number of set bits in " << num << ": " << count << endl;

    // For long long numbers
    long long big_num = 15;                        // Binary: 1111
    int big_count = __builtin_popcountll(big_num); // For long long, use popcountll -> returns 4
    cout << "Set bits in " << big_num << ": " << big_count << endl;

    // Count leading zeros
    int clz = __builtin_clz(8); // 8 = 00000000000000000000000000001000 (32-bit), leading zeros = 28
    cout << "Leading zeros in 8: " << clz << endl;

    // Count trailing zeros
    int ctz = __builtin_ctz(8); // 8 = 1000, trailing zeros = 3
    cout << "Trailing zeros in 8: " << ctz << endl;

    // Check if number is power of 2
    cout << "Is " << num << " power of 2: " << ((num & (num - 1)) == 0 && num > 0) << endl;
    // Logic: Powers of 2 have only one set bit, so n & (n-1) == 0

    // Basic bit operations
    int a = 5, b = 3;                           // a = 101, b = 011 in binary
    cout << "a & b (AND): " << (a & b) << endl; // 101 & 011 = 001 = 1
    cout << "a | b (OR): " << (a | b) << endl;  // 101 | 011 = 111 = 7
    cout << "a ^ b (XOR): " << (a ^ b) << endl; // 101 ^ 011 = 110 = 6

    // Individual bit operations
    int x = 5;   // Binary: 101
    int pos = 1; // Position to manipulate (0-indexed from right)
    cout << "Original x: " << x << endl;

    x |= (1 << pos); // Set bit at position 1: 101 | 010 = 111 = 7
    cout << "After setting bit 1: " << x << endl;

    x &= ~(1 << pos); // Clear bit at position 1: 111 & 101 = 101 = 5
    cout << "After clearing bit 1: " << x << endl;

    x ^= (1 << pos); // Toggle bit at position 1: 101 ^ 010 = 111 = 7
    cout << "After toggling bit 1: " << x << endl;

    bool is_set = (x >> pos) & 1; // Check if bit at position 1 is set: (111 >> 1) & 1 = 11 & 1 = 1 = true
    cout << "Is bit 1 set: " << is_set << endl;
}

// ====================================================================
// 16. LAMBDA FUNCTIONS - Anonymous functions for custom operations
// ====================================================================
void explainLambdaFunctions()
{
    cout << "\n========== LAMBDA FUNCTIONS ==========\n";

    vector<int> v = {5, 2, 8, 1, 9, 3}; // Test vector

    // Basic lambda function
    auto add = [](int a, int b)
    { return a + b; };                                 // Lambda that adds two numbers
    cout << "Lambda add(3, 4): " << add(3, 4) << endl; // Call lambda -> returns 7

    // Lambda with capture (capturing variables from surrounding scope)
    int multiplier = 3; // Variable to capture
    auto multiply_by = [multiplier](int x)
    { return x * multiplier; };                                         // Capture multiplier by value
    cout << "Multiply 5 by captured value: " << multiply_by(5) << endl; // Returns 5 * 3 = 15

    // Using lambdas with STL algorithms
    sort(v.begin(), v.end(), [](int a, int b)
         { return a > b; }); // Sort in descending order using lambda comparator
    cout << "Sorted descending: ";
    for (int x : v)
        cout << x << " "; // Output: 9 8 5 3 2 1
    cout << endl;

    // Find with lambda
    auto it = find_if(v.begin(), v.end(), [](int x)
                      { return x > 5; }); // Find first element > 5
    if (it != v.end())
    {
        cout << "First element > 5: " << *it << endl; // Returns 9 (first element > 5)
    }

    // Count with lambda
    int count_even = count_if(v.begin(), v.end(), [](int x)
                              { return x % 2 == 0; });       // Count even numbers
    cout << "Count of even numbers: " << count_even << endl; // Count of even numbers in vector

    // Transform with lambda
    vector<int> doubled(v.size()); // Vector to store doubled values
    transform(v.begin(), v.end(), doubled.begin(), [](int x)
              { return x * 2; }); // Double each element
    cout << "Doubled values: ";
    for (int x : doubled)
        cout << x << " "; // Each element doubled
    cout << endl;
}

// ====================================================================
// 17. ADVANCED ALGORITHMS - More complex algorithmic operations
// ====================================================================
void explainAdvancedAlgorithms()
{
    cout << "\n========== ADVANCED ALGORITHMS ==========\n";

    vector<int> source = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // Source vector

    // TRANSFORM - Apply operation to each element
    vector<int> squares(source.size()); // Destination vector for squares
    transform(source.begin(), source.end(), squares.begin(),
              [](int x)
              { return x * x; }); // Square each element
    cout << "Squares: ";
    for (int x : squares)
        cout << x << " "; // Output: 1 4 9 16 25 36 49 64 81 100
    cout << endl;

    // COPY_IF - Copy elements that satisfy condition
    vector<int> evens; // Vector to store even numbers
    copy_if(source.begin(), source.end(), back_inserter(evens),
            [](int x)
            { return x % 2 == 0; }); // Copy only even numbers
    cout << "Even numbers: ";
    for (int x : evens)
        cout << x << " "; // Output: 2 4 6 8 10
    cout << endl;

    // REMOVE - Move elements to end (doesn't actually erase)
    vector<int> remove_demo = {1, 2, 3, 2, 4, 2, 5}; // Vector with duplicates
    cout << "Before remove: ";
    for (int x : remove_demo)
        cout << x << " "; // Output: 1 2 3 2 4 2 5
    cout << endl;

    auto new_end = remove(remove_demo.begin(), remove_demo.end(), 2); // Move all 2's to end, return iterator to new end
    remove_demo.erase(new_end, remove_demo.end());                    // Actually remove the moved elements
    cout << "After removing 2's: ";
    for (int x : remove_demo)
        cout << x << " "; // Output: 1 3 4 5 (all 2's removed)
    cout << endl;

    // UNIQUE - Remove consecutive duplicates
    vector<int> unique_demo = {1, 1, 2, 2, 2, 3, 3, 4, 5, 5}; // Vector with consecutive duplicates
    cout << "Before unique: ";
    for (int x : unique_demo)
        cout << x << " "; // Output: 1 1 2 2 2 3 3 4 5 5
    cout << endl;

    auto unique_end = unique(unique_demo.begin(), unique_demo.end()); // Remove consecutive duplicates
    unique_demo.erase(unique_end, unique_demo.end());                 // Erase the "removed" elements
    cout << "After unique: ";
    for (int x : unique_demo)
        cout << x << " "; // Output: 1 2 3 4 5 (consecutive duplicates removed)
    cout << endl;

    // REPLACE - Replace all occurrences of a value
    vector<int> replace_demo = {1, 2, 3, 2, 4, 2, 5};         // Vector with multiple 2's
    replace(replace_demo.begin(), replace_demo.end(), 2, 99); // Replace all 2's with 99
    cout << "After replace(2, 99): ";
    for (int x : replace_demo)
        cout << x << " "; // Output: 1 99 3 99 4 99 5
    cout << endl;

    // ACCUMULATE - Reduce vector to single value
    vector<int> numbers = {1, 2, 3, 4, 5};                   // Numbers to accumulate
    int sum = accumulate(numbers.begin(), numbers.end(), 0); // Sum all elements starting from 0
    cout << "Sum of numbers: " << sum << endl;               // Output: 15 (1+2+3+4+5)

    // Accumulate with custom operation
    int product = accumulate(numbers.begin(), numbers.end(), 1, multiplies<int>()); // Multiply all elements starting from 1
    cout << "Product of numbers: " << product << endl;                              // Output: 120 (1*2*3*4*5)
}

// ====================================================================
// 18. SET OPERATIONS - Mathematical set operations on sorted ranges
// ====================================================================
void explainSetOperations()
{
    cout << "\n========== SET OPERATIONS ==========\n";

    vector<int> set1 = {1, 2, 3, 4, 5}; // First sorted set
    vector<int> set2 = {3, 4, 5, 6, 7}; // Second sorted set

    // Ensure vectors are sorted (required for set operations)
    sort(set1.begin(), set1.end()); // set1: {1, 2, 3, 4, 5}
    sort(set2.begin(), set2.end()); // set2: {3, 4, 5, 6, 7}

    cout << "Set 1: ";
    for (int x : set1)
        cout << x << " ";
    cout << endl;

    cout << "Set 2: ";
    for (int x : set2)
        cout << x << " ";
    cout << endl;

    // SET UNION - All elements from both sets
    vector<int> union_result; // Vector to store union result
    set_union(set1.begin(), set1.end(), set2.begin(), set2.end(),
              back_inserter(union_result)); // Union: all unique elements from both sets
    cout << "Union: ";
    for (int x : union_result)
        cout << x << " "; // Output: 1 2 3 4 5 6 7
    cout << endl;

    // SET INTERSECTION - Common elements in both sets
    vector<int> intersection_result; // Vector to store intersection result
    set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(),
                     back_inserter(intersection_result)); // Intersection: elements present in both sets
    cout << "Intersection: ";
    for (int x : intersection_result)
        cout << x << " "; // Output: 3 4 5
    cout << endl;

    // SET DIFFERENCE - Elements in first set but not in second
    vector<int> difference_result; // Vector to store difference result
    set_difference(set1.begin(), set1.end(), set2.begin(), set2.end(),
                   back_inserter(difference_result)); // Difference: elements in set1 but not in set2
    cout << "Difference (set1 - set2): ";
    for (int x : difference_result)
        cout << x << " "; // Output: 1 2
    cout << endl;
}

// ====================================================================
// 19. COMPLEX DATA STRUCTURES - Nested and advanced combinations
// ====================================================================
void explainComplexDataStructures()
{
    cout << "\n========== COMPLEX DATA STRUCTURES ==========\n";

    // 2D VECTOR - Matrix representation
    cout << "--- 2D Vector ---" << endl;
    vector<vector<int>> matrix(3, vector<int>(4, 0)); // 3x4 matrix initialized with zeros
    matrix[1][2] = 5;                                 // Set element at row 1, column 2 to 5
    matrix[0][1] = 3;                                 // Set element at row 0, column 1 to 3

    cout << "2D Vector (matrix):" << endl;
    for (int i = 0; i < matrix.size(); i++) // Iterate through rows
    {
        for (int j = 0; j < matrix[i].size(); j++) // Iterate through columns
        {
            cout << matrix[i][j] << " "; // Print each element
        }
        cout << endl;
    }

    // VECTOR OF PAIRS - Storing related data together
    cout << "\n--- Vector of Pairs ---" << endl;
    vector<pair<string, int>> name_age = {// Vector storing name-age pairs
                                          {"Alice", 25},
                                          {"Bob", 30},
                                          {"Charlie", 35}};

    // Sort by age (second element of pair)
    sort(name_age.begin(), name_age.end(),
         [](const pair<string, int> &a, const pair<string, int> &b)
         {
             return a.second < b.second; // Compare by age (second element)
         });

    cout << "Sorted by age:" << endl;
    for (auto &person : name_age) // Print sorted pairs
    {
        cout << person.first << ": " << person.second << endl;
    }

    // MAP OF VECTORS - Categorizing data
    cout << "\n--- Map of Vectors ---" << endl;
    map<string, vector<int>> category_map;    // Map where each key points to a vector
    category_map["even"] = {2, 4, 6, 8, 10};  // Category "even" contains even numbers
    category_map["odd"] = {1, 3, 5, 7, 9};    // Category "odd" contains odd numbers
    category_map["prime"] = {2, 3, 5, 7, 11}; // Category "prime" contains prime numbers

    cout << "Map of vectors:" << endl;
    for (auto &entry : category_map) // Iterate through each category
    {
        cout << entry.first << ": "; // Print category name
        for (int num : entry.second) // Print all numbers in that category
        {
            cout << num << " ";
        }
        cout << endl;
    }

    // PRIORITY QUEUE WITH CUSTOM COMPARATOR
    cout << "\n--- Custom Priority Queue ---" << endl;
    auto cmp = [](pair<int, string> a, pair<int, string> b)
    {
        return a.first < b.first; // Max heap based on first element (number)
    };
    priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(cmp)> custom_pq(cmp);

    custom_pq.push({3, "Three"}); // Insert {3, "Three"}
    custom_pq.push({1, "One"});   // Insert {1, "One"}
    custom_pq.push({5, "Five"});  // Insert {5, "Five"}
    custom_pq.push({2, "Two"});   // Insert {2, "Two"}

    cout << "Custom priority queue (max heap by number):" << endl;
    while (!custom_pq.empty()) // Extract all elements in priority order
    {
        auto top = custom_pq.top();                        // Get highest priority element
        cout << top.first << " -> " << top.second << endl; // Print number -> word
        custom_pq.pop();                                   // Remove from queue
    }
}

// ====================================================================
// 20. FINAL COMPREHENSIVE EXAMPLES - Advanced problem-solving patterns
// ====================================================================
void explainFinalExamples()
{
    cout << "\n========== FINAL COMPREHENSIVE EXAMPLES ==========\n";

    // EXAMPLE 1: GROUP ANAGRAMS - Group words that are anagrams of each other
    cout << "--- Group Anagrams ---" << endl;
    vector<string> words = {"eat", "tea", "tan", "ate", "nat", "bat"}; // Input words
    map<string, vector<string>> anagram_groups;                        // Map: sorted_word -> list of anagrams

    for (string word : words) // Process each word
    {
        string sorted_word = word;                    // Create copy for sorting
        sort(sorted_word.begin(), sorted_word.end()); // Sort characters
        anagram_groups[sorted_word].push_back(word);  // Group by sorted form
    }

    cout << "Anagram groups:" << endl;
    for (auto &group : anagram_groups) // Print each group
    {
        cout << "Group: ";
        for (string word : group.second) // Print all words in group
        {
            cout << word << " ";
        }
        cout << endl;
    }

    // EXAMPLE 2: MERGE INTERVALS - Merge overlapping intervals
    cout << "\n--- Merge Intervals ---" << endl;
    vector<pair<int, int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}}; // Input intervals

    sort(intervals.begin(), intervals.end()); // Sort by start time: {1,3}, {2,6}, {8,10}, {15,18}

    vector<pair<int, int>> merged;  // Vector to store merged intervals
    for (auto interval : intervals) // Process each interval
    {
        if (merged.empty() || merged.back().second < interval.first) // No overlap
        {
            merged.push_back(interval); // Add new interval
        }
        else // Overlap detected
        {
            merged.back().second = max(merged.back().second, interval.second); // Merge intervals
        }
    }

    cout << "Original intervals: ";
    for (auto &p : intervals)
        cout << "[" << p.first << "," << p.second << "] ";
    cout << endl;

    cout << "Merged intervals: ";
    for (auto &p : merged)
        cout << "[" << p.first << "," << p.second << "] "; // Output: [1,6] [8,10] [15,18]
    cout << endl;

    // EXAMPLE 3: SLIDING WINDOW MAXIMUM - Find maximum in each sliding window
    cout << "\n--- Sliding Window Maximum ---" << endl;
    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7}; // Input array
    int window_size = 3;                          // Window size
    deque<int> dq;                                // Deque to store indices (maintains decreasing order of values)

    cout << "Array: ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    cout << "Sliding window maximums (size " << window_size << "): ";
    for (int i = 0; i < arr.size(); i++) // Process each element
    {
        // Remove elements outside current window
        while (!dq.empty() && dq.front() <= i - window_size) // Front element is outside window
        {
            dq.pop_front(); // Remove from front
        }

        // Remove smaller elements from back (maintain decreasing order)
        while (!dq.empty() && arr[dq.back()] <= arr[i]) // Current element is larger than back element
        {
            dq.pop_back(); // Remove from back
        }

        dq.push_back(i); // Add current element index

        // Print result when window is complete
        if (i >= window_size - 1) // Window has required size
        {
            cout << arr[dq.front()] << " "; // Front of deque has maximum element index
        }
    }
    cout << endl;

    // EXAMPLE 4: LRU CACHE CONCEPT - Explanation of implementation
    cout << "\n--- LRU Cache Structure ---" << endl;
    cout << "LRU Cache implementation uses:" << endl;
    cout << "1. unordered_map<key, list_iterator> for O(1) access" << endl; // Hash map for fast key lookup
    cout << "2. list<pair<key, value>> to maintain order" << endl;          // Doubly linked list for O(1) insertion/deletion
    cout << "3. get() and put() operations both in O(1) time" << endl;      // Both operations are constant time
    cout << "4. Most recently used items stay at front of list" << endl;    // LRU policy implementation
    cout << "5. When cache is full, remove least recently used (back of list)" << endl;

    // EXAMPLE 5: TRIE STRUCTURE CONCEPT - Explanation of prefix tree
    cout << "\n--- Trie Implementation Concept ---" << endl;
    cout << "Trie (Prefix Tree) uses:" << endl;
    cout << "1. map<char, TrieNode*> for each node's children" << endl;                 // Each node has map of character -> child node
    cout << "2. bool flag to mark end of words" << endl;                                // Flag to indicate complete word
    cout << "3. Efficient for prefix-based searches" << endl;                           // Excellent for autocomplete, word games
    cout << "4. Insert, search, startsWith all in O(m) where m is word length" << endl; // Time complexity proportional to word length
    cout << "5. Space efficient for storing many words with common prefixes" << endl;   // Shares common prefixes
}

// ====================================================================
// 21. MAIN FUNCTION - Complete demonstration with all explanations
// ====================================================================
int main()
{
    cout << "==============================================================" << endl;
    cout << "    COMPREHENSIVE STL GUIDE WITH DETAILED COMMENTS           " << endl;
    cout << "==============================================================" << endl;

    // Execute all demonstrations with detailed explanations
    explainPair();                  // Demonstrates pair usage and operations
    explainVector();                // Comprehensive vector operations and iterators
    explainList();                  // Doubly linked list operations
    explainStack();                 // LIFO stack operations
    explainQueue();                 // FIFO queue operations
    explainPQ();                    // Priority queue (heap) operations
    explainSet();                   // Sorted unique elements container
    explainMultiSet();              // Sorted container allowing duplicates
    explainMap();                   // Sorted key-value pairs
    explainAllMapTypes();           // Comprehensive comparison of all map types
    explainStringOperations();      // Comprehensive string manipulations
    explainAlgorithms();            // STL algorithms for sorting, searching, etc.
    explainPracticalExamples();     // Real-world problem solving examples
    explainPerformanceTips();       // Best practices and optimization guidelines
    explainAdvancedContainers();    // Less common but powerful containers
    explainBitManipulation();       // Bit-level operations and tricks
    explainLambdaFunctions();       // Anonymous functions for custom operations
    explainAdvancedAlgorithms();    // Complex algorithmic operations
    explainSetOperations();         // Mathematical set operations
    explainComplexDataStructures(); // Nested and advanced data combinations
    explainFinalExamples();         // Advanced problem-solving patterns

    cout << "\n==============================================================" << endl;
    cout << "                    END OF ENHANCED STL GUIDE                 " << endl;
    cout << "==============================================================" << endl;

    cout << "\n========== COMPREHENSIVE SUMMARY ==========\n";
    cout << "This enhanced guide covered:" << endl;
    cout << "✓ All major STL containers with detailed side-by-side comments" << endl;
    cout << "✓ Step-by-step explanations of what happens after each operation" << endl;
    cout << "✓ Time and space complexity analysis for each container" << endl;
    cout << "✓ Practical examples showing real-world usage patterns" << endl;
    cout << "✓ Performance optimization tips and best practices" << endl;
    cout << "✓ Advanced algorithms with lambda functions and custom comparators" << endl;
    cout << "✓ Complex data structures and their applications" << endl;
    cout << "✓ Bit manipulation techniques and mathematical operations" << endl;
    cout << "✓ Memory management and iterator invalidation rules" << endl;
    cout << "✓ Problem-solving patterns for competitive programming" << endl;

    cout << "\n========== KEY LEARNING POINTS ==========\n";
    cout << "1. CONTAINER CHOICE: Select the right container based on your operations" << endl;
    cout << "   - Need random access? Use vector or deque" << endl;
    cout << "   - Need fast insertion/deletion? Use list or set/map" << endl;
    cout << "   - Need unique elements? Use set or unordered_set" << endl;
    cout << "   - Need key-value pairs? Use map or unordered_map" << endl;

    cout << "\n2. PERFORMANCE OPTIMIZATION:" << endl;
    cout << "   - Use const auto& in range loops to avoid copying" << endl;
    cout << "   - Reserve memory for vectors when size is known" << endl;
    cout << "   - Use emplace operations instead of push for better performance" << endl;
    cout << "   - Prefer STL algorithms over manual loops" << endl;

    cout << "\n3. COMMON PATTERNS:" << endl;
    cout << "   - Two-pointer technique with vectors" << endl;
    cout << "   - Frequency counting with unordered_map" << endl;
    cout << "   - Priority-based processing with priority_queue" << endl;
    cout << "   - Graph problems with vector<vector<int>>" << endl;
    cout << "   - String processing with various string methods" << endl;

    cout << "\n4. MEMORY AND SAFETY:" << endl;
    cout << "   - Be aware of iterator invalidation rules" << endl;
    cout << "   - Use at() for bounds-checked access" << endl;
    cout << "   - Understand when containers reallocate memory" << endl;
    cout << "   - Use smart pointers for dynamic memory management" << endl;

    return 0;
}

/* ====================================================================
   COMPREHENSIVE STL REFERENCE SUMMARY WITH DETAILED EXPLANATIONS
   ====================================================================

   CONTAINER SELECTION MATRIX:
   ┌─────────────────┬──────────┬───────────┬──────────┬───────────────┐
   │ Container       │ Access   │ Insert    │ Delete   │ Use Case      │
   ├─────────────────┼──────────┼───────────┼──────────┼───────────────┤
   │ vector          │ O(1)     │ O(n)/O(1) │ O(n)/O(1)│ Dynamic array │
   │ list            │ O(n)     │ O(1)      │ O(1)     │ Frequent I/D  │
   │ deque           │ O(1)     │ O(1)/O(n) │ O(1)/O(n)│ Both ends     │
   │ set/map         │ O(log n) │ O(log n)  │ O(log n) │ Sorted data   │
   │ unordered_set   │ O(1)avg  │ O(1)avg   │ O(1)avg  │ Fast lookup   │
   │ stack/queue     │ O(1)     │ O(1)      │ O(1)     │ LIFO/FIFO     │
   │ priority_queue  │ O(1)     │ O(log n)  │ O(log n) │ Priority ops  │
   └─────────────────┴──────────┴───────────┴──────────┴───────────────┘

   ITERATOR CATEGORIES:
   1. Input Iterator: Read-only, single-pass (istream_iterator)
   2. Output Iterator: Write-only, single-pass (ostream_iterator)
   3. Forward Iterator: Read/write, multi-pass (forward_list)
   4. Bidirectional Iterator: Forward + backward (list, set, map)
   5. Random Access Iterator: Jump to any position (vector, deque)

   ALGORITHM COMPLEXITY GUIDE:
   - Sorting: O(n log n) average case for sort()
   - Binary Search: O(log n) on sorted containers
   - Linear Search: O(n) for unsorted data
   - Hash Operations: O(1) average, O(n) worst case
   - Tree Operations: O(log n) for balanced trees

   COMMON PITFALLS TO AVOID:
   1. Using vector when frequent insertion/deletion in middle
   2. Not reserving vector capacity when size is known
   3. Copying large objects in range-based loops without const&
   4. Using map when unordered_map would suffice
   5. Not checking if iterators are valid after container modifications
   6. Using raw loops when STL algorithms are available

   MEMORY LAYOUT UNDERSTANDING:
   - vector: Contiguous memory, good cache locality
   - deque: Chunks of contiguous memory, moderate cache locality
   - list: Non-contiguous nodes, poor cache locality
   - set/map: Tree nodes, moderate cache locality
   - unordered_map: Hash buckets, variable cache locality

   Remember: The STL is designed to be both efficient and easy to use.
   Choose the right container for your use case, and let the STL
   handle the complex implementation details for you!

   ================================================================== */


   /* ====================================================================
   COMPREHENSIVE STL CONTAINER SELECTION MATRIX WITH DETAILED EXPLANATIONS
   ====================================================================

   KEY:
   - Access: Time complexity for accessing elements
   - Search: Time complexity for finding elements
   - Insert: Time complexity for inserting elements
   - Delete: Time complexity for deleting elements
   - Ordering: Whether elements are stored in a particular order
   - Duplicates: Whether duplicate elements are allowed
   - Memory: Memory layout characteristics

   CONTAINER SELECTION MATRIX:
   ┌──────────────────────┬──────────┬──────────┬──────────┬──────────┬───────────┬───────────┬─────────────────────────────┐
   │ Container            │ Access   │ Search   │ Insert   │ Delete   │ Ordering  │ Duplicates│ Memory/Notes               │
   ├──────────────────────┼──────────┼──────────┼──────────┼──────────┼───────────┼───────────┼─────────────────────────────┤
   │ vector               │ O(1)     │ O(n)     │ O(n)E    │ O(n)E    │ Insertion │ Yes       │ Contiguous memory          │
   │                      │          │          │ O(1)E    │ O(1)E    │           │           │ Fast access, slow mid I/D  │
   ├──────────────────────┼──────────┼──────────┼──────────┼──────────┼───────────┼───────────┼─────────────────────────────┤
   │ deque                │ O(1)     │ O(n)     │ O(1)E    │ O(1)E    │ Insertion │ Yes       │ Chunks of contiguous       │
   │                      │          │          │ O(n)M    │ O(n)M    │           │           │ Good for both-end ops      │
   ├──────────────────────┼──────────┼──────────┼──────────┼──────────┼───────────┼───────────┼─────────────────────────────┤
   │ list                 │ O(n)     │ O(n)     │ O(1)     │ O(1)     │ Insertion │ Yes       │ Non-contiguous nodes       │
   │ (forward_list)       │          │          │          │          │           │           │ No random access           │
   ├──────────────────────┼──────────┼──────────┼──────────┼──────────┼───────────┼───────────┼─────────────────────────────┤
   │ array                │ O(1)     │ O(n)     │ N/A      │ N/A      │ Insertion │ Yes       │ Fixed-size contiguous      │
   │                      │          │          │          │          │           │           │ No growth/shrink           │
   ├──────────────────────┼──────────┼──────────┼──────────┼──────────┼───────────┼───────────┼─────────────────────────────┤
   │ set                  │ N/A      │ O(log n) │ O(log n) │ O(log n) │ Sorted    │ No        │ Red-Black Tree             │
   │ (multiset)           │          │          │          │          │           │ (Yes)     │ Slow iteration             │
   ├──────────────────────┼──────────┼──────────┼──────────┼──────────┼───────────┼───────────┼─────────────────────────────┤
   │ unordered_set        │ N/A      │ O(1)     │ O(1)     │ O(1)     │ Hashed    │ No        │ Hash table                 │
   │ (unordered_multiset) │          │ (O(n)W)  │ (O(n)W)  │ (O(n)W)  │           │ (Yes)     │ Fast but unordered         │
   ├──────────────────────┼──────────┼──────────┼──────────┼──────────┼───────────┼───────────┼─────────────────────────────┤
   │ map                  │ O(log n) │ O(log n) │ O(log n) │ O(log n) │ Key-sorted│ No        │ Red-Black Tree             │
   │ (multimap)           │          │          │          │          │           │ (Yes)     │ Key-value pairs            │
   ├──────────────────────┼──────────┼──────────┼──────────┼──────────┼───────────┼───────────┼─────────────────────────────┤
   │ unordered_map        │ O(1)     │ O(1)     │ O(1)     │ O(1)     │ Hashed    │ No        │ Hash table                 │
   │ (unordered_multimap) │ (O(n)W)  │ (O(n)W)  │ (O(n)W)  │ (O(n)W)  │           │ (Yes)     │ Fast but unordered         │
   ├──────────────────────┼──────────┼──────────┼──────────┼──────────┼───────────┼───────────┼─────────────────────────────┤
   │ stack                │ O(1)T    │ N/A      │ O(1)     │ O(1)     │ LIFO      │ Yes       │ Adaptor (uses deque)       │
   │                      │          │          │          │          │           │           │ Only top access            │
   ├──────────────────────┼──────────┼──────────┼──────────┼──────────┼───────────┼───────────┼─────────────────────────────┤
   │ queue                │ O(1)F    │ N/A      │ O(1)     │ O(1)     │ FIFO      │ Yes       │ Adaptor (uses deque)       │
   │                      │          │          │          │          │           │           │ Front/back access only     │
   ├──────────────────────┼──────────┼──────────┼──────────┼──────────┼───────────┼───────────┼─────────────────────────────┤
   │ priority_queue       │ O(1)T    │ N/A      │ O(log n) │ O(log n) │ Sorted    │ Yes       │ Adaptor (uses vector)      │
   │                      │          │          │          │          │ Priority  │           │ Heap structure             │
   ├──────────────────────┼──────────┼──────────┼──────────┼──────────┼───────────┼───────────┼─────────────────────────────┤
   │ string               │ O(1)     │ O(n)     │ O(n)E    │ O(n)E    │ Insertion │ Yes       │ Similar to vector          │
   │                      │          │          │ O(1)E    │ O(1)E    │           │           │ Specialized for chars      │
   └──────────────────────┴──────────┴──────────┴──────────┴──────────┴───────────┴───────────┴─────────────────────────────┘

   LEGEND:
   E - End operations (push_back/pop_back)
   M - Middle operations
   F - Front operations
   T - Top operations
   W - Worst case (hash collision)
   N/A - Not applicable or not available directly

   CONTAINER SELECTION GUIDE:
   1. Need index-based access? → vector, array, deque, string
   2. Need frequent insertion/deletion at both ends? → deque
   3. Need frequent middle insertion/deletion? → list
   4. Need sorted elements? → set, map, multiset, multimap
   5. Need fastest lookup? → unordered_set, unordered_map
   6. Need LIFO/FIFO behavior? → stack, queue
   7. Need priority-based access? → priority_queue
   8. Need string operations? → string

   PERFORMANCE CHARACTERISTICS:
   - Contiguous memory (vector, array, string):
     ✓ Fast iteration
     ✓ Good cache locality
     ✗ Expensive insertions/deletions in middle

   - Node-based (list, set, map):
     ✓ Fast insertions/deletions anywhere
     ✗ Poor cache locality
     ✗ No random access

   - Hash-based (unordered_*):
     ✓ Fastest average access
     ✗ Worst-case O(n) performance
     ✗ No ordering

   - Adaptors (stack, queue, priority_queue):
     ✓ Clean interface for specific use cases
     ✗ Limited functionality

   MEMORY OVERHEAD COMPARISON (per element):
   - Lowest: vector, array, string
   - Medium: deque, unordered_*
   - High: list, set, map
   - Adaptors: Depends on underlying container

   ITERATOR INVALIDATION RULES:
   - vector: All iterators invalidated on reallocation
   - deque: Invalidated on middle insert/delete
   - list: Never invalidated (unless element deleted)
   - set/map: Never invalidated (unless element deleted)
   - unordered_*: Invalidated on rehash
   - string: Same as vector
*/


/* ====================================================================
   ENHANCED STL CONTAINER COMPLEXITY ANALYSIS - ADDITIONS TO EXISTING CODE
   
   Add these sections to enhance the existing STL guide with detailed 
   time complexity analysis and additional implementation details
   ====================================================================

   COMPREHENSIVE TIME COMPLEXITY LEGEND:
   - Best Case: Optimal scenario (e.g., inserting at end of vector)
   - Average Case: Expected performance under typical conditions
   - Worst Case: Maximum time in adverse conditions (e.g., hash collisions)
   - Amortized: Average cost over sequence of operations
*/

// ====================================================================
// ENHANCED CONTAINER SELECTION MATRIX WITH COMPLETE COMPLEXITY ANALYSIS
// ====================================================================

/* ENHANCED CONTAINER SELECTION MATRIX WITH DETAILED TIME COMPLEXITIES:

┌──────────────────────┬────────────────┬────────────────┬────────────────┬────────────────┬───────────────────────────────┐
│ Container            │ Access         │ Search         │ Insert         │ Delete         │ Memory & Implementation        │
├──────────────────────┼────────────────┼────────────────┼────────────────┼────────────────┼───────────────────────────────┤
│ vector               │ Best: O(1)     │ Best: O(1)     │ Best: O(1)     │ Best: O(1)     │ Implementation: Dynamic Array  │
│                      │ Avg:  O(1)     │ Avg:  O(n)     │ Avg:  O(n)     │ Avg:  O(n)     │ Memory: Contiguous             │
│                      │ Worst:O(1)     │ Worst:O(n)     │ Worst:O(n)     │ Worst:O(n)     │ Cache: Excellent locality      │
│                      │ [by index]     │ [unsorted]     │ [end: O(1)ᵃ]   │ [end: O(1)]    │ Overhead: ~24 bytes + data    │
├──────────────────────┼────────────────┼────────────────┼────────────────┼────────────────┼───────────────────────────────┤
│ deque                │ Best: O(1)     │ Best: O(1)     │ Best: O(1)     │ Best: O(1)     │ Implementation: Chunked Array  │
│                      │ Avg:  O(1)     │ Avg:  O(n)     │ Avg:  O(n)     │ Avg:  O(n)     │ Memory: Multiple chunks        │
│                      │ Worst:O(1)     │ Worst:O(n)     │ Worst:O(n)     │ Worst:O(n)     │ Cache: Good for ends          │
│                      │ [by index]     │ [unsorted]     │ [ends: O(1)]   │ [ends: O(1)]   │ Overhead: Higher than vector  │
├──────────────────────┼────────────────┼────────────────┼────────────────┼────────────────┼───────────────────────────────┤
│ list/forward_list    │ Best: O(n)     │ Best: O(1)     │ Best: O(1)     │ Best: O(1)     │ Implementation: Linked List   │
│                      │ Avg:  O(n)     │ Avg:  O(n)     │ Avg:  O(1)ᵇ    │ Avg:  O(1)ᵇ    │ Memory: Non-contiguous nodes  │
│                      │ Worst:O(n)     │ Worst:O(n)     │ Worst:O(1)ᵇ    │ Worst:O(1)ᵇ    │ Cache: Poor locality          │
│                      │ [sequential]   │ [unsorted]     │ [at position]  │ [at position]  │ Overhead: 16+ bytes per node  │
├──────────────────────┼────────────────┼────────────────┼────────────────┼────────────────┼───────────────────────────────┤
│ array                │ Best: O(1)     │ Best: O(1)     │ Best: N/A      │ Best: N/A      │ Implementation: Fixed Array   │
│                      │ Avg:  O(1)     │ Avg:  O(n)     │ Avg:  N/A      │ Avg:  N/A      │ Memory: Stack allocated       │
│                      │ Worst:O(1)     │ Worst:O(n)     │ Worst:N/A      │ Worst:N/A      │ Cache: Excellent locality     │
│                      │ [by index]     │ [unsorted]     │ [fixed size]   │ [fixed size]   │ Overhead: Zero                │
├──────────────────────┼────────────────┼────────────────┼────────────────┼────────────────┼───────────────────────────────┤
│ set/multiset         │ Best: O(log n) │ Best: O(log n) │ Best: O(log n) │ Best: O(log n) │ Implementation: Red-Black Tree│
│                      │ Avg:  O(log n) │ Avg:  O(log n) │ Avg:  O(log n) │ Avg:  O(log n) │ Memory: Tree nodes            │
│                      │ Worst:O(log n) │ Worst:O(log n) │ Worst:O(log n) │ Worst:O(log n) │ Cache: Poor for traversal     │
│                      │ [balanced]     │ [sorted]       │ [balanced]     │ [balanced]     │ Overhead: 24+ bytes per node │
├──────────────────────┼────────────────┼────────────────┼────────────────┼────────────────┼───────────────────────────────┤
│ unordered_set/       │ Best: O(1)     │ Best: O(1)     │ Best: O(1)     │ Best: O(1)     │ Implementation: Hash Table    │
│ unordered_multiset   │ Avg:  O(1)     │ Avg:  O(1)     │ Avg:  O(1)     │ Avg:  O(1)     │ Memory: Buckets + nodes       │
│                      │ Worst:O(n)ᶜ    │ Worst:O(n)ᶜ    │ Worst:O(n)ᶜ    │ Worst:O(n)ᶜ    │ Cache: Depends on hash        │
│                      │ [hash collis.] │ [hash collis.] │ [hash collis.] │ [hash collis.] │ Overhead: Load factor depend. │
├──────────────────────┼────────────────┼────────────────┼────────────────┼────────────────┼───────────────────────────────┤
│ map/multimap         │ Best: O(log n) │ Best: O(log n) │ Best: O(log n) │ Best: O(log n) │ Implementation: Red-Black Tree│
│                      │ Avg:  O(log n) │ Avg:  O(log n) │ Avg:  O(log n) │ Avg:  O(log n) │ Memory: Key-value tree nodes  │
│                      │ Worst:O(log n) │ Worst:O(log n) │ Worst:O(log n) │ Worst:O(log n) │ Cache: Poor for large data    │
│                      │ [by key]       │ [by key]       │ [balanced]     │ [balanced]     │ Overhead: 32+ bytes per pair  │
├──────────────────────┼────────────────┼────────────────┼────────────────┼────────────────┼───────────────────────────────┤
│ unordered_map/       │ Best: O(1)     │ Best: O(1)     │ Best: O(1)     │ Best: O(1)     │ Implementation: Hash Table    │
│ unordered_multimap   │ Avg:  O(1)     │ Avg:  O(1)     │ Avg:  O(1)     │ Avg:  O(1)     │ Memory: Hash buckets          │
│                      │ Worst:O(n)ᶜ    │ Worst:O(n)ᶜ    │ Worst:O(n)ᶜ    │ Worst:O(n)ᶜ    │ Cache: Hash-dependent         │
│                      │ [by key]       │ [by key]       │ [rehashing]    │ [rehashing]    │ Overhead: Buckets + load mgmt │
├──────────────────────┼────────────────┼────────────────┼────────────────┼────────────────┼───────────────────────────────┤
│ stack                │ Best: O(1)     │ Best: N/A      │ Best: O(1)     │ Best: O(1)     │ Implementation: Adapter       │
│                      │ Avg:  O(1)     │ Avg:  N/A      │ Avg:  O(1)ᵈ    │ Avg:  O(1)     │ Memory: Underlying container  │
│                      │ Worst:O(1)     │ Worst:N/A      │ Worst:O(n)ᵈ    │ Worst:O(1)     │ Cache: Depends on underlying  │
│                      │ [top only]     │ [no search]    │ [push]         │ [pop]          │ Default: deque                │
├──────────────────────┼────────────────┼────────────────┼────────────────┼────────────────┼───────────────────────────────┤
│ queue                │ Best: O(1)     │ Best: N/A      │ Best: O(1)     │ Best: O(1)     │ Implementation: Adapter       │
│                      │ Avg:  O(1)     │ Avg:  N/A      │ Avg:  O(1)ᵈ    │ Avg:  O(1)     │ Memory: Underlying container  │
│                      │ Worst:O(1)     │ Worst:N/A      │ Worst:O(n)ᵈ    │ Worst:O(1)     │ Cache: Depends on underlying  │
│                      │ [front/back]   │ [no search]    │ [enqueue]      │ [dequeue]      │ Default: deque                │
├──────────────────────┼────────────────┼────────────────┼────────────────┼────────────────┼───────────────────────────────┤
│ priority_queue       │ Best: O(1)     │ Best: O(n)     │ Best: O(log n) │ Best: O(log n) │ Implementation: Binary Heap   │
│                      │ Avg:  O(1)     │ Avg:  O(n)     │ Avg:  O(log n) │ Avg:  O(log n) │ Memory: Complete binary tree  │
│                      │ Worst:O(1)     │ Worst:O(n)     │ Worst:O(log n) │ Worst:O(log n) │ Cache: Good (array-based)     │
│                      │ [top only]     │ [linear scan]  │ [heapify up]   │ [heapify down] │ Default: vector               │
└──────────────────────┴────────────────┴────────────────┴────────────────┴────────────────┴───────────────────────────────┘

NOTES:
ᵃ Amortized O(1) for push_back due to exponential growth strategy
ᵇ O(1) if iterator to position is available, O(n) to find position
ᶜ Worst case occurs with poor hash function or many collisions
ᵈ Depends on underlying container (deque default gives O(1) amortized)

MEMORY OVERHEAD COMPARISON (typical 64-bit system):
┌─────────────────────────┬──────────────────────────────────────────────┐
│ Container               │ Memory Overhead Analysis                     │
├─────────────────────────┼──────────────────────────────────────────────┤
│ vector<int>            │ 24 bytes (size, capacity, ptr) + 4n bytes   │
│ deque<int>             │ ~40 bytes + chunks + 4n bytes               │
│ list<int>              │ 16 bytes + (16 + 4)n bytes per node         │
│ set<int>               │ 16 bytes + (24 + 4)n bytes per node         │
│ unordered_set<int>     │ 32+ bytes + buckets + (8 + 4)n bytes        │
│ map<int,int>           │ 16 bytes + (24 + 8)n bytes per node         │
│ unordered_map<int,int> │ 32+ bytes + buckets + (8 + 8)n bytes        │
└─────────────────────────┴──────────────────────────────────────────────┘

ITERATOR INVALIDATION RULES:
┌───────────────────┬─────────────────────────────────────────────────────┐
│ Container         │ Iterator Invalidation Conditions                   │
├───────────────────┼─────────────────────────────────────────────────────┤
│ vector            │ • Insert: If reallocation → all invalid            │
│                   │ • Erase: At/after erase point → invalid            │
├───────────────────┼─────────────────────────────────────────────────────┤
│ deque             │ • Insert: middle → all invalid, ends → valid       │
│                   │ • Erase: middle → all invalid, ends → others valid │
├───────────────────┼─────────────────────────────────────────────────────┤
│ list              │ • Insert: never invalidated                        │
│                   │ • Erase: only erased element's iterator invalid    │
├───────────────────┼─────────────────────────────────────────────────────┤
│ set/map           │ • Insert: never invalidated                        │
│                   │ • Erase: only erased element's iterator invalid    │
├───────────────────┼─────────────────────────────────────────────────────┤
│ unordered_*       │ • Insert: if rehashing → all invalid               │
│                   │ • Erase: only erased element's iterator invalid    │
└───────────────────┴─────────────────────────────────────────────────────┘

ADVANCED PERFORMANCE CHARACTERISTICS:

1. CACHE PERFORMANCE ANALYSIS:
   - vector/array: Excellent - sequential memory access
   - deque: Good - chunks provide reasonable locality  
   - list: Poor - nodes scattered in memory
   - set/map: Poor - tree traversal has poor locality
   - unordered_*: Variable - depends on hash distribution

2. BRANCH PREDICTION IMPACT:
   - vector: Predictable access patterns
   - unordered_*: Unpredictable due to hashing
   - set/map: Balanced tree provides some predictability

3. MEMORY ALLOCATION PATTERNS:
   - vector: Batch allocation, exponential growth
   - list: Per-node allocation, potential fragmentation
   - unordered_*: Bucket allocation + node allocation
   - set/map: Per-node allocation with tree balancing

4. MULTITHREADING CONSIDERATIONS:
   - Read-only operations: Generally thread-safe
   - Concurrent modifications: Require external synchronization
   - Iterator safety: Depends on container modification rules

ALGORITHM COMPLEXITY REFERENCE:
┌─────────────────────────┬────────────────────────────────────────────┐
│ Algorithm               │ Time Complexity Analysis                   │
├─────────────────────────┼────────────────────────────────────────────┤
│ sort()                  │ O(n log n) avg/worst, O(n) best (sorted)  │
│ stable_sort()           │ O(n log²n) worst, O(n log n) avg          │
│ partial_sort()          │ O(n log k) where k = number to sort       │
│ nth_element()           │ O(n) avg, O(n²) worst                     │
├─────────────────────────┼────────────────────────────────────────────┤
│ binary_search()         │ O(log n) - requires sorted range          │
│ lower_bound()           │ O(log n) - requires sorted range          │
│ upper_bound()           │ O(log n) - requires sorted range          │
│ equal_range()           │ O(log n) - requires sorted range          │
├─────────────────────────┼────────────────────────────────────────────┤
│ find()                  │ O(n) - linear search                      │
│ find_if()               │ O(n) - linear search with predicate       │
│ count()                 │ O(n) - count occurrences                  │
│ count_if()              │ O(n) - count with predicate               │
├─────────────────────────┼────────────────────────────────────────────┤
│ reverse()               │ O(n) - reverse range                      │
│ rotate()                │ O(n) - rotate elements                    │
│ unique()                │ O(n) - remove consecutive duplicates      │
│ remove()                │ O(n) - remove elements (doesn't resize)   │
├─────────────────────────┼────────────────────────────────────────────┤
│ transform()             │ O(n) - apply function to range            │
│ for_each()              │ O(n) - apply function to each element     │
│ accumulate()            │ O(n) - reduce range to single value       │
│ copy()                  │ O(n) - copy elements between ranges       │
├─────────────────────────┼────────────────────────────────────────────┤
│ set_union()             │ O(m + n) - merge sorted ranges            │
│ set_intersection()      │ O(m + n) - intersect sorted ranges        │
│ set_difference()        │ O(m + n) - difference of sorted ranges    │
│ merge()                 │ O(m + n) - merge two sorted ranges        │
├─────────────────────────┼────────────────────────────────────────────┤
│ next_permutation()      │ O(n) - generate next permutation          │
│ prev_permutation()      │ O(n) - generate previous permutation      │
│ random_shuffle()        │ O(n) - randomly shuffle elements          │
│ shuffle()               │ O(n) - shuffle with random generator       │
└─────────────────────────┴────────────────────────────────────────────┘

SPACE COMPLEXITY ANALYSIS:
┌─────────────────────────┬────────────────────────────────────────────┐
│ Operation               │ Additional Space Required                  │
├─────────────────────────┼────────────────────────────────────────────┤
│ sort()                  │ O(log n) - recursion stack                │
│ stable_sort()           │ O(n) - temporary array when low memory    │
│ merge()                 │ O(1) - in-place merge                     │
│ inplace_merge()         │ O(1) - truly in-place                     │
├─────────────────────────┼────────────────────────────────────────────┤
│ unique()                │ O(1) - in-place removal                   │
│ remove()                │ O(1) - in-place removal                   │
│ reverse()               │ O(1) - in-place reversal                  │
│ rotate()                │ O(1) - in-place rotation                  │
├─────────────────────────┼────────────────────────────────────────────┤
│ copy()                  │ O(1) - destination must exist             │
│ transform()             │ O(1) - destination must exist             │
│ set operations          │ O(1) - if using inserter iterators        │
└─────────────────────────┴────────────────────────────────────────────┘
*/

// ====================================================================
// ENHANCED PERFORMANCE OPTIMIZATION GUIDELINES
// ====================================================================
void explainAdvancedPerformanceOptimizations()
{
    cout << "\n========== ADVANCED PERFORMANCE OPTIMIZATION GUIDE ==========\n";
    
    cout << "1. CONTAINER SELECTION DECISION TREE:\n";
    cout << "   ┌─ Need random access?\n";
    cout << "   │  ├─ Yes ──┐\n";
    cout << "   │  │        ├─ Fixed size? ──── array\n";
    cout << "   │  │        ├─ Insert at ends? ── deque  \n";
    cout << "   │  │        └─ Insert anywhere? ── vector\n";
    cout << "   │  └─ No ───── list (if frequent middle insert/delete)\n";
    cout << "   ├─ Need sorted order?\n";
    cout << "   │  ├─ Yes ──┐\n";
    cout << "   │  │        ├─ Unique keys only? ── set/map\n";
    cout << "   │  │        └─ Allow duplicates? ── multiset/multimap\n";
    cout << "   │  └─ No ───── unordered_set/map (fastest lookup)\n";
    cout << "   └─ Need special access pattern?\n";
    cout << "      ├─ LIFO (Last In First Out) ── stack\n";
    cout << "      ├─ FIFO (First In First Out) ── queue\n";
    cout << "      └─ Priority-based ──────────── priority_queue\n\n";

    cout << "2. MEMORY OPTIMIZATION STRATEGIES:\n";
    cout << "   ┌─ Vector Optimizations:\n";
    cout << "   │  ├─ reserve() when final size is known\n";
    cout << "   │  ├─ shrink_to_fit() to reduce capacity\n";
    cout << "   │  ├─ emplace_back() instead of push_back()\n";
    cout << "   │  └─ Move semantics for expensive objects\n";
    cout << "   ├─ Unordered Container Optimizations:\n";
    cout << "   │  ├─ Set appropriate load factor (0.75 default)\n";
    cout << "   │  ├─ Reserve buckets: unordered_map.reserve(expected_size)\n";
    cout << "   │  ├─ Use good hash function for custom types\n";
    cout << "   │  └─ Consider robin hood hashing for better performance\n";
    cout << "   └─ General Memory Tips:\n";
    cout << "      ├─ Use const auto& in range-based loops\n";
    cout << "      ├─ Avoid unnecessary copies with move semantics\n";
    cout << "      ├─ Consider object pooling for frequent allocations\n";
    cout << "      └─ Profile memory usage with tools like valgrind\n\n";

    cout << "3. CACHE OPTIMIZATION TECHNIQUES:\n";
    cout << "   ┌─ Data Structure Layout:\n";
    cout << "   │  ├─ Prefer vector over list for sequential access\n";
    cout << "   │  ├─ Use struct-of-arrays instead of array-of-structs\n";
    cout << "   │  ├─ Pack data members to minimize padding\n";
    cout << "   │  └─ Consider memory-mapped files for large datasets\n";
    cout << "   ├─ Access Patterns:\n";
    cout << "   │  ├─ Process data in sequential order when possible\n";
    cout << "   │  ├─ Use blocking/tiling for matrix operations\n";
    cout << "   │  ├─ Prefetch data when access pattern is predictable\n";
    cout << "   │  └─ Minimize pointer chasing in hot loops\n";
    cout << "   └─ Algorithm Selection:\n";
    cout << "      ├─ Choose cache-friendly algorithms\n";
    cout << "      ├─ Use iterative instead of recursive when possible\n";
    cout << "      ├─ Consider parallel algorithms for large datasets\n";
    cout << "      └─ Profile with cache analysis tools\n\n";

    cout << "4. COMPLEXITY ANALYSIS IN PRACTICE:\n";
    cout << "   ┌─ Amortized Analysis Understanding:\n";
    cout << "   │  ├─ vector.push_back(): Individual O(n), amortized O(1)\n";
    cout << "   │  ├─ Reason: Doubling strategy spreads cost over operations\n";
    cout << "   │  ├─ Growth factors: 1.5x (MSVC) vs 2x (GCC) trade-offs\n";
    cout << "   │  └─ reserve() eliminates amortized cost uncertainty\n";
    cout << "   ├─ Hash Table Performance:\n";
    cout << "   │  ├─ Load factor impact: 0.5 (fast) vs 0.9 (memory efficient)\n";
    cout << "   │  ├─ Hash function quality affects worst-case behavior\n";
    cout << "   │  ├─ Collision resolution: chaining vs open addressing\n";
    cout << "   │  └─ Rehashing cost: O(n) but infrequent with good sizing\n";
    cout << "   └─ Tree-Based Container Insights:\n";
    cout << "      ├─ Red-black tree guarantees O(log n) worst case\n";
    cout << "      ├─ Tree height: log₂(n) to 2×log₂(n) range\n";
    cout << "      ├─ Node allocation overhead affects small datasets\n";
    cout << "      └─ Consider B-trees for disk-based storage\n\n";

    cout << "5. BENCHMARK-DRIVEN OPTIMIZATION:\n";
    cout << "   ┌─ Micro-benchmarking:\n";
    cout << "   │  ├─ Use std::chrono for timing\n";
    cout << "   │  ├─ Warm up caches before measurement\n";
    cout << "   │  ├─ Run multiple iterations for statistical significance\n";
    cout << "   │  └─ Consider compiler optimization effects (-O2, -O3)\n";
    cout << "   ├─ Profiling Tools:\n";
    cout << "   │  ├─ perf: CPU performance counters\n";
    cout << "   │  ├─ cachegrind: Cache miss analysis\n";
    cout << "   │  ├─ massif: Heap memory usage\n";
    cout << "   │  └─ Intel VTune: Comprehensive performance analysis\n";
    cout << "   └─ A/B Testing:\n";
    cout << "      ├─ Compare different container choices\n";
    cout << "      ├─ Test various algorithm implementations\n";
    cout << "      ├─ Measure under realistic workloads\n";
    cout << "      └─ Consider different data distributions\n";
}

// ====================================================================
// MODERN C++ FEATURES IMPACT ON STL PERFORMANCE  
// ====================================================================
void explainModernCppPerformanceFeatures()
{
    cout << "\n========== MODERN C++ FEATURES & STL PERFORMANCE ==========\n";
    
    cout << "1. MOVE SEMANTICS OPTIMIZATION (C++11):\n";
    cout << "   ┌─ Container Operations:\n";
    cout << "   │  ├─ push_back() vs emplace_back() for objects:\n";
    cout << "   │  │  • push_back(): Copy constructor + possible move\n";
    cout << "   │  │  • emplace_back(): Direct construction in place\n";
    cout << "   │  │  • Performance gain: Eliminates temporary objects\n";
    cout << "   │  ├─ insert() vs emplace() family:\n";
    cout << "   │  │  • emplace_hint(), emplace_front(), etc.\n";
    cout << "   │  │  • Particularly beneficial for complex objects\n";
    cout << "   │  └─ Return value optimization in container operations\n";
    cout << "   ├─ Examples:\n";
    cout << "   │  vector<string> v;\n";
    cout << "   │  v.push_back(string(\"hello\"));    // Copy + move\n";
    cout << "   │  v.emplace_back(\"hello\");         // Direct construction\n";
    cout << "   │  \n";
    cout << "   │  map<int, ComplexType> m;\n";
    cout << "   │  m[1] = ComplexType(args);         // Default construct + assign\n";
    cout << "   │  m.emplace(1, args);               // Direct construction\n";
    cout << "   └─ Performance Impact:\n";
    cout << "      ├─ Reduces constructor/destructor calls\n";
    cout << "      ├─ Eliminates temporary object allocation\n";
    cout << "      ├─ Particularly important for expensive-to-copy types\n";
    cout << "      └─ Can provide 2-10x performance improvement\n\n";

    cout << "2. RANGE-BASED FOR LOOPS OPTIMIZATION (C++11):\n";
    cout << "   ┌─ Syntax Variations & Performance:\n";
    cout << "   │  for (auto element : container)        // Copy each element\n";
    cout << "   │  for (const auto& element : container) // Reference (read-only)\n";
    cout << "   │  for (auto& element : container)       // Reference (modifiable)\n";
    cout << "   │  for (auto&& element : container)      // Universal reference\n";
    cout << "   ├─ Compiler Optimizations:\n";
    cout << "   │  ├─ Often optimized to same assembly as iterator loops\n";
    cout << "   │  ├─ begin()/end() calls may be optimized away\n";
    cout << "   │  ├─ Better optimization with const containers\n";
    cout << "   │  └─ Range-based loops can enable auto-vectorization\n";
    cout << "   └