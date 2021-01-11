#include <iostream>
#include <string>
#include <cstring>
#pragma GCC optimize(3,"Ofast","inline")
using namespace std;

int nxt[1000010];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string str;
	cin>>str;
	int strlen = str.length();
    nxt[0] = -1;
    int k = -1;     
    int j = 0;
    while (j < strlen) {
        if (k == -1 || str[k] == str[j])
        { 
            nxt[++j] = ++k;
        }
        else
        {
            k = nxt[k];
        }
    }
	for (int t = 1; t <= strlen; t++)
	{
        printf("%d\n", nxt[t]);
	}
	return 0;
} 