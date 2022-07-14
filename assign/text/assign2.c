#include<time.h>
#include<stdio.h>
#include<stdlib.h>

long text(int num){
    long i,a[20];
    srand(time(0));

    for ( i = 0; i < 20; ++i) {
        a[i] = rand() +2746815412126722155;
    }
    return a[num];
//    2746815410821/962036
//    return result;
}

int main()
{
//    time_t tnow;
//    tnow = time(0);      // 获取当前时间
//
//    printf("tnow=%lu\n", tnow);   // 输出整数表示的时间
//    long result;
//    for (int i = 0; i < 10; ++i) {
//        srand((unsigned)time( NULL ) );
//         result = rand() + 2746815410821962036;
////        2746815412126722155
//        printf("%ld\n", result);
//    }
    long result = text();

}
