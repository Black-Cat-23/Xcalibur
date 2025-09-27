# include <stdio.h>

#include <windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
    MessageBox(NULL, "Hello, World!", "My App", MB_OK);
    return 0;
}


int main (){
    int n;
    printf("Enter no of rows :");
    scanf("%d",&n);

    for( int i= 1; i<= n ; i++){
        for(int j=1 ;j<=i; j++){
            printf("* ");
        }
        printf("\n");
    }




return 0;
}