#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define maxsize 100

typedef struct {
    char ISBN[20];
    char name[50];
    float price;
} Book;

typedef struct {
    Book data[maxsize];
    int length;
} BookList;

void InitBook(BookList *L){
    L->length = 0; 
}

// 查找
int FindBook(BookList L, char x[]){ 
    system("cls"); 
    for(int i = 0; i < L.length; i++){
        if(strcmp(L.data[i].ISBN, x) == 0 || strcmp(L.data[i].name, x) == 0) 
            return i; 
        }
    return -1; 
}

//int FindBook(BookList L){
//	system("cls");
//	char x[50];
//    printf("请输入图书的ISBN或名称：");
//    scanf("%s", x);
//    
//    int target = -1;
//    for(int i = 0; i < L.length; i++){
//		if(strcmp(L.data[i].ISBN, x) == 0 || strcmp(L.data[i].name, x) == 0){
//			target = i;
//			break;
//		}
//	}
//    if (target == -1)
//        printf("404 not found!\n");
//    else
//        printf("位置序号:%d\t ISBN:%s\t 名称:%s\t 价格:%.2f\t\n",
//            target + 1, 
//			L.data[target].ISBN, 
//			L.data[target].name, 
//			L.data[target].price);
//	return target;
//}
 
// 插入 
int InsertBook(BookList *L){
    system("cls");
    if(L->length >= maxsize){
        printf("库存已满！\n");
        return -1;
    }
    
    Book i;
    
    while(1){
        int flag = 0;
        printf("请输入图书ISBN：");
        scanf("%s", i.ISBN);
        for(int j = 0; j < L->length; j++){
            if(strcmp(L->data[j].ISBN, i.ISBN) == 0){
                printf("该ISBN已存在，请重试。\n");
                getchar(); getchar();system("cls");
                flag = 1;
                break;
            }
        }
        if(flag == 0) break;
    }
    
    printf("输入图书名称：");
    scanf("%s", i.name);
    printf("输入图书价格：");
    scanf("%f", &i.price);
    L->data[L->length++] = i;
    printf("添加成功！\n"); 
    printf("按任意键继续...");
    getchar(); getchar();system("cls");
    return 0;
}

// 删除
void DeleteBook(BookList *L){
    system("cls");
    char x[50];
    printf("请输入要删除的图书ISBN或名称：");
    scanf("%s", x);
    
    int target = FindBook(*L, x);
    if(target == -1){
        printf("未找到该图书！\n");
        getchar(); getchar();system("cls");
        return;
    }
    
    for(int i = target; i < L->length; i++)
        L->data[i] = L->data[i+1]; 
    L->length--;
    printf("删除完成。\n");
    printf("\n按任意键继续...");
    getchar(); getchar();system("cls");
}

// 修改价格 
void ModifyBook(BookList *L){
    system("cls");
    char x[20];
    printf("请输入要修改的图书ISBN或名称：");
    scanf("%s", x);
    
    int target = FindBook(*L, x);
    if(target == -1){
        printf("未找到该图书！\n");
        getchar(); getchar();system("cls");
        return;
    }
    
    float newPrice;
    printf("请输入新价格：");
    scanf("%f", &newPrice);
    L->data[target].price = newPrice;
    printf("修改成功！\n");
    printf("\n按任意键继续...");
    getchar(); getchar();system("cls");
}

// 排序 
void SortBooks(BookList *L){
    system("cls");
    int i, j;
    for(i = 0; i < L->length-1; i++){
        for(j = 0; j < L->length-1; j++){
            if(L->data[j].price > L->data[j+1].price){
                Book t = L->data[j];
                L->data[j] = L->data[j+1]; 
                L->data[j+1] = t; 
            }
        }
    }
    printf("排序完成。\n");
    printf("\n按任意键继续...");
    getchar(); getchar();system("cls");
}

// 统计 
void CountBook(BookList *L){
    system("cls");
    printf("图书总数: %d\n", L->length);
    printf("\n按任意键继续...");
    getchar(); getchar(); system("cls");
}

// 显示
void DisplayBooks(BookList L){
    system("cls");
    printf("\n%-15s %-20s %-10s\n", "ISBN", "name", "price");
    printf("--------------------------------------------------\n");
    
    for (int i = 0; i < L.length; i++) {
        printf("%-15s %-20s %.2f\n",
               L.data[i].ISBN,
               L.data[i].name,
               L.data[i].price);
    }
    printf("\n按任意键继续...");
    getchar(); getchar();system("cls");
} 

////////////////////////////////////////////////////////////////
// 读取 
void LoadFile(BookList *L, const char *filename) {
    FILE *fp = fopen(filename, "r");   
    if (!fp) {
        printf("无法打开文件，请检查文件是否存在或路径是否正确\n");
        return;  
    }

    while (fscanf(fp, "%s %s %f",
                L->data[L->length].ISBN,
                L->data[L->length].name,
                &L->data[L->length].price) == 3)
    {
        L->length++;
    }
    fclose(fp);
}

// 保存 
void SaveFile(BookList L, char *filename) {
    FILE *fp = fopen(filename, "w");
    if (!fp) {
        printf("保存失败\n");
        return;
    }
    for (int i = 0; i < L.length; i++)
        fprintf(fp, "%s %s %.2f\n",
                L.data[i].ISBN,
                L.data[i].name,
                L.data[i].price);
    fclose(fp);
}
////////////////////////////////////////////////////////////////

int main(){
    BookList L;
    InitBook(&L);
    char filename[] = "book.txt";
    
    LoadFile(&L, filename);
    
    int choice;
    do {
        printf("\n====== 图书信息管理系统 ======\n");
        printf("1. 查找图书\n");
        printf("2. 插入图书\n");
        printf("3. 删除图书\n");
        printf("4. 修改价格\n");
        printf("5. 排序图书\n");
        printf("6. 统计数量\n");
        printf("7. 显示所有图书\n");
        printf("0. 退出并保存\n\n");

        printf("请输入操作编号：");
        scanf("%d", &choice);

        switch (choice) {
            case 1:{
                system("cls");
                char x[50];
                printf("请输入要查找的图书ISBN或名称：");
                scanf("%s", x);
                int target = FindBook(L, x);
                    if (target == -1)
                        printf("未找到该图书！\n");
                    else {
                        printf("位置序号:%d \t ISBN:%s\t 名称:%s\t 价格:%.2f\n", 
                            target + 1, 
                            L.data[target].ISBN, 
                            L.data[target].name, 
                            L.data[target].price);
                            printf("按任意键继续..."); 
                    }
                getchar();getchar();system("cls");
                break;
            }
            case 2:
                InsertBook(&L);
                break;
            case 3:
                DeleteBook(&L);
                break;
            case 4:
                ModifyBook(&L);
                break;
            case 5:
                SortBooks(&L);
                break;
            case 6:
                CountBook(&L);
                break;
            case 7:
                DisplayBooks(L);
                break;
            case 0:
                SaveFile(L, filename);
                printf("数据已保存到 %s 。\n", filename);
                break;
            default:
                printf("无效的选项，请重新输入。\n");
                getchar();getchar();system("cls");
        }
    } while (choice != 0);

    return 0;
}
