#include <iostream>
#include <cstring>
#include <cstdlib>
#include <stack>

using namespace std;

struct Question
{
    string strA;
    int A;
    int B;
};

long int stoDec(const string &strA, int A)
{
    int Dec_A = 0;
    int pow_A = 1;

    for(int i=strA.length()-1; i>=0; i--)
    {
        if(strA[i] >= '0' && strA[i] <= '9')
        {
            char* tmp = new char[1];
            *tmp = strA[i];
            Dec_A += atoi(tmp)*pow_A;
        }
        else
            Dec_A += ((int)strA[i] - 55)*pow_A;
        pow_A *= A;
    }
    return Dec_A;
}

string AtoB(const string &strA, int A, int B)
{
    long int a = stoDec(strA, A);
    stack<int> stack_a;

    while(a > 0)
    {
        stack_a.push(a%B);
        a /= B;
    }

    string strB;
    while(!stack_a.empty())
    {
        if(stack_a.top() >= 0 && stack_a.top() <= 9)
            strB += to_string(stack_a.top());
        else
            strB += char(stack_a.top() + 55);
        stack_a.pop();
    }
    
    return strB;
}

int main()
{
    int n;
    cin >> n;

    Question* Q = new Question[n];
    for(int i(0); i<n; i++)
        cin >> Q[i].strA >> Q[i].A >> Q[i].B;
    
    for(int i(0); i<n; i++)
        cout << AtoB(Q[i].strA, Q[i].A, Q[i].B) << endl;

    return 0;
}