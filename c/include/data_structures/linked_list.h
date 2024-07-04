
/**
 * @copyright  Copyright (C) 2024 Kaden Slater. All Rights Reserved. 
 * @license    GNU General Public License version 2 or later; see LICENSE.txt
 */

// Some things cannot be extern'd so you need to use an include guard
#ifndef C_INCLUDE_DATA_STRUCTURES_LINKED_LIST_H_
#define C_INCLUDE_DATA_STRUCTURES_LINKED_LIST_H_

// Make this C library callable from C++
#ifdef __cplusplus
extern "C" {
#endif  // __cplusplus


// Struct that holds a node for a Linked List with int values
typedef struct int_llnode {
  int value;
  struct int_llnode *next;
} int_llnode;


/*
 * Given the current tail, adds the new_node to the list and sets it as the current tail, 
 * or allocates the tail if nil.
 * 
 * @param tail [int_llnode *] pointer to current tail node, or nil
 * @param value [int] pointer to new tail node
*/
void add_node(int_llnode **tail, int value);


#ifdef __cplusplus
}
#endif  // __cplusplus

#endif  // C_INCLUDE_DATA_STRUCTURES_LINKED_LIST_H_
