#include <iostream>

using namespace std;

bool prt_dnguoc(int arr[], int n)
{
    bool flag=false;
    int tmp, dao_ai;
    for(int i(0); i<n-1; i++)
        for(int j(i+1); j<n; j++)
            if(arr[i]*arr[j]>=0)
            {
                if(abs(arr[i])>abs(arr[j]))
                {
                    tmp=abs(arr[i]);
                    dao_ai=0;
                    while(tmp>0)
                    {
                        dao_ai = dao_ai*10 + tmp%10;
                        tmp/=10;
                    }
                    if(abs(arr[j])==dao_ai)
                    {
                        cout << "a[" << i << "]:" << arr[i] << "        a[" << j << "]:" << arr[j] << endl;
                        flag=true;
                    }
                }
                else
                {
                    tmp=abs(arr[j]);
                    dao_ai=0;
                    while(tmp>0)
                    {
                        dao_ai = dao_ai*10 + tmp%10;
                        tmp/=10;
                    }
                    if(abs(arr[i])==dao_ai)
                    {
                        cout << "a[" << i << "]:" << arr[i] << "        a[" << j << "]:" << arr[j] << endl;
                        flag=true;
                    }
                }
            }


    return flag;
}















