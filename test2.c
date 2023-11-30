#include <stdio.h>
#define SIZE 100
int mode,input;
typedef struct graph{
  int size;
  int adj[SIZE][SIZE];
}graph;

void clear(graph* head){
  head->size = NULL;
  for(int i = 0; i < SIZE; i++){
    for(int j = 0; j<SIZE; j++){
      head->adj[i][j] = 0;
    }
  }
}

void addv(graph* head){
  if(head->size >= SIZE){
    printf("���� �߰� ����\n");
  }
  else{
    head->size++;
  }
}

void add(graph* head, int v1, int v2){
  if(v1 > head->size || v2 > head->size){
    printf("���� �߰� ����\n");
  }
  else{
    for(int i = 0; i < head->size; i++){
      for(int j = 0; j<head->size; j++){
        head->adj[v1][v2] = 1;
        head->adj[v2][v1] = 1;
      }
    }
  }
}
void deg(graph* head,int input){
  int cnt = 0;
  for(int i = 0; i<head->size; i++){
    if(head->adj[input][i] == 1){
      cnt++;
    }

  }
  printf("������ : %d\n",cnt);
}

void adj_node(graph* head, int input){
  for(int i = 0; i<head->size; i++){
    if(head->adj[input][i] == 1){
      printf("���� ��� ��ȣ : %d\n",i+1);
    }
  }
}
void print(graph* head){ //print
  for(int i = 0; i<head->size; i++){
    for(int j = 0; j<head->size; j++){
      printf("%d ",head->adj[i][j]);
    }
    printf("\n");
  }
}

int main(void){
  graph graph;
  clear(&graph);
  for(int i = 0; i<5; i++){ //���� 5�� ����
    addv(&graph);
  }
  add(&graph,0,1);
  add(&graph,0,3);
  add(&graph,1,2);
  add(&graph,1,3);
  add(&graph,1,4);
  add(&graph,2,4);
  add(&graph,3,4);
//   adj_node(&graph);
  while(1){
    printf("1:������ 2:�������\n");
    scanf("%d",&mode);
    if(mode == 1){
      printf("��� ��ȣ �Է� : ");
      scanf("%d",&input);
      deg(&graph,input-1);
    }
    if(mode == 2){
      printf("��� ��ȣ �Է� : ");
      scanf("%d",&input);
      adj_node(&graph,input-1);
      //print(&graph);
    }
  }

  return 0;
}
