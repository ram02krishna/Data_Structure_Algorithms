/*
Syntax (STL): priority_queue<data_type> pq;
Example: priority_queue<int> pq;

Default Behavior (Max Heap)
👉 Largest element comes at top

#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int> pq;

    pq.push(10);
    pq.push(5);
    pq.push(20);

    cout << pq.top(); // 20 (largest)

    return 0;
}


| Function  | Description        |
| --------- | ------------------ |
| `push(x)` | Insert element     |
| `pop()`   | Remove top element |
| `top()`   | Access top element |
| `empty()` | Check if empty     |
| `size()`  | Number of elements |


Min Heap (Important ⭐)
By default it's max heap, but you can make min heap using:
priority_queue<int, vector<int>, greater<int>> pq;

Example:
#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<int>> pq;

    pq.push(3);
    pq.push(1);
    pq.push(5);
    pq.push(2);

    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
}


| Part           | Meaning                   |
| -------------- | ------------------------- |
| `int`          | Data type                 |
| `vector<int>`  | Underlying container      |
| `greater<int>` | Comparator (for min heap) |


Example: Sort pairs based on second value
#include <iostream>
#include <queue>
using namespace std;

struct cmp {
    bool operator()(pair<int,int> a, pair<int,int> b) {
        return a.second > b.second; // min heap based on second
    }
};

int main() {
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;

    pq.push({1, 30});
    pq.push({2, 10});
    pq.push({3, 20});

    while (!pq.empty()) {
        cout << pq.top().first << " ";
        pq.pop();
    }
}

// Output: 2 3 1 (sorted by second value)

| Operation | Time     |
| --------- | -------- |
| push      | O(log n) |
| pop       | O(log n) |
| top       | O(1)     |


priority_queue = Heap-based container
Default → Max Heap
Used in graphs, greedy, optimization problems


Declaration for Min Heap:
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

1️⃣ First pair<int, int> → Element type
priority_queue<pair<int, int>, ...>
👉 This tells the queue:
➡️ “I will store elements of type pair<int, int>”


2️⃣ Second pair<int, int> → Container type
vector<pair<int, int>>
👉 This tells the queue:
➡️ “Internally use a vector of pair<int, int> to store elements”
✔ priority_queue uses a container (default = vector)
✔ That container must store the same type as the queue elements


3️⃣ Third pair<int, int> → Comparator type
greater<pair<int, int>>
👉 This tells the queue:
➡️ “Compare elements using greater on pair<int, int>”
✔ This makes it a min heap
✔ Comparison is lexicographical:

First compares .first
If equal, compares .second

| Component      | Needs type? | Why                      |
| -------------- | ----------- | ------------------------ |
| priority_queue | ✅ Yes       | What elements it stores  |
| vector         | ✅ Yes       | What it holds internally |
| greater        | ✅ Yes       | How to compare elements  |

Final Understanding
priority_queue<
    pair<int, int>,              // what to store
    vector<pair<int, int>>,      // how to store
    greater<pair<int, int>>      // how to compare
> pq;

So:
Stores → pair<int, int>
Uses → vector
Orders → smallest first (min heap)



priority_queue<
    pair<int, pair<int, int>>,
    vector<pair<int, pair<int, int>>>,
    greater<pair<int, pair<int, int>>>
> pq; 

This defines a min-heap priority queue that stores: pairs of integers, where the first integer is used for comparison, and the second integer is stored as part of the pair.
example: 
{3, {1,2}}
{5, {0,1}}
{2, {4,4}}
priority queue will order them based on the first integer:
{2, {4,4}}  // smallest first
{3, {1,2}}
{5, {0,1}}  // largest last

*/