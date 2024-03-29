#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    
    string str = "";
    string bar = "--------------------------------------------------------------------------------";
    int line_len = 0;
    
    while(1) {
        cin >> str;
        if(cin.eof() == true) break;
            
        if(str == "<br>") {
            cout << "\n";
            line_len = 0;
        } else if(str == "<hr>") {
            if(line_len != 0) cout << "\n";
            cout << bar << "\n";
            line_len = 0;
        } else {
            if(line_len + str.size() < 80) {
                if(line_len != 0) {
                    cout << " ";
                    line_len++;
                }
                cout << str;
                line_len += str.size();
            } else {
                cout << "\n";
                line_len = 0;
                cout << str;
                line_len += str.size();
            }
        }
    }
}