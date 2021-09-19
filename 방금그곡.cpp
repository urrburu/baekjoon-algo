#include <string>
#include <vector>
using namespace std;
vector<string> strtok(string str, char delim = ' ') { // strtok
    vector<string> ret;
    int prev = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == delim) {
            ret.push_back(str.substr(prev, i - prev));
            prev = i + 1;
        }
    }
    if (str.size() != prev)
        ret.push_back(str.substr(prev, str.size() - prev));
    return ret;
}

string matchTime(string code, int st, int et) {
    int cnt = 0;
    for (int j = 0; j < code.size(); j++) {
        if (code[j] != '#')
            cnt++;
    }
    if (cnt < et - st) {
        int k = 0;
        while (cnt != et - st) {
            code += code[k++];
            if (code[k] == '#') {
                code += code[k];
                k++;
            }
            cnt++;
        }
    }
    else if (cnt > et - st) {
        cnt = 0;
        for (int j = 0; j < code.size(); j++) {
            if (code[j] != '#') {
                cnt++;
                if (cnt == et - st) {
                    if (code[j + 1] == '#')
                        code = code.substr(0, j + 2);
                    else
                        code = code.substr(0, j + 1);
                    break;
                }
            }
        }
    }
    return code;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    int maxT = 0;
    for (int i = 0; i < musicinfos.size(); i++) {
        vector<string> temp = strtok(musicinfos[i], ',');
        string code = temp[3];
        int st = stoi(temp[0].substr(0, 2)) * 60 + stoi(temp[0].substr(3, 2));
        int et = stoi(temp[1].substr(0, 2)) * 60 + stoi(temp[1].substr(3, 2));
        bool isIn = false;
        code = matchTime(code, st, et);
        int k = 0;
        while (code.find(m, k) != string::npos) {
            int ii = code.find(m, k);
            if (ii + m.size() >= code.size() || (ii + m.size() < code.size() && code[ii + m.size()] != '#')) {
                isIn = true;
                break;
            }
            k += m.size();
        }
        if (isIn) {
            if (maxT < et - st) { // °»½Å
                maxT = et - st;
                answer = temp[2];
            }
        }
    }
    if (answer == "")
        return "(None)";
    return answer;
}





#include <string>
#include <vector>

using namespace std;

string convertSharp(string notes)
{
    string ret = "";
    const int diff = 'A' - 'a';
    for (int i = 0; i < notes.size(); i++)
    {
        if (i < notes.size() - 1 && notes.at(i + 1) == '#')
        {
            ret.push_back((char)(notes.at(i) - diff));
            i++;
        }
        else
        {
            ret.push_back(notes.at(i));
        }
    }
    return ret;
}

string getNotesToFind(string info, int countToFind, string& title)
{
    string ret = "";

    const int maxTime = 24 * 60;
    int begin = stoi(info.substr(0, 2)) * 60 + stoi(info.substr(3, 2));
    int end = stoi(info.substr(6, 2)) * 60 + stoi(info.substr(9, 2));
    int runLength = begin >= maxTime ? 0 : min(maxTime, end) - begin;
    if (countToFind > runLength)
        return ret;

    title = info.substr(12, info.rfind(',') - 12);
    int notePtr = 13 + title.size();
    int noteLength = info.size() - notePtr;
    string notes = convertSharp(info.substr(notePtr, noteLength));
    noteLength = notes.size();
    for (int r = 0; r < runLength / noteLength; r++)
    {
        ret = ret.append(notes);
    }
    ret = ret.append(notes, 0, runLength % noteLength);
    return ret;
}


string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";

    int length = 0;
    for (auto it = musicinfos.begin(); it != musicinfos.end(); it++)
    {
        string title;
        string fnotes = convertSharp(m);
        string notes = getNotesToFind(*it, fnotes.size(), title);
        if (notes.find(fnotes) != string::npos && notes.size() > length)
        {
            answer = title;
            length = notes.size();
        }
    }

    return answer;
}