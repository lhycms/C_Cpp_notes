#include <iostream>
#include <complex>
#include <cblas.h>


int main() {
    typedef std::complex<double> Comp;   // 定义复数类型
    int Nr = 2, Nc = 3; // 矩阵行数和列数
    // 矩阵和矢量分配内存
    Comp *a = new Comp[Nr * Nc];
    Comp *x = new Comp[Nc];
    Comp *y = new Comp[Nr];
    Comp alpha(1, 0), beta(0, 0);
    
    // x 矢量赋值
    for (int i = 0; i < Nc; i++)
        x[i] = Comp(i+1., 0);
    // a 矩阵赋值
    for (int i = 0; i < Nc * Nr; i++) 
        a[i] = Comp(i+1., 0);
    
    // 做乘法
    cblas_zgemv(CblasColMajor, CblasNoTrans, Nr, Nc, &alpha, a, Nr, x, 1, &beta, y, 1);
    
    std::cout << std::endl;

    // 以列主元的形式输出
    for (int i = 0; i < Nr; i++) {
        for (int j = 0; j < Nc; j++) {
            std::cout << a[i + Nr*j] << "  ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    
    for (int i = 0; i< Nr; i++)
        std::cout << y[i] << "  ";

    std::cout << std::endl;
    return 0;
}