#include "AQueue.h"
using namespace std;

void show_Menu()
{
    cout << "****************************************************************************" << endl;
    cout << "*****************0.�˳�ϵͳ*************************************************" << endl;
    cout << "*****************1.�������Ƿ�����*****************************************" << endl;
    cout << "*****************2.�鿴��ͷԪ��*********************************************" << endl;
    cout << "*****************3.�������Ƿ�Ϊ��*****************************************" << endl;
    cout << "*****************4.ȷ�����г���*********************************************" << endl;
    cout << "*****************5.���Ӳ���*************************************************" << endl;
    cout << "*****************6.��ն���*************************************************" << endl;
    cout << "*****************7.���ٶ���*************************************************" << endl;
    cout << "*****************8.������������*********************************************" << endl;
    cout << "*****************9.��������*************************************************" << endl;
    cout << "****************************************************************************" << endl;
    cout << endl;
}

void exitSystem()
{
    cout << "��ӭ�´�ʹ��" << endl;
    system("pause");
    exit(0);
}

//��ʼ������
AQueue* InitAQueue(AQueue* Q)
{
    int i;
    Q = (AQueue*)malloc(sizeof(AQueue));
    Q->length = MAXQUEUE;
    for (i = 0; i < MAXQUEUE; i++)
        //��֪���û��������������ʹ�С�����Ը���20
        Q->data[i] = (void*)malloc(21);
    Q->front = Q->rear = 0;
    return Q;
}

//���ٶ���
AQueue* DestoryAQueue(AQueue* Q)
{
    if (Q->data[0] == NULL)
    {
        printf("����Ŀǰδ��ʼ�������ȳ�ʼ�����У�\n");
        return 0;
    }
    for (int i = 0; i < MAXQUEUE; i++)
        free(Q->data[i]);
    Q->data[0] = NULL;
    return Q;
}


//�������Ƿ�����
Status IsFullAQueue(AQueue* Q)
{
    if (Q->data[0] == NULL)
    {
        printf("����Ŀǰδ��ʼ�������ȳ�ʼ�����У�\n");
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

//�������Ƿ�Ϊ��
Status IsEmptyAQueue(AQueue* Q)
{
    if (Q->data[0] == NULL)
    {
        printf("����Ŀǰδ��ʼ�������ȳ�ʼ�����У�\n");
        return FALSE;
    }
    return (LengthAQueue(Q) == 0 ? TRUE : FALSE);
}

//�鿴��ͷԪ��
Status GetHeadAQueue1(AQueue* Q,int* e)
{
    if (IsEmptyAQueue(Q))
    {
        printf("����Ϊ�գ�û�ж�ͷ��\n");
        return FALSE;
    }
    memcpy(e, Q->data[Q->front], 21);
    cout << "��ͷԪ�صĵ�ַ�ǣ�" << *e << endl;
    return TRUE;
}

Status GetHeadAQueue2(AQueue* Q, char* e)
{
    if (IsEmptyAQueue(Q))
    {
        printf("����Ϊ�գ�û�ж�ͷ��\n");
        return FALSE;
    }
    memcpy(e, Q->data[Q->front], 21);
    cout << "��ͷԪ�صĵ�ַ�ǣ�" << *e << endl;
    return TRUE;
}

Status GetHeadAQueue3(AQueue* Q, double* e)
{
    if (IsEmptyAQueue(Q))
    {
        printf("����Ϊ�գ�û�ж�ͷ��\n");
        return FALSE;
    }
    memcpy(e, Q->data[Q->front], 21);
    cout << "��ͷԪ�صĵ�ַ�ǣ�" << *e << endl;
    return TRUE;
}

Status GetHeadAQueue5(AQueue* Q, string* e5)
{
    if (IsEmptyAQueue(Q))
    {
        printf("����Ϊ�գ�û�ж�ͷ��\n");
        return FALSE;
    }
    memcpy(e5, Q->data[Q->front], 21);
    cout << "��ͷԪ�صĵ�ַ�ǣ�" << *e5 << endl;
    return TRUE;
}
//ȷ�����г���
int  LengthAQueue(AQueue* Q)
{
    return (Q->rear - Q->front + Q->length) % Q->length;
}


//��ն���
AQueue* ClearAQueue(AQueue* Q)
{
    if (IsEmptyAQueue(Q))
    {
        printf("�����Ѿ��ǿյ��ˣ�\n");
        return 0;
    }
    Q->front = Q->rear = 0;
    return Q;
}


//��Ӳ���
AQueue* EnAQueue(AQueue* Q, void* data)
{
    if (IsFullAQueue(Q))
    {
        printf("�������ˣ�����������ˣ�\n");
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

//���Ӳ���
Status DeAQueue(AQueue* Q)
{
    if (IsEmptyAQueue(Q))
    {
        printf("�����ǿյģ������˶ӣ�\n");
        return FALSE;
    }
    Q->front = (Q->front + 1) % Q->length;
    return TRUE;
}

//������������
Status traverseaqueue(AQueue* Q, int (*foo)(int typeData))
{
    if (Q->data[0] == NULL)
    {
        printf("����Ŀǰδ��ʼ�������ȳ�ʼ�����У�\n");
        return FALSE;
    }
    if (IsEmptyAQueue(Q))
    {
        printf("��������ʲô��û��!\n");
        return FALSE;
    }
    int i = 0;
    while (i < (MAXQUEUE - Q->front + Q->rear) % MAXQUEUE) {
        foo(Q->type[Q->front + i]);
        i = (i + 1) % MAXQUEUE;
    }
    return TRUE;
}

//��������
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
    cout << "���������ɹ�" << endl;
    return 0;
}

int main()
{
    int t,k=1;
    int choice = 0;
    int i;
    int typeData;

    cout << "���ڳ�ʼ����......" << endl;
    Q=InitAQueue(Q);
    cout << "��ʼ���Ѿ���ɡ�" << endl;
    cout << "��л����ʹ�á�" << endl;

    cout << "��������������ͣ�" << endl;
    cout << "1. ���� 2. �ַ��� 3. ������(��ȷ��С�����2λ) 4. �ַ���\n" << endl;
    cin >> t;
    while (t < 1 || t>4)
    {
        cout << "Ӧ������[1,4]֮���������\n�����䣺" << endl;
        cin >> t;
    }
    while (k) {
        cout << "����ӵ�����: " << endl;
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
            printf("��󳤶�Ϊ20Ŷ��\n");
            scanf("%s", a);
            Q->type[Q->rear] = t;
            EnAQueue(Q, a);
            break;
        }

        }
        cout << "��Ҫ������������𣿣���1/��0��" << endl;
        cin >> k;
    }

    cout << "���������������Ĳ�����" << endl;

    while (true)
    {
        show_Menu();
        cout << "����������ѡ��" << endl;
        cin >> choice;

        switch (choice)
        {
        case 0://�˳�ϵͳ
            exitSystem();
            break;
        case 1://�������Ƿ�����
            if (IsFullAQueue(Q)) {
                cout << "��������" << endl;
            }
            else {
                cout << "����δ��" << endl;
            }
            break;
        case 2://�鿴��ͷԪ��
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
        case 3://�������Ƿ�Ϊ��
            if (IsEmptyAQueue(Q)) {
                cout << "����Ϊ��" << endl;
            }
            else {
                cout << "���в��ǿյ�" << endl;
            }
            break;
        case 4://ȷ�����г���
            int p;
            p=LengthAQueue(Q);
            cout << "���г���Ϊ��" << p-1 << endl;
            break;
        case 5://���Ӳ���
            DeAQueue(Q);
            cout << endl;
            cout << "��ȫ��������ɡ�" << endl;
            break;
        case 6://��ն���
            Q=ClearAQueue(Q);
            cout << "��ȫ�������ɡ�" << endl;
            break;
        case 7://���ٶ���
            Q=DestoryAQueue(Q);
            cout << "��ȫ��������ɡ�" << endl;
            break;
        case 8://������������
            traverseaqueue(Q, foo);
            cout << "��ȫ������������ɡ�" << endl;
            break;
        case 9://��������
            void* q;
            q = Q;
            cin >> typeData;
            APrint(q, typeData);
            cout << "�Ѳ���������ɡ�" << endl;
            break;
        default:
            cout << "�������" << endl;
            cout << "����������" << endl;
            system("pause");
            system("cls");
            break;
        }
    }


    system("pause");
    return 0;
}