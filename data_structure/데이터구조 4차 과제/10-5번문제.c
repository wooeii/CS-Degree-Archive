#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define DataType char*

typedef struct Tnode //이진트리의 노드 구조 정의  
{
    struct Tnode* left; //왼쪽 자식노드를 가리키는  포인터 
    DataType data;
    int line;
    struct Tnode* right; //오른쪽 자식노드를 가리키는 포인터  
} Tnode;

typedef struct LinkedBT //이진트리의 헤드 노드 구조 정의  
{
    Tnode* root; //루트 노드를 가리키는 포인터  
} LinkedBT;

void init_BT(Tnode** root) //트리 초기화  
{
    *root = NULL;
}

void countLines(int line) // line의 각 비트가 1인 위치에 대응하는 줄 번호를 출력
{
    int count = 1;
    int i;
    int flag = 0; // 뒤에 , 출력 여부를 나타내는 플래그

    for (i = 0; i < sizeof(int) * 8; i++) {
        if (line & (1 << i)) {
            if (flag) {
                printf(",");
            } else {
                flag = 1;
            }
            printf("%d", count);
        }
        count++;
    }
    printf("\n");
}

int stricmp(const char* a, const char* b) //문자열을 대소문자를 구분하지 않고 비교
{
    for (; *a && *b; ++a, ++b) {
        int d = tolower((unsigned char)*a) - tolower((unsigned char)*b); //tolower = 소문자로 변환 / 아스키 코드 값 비교  
        if (d != 0)
            return d;
    }
    return *a - *b;
}
void print_BT(Tnode* root, int* totalCount) // 이진 트리를 중위 순회하면서 데이터를 출력
{
    if (root != NULL) {
        print_BT(root->left, totalCount);

        // 데이터의 문자열을 소문자로 변환하고 '?' 문자 이후의 문자를 제거
        char* data = strdup(root->data);
        int i;
        for (i = 0; data[i]; i++) {
            data[i] = tolower(data[i]);
            if (data[i] == '?') {
                data[i] = '\0';
                break;
            }
        }

        printf("%s\t", data); // 변환된 데이터 출력
        printf("%d\t", __builtin_popcount(root->line)); // 등장 횟수 출력
        countLines(root->line); // 등장한 줄 번호 출력

        (*totalCount) += __builtin_popcount(root->line); // 등장 횟수를 총 등장 단어 수에 누적

        free(data);
        print_BT(root->right, totalCount);
    }
}

void insert_node_BST(Tnode** root, DataType data, int line) // 이진 탐색 트리에 새로운 노드를 삽입하는 기능을 수행
{
    Tnode* searched = *root;
    Tnode* parent = NULL;

    while (searched) {
        int cmp = stricmp(data, searched->data);

        if (cmp == 0) {
            // 이미 등장한 단어인 경우 등장 횟수 증가
            searched->line |= line;
            return;
        }
        parent = searched;

        if (cmp < 0)
            searched = searched->left; 
        else
            searched = searched->right; 
    }

    Tnode* new_node = (Tnode*)malloc(sizeof(Tnode));
    if (!new_node) {
        printf("새 노드 메모리 할당 실패\n");
        exit(1);
    }

    new_node->data = strdup(data); 
    new_node->line = line; 
    new_node->left = new_node->right = NULL; 

    if (!parent)
        *root = new_node; 
    else if (stricmp(data, parent->data) < 0)
        parent->left = new_node; 
    else
        parent->right = new_node;
}
int main(void) {
    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return 1;
    }

    Tnode* root;
    init_BT(&root); //초기화  

    char line[256]; //줄  
    int line_number = 1; //줄번호  
    int totalcount = 0; //총 등장 단어 수  
    while (fgets(line, sizeof(line), file)) //읽어드림 
	{
        char* word = strtok(line, " \t\n"); //문자열 분리  

        while (word != NULL) 
		{
            insert_node_BST(&root, word, line_number); //이진트리에 삽입  
            word = strtok(NULL, " \t\n");
        }

        line_number++; //줄번호  
    }

    fclose(file); //파일을 닫는다.  

    printf("단어\t횟수\t줄\n");
    printf("------------------------\n");
    print_BT(root, &totalcount);
    printf("계\t%d\n", totalcount);

    return 0;
}
