#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string,int> com;
    for(int i=0;i<participant.size();i++){
        com[participant[i]]++;
    }
    for(int i=0;i<completion.size();i++){
        com[completion[i]]--;
    }
    for (const auto& pair : com) {
        if (pair.second == 1) {
            answer = pair.first;
        }
    }
    return answer;
}