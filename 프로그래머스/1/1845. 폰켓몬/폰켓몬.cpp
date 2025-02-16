#include <vector>
#include <iostream>
#include <map>
using namespace std;

int solution(vector<int> nums)
{
    map<int,int> table;
    int answer = 0;
    int phone_num;
    for(int i=0;i<nums.size();i++){
        phone_num = nums[i];
        table[phone_num]++; //1씩 증가시켜주기   
    }
    if(table.size()>=nums.size()/2)
        answer = nums.size()/2;
    else{
        answer = table.size();
    }
    return answer;
}