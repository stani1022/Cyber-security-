#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define MAXN 100

char * ceasar_cipher(char* str, int key){
    int length = strlen(str);
    char * cipher = (char*)malloc(sizeof(char)*(length+1));
    for(int i =0; i<length; i++){
        if(str[i]>='a' && str[i]<='z'){
            cipher[i]=((str[i]-'a')+key) %26 + 'a';
        }
        else{
            cipher[i]=str[i];
        }
    }
    return cipher;
}

int main(){
    char str[MAXN];
    scanf("%s", str);
    int key;
    scanf("%d", &key);
    char* cipher = ceasar_cipher(str, key);
    printf("%s\n", cipher);
    return EXIT_SUCCESS;
}
