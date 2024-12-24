#include <stdio.h>
#include <string.h>

struct Book{
    int id;
    char name[50];
    char author[50];
    char category[50];
    float price;
};

void inputBooks(struct Book books[], int *n);

void displayBooks(struct Book books[], int n); 

int findBook(struct Book books[], int n, int id); 

void addBook(struct Book books[], int *n, int position); 

void deleteBook(struct Book books[], int *n, int id); 

void updateBook(struct Book books[], int n, int id); 

void sortBooks(struct Book books[], int n, int ascending); 

void searchBook(struct Book books[], int n, char *name); 
int main() {
    struct Book books[100] = {
        {1, "Toi thay hoa vang tren co xanh", "Nguyen Nhat Anh", "Van hoc", 1200},
        {2, "Nha gia kim", "Paulo Coelho", "Triet hoc", 14000},
        {3, "Duc nhan tam", "Dale Carnegie", "Ky nang song", 15000},
        {4, "Harry Potter", "J.K. Rowling", "Fantasy", 200000},
        {5, "Hat giong tam hon", "Nguyen Van Phuoc", "Tam ly", 80000}
    };
    int n = 5;
    int chose;
    int position;
    int id;
    int order;
    char name[50];
    do{
        printf("--------MENU--------\n");
		printf(" 1. Nhap so luong va thon tin sach\n ");
		printf("2. Hien thi thonh tin sach\n ");
		printf("3. Them sach vao vi tri\n ");
		printf("4. Xoa sach theo ma sach\n ");
		printf("5. Cap nhat thong tin sach theo ma sach\n ");
		printf("6. Sap xep sach theo gia(tang/giam)\n ");
		printf("7. Tim kiem sach theo ten sach\n ");
		printf(" Lua chon cua ban: ");
    	scanf("%d",&chose);
    	fflush(stdin);
        switch (chose){
            case 1: 
                inputBooks(books, &n);
                break;
            case 2:
                displayBooks(books, n);
                break;
            case 3: 
                printf("Nhap vi tri muon them: ");
                scanf("%d", &position);
                addBook(books, &n, position);
                break;
            case 4: 
                printf("Nhap ma sach muon xoa: ");
                scanf("%d", &id);
                deleteBook(books, &n, id);
                break;
            case 5: 
                printf("Nhap ma sach muon cap nhat: ");
                scanf("%d", &id);
                updateBook(books, n, id);
                break;
            case 6: 
                printf("Sap xep theo gia (1: tang, 0: giam): ");
                scanf("%d", &order);
                sortBooks(books, n, order);
                break;
            case 7: 
                printf("Nhap ten sach muon tim: ");
                getchar();
                fgets(name, 50, stdin);
                name[strcspn(name, "\n")] = '\0';
                searchBook(books, n, name);
                break;
            case 8:
                printf("Thoat chuong trinh\n");
                break;
        }
    } while (chose != 8);

    return 0;
}
void inputBooks(struct Book books[], int *n){
    int newBooks;
    printf("Nhap so luong sach: ");
    scanf("%d", &newBooks);
    getchar();
    for (int i = 0; i < newBooks; i++){
        printf("Nhap thong tin sach %d:\n", i + 1);
        printf("ID: "); 
        scanf("%d", &books[*n].id);
        getchar();
        printf("Ten sach: ");
        fgets(books[*n].name, 50, stdin);
        books[*n].name[strcspn(books[*n].name, "\n")] = '\0';
        printf("Tac gia: ");
        fgets(books[*n].author, 50, stdin);
        books[*n].author[strcspn(books[*n].author, "\n")] = '\0';
        printf("The loai: ");
        fgets(books[*n].category, 50, stdin);
        books[*n].category[strcspn(books[*n].category, "\n")] = '\0';
        printf("Gia tien: ");
        scanf("%f", &books[*n].price);
        (*n)++;
    }
}

void displayBooks(struct Book books[], int n){
    printf("\nDanh sach sach:\n");
    for (int i = 0; i < n; i++) {
        printf("ID: %d\nTen: %s\nTac gia: %s\nThe loai: %s\nGia: %.3f\n",
               books[i].id, books[i].name, books[i].author, books[i].category, books[i].price);
    }
}

int findBook(struct Book books[], int n, int id){
    for (int i = 0; i < n; i++) {
        if (books[i].id == id) return i;
    }
    return -1;
}

void addBook(struct Book books[], int *n, int position){
    if (position < 0 || position > *n) {
        printf("Vi tri khong hop le\n");
        return;
    }
    struct Book newBook;
    printf("Nhap thong tin sach:\n");
    printf("ID: "); 
    scanf("%d", &newBook.id);
    getchar(); 
    printf("Ten sach: "); 
    fgets(newBook.name, 50, stdin); 
    newBook.name[strcspn(newBook.name, "\n")] = '\0';
    printf("Tac gia: "); 
    fgets(newBook.author, 50, stdin); 
    newBook.author[strcspn(newBook.author, "\n")] = '\0';
    printf("The loai: "); 
    fgets(newBook.category, 50, stdin); 
    newBook.category[strcspn(newBook.category, "\n")] = '\0';
    printf("Gia tien: "); 
    scanf("%f", &newBook.price);

    for (int i = *n; i > position; i--){
        books[i] = books[i - 1];
    }
    books[position] = newBook;
    (*n)++;
}

void deleteBook(struct Book books[], int *n, int id){
    int index = findBook(books, *n, id);
    if (index == -1){
        printf("Khong tim thay sach voi ID %d\n", id);
        return;
    }
    for (int i = index; i < *n - 1; i++){
        books[i] = books[i + 1];
    }
    (*n)--;
    printf("Da xoa sach co ID %d.\n", id);
}

void updateBook(struct Book books[], int n, int id) {
    int index = findBook(books, n, id);
    if (index == -1){
        printf("Khong tim thay sach voi ID %d\n", id);
        return;
    }
    printf("Cap nhat thong tin sach:\n");
    printf("Ten sach: "); 
    getchar(); 
    fgets(books[index].name, 50, stdin); 
    books[index].name[strcspn(books[index].name, "\n")] = '\0';
    printf("Tac gia: "); 
    fgets(books[index].author, 50, stdin);
    books[index].author[strcspn(books[index].author, "\n")] = '\0';
    printf("The loai: "); 
    fgets(books[index].category, 50, stdin); 
    books[index].category[strcspn(books[index].category, "\n")] = '\0';
    printf("Gia tien: "); 
    scanf("%f", &books[index].price);
    printf("Thong tin sach da duoc cap nhat\n");
}

void sortBooks(struct Book books[], int n, int ascending){
    for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++){
            if ((ascending && books[i].price > books[j].price) || (ascending && books[i].price < books[j].price)==0){
                struct Book temp = books[i];
                books[i] = books[j];
                books[j] = temp;
            }
        }
    }
    printf("Sach da duoc sap xep\n");
}

void searchBook(struct Book books[], int n, char *name){
    printf("Ket qua tim kiem:\n");
    for (int i = 0; i < n; i++){
        if (strstr(books[i].name, name)){
            printf("ID: %d\nTen: %s\nTac gia: %s\nThe loai: %s\nGia: %.3f\n",
                   books[i].id, books[i].name, books[i].author, books[i].category, books[i].price);
        }
    }
}

