#include "Linear_List.h"

/*------------------- ˳��� -------------------*/
//��������ʼ��˳���
//��ڣ�����ʼ����˳���
//���أ���
void InitList(SeqList &L)
{
    L.data = (ElemType *)malloc(InitSize * sizeof(ElemType));   //100*4 = 400�ֽ�
    L.Maxsize = InitSize;   //��ʼ��˳���Ԫ�ظ������100��
    L.length = 0;   //��ʼ��˳������Ϊ0
}

//�������ֶ�����˳����Ԫ��
//��ڣ�Ҫ���ӳ��ȵ�˳�������Ԫ�ظ���
//���ڣ���
void IncreaseSize(SeqList &L,int len)
{
    int *p = L.data;    //ָ��ָ���L��data����
    L.data = (ElemType *)malloc((L.Maxsize+len) * sizeof(ElemType) );   //�������ӿռ�
    for(int i = 0;i < L.length;i++)
    {
        L.data[i] = p[i];   //��һ���������µĿռ�֮���������ã���Ҫ��ԭ�����ݸ��ƽ���
    }
    L.Maxsize += len;   //˳���������
    free(p);    //�ͷ�ָ��p
}

//�������������
//��ڣ������˳�������λ�򣬲���Ԫ��ֵ
//���ڣ�����״ֵ̬��0��1��
bool ListInsert(SeqList &L,int i,ElemType e)   
{
    //�Ϸ����ж�
    if((i < 1) || (i > L.length+1) ) //�ж�i��λ��
        return false;
    if(L.length >= L.Maxsize)   //�Ƿ��п���λ��
        return false;
    //�ƶ����ݲ���
    for(int j = L.length;j >= i;j--)    //�Ӻ�����ǰ���ƶ�
        L.data[j] = L.data[j-1];
    L.data[i-1] = e;    //��i��λ�ò�����ֵ������洢λ��Ϊi-1
    L.length++;
    return true;
}

//������ɾ��������Ԫ����ǰ�ƶ����һ��ֵδ���д���
//��ڣ���ɾ��˳��� ɾ��λ�� ���ɾ��������ֵ
//���ڣ�����״ֵ̬��0��1��
bool ListDelete(SeqList &L,int i,ElemType &e)   
{
    //�Ϸ����ж�
    if((i < 1)||(i > L.length)) //�ж�i
        return false;
    e = L.data[i-1];    //���ɾ��������ֵ
    for(int j = i;j < L.length;j++)     //������ǰ����
        L.data[j-1] = L.data[j];
    L.length--;
    return true;
}

//��������ֵ���Ҳ���
//��ڣ������ҵ�˳�������Ԫ��
//���ڣ�0�� ��0ΪԪ�ش���
int LocateElem(SeqList L,ElemType e)
{
    int i;
    for(i = 0;i < L.length;i++)
    {
        if(L.data[i] == e)  return i+1; //���ش���
    }
    return false;
    
}

//��������λ���Ҳ���
//��ڣ�˳�������λ��
//���ڣ�Ԫ��ֵ
int GetElem(SeqList L,int i)
{
    if((i < 1) || (i >= L.length))
        return false;
    else
        return L.data[i-1];     //����Ԫ��ֵ
}

//��ʾ��ǰ˳����е�Ԫ��
void Show(SeqList L)
{
    printf("��ǰ˳�����Ԫ��Ϊ��");
    for(int i = 0;i < L.length - 1; i++)
        printf("%d ",L.data[i]);
    printf("%d\n",L.data[L.length - 1]);
    
}

/*---------------------------------------------*/

//��ʾ�˵�����
void Show_Menu()
{
    printf("=================================================\n");
    printf("||---------- ���Ա���ѡ��˵� ----------||\n");
    printf("|----- ˳����� -----|\n");
    printf("|1.��������ʼ��˳���.\n");
    printf("|2.����˳�����.\n");
    printf("|3.����˳���Ԫ��.\n");
    printf("|4.ɾ��˳���Ԫ��.\n");
    printf("|5.��ֵ����˳���Ԫ��.\n");
    printf("|6.��λ����˳���Ԫ��.\n");
    printf("|---------------------|\n");
    printf("||--------------------------------------||\n");
    printf("=================================================\n");
}



int choose_number;      //��Ų�����
int len_input = 0;      //Ҫ���ӵ�˳�����
int weizhi_temp = 0;   //��ʱ����
int value_temp = 0;    //��ʱ����
int main()
{
    Show_Menu(); 
    while(1)
    {
        printf("������������:");
        scanf("%d",&choose_number);
        switch (choose_number)
        {
        case 1:
            SeqList L;
            InitList(L);
            for(int i = 1;i <= 10;i++)   ListInsert(L,i,i);
            Show(L);
            printf("��ʼ����ɣ���ǰ˳������Ϊ��%d,�ñ����ɴ�ţ�%d��Ԫ��.\n",L.length,L.Maxsize);
            break;
        case 2:
            printf("������Ҫ���ӵ�˳�����:");
            scanf("%d",&len_input);
            IncreaseSize(L,len_input);
            printf("��ǰ˳������Ϊ��%d,�ñ����ɴ�ţ�%d��Ԫ��.\n",L.length,L.Maxsize);
            break;
        case 3:
            printf("������Ҫ���������Ԫ��λ��1��ʼ����ֵ���ո�ָ���");
            scanf("%d %d",&weizhi_temp,&value_temp);
            if( ListInsert(L,weizhi_temp,value_temp) )
                printf("����ɹ���");
            else
                printf("����ʧ�ܣ�");
            Show(L);
            break;
        case 4:
            printf("������Ҫɾ��������Ԫ��λ��");
            scanf("%d",&weizhi_temp);
            if( ListDelete(L,weizhi_temp,value_temp) )
                printf("ɾ���ɹ���ɾ����Ԫ��ֵΪ��%d.",value_temp);
            else
                printf("ɾ��ʧ�ܣ�");
            Show(L);           
            break;
        case 5:
            printf("������Ҫ���ҵ�����Ԫ��ֵ��");
            scanf("%d",&value_temp);
            if( int temp = LocateElem(L,value_temp) )
                printf("���ҳɹ�����Ԫ�ص�λ��Ϊ��%d\n",temp);
            else
                printf("����ʧ�ܣ�\n");            
            break;
        case 6:
            printf("������Ҫ���ҵ�����Ԫ��λ��");
            scanf("%d",&weizhi_temp);
            if( int temp = GetElem(L,weizhi_temp) )
                printf("���ҳɹ�����Ԫ�ص�ֵΪ��%d\n",temp);
            else
                printf("����ʧ�ܣ�\n");            
            break;
        default:
            printf("����������������룡\n");
            break;
        }
    }


}







