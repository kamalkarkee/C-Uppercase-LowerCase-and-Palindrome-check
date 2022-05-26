
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
void Capitalize( char s[] )
{
   for( int i = 0 ; i < strlen( s ) ; i++ )
      s[i]= toupper(s[i]);
}
void LowerCase( char s[] )
{
   for( int i = 0 ; i < strlen( s ) ; i++ )
      s[i]= tolower(s[i]);
}      
void strrev (char s[])
{
  int lim= strlen(s)-1;
  for (int i=0; i<strlen(s)/2; i++)
  {
    char ch = s[lim-i];
    s[lim-i]=s[i];
    s[i]=ch;
  }
}
bool IsPalindrome (char s[])
{
  char rev[80];
  strcpy(rev,s);
  strrev(rev);
  if (strcmp(rev,s)==0) return true;
  return false;
}
int main(){
  char fn[30];
  cout<<"Enter a filename:";
  cin>>fn;
  ifstream infile(fn);
  if (infile)
  {
    char line [80];
    char cmd;
    cout<<"Choose a cmd:\nC)apitalize or L)ower case:";
    cin>>cmd;
    while (infile.getline (line,80))
    {
      if (cmd=='C')
        Capitalize(line);
      else if (cmd=='L')
        LowerCase(line);
      cout<<line;
      if (IsPalindrome(line))
        cout<<" is a palindrome";
      cout<<endl;  
    }
    infile.close();
  }else cout<<"invalid file\n";
  return 0;
}