#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, m;
    scanf("%d:%d", &h, &m);
    if(m > 0) {
        h++;
    }
    if(h <= 12) {
        printf("Only %02d:%02d.  Too early to Dang.", h - 1, m);
    } else {
        for(int i = 0; i < h - 12; i++) {
            printf("Dang");
        }
    }
    return 0;
}