#include<bits/stdc++.h>
#include<thread>
using namespace std;

bool compile(const string& source, const string& target) {
    string cmd = "g++ -o " + target + " " + source + " -g -O2 -std=c++26";
    cout << "正在编译 " << source << "..." << endl;
    int result = system(cmd.c_str());
    if (result != 0) {
        cout << "编译 " << source << " 失败！" << endl;
        return false;
    }
    cout << "编译 " << source << " 成功！" << endl;
    return true;
}

// 用于并行执行的函数
void runProgram(const string& cmd, long long& duration) {
    auto start = chrono::high_resolution_clock::now();
    system(cmd.c_str());
    auto end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

bool compareFiles(const string& file1, const string& file2) {
    ifstream f1(file1), f2(file2);
    string line1, line2;
    
    while (getline(f1, line1) && getline(f2, line2)) {
        // 简单比较，可根据需要改进（如忽略空格、大小写等）
        if (line1 != line2) return false;
    }
    
    // 检查是否有一个文件更长
    return !(getline(f1, line1) || getline(f2, line2));
}

int main() {
    // 编译三个程序
    if (!compile("data.cpp", "data") || 
        !compile("baoli.cpp", "baoli") || 
        !compile("std.cpp", "std")) {
        return 1;
    }
    
    // 对拍测试
    for(int i = 1; i <= 50000; i++) {
        cout << "\n===== 测试点 #" << i << " =====" << endl;
        
        // 生成数据
        cout << "生成测试数据..." << endl;
        system("data > in.txt");
        
        // 并行运行暴力解法和标准解法
        long long duration1 = 0, duration2 = 0;
        thread t1(runProgram, "baoli < in.txt > baoli.txt", ref(duration1));
        thread t2(runProgram, "std < in.txt > std.txt", ref(duration2));
        
        // 等待两个线程完成
        t1.join();
        t2.join();
        
        // 输出运行时间
        cout << "暴力解法耗时: " << duration1 << "ms" << endl;
        cout << "标准解法耗时: " << duration2 << "ms" << endl;
        
        // 比较结果
        cout << "比较输出结果..." << endl;
        if (!compareFiles("std.txt", "baoli.txt")) {
            cout << "测试点 #" << i << ": WA (答案不一致)" << endl;
            cout << "测试数据已保存到 in.txt" << endl;
            break;
        } else {
            cout << "测试点 #" << i << ": AC (答案一致)" << endl;
        }
    }
    
    return 0;
}