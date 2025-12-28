
/**
 * @copyright  Copyright (C) 2024 Kaden Slater. All Rights Reserved.
 * @license    GNU General Public License version 2 or later; see LICENSE.txt
 */

#include <stdlib.h>

#include <gtest/gtest.h>

#include "data_structures/lists/linked_list.h"


/*
  Tests that when you try to remove from an empty list it just returns
*/
TEST(RemoveLLNodeTest, EmptyDoesNothing) {
  int_llnode *head = NULL;

  remove_llnode(&head, NULL, 1);

  // If no error or seg fault occurred I will reach this succeed call
  SUCCEED();
}

/*
  Tests that when you remove a value that isn't in the non-empty list it
  just returns
*/
TEST(RemoveLLNodeTest, RemoveNonExistantValue) {
  int_llnode *head = NULL;
  int_llnode *tail = NULL;

  add_llnode(&head, 1);
  tail = head;
  add_llnode(&tail, 2);
  add_llnode(&tail, 3);

  remove_llnode(&head, &tail, 7);

  // Everything should still be in the list
  int_llnode *current = head;
  EXPECT_EQ(current->value, 1);

  current = current->next;
  EXPECT_EQ(current->value, 2);

  current = current->next;
  EXPECT_EQ(current->value, 3);
  EXPECT_EQ(current, tail);

  if (head) {
      clear_llnode(&head, &tail);
  }
}

/*
  Tests that when you remove the value that is the only item in the list then
  any "if (head)" and "if (tail)" checks will fail as expected
*/
TEST(RemoveLLNodeTest, RemoveOnlyItem) {
  int_llnode *head = NULL;
  int_llnode *tail = NULL;

  add_llnode(&head, 1);
  tail = head;

  remove_llnode(&head, &tail, 1);

  EXPECT_FALSE(head);
  EXPECT_FALSE(tail);
}

/*
  Tests that it updates the head if you remove the first value in a list with
  multiple items
*/
TEST(RemoveLLNodeTest, UpdatesHeadIfRemoved) {
  int_llnode *head = NULL;
  int_llnode *tail = NULL;

  add_llnode(&head, 1);
  tail = head;
  add_llnode(&tail, 2);
  add_llnode(&tail, 3);

  remove_llnode(&head, &tail, 1);

  EXPECT_EQ(head->value, 2);
  EXPECT_EQ(head->next, tail);

  if (head) {
      clear_llnode(&head, &tail);
  }
}

/*
  Tests that it removes a value that is in the middle of the list
*/
TEST(RemoveLLNodeTest, RemoveFromMiddle) {
  int_llnode *head = NULL;
  int_llnode *tail = NULL;

  add_llnode(&head, 1);
  tail = head;
  add_llnode(&tail, 2);
  add_llnode(&tail, 3);

  remove_llnode(&head, &tail, 2);

  EXPECT_EQ(head->value, 1);
  EXPECT_EQ(head->next, tail);
  EXPECT_EQ(tail->value, 3);
  EXPECT_FALSE(tail->next);

  if (head) {
      clear_llnode(&head, &tail);
  }
}

/*
  Tests that it updates the tail if you remove the last value in a list
  with multiple items
*/
TEST(RemoveLLNodeTest, UpdatesTailIfRemoved) {
  int_llnode *head = NULL;
  int_llnode *tail = NULL;

  add_llnode(&head, 1);
  tail = head;
  add_llnode(&tail, 2);
  add_llnode(&tail, 3);

  remove_llnode(&head, &tail, 3);

  EXPECT_EQ(head->value, 1);
  EXPECT_EQ(head->next, tail);
  EXPECT_EQ(tail->value, 2);
  EXPECT_FALSE(tail->next);

  if (head) {
      clear_llnode(&head, &tail);
  }
}
