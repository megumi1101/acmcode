#include <iostream>
#include <vector>
using namespace std;
#define int long long
// 快速沃尔什变换（OR卷积）的正变换
void fwt_or(vector<int>& a, bool inverse = false) {
    int n = a.size();
    for (int m = 1; m < n; m <<= 1) {
        for (int i = 0; i < n; i += 2 * m) {
            for (int j = 0; j < m; j++) {
                if (!inverse) {
                    a[i + j + m] += a[i + j];
                } else {
                    a[i + j + m] -= a[i + j];
                }
            }
        }
    }
}

// 主函数：使用FWT实现F(j | ai) += F(j)的累加操作
vector<int> updateFunction(vector<int>& F, vector<int>& a_list, int m) {
    int n = 1 << m;  // 2^m
    vector<int> result = F;
    
    // 对每个ai进行处理
    for (int ai : a_list) {
        // 构造当前ai对应的掩码向量
        vector<int> mask(n, 0);
        mask[ai] = 1;
        
        // 对F和掩码向量分别进行FWT变换
        vector<int> f_transform = result;
        fwt_or(f_transform);
        fwt_or(mask);
        
        // 点乘（对应位相乘）
        vector<int> product(n);
        for (int i = 0; i < n; i++) {
            product[i] = f_transform[i] * mask[i];
        }
        
        // 逆变换回时域并累加到结果中
        fwt_or(product, true);
        for (int i = 0; i < n; i++) {
            result[i] += product[i];
        }
    }
    
    return result;
}

int main() {
    int m = 3;  // j的范围是0到2^m-1
    vector<int> F = {1, 2, 3, 4, 5, 6, 7, 8};  // 初始函数F
    vector<int> a_list = {2, 5};  // a1=2, a2=5
    
    // 执行更新操作
    vector<int> updated_F = updateFunction(F, a_list, m);
    
    // 输出结果
    cout << "原始F: ";
    for (int val : F) {
        cout << val << " ";
    }
    cout << endl;
    
    cout << "更新后的F: ";
    for (int val : updated_F) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}