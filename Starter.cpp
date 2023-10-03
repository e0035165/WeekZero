//
//  main.cpp
//  Kattis_OneD_Frogger
//
//  Created by Sart Way on 18/8/23.
//

#include <stdio.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <functional>
#include <fstream>
#include <vector>
#include <queue>
#include <set>
#include <vector>
#include <iostream>
#include <list>

using namespace std;
string ltrim(const string &str);
string rtrim(const string &str);
vector<string> split(const string &str);
long Solver(int*,int);
vector<int> SolverAssistant(vector<vector<int>>&,int*,int*,int,int,int*);
int stepper(int A, int n, int i);
int repeat_position = -1;
int counter = 0;


long Solver(int* array, int n)
{
    int SIZE = n;
    long ans = 0;
    vector<vector<int>>vect(n);
    int* visited = new int[n];
    for(int i=0;i<n;i++)
    {
        visited[i] = -1;
    }
    for(int i=0;i<n;++i)
    {
        //cout << visited[i] << endl;
        if(vect[i].empty())
        {
            int* visitedtwo = new int[n];
            memset(visitedtwo, 0, n);
            vect[i] = SolverAssistant(vect, array, visited, n, i, visitedtwo);
            //cout << endl;
        }
        
        repeat_position = -1;
        if(counter == n) {
            break;
        }
            
    }
    
    for(int i=0;i<n;++i)
    {

        for(int j=0;j<vect[i].size();++j)
        {
            cout << vect[i][j] << " ";
        }
        cout << endl;
        ans += (long)vect[i].size();
    }
    delete[] visited;
    return ans;
}

vector<int> SolverAssistant(vector<vector<int>>& vect, int* array, int* visited, int n, int i, int* visitedtwo)
{
    
    if(i<0 || i >= n)
    {
        vector<int>temp;
        return temp;
    }
    visitedtwo[i] += 1;
    
    if(visited[i] == 1 || visitedtwo[i] > 1)
    {
        return vect[i];
    }

    vect[i] = SolverAssistant(vect, array, visited, n, i + stepper(array[i], n, i), visitedtwo);
    visited[i] = 1;
    counter += 1;
    vect[i].push_back(i);
    if(visitedtwo[i]>1)
    {
        for(auto x=vect[i].begin();x!=vect[i].end();++x)
        {
            vect[*x] = vect[i];
        }
    }
    return vect[i];
}


int stepper(int A, int n, int i)
{
    if(abs(A) > n)
    {
        return 0;
    } else {
        if(A < 0)
        {
            return (abs(A) - n);
        } else {
            return (n - abs(A));
        }
    }
}


int main(int argc, const char * argv[]) {
    // insert code here...
    
    //cout << "SIZE: " << SIZE << endl;
    string first_multiple;
    //cin.getline(first_multiple, SIZE*2);
    getline(cin,first_multiple);
    int SIZE = stoi(first_multiple);
    getline(cin,first_multiple);
    //cout << first_multiple << endl;
    vector<string> a_temp = split(rtrim(first_multiple));

    int* sizer = new int[SIZE];

    for(int i=0;i<SIZE;++i)
        sizer[i] = stoi(a_temp[i]);
    
    long ans = Solver(sizer,SIZE);
    cout << ans << endl;
    delete []sizer;
    return 0;
}


string ltrim(const string &str) {
    string s(str);

    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int c) {return !std::isspace(c);}));
    return s;

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int c) {return !std::isspace(c);}));
    return s;

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

