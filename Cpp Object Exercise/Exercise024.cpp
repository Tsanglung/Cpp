/*
密文解碼:將所有的英文字母做移位(只做大寫處理)
A->D，B->E.....X->A、Y->B、Z->C
*/
#include<iostream>
using namespace std;

class Encryption{
    friend istream& operator>>(istream& is,Encryption& E){cout << "輸入明文 : ";is >> E.plaintext; return is;}
    friend ostream& operator<<(ostream& os, Encryption& E){os << "密文 : " << E.plaintext << endl; return os;}
private:
    string plaintext;//明文
public:
    Encryption() {}
    void Encode(){
        for(int i = 0; i < plaintext.size(); i++){ //ASCII碼運算
            if(this->plaintext[i] >= 65 && this->plaintext[i] < 88) this->plaintext[i] += 3;
            else this->plaintext[i] -= 23;
        }
    }
};

class Decryption{
    friend istream& operator>>(istream& is,Decryption& D){cout << "輸入密文 : "; is >> D.ciphertext; return is;}
    friend ostream& operator<<(ostream& os, Decryption& D){os << "明文 : " << D.ciphertext << endl; return os;}
private:
    string ciphertext;//密文
public:
    Decryption(){}
    void Decode(){
        for(int i = 0; i < ciphertext.size(); i++){ //ASCII碼運算
            if(this->ciphertext[i] > 67 && this->ciphertext[i] <= 90) this->ciphertext[i] -= 3;
            else this->ciphertext[i] += 23;
        }
    }
};

int main(){
    Encryption E;
    cin >> E;
    E.Encode();
    cout << E;
    Decryption D;
    cin >> D;
    D.Decode();
    cout << D << endl;
}