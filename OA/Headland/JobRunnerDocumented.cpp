// Include necessary libraries
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

// Define a Job structure with its properties
struct Job {
    int id;           // Job ID
    int runtime;      // Runtime of the job
    int next_id;      // Next job's ID
};

// Define a Chain structure to represent a sequence of jobs
struct Chain {
    int start_job;            // The starting job of the chain
    int last_job;             // The ending job of the chain
    int number_of_jobs;       // Total number of jobs in the chain
    int job_chain_runtime;    // Total runtime for the entire chain
};

// Utility function to format time in seconds to HH:MM:SS format
string format_time(int seconds) {
    int hours = seconds / 3600;
    seconds %= 3600;
    int minutes = seconds / 60;
    seconds %= 60;
    stringstream ss;
    ss << setfill('0') << setw(2) << hours << ":" << setw(2) << minutes << ":" << setw(2) << seconds;
    return ss.str();
}

/**
 * Validates the token read from the stringstream. Checks if the token is non-empty and consists of only digits.
 */
bool isValidToken(stringstream &ss, string &token) {
    if (!getline(ss, token, ',') || token.empty() || !all_of(token.begin(), token.end(), ::isdigit)) {
        return false;
    }
    return true;
}

int main() {
    string line;
    getline(cin, line);
    
    // Validate the header of the input
    if (line != "#job_id,runtime_in_seconds,next_job_id") {
        cout << "Malformed Input" << endl;
        return 0;
    }
    
    // Store the jobs and track the count of jobs that come before each job
    unordered_map<int, Job> jobs;
    unordered_map<int, int> in_degree;  // Helps identify start of chains
    
    // Parse the input and populate the jobs map and in_degree map
    while (getline(cin, line)) {
        stringstream ss(line);
        string token;
        Job job;
        
        // Validate job.id
        if (!isValidToken(ss, token)) {
            cout << "Malformed Input" << endl;
            return 0;
        }
        job.id = stoi(token);
        
        // Validate job.runtime
        if (!isValidToken(ss, token)) {
            cout << "Malformed Input" << endl;
            return 0;
        }
        job.runtime = stoi(token);
        
        // Validate job.next_id
        if (!isValidToken(ss, token)) {
            cout << "Malformed Input" << endl;
            return 0;
        }
        job.next_id = stoi(token);

        // Check if the job ID is unique
        if (jobs.find(job.id) != jobs.end()) {
            cout << "Malformed Input" << endl;
            return 0;
        }
        
        jobs[job.id] = job;
        in_degree[job.next_id]++;
    }

    // Create chains by traversing through the jobs map
    vector<Chain> chains;
    for (auto &pair : jobs) {
        if (in_degree[pair.first] == 0) {
            Chain chain;
            int current_id = pair.first;
            chain.start_job = current_id;
            chain.number_of_jobs = 0;
            chain.job_chain_runtime = 0;

            // Calculate properties for each chain
            while (current_id != 0) {
                chain.number_of_jobs++;
                chain.job_chain_runtime += jobs[current_id].runtime;
                chain.last_job = current_id;
                current_id = jobs[current_id].next_id;
            }
            chains.push_back(chain);
        }
    }
    
    // Sort chains by total runtime
    sort(chains.begin(), chains.end(), [](Chain &a, Chain &b) {
        return a.job_chain_runtime > b.job_chain_runtime;
    });

    // Print the sorted chains
    for (Chain &chain : chains) {
        cout << "-" << endl;
        cout << "start_job: " << chain.start_job << endl;
        cout << "last_job: " << chain.last_job << endl;
        cout << "number_of_jobs: " << chain.number_of_jobs << endl;
        cout << "job_chain_runtime: " << format_time(chain.job_chain_runtime) << endl;
        cout << "average_job_time: " << format_time(chain.job_chain_runtime / chain.number_of_jobs) << endl;
    }
    
    if(chains.size() > 0) {
        cout << "-" << endl;
    }
    
    return 0;
    
}
