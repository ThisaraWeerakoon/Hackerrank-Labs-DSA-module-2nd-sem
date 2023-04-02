#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'lilysHomework' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */
int numOfSwaps(vector<int> arr){
    unordered_map<int,int> dict;//to store index by the values
    int N=arr.size();
    for(int i=0;i<N;i++){
        dict[arr[i]]=i; //make dictionary like thing in c++
    }
    vector<int> temp(arr.begin(),arr.end());//copy the array before sort
    sort(temp.begin(),temp.end());//sort copy
    int count=0;//number of swaps
    for(int j=0;j<N;j++){
        if(arr[j]!=temp[j]){//check whether there is a mismatch between sorted one and actual array
            count++;
            int indexToSwap=dict[temp[j]];//find the wanted index from map
            dict[arr[j]]=indexToSwap;//update the map
            swap(arr[j],arr[indexToSwap]);//swap the unmatched element

        }
    }
    return count;
}

int lilysHomework(vector<int> arr) {
    vector<int> reversed(arr.rbegin(),arr.rend());
    int asc=numOfSwaps(arr);//check with ascending sorted array
    int desc=numOfSwaps(reversed);//check with descending sorted array
    return min(asc,desc);// min between reverse sorted one and ascending one
    
 
    
}



int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = lilysHomework(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
