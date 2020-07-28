#include <iostream>
#include <vector>
#include <algorithm>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

using namespace std;
class TreeOrders {
    int n;
    vector <int> key;
    vector <int> left;
    vector <int> right;
    TreeOrders* trees;

public:
    void read() {
        cin >> n;
        key.resize(n);
        left.resize(n);
        right.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> key[i] >> left[i] >> right[i];
        }
    }


    void in_order(vector <int>& result,int tree) {
        if (tree==-1)
        {
            return;
        }
        
            in_order(result,this->left[tree]);
            result.push_back(this->key[tree]);
            in_order(result,this->right[tree]);

        

    }

    void  pre_order(vector <int>& result,int tree) {
        
        if (tree == -1)
        {
            return;
        }

        result.push_back(this->key[tree]);
        pre_order(result,this->left[tree]);
        pre_order(result,this->right[tree]);


        
    }

    void post_order(vector <int>&result,int tree) {

        if (tree == -1)
        {
            return;
        }
        post_order(result,this->left[tree]);
        post_order(result,this->right[tree]);
        result.push_back(this->key[tree]);
    }
    vector <int> IN() {
        vector<int>result;
        in_order(result, 0);
        return result;
    }
    vector <int> PRE() {
        vector<int>result;
        pre_order(result, 0);
        return result;

    }
    vector <int> POST() {
        vector<int>result;
        post_order(result, 0);
        return result;

    }

};

void print(vector <int> a) {
    for (size_t i = 0; i < a.size(); i++) {
        if (i > 0) {
            cout << ' ';
        }
        cout << a[i];
    }
    cout << '\n';
}

int main_with_large_stack_space() {
    ios_base::sync_with_stdio(0);
    TreeOrders t;
    t.read();
    print(t.IN());
    print(t.PRE());
    print(t.POST());
    return 0;
}

int main(int argc, char** argv)
{
#if defined(__unix__) || defined(__APPLE__)
    // Allow larger stack space
    const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
    struct rlimit rl;
    int result;

    result = getrlimit(RLIMIT_STACK, &rl);
    if (result == 0)
    {
        if (rl.rlim_cur < kStackSize)
        {
            rl.rlim_cur = kStackSize;
            result = setrlimit(RLIMIT_STACK, &rl);
            if (result != 0)
            {
                std::cerr << "setrlimit returned result = " << result << std::endl;
            }
        }
    }
#endif

    return main_with_large_stack_space();
}

