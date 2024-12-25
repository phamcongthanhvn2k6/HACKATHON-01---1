#include<stdio.h>
#include<math.h>

    int main(){
        int luachon, n;
        int trangthainhap = 0;
        int array[100];
        do {
            printf("MENU\n");
            printf("1. Nhap so phan tu va gia tri cho mang \n");
            printf("2. In ra gia tri cac phan tu trong mang \n");
            printf("3. Tim gia tri lon nhat va nho nhat \n");
            printf("4. In ra tong cua tat ca cac phan tu \n");
            printf("5. Them phan tu vao cuoi mang  \n");
            printf("6. Xoa phan tu tai vi tri cu the \n");
            printf("7. Sap Xep Mang theo thu tu giam dan \n");
            printf("8. Cho Nguoi Dung Nhap vao mot phan tu, KIem tra phan tu do co ton tai khong?\n");
            printf("9. In ra toan bo so nguyen to trong mang \n");
            printf("10. Sap xep mang theo thu tu tang dan \n");
            printf("11. Thoat chuong trinh \n");  
            printf("Lua chon cua ban la: ");
            scanf("%d", &luachon);
            
            switch(luachon){
                case 1: 
                printf("Hay Nhap so phan tu trong mang: \n");
                    scanf("%d", &n);
                    for(int i = 0; i < n; i++){
                        printf("Nhap vao phan tu thu %d: ", i + 1);
                        scanf("%d", &array[i]);
                    }
                    trangthainhap = 1;
                    break;
                    
                case 2:
                if(trangthainhap){
                    for(int i = 0; i < n; i++){
                        printf("Phan tu arr[%d]: %d\n", i, array[i]);
                    }
                }
                else{
                    printf("Ban Chua Nhap Phan Tu trong Mang! ");
                }
                break;
                
                case 3:
                if(trangthainhap){
                    int giatrilonnhat = array[0];
                    int giatrinhonhat = array[0];
                    for(int i = 0; i < n; i++){
                        if(array[i] < giatrinhonhat){
                            giatrinhonhat = array[i];
                        }
                        if(array[i] > giatrilonnhat){
                            giatrilonnhat = array[i];
                        }
                    }
                    printf("Gia tri Lon Nhat La: %d\n", giatrilonnhat);
                    printf("Gia tri Nho Nhat La: %d\n", giatrinhonhat);
                }
                else{
                    printf("Ban Chua Nhap Phan Tu trong Mang! ");
                }
                break;

                case 4:
                if(trangthainhap){
                    int tong = 0;
                    for(int i = 0; i < n; i++){
                        tong += array[i];
                    }
                    printf("Tong cua cac phan tu la: %d\n", tong);
                }
                else{
                    printf("Ban Chua Nhap Phan Tu trong Mang! ");
                }
                break;

                case 5:
                if(trangthainhap){
                    int giatri;
                    printf("Them Phan tu: ");
                    scanf("%d", &giatri);  
                    
                    
                    array[n] = giatri;
                    n++;  

                    printf("Da them phan tu %d vao cuoi mang.\n", giatri);
                }
                else{
                    printf("Ban Chua Nhap Phan Tu trong Mang! ");
                }
                break;

                case 6:
                if(trangthainhap){
                    int xoa;
                    printf("Xoa phan tu: \n");
                    printf("Nhap vi tri phan tu muon xoa (1 den %d): ", n);
                    scanf("%d", &xoa);

                    if(xoa < 1 || xoa > n) {
                        printf("Vi tri khong hop le. Vui long thu lai.\n");
                    } else {
                        for(int i = xoa - 1; i < n - 1; i++) {
                            array[i] = array[i + 1];
                        }
                        n--;
                    }
                } 
                else {
                    printf("Ban chua nhap mang, vui long nhap mang truoc! \n");          
                }
                break;
                
                case 7:
                if(trangthainhap){
                    int temp;
                    printf("Sap Xep mang theo thu tu giam dan:  \n");
                    for (int i = 0; i < n-1; i++) {
                        for (int j = 0; j < n-i-1; j++) {
                             if (array[j] < array[j+1]) {
                                    temp = array[j];
                                    array[j] = array[j+1];
                                    array[j+1] = temp;
                                    }
                                }
                            }
                    printf("Mang Sau Khi Duoc Sap Xep la: \n");
                    for(int i = 0; i < n; i++){
                        printf("Phan tu arr[%d]: %d\n", i, array[i]);
                        }
                    }
                else {
                    printf("Ban chua nhap mang, vui long nhap mang truoc! \n");          
                }
                break;
                
                case 8:
                if(trangthainhap){
                    int trangthaitimkiem = 0;
                    int timkiem;
                    printf("Hay Nhap Phan Tu Muon Tim Kiem: \n");
                    scanf("%d", &timkiem);

                    for(int i = 0; i < n; i++){
                        if(array[i] == timkiem){
                            trangthaitimkiem = 1;
                            printf("Da Tim Thay Phan Tu Tai Vi tri %d\n", i + 1);
                        }
                    }
                    
                    if(trangthaitimkiem){
                        printf("Phan Tu %d Co Trong Mang! ", timkiem);
                    } else {
                        printf("Phan tu %d Khong Co O Trong Mang!\n", timkiem);
                    }
                } else {
                    printf("Ban chua nhap mang, vui long nhap mang truoc! \n");          
                }
                break;
                
                case 9:
                if(trangthainhap){
                    int cosonguyento = 0;
                    printf("Cac phan tu trong mang la so nguyen to: ");
                    for (int i = 0; i < n; i++){
                        int trangthai = 1;
                        if(array[i] <= 1){
                            trangthai = 0;
                        }
                        for (int j = 2; j <= sqrt(array[i]); j++){
                            if(array[i] % j == 0){
                                trangthai = 0;
                                break;
                            }
                        }
                        if(trangthai){
                            cosonguyento = 1;
                            printf("%d\n", array[i]);
                        }
                    }
                    if(cosonguyento){
                        printf("Mang Co So Nguyen To!\n");
                    } else {
                        printf("Mang Khong Co So Nguyen To!\n");
                    }
                } else {
                    printf("Ban chua nhap mang, vui long nhap mang truoc! \n");          
                }
                break;
                    
                case 10:
                if(trangthainhap){
                    printf("Phan tu truoc khi duoc sap xep: \n");
                    for (int i = 0; i < n; i++){
                        printf("%d ", array[i]);
                    }
                    printf("\n");
        
                    for (int i = 0; i < n-1; i++){
                        int vitrinhonhat = i;
                        for (int j = i + 1; j < n; j++){
                            if(array[j] < array[vitrinhonhat]){
                                vitrinhonhat = j;
                            }
                        }
                        int bientam = array[vitrinhonhat];
                        array[vitrinhonhat] = array[i];
                        array[i] = bientam;
                    }
        
                    printf("Phan tu sau khi duoc sap xep: \n");
                    for (int i = 0; i < n; i++){
                        printf("%d ", array[i]);
                    }
                    printf("\n");
                } else {
                    printf("Ban chua nhap mang, vui long nhap mang truoc! \n");          
                }
                break;

                case 11: 
                    printf("Thoat chuong trinh.\n");
                    break;

                default: 
                    printf("Lua chon khong hop le. Vui long chon lai.\n"); 
                    break;      
            }
        } while(luachon != 11);
    
    return 0;
}
