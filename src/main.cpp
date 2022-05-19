#include<string>
#include<string.h>
#include<iostream>
#include<ncurses.h>
#include<set>
#include<glog/logging.h>
#include <gflags/gflags.h>
#include<array>
#include<time.h>
#include<unistd.h>
#include<vector>
#include<gtest/gtest.h>
#include"test_unnitest.h"
#include"test.h"
using namespace std;


int glog_init(){
    FLAGS_log_dir = "/home/lighthouse/code/clearn/log";
    FLAGS_logtostderr = true; // whether to stdout 
    FLAGS_alsologtostderr = true;  // whether log and std together
    FLAGS_colorlogtostderr = true; // color change if stdout 
    FLAGS_log_prefix = true; // whether add log prefix
    FLAGS_logbufsecs = 0; // delay out 
    FLAGS_max_log_size = 10; // max log size 
    FLAGS_stop_logging_if_full_disk = true; // whether to log if disk is full
    FLAGS_minloglevel = google::GLOG_INFO; // set min log level 
    return 0;
    }

int* bubblesort(int a[], int n){
    if(n <= 1){
        return a;
    }

    for(int j=n-1;j>0;j--){
        for(int i=0;i<j;i++){
            if(a[i] < a[i+1] ){
                std::swap(a[i],a[i+1]);
            }
        } 
    }
}

int* selectsort(int a[], int n){

    for(int i=0;i<n;i++){

        int tmp = INT64_MIN;
        for(int j=i;j<n;j++){
            if(a[j] > tmp ){
                std::swap(a[j],a[tmp]);
            }
        } 
    }
}
DEFINE_bool(bubblesort_bool, false, "bool flag");
DEFINE_bool(selectsort_bool, false, "bool_flag");
DEFINE_bool(insertsort_bool, false, "bool_flag");
DEFINE_bool(mergesort_bool, false, "bool_flag");

int maxProduct() {
    vector<string> words = {"a","ab","abc","d","cd","bcd","abcd"};
    int max_len = 0;
    int cur_len = 0;
    int find = 0;
    for(auto iter_left=words.begin(); iter_left != words.end() - 1; iter_left ++){
        
        set<char> pool;
        for(auto item : *iter_left){
            pool.insert(item);
        }
        for(auto iter_right = iter_left + 1;iter_right != words.end(); iter_right ++){
            std::cout << (*iter_left) << " | " << (*iter_right) << std::endl;

            find = 0;
            cur_len =0;
            for(char it : *iter_right ){
                    if(pool.count((it)) == 1){
                        find = 1;
                }
            }
            std::cout << "cur_len: " << cur_len << std::endl;
            std::cout << "cur_find: " << find << std::endl;

            if(find == 0){
                cur_len = ((*iter_left).length()) *  ((*iter_right).length()) ;
                max_len = max(cur_len, max_len); 
            }
            else{
                cur_len = 0;
            }

            std::cout << "cur_len: " << cur_len << std::endl;

        }
    }
    std::cout << "max_len" << max_len << std::endl;
    return max_len;
}

class Base1
{
public:
    int base1_1;
    int base1_2;
};

void show(string name,string content){
    std::cout << name << " : " << content << endl;
}

int main(int argc, char * argv[]){

    Base1 base;
    base.base1_1 = 1;
    base.base1_2 = 2;
     
    show("base1", std::to_string(base.base1_1));

    glog_init();
    ::testing::InitGoogleTest(&argc, argv);
    int istest = RUN_ALL_TESTS();
    

    clock_t clk = clock();

    gflags::ParseCommandLineFlags(&argc, &argv, false);
    // stage1
    if(FLAGS_bubblesort_bool){
        std::cout << "bubblesort..." << std::endl; 
    }

    // stage2
    if(FLAGS_selectsort_bool){
        std::cout << "selectsort..." << std::endl; 
    }

    // stage3
    if(FLAGS_insertsort_bool){
        std::cout << "insertsort..." << std::endl; 
    }

    //stage4
    if(FLAGS_mergesort_bool){
        std::cout << "mergesort..." << std::endl; 
    }
    for(int i=0;i<argc;i++){
        std::cout << argv[i] << std::endl;  
    }
    int a[5]= {2,6,4,3,2};
    //bubblesort(a,1);
    selectsort(a,5);
    std::set<int> num;
    google::InitGoogleLogging("./log");
    num.insert(1);
    for(auto &x :a){
        std::cout << x << std::endl;  
    }
    
    std::array<long,50> arr;
    for(long &item:arr){  
        item = rand();
        //LOG(INFO) << item;
    }
    sleep(1);
    long i = 100000000L;
    while(i--);

    clk = clock() - clk;
    printf ("It took me %d clicks (%f seconds).\n",clk,((float)clk)/CLOCKS_PER_SEC);
    LOG(INFO) << ((float)clk)/CLOCKS_PER_SEC;

    test_vect::test_vector();
    test_list::func_list();
    test_unordered::func_unordered_multiset();

    std::string aaa = "abcde";
    char x = aaa[1];
    LOG(INFO) << x;

    //maxProduct();
    LOG(INFO) << "end pro";
    return 0;
}