#include <stdio.h>
#include <string.h>

struct SanPham{
	int maSP;
	char tenSP[50];
	float giaNhap;
	float giaBan;
	int soLuong;
};

void addProd(struct SanPham sp[], int *n );
void show(struct  SanPham sp[], int n);
void addItem(struct SanPham sp[], int *n, float *rev);
void updateItem(struct SanPham sp[], int n);
void sort(struct SanPham sp[], int n );
void search(struct SanPham sp[], int n );
void sell(struct SanPham sp[], int n, float *rev );
void revenue( float rev );

int main(){
	struct SanPham sp[100];
	int chose;
	int check = -1;
	int n = 0;
	float rev = 0;
	
	do{
		printf("--------MENU--------\n");
		printf("1. Nhap so luong va thong tin san pham\n");
		printf("2. Hien thi danh sach san pham\n ");
		printf("3. Nhap san pham\n ");
		printf("4. Cap nhat thong tin san pham\n ");
		printf("5. Sap xep san pham theo gia(tang/giam)\n ");
		printf("6. Tim kiem san pham theo ten\n ");
		printf("7. Ban san pham( co the nhap so luong can ban)\n ");
		printf("8. Doanh thu hien tai\n ");
		printf("9. Thoat\n ");
		printf(" Lua chon cua ban: ");
		scanf("%d", &chose );
		fflush(stdin);
		switch( chose){
			case 1:
				check = 1;
				addProd(sp, &n );
				break;
			case 2:
				if ( check == -1 ){
					printf("Mang rong, vui long su dung chuc nang 1 ");
				}else{
					show(sp, n);
				}
				break;
			case 3:
				if ( check == -1 ){
					printf("Mang rong, vui long su dung chuc nang 1 ");
				}else{
					addItem(sp, &n, &rev);
				}
				break;
			case 4:
				if ( check == -1 ){
					printf("Mang rong, vui long su dung chuc nang 1 ");
				}else{
					updateItem(sp, n);
				}
				break;
			case 5:
				if ( check == -1 ){
					printf("\nMang rong, vui long su dung chuc nang 1! ");
				}else{
					sort(sp, n);
				}
				break;
			case 6:
				if ( check == -1 ){
					printf("Mang rong, vui long su dung chuc nang 1 ");
				}else{
					search(sp, n);
				}
				break;
			case 7:
				if ( check == -1 ){
					printf("\nMang rong, vui long su dung chuc nang 1! ");
				}else{
					sell(sp, n, &rev);
				}
				break;
			case 8:
				revenue( rev);
				break;
			case 9:
				printf("\nBan chon thoat! ");
				break;
		}
	}while( chose != 9);

	return 0;
}

void addProd(struct SanPham sp[], int *n ){
	printf("Nhap so luong san pham: ");
	scanf("%d", n);
	fflush(stdin);
	
	for ( int i = 0; i< *n ; i++){
		sp[i].maSP = i+1 ;
		printf("Nhap thong tin san pham thu: %d\n", i+1);
		fflush(stdin);
		printf("Nhap ten san pham: ");
		fgets(sp[i].tenSP , 50, stdin);
		sp[i].tenSP[strlen(sp[i].tenSP) -1] = '\0' ;
		
		printf("Gia nhap: ");
		scanf("%f", &sp[i].giaNhap);
		printf("Gia ban: ");
		scanf("%f", &sp[i].giaBan);
		printf("So luong: ");
		scanf("%d", &sp[i].soLuong);
	}
}

void show(struct SanPham sp[], int n){
	printf("Danh sach san pham: ");
	for ( int i = 0; i<n ; i++){
		printf("%d\n %s\n", sp[i].maSP, sp[i].tenSP );
		printf("Gia nhap: %.2f\n", sp[i].giaNhap);
		printf("Gia ban: %.2f\n", sp[i].giaBan);
		printf("So luong: %d\n", sp[i].soLuong);
	}
}

void addItem(struct SanPham sp[], int *n, float *rev ){
	char input[50];
	int check = 0;
	
	printf("Nhap thong tin san pham can them\n " );
	printf("Nhap ten san pham:\n ");
	fgets(input, 50, stdin);
	input[strlen(input) -1] = '\0' ;
	
	for ( int i =0; i< *n; i++){
		if (  strcmp(sp[i].tenSP, input) == 0 ){
			check = 1;
			sp[i].soLuong += 1;
			*rev -= sp[i].giaNhap  ;
			break;
		}
	}
	
	if ( check == 0 ){
		strcpy(sp[*n].tenSP, input );
		
		sp[*n].maSP = (*n)+1;
		printf("Gia nhap: ");
		scanf("%f", &sp[*n].giaNhap);
		printf("Gia ban: ");
		scanf("%f", &sp[*n].giaBan);
		printf("So luong: ");
		scanf("%d", &sp[*n].soLuong);
		
		*rev -= sp[*n].giaNhap ;
		(*n)++ ;
	}
	
	printf("Ket qua them san pham:\n ");
	for ( int i = 0; i< *n ; i++){
		printf("%d\n %s\n", sp[i].maSP, sp[i].tenSP );
		printf("Gia nhap: %.2f\n", sp[i].giaNhap);
		printf("Gia ban: %.2f\n", sp[i].giaBan);
		printf("So luong: %d\n", sp[i].soLuong);
	}
}

void updateItem(struct SanPham sp[], int n){
	int index, input, check = -1;
	printf("Nhap ma san pham muon sua: ");
	scanf("%d", &input);
	fflush(stdin);
	
	for ( int i =0; i< n; i++){
		if (sp[i].maSP == input ) {
			check = 1;
			index = i;
			break;
		}
	}
	
	if ( check == -1 ){
		printf("Khong co ma san pham can sua\n");
	}else{
		printf("Nhap ten san pham: ");
		fgets(sp[index].tenSP , 50, stdin);
		sp[index].tenSP[strlen(sp[index].tenSP) -1] = '\0' ;
		
		printf("Gia nhap: ");
		scanf("%f", &sp[index].giaNhap);
		printf("Gia ban: ");
		scanf("%f", &sp[index].giaBan);
		printf("So luong: ");
		scanf("%d", &sp[index].soLuong);
		fflush(stdin);
			
		printf("\nDanh sach ket qua: ");
		for ( int i = 0; i< n ; i++){
			printf("%d\n %s\n", sp[i].maSP, sp[i].tenSP );
			printf("Gia nhap: %.2f\n",sp[i].giaNhap);
			printf("Gia ban: %.2f\n",sp[i].giaBan);
			printf("So luong: %d\n",sp[i].soLuong);
		}
	}
}

void sort(struct SanPham sp[], int n ){
	char chose;
	do{
		printf("a. Gia tang dan\n ");
		printf("b. Gia giam dan\n ");
		printf(" Lua chon cua ban:\n ");
		scanf("%c", &chose );
		fflush(stdin);
	}while( chose != 'a' && chose != 'b' );
	fflush(stdin);
	
	if ( chose == 'a' ){
		for( int i = 0; i< n; i++){
			for ( int j = 0; j< n-1-i; j++){
				if (sp[j].giaBan > sp[j+1].giaBan  ){
					struct SanPham temp = sp[j];
	                sp[j] = sp[j+1];
	                sp[j+1] = temp;
				}
			}
		}
	}else{
		for( int i = 0; i< n; i++){
			for ( int j = 0; j< n-1-i; j++){
				if (sp[j].giaBan < sp[j+1].giaBan  ){
					struct SanPham temp = sp[j];
	                sp[j] = sp[j+1];
	                sp[j+1] = temp;
				}
			}
		}
	}
	
	printf("Danh sach sap xep: ");
	for ( int i = 0; i< n ; i++){
		printf("%d\n %s\n", sp[i].maSP, sp[i].tenSP );
		printf("Gia nhap: %.2f\n",sp[i].giaNhap);
		printf("Gia ban: %.2f\n",sp[i].giaBan);
		printf("So luong: %d\n",sp[i].soLuong);
	}
}

void search(struct SanPham sp[], int n ){
	char input[50];
	int count = 0;
	
	fflush(stdin);
	printf("Nhap ten san pham can tim: ");
	fgets( input, 50, stdin);
	input[strlen(input) -1] = '\0';
	
	for ( int i = 0; i< n; i++){
		if ( strstr(sp[i].tenSP, input) != NULL ){
			count = 1;
			printf("Ket qua tim kiem:\n ");
			printf("%d\n %s\n", sp[i].maSP, sp[i].tenSP );
			printf("Gia nhap: %.2f\n", sp[i].giaNhap);
			printf("Gia ban: %.2f\n", sp[i].giaBan);
			printf("So luong: %d\n", sp[i].soLuong);
		}
	}

	if ( count == 0 ) printf("Khong tim thay san pham");
}

void sell(struct SanPham sp[], int n, float *rev ){
	int id, check = 0, index, qty;
	printf("Nhap ma san pham can ban: ");
	scanf("%d", &id);
	
	for ( int i = 0; i<n ; i++){
		if (sp[i].maSP == id ) {
			check = 1;
			index = i;
			break;
		}
	}
	
	if ( check == 0){
		printf("ID k ton tai");
	}else{
		printf("Nhap so luong ban: ");
		scanf("%d", &qty);
		
		if (sp[index].soLuong == 0 ){
			printf("San pham het hang");
		}else if (sp[index].soLuong < qty ){
			printf("San pham khong du so luong!");
		}else{
			sp[index].soLuong -= qty;
			*rev += sp[index].giaBan * qty ;
			
			printf("Ket qua ban san pham: ");
			for ( int i = 0; i< n ; i++){
				printf("%d\n %s\n", sp[i].maSP,sp[i].tenSP );
				printf("Gia nhap: %.2f\n",sp[i].giaNhap);
				printf("Gia ban: %.2f\n",sp[i].giaBan);
				printf("So luong: %d\n",sp[i].soLuong);
			}
		}
	}
}

void revenue( float rev ){
	printf("Doanh thu hien tai: %.2f\n", rev);
}

