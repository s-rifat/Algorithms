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


void Insert(char* str, int len)
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


bool Search(char* str, int len)
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


int main()
{
    while(true)
    {
        root = new node();
        int n;
        cin >>n;
        for (int i = 1; i <= n; i++) {

            char str[50];
            scanf("%s", str);

            Insert(str, strlen(str));
        }

        int q;
        cin >> q;


        while (q--)
        {
            char s[50];
            scanf("%s", s);

            if (Search(s, strlen(s)))
                puts("FOUND");
            else
                puts("NOT FOUND");
        }

        del(root);
    }
    return 0;
}
