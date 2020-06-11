#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void check_ID(char *id){
 if(strcmp(id, "18FEF100")==0){
    printf("speed data\n");
  }
}

void check_ext(char *ex){
  if(strcmp(ex, "1")==0){
    printf("Extend Frame\n");
  }else{
    printf("Base Frame\n");
  }
}

void check_remo(char *rem){
  if(strcmp(rem, "1")==0){
    printf("Remote Frame\n");
  }else{
    printf("Data Frame\n");
  }
}

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
  check_ext(ext);  

  char remo[20];
  fscanf(fp, "%[^,]%*c",remo);
  check_remo(remo);

  char ids[20];  
  fscanf(fp, "%[^,]%*c",ids);
  check_ID(ids);

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
