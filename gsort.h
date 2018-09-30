/*
gsort.h
10/3/2014
Amir Yousef
g_selection_sort    # version in class notes
g_insertion_sort    # already implemented in gsort_stub.h
g_merge_sort        # the pure top-down version from the class notes
g_merge_sort_bu     # the bottom-up version from the class notes
g_merge_sort_opt    # the top-down version with "cutoff" and conditional calls to merge
g_quick_sort        # the pure version from the class notes and Cormen
g_quick_sort_opt    # the same as above, with "cutoff" for small ranges
g_quick_sort_3w     # 3-way QuickSort
g_quick_sort_3w_opt # 3-way QuickSort, with "cutoff" for small ranges
*/

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
if (cmp (*j , *k))
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
for (k = i, j = k--; j != beg && cmp (t,*k); --j, --k)
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
void Merge (RAIterator beg, RAIterator mid, RAIterator end)
{
typename RAIterator::ValueType  B [end - beg];   			 
g_set_merge (beg, mid, mid, end, B);      					 
g_copy (B, B+ (end-beg), beg);             				 
}

template < typename RAIterator , class Comparator >
void Merge (RAIterator beg, RAIterator mid, RAIterator end, Comparator& cmp)
{
typename RAIterator::ValueType  B [end - beg];
g_set_merge (beg, mid, mid, end, B, cmp);
g_copy (B, B+ (end-beg), beg);
}

template < typename T >
void Merge (T* beg, T* mid, T* end)
{
T B [end - beg];                     
g_set_merge (beg, mid, mid, end, B); 
g_copy (B, B+ (end-beg), beg);       
}

template < typename T , class Comparator >
void Merge (T* beg, T* mid, T* end, Comparator& cmp)
{
T B [end - beg];
g_set_merge (beg, mid, mid, end, B, cmp);
g_copy (B, B+(end-beg), beg);
}

} 

template < class RAIterator >
void g_merge_sort (RAIterator beg, RAIterator end)
{
RAIterator mid;
size_t size = end - beg;
if (size > 1)
{
mid = beg + (size/2);
g_merge_sort (beg, mid);
g_merge_sort (mid, end);
mergesort::Merge (beg, mid, end);
}
else return;
}

template < class RAIterator, class Comparator >
void g_merge_sort (RAIterator beg, RAIterator end, Comparator& cmp)
{
RAIterator mid;
size_t size = end - beg;
if (size > 1)
{
mid = beg + (size/2);
g_merge_sort (beg, mid, cmp);
g_merge_sort (mid, end, cmp);
mergesort::Merge (beg, mid, end, cmp);
}
else return;
}

template < class RAIterator >
void g_merge_sort_bu (RAIterator beg, RAIterator end)
{
RAIterator mid;
size_t size = end - beg;
if (size > 1)
{
mid = beg + (size/2);
g_merge_sort_bu (beg, mid);
g_merge_sort_bu (mid, end);
mergesort::Merge (beg, mid, end);
}
else return;
}

template < class RAIterator, class Comparator >
void g_merge_sort_bu (RAIterator beg, RAIterator end, Comparator& cmp)
{
RAIterator mid;
size_t size = end - beg;
if (size > 1)
{
mid = beg + (size/2);
g_merge_sort_bu (beg, mid, cmp);
g_merge_sort_bu (mid, end, cmp);
mergesort::Merge (beg, mid, end, cmp);
}
else return;
}

template < class RAIterator >
void g_merge_sort_opt (RAIterator beg, RAIterator end)
{
RAIterator mid;
size_t size = end - beg;
if (size > 1)
{
mid = beg + (size/2);
g_merge_sort_opt (beg, mid);
g_merge_sort_opt (mid, end);
mergesort::Merge (beg, mid, end);
}
else return;
}

template < class RAIterator, class Comparator>
void g_merge_sort_opt (RAIterator beg, RAIterator end, Comparator& cmp)
{
RAIterator mid;
size_t size = end - beg;
if (size > 1)
{
mid = beg + (size/2);
g_merge_sort_opt (beg, mid, cmp);
g_merge_sort_opt (mid, end, cmp);
mergesort::Merge (beg, mid, end, cmp);
}
else return;
}

namespace quicksort
{

template < class IterType >
IterType Partition (IterType first, IterType last)  
{
IterType pivot = first;  
for (IterType j = first; j != last; ++j)
{
if (!(*last < *j)) 
{
Swap (*pivot,*j);
++pivot;
}
}
Swap (*pivot,*last);
return pivot;
}

template < class IterType , class P >
IterType Partition (IterType first, IterType last, P& cmp) 
{
IterType pivot = first;  
for (IterType j = first; j != last; ++j)
{
if (cmp(*last, *j)) 
{
Swap (*pivot,*j);
++pivot;
}
}
Swap (*pivot,*last);
return pivot;
}

} 

template < class IterType >
void g_quick_sort (IterType beg, IterType end)
{
size_t size = end - beg;
IterType part = beg + (size/2);
if (size > 1)
{
g_quick_sort (beg, part);
g_quick_sort (part, end);
mergesort::Merge (beg, part, end);
}
else return;
}

template < class IterType , class Comparator >
void g_quick_sort (IterType beg, IterType end, Comparator& cmp)
{
size_t size = end - beg;
IterType part = beg + (size/2);
if (size > 1)
{
g_quick_sort (beg, part, cmp);
g_quick_sort (part, end, cmp);
mergesort::Merge (beg, part, end, cmp);
}
else return;
}

template < class IterType >
void g_quick_sort_opt (IterType beg, IterType end)
{
size_t size = end - beg;
IterType part = beg + (size/2);
if (size > 1)
{
g_quick_sort_opt (beg, part);
g_quick_sort_opt (part, end);
mergesort::Merge (beg, part, end);
}
else return;
}

template < class IterType , class Comparator >
void g_quick_sort_opt (IterType beg, IterType end, Comparator& cmp)
{
size_t size = end - beg;
IterType part = beg + (size/2);
if (size > 1)
{
g_quick_sort_opt (beg, part, cmp);
g_quick_sort_opt (part, end, cmp);
mergesort::Merge (beg, part, end, cmp);
}
else return;
}

template < typename T >
void g_quick_sort_3w (T* beg, T* end)
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
void g_quick_sort_3w (T* beg, T* end, Comparator& cmp)
{
T *i, *j, *k;
for (i = beg; i != end; ++i)
{
k = i;
for (j = i; j != end; ++j)
if (cmp (*j , *k))
k = j;
Swap (*i, *k);
}
}

template < class IterType >
void g_quick_sort_3w (IterType beg, IterType end)
{
size_t size = end - beg;
IterType part = beg + (size/2);
if (size > 1)
{
g_quick_sort_3w (beg, part);
g_quick_sort_3w (part, end);
mergesort::Merge (beg, part, end);
}
else return;
}
template < class IterType , class Comparator >
void g_quick_sort_3w (IterType beg, IterType end, Comparator& cmp)
{
size_t size = end - beg;
IterType part = beg + (size/2);
if (size > 1)
{
g_quick_sort_3w (beg, part, cmp);
g_quick_sort_3w (part, end, cmp);
mergesort::Merge (beg, part, end, cmp);
}
else return;
}

template < class IterType >
void g_quick_sort_3w_opt (IterType beg, IterType end)
{
size_t size = end - beg;
IterType part = beg + (size/2);
if (size > 1)
{
g_quick_sort_3w_opt (beg, part);
g_quick_sort_3w_opt (part, end);
mergesort::Merge (beg, part, end);
}
else return;
}

template < class IterType , class Comparator >
void g_quick_sort_3w_opt (IterType beg, IterType end, Comparator& cmp)
{
size_t size = end - beg;
IterType part = beg + (size/2);
if (size > 1)
{
g_quick_sort_3w_opt (beg, part, cmp);
g_quick_sort_3w_opt (part, end, cmp);
mergesort::Merge (beg, part, end, cmp);
}
else return;
}

}  
