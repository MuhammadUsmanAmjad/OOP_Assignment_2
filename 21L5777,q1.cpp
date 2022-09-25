#include <iostream>
#include <cstring>
using namespace std;
int str_len(char c[])//used to return length of the array
{
	int i = 0;
	for(;c[i]!='\0';i++)
	{ }
	return i;

}
 void cat(char*& s1, char* s2)//concatination of two c-strings
{
     int str_length = str_len(s1) + str_len(s2) ;
     	char* s = new char[str_length];
     	s[str_length] = '\0';
     	int i = 0;
     	for (; i < str_len(s1); i++)
     		s[i] = s1[i];
     	 s[i] = ' ';
     	  i++;
     	for (int j=0; j<str_len(s2); j++, i++)
     		s[i] = s2[j];
     	
     	s1 = new char[str_length];
     	for (int i = 0; s[i] != '\0'; i++)
     		s1[i] = s[i];
     	s1[i] = '\0';

}
char* reverse_str(char* str)//function used to reverse the input string
{
	int i, prev, next, j, k;
	prev=0;
	int length = strlen(str);
	char* arr;
	arr = new char[length];
	int p = 0;
	for (i = 0; str[i] != '\0'; i++)
		prev = i;


	for (k = i - 1; k >= 0; k--)
	{
		if (str[k] == ' ' || k == 0)
		{
			if (k == 0)
			{
				next = 0;
			}
			else
			{
				next = k + 1;
			}

			for (j = next; j <= prev; j++)
			{
				arr[p] = str[j];
				p++;

			}
			arr[p] = ' ';
			p++;
			prev = next - 2;
		}
	}
	arr[p] = '\0';
	return arr;
}
char** token(char* str, int& row)//function used to print toknens
{


    for (int i = 0; str[i] != 0; i++)//loop to find rows 
    {
        if (str[i] == ' ' || str[i] == '\0')
            row++;
    }
   // cout << "row is:" << row << endl;
    char** arr = new char* [row];//allocating the  array
    int j = 0, k = 0;
    for (int i = 0; i <= str_len(str); i++)//loop to fix coloumn size
    {
        j++;
        if (str[i] == ' ' || str[i] == '\0')
        {
            //cout << "col" << k << " is " << j << endl;
            arr[k] = new char[j + 1]; //+1 for null character
            j = 0;
            k++;
        }
    }
    k = 0;
    j = 0, k = 0;
    for (int i = 0; i <= str_len(str); i++)//for storing string in 2-D dynamic array
    {

        arr[j][k] = str[i];
        k++;
        if (str[i] == ' ' || str[i] == '\0')
        {
            arr[j][k] = '\0';
            j++;
            k = 0;
        }
    }
    return arr;
}
char** reverse_tokens(char* a, int & row)//used to reverse printing of string in 2-D dynamic array
{

    char** arr = token(a, row);
    return arr;
}
int main()
{
    char* str;
    str = new char[100];
    cin.getline(str, 100);
    char* str1;
    str1 = new char[100];
    cin.getline(str1, 100);
    cat(str, str1);
    cout << "concatinated string is:\n";
    cout << str << endl;
    int row = 0;
   char** a = token(str, row);
   cout << "token printing is:\n";
   for (int i = 0; i <=row; i++)
   {
       for (int j = 0; a[i][j] != 0; j++)
           cout << a[i][j];
       cout << endl;
   }
   
    char* arr = reverse_str(str);
    cout << "reverse string is:\n";
    cout << arr << endl;
    int size = 0;
    char** ptr = reverse_tokens(arr,size);
    cout << "reverse-token printing is:\n";
    for (int i = 0; i <=size; i++)
    {
        for (int j = 0; ptr[i][j] != 0; j++)
            cout << ptr[i][j];
        cout << endl;
    }
    system("pause");
    return 0;
    
}
