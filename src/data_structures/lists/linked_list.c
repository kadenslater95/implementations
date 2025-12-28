
/**
 * @copyright  Copyright (C) 2024 Kaden Slater. All Rights Reserved.
 * @license    GNU General Public License version 2 or later; see LICENSE.txt
 */

#include <stdio.h>
#include <stdlib.h>

#include "data_structures/lists/linked_list.h"


/**
 * Given the current tail, adds the new_node to the list and sets it as the current tail,
 * or allocates the tail if nil.
 *
 * @param tail [int_llnode **] pointer to current tail node's pointer, or nil
 * @param value [int] value to store in the newly added node
*/
void add_llnode(int_llnode **tail, int value) {
  int_llnode *new_tail = malloc(sizeof(int_llnode));
  new_tail->value = value;
  new_tail->next = NULL;

  if (*tail) {
    (*tail)->next = new_tail;
  }

  *tail = new_tail;
}


/**
 * Given the current head and a value, it iterates through the linked_list and removes the first occurence of the
 * value if it is found, and re-addresses the head if needed.
 * Note: If you keep track of the tail (for speed) then you should pass that reference with calls to
 * this method so that it gets updated appropriately if the value being removed is in the tail.
 *
 * @param head [int_llnode **] pointer to current head node's pointer
 * @param tail [int_llnode **] pointer to current tail
 * @param value [int] value to find first occurence of to determine node to remove
*/
void remove_llnode(int_llnode **head, int_llnode **tail, int value) {
  if (!head) {
    return;
  }

  int_llnode *current = *head;
  int_llnode *prev = NULL;
  while (current) {
    if (current->value == value) {
      if (prev) {
        prev->next = current->next;

        // If the node getting removed is the tail, then update the tail
        // reference to be the node before it
        if ( !(current->next) ) {
          *tail = prev;
        }
      } else {
        // Note: This handles setting head to null if it was the only item
        // in the list, which makes an "if (head)" check fail as expected
        *head = current->next;

        // If this was the only node in the list, then update the tail
        // to null so that "if (tail)" checks will fail
        if (tail && !(current->next)) {
          *tail = NULL;
        }
      }

      free(current);

      return;
    }

    prev = current;
    current = prev->next;
  }
}


/**
 * Given the current head, it iterates through the linked_list and calls free on all the nodes
 *
 * @param head [int_llnode **] pointer to current head node's pointer
 * @param tail [int_llnode **] pointer to current tail node's pointer
*/
void clear_llnode(int_llnode **head, int_llnode **tail) {
    int_llnode *current = *head;
    int_llnode *prev = NULL;
    while (current) {
        prev = current;
        current = prev->next;

        free(prev);
    }

    // Have to set head to null because free alone just makes the memory
    // accessible again but won't make an "if (head)" check fail
    if (head) {
      *head = NULL;
    }
    if (tail) {
      *tail = NULL;
    }
}


/**
 * Given the current head, it iterates through the linked_list and prints out the contents in a readable format.
 *
 * @param head [int_llnode *] pointer to current head node
*/
void print_llnode(int_llnode *head) {
    printf("Linked List Contents:\n\t");

    int_llnode *current = head;
    while (current) {
        printf("%d", current->value);

        current = current->next;

        if (current) {
            printf(" --> ");
        }
    }

    printf("\n");
}
