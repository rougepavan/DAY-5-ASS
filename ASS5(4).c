#include <stdio.h>
#include <stdlib.h>

char *read_file(char *filename);

int main()
{
  char filename[1024];
  printf("File: ");
  scanf("%s", filename);
  char *file_contents = read_file(filename);
  if (file_contents == NULL)
  {
    printf("Error reading file.\n");
    return 1;
  }
  printf("File Contents:\n\n%s\n", file_contents);
  free(file_contents);

  return 0;
}
char *read_file(char *filename)
{
  FILE *file;
  file = fopen(filename, "r");
  if (file == NULL) return NULL;
  fseek(file, 0, SEEK_END); 
  int length = ftell(file);
  fseek(file, 0, SEEK_SET);
  char *string = malloc(sizeof(char) * (length+1));
  char c;
  int i = 0;
  while ( (c = fgetc(file)) != EOF)
  {
    string[i] = c;
    i++;
  }
  string[i] = '\0';
  fclose(file);
  return string;
}
