#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    queue<int> myQueue;

    for (int i = 0; i < N; ++i) {
        string command;
        cin >> command;

        if (command == "push") {
            int X;
            cin >> X;
            myQueue.push(X);
        }
        else if (command == "pop") {
            if (!myQueue.empty()) {
                cout << myQueue.front() <<"\n";
                myQueue.pop();
            }
            else {
                cout << "-1" << "\n";
            }
        }
        else if (command == "size") {
            cout << myQueue.size() << "\n";
        }
        else if (command == "empty") {
            cout << (myQueue.empty() ? 1 : 0) << "\n";
        }
        else if (command == "front") {
            if (!myQueue.empty()) {
                cout << myQueue.front() << "\n";
            }
            else {
                cout << "-1" << "\n";
            }
        }
        else if (command == "back") {
            if (!myQueue.empty()) {
                cout << myQueue.back() << "\n";
            }
            else {
                cout << "-1" << "\n";
            }
        }
    }

    return 0;
}
