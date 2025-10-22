
// T(num) = O(√num)
vector<int> getPrimeFactors(int num){
    vector<int> factors;
    int d = 2;
    while (d * d <= num) {
        if (num % d == 0) {
            factors.push_back(d);
            while (num % d == 0) num /= d;
        }
        d++;
    }
    if (num > 1) factors.push_back(num);
    return factors;
}

