
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    vector<int> multiplication;
    int test;
    string a, b;
    int valueChar;
    string message;
    vector<int> result;
    int num[2][101] = {0};
    cout << "Hello it's calculator the big numbers !!! VERY BIG NUMBERS !!!! Your num must has size < 101 and you can use different operations\n+ adds two larger numbers\n- subtracts one number from another (large)\n=, >, < compares two large numbers\n multiplication and division must have first large number and second single digit number." << endl;
    cin >> a;
    for (int i = 0; i < a.size(); i++) {
        string bufer;
        if (a.size() < 100){
            int difference = 100 - a.size();
            bufer = a[i];
            num[0][difference+i] = stoi(bufer);
        }
    }
    cin >> message;
    cin >> b;
    for (int i = 0; i < b.size(); i++) {
        string bufer;
        if (b.size() < 100){
            int difference = 100 - b.size();
            bufer = b[i];
            num[1][difference+i] = stoi(bufer);
        }
    }
    if (message == "+") {
        for (int i = 99; i > -1; i--) {
            valueChar = num[0][i] + num[1][i];
            if (valueChar > 9) {
                result.push_back(valueChar % 10);
                num[0][i-1] += 1;
                if (num[0][i-1] > 9) {
                    num[0][i-2] += 1;
                    num[0][i-1] = num[0][i-1] % 10;
                } 
            }
            else {
                result.push_back(valueChar);
            }
        }
    }
    else if (message == "-") {
        for (int i = 99; i > -1; i--) {
            valueChar = num[0][i] - num[1][i];
            if (valueChar < 0) {
                result.push_back(valueChar + 10);
                num[0][i-1] -= 1;
                if (num[0][i-1] < 0) {
                    num[0][i-2] -= 1;
                    num[0][i-1] = 9;
                } 
            }
            else {
                result.push_back(valueChar);
            }
        }
    }
    else if (message == "*") {
        if (num[1][98] == 0) {
            for (int i = 99; i > -1; i--) {
                valueChar = num[0][i] * num[1][99];
                result.push_back(valueChar);
            }
            for (int i = 99; i > -1; i--) {
                if (result[i] > 9) {
                    result[i+1] += result[i] / 10;
                    result[i] = result[i] % 10;
                    if (result[i+1] > 9){
                        result[i+2] += result[i+1] / 10;
                        result[i+1] = result[i+1] % 10;
                    }
                }
            }
        }
        else {
            cout << "WRONG INPUT" << endl;
        }
    }
    else if (message == "/") {
        if (num[1][98] == 0) {
            for (int i = 0; i < 100; i++){
                if (num[0][i] != 0) {
                    test = 1;
                }
                if (test > 0) {
                    
                    int rem;
                    int bufer;
                    rem = num[0][i] % num[1][99];
                    valueChar = num[0][i] / num[1][99];
                    result.push_back(valueChar);
                    bufer = stoi(to_string(rem) + to_string(num[0][i+1]));
                    num[0][i+1] = bufer;
                }
            }
            reverse(result.begin(), result.end());
        }
        else {
            cout << "WRONG INPUT" << endl;
        }
        test = 0;
    }

    else if (message == "=") {
        for (int i = 0; i < 100; i++) {
            if (num[0][i] == num[1][i]) {
                test = 1;
            }
            else {
                test = 0;
            }
            
        }
        if (test > 0) {
            cout << "It's True!! My congratulations !!" << endl;
        }
        else {
            cout << "Your mistake... Try again !!!" << endl;
        }
    }
    
    else if (message == ">") {
        for (int i = 0; i < 100; i++) {
            if (num[0][i] > num [1][i]) {
                test = 1;
            }
            else if (num[0][i] == num[1][i] and i != 99) {
                test = 1;
            }
            else {
                test = 0;
            }
        }
        if (test > 0) {
            cout << "It's True!! My congratulations !!" << endl;
        }
        else {
            cout << "Your mistake... Try again !!!" << endl;
        }
        test = 0;
    }
    else if (message == "<") {
        for (int i = 0; i < 100; i++) {
            if (num[0][i] < num[1][i]) {
                test = 1;
            }
            else if (num[0][i] == num[1][i] and i != 99) {
                test = 1;
            }
            else {
                test = 0;
            }
        }
        if (test > 1) {
            cout << "It's True!! My congratulations !!" << endl; 
        }
        else {
            cout << "Your mistake... Try again !!!" << endl;
        }
        test = 0;
    }
    
    else {
        cout << "WRONG INPUT" << endl;
    }

    
    
    test = 0;
    
    for (int i = result.size(); i > -1; i--) {
        if (result[i] != 0) {
            test = 1;
        }
        if (test > 0) { 
            cout << result[i];
        }
        
    }
}
