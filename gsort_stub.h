#include <genalg.h>
#include <gset.h>
#include <cstdlib>
#include <algorithm>
#include <iterator>
#include <functional>

namespace fsu
{

template < class ForwardIterator >
void g_selection_sort (ForwardIterator beg, ForwardIterator end)
{
ForwardIterator i, j, k;
for (i = beg; i != end; ++i)
{
k = i;
for (j = i; j != end; ++j)
if (*j < *k)
k = j;
Swap (*i, *k);
}
}

template < class ForwardIterator, class Comparator >
void g_selection_sort (ForwardIterator beg, ForwardIterator end, Comparator& cmp)
{
ForwardIterator i, j, k;
for (i = beg; i != end; ++i)
{
k = i;
for (j = i; j != end; ++j)
if (cmp(*j , *k))
k = j;
Swap (*i, *k);
}
}

template < class BidirectionalIterator >
void g_insertion_sort (BidirectionalIterator beg, BidirectionalIterator end)
{
BidirectionalIterator i, j, k;
typename BidirectionalIterator::ValueType t;
for (i = beg; i != end; ++i)
{
t = *i;
for (k = i, j = k--; j != beg && t < *k; --j, --k)
*j = *k;
*j = t;
}
}

template < class BidirectionalIterator, class Comparator >
void g_insertion_sort (BidirectionalIterator beg, BidirectionalIterator end, Comparator& cmp)
{
BidirectionalIterator i, j, k;
typename BidirectionalIterator::ValueType t;
for (i = beg; i != end; ++i)
{
t = *i;
for (k = i, j = k--; j != beg && cmp(t,*k); --j, --k)
*j = *k;
*j = t;
}
}

template < typename T >
void g_insertion_sort (T* beg, T* end)
{
T *i, *j, *k;
T t;
for (i = beg; i != end; ++i)
{
t = *i;
for (k = i, j = k--; j != beg && t < *k; --j, --k)
*j = *k;
*j = t;
}
}

template < typename T , class Comparator >
void g_insertion_sort (T* beg, T* end, Comparator& cmp)
{
T *i, *j, *k;
T t;
for (i = beg; i != end; ++i)
{
t = *i;
for (k = i, j = k--; j != beg && cmp(t,*k); --j, --k)
*j = *k;
*j = t;
}
}

namespace mergesort
{

template < typename RAIterator >
void Merge(RAIterator beg, RAIterator mid, RAIterator end)
{
typename RAIterator::ValueType  B [end - beg];   
g_set_merge(beg, mid, mid, end, B);     
g_copy(B, B+(end-beg), beg);        
}

template < typename RAIterator , class Comparator >
void Merge(RAIterator beg, RAIterator mid, RAIterator end, Comparator& cmp)
{
typename RAIterator::ValueType  B [end - beg];
g_set_merge(beg, mid, mid, end, B, cmp);
g_copy(B, B+(end-beg), beg);
}

template < typename T >
void Merge(T* beg, T* mid, T* end)
{
T B [end - beg];                     
g_set_merge(beg, mid, mid, end, B);  
g_copy(B, B+(end-beg), beg);        
}

template < typename T , class Comparator >
void Merge(T* beg, T* mid, T* end, Comparator& cmp)
{
T B [end - beg];
g_set_merge(beg, mid, mid, end, B, cmp);
g_copy(B, B+(end-beg), beg);
}

} 

template < class RAIterator >
void g_merge_sort(RAIterator beg, RAIterator end)
{
RAIterator mid;
size_t size = end - beg;
if (size > 1)
{
mid = beg + (size/2);
g_merge_sort(beg, mid);
g_merge_sort(mid, end);
mergesort::Merge(beg, mid, end);
}
else return;
}

template < class RAIterator, class Comparator >
void g_merge_sort(RAIterator beg, RAIterator end, Comparator& cmp)
{
RAIterator mid;
size_t size = end - beg;
if (size > 1)
{
mid = beg + (size/2);
g_merge_sort(beg, mid, cmp);
g_merge_sort(mid, end, cmp);
mergesort::Merge(beg, mid, end, cmp);
}
else return;
}

namespace quicksort
{


// NOTE that inside this namespace iterators define closed ranges [p,r]

template < class IterType >
IterType Partition (IterType first, IterType last) // closed range [first,last]
{
// this code is complete
IterType pivot = first;  // initially the pivot position is first position
for (IterType j = first; j != last; ++j)
{
if (!(*last < *j)) // if (*j <= *last)
{
Swap(*pivot,*j);
++pivot;
}
}
Swap (*pivot,*last);
return pivot;
}

template < class IterType , class P >
IterType Partition (IterType first, IterType last, P& cmp) // closed range [first,last]
{
IterType pivot = first;
// .. needs code here
return pivot;
}

} // namespace

template < class IterType >
void g_quick_sort (IterType beg, IterType end)
{
// recursive
// calls quicksort::Partition(beg, end);
}

template < class IterType , class Comparator >
void g_quick_sort (IterType beg, IterType end, Comparator& cmp)
{
// recursive
// calls quicksort::Partition(beg, end, cmp);
}

// following are the optimized versions

template < class IterType >
void g_quick_sort_opt (IterType beg, IterType end)
{
// implementation required
}

template < class IterType , class Comparator >
void g_quick_sort_opt (IterType beg, IterType end, Comparator& cmp)
{
// implementation required
}

template < typename T >
void g_quick_sort_3w (T* beg, T* end)
{
// implementation required
}

template < typename T , class Comparator >
void g_quick_sort_3w (T* beg, T* end, Comparator& cmp)
{
// implementation required
}

template < class IterType >
void g_quick_sort_3w (IterType beg, IterType end)
{
// implementation required
}

template < class IterType , class Comparator >
void g_quick_sort_3w (IterType beg, IterType end, Comparator& cmp)
{
// implementation required
}

// note: missing are g_merge_sort_opt, g_merge_sort_bu, g_quick_sort_3w_opt

} // namespace fsu
