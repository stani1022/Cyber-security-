#include <stdio.h>
#include <string.h>
#include <openssl/des.h>
#include <stdlib.h>
#define KEY_SIZE 8
#define MAXN 1000

int main()
{
    unsigned char key[KEY_SIZE] ="banichka";
    unsigned char input[MAXN];
    fgets(input,MAXN, stdin );

    input[strcspn(input, "\n")]="\0";
    unsigned int input_lenght =strlen(input);

    int padding_length=((input_lenght +7)/8) * 8;
    unsigned char padded_input[padding_length];
    unsigned char output[padding_length];

    memcpy(padded_input,input,input_lenght);
    //PKCS55 padding
    memset (padded_input + input_lenght,
            padding_length - input_lenght,
            padding_length - input_lenght
        );
        
        DES_key_schedule  key_schedule;
        DES_set_key((DES_cblock*) key, &key_schedule);
        for(int i=0;i <padding_length;i+=8){
            DES_ecb_encrypt((DES_cblock*)(padded_input + 1),
        (DES_cblock*)(output+ i),
          &key_schedule,
          DES_ENCRYPT
       );
    }
    for(int i=0;i < padding_length;i++){
        printf("%02x", output[i]);
    }
    
    return EXIT_SUCCESS;
    }
