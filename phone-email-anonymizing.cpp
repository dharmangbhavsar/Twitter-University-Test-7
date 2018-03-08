#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
     string input;
    while(getline(std::cin, input))
    {
        if(input[0]=='E')
        {
            int i=0;
            //taking the first character of the email id
            //simply checking the position of @ in the string and taking the character before it
            //adding stars and outputting
            for( i=2;i<input.size();i++)
            {
                if(input[i]=='@')
                    break;
            }
            string s = "E:";
            s+=input[2];
            s+="*****";
            s+=input.substr(i-1);
            cout<<s<<endl;
        }
        else if(input[0]=='P')
        {
            string s = "P:";
            int i =2 ;
            if(input[i]=='+')
            {
                i++; 
                s+='+';
            }
            //removing the spaces hyphens and brackets from the string
            for(int j=i;j<input.size();j++)
            {
                if(input[j]=='-' || input[j]==' ' || input[j]=='(' || input[j]==')')
                {input.erase(input.begin()+j); j--;}
            }
            
            //adding *'s to the input according to the number of digits after the + sign
            if(input.size()-i==10)
                {
                    s+="***-***-";
                }
             else if(input.size()-i==11)
             {
                 s+="*-***-***-";
             }
            else if(input.size()-i==12)
                    s+="**-***-***-";
            
            else s+="***-***-***-";
            //adding the last 4 digits of input to the answer
            for(int i=input.size()-4;i<input.size();i++)
            {
                    s+=input[i];
            }
            cout<<s<<endl;
        }
    }
    return 0;
}