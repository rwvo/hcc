//===----------------------------------------------------------------------===//
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#pragma once

// sequential versions of algorithms are implemented inside this  file
// FIXME: gradually move them to SPMD-version of algorithms
#include <algorithm>

namespace std {
namespace experimental {
namespace parallel {
inline namespace v1 {

// mismatch
template <typename ExecutionPolicy, typename InputIt1, typename InputIt2>
typename std::enable_if<is_execution_policy<typename std::decay<ExecutionPolicy>::type>::value, std::pair<InputIt1, InputIt2>>::type
mismatch(ExecutionPolicy&& exec,
         InputIt1 first1, InputIt1 last1,
         InputIt2 first2) {
    return std::mismatch(first1, last1, first2);
}

template <typename ExecutionPolicy, typename InputIt1, typename InputIt2, typename BinaryPredicate>
typename std::enable_if<is_execution_policy<typename std::decay<ExecutionPolicy>::type>::value, std::pair<InputIt1, InputIt2>>::type
mismatch(ExecutionPolicy&& exec,
         InputIt1 first1, InputIt1 last1,
         InputIt2 first2,
         BinaryPredicate p) {
    return std::mismatch(first1, last1, first2, p);
}


// equal
template <typename ExecutionPolicy, typename InputIt1, typename InputIt2>
typename std::enable_if<is_execution_policy<typename std::decay<ExecutionPolicy>::type>::value, bool>::type
equal(ExecutionPolicy&& exec,
      InputIt1 first1, InputIt1 last1, 
      InputIt2 first2) {
    return std::equal(first1, last1, first2);
}

template <typename ExecutionPolicy, typename InputIt1, typename InputIt2, typename BinaryPredicate>
typename std::enable_if<is_execution_policy<typename std::decay<ExecutionPolicy>::type>::value, bool>::type
equal(ExecutionPolicy&& exec,
      InputIt1 first1, InputIt1 last1, 
      InputIt2 first2,
      BinaryPredicate p) {
    return std::equal(first1, last1, first2, p);
}

template <typename ExecutionPolicy, typename InputIt1, typename InputIt2>
typename std::enable_if<is_execution_policy<typename std::decay<ExecutionPolicy>::type>::value, bool>::type
equal(ExecutionPolicy&& exec,
      InputIt1 first1, InputIt1 last1, 
      InputIt2 first2, InputIt2 last2) {
    return std::equal(first1, last1, first2, last2);
}

template <typename ExecutionPolicy, typename InputIt1, typename InputIt2, typename BinaryPredicate>
typename std::enable_if<is_execution_policy<typename std::decay<ExecutionPolicy>::type>::value, bool>::type
equal(ExecutionPolicy&& exec,
      InputIt1 first1, InputIt1 last1, 
      InputIt2 first2, InputIt2 last2,
      BinaryPredicate p) {
    return std::equal(first1, last1, first2, last2, p);
}


// find
template <typename ExecutionPolicy, typename InputIt, typename T>
typename std::enable_if<is_execution_policy<typename std::decay<ExecutionPolicy>::type>::value, InputIt>::type
find(ExecutionPolicy&& exec,
     InputIt first, InputIt last,
     const T& value) {
    return std::find(first, last, value);
}


// find_if
template <typename ExecutionPolicy, typename InputIt, typename UnaryPredicate>
typename std::enable_if<is_execution_policy<typename std::decay<ExecutionPolicy>::type>::value, InputIt>::type
find_if(ExecutionPolicy&& exec,
        InputIt first, InputIt last, 
        UnaryPredicate p) {
    return std::find_if(first, last, p);
}


// find_if_not
template <typename ExecutionPolicy, typename InputIt, typename UnaryPredicate>
typename std::enable_if<is_execution_policy<typename std::decay<ExecutionPolicy>::type>::value, InputIt>::type
find_if_not(ExecutionPolicy&& exec,
            InputIt first, InputIt last, 
            UnaryPredicate p) {
    return std::find_if_not(first, last, p);
}


// find_end
template <typename ExecutionPolicy, typename ForwardIt1, typename ForwardIt2>
typename std::enable_if<is_execution_policy<typename std::decay<ExecutionPolicy>::type>::value, ForwardIt1>::type
find_end(ExecutionPolicy&& exec,
         ForwardIt1 first, ForwardIt1 last,
         ForwardIt2 s_first, ForwardIt2 s_last) {
    return std::find_end(first, last, s_first, s_last);
}

template <typename ExecutionPolicy, typename ForwardIt1, typename ForwardIt2, typename BinaryPredicate>
typename std::enable_if<is_execution_policy<typename std::decay<ExecutionPolicy>::type>::value, ForwardIt1>::type
find_end(ExecutionPolicy&& exec,
         ForwardIt1 first, ForwardIt1 last,
         ForwardIt2 s_first, ForwardIt2 s_last,
         BinaryPredicate p) {
    return std::find_end(first, last, s_first, s_last, p);
}


// find_first_of
template <typename ExecutionPolicy, typename InputIt, typename ForwardIt>
typename std::enable_if<is_execution_policy<typename std::decay<ExecutionPolicy>::type>::value, InputIt>::type
find_first_of(ExecutionPolicy&& exec,
              InputIt first, InputIt last,
              ForwardIt s_first, ForwardIt s_last) {
    return std::find_first_of(first, last, s_first, s_last);
}

template <typename ExecutionPolicy, typename InputIt, typename ForwardIt, typename BinaryPredicate>
typename std::enable_if<is_execution_policy<typename std::decay<ExecutionPolicy>::type>::value, InputIt>::type
find_first_of(ExecutionPolicy&& exec,
              InputIt first, InputIt last,
              ForwardIt s_first, ForwardIt s_last,
              BinaryPredicate p) {
    return std::find_first_of(first, last, s_first, s_last, p);
}


// adjacent_find
template <typename ExecutionPolicy, typename ForwardIt>
typename std::enable_if<is_execution_policy<typename std::decay<ExecutionPolicy>::type>::value, ForwardIt>::type
adjacent_find(ExecutionPolicy&& exec,
              ForwardIt first, ForwardIt last) {
    return std::adjacent_find(first, last);
}

template <typename ExecutionPolicy, typename ForwardIt, typename BinaryPredicate>
typename std::enable_if<is_execution_policy<typename std::decay<ExecutionPolicy>::type>::value, ForwardIt>::type
adjacent_find(ExecutionPolicy&& exec,
              ForwardIt first, ForwardIt last,
              BinaryPredicate p) {
    return std::adjacent_find(first, last, p);
}


// search
template <typename ExecutionPolicy, typename ForwardIt1, typename ForwardIt2>
typename std::enable_if<is_execution_policy<typename std::decay<ExecutionPolicy>::type>::value, ForwardIt1>::type
search(ExecutionPolicy&& exec,
       ForwardIt1 first, ForwardIt1 last,
       ForwardIt2 s_first, ForwardIt2 s_last) {
    return std::search(first, last, s_first, s_last);
}

template <typename ExecutionPolicy, typename ForwardIt1, typename ForwardIt2, typename BinaryPredicate>
typename std::enable_if<is_execution_policy<typename std::decay<ExecutionPolicy>::type>::value, ForwardIt1>::type
search(ExecutionPolicy&& exec,
       ForwardIt1 first, ForwardIt1 last,
       ForwardIt2 s_first, ForwardIt2 s_last,
       BinaryPredicate p) {
    return std::search(first, last, s_first, s_last, p);
}


// search_n
template <typename ExecutionPolicy, typename ForwardIt, typename Size, typename T>
typename std::enable_if<is_execution_policy<typename std::decay<ExecutionPolicy>::type>::value, ForwardIt>::type
search_n(ExecutionPolicy&& exec,
         ForwardIt first, ForwardIt last, Size count, const T& value) {
    return std::search_n(first, last, count, value);
}

template <typename ExecutionPolicy, typename ForwardIt, typename Size, typename T, typename BinaryPredicate>
typename std::enable_if<is_execution_policy<typename std::decay<ExecutionPolicy>::type>::value, ForwardIt>::type
search_n(ExecutionPolicy&& exec,
         ForwardIt first, ForwardIt last,
         Size count, const T& value,
         BinaryPredicate p) {
    return std::search_n(first, last, count, value, p);
}


// copy_if
template <typename ExecutionPolicy, typename InputIt, typename OutputIt, typename UnaryPredicate>
typename std::enable_if<is_execution_policy<typename std::decay<ExecutionPolicy>::type>::value, OutputIt>::type
copy_if(ExecutionPolicy&& exec,
        InputIt first, InputIt last,
        OutputIt d_first,
        UnaryPredicate pred) {
    return std::copy_if(first, last, d_first, pred);
}


// move
template <typename ExecutionPolicy, typename InputIt, typename OutputIt>
typename std::enable_if<is_execution_policy<typename std::decay<ExecutionPolicy>::type>::value, OutputIt>::type
move(ExecutionPolicy&& exec,
     InputIt first, InputIt last,
     OutputIt d_first) {
    return std::move(first, last, d_first);
}


// remove
template <typename ExecutionPolicy, typename ForwardIt, typename T>
typename std::enable_if<is_execution_policy<typename std::decay<ExecutionPolicy>::type>::value, ForwardIt>::type
remove(ExecutionPolicy&& exec,
       ForwardIt first, ForwardIt last,
       const T& value) {
    return std::remove(first, last, value);
}


// remove_if
template <typename ExecutionPolicy, typename ForwardIt, typename UnaryPredicate>
typename std::enable_if<is_execution_policy<typename std::decay<ExecutionPolicy>::type>::value, ForwardIt>::type
remove_if(ExecutionPolicy&& exec,
          ForwardIt first, ForwardIt last,
          UnaryPredicate p) {
    return std::remove_if(first, last, p);
}


// remove_copy
template <typename ExecutionPolicy, typename InputIt, typename OutputIt, typename T>
typename std::enable_if<is_execution_policy<typename std::decay<ExecutionPolicy>::type>::value, OutputIt>::type
remove_copy(ExecutionPolicy&& exec,
            InputIt first, InputIt last,
            OutputIt d_first,
            const T& value) {
    return std::remove_copy(first, last, d_first, value);
}


// remove_copy_if
template <typename ExecutionPolicy, typename InputIt, typename OutputIt, typename UnaryPredicate>
typename std::enable_if<is_execution_policy<typename std::decay<ExecutionPolicy>::type>::value, OutputIt>::type
remove_copy_if(ExecutionPolicy&& exec,
               InputIt first, InputIt last,
               OutputIt d_first,
               UnaryPredicate p) {
    return std::remove_copy_if(first, last, d_first, p);
}


// reverse
template <typename ExecutionPolicy, typename BidirIt>
typename std::enable_if<is_execution_policy<typename std::decay<ExecutionPolicy>::type>::value, void>::type
reverse(ExecutionPolicy&& exec,
        BidirIt first, BidirIt last) {
    return std::reverse(first, last);
}


// reverse_copy
template <typename ExecutionPolicy, typename BidirIt, typename OutputIt>
typename std::enable_if<is_execution_policy<typename std::decay<ExecutionPolicy>::type>::value, OutputIt>::type
reverse_copy(ExecutionPolicy&& exec,
             BidirIt first, BidirIt last,
             OutputIt d_first) {
    return reverse_copy(first, last, d_first);
}


// rotate
template <typename ExecutionPolicy, typename ForwardIt>
typename std::enable_if<is_execution_policy<typename std::decay<ExecutionPolicy>::type>::value, ForwardIt>::type
rotate(ExecutionPolicy&& exec,
       ForwardIt first, ForwardIt n_first, ForwardIt last) {
    return std::rotate(first, n_first, last);
}

// rotate_copy
template <typename ExecutionPolicy, typename ForwardIt, typename OutputIt>
typename std::enable_if<is_execution_policy<typename std::decay<ExecutionPolicy>::type>::value, OutputIt>::type
rotate_copy(ExecutionPolicy&& exec,
            ForwardIt first, ForwardIt n_first, ForwardIt last,
            OutputIt d_first) {
    return std::rotate_copy(first, n_first, last, d_first);
}


// unique
template <typename ExecutionPolicy, typename ForwardIt>
typename std::enable_if<is_execution_policy<typename std::decay<ExecutionPolicy>::type>::value, ForwardIt>::type
unique(ExecutionPolicy&& exec,
       ForwardIt first, ForwardIt last) {
    return std::unique(first, last);
}

template <typename ExecutionPolicy, typename ForwardIt, typename BinaryPredicate>
typename std::enable_if<is_execution_policy<typename std::decay<ExecutionPolicy>::type>::value, ForwardIt>::type
unique(ExecutionPolicy&& exec,
       ForwardIt first, ForwardIt last,
       BinaryPredicate p) {
    return std::unique(first, last, p);
}


// unique_copy
template <typename ExecutionPolicy, typename InputIt, typename OutputIt>
typename std::enable_if<is_execution_policy<typename std::decay<ExecutionPolicy>::type>::value, OutputIt>::type
unique_copy(ExecutionPolicy&&,
            InputIt first, InputIt last,
            OutputIt d_first) {
    return std::unique_copy(first, last, d_first);
}

template <typename ExecutionPolicy, typename InputIt, typename OutputIt, typename BinaryPredicate>
typename std::enable_if<is_execution_policy<typename std::decay<ExecutionPolicy>::type>::value, OutputIt>::type
unique_copy(ExecutionPolicy&& exec,
            InputIt first, InputIt last,
            OutputIt d_first,
            BinaryPredicate p) {
    return std::unique_copy(first, last, d_first, p);
}


// is_partitioned
template <typename ExecutionPolicy, typename InputIt, typename UnaryPredicate>
typename std::enable_if<is_execution_policy<typename std::decay<ExecutionPolicy>::type>::value, bool>::type
is_partitioned(ExecutionPolicy&& exec,
               InputIt first, InputIt last,
               UnaryPredicate p) {
    return std::is_partitioned(first, last, p);
}


// partition
template <typename ExecutionPolicy, typename ForwardIt, typename UnaryPredicate>
typename std::enable_if<is_execution_policy<typename std::decay<ExecutionPolicy>::type>::value, ForwardIt>::type
partition(ExecutionPolicy&& exec,
          ForwardIt first, ForwardIt last,
          UnaryPredicate p) {
    return std::partition(first, last, p);
}


// partition_copy
template <typename ExecutionPolicy, typename InputIt, typename OutputIt1, typename OutputIt2, typename UnaryPredicate>
typename std::enable_if<is_execution_policy<typename std::decay<ExecutionPolicy>::type>::value, std::pair<OutputIt1, OutputIt2>>::type
partition_copy(ExecutionPolicy&& exec,
               InputIt first, InputIt last,
               OutputIt1 d_first_true,
               OutputIt2 d_first_false,
               UnaryPredicate p) {
    return std::partition_copy(first, last, d_first_true, d_first_false, p);
}


// stable_partition
template <typename ExecutionPolicy, typename BidirIt, typename UnaryPredicate>
typename std::enable_if<is_execution_policy<typename std::decay<ExecutionPolicy>::type>::value, BidirIt>::type
stable_partition(ExecutionPolicy&& exec,
                 BidirIt first, BidirIt last,
                 UnaryPredicate p) {
    return std::stable_partition(first, last, p);
}


// is_sorted
template <typename ExecutionPolicy, typename ForwardIt>
typename std::enable_if<is_execution_policy<typename std::decay<ExecutionPolicy>::type>::value, bool>::type
is_sorted(ExecutionPolicy&& exec,
          ForwardIt first, ForwardIt last) {
    return is_sorted(first, last);
}

template <typename ExecutionPolicy, typename ForwardIt, typename Compare>
typename std::enable_if<is_execution_policy<typename std::decay<ExecutionPolicy>::type>::value, bool>::type
is_sorted(ExecutionPolicy&& exec,
          ForwardIt first, ForwardIt last,
          Compare comp) {
    return is_sorted(first, last, comp);
}


// is_sorted_until
template <typename ExecutionPolicy, typename ForwardIt>
typename std::enable_if<is_execution_policy<typename std::decay<ExecutionPolicy>::type>::value, ForwardIt>::type
is_sorted_until(ExecutionPolicy&& exec,
                ForwardIt first, ForwardIt last) {
    return std::is_sorted_until(first, last);
}

template <typename ExecutionPolicy, typename ForwardIt, typename Compare>
typename std::enable_if<is_execution_policy<typename std::decay<ExecutionPolicy>::type>::value, ForwardIt>::type
is_sorted_until(ExecutionPolicy&& exec,
                ForwardIt first, ForwardIt last, 
                Compare comp) {
    return std::is_sorted_until(first, last, comp);
}


// sort
template <typename ExecutionPolicy, typename RandomIt>
typename std::enable_if<is_execution_policy<typename std::decay<ExecutionPolicy>::type>::value, void>::type
sort(ExecutionPolicy&& exec,
     RandomIt first, RandomIt last) {
    return std::sort(first, last);
}

template <typename ExecutionPolicy, typename RandomIt, typename Compare>
typename std::enable_if<is_execution_policy<typename std::decay<ExecutionPolicy>::type>::value, void>::type
sort(ExecutionPolicy&& exec,
     RandomIt first, RandomIt last,
     Compare comp) {
    return std::sort(first, last, comp);
}


// partial_sort
template <typename ExecutionPolicy, typename RandomIt>
typename std::enable_if<is_execution_policy<typename std::decay<ExecutionPolicy>::type>::value, void>::type
partial_sort(ExecutionPolicy&& exec,
             RandomIt first, RandomIt middle, RandomIt last) {
    return std::partial_sort(first, middle, last);
}


template <typename ExecutionPolicy, typename RandomIt, typename Compare>
typename std::enable_if<is_execution_policy<typename std::decay<ExecutionPolicy>::type>::value, void>::type
partial_sort(ExecutionPolicy&& exec,
             RandomIt first, RandomIt middle, RandomIt last,
             Compare comp) {
    return std::partial_sort(first, middle, last, comp);
}


// partial_sort_copy
template <typename ExecutionPolicy, typename InputIt, typename RandomIt>
typename std::enable_if<is_execution_policy<typename std::decay<ExecutionPolicy>::type>::value, RandomIt>::type
partial_sort_copy(ExecutionPolicy&& exec,
                  InputIt first, InputIt last,
                  RandomIt d_first, RandomIt d_last) {
    return std::partial_sort_copy(first, last, d_first, d_last);
}

template <typename ExecutionPolicy, typename InputIt, typename RandomIt, typename Compare>
typename std::enable_if<is_execution_policy<typename std::decay<ExecutionPolicy>::type>::value, RandomIt>::type
partial_sort_copy(ExecutionPolicy&& exec,
                  InputIt first, InputIt last,
                  RandomIt d_first, RandomIt d_last,
                  Compare comp) {
    return std::partial_sort_copy(first, last, d_first, d_last, comp);
}


// stable_sort
template <typename ExecutionPolicy, typename RandomIt>
typename std::enable_if<is_execution_policy<typename std::decay<ExecutionPolicy>::type>::value, void>::type
stable_sort(ExecutionPolicy&& exec,
            RandomIt first, RandomIt last) {
    return std::stable_sort(first, last);
}

template <typename ExecutionPolicy, typename RandomIt, typename Compare>
typename std::enable_if<is_execution_policy<typename std::decay<ExecutionPolicy>::type>::value, void>::type
stable_sort(ExecutionPolicy&& exec,
            RandomIt first, RandomIt last,
            Compare comp) {
    return std::stable_sort(first, last, comp);
}


// nth_element
template <typename ExecutionPolicy, typename RandomIt>
typename std::enable_if<is_execution_policy<typename std::decay<ExecutionPolicy>::type>::value, void>::type
nth_element(ExecutionPolicy&& exec,
            RandomIt first, RandomIt nth, RandomIt last) {
    return std::nth_element(first, nth, last);
}

template <typename ExecutionPolicy, typename RandomIt, typename Compare>
typename std::enable_if<is_execution_policy<typename std::decay<ExecutionPolicy>::type>::value, void>::type
nth_element(ExecutionPolicy&& exec,
            RandomIt first, RandomIt nth, RandomIt last,
            Compare comp) {
    return std::nth_element(first, nth, last);
}


// merge
template <typename ExecutionPolicy, typename InputIt1, typename InputIt2, typename OutputIt>
typename std::enable_if<is_execution_policy<typename std::decay<ExecutionPolicy>::type>::value, OutputIt>::type
merge(ExecutionPolicy&& exec,
      InputIt1 first1, InputIt1 last1,
      InputIt2 first2, InputIt2 last2,
      OutputIt d_first) {
    return std::merge(first1, last1, first2, last2, d_first);
}

template <typename ExecutionPolicy, typename InputIt1, typename InputIt2, typename OutputIt, typename Compare>
typename std::enable_if<is_execution_policy<typename std::decay<ExecutionPolicy>::type>::value, OutputIt>::type
merge(ExecutionPolicy&& exec,
      InputIt1 first1, InputIt1 last1,
      InputIt2 first2, InputIt2 last2,
      OutputIt d_first, Compare comp) {
    return std::merge(first1, last1, first2, last2, d_first, comp);
}


// inplace_merge
template <typename ExecutionPolicy, typename BidirIt>
typename std::enable_if<is_execution_policy<typename std::decay<ExecutionPolicy>::type>::value, void>::type
inplace_merge(ExecutionPolicy&& exec,
              BidirIt first, BidirIt middle, BidirIt last) {
    return std::inplace_merge(first, middle, last);
}

template <typename ExecutionPolicy, typename BidirIt, typename Compare>
typename std::enable_if<is_execution_policy<typename std::decay<ExecutionPolicy>::type>::value, void>::type
inplace_merge(ExecutionPolicy&& exec,
              BidirIt first, BidirIt middle, BidirIt last, Compare comp) {
    return std::inplace_merge(first, middle, last, comp);
}


// includes
template <typename ExecutionPolicy, typename InputIt1, typename InputIt2>
typename std::enable_if<is_execution_policy<typename std::decay<ExecutionPolicy>::type>::value, bool>::type
includes(ExecutionPolicy&& exec,
         InputIt1 first1, InputIt1 last1,
         InputIt2 first2, InputIt2 last2) {
    return std::includes(first1, last1, first2, last2);
}

template <typename ExecutionPolicy, typename InputIt1, typename InputIt2, typename Compare>
typename std::enable_if<is_execution_policy<typename std::decay<ExecutionPolicy>::type>::value, bool>::type
includes(ExecutionPolicy&& exec,
         InputIt1 first1, InputIt1 last1,
         InputIt2 first2, InputIt2 last2,
         Compare comp) {
    return std::includes(first1, last1, first2, last2, comp);
}


// set_difference
template <typename ExecutionPolicy, typename InputIt1, typename InputIt2, typename OutputIt>
typename std::enable_if<is_execution_policy<typename std::decay<ExecutionPolicy>::type>::value, OutputIt>::type
set_difference(ExecutionPolicy&& exec,
               InputIt1 first1, InputIt1 last1,
               InputIt2 first2, InputIt2 last2,
               OutputIt d_first) {
    return std::set_difference(first1, last1, first2, last2, d_first);
}

template <typename ExecutionPolicy, typename InputIt1, typename InputIt2, typename OutputIt, typename Compare>
typename std::enable_if<is_execution_policy<typename std::decay<ExecutionPolicy>::type>::value, OutputIt>::type
set_difference(ExecutionPolicy&& exec,
               InputIt1 first1, InputIt1 last1,
               InputIt2 first2, InputIt2 last2,
               OutputIt d_first,
               Compare comp) {
    return std::set_difference(first1, last2, first2, last2, d_first, comp);
}


// set_intersection
template <typename ExecutionPolicy, typename InputIt1, typename InputIt2, typename OutputIt>
typename std::enable_if<is_execution_policy<typename std::decay<ExecutionPolicy>::type>::value, OutputIt>::type
set_intersection(ExecutionPolicy&& exec,
                 InputIt1 first1, InputIt1 last1,
                 InputIt2 first2, InputIt2 last2,
                 OutputIt d_first) {
    return std::set_intersection(first1, last1, first2, last2, d_first);
}

template <typename ExecutionPolicy, typename InputIt1, typename InputIt2, typename OutputIt, typename Compare>
typename std::enable_if<is_execution_policy<typename std::decay<ExecutionPolicy>::type>::value, OutputIt>::type
set_intersection(ExecutionPolicy&& exec,
                 InputIt1 first1, InputIt1 last1,
                 InputIt2 first2, InputIt2 last2,
                 OutputIt d_first, Compare comp) {
    return std::set_intersection(first1, last1, first2, last2, d_first, comp);
}


// set_symmetric_difference
template <typename ExecutionPolicy, typename InputIt1, typename InputIt2, typename OutputIt>
typename std::enable_if<is_execution_policy<typename std::decay<ExecutionPolicy>::type>::value, OutputIt>::type
set_symmetric_difference(ExecutionPolicy&& exec,
                         InputIt1 first1, InputIt1 last1,
                         InputIt2 first2, InputIt2 last2,
                         OutputIt d_first) {
    return std::set_symmetric_difference(first1, last1, first2, last2, d_first);
}

template <typename ExecutionPolicy, typename InputIt1, typename InputIt2, typename OutputIt, typename Compare>
typename std::enable_if<is_execution_policy<typename std::decay<ExecutionPolicy>::type>::value, OutputIt>::type
set_symmetric_difference(ExecutionPolicy&& exec,
                         InputIt1 first1, InputIt1 last1,
                         InputIt2 first2, InputIt2 last2,
                         OutputIt d_first,
                         Compare comp) {
    return std::set_symmetric_difference(first1, last1, first2, last2, d_first, comp);
}


// set_union
template <typename ExecutionPolicy, typename InputIt1, typename InputIt2, typename OutputIt>
typename std::enable_if<is_execution_policy<typename std::decay<ExecutionPolicy>::type>::value, OutputIt>::type
set_union(ExecutionPolicy&& exec,
          InputIt1 first1, InputIt1 last1,
          InputIt2 first2, InputIt2 last2,
          OutputIt d_first) {
    return std::set_union(first1, last1, first2, last2, d_first);
}

template <typename ExecutionPolicy, typename InputIt1, typename InputIt2, typename OutputIt, typename Compare>
typename std::enable_if<is_execution_policy<typename std::decay<ExecutionPolicy>::type>::value, OutputIt>::type
set_union(ExecutionPolicy&& exec,
          InputIt1 first1, InputIt1 last1,
          InputIt2 first2, InputIt2 last2,
          OutputIt d_first,
          Compare comp) {
    return std::set_union(first1, last1, first2, last2, d_first, comp);
}


// is_heap
template <typename ExecutionPolicy, typename RandomIt>
typename std::enable_if<is_execution_policy<typename std::decay<ExecutionPolicy>::type>::value, bool>::type
is_heap(ExecutionPolicy&& exec,
        RandomIt first, RandomIt last) {
    return std::is_heap(first, last);
}

template <typename ExecutionPolicy, typename RandomIt, typename Compare>
typename std::enable_if<is_execution_policy<typename std::decay<ExecutionPolicy>::type>::value, bool>::type
is_heap(ExecutionPolicy&& exec,
        RandomIt first, RandomIt last,
        Compare comp) {
    return std::is_heap(first, last, comp);
}


// is_heap_until
template <typename ExecutionPolicy, typename RandomIt>
typename std::enable_if<is_execution_policy<typename std::decay<ExecutionPolicy>::type>::value, RandomIt>::type
is_heap_until(ExecutionPolicy&& exec,
              RandomIt first, RandomIt last) {
    return std::is_heap_until(first, last);
}

template <typename ExecutionPolicy, typename RandomIt, typename Compare>
typename std::enable_if<is_execution_policy<typename std::decay<ExecutionPolicy>::type>::value, RandomIt>::type
is_heap_until(ExecutionPolicy&& exec,
              RandomIt first, RandomIt last,
              Compare comp) {
    return is_heap_until(first, last, comp);
}


// lexicographical_compare
template <typename ExecutionPolicy, typename InputIt1, typename InputIt2>
typename std::enable_if<is_execution_policy<typename std::decay<ExecutionPolicy>::type>::value, bool>::type
lexicographical_compare(ExecutionPolicy&& exec,
                        InputIt1 first1, InputIt1 last1,
                        InputIt2 first2, InputIt2 last2) {
    return std::lexicographical_compare(first1, last1, first2, last2);
}

template <typename ExecutionPolicy, typename InputIt1, typename InputIt2, typename Compare>
typename std::enable_if<is_execution_policy<typename std::decay<ExecutionPolicy>::type>::value, bool>::type
lexicographical_compare(ExecutionPolicy&& exec,
                        InputIt1 first1, InputIt1 last1,
                        InputIt2 first2, InputIt2 last2,
                        Compare comp) {
    return std::lexicographical_compare(first1, last1, first2, last2, comp);
}

} // inline namespace v1
} // namespace parallel
} // namespace experimental 
} // namespace std

