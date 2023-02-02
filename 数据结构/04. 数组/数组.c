#include <stdarg.h>
#include <stdlib.h>


#define MAX_ARRAY_DIM 8 // 最大数组维数
#define OK 0
#define ERROR 1
#define OVERFLOW 2
#define UNDERFLOW 3


typedef struct {
    int *base; // 数组元素基址
    int dim;
    int *bounds; // 数组维界基址
    int *constants; // 映像函数常量基址
}Array;


void InitArray(Array *a, int dim, ...) {
    if(dim < 1 || dim > MAX_ARRAY_DIM) exit(ERROR);
    a->dim = dim;
    a->bounds = (int *)malloc(dim * sizeof(int)); // 每个维分配一个数组维界基址
    if(!a->bounds) exit(OVERFLOW);
    int count = 1; // 求元素总数count
    va_list ap; // 存放变长参数表
    va_start(ap, dim);
    for(int i=0; i<dim; ++i) {
        a->bounds[i] = va_arg(ap, int);
        if(a->bounds[i] < 0) exit(UNDERFLOW); // 维的长度不可能小于0
        count *= a->bounds[i]; // 新增一个维度后count改变
    }
    va_end(ap);
    a->base = (int *)malloc(count * sizeof(int));
    if(!a->base) exit(OVERFLOW);
    // 映像函数常数
    a->constants = (int *)malloc(dim * sizeof(int));
    if(!a->constants) exit(OVERFLOW);
    // 求每一维的映像函数常量 其中第n维（下标是n-1）的c=1(L)
    a->constants[dim-1] = 1;
    for(int i=dim-2; i>=0; --i) {
        a->constants[i] = a->bounds[i+1] * a->constants[i+1];
    }
}


void DestroyArray(Array *a) {
    if(!a->base) exit(ERROR);
    if(!a->bounds) exit(ERROR);
    if(!a->constants) exit(ERROR);
    free(a->base);
    a->base = NULL;
    free(a->bounds);
    a->bounds = NULL;
    free(a->constants);
    a->constants = NULL;
}


int Locate(Array a, va_list ap, int *o) {
    *o = 0;
    for(int i=0; i<a.dim; ++i) {
        int pos = va_arg(ap, int);
        if(pos < 0 || pos >= a.bounds[i]) return OVERFLOW;
        o += a.constants[i] * pos; // c_i * j_i
    }
    return OK;
}


int Value(Array a, int *e, ...) {
    // e是元素变量 随后跟随n个下标值
    // 如果下标组合有效 则赋值给e
    va_list ap;
    va_start(ap, e);
    int o = 0;
    int result = Locate(a, ap, &o);
    if(result != 0) return result;
    *e = *(a.base + o);
    return OK;
}


int Assign(Array a, int e, ...) {
    // e是元素变量 随后跟随n个下标值
    // 如果下标组合有效 则把e赋值给指向的元素
    va_list ap;
    va_start(ap, e);
    int o = 0;
    int result = Locate(a, ap, &o);
    if(result != 0) return result;
    *(a.base + o) = e;
    return OK;
}


int main() {
    return 0;
}