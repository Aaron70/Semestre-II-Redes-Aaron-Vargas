#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int char_to_hex(char c){

  if ( c >= 0x30 && c <= 0x39 ) return c - 0x30;

  if ( c >= 0x41 && c <= 0x46 ) return c - 0x41 + 10;

  if ( c >= 0x61 && c <= 0x66 ) return c - 0x61 + 10;

  return 0;
}

int strHex_to_binary(char* hex){
  if ( hex[0] == '\0' ) return 0x0;

  int count = 0;
  int binary = char_to_hex(hex[count]);

  count++;
  while ( hex[count] != '\0'){
    int hexDigit = char_to_hex(hex[count]);
    binary = binary << 4;
    binary += hexDigit;
    count++;
  } 

  return binary;
}

int encode(int binary){
  printf("Hexa in decimal: %b\n", binary);
}
 
int main(int argc, char* argv[]){

  char* argMode = argv[1]; 
  int mode;

  if ( strcmp(argMode,"encode") == 0 ) mode = 0;
  else if ( strcmp(argMode,"decode") == 0 ) mode = 1;
  else {
    printf("Unknown mode.\nThe first argument must be the mode. (encode or decode).\n");
    return 1;
  } 

  int inputFlag = 0;
  int errorFlag = 0;
  int input = -1;
  int errors[(argc - 4)/2];
  int errorsCount = 0; 

  for( int i = 2; i < argc; i++ ){

    if( inputFlag == 1 ){
      input = strHex_to_binary(argv[i]);
      inputFlag = 0;
    }else if ( errorFlag == 1 ){
      errors[errorsCount] = atoi(argv[i]);
      errorFlag = 0;
      errorsCount += 1;
    }

    if ( strcmp(argv[i],"--input") == 0 ) inputFlag = 1;
    else if ( strcmp(argv[i],"--error") ) errorFlag = 1;
    else {
      printf("Argument %s not recognized.\n",argv[i]);
    }
   
  } 

  if ( input == -1 ){
    printf("You must provide the input argument.\n");
    return 1;
  }

  if ( mode == 0 ) { encode(input); return 0; }
  printf("Module not implementend.\n");

  return 0;

}