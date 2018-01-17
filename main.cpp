//
//  main.cpp
//  deleterEnter
//
//  Created by ustc@tll on 16/1/18.
//  Copyright © 2018 ustc@tll. All rights reserved.
//

#include <iostream>
#define MAX_LINE_LENGTH 1000000
    char *data_file;
char * replaceAll(char * src,char oldChar,char newChar){
    char * head=src;
    while(*src!='\0'){
        if(*src==oldChar) *src=newChar;
        src++;
    }
    return head;
}
int main(int argc,  char * argv[]) {

    char buffer[MAX_LINE_LENGTH];
    char *token;
    FILE *f_in;
    int i,n_cases=20000;
    const char *separators="\n";
    data_file = argv[1];
    f_in=fopen(data_file, "r+");
    if (!f_in)
    {
        perror("Failed to open file");
        exit(1);
    }
   
    for(i=0;i<n_cases;i++)
    {
        
        fgets(buffer,(int)MAX_LINE_LENGTH,f_in);
        if(i%2!=0)continue;
        if((int)strlen(buffer)==(int)MAX_LINE_LENGTH-1)
        {printf("\n\n Exceeding MAX_LINE_LENGTH. \n\n");
            exit(0);
        }
        token=replaceAll(buffer, '\n', '\t');
        fseek(f_in, -1, SEEK_CUR);
        fputs(token,f_in);
        fseek(f_in, 0, SEEK_CUR);
    }
    fclose(f_in);
    return 0;
}
