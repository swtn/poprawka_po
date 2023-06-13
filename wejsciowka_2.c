#include <stdio.h>


int main(){
  char A[5][5];
  char* B[25];

  for(int i = 0; i < 25; i++){
    B[i] = NULL;
  }
int asci = 65
  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 5; j++){
      A[i][j] = asci;
      asci++;
    }
  }
  char napis[25];
  printf("Podaj napis, ktory chcesz zaszyfrowac: \n");
  scanf("%s", &napis);


  int k = 0;
  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 5; j++){
        if(napis[k] == A[i][j]){
        B[k] == A[i][j];
        k++;
      }
    }
  }

for(int i = k+1; i < 25; i++){
  B[i] = NULL;
}

int i = 0;
while(B[i] != NULL){
  printf("%c", B[i])
  i++;
}
  return 0;
}
