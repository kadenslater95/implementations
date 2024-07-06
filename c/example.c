
/**
 * @copyright  Copyright (C) 2024 Kaden Slater. All Rights Reserved.
 * @license    GNU General Public License version 2 or later; see LICENSE.txt
 */

#include <stdio.h>
#include <stdlib.h>

#include "data_structures/linked_list.h"

int main(int argc, char **argv) {
    int_llnode *head = NULL;
    int_llnode *tail = NULL;

    add_llnode(&head, 1);
    tail = head;
    add_llnode(&tail, 2);
    add_llnode(&tail, 3);

    printf("Full List\n");
    print_llnode(head);

    remove_llnode(&head, 2);

    printf("\nThis time will remove 2\n");
    print_llnode(head);

    remove_llnode(&head, 2);

    printf("\nThis time won't remove anything\n");
    print_llnode(head);

    remove_llnode(&head, 1);

    printf("\nThis time will remove 1\n");
    print_llnode(head);

    remove_llnode(&head, 3);

    printf("\nThis time will remove 3\n");
    print_llnode(head);

    remove_llnode(&head, 5);
    printf("\nThis time won't remove anything\n");
    print_llnode(head);

    add_llnode(&head, 1);
    tail = head;
    add_llnode(&tail, 2);
    add_llnode(&tail, 3);

    printf("\nShould all be added back\n");
    print_llnode(head);

    clear_llnode(&head);

    printf("\nShould be cleared out\n");
    print_llnode(head);

    return 0;
}
