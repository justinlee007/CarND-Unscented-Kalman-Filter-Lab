#include <iostream>
#include "Eigen/Dense"
#include <vector>
#include "ukf.h"

using namespace std;
using Eigen::MatrixXd;
using Eigen::VectorXd;
using std::vector;

int main() {

  // Create a UKF instance
  UKF ukf;

  /*******************************************************************************
  * Programming assignment calls
  *******************************************************************************/

  MatrixXd Xsig = MatrixXd(11, 5);
  ukf.GenerateSigmaPoints(&Xsig);

  MatrixXd Xsig_aug = MatrixXd(15, 7);
  ukf.AugmentedSigmaPoints(&Xsig_aug);

  MatrixXd Xsig_pred = MatrixXd(15, 5);
  ukf.SigmaPointPrediction(&Xsig_pred);

  VectorXd x_pred = VectorXd(5);
  MatrixXd P_pred = MatrixXd(5, 5);
  ukf.PredictMeanAndCovariance(&x_pred, &P_pred);

  return 0;
}
