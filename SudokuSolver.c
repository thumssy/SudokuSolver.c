/*******************************
 *        SUDOKU SOLVER        *
 *      ^^^^^^^^^^^^^^^^       *
 *          By T90             *
 *******************************/
 
#include <stdio.h>

int mat[9][9];
 
int findZero(int *row,int *col){
  int i,j;
  for (i=0;i<9;i++)
    for (j=0;j<9;j++)
      if (mat[i][j]==0){
          *row=i;
          *col=j;
          return 1;
        }
  return 0;
}

int canPlace(int row,int col,int num){
  int i,j;
  for (i=0;i<9;i++){
    if (mat[i][col] == num)
        return 0;
    if (mat[row][i] == num)
        return 0;
  }
  for (i=0;i<3;i++)
    for (j=0;j<3;j++)
       if (mat[i+(row-row%3)][j+(col-col%3)] == num)
           return 0;
  return 1;
}

int FillMatrix(){
  int row, col, num;
  if (!findZero(&row,&col))
    return 1;
  for (num=1;num<=9;num++){
    if (canPlace(row, col, num)){
      mat[row][col] = num;
      if (FillMatrix())
        return 1;
      mat[row][col] = 0;
      }
    }
  return 0;
}

void printMatrix(){
  int i,j;
  for (i=0;i<9;i++){
      if(i%3==0)
        printf("\n");
      printf("\n\t");
      for (j=0;j<9;j++){
        printf("%d ",mat[i][j]);
        if(j%3==2)
          printf("\t");
      }
    }
  printf("\n");
}

void getMatrix(char *name){
  int i,j;
  FILE *f;
  f=fopen(name,"r");
  for (i=0;i<9;i++)
    for (j=0;j<9;j++)
        fscanf(f,"%d",&mat[i][j]);
}
 
void main(int argc, char* name[]){
  if(argc>1){
    getMatrix(name[1]);
    printf("\n\tInput Matrix\n");
    printMatrix();
    if (FillMatrix()==1){
      printf("\n\tResult ^_^\n");
      printMatrix();
    }
    else
      printf("\nUnable to Solve :'(\n");
    }
  else 
    printf("\nNo File Specified!!!\n");
}