#include <string>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <fstream>
#include <vector>


#include "inverter.h"

using namespace std;

map<string, set<int>> invertedIndex;

vector<string> lineToWord(const string s,int fileNum){//split words
    vector<string> ret;
    typedef string::size_type string_size;
    string_size i = 0;

    while( i != s.size() )
    {
//        if(!((s[i] >= 65 && s[i] <=90) || (s[i] >= 97 && s[i] <= 122))){
//            ret.push_back(s.substr(tempHead,i-tempHead));
//            i++;
//            tempHead = i;
//        }
//        else i++;
        if((s[i] >= 65 && s[i] <=90) || (s[i] >= 97 && s[i] <= 122)){
            string_size tempTail = i;
            while((s[tempTail] >= 65 && s[tempTail ] <=90) || (s[tempTail ] >= 97 && s[tempTail ] <= 122)){
                tempTail++;
            }
            ret.push_back(s.substr(i,tempTail-i));
            invertedIndex[s.substr(i,tempTail-i)].insert(fileNum);
            i = tempTail;
        }
        else i++;
    }
    return ret;
}


string build_inverted_index(string filename){

    fstream outFile;
    outFile.open(filename,ios::in);
    string buffer;
    string file[10000];
    int count = 0;
//    cout << "fileNames: " << endl;
    while (getline (outFile, buffer)){ // line does not include '\n'
//        cout << buffer << endl;
        file[count] = buffer;//store file name into buffer
        count++;
    }
    outFile.close();

    int sizeOfArray = sizeof(file)/sizeof(file[0]);//size of string array

    for(int i =0;i < sizeOfArray;i++){
        fstream foo;
        foo.open(file[i],ios::in);
        string fileBuffer;
        string line[10000];
        int textCount = 0;
        while(getline(foo,fileBuffer)){
            //cout << fileBuffer << endl;
            line[i] = fileBuffer;
            vector<string> vec = lineToWord(line[i],i);
//            cout << "vec.size() = " << vec.size() << endl;
//            cout << "contents: " << line[i] << endl;
//            cout << "splited: " << endl;
//            for(auto val : vec){
//                cout << val << endl;
//            }
            textCount++;
        }
        foo.close();
    }
    map<string,set<int>>::iterator it;
    set<int>::iterator sit;
    std::string answer = "";
    for(it = invertedIndex.begin();it != invertedIndex.end();it++){
        cout<< it->first << ":";
        answer += it->first;
        answer += ":";
        for(sit=it->second.begin();sit!=it->second.end();sit++){
            cout<< *sit << " ";
            answer += " ";
            answer += std::to_string(*sit);
        }
        answer += '\n';
    }

	return answer;
}

