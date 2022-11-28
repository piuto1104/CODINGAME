#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

vector<int> arr;

int main()
{
    int r;
    cin >> r; cin.ignore();
    int l;
    cin >> l; cin.ignore();
    
    arr.push_back(r);
    for(int i=1;i<l;i++){
        vector<int> newArr;
        int num =0;
        int last =-1;
        for(int j=0;j<arr.size();j++){
            if(arr[j] != last){
                if(num !=0){
                    newArr.push_back(num);
                    newArr.push_back(last);
                }
                num =1;
            }else {
                num +=1;
            }
            last = arr[j];
        }
        newArr.push_back(num);
        newArr.push_back(last);
        arr = newArr;
    }
    for(int i=0;i<arr.size()-1;i++) {
        cout << arr[i]<<" ";
    }
    cout<<arr[arr.size()-1];
}