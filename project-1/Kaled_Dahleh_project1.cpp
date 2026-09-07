


#include <iostream>
#include <algorithm>
#include <chrono>
#include <concepts>
#include <type_traits>

#include "testing.h"
#include "Kaled_Dahleh_project1.h"

using namespace std;

/****************
 * INSTRUCTIONS *
 ****************
 *
 * - Replace all instances of "Firstname_Lastname" with your firstname and
 *   your last name. This include the .h and .cpp files, along with the
 *   header guards at the top of the .h file.
 *
 * - Implement the appropriate algorithms as described below.
 *   You must follow the specifications as written
 *   below (e.g., stability, in-place, etc.).
 *
 * - DO NOT MODIFY THE FUNCTION SIGNATURES!!!
 *
 * - You are allowed to add helper functions. Be sure to add the appropriate
 *   function prototypes in "Fistname_Lastname_project1.h".
 *
 * - The file "testing.cpp" has various functions you can utilize to test
 *   your code. You can also add your own tests!
 *
 * - If you are working in a group, please modify the comments directly below.
 *
 */


/** This please add your name here as well **/
const std::string who_am_i() {
    return "Kaled_Dahleh";
}


/*** GROUP PROJECT ***/
// Please list ALL of your other group members as comments below.
//   Member 1
//   Member 2



/* Bubble Sort 
 *
 * 5 points
 * 
 * Algorithm: Continuously compare adjacent elements and swap them if necessary.
 *            This is a stable, in-place sorting algorithm. Your implementation must be in-place.
 *
 * Parameters:
 *  vector<T> &list: reference to a list of type T. You can assume this type
 *                   has all of the normal binary comparison operators such
 *                   as <, >, ==, !=, etc.
 *  bool decending:  if true, then sort in descending order; otherwise sort
 *                   in ascending order (the default)
 * */
template<typename T>
void bubble_sort(vector<T> &list, bool descending) {
    if (list.size() <= 1) {
        return;
    }
    int swaps = 1;
    while (swaps > 0) {
        swaps = 0;
        for (int i = 0; i < list.size() - 1; i++) {
            if ((list[i] > list[i + 1] && descending == false) || (list[i] < list[i + 1] && descending == true)) {
                T temp = list[i];
                list[i] = list[i + 1];
                list[i + 1] = temp;
                swaps += 1;
            }
        }
    }
}














/* Selection Sort 
 *
 * 5 points
 * 
 * Algorithm: Continuously finds the minimium (or maximum) element in the list, 
 *            then swaps it with the first non-sorted element of the list.
 *            This is an unstable, in-place sorting algorithm. 
 *            Your implementation must be in-place.
 *
 * Parameters:
 *  vector<T> &list: reference to a list of type T. You can assume this type
 *                   has all of the normal binary comparison operators such
 *                   as <, >, ==, !=, etc.
 *  bool decending:  if true, then sort in descending order; otherwise sort
 *                   in ascending order (the default)
 * */
template<typename T>
void selection_sort(vector<T> &list, bool descending) {
    if (list.size() <= 1) {
        return;
    }
    for (int i = 0; i < list.size() - 1; i++) { // starting index
        T best = list[i]; // smallest or largest depending on 'descending'
        int best_index = i;
        for (int j = i + 1; j < list.size(); j++) {
            if ((list[j] < best && descending == false) || (list[j] > best && descending == true)) {
                best = list[j];
                best_index = j;
            }
        }

        if (best_index != i){ // need a swap
            T temp = list[i];
            list[i] = list[best_index];
            list[best_index] = temp;
        }
    }
}















/* Insertion Sort 
 *
 * 5 points
 * 
 * Algorithm: Iterates through the list and inserts the current element into
 *            the correct sorted position of the prefix of the list.
 *            This is a stable, in-place sorting algorithm. Your implementation
 *            does not need to be in-place.
 *
 * Parameters:
 *  vector<T> &list: reference to a list of type T. You can assume this type
 *                   has all of the normal binary comparison operators such
 *                   as <, >, ==, !=, etc.
 *  bool decending:  if true, then sort in descending order; otherwise sort
 *                   in ascending order (the default)
 * */
//template<typename T>
//void insertion_sort(vector<T> &list, bool descending = false);
template<typename T>
void insertion_sort(vector<T> &list, bool descending) {
    if (list.size() <= 1) {
        return;
    }
    for (int i = 1; i < list.size(); i++) {
        int pos = i;
        while ((pos - 1 >= 0) && (
            ((list[pos-1] > list[pos]) && descending == false) ||
            ((list[pos-1] < list[pos]) && descending == true) ) 
        ) {
            // need a swap
            T temp = list[pos];
            list[pos] = list[pos - 1];
            list[pos - 1] = temp;

            pos -= 1;
        }
    }
}







/* Quicksort 
 *
 * 10 points
 * 
 * Algorithm: Sorts by first choosing a random pivot from the list, then 
 *            partitioning the list into two halves with respect to the 
 *            pivot, then recursing on each half.
 *            This is an unstable sorting algorithm. Not required to be
 *            implemented as an in-place sort.
 *            
 *
 * Parameters:
 *  vector<T> &list: reference to a list of type T. You can assume this type
 *                   has all of the normal binary comparison operators such
 *                   as <, >, ==, !=, etc.
 *  bool decending:  if true, then sort in descending order; otherwise sort
 *                   in ascending order (the default)
 *
 * */
template<typename T>
void quicksort(vector<T> &list, bool descending) {

    if (list.size() <= 1) {
        return;
    }

    int pivot = get_rand_index(list.size());

    vector<T> smaller;
    vector<T> greater;
    for (int i = 0; i < list.size(); i++) {
        if (list[i] < list[pivot]) {
            smaller.push_back(list[i]);
        }
        else if (i != pivot) {
            greater.push_back(list[i]);
        }
    }
    quicksort(smaller, descending);
    quicksort(greater, descending);
    if (descending) {
        greater.push_back(list[pivot]);
        greater.insert(greater.end(), smaller.begin(), smaller.end());
        list = greater;
    }
    else {
        smaller.push_back(list[pivot]);
        smaller.insert(smaller.end(), greater.begin(), greater.end());
        list = smaller;
    }
}








/* Merge Sort 
 *
 * 10 points
 * 
 * Algorithm: Sorts the list by recursively sorting the left and right
 *            halves, then merging the two left and right halves together.
 *            This is a stable sorting algorithm. Not required to be implemented
 *            as an in-place sort.
 *
 * Parameters:
 *  vector<T> &list: reference to a list of type T. You can assume this type
 *                   has all of the normal binary comparison operators such
 *                   as <, >, ==, !=, etc.
 *  bool decending:  if true, then sort in descending order; otherwise sort
 *                   in ascending order (the default)
 *
 * */
template<typename T>
void merge_sort(vector<T> &list, bool decending) {
    if (list.size() <= 1) {
        return;
    }
    int mid_point = list.size() / 2;
    
    vector<T> left;
    vector<T> right;
    for (int i = 0; i < list.size(); i++) {
        if (i < list.size() / 2) {
            left.push_back(list[i]);
        }
        else {
            right.push_back(list[i]);
        }
    }
    merge_sort(left, decending);
    merge_sort(right, decending);
    
    // intertwine two sorted halves
    int left_idx = 0;
    int right_idx = 0;
    vector<T> res;

    while ((left_idx < left.size()) || (right_idx < right.size())){
        if (left_idx < left.size() && right_idx < right.size()) {
            if (left[left_idx] < right[right_idx]) {
                if (decending) {
                    res.push_back(right[right_idx]);
                    right_idx++;
                }
                else {
                    res.push_back(left[left_idx]);
                    left_idx++;
                }
            }
            else {
                if (decending) {
                    res.push_back(left[left_idx]);
                    left_idx++;
                }
                else {
                    res.push_back(right[right_idx]);
                    right_idx++;
                }
            }
        }
        else if (left_idx < left.size()) {
            res.push_back(left[left_idx]);
            left_idx++;
        }
        else {
            res.push_back(right[right_idx]);
            right_idx++;
        }
    }
    list = res;
}















/* Your Hybrid Sort
 *
 * 20 points
 *
 * Algorithm: Your own custom Hybrid Sorting algorithm! Remember, a hybrid
 *            sort tries to take advantage of two (or more) sorting algorithms
 *            to speed up data processing.
 *
 * Parameters:
 *  vector<T> &list: reference to a list of type T. You can assume this type
 *                   has all of the normal binary comparison operators such
 *                   as <, >, ==, !=, etc.
 *  bool decending:  if true, then sort in descending order; otherwise sort
 *                   in ascending order (the default)
 *
 */
template<typename T>
void my_hybrid_sort(vector<T> &list, bool descending) {
    if (list.size() <= 1) {
        return;
    }
    else if (list.size() < 128) { // insertion sort



        for (int i = 1; i < list.size(); i++) {
            int pos = i;
            while ((pos - 1 >= 0) && (
                ((list[pos-1] > list[pos]) && descending == false) ||
                ((list[pos-1] < list[pos]) && descending == true) ) 
            ) {
                // need a swap
                T temp = list[pos];
                list[pos] = list[pos - 1];
                list[pos - 1] = temp;

                pos -= 1;
            }
        }



    }
    else { // quick sort



        int pivot = get_rand_index(list.size());

        vector<T> smaller;
        vector<T> greater;
        for (int i = 0; i < list.size(); i++) {
            if (list[i] < list[pivot]) {
                smaller.push_back(list[i]);
            }
            else if (i != pivot) {
                greater.push_back(list[i]);
            }
        }
        my_hybrid_sort(smaller, descending);
        my_hybrid_sort(greater, descending);
        if (descending) {
            greater.push_back(list[pivot]);
            greater.insert(greater.end(), smaller.begin(), smaller.end());
            list = greater;
        }
        else {
            smaller.push_back(list[pivot]);
            smaller.insert(smaller.end(), greater.begin(), greater.end());
            list = smaller;
        }



    }
}


/* Binary Radix Sort
 *
 * 20 points, EXTRA CREDIT
 *
 * Algorithm:
 *
 * Parameters: 
 *   vector<T> &list: reference to a list of type T.
 *                    IMPORTANT: this type T is assumed to be *integral*. It
 *                    can be any of the following integral types in C++:
 *                      - (unsigned) short int
 *                      - (unsigned) int
 *                      - (unsigned) long int
 *
 * Additional Information:
 *   - If you are enrolled in the undergraduate section of this course, this
 *     function is optional and worth extra credit.
 */
//template<class T>
//concept Integral = std::is_integral<T>::value;
template<Integral T> 
void binary_radix_sort(vector<T> &list, bool descending) {
    // Your code here!
}



/* Base B Radix Sort 
 *
 * 25 Points
 *
 * Algorithm: Implement Radix Sort as discussed in class, but with
 *            respect to any unspecified base.
 *
 * Parameters: 
 *   vector<T> &list: reference to a list of type T.
 *                    IMPORTANT: this type T is assumed to be *integral*. It
 *                    can be any of the following integral types in C++:
 *                      - (unsigned) short int
 *                      - (unsigned) int
 *                      - (unsigned) long int
 *
 *   unsigned int base: the base with which to implement the radix sort. 
 *                      Note that base should be at least 2. The default
 *                      base is 10.
 *
 *   bool decending: if true, then sort in descending order; otherwise sort
 *                   in ascending order (the default).
 *
 */
template<Integral T>
void radix_sort(vector<T> &list, unsigned int base, bool descending) {

    if (list.size() <= 1) {
        return;
    }


    vector<T> negatives;
    vector<T> positives;
    for (T num : list) { // splut list by sign
        if (num < 0) {
            negatives.push_back(-num);
        }
        else {
            positives.push_back(num);
        }
    }

    // sort by size, flip back, then combine
    if (!negatives.empty()) {
        radix_sort(negatives, base, false);
        reverse(negatives.begin(), negatives.end());
        for (int i = 0; i < negatives.size(); i++) {
            negatives[i] = -negatives[i];
        }
        radix_sort(positives, base, false);
        negatives.insert(negatives.end(), positives.begin(), positives.end());
        list = negatives;
        if (descending) {
            reverse(list.begin(), list.end());
        }
        return;
    }


    // get max num digits
    T largest_element = *max_element(list.begin(), list.end());
    string T_as_string = to_string(largest_element);
    int length_of_longest = T_as_string.size();

    vector<T> order_so_far = list;

    for (int digit_to_extract = 0; digit_to_extract < length_of_longest; digit_to_extract++){ // for each digit

        vector<vector<T>> frequencies(base);
        for (int i = 0; i < order_so_far.size(); i++) { // counting sort

            // get digit
            int extracted_digit = (order_so_far[i] / (int)pow(base, digit_to_extract)) % base;
            frequencies[extracted_digit].push_back(order_so_far[i]);

        }

        order_so_far.clear();
        for (vector<T> freq : frequencies) {
            for (T num : freq) {
                order_so_far.push_back(num);
            }
        }
    }
    list = order_so_far;
    if (descending) {
        reverse(list.begin(), list.end());
    }
}






int main() {
    /**** STUDENT CODE HERE ****/ 

    /**** END STUDENT CODE ****/

    /***** DO NOT MODIFY BELOW THIS LINE *****/
    /*** INSTRUCTIONS ***
     *
     * Before submitting your code: 
     *   - remove all code within the main function that you have written above the `do-not-modify` line;
     *   - uncomment all lines below that begin with "//".
     *   - NOTE: you can uncomment the code below if you are testing your code with the autograder. The 
     *     autograder will throw an error if you run it without uncommenting the code.
     */

    vector<int> test_list {1, 2, 3, 4, 5};
    vector<unsigned int> test_list2 {1, 2, 3, 4, 5};
    vector<StableChar> test_list3  {};
    vector<StableInt> test_list4 {};
    vector<StableString> test_list5 {};
    vector<short> test_list6  {};
    vector<unsigned short> test_list7  {};
    vector<long> test_list8  {};
    vector<unsigned long> test_list9  {};


    insertion_sort(test_list);
    insertion_sort(test_list2);
    insertion_sort(test_list3);
    insertion_sort(test_list4);
    insertion_sort(test_list5);
    insertion_sort(test_list6);
    insertion_sort(test_list7);
    insertion_sort(test_list8);
    insertion_sort(test_list9);


    selection_sort(test_list);
    selection_sort(test_list2);
    selection_sort(test_list3);
    selection_sort(test_list4);
    selection_sort(test_list5);
    selection_sort(test_list6);
    selection_sort(test_list7);
    selection_sort(test_list8);
    selection_sort(test_list9);

    bubble_sort(test_list);
    bubble_sort(test_list2);
    bubble_sort(test_list3);
    bubble_sort(test_list4);
    bubble_sort(test_list5);
    bubble_sort(test_list6);
    bubble_sort(test_list7);
    bubble_sort(test_list8);
    bubble_sort(test_list9);


    merge_sort(test_list);
    merge_sort(test_list2);
    merge_sort(test_list3);
    merge_sort(test_list4);
    merge_sort(test_list5);
    merge_sort(test_list6);
    merge_sort(test_list7);
    merge_sort(test_list8);
    merge_sort(test_list9);

    quicksort(test_list);
    quicksort(test_list2);
    quicksort(test_list3);
    quicksort(test_list4);
    quicksort(test_list5);
    quicksort(test_list6);
    quicksort(test_list7);
    quicksort(test_list8);
    quicksort(test_list9);

    my_hybrid_sort(test_list);
    my_hybrid_sort(test_list2);
    my_hybrid_sort(test_list3);
    my_hybrid_sort(test_list4);
    my_hybrid_sort(test_list5);
    my_hybrid_sort(test_list6);
    my_hybrid_sort(test_list7);
    my_hybrid_sort(test_list8);
    my_hybrid_sort(test_list9);

    binary_radix_sort(test_list);
    binary_radix_sort(test_list2);
    binary_radix_sort(test_list6);
    binary_radix_sort(test_list7);
    binary_radix_sort(test_list8);
    binary_radix_sort(test_list9);

    radix_sort(test_list);
    radix_sort(test_list2);
    radix_sort(test_list6);
    radix_sort(test_list7);
    radix_sort(test_list8);
    radix_sort(test_list9);


    return 0;
}









