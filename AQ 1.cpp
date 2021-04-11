#include "AQueue.h"
using namespace std;

void show_Menu()
{
    cout << "****************************************************************************" << endl;
    cout << "*****************0.退出系统*************************************************" << endl;
    cout << "*****************1.检查队列是否已满*****************************************" << endl;
    cout << "*****************2.查看队头元素*********************************************" << endl;
    cout << "*****************3.检查队列是否为空*****************************************" << endl;
    cout << "*****************4.确定队列长度*********************************************" << endl;
    cout << "*****************5.出队操作*************************************************" << endl;
    cout << "*****************6.清空队列*************************************************" << endl;
    cout << "*****************7.销毁队列*************************************************" << endl;
    cout << "*****************8.遍历函数操作*********************************************" << endl;
    cout << "*****************9.操作函数*************************************************" << endl;
    cout << "****************************************************************************" << endl;
    cout << endl;
}

void exitSystem()
{
    cout << "欢迎下次使用" << endl;
    system("pause");
    exit(0);
}

//初始化队列
AQueue* InitAQueue(AQueue* Q)
{
    int i;
    Q = (AQueue*)malloc(sizeof(AQueue));
    Q->length = MAXQUEUE;
    for (i = 0; i < MAXQUEUE; i++)
        //不知道用户想放入的数据类型大小，所以给个20
        Q->data[i] = (void*)malloc(21);
    Q->front = Q->rear = 0;
    return Q;
}

//销毁队列
AQueue* DestoryAQueue(AQueue* Q)
{
    if (Q->data[0] == NULL)
    {
        printf("队列目前未初始化！请先初始化队列！\n");
        return 0;
    }
    for (int i = 0; i < MAXQUEUE; i++)
        free(Q->data[i]);
    Q->data[0] = NULL;
    return Q;
}


//检查队列是否已满
Status IsFullAQueue(AQueue* Q)
{
    if (Q->data[0] == NULL)
    {
        printf("队列目前未初始化！请先初始化队列！\n");
        return FALSE;
    }
    if (IsEmptyAQueue(Q)) {
        return FALSE;
    }
    if (LengthAQueue(Q) == MAXQUEUE - 1)
    {
            return TRUE;
    }
    else
        return FALSE;
}

//检查队列是否为空
Status IsEmptyAQueue(AQueue* Q)
{
    if (Q->data[0] == NULL)
    {
        printf("队列目前未初始化！请先初始化队列！\n");
        return FALSE;
    }
    return (LengthAQueue(Q) == 0 ? TRUE : FALSE);
}

//查看队头元素
Status GetHeadAQueue1(AQueue* Q,int* e)
{
    if (IsEmptyAQueue(Q))
    {
        printf("队列为空！没有队头！\n");
        return FALSE;
    }
    memcpy(e, Q->data[Q->front], 21);
    cout << "队头元素的地址是：" << *e << endl;
    return TRUE;
}

Status GetHeadAQueue2(AQueue* Q, char* e)
{
    if (IsEmptyAQueue(Q))
    {
        printf("队列为空！没有队头！\n");
        return FALSE;
    }
    memcpy(e, Q->data[Q->front], 21);
    cout << "队头元素的地址是：" << *e << endl;
    return TRUE;
}

Status GetHeadAQueue3(AQueue* Q, double* e)
{
    if (IsEmptyAQueue(Q))
    {
        printf("队列为空！没有队头！\n");
        return FALSE;
    }
    memcpy(e, Q->data[Q->front], 21);
    cout << "队头元素的地址是：" << *e << endl;
    return TRUE;
}

Status GetHeadAQueue5(AQueue* Q, string* e5)
{
    if (IsEmptyAQueue(Q))
    {
        printf("队列为空！没有队头！\n");
        return FALSE;
    }
    memcpy(e5, Q->data[Q->front], 21);
    cout << "队头元素的地址是：" << *e5 << endl;
    return TRUE;
}
//确定队列长度
int  LengthAQueue(AQueue* Q)
{
    return (Q->rear - Q->front + Q->length) % Q->length;
}


//清空队列
AQueue* ClearAQueue(AQueue* Q)
{
    if (IsEmptyAQueue(Q))
    {
        printf("队列已经是空的了！\n");
        return 0;
    }
    Q->front = Q->rear = 0;
    return Q;
}


//入队操作
AQueue* EnAQueue(AQueue* Q, void* data)
{
    if (IsFullAQueue(Q))
    {
        printf("队列满了！不能再入队了！\n");
        return 0;
    }
    if (IsEmptyAQueue(Q))
    {
        memcpy(Q->data[Q->front], data, 20);
        Q->rear = (Q->rear + 1) % Q->length;
    }
    memcpy(Q->data[Q->rear], data, 20);
    Q->rear = (Q->rear + 1) % Q->length;
    return Q;
}

//出队操作
Status DeAQueue(AQueue* Q)
{
    if (IsEmptyAQueue(Q))
    {
        printf("队列是空的！出不了队！\n");
        return FALSE;
    }
    Q->front = (Q->front + 1) % Q->length;
    return TRUE;
}

//遍历函数操作
Status traverseaqueue(AQueue* Q, int (*foo)(int typeData))
{
    if (Q->data[0] == NULL)
    {
        printf("队列目前未初始化！请先初始化队列！\n");
        return FALSE;
    }
    if (IsEmptyAQueue(Q))
    {
        printf("队列里面什么都没有!\n");
        return FALSE;
    }
    int i = 0;
    while (i < (MAXQUEUE - Q->front + Q->rear) % MAXQUEUE) {
        foo(Q->type[Q->front + i]);
        i = (i + 1) % MAXQUEUE;
    }
    return TRUE;
}

//操作函数
void APrint(void* q, int typeData)
{
    if (typeData == 3)
        printf("--> %.2lf", *(double*)q);
    if (typeData == 2)
        printf("--> %c", *(char*)q);
    if (typeData == 1)
        printf("--> %d ", *(int*)q);
    if (typeData == 4)
        printf("--> %s ", (char*)q);
}

int foo(int typeData) {
    cout << "遍历函数成功" << endl;
    return 0;
}

int main()
{
    int t,k=1;
    int choice = 0;
    int i;
    int typeData;

    cout << "正在初始化中......" << endl;
    Q=InitAQueue(Q);
    cout << "初始化已经完成。" << endl;
    cout << "感谢您的使用。" << endl;

    cout << "你想入队哪种类型？" << endl;
    cout << "1. 整型 2. 字符型 3. 浮点型(精确到小数点后2位) 4. 字符串\n" << endl;
    cin >> t;
    while (t < 1 || t>4)
    {
        cout << "应输入在[1,4]之间的整数！\n请重输：" << endl;
        cin >> t;
    }
    while (k) {
        cout << "想入队的数据: " << endl;
        switch (t)
        {
        case 1: {
            int a, b;
            cin >> a;
            b = Q->rear;
            Q->type[b] = t;
            EnAQueue(Q, &a);
            break;
        }
        case 2: {
            char a;
            cin >> a;
            Q->type[Q->rear] = t;
            EnAQueue(Q, &a);
            break;
        }
        case 3: {
            double a;
            cin >> a;
            Q->type[Q->rear] = t;
            EnAQueue(Q, &a);
            break;
        }
        case 4: {
            char a[20];
            printf("最大长度为20哦！\n");
            scanf("%s", a);
            Q->type[Q->rear] = t;
            EnAQueue(Q, a);
            break;
        }

        }
        cout << "需要继续入队数据吗？（是1/否0）" << endl;
        cin >> k;
    }

    cout << "请输入您接下来的操作：" << endl;

    while (true)
    {
        show_Menu();
        cout << "请输入您的选择" << endl;
        cin >> choice;

        switch (choice)
        {
        case 0://退出系统
            exitSystem();
            break;
        case 1://检查队列是否已满
            if (IsFullAQueue(Q)) {
                cout << "队列已满" << endl;
            }
            else {
                cout << "队列未满" << endl;
            }
            break;
        case 2://查看队头元素
            if (t == 1) {
                int* e;
                e = (int*)malloc(21);
                GetHeadAQueue1(Q, e);
            }
            if (t == 2) {
                char* e;
                e = (char*)malloc(21);
                GetHeadAQueue2(Q, e);
            }
            if (t == 3) {
                double* e;
                e = (double*)malloc(21);
                GetHeadAQueue3(Q, e);
            }
            if (t == 4) {
                string* e5;
                e5 = (string*)malloc(21);
                //GetHeadAQueue5(Q, e5);
            }
            break;
        case 3://检查队列是否为空
            if (IsEmptyAQueue(Q)) {
                cout << "队列为空" << endl;
            }
            else {
                cout << "队列不是空的" << endl;
            }
            break;
        case 4://确定队列长度
            int p;
            p=LengthAQueue(Q);
            cout << "队列长度为：" << p-1 << endl;
            break;
        case 5://出队操作
            DeAQueue(Q);
            cout << endl;
            cout << "已全部出队完成。" << endl;
            break;
        case 6://清空队列
            Q=ClearAQueue(Q);
            cout << "已全部清空完成。" << endl;
            break;
        case 7://销毁队列
            Q=DestoryAQueue(Q);
            cout << "已全部销毁完成。" << endl;
            break;
        case 8://遍历函数操作
            traverseaqueue(Q, foo);
            cout << "已全部遍历函数完成。" << endl;
            break;
        case 9://操作函数
            void* q;
            q = Q;
            cin >> typeData;
            APrint(q, typeData);
            cout << "已操作函数完成。" << endl;
            break;
        default:
            cout << "输入错误" << endl;
            cout << "请重新输入" << endl;
            system("pause");
            system("cls");
            break;
        }
    }


    system("pause");
    return 0;
}