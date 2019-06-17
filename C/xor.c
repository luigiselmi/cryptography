#include <stdio.h>

/* 
Simple XOR cipher 
from Schneier's book, Applied Cryptography, 2nd ed.
This application provides a xor function that can be used to implement the one-time pad cipher.
The xor function can be used to encode and decode a string using the same key.

Compile:

$ gcc xor.c -o xor 

Usage for encoding and decoding:
1) Encode: 

$ ./xor.exe key plaintext ciphertext

where key is a string whose length is >= 1 byte, plaintext a file containing a string
and ciphertext is the file that will containt the result of the xor between the key and the 
plaintext.

2) Decode:

$ ./xor.exe key ciphertext xoroutput

xoroutput will contain the xor between the key and the ciphertext that will be equal to the
original plaintext.
 
*/

void main (int argc, char *argv[]) {
  FILE *fi, *fo;
  char *cp;
  int c;
  if ((cp = argv[1]) && *cp!='\0') {
    if ((fi = fopen(argv[2], "rb")) != NULL) {
      if ((fo = fopen(argv[3], "wb")) != NULL) {
        while ((c = getc(fi)) != EOF) {
          if (!*cp) cp = argv[1];
          c ^= *(cp++);
          putc(c,fo);
        }
        fclose(fo);
      }
      fclose(fi);
    }
  }
}
