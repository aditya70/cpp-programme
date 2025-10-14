#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <iomanip>

using namespace std;

struct Job {
    int id;
    int runtime;
    int next_id;
};

struct Chain {
    int start_job;
    int last_job;
    int number_of_jobs;
    int job_chain_runtime;
};

string format_time(int seconds) {
    int hours = seconds / 3600;
    seconds %= 3600;
    int minutes = seconds / 60;
    seconds %= 60;
    stringstream ss;
    ss << setfill('0') << setw(2) << hours << ":" << setw(2) << minutes << ":" << setw(2) << seconds;
    return ss.str();
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string line;
    getline(cin, line);
    
    // Check for malformed header
    if (line != "#job_id,runtime_in_seconds,next_job_id") {
        cout << "Malformed Input" << endl;
        return 0;
    }
    
    unordered_map<int, Job> jobs;
    unordered_map<int, int> in_degree;  // This will help identify start of chains
    
    while (getline(cin, line)) {
        stringstream ss(line);
        string token;
        Job job;
        
        getline(ss, token, ',');
        job.id = stoi(token);
        
        getline(ss, token, ',');
        job.runtime = stoi(token);
        
        getline(ss, token, ',');
        job.next_id = stoi(token);
        
        jobs[job.id] = job;
        in_degree[job.next_id]++;
    }
    
    vector<Chain> chains;

    for (auto &pair : jobs) {
        if (in_degree[pair.first] == 0) {
            Chain chain;
            int current_id = pair.first;
            chain.start_job = current_id;
            chain.number_of_jobs = 0;
            chain.job_chain_runtime = 0;

            while (current_id != 0) {
                chain.number_of_jobs++;
                chain.job_chain_runtime += jobs[current_id].runtime;
                chain.last_job = current_id;  // This will keep updating till the end of the chain
                current_id = jobs[current_id].next_id;
            }
            chains.push_back(chain);
        }
    }
    
    sort(chains.begin(), chains.end(), [](Chain &a, Chain &b) {
        return a.job_chain_runtime > b.job_chain_runtime;
    });

for (Chain &chain : chains) {
        cout << "-" << endl;
        cout << "start_job: " << chain.start_job << endl;
        cout << "last_job: " << chain.last_job << endl;
        cout << "number_of_jobs: " << chain.number_of_jobs << endl;
        cout << "job_chain_runtime: " << format_time(chain.job_chain_runtime) << endl;
        cout << "average_job_time: " << format_time(chain.job_chain_runtime / chain.number_of_jobs) << endl;
    }
    cout << "-" << endl;
    return 0;
}