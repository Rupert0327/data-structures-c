#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Book {
    char ISBN[20];
    char name[50];
    float price;
    struct Book *next;
} Book, *BookPtr;

void LoadFile(BookPtr *head, const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("文件不存在，已创建新文件。\n");
        return;
    }

    Book *tail = NULL;
    while (1) {
        Book *newNode = (Book *)malloc(sizeof(Book));
        if (fscanf(fp, "%s %s %f", newNode->ISBN, newNode->name, &newNode->price) != 3) {
            free(newNode);
            break;
        }
        newNode->next = NULL;

        if (*head == NULL)
            *head = tail = newNode;
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    fclose(fp);
}

void SaveFile(BookPtr head, const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (!fp) {
        printf("保存失败！\n");
        return;
    }

    Book *p = head;
    while (p) {
        fprintf(fp, "%s %s %.2f\n", p->ISBN, p->name, p->price);
        p = p->next;
    }
    fclose(fp);
}

void DisplayBooks(BookPtr head) {
    system("cls");
    if (!head) {
        printf("暂无图书数据！\n");
        printf("\n按任意键返回菜单...");
        getchar(); system("cls");
        return;
    }

    printf("\n%-15s %-20s %-10s\n", "ISBN", "书名", "价格");
    printf("--------------------------------------------------\n");

    Book *p = head;
    while (p) {
        printf("%-15s %-20s %.2f\n", p->ISBN, p->name, p->price);
        p = p->next;
    }

    printf("\n按任意键返回菜单...");
    getchar(); getchar(); system("cls");
}

Book* FindBook(BookPtr head, const char *x) {
    Book *p = head;
    while (p) {
        if (strcmp(p->ISBN, x) == 0 || strcmp(p->name, x) == 0)
            return p;
        p = p->next;
    }
    return NULL;
}

void InsertBook(BookPtr *head) {
    system("cls");
    Book *newNode = (Book *)malloc(sizeof(Book));
    if (!newNode) {
        printf("内存分配失败！\n");
        return;
    }

    // 检查ISBN重复
    while (1) {
        int duplicate = 0;
        printf("请输入ISBN：");
        scanf("%s", newNode->ISBN);
        Book *temp = *head;
        while (temp) {
            if (strcmp(temp->ISBN, newNode->ISBN) == 0) {
                printf("该ISBN已存在，请重新输入！\n");
                duplicate = 1;
                getchar(); getchar(); system("cls");
                break;
            }
            temp = temp->next;
        }
        if (!duplicate)
            break;
    }

    printf("请输入书名：");
    scanf("%s", newNode->name);
    printf("请输入价格：");
    scanf("%f", &newNode->price);
    getchar();
    newNode->next = NULL;

    if (*head == NULL)
        *head = newNode;
    else {
        Book *p = *head;
        while (p->next)
            p = p->next;
        p->next = newNode;
    }

    printf("插入成功！\n");
    printf("\n按任意键返回菜单...");
    getchar(); getchar(); system("cls");
}

void DeleteBook(BookPtr *head) {
    system("cls");
    char x[50];
    printf("请输入要删除的ISBN或书名：");
    scanf("%s", x);

    Book *p = *head, *prev = NULL;
    while (p) {
        if (strcmp(p->ISBN, x) == 0 || strcmp(p->name, x) == 0) {
            if (prev == NULL)
                *head = p->next;
            else
                prev->next = p->next;
            free(p);
            printf("删除成功！\n");
            printf("\n按任意键返回菜单...");
            getchar(); getchar(); system("cls");
            return;
        }
        prev = p;
        p = p->next;
    }

    printf("未找到该图书！\n");
    printf("\n按任意键返回菜单...");
    getchar(); getchar(); system("cls");
}

void ModifyBook(BookPtr head) {
    system("cls");
    char x[20];
    printf("请输入ISBN以修改价格：");
    scanf("%s", x);

    Book *target = FindBook(head, x);
    if (!target) {
        printf("未找到该图书！\n");
        printf("\n按任意键返回菜单...");
        getchar(); getchar(); system("cls");
        return;
    }

    float newPrice;
    printf("原价格：%.2f\n请输入新价格：", target->price);
    scanf("%f", &newPrice);
    target->price = newPrice;

    printf("修改成功！\n");
    printf("\n按任意键返回菜单...");
    getchar(); getchar(); system("cls");
}

void SortBooks(BookPtr *head) {
    system("cls");
    if (!(*head) || !(*head)->next) {
        printf("图书数量不足，无法排序。\n");
        printf("\n按任意键返回菜单...");
        getchar(); getchar(); system("cls");
        return;
    }

    for (Book *i = *head; i != NULL; i = i->next) {
        for (Book *j = i->next; j != NULL; j = j->next) {
            if (i->price > j->price) {
                char tmpISBN[20], tmpName[50];
                float tmpPrice = i->price;

                strcpy(tmpISBN, i->ISBN);
                strcpy(tmpName, i->name);

                strcpy(i->ISBN, j->ISBN);
                strcpy(i->name, j->name);
                i->price = j->price;

                strcpy(j->ISBN, tmpISBN);
                strcpy(j->name, tmpName);
                j->price = tmpPrice;
            }
        }
    }

    printf("排序完成！\n");
    printf("\n按任意键返回菜单...");
    getchar(); getchar(); system("cls");
}

void CountBook(BookPtr head) {
    system("cls");
    int count = 0;
    Book *p = head;
    while (p) {
        count++;
        p = p->next;
    }
    printf("当前共有 %d 本图书。\n", count);
    printf("\n按任意键返回菜单...");
    getchar(); getchar(); system("cls");
}

int main() {
    BookPtr head = NULL;
    char filename[] = "book.txt";
    LoadFile(&head, filename);

    int choice;
    do {
        printf("\n====== 图书信息管理系统（链式存储） ======\n");
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
        getchar(); // 吸收回车

        switch (choice) {
            case 1: {
                system("cls");
                char x[50];
                printf("请输入ISBN或书名：");
                scanf("%s", x);
                Book *target = FindBook(head, x);
                if (target == NULL)
                    printf("404 Not Found!\n");
                else
                    printf("ISBN:%s\t 书名:%s\t 价格:%.2f\n",
                           target->ISBN, target->name, target->price);
                printf("按任意键返回菜单...");
                getchar(); getchar(); system("cls");
                break;
            }
            case 2:
                InsertBook(&head);
                break;
            case 3:
                DeleteBook(&head);
                break;
            case 4:
                ModifyBook(head);
                break;
            case 5:
                SortBooks(&head);
                break;
            case 6:
                CountBook(head);
                break;
            case 7:
                DisplayBooks(head);
                break;
            case 0:
                SaveFile(head, filename);
                printf("数据已保存到 %s ，程序结束。\n", filename);
                break;
            default:
                printf("无效选项，请重新输入。\n");
                getchar(); getchar(); system("cls");
        }
    } while (choice != 0);

    return 0;
}
