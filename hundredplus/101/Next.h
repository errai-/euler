#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <cmath>
#include <Eigen/Dense>
#include <Eigen/Eigenvalues>
#include <limits>

using std::cout;
using std::endl;
using std::string;
using std::pair;
using std::vector;

using namespace Eigen;

typedef unsigned long int ulong;
typedef Matrix<double,Dynamic,1> VectorXul;
typedef Matrix<double,Dynamic,Dynamic> MatrixXul;

static ulong Truth(int k) {
    return 1-k+pow(k,2)-pow(k,3)+pow(k,4)-pow(k,5)+pow(k,6)-pow(k,7)+pow(k,8)-pow(k,9)+pow(k,10);
}

MatrixXul Coeffs(const unsigned n) {
    MatrixXul cfs(n,n);
    for ( unsigned row = 0; row < n; ++row ) {
    for ( unsigned col = 0; col < n; ++col ) {
        cfs(row,col) = pow( row+1, col );
    }
    }
    return cfs;
}

template<class Iter>
static double BOP(Iter start, Iter stop) {
    unsigned n = stop-start;
    VectorXul vals(n);

    unsigned pos = 0;
    while ( start != stop ) {
        vals( pos++ ) = *(start++);
    }

    VectorXul res = Coeffs(n).inverse()*vals;
    double nplus1 = 0;

    for ( unsigned i = 0; i < n; ++i ) {
        nplus1 += res(i)*pow( n+1, i );
    }
    return nplus1;
}

//class Data {
//private:
//    VectorXd x_data, y_data;
//
//    Matrix2d covariance;
//    Matrix2d transformation;
//    /* x and y errors in the new base */
//    Matrix2d diag_errs;
//
//    bool fresh_covariance;
//    bool fresh_transformation;
//public:
//    Data() {
//        fresh_covariance = false;
//        fresh_transformation = false;
//    }
//
//    unsigned no_entries() { return x_data.size(); }
//
//    void add_data(double x, double y) {
//        unsigned loc = x_data.size();
//        x_data.conservativeResize( loc+1 );
//        x_data( loc ) = x;
//        y_data.conservativeResize( loc+1 );
//        y_data( loc ) = y;
//        if (fresh_covariance) {
//            fresh_covariance = false;
//            fresh_transformation = false;
//        }
//    }
//
//    Matrix2d covariance_matrix() {
//        refresh_covariance();
//        return covariance;
//    }
//
//    Matrix2d error_matrix() {
//        refresh_transformation();
//        return diag_errs;
//    }
//
//    Matrix2d transformation_matrix() {
//        refresh_transformation();
//        return transformation;
//    }
//
//    /* The covariance matrix is recalculated only on demand */
//    bool refresh_covariance();
//    /* Diagonalization made only on demand */
//    bool refresh_transformation();
//
//    double x_val() { return x_data.mean(); }
//    double y_val() { return y_data.mean(); }
//    double r_val() { return sqrt( pow(x_val(),2)+pow(y_val(),2) ); }
//
//    /* Significance in the naive way */
//    /* Calculate errors only using the diagonal values of the original matrix */
//    double r_err_naive() {
//        refresh_covariance();
//        return (sqrt(covariance(0,0))*fabs(x_val()) + sqrt(covariance(1,1))*fabs(y_val()))/(r_val());
//    }
//    double significance_naive() {
//        return r_val()/r_err_naive();
//    }
//    double r_err_alt() {
//        refresh_covariance();
//        return sqrt(covariance(0,0)*pow(x_val(),2)+(covariance(1,0)+covariance(0,1))*x_val()*y_val()+covariance(1,1)*pow(y_val(),2))/r_val();
//    }
//
//    /* Calculate errors through diagonalization */
//    double r_err();
//    /* Significance using diagonalization */
//    double significance();
//};
