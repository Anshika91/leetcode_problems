#include <bits/stdc++.h>
using namespace std;

void solution()
{
    int N, temp =0, tempnum;
    string S;
	cin >> N >> S;
	for(int i = 0; i < N - 1; i = i + 2)
	{
	    temp = S[i];
	    S[i] = S[i + 1];
	    S[i+1] = temp;
	}
	
	for(int i = 0; i < N; i++)
	{
	    tempnum = 0;
	    if(int(S[i]) <= 109)
	    {
	        tempnum = int(S[i]) - 97;
	        S[i] = char(122 - tempnum);
	    }
	    else if(int(S[i]) >= 110)
	    {
	        tempnum = 122 - int(S[i]);
	        S[i] = char(97 + tempnum);
	    }
	}
	
	cout << S << endl;

}

int main() {
	// your code goes here
	int T;
	cin >> T;
	while(T--)
	{
        solution();
	}
	return 0;
}
