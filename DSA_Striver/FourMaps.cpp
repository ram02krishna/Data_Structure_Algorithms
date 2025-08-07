#include <bits/stdc++.h>
using namespace std;

int main()
{
    // 1. map (ordered, unique keys)
    map<int, string> orderedMap;
    orderedMap[3] = "Three";
    orderedMap[1] = "One";
    orderedMap[2] = "Two";
    orderedMap[3] = "Three-Updated"; // duplicate key: updates value

    // 2. unordered_map (unordered, unique keys)
    unordered_map<int, string> unorderedMap;
    unorderedMap[3] = "Three";
    unorderedMap[1] = "One";
    unorderedMap[2] = "Two";
    unorderedMap[3] = "Three-Updated"; // duplicate key: updates value

    // 3. multimap (ordered, allows duplicate keys)
    multimap<int, string> orderedMultiMap;
    orderedMultiMap.insert({3, "Three"});
    orderedMultiMap.insert({1, "One"});
    orderedMultiMap.insert({2, "Two"});
    orderedMultiMap.insert({3, "Three-Again"}); // duplicate key: allowed

    // 4. unordered_multimap (unordered, allows duplicate keys)
    unordered_multimap<int, string> unorderedMultiMap;
    unorderedMultiMap.insert({3, "Three"});
    unorderedMultiMap.insert({1, "One"});
    unorderedMultiMap.insert({2, "Two"});
    unorderedMultiMap.insert({3, "Three-Again"}); // duplicate key: allowed

    // Output
    cout << "=== map (ordered, unique keys) ===\n";
    for (const auto &[key, value] : orderedMap)
    {
        cout << key << ": " << value << endl;
    }

    cout << "\n=== unordered_map (unordered, unique keys) ===\n";
    for (const auto &[key, value] : unorderedMap)
    {
        cout << key << ": " << value << endl;
    }

    cout << "\n=== multimap (ordered, allows duplicate keys) ===\n";
    for (const auto &[key, value] : orderedMultiMap)
    {
        cout << key << ": " << value << endl;
    }

    cout << "\n=== unordered_multimap (unordered, allows duplicate keys) ===\n";
    for (const auto &[key, value] : unorderedMultiMap)
    {
        cout << key << ": " << value << endl;
    }

    return 0;
}   
