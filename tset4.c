#include <stdio.h>
#include <stdlib.h>
int input, mode;

typedef struct node {
  struct node *right;
  int data;
  struct node *left;
} node;

node *insert(node **head, int input) {
  node *newNode = (node *)malloc(sizeof(node));
  newNode->data = input;
  newNode->right = NULL;
  newNode->left = NULL;

  node *cur = *head;
  if (*head == NULL) {
    *head = newNode;
    return *head;
  } else {
    while (cur != NULL) {

      if (input > cur->data) { // input이 더 클 때

        if (cur->right == NULL) {
          cur->right = newNode;
          return *head;
        }
        cur = cur->right;
      } else if (input < cur->data) { // input이 더 작을 때

        if (cur->left == NULL) {
          cur->left = newNode;
          return *head;
        }
        cur = cur->left;
      }
    }
  }
}

void inorder(node *head) {
  if (head->left != NULL) {
    inorder(head->left);
  }
  printf("%d ", head->data);
  if (head->right != NULL) {
    inorder(head->right);
  }
}

int main(void) {
  node *head = NULL;

  while (1) {
    printf("삽입 : 1  출력 : 2\n");
    scanf("%d", &mode);
    if (mode == 1) {
      printf("삽입할 수를 입력하시오 : ");
      scanf("%d", &input);
      insert(&head, input);
    }
    if (mode == 2) {
      inorder(head);
      printf("\n");
    }
  }
  return 0;
}
