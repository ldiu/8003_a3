#include<string.h>
#include<stdio.h>
#include<stdlib.h>

#define BUFFER_SIZE 1024

int main() {
      FILE *sourceFile, *destinationFile;
      char ch;
      char buffer[BUFFER_SIZE];
      size_t bytesRead;

      sourceFile = fopen("test/secret_passwords.txt", "r");
      if (sourceFile == NULL){
            perror("Error opening source file");
            return 1;
      }

      destinationFile = fopen("test_results/stolen_passwords.txt", "w");
      if (destinationFile == NULL){
            perror("Error opening destination file");
            fclose(sourceFile);
            return 1;
      }

      while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, sourceFile)) > 0){
            fwrite(buffer, 1, bytesRead, destinationFile);
      }

      fclose(sourceFile);
      fclose(destinationFile);
      return 0;
}
