#include <iostream>
#include <cmath>
#define endl "\n"

using ll = long long;
using namespace std;

int ucln(int a, int b)
{
    a = abs(a);
    b = abs(b);
    if (b == 0)
        return a + b;

    return ucln(b, a % b);
}

class PhanSo
{
private:
    int tu;
    int mau;

public:
    PhanSo(int tu, int mau) : tu(tu)
    {
        if (mau == 0)
        {
            throw "Mau bang 0, vui long nhap lai";
        }
        this->rutGon();
        this->mau = mau;
    }
    PhanSo() : tu(0), mau(1) {}
    PhanSo(int tu) : tu(tu), mau(1) {}
    PhanSo(const PhanSo &ps)
    {
        this->tu = ps.tu;
        this->mau = ps.mau;
    }
    ~PhanSo() {}

    void rutGon()
    {
        int gcd = ucln(this->tu, this->mau);
        if (gcd != 0)
        {
            this->tu /= gcd;
            this->mau /= gcd;
        }
        else
            throw "khong the rut gon";

        if (mau < 0)
        {
            tu = -tu;
            mau = -mau;
        }
    }

    // +
    friend PhanSo operator+(const PhanSo &, const PhanSo &);

    // -
    friend PhanSo operator-(const PhanSo &, const PhanSo &);

    // *
    friend PhanSo operator*(const PhanSo &, const PhanSo &);

    // /
    friend PhanSo operator/(const PhanSo &, const PhanSo &);

    // >
    bool operator>(const PhanSo &) const;

    // <
    bool operator<(const PhanSo &) const;

    // >=
    bool operator>=(const PhanSo &) const;

    // <=
    bool operator<=(const PhanSo &) const;

    // ==
    bool operator==(const PhanSo &) const;

    // !=
    bool operator!=(const PhanSo &) const;

    // >> (extraction operator)
    friend istream &operator>>(istream &, PhanSo &);

    // << (insertion operator)
    friend ostream &operator<<(ostream &, const PhanSo &);

    // = (assignment)
    PhanSo &operator=(const PhanSo &ps1);

    // +=
    PhanSo &operator+=(const PhanSo &);

    // -=
    PhanSo &operator-=(const PhanSo &);

    // *=
    PhanSo &operator*=(const PhanSo &);

    // /=
    PhanSo &operator/=(const PhanSo &);

    // ++ (prefix)
    PhanSo &operator++();

    // ++(postfix)
    PhanSo operator++(int);
};

PhanSo &PhanSo::operator++()
{
    (*this) += PhanSo(1);
    return *this;
}
PhanSo PhanSo::operator++(int) // ko dung &
{
    PhanSo tmp = *this;

    ++(*this);
    return tmp;
}

PhanSo &PhanSo::operator/=(const PhanSo &ps)
{
    *this = *this / ps;
    this->rutGon();
    return *this;
}

PhanSo &PhanSo::operator*=(const PhanSo &ps)
{
    *this = *this * ps;
    this->rutGon();
    return *this;
}

PhanSo &PhanSo::operator-=(const PhanSo &ps)
{
    *this = *this - ps;
    this->rutGon();
    return *this;
}

PhanSo &PhanSo::operator+=(const PhanSo &ps)
{
    *this = *this + ps;
    this->rutGon();
    return *this;
}

PhanSo &PhanSo::operator=(const PhanSo &ps)
{
    this->tu = ps.tu;
    this->mau = ps.mau;

    return *this;
}

bool PhanSo::operator!=(const PhanSo &ps) const
{
    return (1LL * this->tu * ps.mau) != (1LL * this->mau * ps.tu);
}

bool PhanSo::operator==(const PhanSo &ps) const
{
    return (1LL * this->tu * ps.mau) == (1LL * this->mau * ps.tu);
}

ostream &operator<<(ostream &os, const PhanSo &ps)
{
    os << ps.tu << "/" << ps.mau;
    return os;
}

istream &operator>>(istream &is, PhanSo &ps)
{
    is >> ps.tu;
    is >> ps.mau;
    ps.rutGon();
    return is;
}

bool PhanSo::operator>(const PhanSo &ps) const
{
    return (1LL * this->tu * ps.mau) > (1LL * this->mau * ps.tu);
}

bool PhanSo::operator<(const PhanSo &ps) const
{
    return (1LL * this->tu * ps.mau) < (1LL * this->mau * ps.tu);
}

bool PhanSo::operator<=(const PhanSo &ps) const
{
    return (1LL * this->tu * ps.mau) <= (1LL * this->mau * ps.tu);
}

bool PhanSo::operator>=(const PhanSo &ps) const
{
    return (1LL * this->tu * ps.mau) >= (1LL * this->mau * ps.tu);
}

PhanSo operator+(const PhanSo &ps1, const PhanSo &ps2)
{
    PhanSo res;
    res.tu = ps1.tu * ps2.mau + ps1.mau * ps2.tu;
    res.mau = ps1.mau * ps2.mau;

    res.rutGon();

    return res;
}

PhanSo operator-(const PhanSo &ps1, const PhanSo &ps2)
{
    PhanSo res;
    res.tu = ps1.tu * ps2.mau - ps2.tu * ps1.mau;
    res.mau = ps1.mau * ps2.mau;

    res.rutGon();

    return res;
}

PhanSo operator*(const PhanSo &ps1, const PhanSo &ps2)
{
    PhanSo res;
    res.tu = ps1.tu * ps2.tu;
    res.mau = ps1.mau * ps2.mau;

    res.rutGon();
    return res;
}

PhanSo operator/(const PhanSo &ps1, const PhanSo &ps2)
{
    PhanSo res;
    res.tu = ps1.tu * ps2.mau;
    res.mau = ps1.mau * ps2.tu;
    res.rutGon();
    return res;
}