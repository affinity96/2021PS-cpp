#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
double AX, AY, BX, BY, CX, CY, DX, DY;
double distance(double ax, double ay, double bx, double by){
    double dis = pow(ax-bx,2) + pow(ay-by,2);
    dis = sqrt(dis);
    return dis;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> AX >> AY >> BX >> BY >> CX >> CY >> DX >> DY;
    double l = 0;
    double r = 100;
    double p, q;
    double ans = 2*10e4;

    while(r - l >= 1e-6){
        p = (l*2+r)/3;
        q = (l+2*r)/3;

        double minho_px = (AX + (BX-AX)*(p/100));
     
        double minho_py = (AY + (BY-AY)*(p/100));
        double gangho_px = (CX + (DX-CX)*(p/100));
        double gangho_py = (CY + (DY-CY)*(p/100));
        double minho_qx = (AX + (BX-AX)*(q/100));
        double minho_qy = (AY + (BY-AY)*(q/100));
        double gangho_qx = (CX + (DX-CX)*(q/100));
        double gangho_qy = (CY + (DY-CY)*(q/100));

        double p_dis = distance(minho_px, minho_py, gangho_px, gangho_py);
        double q_dis = distance(minho_qx, minho_qy, gangho_qx, gangho_qy);

        ans = min({ans, p_dis, q_dis});

        if(p_dis >= q_dis){
            l = p;
        }else{
            r = q;
        }
    }
    cout.setf(ios::fixed);
    cout.precision(10);
    cout << ans;
}