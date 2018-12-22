#include <stdio.h>
#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
int main ()
{
    char file_path[40] = { 0 }, lookfor[255] = { 0 }, changeto[255] = { 0 }, str[255] = { 0 };
    FILE* file = NULL;
    
    {
    printf("Enter file path: ");
    fgets(file_path, 40, stdin);
    file_path[strlen(file_path) - 1] = '\0';
    file = fopen(file_path, "r+");
    }
    while(file == NULL);
    
    printf("Enter text to find: ");
    fgets(lookfor, 255, stdin);
    lookfor[strlen(lookfor) - 1] = '\0';
    printf("Enter text to replace: ");
    fgets(changeto, 255, stdin);
    changeto[strlen(changeto) - 1] = '\0';
    
    {
    while(fgets(str, 255, file) != NULL)
    {
    char* tmp_ptr = strstr(str, lookfor);
    while(!feof(file))
    {
        
        char tmp_str[255];
        strcpy(tmp_str, tmp_ptr + strlen(lookfor));
        strcpy(str + strlen(str) - strlen(tmp_ptr), changeto);
        strcat(str, tmp_str);
        tmp_ptr = strstr(str, lookfor);       
    }
    {   fstream clear_file("output.txt", ios::out); 
        clear_file.close();
        freopen("output.txt", "r+",stdout);
        printf("%s", str);
    } 
        fclose(file);
        getchar();
        return 0;
    }     
}
}
