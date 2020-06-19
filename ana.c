#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// hex to number
float getNum(char ch){
  float num = 0;
  if(ch>='0' && ch<='9'){
    num = ch - '0';
  }else{
    switch(ch)
    {
      case 'A': case 'a': num = 10; break;
      case 'B': case 'b': num = 11; break;
      case 'C': case 'c': num = 12; break;
      case 'D': case 'd': num = 13; break;
      case 'E': case 'e': num = 14; break;
      case 'F': case 'f': num = 15; break;
      default: num=0;
    }
  }
  return num;
}

float HextoInt(char* hex1, char* hex2){
  float speed = (4096*getNum(hex2[0]) + 256*getNum(hex2[1]) + 16*getNum(hex1[0]) + getNum(hex1[1]))/256;
  return speed;
}

int check_gear(char* hex1){
  if(hex1[0]=='4'&&hex1[1]=='E'){
    return 1;
  }else if(hex1[0]=='5'&&hex1[1]=='2'){
    return 2;
  }else if(hex1[0]=='4'&&hex1[1]=='4'){
    return 3;
  }else{
    return 4;
  }
  //printf("char1: %c char2: %c\n",hex1[0],hex1[1]); 
}

// print times data
void check_times(char *times){
  printf("time:%s\n", times);
}

//Check the data ID
int check_ID(char *id){
  if(strcmp(id, "18FEF100")==0){
    printf("data is speed\n");
    return 1;
  }
  if(strcmp(id, "18F00503")==0){
    printf("data is gear\n");
    return 2;
  }
  return 0;
}

// Check extend or base frame
void check_ext(char *ex){
  if(strcmp(ex, "1")==0){
    printf("Extend Frame\n");
  }else{
    printf("Base Frame\n");
  }
}

//Check frame
void check_remo(char *rem){
  if(strcmp(rem, "1")==0){
    printf("Remote Frame\n");
  }else{
    printf("Data Frame\n");
  }
}

// print the meaning of data frame
void check_mean(int cata, char **datas){
  if(cata==1){
    float speed = HextoInt(datas[1], datas[2]);
    printf("speed data: %f\n", speed);
  }
  if(cata==2){
    printf("Gear data is %s\n", datas[7]);
    int gear_data = check_gear(datas[7]);
    if(gear_data==1){
      printf("Gear: N\n");
    }else if(gear_data==2){
      printf("Gear: R\n");
    }else if(gear_data==3){
      printf("Gear: D\n");
    }else{
      printf("Not define data\n");
    }
    /*
    if(strcmp(datas[7], "4E")==0){
      printf("Gear data: N\n");
    }else if(strcmp(datas[7], "52")==0){
      printf("Gear data: R\n");
    }else if(strcmp(datas[7], "44")==0){
      printf("Gear data: D\n");
    }else{
      printf("Gear data is not define\n");
    }
    */
  }
}

//main function
int main(){
  FILE *fp;
  char ch;
  char *line_buf = NULL;
  size_t line_buf_size = 0;
  ssize_t line_size;
  int i=0, count=0;
  char * delims = ",";

  if((fp=fopen("test.can","rt"))==NULL){
    printf("open file error!\n");
    return -1;
  }
  
  line_size = getline(&line_buf, &line_buf_size, fp);
  
  /*
  while(line_size >= 0){
    printf("content: %s\n", line_buf);
    char *test1 = strtok(line_buf, delims);
    printf("contenet1: %s\n", test1);
    char *test2 = strtok(NULL, delims);
    printf("contenet2: %s\n", test2);
    line_size = getline(&line_buf, &line_buf_size, fp);
  }
  */

  while(line_size >= 0){
    char *times = strtok(line_buf, delims);
    check_times(times);

    char *ext = strtok(NULL, delims);
    check_ext(ext);  

    char *remo = strtok(NULL, delims);
    check_remo(remo);

    char *ids = strtok(NULL, delims);
    int cata = check_ID(ids);

    char *datas[8];
    for(int i=0;i<8;++i){
        datas[i] = strtok(NULL, delims);
    }

    check_mean(cata, datas);

    line_size = getline(&line_buf, &line_buf_size, fp);
  }

  fclose(fp);
  return 0;
}
