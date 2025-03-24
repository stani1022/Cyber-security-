#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXN 1024

char * vigenere_decrypt(char* ciphertext, char* key)
{
    int text_length = strlen(ciphertext);
    int key_length = strlen(key);

    char* plaintext = (char*) malloc(sizeof(char)*(text_length + 1));
    memset(plaintext, '\0', sizeof(char) * (text_length + 1));

    for (int i = 0; i < text_length; i++)
    {
        if (isalpha(ciphertext[i]))
        {
            int shift = tolower(key[i % key_length]) - 'a';
            if (islower(ciphertext[i]))
            {
                plaintext[i] = 'a' + (ciphertext[i] - 'a' - shift)%26;
            }
            else
            {
                plaintext[i] = 'A' + (ciphertext[i] - 'A' - shift)%26;
            }
        }
        else
        {
            plaintext[i] = ciphertext[i];
        }
    }

    plaintext[text_length] = '\0';
    return plaintext;
}

int main()
{
    char text[MAXN];
    scanf("%s", text);

    char key[MAXN];
    scanf("%s", key);

    char* decrypted = vigenere_decrypt(text, key);
    printf("%s", decrypted);

    free(decrypted);
    return EXIT_SUCCESS;
}
