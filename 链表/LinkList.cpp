//���ļ�Ϊ ������ʵ��
#include<bits/stdc++.h>
typedef int ElemType;   //˳�������Ϊint 4�ֽ�

//-- ������ --//
//��㶨��
typedef struct LNode{
    ElemType data;  //������
    struct LNode *next; //ָ����
}LNode,*LinkList;
//�˴�typedef�����൱�ڣ�
//typedef struct LNode LNode;
//typedef struct LNode *LinkList;

/*------------------- ������ -------------------*/
//���ں�����ָ���ʹ�ã�LiskList��*LNode��������ͬ������ǰ�߸���ǿ����ǰ����Ϊ��������ǿ����ǰ����Ϊ��㣬ע�⺯���е��õ�����


//��������ͷ����������(����ͷ�巨)
//��ڣ�����ʼ������
//���ڣ���ʼ����ɵ�����
LinkList List_HeadInsert(LinkList &L)   //������������
{
    LNode *s;
    int x;
    L = (LinkList)malloc(sizeof(LNode));    //����ͷ���
    L->next = NULL;     //��ʼ��Ϊ�ձ�ͷ���ָ��null
    printf("\n������Ҫ�����ĵ������������");
    scanf("%d",&x);
    while(x)
    {
        s = (LNode *)malloc(sizeof(LNode)); //�����½�㣬ע������ʹ�õ���LNode *��������LinkList��������ͬ�ģ����岻ͬ���ѡ�
        s->data = x;    //Ĭ��Ϊ����˳��ֵ
        s->next = L->next;
        L->next = s;    //���½�������У�LΪͷָ��
        x--;
    }
    return L;
}

//��������ͷ����������������β�巨��
//��ڣ�����ʼ������
//���ڣ���ʼ����ɵ�����
LinkList List_TailInsert(LinkList &L)   //������������
{
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    LNode *s,*r = L;    //rΪ��βָ��
    printf("\n������Ҫ�����ĵ������������");
    scanf("%d",&x);
    while(x)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        x--;
    }
    r->next = NULL;
    return L;
}


//��������λ��ǰ���루��ͷ��㣩
//��ڣ�������λ��ֵ
//���ڣ�����״ֵ̬ 0��1��
bool  ListInsert_WithHead(LinkList &L,int i,ElemType e)
{
    //�Ϸ����ж�
    if(i < 1)   return false;
    //��ʼ�ҵ�i-1�����
    LNode *p;   //ָ��ǰɨ����
    int j = 0;  //��¼��ǰָ����ǵڼ������
    p = L;      //��ʼָ��ͷ��㣬Ϊ��0��
    while((p != NULL) && (j < i-1)) //ѭ���ҵ���i-1����㣬������Ľ��ǰһ��
    {
        p = p->next;
        j++;
    }
    if(p == NULL)   //pָ����null��������i-1��Ԫ�ز����ڣ���i���Ϸ�
        return false;
    //��ʼ�����½��
    LNode *s = (LNode *)malloc(sizeof(LNode));  //�����½��
    s->data = e;
    s->next = p->next;  //��һ������һ�����ܻ�˳�򣬷���ͱ��2������ָ����ɺ����㶪ʧ
    p->next = s;    //p����sǰ��

    return true;

}

//��������λ��ǰ���루����ͷ��㣩
//��ڣ�������λ��ֵ
//���ڣ�����״ֵ̬ 0��1��
bool  ListInsert_WithoutHead(LinkList &L,int i,ElemType e)
{
    //�Ϸ����ж�
    if(i < 1)   return false;

    //���ͷ������������Ҫ�Բ����1��ͷ��������⴦��
    if(i == 1)
    {
        LNode *s = (LNode *)malloc(sizeof(LNode));
        s->data = e;
        s->next = L;
        L = s;      //ͷָ��ָ���½��
        return true;
    }

    //��ʼ�ҵ�i-1�����
    LNode *p;   //ָ��ǰɨ����
    int j = 0;  //��¼��ǰָ����ǵڼ������
    p = L;      //��ʼָ��ͷ��㣬Ϊ��0��
    while((p != NULL) && (j < i-1)) //ѭ���ҵ���i-1����㣬������Ľ��ǰһ��
    {
        p = p->next;
        j++;
    }
    if(p == NULL)   //pָ����null��������i-1��Ԫ�ز����ڣ���i���Ϸ�
        return false;
    //��ʼ�����½��
    LNode *s = (LNode *)malloc(sizeof(LNode));  //�����½��
    s->data = e;
    s->next = p->next;  //��һ������һ�����ܻ�˳�򣬷���ͱ��2������ָ����ɺ����㶪ʧ
    p->next = s;    //p����sǰ��

    return true;
}

//����:ָ�����ĺ�����    ʱ�临�Ӷ�ΪO(1)
//��ڣ������㣬������½��ֵ
//���ڣ�����״ֵ̬ 0��1��
bool InsertNextNode(LNode *p,ElemType e)
{
    if(p == NULL)   return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if(s == NULL)   return false;

    s->data = e;
    s->next = p->next;
    p->next = s;
    
    return true;
}

//������ָ������ǰ�����   ʱ�临�Ӷ�ΪO(1)
//��ڣ������㣬������½��ֵ
//���ڣ�����״ֵ̬ 0��1��
bool InsertPriorNode(LNode *p,LNode *s)
{
    if((p == NULL) || (s == NULL))  return false;
    s->next = p->next;  //s��p����Ľ������
    p->next = s;    //p�ĺ�̽���Ϊs
    ElemType tp = p->data;  //�ݴ�p����data
    p->data = s->data;  //��p����data��ֵ��p���棬Ȼ���s����data��Ϊp���ģ����൱�ڽ�����p����ǰ�����
    s->data = tp;
    return true;
}

//��������λ��ɾ������ͷ��㣩 ���ƽ�����Ӷ�Ϊ��O(n)  ��ø��Ӷ�Ϊ��O(1)
//��ڣ�������λ�򣬴��ɾ���������ݣ����أ�
//���ڣ�����״ֵ̬ 0��1��
bool ListDelete(LinkList &L,int i,ElemType &e)
{
    if( i < 1)  return false;
    LNode *p;       //��ǰɨ����
    int j = 0;      //��ǰpָ��Ľ�����
    p = L;          //ָ��ͷ��㣬��0�����
    while((p != NULL) && (j < i-1)) //�ҵ���i-1�����
    {
        p = p->next;
        j++;
    }
    if((p == NULL) || (p->next == NULL))    //iֵ���Ϸ�|��i-1���������޽��
        return false;
    LNode *q = p->next; //qָ��ɾ���Ľ��
    e = q->data;    //���ر�ɾ������ֵ
    p->next = q->next;  //Խ��p����Ľ�㣬��pָ��p+1 +1 �Ľ�㣬�м��Ǹ�ɾ��
    free(q);
    return true;
}

//������ָ������ɾ��  
//��ڣ���ɾ���Ľ��
//���ڣ�����״ֵ̬ 0��1��
//ע������һ��ԭ��bug�����������ʱ�临�Ӷ�ΪO(1)
//���ǣ����Ҫɾ�����һ����㣬��ô��������ͻ������Ϊ���һ�����ɾ�����������������ԭ��
//�����˵�����ľ����ԣ��޷����������Ҫ�����Ҫʹ��˫����������޸��㷨�������һ��������������⴦��
//��������һ����㣬��ôֻ�ܴӱ�ͷ��ʼ����Ѱ��p��ǰ����ʱ�临�Ӷ�ΪO(n) 
bool DeleteNode(LNode *p)
{
    if(p == NULL)   return false;
    LNode *q = p->next; //��qָ��*p�ĺ�̽��
    p->data = p->next->data;    //p��p����Ľ�㽻������
    p->next = q->next;  //p�ĺ��ָ��ɾ����������Ǹ����
    free(q);    //�ͷ�p�ĺ�̽��

    return true;
}

//��������λ���ң���ͷ��㣩    ƽ��ʱ�临�Ӷȣ�O(n)
//��ڣ����������λ��
//���ڣ����ҵĽ��
//ע���Ѿ����ǵ�0�������
LNode * GetElem(LinkList L,int i)
{
    if(i < 0)   return NULL;
    LNode *p;   //��¼��ǰɨ����
    int j = 0;  //��ǰpָ��Ľ��
    p = L;  //ָ��ͷ��㣬ͷ���Ϊ��0�����
    while(p != NULL && j < i)   //�ҵ���i����㣬ע�������0��ʼ�ģ����в���i-1
    {
        p = p->next;
        j++;
    }
    return p;   //ֱ�ӷ��ز��ҵĽ�㣬����0�������
}

//��������ֵ����       ƽ��ʱ�临�Ӷȣ�O(n)
//��ڣ����������ֵ
//���ڣ����ҽ��
LNode * LocateElem(LinkList L,ElemType e)
{
    LNode *p = L->next;
    //�ӵ�һ����㿪ʼ����
    while(p != NULL && p->data != e)    p = p->next;
    return p;
}

//�������޸�����
//��ڣ������� ���λ�� �޸�ֵ
//���ڣ�����״ֵ̬ 0��1��
bool ChangeNodeValue(LinkList &L,int i,ElemType e)
{
    if( LNode *p = GetElem(L,i) )
    {
        p->data = e;
        return true;
    }
    else
        return false;
}

//���������ĳ���
//��ڣ�������
//���ڣ���
int Length(LinkList L)
{
    int len = 0;
    LNode *p = L;
    while (p->next != NULL)
    {
        p = p->next;
        len++;
    }
    return len;
}

//��������ʾ��ǰ��������ֵ
//��ڣ�������
//���ڣ���
void Show_LinkList(LinkList L)
{
    LNode *p = L;
    printf("��ǰ������������Ϊ��");
    while(p->next != NULL)
    {
        p = p->next;
        printf("%-6d",p->data);
    }
    printf("\n");
}
/*---------------------------------------------*/


//��ʾ�˵�����
void Show_Menu()
{
    printf("=================================================\n");
    printf("||---------- ���Ա���ѡ��˵� ----------||\n");
    printf("|----- �������� -----|\n");
    printf("|11.����ͷ�巨��������.\n");
    printf("|12.����β�巨��������.\n");
    printf("|13.��λ��ǰ����.\n");
    printf("|14.ָ�����ǰ��(��).\n");
    printf("|15.ָ�������(��).\n");
    printf("|16.��λ��ɾ��.\n");
    printf("|17.ָ������ɾ��(��).\n");
    printf("|18.��λ����.\n");
    printf("|19.��ֵ����.\n");
    printf("|20.�޸�����.\n");
    printf("|---------------------|\n");
    printf("||--------------------------------------||\n");
    printf("=================================================\n");
}



int choose_number;      //��Ų�����
//int len_input = 0;      //Ҫ���ӵ�˳�����
int weizhi_temp = 0;   //��ʱ����
int value_temp = 0;    //��ʱ����
LinkList List;
int main()
{
    Show_Menu(); 
    while(1)
    {
        printf("������������:");
        scanf("%d",&choose_number);
        switch (choose_number)
        {
        case 11:
            List = List_HeadInsert(List);
            Show_LinkList(List);
            break;
        case 12:
            List = List_TailInsert(List);
            Show_LinkList(List);
            break;
        case 13:
            Show_LinkList(List);
            printf("���������λ���ֵ���ո���룺");
            scanf("%d %d",&weizhi_temp,&value_temp);
            if( ListInsert_WithHead(List,weizhi_temp,value_temp) )  printf("����ɹ���\n");
            else    printf("����ʧ�ܣ�\n");
            Show_LinkList(List);
            break;
        case 14:
            Show_LinkList(List);
            printf("�䲻�������ֶ�����.\n");
            LNode *tp;
            tp->data = 123;
            InsertPriorNode(List+3,tp);
            Show_LinkList(List);
            break;
        case 16:
            Show_LinkList(List);
            printf("������ɾ����λ��");
            scanf("%d",&weizhi_temp);
            if( ListDelete(List,weizhi_temp,value_temp) )  printf("ɾ���ɹ���ɾ��ֵΪ��%d\n",value_temp);
            else    printf("ɾ��ʧ�ܣ�\n");
            Show_LinkList(List);
            break;
        case 18:
            Show_LinkList(List);
            printf("��������ҵ�λ��");
            scanf("%d",&weizhi_temp);
            if( LNode * tp = GetElem(List,weizhi_temp) )  printf("���ҳɹ���������ֵΪ��%d\n",tp->data);
            else    printf("����ʧ�ܣ�\n");
            break;
        case 19:
            Show_LinkList(List);
            printf("��������ҵ�ֵ��");
            scanf("%d",&value_temp);
            if( LNode * tp = LocateElem(List,value_temp) )  printf("���ҳɹ���\n");
            else    printf("����ʧ�ܣ�\n");
            break;
        case 20:
            Show_LinkList(List);
            printf("�������޸����ݵ�λ����޸�ֵ���ո�ָ");
            scanf("%d %d",&weizhi_temp,&value_temp);
            if( ChangeNodeValue(List,weizhi_temp,value_temp) )  printf("�޸ĳɹ���\n");
            else    printf("�޸�ʧ�ܣ�\n");
            Show_LinkList(List);
            break;

        default:
            printf("����������������룡\n");
            break;
        }
    }


}
