class Solution {

public:

    string interpret(string command) {

        string a,b,c,d,s;

        s=command;

        for(int i=0; i<s.length(); i++){

        if(s[i]=='G'){

            a="G";

            d=d+a;

        }

        if(s[i]=='(' && s[i+1]==')' ){

            b="o";

            d=d+b;

        }

        if(s[i]=='(' && s[i+1]=='a' && s[i+2]=='l' && s[i+3]==')') {

            string c="al";

            d=d+c;

        }

    } 

    return d;       

    }

};