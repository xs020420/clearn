#include<vector>
#include<list>
#include<string>
#include<unordered_set>
#include<glog/logging.h>
#include<gflags/gflags.h>
#include<algorithm>
using namespace std;
namespace test_vect{
    void test_vector(){

        vector<string> t;

        string a = "aabc";
        string b = "ccdd";
        string c = "ccdd";

        t.push_back(a);
        t.push_back(b);
        t.push_back(c);

        LOG(INFO) << t[0];
        LOG(INFO) << t.size();
        LOG(INFO) << t.capacity();
        LOG(INFO) << t.front();
        LOG(INFO) << t.back();

        auto item = ::find(t.begin(), t.end(), "aabc");
        if (item != t.end()){
            LOG(INFO) << "find target";
        }
        else{
            LOG(INFO) << "not find target";

        }
    }
}

namespace test_list{

    void func_list(){
        list<string> t;
        
        string a = "aabc";
        string b = "ccdd";
        string c = "ccdd";

        t.push_back(a);
        t.push_back(b);
        t.push_back(c);

        LOG(INFO) << t.size();
        LOG(INFO) << t.front();
        LOG(INFO) << t.back();

    }

}

namespace test_unordered{
    void func_unordered_multiset(){
        unordered_multiset<string> ms;

        string a = "aabc";
        string b = "ccdd";
        string c = "ccdd";

        ms.insert(a);
        ms.insert(b);
        ms.insert(c);

        LOG(INFO) << ms.size();
        LOG(INFO) << ms.bucket_count();



    }

}