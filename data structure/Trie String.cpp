#include<bits/stdc++.h>
using namespace std;


struct node {
    bool endmark;
    node* next[26 + 1];
    node()
    {
        endmark = false;
        for (int i = 0; i < 26; i++)
            next[i] = NULL;
    }
} * root;


void Insert(string& str, int len)
{
    node* curr = root;
    for (int i = 0; i < len; i++) {
        int id = str[i] - 'a';
        if (curr->next[id] == NULL)
            curr->next[id] = new node();
        curr = curr->next[id];
    }
    curr->endmark = true;
}


bool Search(string& str, int len)
{
    node* curr = root;
    for (int i = 0; i < len; i++) {
        int id = str[i] - 'a';
        if (curr->next[id] == NULL)
            return false;
        curr = curr->next[id];
    }
    return curr->endmark;
}


void del(node* cur)
{
    for (int i = 0; i < 26; i++)
        if (cur->next[i])
            del(cur->next[i]);

    delete (cur);
}

void print(node* curr, string& str)
{
   if(curr->endmark)
        cout<<str<<endl;
   for(int i=0;i<26;i++)
   {
       if(curr->next[i]!=NULL)
       {
            char c = i+'a';
            string s = str;
            s.push_back(c);
            print(curr->next[i],s);
       }
   }
}


int main()
{



    while(true)
    {
        root  = new node();
        int n;
        cin>>n;

        for(int i=0;i<n;i++)
        {
            string s;
            cin>>s;
            Insert(s,s.size());

        }

        string str = ""; //for printing
        print(root,str);//for printing

        int q;
        cin>>q;

        while(q--)
        {
            string s;
            cin>>s;

            if(Search(s,s.size()))
            {
                cout<<"Found"<<endl;
            }
            else
            {
                cout<<"Not Found"<<endl;
            }

        }



        del(root);

    }
    return 0;
}
