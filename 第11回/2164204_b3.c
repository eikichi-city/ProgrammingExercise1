#include <stdio.h>
#define N 10
int data[N][N]={
  {8,8,8,8,8,8,8,8,8,8},
  {8,1,0,0,8,8,0,0,0,8},
  {8,0,8,0,0,0,0,8,0,8},
  {8,0,8,8,8,0,8,8,0,8},
  {8,0,0,8,8,0,0,8,0,8},
  {8,8,0,0,8,0,8,8,0,8},
  {8,0,8,0,8,0,0,8,0,8},
  {8,0,0,0,8,8,0,0,0,8},
  {8,8,8,0,0,0,0,8,0,8},
  {8,8,8,8,8,8,8,8,9,8}};

//結果出力用関数
void output(int n,FILE *fp) 
{
    fprintf(fp,"%2d回でゴール\n",n);
    for(int y=0;y<N;y++){
        for(int x=0;x<N;x++){
            if(data[y][x]==2||data[y][x]==9)
                fprintf(fp,"○ ");
            else
                fprintf(fp,"■ ");
        }
        fprintf(fp,"\n");
    }
}

//探索用関数
void search(int n,int x,int y,FILE *fp) 
{
    //値によって処理を変える
    switch (data[y][x]) {
        case 0:
            data[y][x] = 2; //2は通った印
        case 1:
            break;
        case 9:
            output(n,fp);
        default:
            return;
    }
    if (x>0) search(n+1,x-1,y,fp);
    if (y>0) search(n+1,x,y-1,fp);
    if (x<N-1) search(n+1,x+1,y,fp);
    if (y<N-1) search(n+1,x,y+1,fp);
    if (data[y][x]==2) data[y][x] = 0;
}

int main(int argc,char *argv[]) {
    FILE *fp;
    fp=fopen(argv[1], "w");
    for (int i=0;i<N;i++) 
    {
        for (int j=0;j<N;j++) 
        {
            if (data[i][j]==1) 
            {
                data[i][j]=0;
                search(0,i,j,fp);
            }
        }
    }
    fclose(fp);
    return 0;
}