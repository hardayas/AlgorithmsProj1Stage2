#include "func.h"

int main(int argc, char * argv[]) {
    struct node *root = NULL;
    root = insert(root, "cut", 11);
    root = insert(root, "at", 112);
    root = insert(root, "cute", 3);
    root = insert(root, "cure", 2);
    root = insert(root, "cat", 555);
    root = insert(root, "car", 64);
    root = insert(root, "pet", 15);
    root = insert(root, "pe", 334);

    char buffer[CHAR_LIMIT]; int weight;
    FILE *f = fopen(argv[1],"r");
    assert(f != NULL);
    while (fscanf(f, "%d;%[^\n]", &weight, buffer) != EOF) {
        root = insert(root, buffer, weight);
    }
    fclose(f);

    //scanf("%s", argv[1]);

    list_t *head = NULL;

    find_and_traverse(root, argv[2], argv[3], &head);
    head = sort(head);

    print_list(head);
    return 0;
}
