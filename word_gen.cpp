#include<bits/stdc++.h>

using namespace std;

vector<string> word_list;
string location;
ofstream file;

void write(string t){
    file << (t+"\n");
}

void WLC(string text, int length){
    bool index_flag = false;
    string new_text;
    for (auto word : word_list){
        new_text = text + word;
        if (!index_flag){
            length--;
            index_flag = true;
        }
        if (length){
            WLC(new_text, length);
        }
        else{
            write(new_text);
        }
    }
}

void inp(){
    int min_chain, max_chain;
    string temp;
    cout << "min chain len:";
    cin >> min_chain;
    cout << "max chain len:";
    cin >> max_chain;
    cout << "output location: (folder)\n";
    cin.get();
    getline(cin, temp);
    for (auto i:temp){
        if (i == '\\'){
            location += "\\\\";
        } else {
            location += i;
        }
    }
    location = location + "\\\\out.txt";
    file.open(location, ios_base::app);
    while (1){
        cout << "enter a word/digit: (enter stop to stop)\n";
        string t;
        cin >> t;
        if (t != "stop"){
            word_list.push_back(t);
        } else {
            cout << "do you want to creat the word list?(y/n)";
            string a;
            cin >> a;
            if (a == "y" || a == "yes"){
                break;
            }
        }
    }
    clock_t tStart = clock();
    for (int i=min_chain;i<=max_chain;i++){
        WLC("", i);
    }
    file.close();
    printf("Time taken: %.2fs", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    printf(" or %.2fm", (double)(clock() - tStart)/CLOCKS_PER_SEC/60);
}

int main(){
    inp();
}
