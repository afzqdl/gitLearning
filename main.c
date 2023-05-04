#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1024

int main() {
	
    int duanluo = 0, words = 0;
    
    int min = 65525, ave = 0, max = 0,sum = 0;
    FILE* fp;        
    
    char buffer[MAX_LINE] ;        
    int len ;    
    int i;
    fp = fopen("C:/Users/32303/Desktop/UL/xdrjgc/test.txt","r");
    if(fp == NULL){
        printf("cannot open!");
        exit(0);
    }
    
    while(! feof(fp)){
        
        if(fgets(buffer, MAX_LINE, fp) != NULL){
            duanluo ++;
            len = strlen(buffer);
           	
            words = 1;
            sum ++;
            
            for(i = 0; i < len - 1; i++){
                if((buffer[i] == ' ') || (buffer[i] == ',')){
                	if (i!=0 && (buffer[i-1] != ' ' && buffer[i-1] != ',')) {
                		words ++;
                    	sum ++;
					}
                    
                }
            }
        }
        
        if(min > words){
            min = words;
        }
        if(max < words){
            max = words;
        }
        
    }

    fclose(fp);
	
    printf("\n\t 总单词数为 %d \n \n",sum);
	printf("\n\t 总字符数为%d\n", len);
    
    return 0;
}
