#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  FILE *fp;
  char ch;
  int i=0, count=0;

  if((fp=fopen("test.can","r"))==NULL){
    printf("open file error!\n");
    return -1;
  }

  char times[20];
  fscanf(fp, "%[^,]%*c",times);
  printf("%s\n", times);

  char ext[20];
  fscanf(fp, "%[^,]%*c",ext);
  printf("%s\n", ext);

  char remo[20];
  fscanf(fp, "%[^,]%*c",remo);
  printf("%s\n", remo);

  char ids[20];  
  fscanf(fp, "%[^,]%*c",ids);
  printf("%s\n", ids);

  if(strcmp(ids, "18FEF100")==0){
    printf("speed data\n");
  }

  char datas[8][20];
  fscanf(fp, "%[^,]%*c",datas[0]);
  printf("%s\n", datas[0]);

  fscanf(fp, "%[^,]%*c",datas[1]);
  printf("%s\n", datas[1]);

  fscanf(fp, "%[^,]%*c",datas[2]);
  printf("%s\n", datas[2]);

  fscanf(fp, "%[^,]%*c",datas[3]);
  printf("%s\n", datas[3]);

  fscanf(fp, "%[^,]%*c",datas[4]);
  printf("%s\n", datas[4]);

  fscanf(fp, "%[^,]%*c",datas[5]);
  printf("%s\n", datas[5]);

  fscanf(fp, "%[^,]%*c",datas[6]);
  printf("%s\n", datas[6]);

  fscanf(fp, "%[^,]%*c",datas[7]);
  printf("%s\n", datas[7]);

  fclose(fp);
  return 0;
}
