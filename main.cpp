#include <bits/stdc++.h>

using namespace std;

string elements = "abcdefghijklmnopqrstuvwxyz@!#%$&*()_+=-123456789";
string elems = "abcdefghijklmnopqrstuvwxyz!#%$&*()_+=-123456789";
string name = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
string nums = "123456789";

string generate_Password()
{
    string pass="";
    char current_char;

    for(int i=0; i<10; i++)
    {
          current_char= elements[rand()%38];
          pass+=current_char;
    }

    return pass;
}

string generate_User()
{
    string user="";
    char current_char;
    for(int i=0; i<10; i++)
    {
      if(i<8)
      {
        current_char= name[rand()%52];
        user+=current_char;
      }
      else
      {
          current_char = nums[rand()%9];
          user+=current_char;
      }
    }
    return user;
}

string generate_Mail()
{
    string mail="";
    char current_char;

    for(int i=0; i<10; i++)
    {
          current_char= elems[rand()%37];
          mail+=current_char;
    }
    mail+="@smecar.com";
    return mail;
}


int main()
{
    srand(time(NULL));
    string mail,user,password;
    int n;
    ofstream file;
    file.open("lista.txt");
    cout<<"How many accounts?"<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
       password = generate_Password();
       user = generate_User();
       file << "EUW:" << user <<":"<<password<<"\n";
    }
    file << "\n";
    for(int i=0; i<n; i++)
    {
        mail = generate_Mail();
        file << mail << "\n";
    }


    file.close();

    return 0;
}
