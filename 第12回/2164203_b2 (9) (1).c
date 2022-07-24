#include <stdio.h>
struct object {
	char name[20];  /* 名称 */
	int weight;     /* 重さ  */
};
#define N 5
struct object b[N] ={ /* {名称,重さ} */
	{"A",7},{"B",4},{"C",5},{"D",6},{"E",3}
};

int limw = 15;/*条件重量*/

//関数の宣言
void check(int i, int tw,int sel[N],int t);
void print_set(int i,int sel[N]);
void empty_set(int s[],int n);


int main(void)
{
	int i;
	int sel[N];
//sel[N]を空にしている
	empty_set(sel,N); 
	check(0,0,sel,0);
	return 0;
}


void empty_set(int s[], int n)
{
	while(n>0) {
		n--; s[n]=0;
	}
}
void print_set(int w,int sel[N]){
    		/* 結果の印刷 */
		for(int i=0; i<w; i++){
	        printf(" %s：%dｔ", b[sel[i]].name,b[sel[i]].weight);
	    }
	    printf("\n");
    
}

void check(int w, int tw,int sel[N],int t)
{
	for(int i=w;i<N;++i){
	  sel[t]=i;
      if(tw + b[i].weight == limw)   print_set(t+1,sel);
      if (tw + b[i].weight >= limw)  continue;          
	  check(i+1,tw+b[i].weight,sel,t+1);
	}
}
