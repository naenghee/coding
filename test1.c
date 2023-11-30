#include <stdio.h>
int rear = 0;
int front = 0;

int arr[4] = {};
int input,mode;

int insert(int input){
  if(rear == 4){
    rear = 0;
  }
  if(arr[rear] == NULL){
    arr[rear] = input;
    rear++;
    return 0;
  }
  else{
    printf("Full\n");
    return 0;
  }
}
void del(){
  if(arr[front] == NULL){
    printf("삭제할 데이터가 없습니다.\n");
    return;
  }
  if(front == 4){
    front = 0;
    arr[front] = 0;
    front++;
  }
  else{
    arr[front] = 0;
    front++;
    return;
  }
}

int main(void){
  while(1){
    printf("삽입 : 1 삭제 : 2\n");
    scanf("%d",&mode);
    if(mode == 1){
      printf("삽입할 수를 입력하시오 : ");
      scanf("%d",&input);
      insert(input);
    }
    if(mode == 2){
      del();
    }
    for(int i = 0; i<4; i++){
      printf("%d ",arr[i]);
    }
    printf("\n");
    printf("rear : %d  front : %d\n",rear,front);
  }
  return 0;
}
