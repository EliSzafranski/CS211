#include <iostream>
using namespace std; 

class Rat{
    private:
        int n; 
        int d; 

    public: 

    //Constructors 
    Rat(){
        n = 0; 
        d = 1; 
    }

    Rat(int i){
        n = i; 
        d = 1; 
    }

    Rat(int i, int j){
        n = i; 
        d = j; 
    }

    Rat simplify(Rat r){
        Rat t; 
        int factor;
        int a = r.n, b = r.d; 
        while (a % b != 0){
            factor = a % b; 
            a = b;
            b = factor; 
        }
        r.n = r.n / b; 
        r.d = r.d / b; 
        return Rat(r.n, r.d); 
    }
    //Getters and Setters
    int getNum(){
        return n; 
    }
    int getDen(){
        return d; 
    }
    void setNum(int i){
        n = i; 
    }
    void setDen(int i){
        d = i; 
    }

    
    /*
    //Arithmatic operators
    Rat operator+(Rat r){
        Rat t; 
        t.n = (n * r.d) + (d * r.n); 
        t.d = d * r.d; 
        return simplify(t); 
    }
    

    Rat operator-(Rat r){
        Rat t; 
        t.n = (n * r.d) - (d * r.n); 
        t.d = d * r.d; 
        return simplify(t); 
    } 

    Rat operator*(Rat r){
        Rat t; 
        t.n = n * r.n; 
        t.d = d * r.d; 
        return simplify(t); 
    }

    Rat operator/(Rat r){
        Rat t; 
        t.n = n * r.d; 
        t.d = d * r.n; 
        return simplify(t); 
    }
    */

    friend ostream& operator<<(ostream& cout, Rat r);
    friend istream& operator>>(istream& cin, Rat& r);
};

// Overloaded arithmatic opperators which can take integers and convert them to Rat's 
Rat operator+(Rat i, Rat r){
    Rat t; 
    t.setNum((i.getNum() * r.getDen()) + (i.getDen() * r.getNum())); 
    t.setDen(i.getDen() * r.getDen()); 
    return t.simplify(t); 
}

Rat operator-(Rat i, Rat r){
    Rat t; 
    t.setNum((i.getNum() * r.getDen()) - (i.getDen() * r.getNum()));
    t.setDen(i.getDen() * r.getDen()); 
    return t.simplify(t); 
}

Rat operator*(Rat i, Rat r){
    Rat t; 
    t.setNum(i.getNum() * r.getNum());
    t.setDen(i.getDen() * r.getDen());
    return t.simplify(t); 
}

Rat operator/(Rat i, Rat r){
    Rat t; 
    t.setNum(i.getNum() * r.getDen()); 
    t.setDen(i.getDen() * r.getNum()); 
    return t.simplify(t); 
}

// Overloaded iostream opperators 
ostream& operator<<(ostream& cout, Rat r){
    if(r.n < r.d){
        cout<<r.n<<" / "<<r.d<<endl;
        return cout;
    }
    else if (r.n > r.d){
        cout << r.n/r.d << " " << r.n % r.d << "/" << r.d;
        return cout; 
    }
    else{
        cout << 1; 
        return cout; 
    }
}

// Rat& has to be a reference so we can physically change r, otherwise it would create a copy (via pass-by-value) and then change the num and den of the copy
istream& operator>>(istream& cin, Rat& r){
    cin>>r.n>>r.d;
    return cin;
}

int main(){
    Rat x(1,2), y(2,3), z;
    z=x+y;
    cout<< z << endl;
    
    x.setNum(3); 
    y.setDen(2);
    z = x + y; 
    cout << z << endl; 

    Rat i(4,6), j(3,17), k; 
    k = i + j; 
    cout << k << endl;  

    cout << 5 * i << endl; 

    cout << "Enter a numerator and a denominator:";
    cin >> x; 
    cout << x << endl;

    z = x + 5; 
    cout<< z << endl; 

    Rat prac(4, 7), ans; 
    ans = 4 + prac; 
    cout << ans << endl; 

    return 0; 
}