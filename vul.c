#include <stdio.h>  
#include <string.h>  

void secretFunction() {
    printf("Secret function activated!\n");
}

void sayHello(char *input) {  
    char name[12];  // Buffer stored on the stack
    strcpy(name, input); // This copies a potentially malicious string into the character buffer without checking size
    printf("Hello %s\n", name); // Print using the buffer to ensure we're using the stack-stored value
}  

int main(int argc, char* argv[]) {  
    if (argc != 2) { // Error message if run improperly  
        printf("Usage: %s arg\n", argv[0]);  
        return 1;  
    }  
    sayHello(argv[1]); // Passes our input to the vulnerable function  
    return 0;  
}
