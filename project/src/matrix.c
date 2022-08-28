#include "matrix.h"

Matrix* create_matrix(size_t rows, size_t cols) {
    if (cols == 0 || rows == 0) { 
        return NULL;
    }
    Matrix *matrix = calloc(1, sizeof(Matrix));
    matrix->data = (double**)calloc(rows + rows*cols, sizeof(double));
    double *start = (double*)((char*)matrix->data + rows*sizeof(double*));
    for (size_t i = 0; i < rows; i++) { 
        matrix->data[i] = start + i*cols;
    }
    matrix->rows = rows;
    matrix->cols = cols;
    return matrix;
}

Matrix* create_matrix_from_file(const char *path_file) { 
    FILE *matrix_file = fopen(path_file, "r");
    if (matrix_file == NULL) { 
        return NULL;
    }
    size_t rows, cols;
    fscanf(matrix_file, "%zu %zu", &rows, &cols);
    Matrix *mat = create_matrix(rows, cols);
    for (size_t i = 0; i < rows; i ++) {
        for (size_t j = 0; j < cols; j++) { 
            fscanf(matrix_file, "%lf", &(mat->data[i][j]));
        }
    }
    fclose(matrix_file);
    return mat;
}

void free_matrix(Matrix *matrix) { 
    free(matrix);
}

// Basic operations
int get_rows(const Matrix* matrix, size_t* rows) { 
    if (NULL == matrix && *rows == 0) { 
        return -1;
    }
    *rows = matrix->rows;
    return 0;
}
int get_cols(const Matrix* matrix, size_t* cols) { 
    if (NULL == matrix && *cols == 0) { 
        return -1;
    }
    *cols = matrix->cols;
    return 0;
}
int get_elem(const Matrix* matrix, size_t row, size_t col, double* val) { 
     if (NULL == matrix && row == 0 && col == 0) { 
        return -1;
    }
    *val = matrix->data[row][col];
    return 0;
}
int set_elem(Matrix* matrix, size_t row, size_t col, double val) {
     if (NULL == matrix && row == 0 && col == 0) { 
        return -1;
    }
    matrix->data[row][col] = val;
    return 0;
}
//Math operations
Matrix* mul_scalar(const Matrix* matrix, double val) { 
    if (NULL == matrix) { 
        return NULL;
    }
    
    Matrix* new_matrix = create_matrix(matrix->rows, matrix->cols); 
    for (size_t i = 0; i < matrix->rows; i++) { 
        for (size_t j = 0; j < matrix->cols; j++) {
            new_matrix->data[i][j] = matrix->data[i][j]*val;
        }
    }
    return new_matrix; 
}

Matrix* sum(const Matrix* l, const Matrix* r) {
    if (l == NULL || r == NULL)  { 
        return NULL;
    }
    if (l->cols == r->cols && l->rows == r->rows ) {
        Matrix *sum_matrix = create_matrix(l->rows, l->cols);
        for (size_t i = 0; i < sum_matrix->rows; i++) { 
            for (size_t j = 0; j < sum_matrix->cols; j++) {
           sum_matrix->data[i][j] = l->data[i][j] + r->data[i][j];
            }
        }
    return sum_matrix;
    } else {
        return NULL;
     }
}
Matrix* sub(const Matrix* l, const Matrix* r) { 
     if (l == NULL || r == NULL) { 
        return NULL;
    }
     if (l->cols == r->cols && l->rows == r->rows) {
        Matrix *sub_matrix = create_matrix(l->rows, l->cols);
    for (size_t i = 0; i < sub_matrix->rows; i++) { 
        for (size_t j = 0; j < sub_matrix->cols; j++) {
           sub_matrix->data[i][j] = l->data[i][j] - r->data[i][j];
        }
    }
    return sub_matrix;
     } else { 
         return NULL;
     }    
}
Matrix* mul(const Matrix* l, const Matrix* r) {
    if (l == NULL || r == NULL) {
        return NULL;
    }
    if (l->cols == r->rows) { 
        Matrix* mul_matrix = create_matrix(l->rows, r->cols);
        for (size_t i = 0; i < l->rows; i++) {
            for (size_t j = 0; j < r->cols; j++) {
                mul_matrix->data[i][j] = 0;
                for (size_t k = 0; k < l->cols; k++) { 
                    mul_matrix->data[i][j] += l->data[i][k]*r->data[k][j];
                }
            } 
        }
        return mul_matrix;
    } else {
        return NULL;
    }
}

Matrix* transp(const Matrix* matrix) {
    if (matrix == NULL) {
        return NULL;
    }
    Matrix *transp_matrix = create_matrix(matrix->cols, matrix->rows);
    for (size_t i = 0; i < matrix->cols; i++) { 
        for (size_t j = 0; j < matrix ->rows; j++) { 
            transp_matrix->data[i][j] = matrix->data[j][i];
        }
    }
    return transp_matrix; 
}


// Extra operations
int det(const Matrix* matrix, double* val) { 
    if (matrix == NULL || val == 0) { 
        return -1;
    }
    return 0;
}
Matrix* adj(const Matrix* matrix) {
    if (matrix == NULL) { 
        return NULL;
    }
return 0;
}
Matrix* inv(const Matrix* matrix) {
    if (matrix == NULL) { 
        return NULL;
    }
    return 0;
}
