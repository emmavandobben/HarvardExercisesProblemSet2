#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[]){
    
    //there must be two argument (the file name and the key)
     if (argc != 2 ) { 
         printf("Wrong!\n");
         return 1;
     }

    //get a string as key
    string keyString = argv[1];
    // keyLength 
    int keyLength = strlen(keyString);
    int key; 
    
    //iterate through string to see if is all aphabetical
    for (int i = 0, n = keyLength; i < n; i++){
        if (!isalpha(keyString[i])){
        printf("Wrong!\n");
                return 1;
        }
    }
     
     //ask for plaintext to encrypt
     printf("plaintext: ");
     printf("\n");
    //get plaintext
    string plainText = GetString();
    printf("ciphertext: ");
    
    // just as argv is an array of strings, so is a string an array of chars.
    //iterate through the keyString to use every individual char of the string as key. 
    for (int i = 0, n = strlen(plainText); i < n; i++){
        
        //bepaal de remain. Als de key korter is dan het te encrypten woord, dan begin je na de laatste letter van de key weer bij de eerste letter. 
        int remain= i % (keyLength); 

       //bepaal de key
        if (isalpha(keyString[remain])){
             if(isupper(keyString[remain])){
                     key = (keyString[remain]- 'A');
            }
            else if(islower(keyString[remain])){
                     key = (keyString[remain]- 'a');
           }
        }
        
        if (!isalpha(keyString[remain])){
        printf("Wrong!\n");
                return 1;
        }
  
    //isappha check if the letter is in the alphabet. 
    if (isalpha(plainText[i])) {
      
        if(isupper(plainText[i])){
            
            //nr of character in ascII
           char text = (plainText[i]- 'A');
           //nr of crypted character in ascII
           int ascii = (text + key) % 26;
           char newText = ascii + 'A';
           printf("%c", newText); 
        }
        
        else if(islower(plainText[i])){
           //nr of character in ascII
           char text = (plainText[i]- 'a');
           //nr of crypted character in ascII
           int ascii = (text + key) % 26;
           char newText = ascii + 'a';
           printf("%c", newText); 
        }
        
}
    if (!isalpha(plainText[i])) {
    printf("%c", plainText[i]);
}
}
printf("\n");
}