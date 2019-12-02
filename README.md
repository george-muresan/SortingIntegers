# SortingIntegers
Comparing two methods of sorting through lists of integers. They include the merge sort method & the move to front method

Merge Sort: Splits the array into halves until there are just the integers themselves, and then it calls a merge method
            to sort this numbers back up in order into the array again. Although being fast, it holds a larger space
            complexity, because of the multiple arrays needing to be made in order to merge sort through the numbers.
         
Move to Front: Implements a linked list and by reading and iterating through a different list, moves individual integers
               to the front of the list

Comparison: The Merge Sort through the ordered list is faster than the Move to Front method. This is because it doesn’t
            need to iterate through a whole list of numbers. It is able to keep dividing those numbers until a base point
            in which it starts building on top of its self. That being said, the Move to Front method is better with the
            space complexity because it is a single linked list that move its own nodes around in order to bring integers
            to the front. This is the optimal efficiency and by not iterating through the linked list, it would have a better
            time complexity as well. 
