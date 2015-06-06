#include <stdio.h>

static int rot13(char *str)
{
  for (int i = 0; str[i] != '\0'; ++i)
  {
    if (65 <= str[i] && str[i] <= 90)
    {
      if (str[i] + 13 <= 90)
        str[i] += 13;
      else
        str[i] = 65 + 13 - (91 - str[i]); 
    }
    else if (97 <= str[i] && str[i] <= 122)
    {
      if (str[i] + 13 <= 122)
        str[i] += 13;
      else
        str[i] = 97 + 13 - (123 - str[i]);
    }
  }
  printf("%s\n", str);
}

int main(int argc, char *argv[])
{
  if (argc < 2)
    return 1;
  rot13(argv[1]);
  return 0;
}
