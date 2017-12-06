FastMat library is a matrix library that uses C++11 features for creating better interface on linear algebra computations in C++.
Distinct features of this library there is a calculation buffer for fixed size vectors so that there would be no intermediate memory allocation for calculations.
Also it uses threads that could divide computation into multiple cores.
It also contains few distributions that could be extended later
MKL support is disabled due to similar performance measurements

Warning : This library works on square matrices which is suitable and efficient for covariances. It is not yet for general purpose linear algebra
