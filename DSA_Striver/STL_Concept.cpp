/* ====================================================================
   ENHANCED STL CONTAINER COMPLEXITY ANALYSIS - REFERENCE GUIDE

   Comprehensive time complexity analysis and implementation details
   for C++ STL containers with performance optimization guidelines
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

