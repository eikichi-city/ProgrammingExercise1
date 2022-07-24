#include <stdio.h>
int main() {
//数字を片っ端から当てはめる
  for(int i=1;i<10;i++){
    for(int j=1;j<10;j++){
      if(j==i){
//条件が合わなかったらスキップする
      continue;
    }
      for(int k=1;k<10;k++){
        if (i==k || j==k){
          continue;
        }
        for(int l=1;l<10;l++){
          if (i==l || j==l || k==l){
            continue;
          }
//命題通りになるかを選別する
          if ((i*10+j)/(k*10+l)==3 && ((i*10+j)%(k*10+l))==0){
            int a=i*10+j;
            int b=k*10+l;
            printf("%d, %d\n",a,b);
          }
        }
      }
    }
  }
}