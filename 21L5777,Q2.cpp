#include<iostream>
using namespace std;
class MyString { 
   
     char* str=nullptr; int length;
    friend istream& operator>>(istream& , MyString&);
    friend ostream& operator<<(ostream&, const MyString );
    friend bool operator<(const MyString obj, const MyString obj1);
     
public:
    MyString()
    {
        length = 1;
        str = new char[100];
        str[0] = 0;
    }

    int str_len(char str[])
    {
        int i = 0;
        while (str[i] != 0)
            i++;
        return i;
    }
    bool operator!()
    {
        if (str[0] != 0)
            return false;
        else
            return true;
    }
    
    MyString operator+(const MyString obj)
    {
        MyString temp;
        temp.length = str_len(obj.str) + str_len(str)+1;
        int i = 0;
        for (; i < str_len(str); i++)
            temp.str[i] = str[i];
        for (int j = 0; j < str_len(obj.str); j++, i++)
            temp.str[i] = obj.str[j];
        temp.str[i] = '\0';
        return temp;

    }
    MyString& operator=(const MyString& obj)
    {
        //cout << "deep copy\n";
        length = str_len(obj.str);
        int i = 0;
        for (; i < length; i++)
            str[i] = obj.str[i];
        str[i] = 0;
        return *this;
    }
    char* operator()(int a,int b)
    {
        char* temp;
        temp = new char[b];
        int j = 0;
        for (int i = a; str[i] != 0 && j<b; i++,j++)
        {
            temp[j] = str[i];
        }
        temp[j] ='\0';
        return temp;
    }
    MyString  operator-(const MyString& obj)
    {
        MyString o;
        bool check = true;
        int first = 0;
        int second = 0;
        if (length <= obj.length)
            o.str = 0;
        else
        {
            for (int i = 0; i < length; i++)
            {
                if (str[i] == obj.str[0])
                {
                    first = i;
                    for (int j = 0; j < obj.length; j++)
                    {
                        if (obj.str[j] != str[i]) {
                            check = false;

                            i++;
                        }
                    }
                    if (check == true)
                    {
                        second = i - 1;
                        i = length;

                    }
                }
            }
            if (check == true)
            {
                int k = 0;
                for (int i = 0; i < length; i++)
                {
                    if (i<first || i>second)
                    {
                        o.str[k] = str[i];
                        k++;
                    }
                }
                o.str[k + 1] = 0;
                o.length = o.str_len(o.str);
            }
            return o;

        }
    }

    char&operator[](int idx)
    {
        return str[idx];
    }
    
    MyString & operator++()
    {
        length = str_len(str);
        str[length] = 'a';
        length++;
        str[length] = 0;
        return *this;
    }
    MyString& operator--()
    {
        length = str_len(str);
        str[length - 1] = 0;
        return *this;
    }
    };

istream& operator>>(istream& o, MyString& obj)
{
    o.getline(obj.str, 100);
    obj.length = obj.str_len(obj.str);
    obj.str[obj.length] = 0;
   
    return o;
}
ostream& operator<<(ostream& o,const MyString obj)
{
    
    for (int i = 0; obj.str[i]!=0; i++)
        o <<obj. str[i];
    return o;
}
bool operator<(const MyString obj, const MyString obj1)
{
    if (obj.length >= obj1.length)
    {
        for (int i = 0; i < obj.length; i++)
        {
            if (obj.str[i] < obj1.str[i])
                return false;
        }
        return true;
    }
    return false;
}

int main()
{
  
     MyString str1, str2, str3, str4, str5; //Default constructor will make a string of lenght 1 having null character only i.e. empty string
     if (!str1)
        { 
            cout << "String 1 is Empty.\n";

        cout << "Str 1 = " << str1 << endl << endl << endl;
        }
        cout << "Enter String 1:\t";
        cin >> str1;
        cout << "Enter String 2:\t";
        cin >> str2;
        cout << "\n\n\nUser Entered:\n";
        cout << "String 1 = " << str1 << endl;
        cout << "String 2 = " << str2 << endl << endl << endl;
        //What is following code testing? 
        cout<<"Before str1 = str1; str1 = "<<str1<<endl; str1 = str1;
        cout<<"After str1 = str1, str1 = "<<str1<<endl<<endl<<endl;
        cout << "Before str4 = str3 = str1+str2\n";
        cout << "str1 = " << str1 << endl;
        cout << "str2 = " << str2 << endl; cout << "str3 = " << str3 << endl;
        cout << "str4 = " << str4 << endl;
        str4 = str3 = str1 + str2;
        cout << "\n\n\nAfter str4 = str3 = str1+str2\n";
        cout << "str1 = " << str1 << endl;
        cout << "str2 = " << str2 << endl; 
        cout << "str3 = " << str3 << endl;
        cout << "str4 = " << str4 << endl;
        cout << "\n\n\nEnter String 3:\t"; 
        cin >> str3;
        cout << "\n\n\nEnter String 4:\t"; 
        cin >> str4;
        cout << "\n\n\nstr3 = " << str3 << endl; 
        cout << "str4 = " << str4 << endl;
        if (str3 < str4)
            cout << "String 3 is Less than String 4.\n"; 
        else 
            cout << "String 3 is NOT Less than String 4.\n";
        str5 = str1 + str2;
        cout << "\n\n\nStr5:\t" << str5 << endl;
        cout << "Str5[7]:\t" << str5[7] << endl; //Function Call: str5.operator[](7). str5[7] = '$';
        cout << "\n\nStr5:\t" << str5 << endl;
        cout << "\n\n\nstr5(5, 10):\t" << str5(5, 10) << endl;// Substring of lenght 10 starting from index 5 .
        //Function Call str5.operator()(5,10) Let the returned MyString 
        //or char* leak
          // Output for below statements is going to be shown below the sample output given above
          // Values right now -> str3 = abcd, str4 = abcD
            cout << "\n\n ++Str3 :\t" << ++str3 << endl;
        // ++Str3: abcda
        str5 = str1-str2;
        cout << "\n\n Str1-Str2 :\t" << str5 << endl;
        // Str4 – Str3:      // Nothing printed because str4 is less than str3
        cout << "\n\n --Str3 :\t" << --str3 << endl;
        // Str3 : abcd
        cout << "\n\n --Str3 :\t" << --str3 << endl;
        // Str3 : abc
        str5 = str4-str3;
        cout << "\n\n Str4-str3 :\t" << str5 << endl;
        // Str4 – Str3: D    ( abcD – abc = D )

    return 0;
        

}

