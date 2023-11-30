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

      if (input > cur->data) { // input�� �� Ŭ ��

        if (cur->right == NULL) {
          cur->right = newNode;
          return *head;
        }
        cur = cur->right;
      } else if (input < cur->data) { // input�� �� ���� ��

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
    printf("���� : 1  ��� : 2\n");
    scanf("%d", &mode);
    if (mode == 1) {
      printf("������ ���� �Է��Ͻÿ� : ");
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
