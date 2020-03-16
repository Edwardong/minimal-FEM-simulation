#include <eigen3/Eigen/Eigen>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>

//using namespace std;

//remind
//input two empty vectors B, W
#define MU 0.1758
#define LAMBDA 0.7141
#define GAMMA 1
#define DELTA_TIME 1
#define MASS 100.0

void precompute(std::vector<Eigen::Vector3d> X,
                               std::vector<Eigen::Vector4i> T,
                               std::vector<Eigen::Matrix3d> &B,
                               std::vector<double> &W);

Eigen::Matrix3d compute_P(Eigen::Matrix3d F);

std::vector<Eigen::Vector3d> compute_F(std::vector<Eigen::Vector3d> def_X,
                                       std::vector<Eigen::Vector4i> T,
                                       std::vector<Eigen::Matrix3d> B,
                                       std::vector<double> W);


Eigen::Matrix3d compute_dP(Eigen::Matrix3d F, Eigen::Matrix3d dF);

std::vector<Eigen::Vector3d> compute_dF(std::vector<Eigen::Vector3d> def_X,
                                        std::vector<Eigen::Vector3d> dX,
                                        std::vector<Eigen::Vector4i> T,
                                        std::vector<Eigen::Matrix3d> B,
                                        std::vector<double> W);

std::vector<Eigen::Vector3d> update_XV(std::vector<Eigen::Vector3d> def_X,
                                        std::vector<Eigen::Vector3d> dX,
                                        std::vector<Eigen::Vector4i> T,
                                        std::vector<Eigen::Vector3d> V,
                                        std::vector<Eigen::Matrix3d> B,
                                        std::vector<double> W);