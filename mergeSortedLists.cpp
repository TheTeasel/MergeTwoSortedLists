/*
 *  Read the readme.md for more detail about the problem.
 *  You can find this problem at https://leetcode.com/problems/merge-two-sorted-lists/
 */
#include <iostream>

/*
 * Quick struct representing a node in a liked list
 */
struct ListNode{
    int         value; //Value in the node
    ListNode*   next;  //Next node
    ListNode(int x) : value(x), next(NULL){};
};

/*
 * THE MERGE FUNCTION
 */
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
    ListNode* dummy(0);                 //We create a dummy in case l1 or l2 are empty
                                        //The value doesn't matter, it'll not be compared to anything
    ListNode* last = &dummy;            //Initially the last node will be the dummy

    //Until we reach the end of l1 or l2
    while(l1 != NULL and l2 != NULL){
        //If l1 is smaller than l2
        if(l1->value < l2->value){
            //Then the next element of the last node will be l1
            last->next = l1;
            //The last element will be l1 as well
            last = l1;
            //Then we'll consider the next element of l1
            l1 = l1->next;
        }
        //If l1 is bigger than l2
        else{
            //The next element of the last node will be l2
            last->next = l2;
            //The last element will be l2 as well
            last = l2;
            //We'll consider the next element of l2
            l2 = l2->next;
        }
    }

    //If we reached the end of l2
    if(l1 != NULL)
        //The next element of the combined list will be l1
        //(we append the rest of l1 to the combined list)
        last->next = l1;

    //If we reached the end of l1
    //(we append the rest of l2 to the combined list)
    if(l2 != NULL)
        //The next element of the combined list will be l2
        last->next = l2;

    //We don't return the dummy node but its next element (the first element of the combined list)
    return dummy.next;
}
