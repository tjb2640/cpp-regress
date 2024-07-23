#include <iostream>
#include <vector>
#include <Eigen/Dense>

// http://users.stat.umn.edu/~helwig/notes/mvlr-Notes.pdf
// https://people.stfx.ca/bliengme/exceltips/Regression%20Analysis%20using%20Matrix%20Algebra.htm

// Do multivariate linear regression here
Eigen::VectorXd regress(Eigen::MatrixXd& xmat, const Eigen::VectorXd& yvec) {
    // Fill an extra column with 1s for the intercept,
    // and do some transposals to calculate the coefficients.
    Eigen::MatrixXd xintercept(xmat.rows(), xmat.cols() + 1);
    xintercept << Eigen::MatrixXd::Ones(xmat.rows(), 1), xmat;
    return (xintercept.transpose() * xintercept).inverse() * xintercept.transpose() * yvec;
}

int main() {
    // Just using the example values from the stfx.ca link up top to verify correctness
    Eigen::MatrixXd xmat(6, 2);
    xmat << 1, 1,
            2, 4,
            3, 9,
            4, 16,
            5, 25,
            6, 36;

    Eigen::VectorXd yvec(6);
    yvec << 0.5,
            2.0,
            7.5,
            17.0,
            30.5,
            48.0;

    Eigen::VectorXd bmatrix = regress(xmat, yvec);

    std::cout << "B matrix: [" << bmatrix(0) << " (intercept)";
    for (int i = 1; i < bmatrix.size(); i++) {
        std::cout << ", " << bmatrix(i);
    }
    std::cout << "]" << std::endl;

    return 0;
}
