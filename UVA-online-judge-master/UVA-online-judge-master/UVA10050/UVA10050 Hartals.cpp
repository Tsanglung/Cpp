#include <iostream>
using namespace std;

int main()
{
    int T, Days, P, h[101]; // T: number of cases, N: number of days
                      // P: number of parties, h[i]: hartal parameter for party i
    cin >> T;//´Xµ§¸ê®Æ
    while (T--)
    {
        cin >> Days >> P;//¤é´Á //party¦¸¼Æ
        for (int i = 0; i < P; i++) cin >> h[i];//party¤é´Á
        int hartal = 0;
        for (int i = 1; i <= Days; i++) {
            if (i % 7 == 6) {           // ¸õ¹L¬P´Á¤­©M¬P´Á¤»¡A¥u­pºâ©P¤é¦Ü©P¥|
                i++; continue;
            }
            for (int j = 0; j < P; j++) {
                if (i % h[j] == 0) {
                    hartal++;//­pºâµ²ªG
                    break;
                }
            }
        }
        cout << hartal << endl;
    }
    return 0;
}
