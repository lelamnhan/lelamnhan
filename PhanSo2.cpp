#include <iostream>
using namespace std;

int UCLN(int a,int b){
    if (a%b==0)
        return b;
    else
        return UCLN(b,a%b);
}
class PhanSo{
    private:
        int tu,mau;
        void rutGon(){
            int uc = UCLN(tu,mau);
            tu=tu/uc;
            mau=mau/uc;
        }
    public:
        void ganPS(int ,int);
        void inPS();
        PhanSo cong(PhanSo);
        PhanSo tru(PhanSo);
        PhanSo nhan(PhanSo);
        PhanSo chia(PhanSo);
};
void PhanSo::ganPS(int t,int m){
    tu = t;
    mau = m;
}
void PhanSo::inPS(){
    cout<<tu<<"/"<<mau<<endl;
}

PhanSo PhanSo::cong(PhanSo ps2){
    PhanSo kq;
    kq.tu = tu*ps2.mau+mau*ps2.tu;
    kq.mau = mau*ps2.mau;
    kq.rutGon();
    return kq;
}
PhanSo PhanSo::tru(PhanSo ps2){
    PhanSo kq;
    kq.tu = tu*ps2.mau-mau*ps2.tu;
    kq.mau = mau*ps2.mau;
    kq.rutGon();
    return kq;
}
PhanSo PhanSo::nhan(PhanSo ps2){
    PhanSo kq;
    kq.tu = tu*ps2.tu;
    kq.mau = mau*ps2.mau;
    kq.rutGon();
    return kq;
}
PhanSo PhanSo::chia(PhanSo ps2){
    PhanSo kq;
    kq.tu = tu*ps2.mau;
    kq.mau = mau*ps2.tu;
    kq.rutGon();
    return kq;
}
int main(){
    PhanSo ps1,ps2;
    ps1.ganPS(5,2);
    ps2.ganPS(10,5);
    cout<<"Phan so 1: ";
    ps1.inPS();
    cout<<"Phan so 2: ";
    ps2.inPS();

    PhanSo ps3,ps4,ps5,ps6;
    ps3 = ps1.cong(ps2);
    ps4 = ps1.tru(ps2);
    ps5 = ps1.nhan(ps2);
    ps6 = ps1.chia(ps2);
    cout<<"PS1 + PS2 = ";ps3.inPS();
    cout<<"PS1 - PS2 = ";ps4.inPS();
    cout<<"PS1 * PS2 = ";ps5.inPS();
    cout<<"PS1 / PS2 = ";ps6.inPS();
    return 0;
}