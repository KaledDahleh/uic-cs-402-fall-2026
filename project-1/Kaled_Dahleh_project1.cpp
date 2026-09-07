


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
    // Your code here!
}






int main() {
    /**** STUDENT CODE HERE ****/ 

    // BUBBLE SORT ------------------------------------------------------------------------------

    vector<int> bubble_list1 = {482, 917, 103, 650, 274, 839};
    bubble_sort(bubble_list1, false);
    bool bubble_test_1_success = (bubble_list1 == vector<int>{103, 274, 482, 650, 839, 917});
    if (bubble_test_1_success) {
        cout << "bubble test 1 is a success" << endl;
    } else {
        cout << "bubble test 1 is a failure, got: ";
        print_list(bubble_list1);
    }

    // SELECTION SORT ------------------------------------------------------------------------------

    vector<int> selection_list1 = {482, 917, 103, 650, 274, 839};
    selection_sort(selection_list1, false);
    bool selection_test_1_success = (selection_list1 == vector<int>{103, 274, 482, 650, 839, 917});
    if (selection_test_1_success) {
        cout << "selection test 1 is a success" << endl;
    } else {
        cout << "selection test 1 is a failure, got: ";
        print_list(selection_list1);
    }

    // INSERTION SORT ------------------------------------------------------------------------------

    vector<int> insertion_list1 = {482, 917, 103, 650, 274, 839};
    insertion_sort(insertion_list1, false);
    bool insertion_test_1_success = (insertion_list1 == vector<int>{103, 274, 482, 650, 839, 917});
    if (insertion_test_1_success) {
        cout << "insertion test 1 is a success" << endl;
    } else {
        cout << "insertion test 1 is a failure, got: ";
        print_list(insertion_list1);
    }

    // QUICK SORT ------------------------------------------------------------------------------

    vector<int> quick_list1 = {482, 917, 103, 650, 274, 839};
    quicksort(quick_list1, false);
    bool quick_test_1_success = (quick_list1 == vector<int>{103, 274, 482, 650, 839, 917});
    if (quick_test_1_success) {
        cout << "quick test 1 is a success" << endl;
    } else {
        cout << "quick test 1 is a failure, got: ";
        print_list(quick_list1);
    }

    // MERGE SORT ------------------------------------------------------------------------------

    vector<int> merge_list1 = {482, 917, 103, 650, 274, 839};
    merge_sort(merge_list1, false);
    bool merge_test_1_success = (merge_list1 == vector<int>{103, 274, 482, 650, 839, 917});
    if (merge_test_1_success) {
        cout << "merge test 1 is a success" << endl;
    } else {
        cout << "merge test 1 is a failure, got: ";
        print_list(merge_list1);
    }

    // HYBRID SORT ------------------------------------------------------------------------------

    vector<int> hybrid_list1 = {482, 917, 103, 650, 274, 839};
    my_hybrid_sort(hybrid_list1, false);
    bool hybrid_test_1_success = (hybrid_list1 == vector<int>{103, 274, 482, 650, 839, 917});
    if (hybrid_test_1_success) {
        cout << "hybrid test 1 is a success" << endl;
    } else {
        cout << "hybrid test 1 is a failure, got: ";
        print_list(hybrid_list1);
    }

    // BINARY RADIX SORT ------------------------------------------------------------------------------

    vector<int> binary_radix_list1 = {482, 917, 103, 650, 274, 839};
    binary_radix_sort(binary_radix_list1, false);
    bool binary_radix_test_1_success = (binary_radix_list1 == vector<int>{103, 274, 482, 650, 839, 917});
    if (binary_radix_test_1_success) {
        cout << "binary radix test 1 is a success" << endl;
    } else {
        cout << "binary radix test 1 is a failure, got: ";
        print_list(binary_radix_list1);
    }

    // RADIX SORT ------------------------------------------------------------------------------

    vector<int> radix_list1 = {482, 917, 103, 650, 274, 839};
    radix_sort(radix_list1, 10, false);
    bool radix_test_1_success = (radix_list1 == vector<int>{103, 274, 482, 650, 839, 917});
    if (radix_test_1_success) {
        cout << "radix test 1 is a success" << endl;
    } else {
        cout << "radix test 1 is a failure, got: ";
        print_list(radix_list1);
    }

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

    //vector<int> test_list {1, 2, 3, 4, 5};
    //vector<unsigned int> test_list2 {1, 2, 3, 4, 5};
    //vector<StableChar> test_list3  {};
    //vector<StableInt> test_list4 {};
    //vector<StableString> test_list5 {};
    //vector<short> test_list6  {};
    //vector<unsigned short> test_list7  {};
    //vector<long> test_list8  {};
    //vector<unsigned long> test_list9  {};


    //insertion_sort(test_list);
    //insertion_sort(test_list2);
    //insertion_sort(test_list3);
    //insertion_sort(test_list4);
    //insertion_sort(test_list5);
    //insertion_sort(test_list6);
    //insertion_sort(test_list7);
    //insertion_sort(test_list8);
    //insertion_sort(test_list9);


    //selection_sort(test_list);
    //selection_sort(test_list2);
    //selection_sort(test_list3);
    //selection_sort(test_list4);
    //selection_sort(test_list5);
    //selection_sort(test_list6);
    //selection_sort(test_list7);
    //selection_sort(test_list8);
    //selection_sort(test_list9);

    //bubble_sort(test_list);
    //bubble_sort(test_list2);
    //bubble_sort(test_list3);
    //bubble_sort(test_list4);
    //bubble_sort(test_list5);
    //bubble_sort(test_list6);
    //bubble_sort(test_list7);
    //bubble_sort(test_list8);
    //bubble_sort(test_list9);


    //merge_sort(test_list);
    //merge_sort(test_list2);
    //merge_sort(test_list3);
    //merge_sort(test_list4);
    //merge_sort(test_list5);
    //merge_sort(test_list6);
    //merge_sort(test_list7);
    //merge_sort(test_list8);
    //merge_sort(test_list9);

    //quicksort(test_list);
    //quicksort(test_list2);
    //quicksort(test_list3);
    //quicksort(test_list4);
    //quicksort(test_list5);
    //quicksort(test_list6);
    //quicksort(test_list7);
    //quicksort(test_list8);
    //quicksort(test_list9);

    //my_hybrid_sort(test_list);
    //my_hybrid_sort(test_list2);
    //my_hybrid_sort(test_list3);
    //my_hybrid_sort(test_list4);
    //my_hybrid_sort(test_list5);
    //my_hybrid_sort(test_list6);
    //my_hybrid_sort(test_list7);
    //my_hybrid_sort(test_list8);
    //my_hybrid_sort(test_list9);

    //binary_radix_sort(test_list);
    //binary_radix_sort(test_list2);
    //binary_radix_sort(test_list6);
    //binary_radix_sort(test_list7);
    //binary_radix_sort(test_list8);
    //binary_radix_sort(test_list9);

    //radix_sort(test_list);
    //radix_sort(test_list2);
    //radix_sort(test_list6);
    //radix_sort(test_list7);
    //radix_sort(test_list8);
    //radix_sort(test_list9);


    return 0;
}









