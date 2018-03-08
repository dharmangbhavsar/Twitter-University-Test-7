#include <bits/stdc++.h>
#include <string>
#define fr freopen("input.in","r",stdin)
#define fw freopen("output.out","w",stdout)
#define iOs ios_base::sync_with_stdio(false);
#define INF 111313131
#define all(x) (x).begin(), (x).end()
#define debug cout<<"here\n"
#define debugin cout<<"inhere\n"
#define debugname cout<<"dharmang\n";
using namespace std;
#define pb push_back
#define mp make_pair
#define sc second
#define fir first
#define No_Of_Inputs 2
#define No_Of_Layer 3
#define HI 0.5
#define LO -0.5
typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
vector< pair<int,int> > v;
//map<int,int> mi;
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
map< string, vector< pair< string,int > > > m;
bool fun(pair<string,int> p , pair<string,int> t  )
{
    return p.first<t.first;
}
int main()
{
    //fw;fr; 
    string timeframe;
    getline (std::cin,timeframe);
    string startYear, startMonth, endYear, endMonth;
    startYear = timeframe.substr(0,4);
    startMonth = timeframe.substr(5,2);
    endYear = timeframe.substr(9,4);
    endMonth = timeframe.substr(14,2);
    string s;
    getline(std::cin, s);
    while(getline(std::cin, s))
    {
        //cout<<s<<endl;
        string dataYear,dataMonth;
        dataYear = s.substr(0,4);
        dataMonth = s.substr(5,2);
        if((dataYear>startYear && dataYear<endYear) or (dataYear==startYear && dataMonth>=startMonth) or (dataYear==endYear && dataMonth<endMonth))
        {
            //cout<<s<<endl;
            string key = s.substr(0,7),ins="";
            //cout<<key<<endl;
            //if the key doesnt exist in the map.
            if(m.find(key)==m.end())
            {
                //finding the length of the number and converting it into integer 
                int j=s.size()-1; long long int ans = 0;
                while(s[j]!=' ')
                {
                    j--;
                }
                int temp = j+1;
                for(int k = temp ; k<s.size();k++)
                {
                    ans*=10;
                    ans+=int(s[k]-'0');
                }
                //saving the type of statistic in the data
                for(int y=12; ;y++)
                {
                   
                    if(s[y]==',') break;
                    else ins+=s[y];
                }
                //cout<<ins<<" "<<ans<<endl;
                //putting the data in the map.
                m[key].push_back(make_pair(ins,ans));
            }
            //if the key already exists in the map
            else 
            {
                //cout<<"here";
                //extracting the number from the data.
                int j=s.size()-1; long long int ans = 0;
                while(s[j]!=' ')
                {
                    j--;
                }
                int temp = j+1;
                for(int k = temp ; k<s.size();k++)
                {
                    ans*=10;
                    ans+=int(s[k]-'0');
                }
                //extracting the type of statistic from the data.
                for(int y=12; ;y++)
                {
                    if(s[y]==',') break;
                    else ins+=s[y];
                }
               // m[key].push_back(make_pair(ins,ans));
                //cout<<ins<<" "<<ans<<endl;
                //boolshoes if the statistic is already present in the map
                bool present = false;
                for (auto iter = m[key].begin(); iter != m[key].end(); ++iter)
                {
                    //if present, we add the value to the statistic and save it again.
                    if(iter->first==ins)
                    {
                        //cout<<endl<<"inhere ";
                        present = true;
                        iter->second+=ans;
                        //cout<<iter->second;  
                        break;
                    }
                }
                //if not present we push it
                if(present ==false)
                    m[key].push_back(make_pair(ins,ans));
            }
        //}
    }
    }
    //printing the map in reverse order and sorting the vector present in it
    for (auto pair = m.rbegin(); pair != m.rend(); ++pair)
    // for( const auto& pair : m )
        {
            
            sort(pair->second.begin(),pair->second.end(), fun);
            cout<<pair->first<<", ";
            for( std::size_t i = 0 ; i < pair->second.size() ; ++i )  { if(i!=0) cout<<", "; std::cout << pair->second[i].first << ", "<<pair->second[i].second ;}
            cout<<endl;
        }
return 0;    
}
//Sample Input
//2015-08-15, clicks, 635
//2016-03-24, app_installs, 683
