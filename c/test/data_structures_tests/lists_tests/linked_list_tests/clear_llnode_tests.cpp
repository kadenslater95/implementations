

/**
 * @copyright  Copyright (C) 2024 Kaden Slater. All Rights Reserved.
 * @license    GNU General Public License version 2 or later; see LICENSE.txt
 */

#include <stdlib.h>

#include <gtest/gtest.h>

#include "data_structures/lists/linked_list.h"


/*
  Tests that when you try to clear an empty list it just returns
*/
TEST(ClearLLNodeTest, EmptyDoesNothing) {
  int_llnode *head = NULL;

  clear_llnode(&head, NULL);

  // If no error or seg fault occurred I will reach this succeed call
  SUCCEED();
}

/*
  Tests that when you clear a list that only has 1 item then
  any "if (head)" and "if (tail)" checks will fail as expected
*/
TEST(ClearLLNodeTest, ClearOnlyOneItem) {
  int_llnode *head = NULL;
  int_llnode *tail = NULL;

  add_llnode(&head, 1);
  tail = head;

  clear_llnode(&head, &tail);

  EXPECT_FALSE(head);
  EXPECT_FALSE(tail);
}

/*
  Tests that when you clear a list that has multiple items then
  any "if (head)" and "if (tail)" checks will fail as expected
*/
TEST(ClearLLNodeTest, ClearMultipleItems) {
  int_llnode *head = NULL;
  int_llnode *tail = NULL;

  add_llnode(&head, 1);
  tail = head;

  clear_llnode(&head, &tail);

  EXPECT_FALSE(head);
  EXPECT_FALSE(tail);
}
