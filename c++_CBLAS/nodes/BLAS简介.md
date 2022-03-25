<font color="orange" size="4"><b>
函数名：https://www.gnu.org/software/gsl/doc/html/cblas.html#examples
函数作用：http://www.netlib.org/blas/#_documentation
</b></font>

# CBLAS使用手册：https://www.intel.com/content/www/us/en/develop/documentation/onemkl-developer-reference-c/top/blas-and-sparse-blas-routines/blas-routines/blas-level-2-routines/cblas-gemv.html

# 1. BLAS 包含四类数据的计算
<font color="gree" size="4"><b>

- `s`: 单精度实数 （最常用的）
- `d`: 双精度实数
- `c`: 单精度复数
- `z`: 双精度复数

</b></font>

在机器学习中大量依赖的是`gemm`（矩阵乘）和`gemv`（矩阵乘向量）。这里不建议使用blas网站上的fortran示例，这个库的实现很慢。现在计算速度比较快的blas库是intel的mkl，非商业的实现可以用openblas，后者最好自己编译一遍，以适合自己电脑的cpu。在gpu上计算一般使用cublas，号称速度是mkl的20倍左右。pascal架构的显卡计算双精度的速度远远慢于单精度（Tesla除外），所以使用双精度时gpu速度一般会反而慢于cpu。

# 2. BLAS 计算级别 (LEVEL)
<font color="gree" size="4"><b>

1. 向量与向量操作 (复杂度=n)
2. 矩阵与向量操作 (复杂度=n^2)
3. 矩阵与矩阵操作 (复杂度=n^3)
  
</b></font>


# 3. 函数命名格式 (举例说明)
<font color="orange" size="4"><b>
根据上述的`数据类型`和`计算级别`，BLAS有一套系统的命名规则。

函数名的格式为`cblas_?gemv`：
- `cblas_`：固定前缀
- `?`: 表示`数据类型`，
  - s：单精度实数(float)
  - d：双精度实数(double)
  - c：单精度复数
  - z：双精度复数
- `ge`: 表示输入的是一个一般矩阵，以行主序或者列主序线性存储
- `mv`: 表示矩阵与向量操作

</b></font>


# 4. `cblas_zgemv`为例
`cblas_zgemv`函数声明：
```c++
void cblas_zgemv (const CBLAS_LAYOUT Layout, const CBLAS_TRANSPOSE trans,
const MKL_INT m, const MKL_INT n, const void *alpha, const void *a,
const MKL_INT lda, const void *x, const MKL_INT incx, const void *beta,
void *y, const MKL_INT incy);
```
BLAS 接口给人的第一感觉就是冗长，为什么实现一个简单的功能需要这么多变量？因为这个接口具有相当大的灵活性．
- 例如可以使用一个列主序（行主序）矩阵的子矩阵作为矩阵，又例如可以使用一个列主序（行主序）矩阵的某一行（列）作为矢量
- 例如可以在做乘法以前对矩阵进行转置
- 例如可以把相乘的结果累加到输出矢量已有的值上，而不是直接覆盖．


```c++
// 计算矩阵—矢量乘法 y = a * x
#include <iostream>
#include <complex>
#include <cblas.h>
int main() {
    using namespace std;
    typedef complex<double> Comp; // 定义复数类型
    int Nr = 2, Nc = 3; // 矩阵行数和列数
    // 矩阵和矢量分配内存
    Comp *a = new Comp [Nr*Nc];
    Comp *x = new Comp [Nc];
    Comp *y = new Comp [Nr];
    Comp alpha(1, 0), beta(0, 0);
    // x 矢量赋值
    for (int i = 0; i < Nc; ++i) {
        x[i] = Comp(i+1., i+2.);
    }
    // a 矩阵赋值
    for (int i = 0; i < Nr*Nc; ++i) {
        a[i] = Comp(i+1., i+2.);
    }
    // 做乘法
    cblas_zgemv(CblasColMajor, CblasNoTrans, Nr, Nc, &alpha, a,
        Nr, x, 1, &beta, y, 1);
        
    // 控制行分别输出 x, a, y
    for (int i = 0; i < Nc; ++i) {
        cout << x[i] << "  ";
    }
    cout << "\n" << endl;
    for (int i = 0; i < Nr; ++i) {
        for (int j = 0; j < Nc; ++j) {
            cout << a[i + Nr*j] << "  ";
        }
        cout << endl;
    }
    cout << "\n" << endl;
    for (int i = 0; i < Nr; ++i) {
        cout << y[i] << "  ";
    }

    std::cout << std::endl;
    return 0;
}
```

Output:
```shell
(1,2)  (2,3)  (3,4)  

(1,2)  (3,4)  (5,6)  
(2,3)  (4,5)  (6,7)  


(-18,59)  (-21,74) 
```

## Description
The `?gemv` routines perform a matrix-vector operation defined as:
$$y := alpha*A*x + beta*y,$$
or
$$y := alpha*A'*x + beta*y,$$
or
$$y := alpha*conjg(A')*x + beta*y,$$
where:
- `alpha` and `beta` are scalars,
- `x` and `y` are vectors,
- `A` is an m-by-n matrix.


## Parameter 版本一
`void cblas_zgemv (const CBLAS_LAYOUT Layout, const CBLAS_TRANSPOSE trans, const MKL_INT m, const MKL_INT n, const void *alpha, const void *a, const MKL_INT lda, const void *x, const MKL_INT incx, const void *beta, void *y, const MKL_INT incy);`

1. `layout`: Species two-dimensional array storage is row-major/column-major
    Layout（一个 enum 类型）指定行主序（CblasRowMajor）还是列主序（CblasColMajor）
2. `trans`: 
    我们只需要关心几个变量，即 Layout（一个 enum 类型）指定行主序（CblasRowMajor）还是列主序（CblasColMajor）
    - `trans = CblasNoTrans`：不转置
    - `trans = CblasTrans`：转置
    - `trans = CblasConjTrans`
3. `m`: 指定矩阵 A 的行数(>=0)
4. `n`: 指定矩阵 A 的列数(>=0)
5. `alpha`: Specifies the scalar `alpha`
6. `a`: 
    Array, size `lda` * k:
    - `layout = CblasColMajor`: k = `n`. Before entry, the leading `m`-by-`n` part of the array `a` must contain the matrix `A`
    - `layout = CblasRowMajor`: k = `m`. Before entry, the leading `n`-by-`m` part of the array `a` must contain the matirx `A`
7. `lda`: 
    Specifies the leading dimension of a as declared in the calling (sub)program：
    - For `layout = CblasColMajor`, the value of `lda` must be at least max(1, m)
    - For `layout = CblasRowMajor`, the value of `lda` must be at least max(1, n)
8. `x`:
    Array:
    - size at least (1+(n-1)*abs(incx)) when trans=CblasNoTrans and 
    - size at least (1+(m-1)*abs(incx)) otherwise. 
    - Before entry, the incremented array x must contain the vector x.
9.  `incx`: 
    Specifies the increment for the elements of x. The value of `incx` must not be 0
10. `beta`:
    Specifies the scalar `beta`. When beta is set to zero, then y need not be set on input.
11. `y`:
    Array:
    - size at least (1 +(m - 1)*abs(incy)) when trans=CblasNoTrans
    - size at least (1 +(n - 1)*abs(incy)) otherwise.
    - Before entry with non-zero beta, the incremented array y must contain the vector y.
12. `incy`:
    Specifies the increment for the elements of y. The value of incy must not be zero.


<font color="orange" size="4"><b>
leading dimension ( lda s)

$$\left[ 
\begin{matrix} 
a & b & c & d & e\\ 
f & g & h & i & j \\ 
k & l & m & n & o \\ 
p & q & r & s & t 
\end{matrix} \right]$$

- 矩阵空间是 4\*5，其左上角有一个矩阵 3\*4
- i, j 分裂为行、列索引
- 如果用列存储: leading dimension = 4（矩阵行的数目）
- 如果用行存储: leading dimension = 5（矩阵列的数目）

</b></font>

## Output
- `y`: Updated vector y.


## Parameter 版本二
作为一个最简单的例子，我们可以用以下测试函数，在这个例子中，我们只需要关心几个变量，即 Layout（一个 enum 类型）指定行主序（CblasRowMajor）还是列主序（CblasColMajor），m 和 n 分别指定矩阵的行数和列数，a, x, y 分别是矩阵第一个元的指针．

- trans（也是 enum）指定预先转置矩阵（CblasTrans）或不转置（CblasNoTrans）
- alpha, beta 用于计算 y = alpha * a * x + beta y，上例中我们使用了 alpha = 1, beta = 0
- lda 叫做 leading dimension，在列主元的情况下用于指定从某一列第 i 个元的索引（index）减去上一列第 i 元的索引．在上例中 lda 就是行数．但如果我们需要在一个更大的列（行）主元矩阵中截取一个小矩阵进行计算，那么 lda 就是大矩阵的行（列）数．
- incx 和 incy 用于指定两个矢量的步长（increment），由于上例中两矢量在内存中是连续的，所以步长为 1．但若某个矢量是行（列）主元矩阵中的一列（行），那么步长就是矩阵的列（行）数．