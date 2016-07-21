/*
C file to compute the band-diagonal part of the inverse of a
banded matrix

Luca Citi
July 2013
*/

#include "bandinverse.h"


char syntax[] =
"bandinverse computes the band-diagonal part of the inverse of a banded\n"
"matrix.\n\n"
"Syntax:\n"
"\n"
"P = bandinverse(U)\n"
"where:\n"
" - matrix U is a full matrix containing as rows, the diagonals of the\n"
"        cholesky factorization of a banded matrix.\n\n"
"Example:\n"
"  given a 3-diagonal 5x5 matrix A, with U = chol(A) and\n"
"  with Ud = [  0    U(1,2), U(2,3), U(3,4), U(4,5);\n"
"             U(1,1) U(2,2), U(3,3), U(4,4), U(5,5)];\n"
"bandinverse(Ud)\n"
"will produce:\n"
"  [  0     P(1,2)  P(2,3)  P(3,4)  P(4,5)\n"
"   P(1,1)  P(2,2)  P(3,3)  P(4,4)  P(5,5)\n"
"   P(2,1)  P(3,2)  P(4,3)  P(5,4)    0   ]\n"
"where P*(U'*U) = eye()\n";


void bandinverse(double *P, double *U, int M, int N)
{
    int i, j, l;
    int S = 2 * M - 1;
    double *pPjj = P + (N-1)*S + M-1;
    for (j = N; j > 0; --j, pPjj-=S) {
        double *pUii = U + j * M - 1;
        double *pPij = pPjj;
        double *pPji = pPjj;
        for (i = j; i > 0 && i+M > j; --i, pUii-=M, pPji-=S-1, --pPij) {
            double *pU = pUii;
            double *pP = pPij;
            double v = (i == j) ? (1./(*pUii)) : 0.;
            for (l = 1; l < M && l <= N-i; ++l) {
                pU += M - 1;
                v -= *(++pP) * (*pU);
            }
            v /= (*pUii);
            *pPij = v;
            *pPji = v;
        }
    }
}
