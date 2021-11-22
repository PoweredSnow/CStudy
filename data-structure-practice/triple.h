#define MAXSIZE 12500   //假设非零元个数的最大值为 12500
#define OK 0

typedef int ElemType;
typedef int Status;

typedef struct {
    int i, j;          // 该非零元的行下标和列下标
    ElemType e;
} Triple;
typedef struct {
    Triple data[MAXSIZE + 1]; // 非零元三元组表，data[0] 未用;
    int mu, nu, tu;           // 矩阵的行数、列数和非零元个数
} TSMatrix;


// 采用三元组表存储表示，求稀疏矩阵 M 的转置矩阵 T 。
Status TransposeSMatrix(TSMatrix M, TSMatrix& T) {
    T.mu = M.nu; T.nu = M.mu; T.tu = M.tu;
    if (T.tu) {
        int q = 1;
        for (int col = 1; col <= M.nu; col++) {
            for (int p = 1; p <= M.tu; p++) {
                if (M.data[p].j == col) {
                    T.data[q].i = M.data[p].j;
                    T.data[q].j = M.data[p].i;
                    T.data[q].e = M.data[p].e;
                    ++q;
                }

            }
        }
    }
    return OK;
}

