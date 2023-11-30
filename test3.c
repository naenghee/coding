
#include <stdio.h>
#include <stdlib.h>

int input,mode;

typedef struct node{
  int data;
  struct node *next;
}node;


node* insert(node** head, int input){
  node* newNode = (node*)malloc(sizeof(node));
  newNode->data = input;
  newNode->next = NULL;

  node* cur = *head;

  if(*head == NULL){
    *head = newNode;
    return *head;
  }
  else{
    if(input < cur->data){
      *head = newNode;
      newNode->next = cur;
      return *head;
    }

    else if(input > cur->data){
      while(1){

        if(cur->next == NULL){
          cur->next = newNode;
          break;
        }
        else if(input>cur->data && input<cur->next->data){
          newNode->next = cur->next;
          cur->next = newNode;
          break;
        }
        else{
          cur = cur->next;
        }
      }
    }
//      newNode->next = cur->next;
//      cur->next = newNode;


    }

    return *head;

  }


node* print(node* head){
  node* cur = head;
  while(cur != NULL){
    printf("%d ",cur->data);
    cur = cur ->next;
  }
  printf("\n");
  return 0;
}

int main(void){
  node* head = NULL;
  node* max = NULL;
  while(1){

    printf("삽입 : 1  출력 : 2\n");
    scanf("%d",&mode);
    if(mode == 1){
      printf("삽입할 수를 입력하시오 : ");
      scanf("%d",&input);
      insert(&head,input);
    }
    if(mode == 2){
      print(head);
    }
    node* cur = head;
    while(cur != NULL){
      printf("%d ",cur->data);
      cur= cur->next;
    }
    printf("\n");
  }
  return 0;
}
