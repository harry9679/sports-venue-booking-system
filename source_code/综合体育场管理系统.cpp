//
//  �ۺ�����������ϵͳ 
//
//  Created by Group 46. 
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h> 

#define AWEEK 604800		//һ�����ڵ����������ڴ�����ʱ��ʱ����� 
#define YES 1
#define NO 0

typedef struct {
    char name[20];
    char ID[20];
    char password[20];
    int sex;
    int age;
    char phone[12];
    char email[25];
    float money;
    char district[20];
}CUSTOMER;				//���ڱ���˿���Ϣ�Ľṹ 

typedef struct {
    char name[20];
    char ID[20];
    char password[20];
    int sex;
    char phone[12];
    char email[25];
    char district[20];
}ADMIN;					//���ڱ������Ա��Ϣ�Ľṹ 

typedef struct {
    char siteID[20];
    char area[20];
    char venue[20];
    char sportType[20];
    char intro[350];
    int minAge;
    int maxAge;
    int rent;
    int number;
}SITE;					//���ڱ��泡����Ϣ�Ľṹ 

typedef struct {
    char orderID[50];
    char orderDate[20];
    char siteID[20];
    char useDate[20];
    int timeInterval;
    int isOnTime;
    int sex;
}ORDER;					//���ڱ��涩����Ϣ�Ľṹ 

//���˵�����
void Customer(void);
void Admin(void);
int Registration(void);

//�û����ܺ���
int customer_Login(void);
void customer_Change(void);
void customer_Order(SITE *);
void customer_Search(void);
void customer_Cancel(void);
void customer_getSiteInformation(char *);

//����Ա���ܺ���
int admin_Login(void);
void admin_Change(void);
void admin_Search(void);
void admin_Arrange1(void);
void admin_Arrange2(void);
void admin_Statistics(void);
void admin_SexStatistics(void);
void admin_siteInformation(void);
void admin_addSite(void);

//�û���ѯ���ܺ���
void mainSearch(void);
void rentRank(void);
void bookingRank(void);
void search_Site(void);
void search_Gym(void);
void search_District(void);
void search_Hot(void);
void search_filterSites(int);

//��֤��ת�������˵ȹ��ܺ���
int inputValidation(char *);
int checkInputUsername(int);
void timeTransfer(int, char *);
int emailValid(char *);
void screenAvalableInterval(char *);
int total_day(int, int ,int);
int total_year_day(int ,int);


char choice[5];             //���ڶ����û��Ķ�ѡ���ѡ�������У��
char username[20];          //���ڱ����û��ĵ�¼�û���
int orderTimes;             //���ڱ��浥���û����ε�¼��Ԥ������

/* ��������ϵͳ�����˵�����ѡ���û���¼����������Ա��¼�������û�ע�ᡱ�Լ����˳�ϵͳ����Ȼ����ת����ͬ����Ӧ�������к������� */
int main()
{
    for(;;){
        printf("       ===========================\n");
        printf("           �ۺ��������ݹ���ϵͳ      \n");
        printf("       ===========================\n");
        printf("       1.�˿͵�¼                  \n");
        printf("       2.����Ա��¼                \n");
        printf("       3.�˿�ע��                  \n");
        printf("       4.�˳�ϵͳ                  \n");
        printf("       ===========================\n");
        printf("\n");
        printf("       ��ѡ������Ҫ�Ĳ���:");
        
        scanf("%s", choice);
        while(inputValidation(choice) != YES){      //����inputValidation()������ȷ��������ȷ
            printf("����������������롣\n");
            scanf("%s", choice);
        }
        switch (atoi(choice)) {
            case 1:
            	system("cls");
                Customer();         //��ת�û������˵�
                break;
            case 2:
            	system("cls");
                Admin();            //��ת����Ա�����˵�
                break;
            case 3:
            	system("cls");
                printf("����������ע����û���(6-10λ��ĸ���������)��");           //�����û�����ע�ᣬ����Registration�������������
                scanf("%s", username);
                while(Registration() == NO){
                    printf("����������ע����û���(6-10λ��ĸ���������)��");
                    scanf("%s", username);
                }
                printf("ע��ɹ����������½�����н�һ��������\n");
                break;
            case 4:
            	system("cls");
            	printf("       ================================\n");
        		printf("        ��л��ʹ���ۺ��������ݹ���ϵͳ  \n");
        		printf("       ================================\n");
                exit(1);            //�������У��˳�����
            default:
            	system("cls");
                printf("����������������롣\n");            //û�������ѡ�ĵ��ĸ�ѡ��������ʾ��Ҫ������ѡ��
        }
    }
    
    return 0;
}

/* �û������˵������Ƚ��е�¼������customer_Login������������
 Ȼ�����û������������л�����Ĳ����������û�ѡ����ת����Ӧ�ĺ�������һ���˵����к������� */
void Customer(void)
{
	printf ("�û���¼\n");
    printf("�������û�����");
    scanf("%s", username);
    if (customer_Login() == NO){            //����customer_Login��������ɵ�¼����
        printf("��¼ʧ�ܣ������ԡ�\n");
        return;
    }
    orderTimes = 0;             //��¼�ɹ���ʹԤ���������㣬ȷ���û�����Ԥ��
    system("cls");
    printf("       ===========================\n");
    printf("                 ��¼�ɹ���         \n");
    printf("       ===========================\n");
    for(;;){
    	mark1:
        printf("                  ���˵�\n");
        printf("       ===========================\n");
        printf("       1.���ز�ѯ��Ԥ��\n");
        printf("       2.������ѯ\n");
        printf("       3.������Ϣ����\n");
        printf("       4.�˳���¼\n");
        printf("       ===========================\n");
        printf("       ��ѡ����һ��������");
        scanf("%s", choice);
        while(inputValidation(choice) != YES){               //����inputValidation()������ȷ��������ȷ
            printf("����������������롣\n");
            scanf("%s", choice);
        }
        switch (atoi(choice)) {
            case 1:
            	system("cls");
                mainSearch();
                system("cls");
                break;
            case 2:
            	system("cls");
				mark2:
                printf("       ===========================\n");
                printf("        ��ѡ����Ҫ���е���һ������     \n");
                printf("       ===========================\n");
                printf("       1.��ѯ���ж���\n");
                printf("       2.ȡ������\n");
                printf("       3.������һ��\n");
                printf("       ===========================\n");
                printf("       \n");
                scanf("%s", choice);
                while(inputValidation(choice) != YES){
                    printf("����������������롣\n");
                    scanf("%s", choice);
                }
                switch(atoi(choice)){
                    case 1:
                    	system("cls");
                        customer_Search ();             //����customer_Search������������ѯ���еĶ���
                        goto mark2; 
                        break;
                    case 2:
                    	system("cls");
                        customer_Cancel ();             //����customer_Cancel������������ѯ��ȡ���Ķ�����������ѡ��ȡ��
                        goto mark2;
                        break;
                    case 3:
                    	system("cls");
                    	goto mark1;
                    	break;
                    default:
             		 	system("cls");
                        printf("����������������롣\n");
                        goto mark2;
                }
                break;
            case 3:
            	system("cls");
                customer_Change();                      //����customer_Change�����������鿴���ȵĸ�����Ϣ���Լ�����ѡ���޸ĸ�����Ϣ
                break;
            case 4:
            	system("cls");
                return;
            default:
				system("cls");
				printf("����������������롣\n") ; 
        }
    }
}

/* ����Ա�����˵������Ƚ��е�¼������admin_Login������������
 Ȼ�����û������������л�����Ĳ����������û�ѡ����ת����Ӧ�ĺ�������һ���˵����к������� */
void Admin(void)
{
	printf ("����Ա��¼\n");
    printf("�������û�����");
    scanf("%s", username);
    if (admin_Login() == NO){               //����admin_Login�������������е�¼����
        printf("��¼ʧ�ܣ������ԡ�\n");
        return;
    }
    system("cls");
    printf("       ===========================\n");
    printf("                 ��¼�ɹ���         \n");
    printf("       ===========================\n");
    for(;;){
    	
        printf("                  ���˵�\n");
        printf("       ===========================\n");
        printf("       1.Ԥ������\n");
        printf("       2.���ع���\n");
        printf("       3.������Ϣ����\n");
        printf("       4.�˳���¼\n");
        printf("       ===========================\n");
        printf("       ��ѡ����һ��������");
        scanf("%s", choice);
        while(inputValidation(choice) != YES){               //����inputValidation()������ȷ��������ȷ
            printf("����������������롣\n");
            scanf("%s", choice);
        }
        switch (atoi(choice)) {
            case 1:
            	system("cls");
                admin_Arrange1();               //��ת����Ԥ������˵�
                break;
            case 2:
            	system("cls");
                admin_Arrange2();               //��ת���볡�ع���˵�
                break;
            case 3:
            	system("cls");
                admin_Change();                 //����admin_Change�������鿴��ǰ���û���Ϣ��ѡ���޸Ĳ����û���Ϣ
                break;
            case 4:
            	system("cls");
                return;
             default:
             system("cls");
             printf("����������������롣\n");
             	
        }
    }
}

/* �ú������ڸ��û�ע�ᣬ��ȡ�û��Ļ�����Ϣ��д�뵽�µ��û���Ϣ�ļ��У�ͬʱ���ɿյ��û������ļ�
 �ú������ڵ�¼ʱ�����û������������û�ϣ��ע��ʱ�����ã��������˵���ѡ�����û�ע���ֱ�ӵ���
 �ú�������һ������ֵ����YES����NO����,����ȷ��ע���Ƿ�ɹ� */
int Registration(void)
{
	system("cls");
    int registerSuccess;
    int i, j;
    int isCorrect = YES;
    char recordedNames[20][11];
    char infoFileName[20];
    char orderFileName[20];
    char password1[20];
    char password2[20];
    char inputSex[5];
    char inputPhonenum[20];
    char inputEmail[30];
    FILE *Registry;
    FILE *newUsersInfoFile;
    FILE *newUsersOrderFile;
    CUSTOMER newUser;
    
    //����û���λ���Ƿ����Ҫ��
    if (strlen(username) > 10 || strlen(username) < 6){
        printf("�û�����������̣���ѡ��6-10λ���û������ԡ�\n");
        registerSuccess = NO;
        return registerSuccess;
    }
    
    //����û����Ƿ�ֻ������ĸ������
    for (i = 0; username[i] != '\0'; i++){
        if (!((username[i] >= '0' && username[i] <= '9') ||
              (username[i] >= 'A' && username[i] <= 'Z') ||
              (username[i] >= 'a' && username[i] <= 'z'))){
            printf("�û��������˳���ĸ������������ַ��������ԡ�\n");
            registerSuccess = NO;
            return registerSuccess;
        }
    }
    
    //����Ƿ����ظ����û���
    Registry = fopen("Registry_users.txt","r");
    if (Registry == NULL){
        printf("�û�ע����ʧ�ܡ�������\n");
        exit(1);
    }
    for (i = 0; feof(Registry) == 0; i++){
        fscanf(Registry, "%s ", recordedNames[i]);
    }
    fclose(Registry);
    for (j = 0; j < i; j++){
        if (strcmp(recordedNames[j], username) == 0){
            printf("�û����Ѵ��ڣ�ע��ʧ�ܣ������ԡ�\n");
            registerSuccess = NO;
            return registerSuccess;
        }
    }
    
    //���ͨ������ʼ��ȡ�û���Ϣ��������
    //¼���û���
    sprintf(newUser.ID, "%s", username);
    
    //¼�����벢���
    printf("�������������룺");
    scanf("%s", password1);
    printf("���ٴ������������룺");
    scanf("%s", password2);
    while (strcmp(password1,password2) != 0){
        printf("�����������벻һ�£�����������:");
        scanf("%s", password2);
    }
    sprintf(newUser.password, "%s", password2);
    
    //��ȡ����
    printf("����������������");
    scanf("%s", newUser.name);
    
    //��ȡ�Ա�
    printf("�����������Ա�(��/Ů)��");
    scanf("%s", inputSex);
    if (!strcmp(inputSex, "��")){
        newUser.sex = 1;
    } else {
        newUser.sex = 0;
    }
    
    //��ȡ����
    printf("�������������䣺");
    scanf("%d", &newUser.age);
    
    //��ȡ�绰����
    do{
        isCorrect = YES;
        printf("�����������ֻ����룺");
        scanf("%s",inputPhonenum);
        for(i=0;i<11;i++) {
            if(inputPhonenum[i]>'9'  ||  inputPhonenum[i]<'0'){
                isCorrect = NO;
                break;
            }
            if(strlen(inputPhonenum) != 11){
                isCorrect = NO;
                break;
            }
        }
        if(isCorrect == NO){
            printf("�ֻ������ʽ�������������롣\n");
        }
    }while(isCorrect == NO);
    sprintf(newUser.phone, "%s", inputPhonenum);
    
    //��ȡ�����ַ
    printf("���������ĵ��������ַ��");
    scanf("%s", inputEmail);
    isCorrect = emailValid(inputEmail);         //��ȡemailValid������У������������ַ�Ƿ����Ҫ��
    while(isCorrect == NO){
        printf("���������ʽ����ȷ�����������룺");
        scanf("%s", inputEmail);
        isCorrect = emailValid(inputEmail);
    }
    sprintf(newUser.email, "%s", inputEmail);
    
    //��ȡ����������Ϣ
    printf("������������������");
    scanf("%s", newUser.district);
    
    //������ע���û����ֵ500Ԫ����֤��ע���û����ܽ���Ԥ����
    newUser.money = 500.00;
    
    //�����û�����Ҫ����Ϣ�ļ��������ļ��������û�ע����м������û��û���
    sprintf(infoFileName, "%s.txt", username);
    sprintf(orderFileName, "%sorder.txt", username);
    newUsersOrderFile = fopen(orderFileName, "w");
    fclose(newUsersOrderFile);
    newUsersInfoFile = fopen(infoFileName, "w");
    fprintf(newUsersInfoFile, "%s %s %s %d %d %s %s %.2f %s",newUser.name, newUser.ID, newUser.password,
            newUser.sex, newUser.age, newUser.phone, newUser.email, newUser.money, newUser.district);
    fclose(newUsersInfoFile);
    Registry = fopen("Registry_users.txt", "a");
    fprintf(Registry, "%s ", newUser.ID);
    fclose(Registry);
    
    registerSuccess = YES;
    return registerSuccess;
}

/* �ú��������û��ĵ�¼У�飬�ȵ���checkInputUsername(int)����������ֵΪ1��������û����Ƿ���Ч
 �����û������ڣ��������û�����ע�ᣨ����Registration������
 ���û����ڣ����ȡ�û���Ϣ�ļ���������������У�飬�����λ��ᣬ������������󣬽�ֱ�ӽ�����ʾ���������˵�
 �ú�������һ������ֵ����YES����NO����������ȷ�ϵ�¼�Ƿ�ɹ�*/
int customer_Login(void)
{
    FILE *outFile;
    int i=0;
    int loginSuccess = NO;              //����ȷ�ϵ�¼�Ƿ�ɹ��ı���
    char inputPassword[20];
    char infoFileName[20];
    CUSTOMER user;
    
    //��������û����Ƿ���ڡ��������ڣ������û�����ע�ᡣ
    if(checkInputUsername(1) == NO){
        printf("��������û��������ڡ�\n");
        printf("�Ƿ���Ҫע���Ϊ���û�����y/n��");
        scanf("%s", choice);
        while(strcmp(choice, "y") != 0 && strcmp(choice, "n") != 0){            //У���û�������Ƿ��ǡ�y����n��������һ��
            printf("�������������'y'���ǣ���'n'����������ѡ��\n");
            printf("�Ƿ���Ҫע���Ϊ���û�����y/n��");
            scanf("%s", choice);
        }
        
        if (strcmp(choice, "y") == 0){
            while(Registration() == NO){                    //����û�ѡ��Ҫע�ᣬ�����Registration�������������ע��
                printf("����������ע����û���(6-10λ��ĸ���������)��");
                scanf("%s", username);
            }
            printf("ע��ɹ�����������е�¼��\n");
        }else{
            return loginSuccess;
        }
    }
    
    sprintf(infoFileName, "%s.txt", username);              //�����ض��ĸ�ʽ������Ӧ���û���Ϣ�ļ����������������������Ϣ�����û�������������ȶ�
    outFile = fopen(infoFileName, "r");
    if (outFile == NULL) {
        printf("�û��ļ���ʧ�ܡ�");
        exit(1);
    }
    fscanf(outFile, "%s %s %s %d %d %s %s %f %s", user.name, user.ID, user.password,
           &user.sex, &user.age, user.phone, user.email, &user.money, user.district);
    fclose(outFile);
    do {
        printf("�������������룺");
        scanf("%s", inputPassword);
        if(strcmp(user.password, inputPassword) == 0){
            loginSuccess = YES;                 //��������ȷ�������ѭ������¼�ɹ�
        }
        i++;                //i��¼�����������Ĵ���
    } while (i<3 && loginSuccess == NO);    //��i����3�����������������࣬��¼ʧ��
    return loginSuccess;
}

/* ���ڲ鿴�û���Ϣ�ҿ��������û��޸Ĳ�����Ϣ */
void customer_Change(void)
{
    int i = 0;
    int j = 0;
    int isCorrect = YES;
    int isValid;
    char infoFileName[20];
    char oriPassword[20];
    char newPassword1[20];
    char newPassword2[20];
    char address[20];
    char testPhone[20];
    char newEmail[25];
    
    FILE *outFile;
    CUSTOMER user;
    
    //���û��ļ��Ҽ���û��ļ��Ƿ�ɹ���
    sprintf(infoFileName, "%s.txt", username);
    outFile = fopen(infoFileName,"r");
    if (outFile == NULL) {
        printf("�û��ļ���ʧ�ܡ�");
        exit(1);
    }
    
    //��ȡ���û�����Ϣ
    fscanf(outFile, "%s %s %s %d %d %s %s %f %s", user.name, user.ID, user.password,
           &user.sex, &user.age, user.phone, user.email, &user.money, user.district);
    fclose(outFile);
    
    for(;;){
		printf("������%s\n�û�ID��%s\n�ֻ����룺%s\n�������䣺%s\n��ַ��%s\n��%.2fԪ\n",
           user.name, user.ID, user.phone, user.email, user.district,user.money); 
        printf("       ===========================\n");
        printf("           ��ѡ����Ҫ�޸ĵ���Ŀ     \n");
        printf("       ===========================\n");
        printf("       1.����\n");
        printf("       2.�ֻ�����\n");
        printf("       3.����\n");
        printf("       4.��ַ\n");
        printf("       5.������һ��\n");
        printf("       ===========================\n");
        printf("       \n");
        
        scanf("%s", choice);
        while(inputValidation(choice) != YES){
            printf("����������������롣\n");
            scanf("%s", choice);
        }
        switch (atoi(choice)) {
                
                //����û������������Ƿ���ԭ������ͬ�����3���Ƿ�����һ��
            case 1:
            	system("cls");
                printf("������ԭ���룺");
                scanf("%s", oriPassword);
                while(strcmp(oriPassword,user.password)!=0 && i<3){
                    printf("������ԭ���벻��������������:");
                    scanf("%s", oriPassword);
                    i++;
                }
                if(i == 3){
                    return;
                }
                
                //�������������������Ƿ���ͬ ���������ʱ������һ��
                printf("�����������룺");
                scanf("%s", newPassword1);
                printf("���ٴ����������룺");
                scanf("%s", newPassword2);
                while (strcmp(newPassword1,newPassword2) != 0 && j < 2){
                    printf("�����������벻��ͬ������������:");
                    scanf("%s", newPassword2);
                    j++;
                }
                if (j == 2){
                    printf("�޸�ʧ�ܣ������������������ࡣ");
                    return;
                } else {
                    printf("�޸ĳɹ���\n");
                    strcpy(user.password, newPassword2);
                }
                Sleep(3000);
                break;
            case 2:
     		 	system("cls");
                do{
                    isCorrect = YES;
                    printf("���������ֻ�����:");
                    scanf("%s",testPhone);
                    
                    //����û�������ֻ������Ƿ�ȫΪ����
                    for(i=0;i<11;i++) {
                        if(testPhone[i]>'9'  ||  testPhone[i]<'0'){
                            isCorrect = NO;
                            break;
                        }
                        
                        //����û�������ֻ����볤���Ƿ�Ϊ11λ
                        if(strlen(testPhone) != 11){
                            isCorrect = NO;
                            break;
                        }
                    }
                    if(isCorrect == NO){
                        printf("����������������롣\n");
                    }
                }while(isCorrect == NO);
                printf("�޸ĳɹ���\n");
                strcpy(user.phone,testPhone);
                Sleep(3000);
                break;
            case 3:
            	system("cls");
                printf("�����������䣺");
                scanf("%s", newEmail);
                isValid = emailValid(newEmail);
                while(isValid == 0 && i < 2){
                    printf("�����ʽ����ȷ�����������룺");
                    scanf("%s", newEmail);
                    isValid = emailValid(newEmail);
                    i++;
                }
                
                //�������θ�ʽ����ȷ�����䷵����һ��
                if (i == 2 && isValid == 0){
                    return;
                }else{
                    printf("�޸ĳɹ�\n");
                    strcpy(user.email, newEmail);
                }
                Sleep(3000);
                break;
            case 4:
            	system("cls");
                printf("�������µ�ַ��");
                scanf("%s", address);
                strcpy(user.district, address);
                printf("�޸ĳɹ�\n");
                Sleep(3000);
                break;
            case 5:
            	system("cls");
                return;
            default:
            	system("cls");
                printf("����������������롣\n");
				break;
        }
        
        FILE* inFile;
        inFile = fopen(infoFileName,"w");
        if (inFile == NULL) {
            printf("�޸�ʧ�ܣ��û��ļ���ʧ�ܡ�");
            exit(1);
        }
        fprintf(inFile, "%s %s %s %d %d %s %s %.2f %s", user.name, user.ID, user.password,
                user.sex, user.age, user.phone, user.email, user.money, user.district);
        fclose(inFile);
    }
}

/* �ú������ڼ���û��Ƿ�����Ԥ���������û��¶�������customer_getSiteInformation�����������ã���������ã���
 �����û����˽��˳�����Ϣ�Ϳ���ʱ��֮��Կ���ʱ�ν���Ԥ��
 ����һ��SITE������ָ�룬���ڻ���û�Ԥ���ĳ�����Ϣ��ÿ�ο��Զ�һ�����ص�һ��ʱ�ν���Ԥ����Ԥ���ɹ�����ٴμ����ͬ���صĿ���ʱ�ν����ٴ�Ԥ������������е��� */
void customer_Order(SITE *siteInfo)
{
    int i, j;
    int intervalNum[8];
    int notOnTime = 0;
    int timeInterval[8];
    int chosenInterval;
    int option;
    int canOrder = YES;
    char usersOrderFileName[20];
    char sitesOrderFileName[20];
    char usersInfoFileName[20];
    char sitesTimeIntervalName[20];
    char orderDate[30];
    char useDate[30];
    char orderID[30];
    char year1[10], month1[10], day1[10], hour1[10], minute1[10];           //���ڱ���Ԥ��ʱ���ʱ������
    char year2[10], month2[10], day2[10];               //���ڱ���ʹ��ʱ���ʱ������
    FILE *sitesOrderFile;               //���ݵĶ�����Ϣ�ļ�
    FILE *usersOrderFile;               //�û����˵Ķ�����Ϣ�ļ�
    FILE *usersInfoFile;                //�û���Ϣ�ļ�
    FILE *TEMP;                         //��screenAvalableInterval()��������ʱ�ļ�����˳�򱣴��ſ�Ԥ��ʱ�ε�ʱ�α��
    FILE *timeSituation;                //���ؿ���ʱ��״̬�ļ�
    CUSTOMER user;
    ORDER order;
    ORDER oldOrder[30];
    time_t orderTime, useTime;
    struct tm *ptr1, *ptr2;
    
    //׼����Ҫ�õ����ļ�
    sprintf(usersOrderFileName, "%sorder.txt", username);
    sprintf(usersInfoFileName, "%s.txt", username);
    sprintf(sitesOrderFileName, "%sorder.txt", siteInfo->siteID);
    
    sitesOrderFile = fopen(sitesOrderFileName, "a+");
    if (sitesOrderFile == NULL) {
        printf("���ض����ļ���ʧ�ܡ�\n");
        exit(1);
    }
    usersOrderFile = fopen(usersOrderFileName, "a+");
    if (usersOrderFile == NULL) {
        printf("�û������ļ���ʧ�ܡ�\n");
        exit(1);
    }
    usersInfoFile = fopen(usersInfoFileName, "r");
    if (usersInfoFile == NULL) {
        printf("�û���Ϣ�ļ���ʧ�ܡ�");
        exit(1);
    }
    rewind(usersOrderFile);
    
    fscanf(usersInfoFile, "%s %s %s %d %d %s %s %f %s", user.name, user.ID, user.password,
           &user.sex, &user.age, user.phone, user.email, &user.money, user.district);
    fclose(usersInfoFile);
    
    for (i = 0; feof(usersOrderFile) == 0; i++) {
        fscanf(usersOrderFile, "%s %s %s %s %d %d %d",
               oldOrder[i].orderID, oldOrder[i].orderDate, oldOrder[i].siteID,
               oldOrder[i].useDate, &oldOrder[i].timeInterval, &oldOrder[i].isOnTime, &oldOrder[i].sex);
    }
    
    //����Ƿ����Ԥ������
    //��鵥�ε�½Ԥ������
    if (orderTimes >= 3){
        printf("�Բ���ÿ���û�ÿ�ν���ԤԼ���Ρ�\n");
        canOrder = NO;
    }
    
    //���ʧ�Ŵ���
    for (j = 0; j < i-1; j++) {
        if (oldOrder[j].isOnTime == 0) {
            notOnTime++;
        }
    }
    if (notOnTime >= 3) {
        printf("�Բ�������ʧ�Ŵ����Ѵﵽ3�Ρ��޷��ٽ���ԤԼ��\n");
        canOrder = NO;
    }
    
    //����˻�����Ƿ�ԤԼ�˳���
    if (user.money < siteInfo->rent) {
        printf("�Բ��������˻����㣬�޷��Ըó��ݵĽ���ԤԼ��\n");
        canOrder = NO;
    }
    
    //����û������Ƿ�������������
    if (user.age < siteInfo->minAge || user.age > siteInfo->maxAge) {
        printf("�Բ����������䲻���ϸó��ݵ���������Ҫ���޷��Ըó��ݽ���ԤԼ��\n");
        canOrder = NO;
    }
    
    //����Ƿ����Ԥ�����������ԣ�����ʾ�û����Ƴ��������С�
    if (canOrder == NO) {
        printf("                     ===========================\n");
        printf("                               ԤԼʧ�ܣ�         \n");
        printf("                     ===========================\n");
        Sleep(3000);
        system("cls");
        return;
    }
    
    //���ļ��ж�����Ԥ���ĳ������
    TEMP = fopen("temp.txt", "r");
    for (i = 0; feof(TEMP) == 0; i++){
        fscanf(TEMP, "%d ", &intervalNum[i]);
    }
    
    printf("��ѡ����ҪԤԼ�ĳ��Σ�������0������һ������");
    scanf("%s", choice);
    while(inputValidation(choice) != YES || atoi(choice) > i){
        printf("�������������ѡ��\n");
        printf("��ѡ����ҪԤԼ�ĳ��Σ�������0������һ������");
        scanf("%s", choice);
    }
    if(atoi(choice) == 0){
    	system("cls"); 
    	return;
    } 
    system("cls");
    
    //���ɶ�����Ϣ
    //ת������ѡ���ʱ��
    option = atoi(choice);
    chosenInterval = intervalNum[option - 1];
    
    //���ݸ�ʽ���ɳ���ʹ��ʱ��
    orderTime = time(NULL);             //���Ԥ��ʱ��ϵͳʱ��
    ptr1 = localtime(&orderTime);       //��ϵͳʱ��ת����ֳɿ���ʹ�õ�ʱ��ṹ
    sprintf(year1, "%d" , ptr1->tm_year + 1900);
    sprintf(month1, "%d" , ptr1->tm_mon + 1);
    sprintf(day1, "%d" , ptr1->tm_mday);
    sprintf(hour1, "%d", ptr1->tm_hour);
    sprintf(minute1, "%d", ptr1->tm_min);
    //����·ݡ����ڡ�Сʱ�������Ƿ�Ϊ��λ�����������á�0������һλ����
    if(atoi(month1)<10 && atoi(month1)>0)
    {
        month1[1]=month1[0];
        month1[0]='0';
        month1[2]='\0';
    }
    if(atoi(day1)<10 && atoi(day1)>0)
    {
        day1[1]=day1[0];
        day1[0]='0';
        day1[2]='\0';
    }
    if(atoi(hour1)<10 && atoi(hour1)>=0)
    {
        hour1[1]=hour1[0];
        hour1[0]='0';
        hour1[2]='\0';
    }
    if(atoi(minute1)<10 && atoi(minute1)>=0)
    {
        minute1[1]=minute1[0];
        minute1[0]='0';
        minute1[2]='\0';
    }
    sprintf(orderDate, "%s:%s:%s:%s:%s", year1, month1, day1, hour1, minute1);
    sprintf(orderID, "%s%s", username, orderDate);
    
    //���ݸ�ʽ���ɳ���ʹ��ʱ��
    useTime = orderTime + AWEEK;            //ʹ��ʱ��ΪԤ��ʱ���һ��֮����һ��
    ptr2 = localtime(&useTime);
    sprintf(year2, "%d" , ptr2->tm_year + 1900);
    sprintf(month2, "%d" , ptr2->tm_mon + 1);
    sprintf(day2, "%d" , ptr2->tm_mday);
    
    //����·ݺ������Ƿ�Ϊ��λ
    if(atoi(month2)<10 && atoi(month2)>0)
    {
        month2[1]=month2[0];
        month2[0]='0';
        month2[2]='\0';
    }
    if(atoi(day2)<10 && atoi(day2)>0)
    {
        day2[1]=day2[0];
        day2[0]='0';
        day2[2]='\0';
    }
    
    sprintf(useDate, "%s:%s:%s", year2, month2, day2);
    sprintf(sitesTimeIntervalName, "%s%s%s%s.txt", siteInfo->siteID, year2, month2, day2);
    
    timeSituation = fopen(sitesTimeIntervalName, "r");
    if (timeSituation == NULL) {
        printf("Ԥ��ʧ�ܣ����ؿ���ʱ�μ���ļ���ʧ�ܡ�\n");
        exit(1);
    }
    
    //�Ѷ�����Ϣ�������붩���ṹ�������û��ͳ��ݵĶ�����¼�ļ�����¼����Ϣ
    sprintf(order.orderID, "%s", orderID);
    sprintf(order.orderDate, "%s",orderDate);
    sprintf(order.siteID, "%s", siteInfo->siteID);
    sprintf(order.useDate, "%s", useDate);
    order.timeInterval = chosenInterval;
    order.isOnTime = 1;
    order.sex = user.sex;
    
    for (j = 0; j < i - 1; j++) {
        if (!strcmp(oldOrder[j].useDate, order.useDate) && (oldOrder[j].timeInterval == order.timeInterval)) {
            canOrder = NO;
            printf("�Բ���ǰʱ������ԤԼ�˱�ĳ��أ��޷��ٽ���ԤԼ��\n");
            break;
        }
    }
    
    //����Ƿ����Ԥ�����������ԣ�����ʾ�û����Ƴ��������С�
    if (canOrder == NO) {
        printf("                     ===========================\n");
        printf("                              ԤԼʧ�ܣ�         \n");
        printf("                     ===========================\n");
        printf("�����Ǹó��ݿ���ʱ�Σ��볢��Ԥ���������ݣ�\n");				//�����û�����Ϊʱ�γ�ͻ��Ԥ��ʧ�ܣ� 
        screenAvalableInterval(siteInfo->siteID);
        customer_Order(siteInfo);
        system("cls");
        return;
    }
    
    //��Ԥ����Ϣ�ֱ�д���û��ͳ��صĶ����ļ���
    fprintf(usersOrderFile, "%s %s %s %s %d %d %d\n", order.orderID, order.orderDate,
            order.siteID, order.useDate, order.timeInterval, order.isOnTime, order.sex);
    fprintf(sitesOrderFile, "%s %s %s %s %d %d %d\n", order.orderID, order.orderDate,
            order.siteID, order.useDate, order.timeInterval, order.isOnTime, order.sex);
    fclose(usersOrderFile);
    fclose(sitesOrderFile);
    
    //���ĳ���ʱ�εĿ���״̬
    for (i = 0; feof(timeSituation) == 0; i++){
        fscanf(timeSituation, "%d ", &timeInterval[i]);
    }
    fclose(timeSituation);
    
    timeInterval[chosenInterval] = 0;
    
    timeSituation = fopen(sitesTimeIntervalName, "w");
    if (timeSituation == NULL) {
        printf("Ԥ��ʧ�ܣ����ؿ���ʱ�μ���ļ���ʧ�ܡ�\n");
        exit(1);
    }
    for (i = 0; i < 8; i++) {
        fprintf(timeSituation, "%d ", timeInterval[i]);
    }
    fclose(timeSituation);
    
    //�۳��û��˻��е�Ǯ
    user.money -= siteInfo->rent;
    usersInfoFile = fopen(usersInfoFileName, "w");
    if (usersInfoFile == NULL) {
        printf("Ԥ��ʧ�ܣ��û���Ϣ�ļ���ʧ�ܡ�");
        exit(1);
    }
    fprintf(usersInfoFile, "%s %s %s %d %d %s %s %.2f %s", user.name, user.ID, user.password,
            user.sex, user.age, user.phone, user.email, user.money, user.district);
    fclose(usersInfoFile);
    
    //��Ԥ����Ϣ��ӡ�������û���չʾ
    char literalInterval[20];
    timeTransfer(order.timeInterval, literalInterval);
    printf("                     ===========================\n");
    printf("                               ԤԼ�ɹ���         \n");
    printf("                     ===========================\n");
    printf("                            ����������ԤԼ��Ϣ��\n\n");
    printf("�������                       Ԥ������          ���ر��  ʹ������    ԤԼʱ���\n");
    printf("%-30s %-17s %-9s %-11s %-10s\n",
           order.orderID, order.orderDate, order.siteID, order.useDate, literalInterval);
    orderTimes++;
    
    //ѯ���û��Ƿ�Ҫ����Ԥ��ͬһ���ص������������ʱ�Σ����û�ѡ��y�������ٴε���screenAvaluable���������������ٴζԿ���ʱ�ν���Ԥ��
    printf("�Ƿ���Ҫ����ԤԼ�ó����������Σ�(y/n)");
    scanf("%s", choice);
    while(strcmp(choice, "y") != 0 && strcmp(choice, "n") != 0){
        printf("�������������'y'���ǣ���'n'����������ѡ��\n");
        printf("�Ƿ���Ҫ����ԤԼ�ó����������Σ�(y/n)");
        scanf("%s", choice);
    }
    if (strcmp(choice, "y") == 0){
    	system("cls");
        screenAvalableInterval(siteInfo->siteID);
        customer_Order(siteInfo);
    } else {
    	system("cls");
        return;
    }
}

/* �����û���ѯԤ����Ϣ���䴫�뺯���Ĳ���Ϊ�û��������ڴ򿪸��û���Ӧ���ļ� */
void customer_Search()
{
    int i = 0;
    char fileName[20];
    char string2[20];
    char interval[20];
    
    FILE *outFile;
    ORDER user[20];
    
    
    strcpy(fileName, username);
    strcpy(string2, "order.txt");
    strcat(fileName, string2);
    
    
    outFile = fopen(fileName, "r");
    if (outFile == NULL) {
        printf("�û��ļ���ʧ�ܡ�");
        exit(1);
    }
    printf("��Ķ�����ϢΪ��\n");
    printf("�������                       Ԥ������          ���ر��  ʹ������    ԤԼʱ���\n");
    
    while (fscanf(outFile, "%s %s %s %s %d %d %d\n", user[i].orderID, user[i].orderDate, user[i].siteID, user[i].useDate,
                  &user[i].timeInterval, &user[i].isOnTime, &user[i].sex) != EOF) {
        
        timeTransfer(user[i].timeInterval, interval);
        printf("%-30s %-17s %-9s %-11s %-10s\n", user[i].orderID, user[i].orderDate, user[i].siteID, user[i].useDate,
               interval);
        i++;
    }
    fclose(outFile);
}

/* �����û�ɾ��Ԥ����Ϣ���䴫�뺯���Ĳ���Ϊ�û��������ڴ򿪸��û���Ӧ���ļ� */
void customer_Cancel()
{
    typedef struct {
        char year[10];
        char month[10];
        char day[10];
    }DATE;
    
    typedef struct{
        int option;
        int row;
    }USERCANCEL;
    
    DATE customer[20];
    USERCANCEL count[20];
    ORDER user[20];
    
    int i;
    int j = 0;
    int k = 0;
    int m = 0;
    int num = 1;
    int sum = 0;
    int wantCancel;
    int orderCancel=0;
    char splitDate[60][10];
    char fileName[20];
    char string2[20];
    char *ptrDate;
    char interval[20];
    char substituteTime[20][20];
    char siteFile[25];
    char idCancel[50];
    char cancelConfirm[20];
    
    FILE *outFile;
    
    
    strcpy(fileName, username);
    strcpy(string2, "order.txt");
    strcat(fileName, string2);
    
    
    outFile = fopen(fileName, "r");
    if (outFile == NULL) {
        printf("�û��ļ���ʧ�ܡ�");
        exit(1);
    }
    
    for(i=0;feof(outFile)==0;i++) {
        
        fscanf(outFile, "%s %s %s %s %d %d %d\n", user[i].orderID, user[i].orderDate, user[i].siteID, user[i].useDate,
               &user[i].timeInterval, &user[i].isOnTime, &user[i].sex);
        
        strcpy(substituteTime[i], user[i].useDate);
        ptrDate = strtok(user[i].useDate, ":");
        
        //�������õ���ʹ��ʱ�䰴���ַ�����ʽ�������ַ������Ϊ�����գ������俽�����µ��ַ���������
        while (ptrDate != NULL){
            strcpy(splitDate[j], ptrDate);
            j++;
            ptrDate = strtok(NULL, ":");
        }
    }
    fclose(outFile);
    
    //���ַ�������д��ṹ
    i = 0;
    while(i < j-1){
        strcpy(customer[k].year, splitDate[i]);
        strcpy(customer[k].month, splitDate[i+1]);
        strcpy(customer[k].day, splitDate[i+2]);
        k++;
        i = i+3;
    }
    
    k = 0;//���³�ʼ��k��ֵ
    
    //����ʱ��ṹָ�벢��ȡ���ڵ�ϵͳʱ�佫�����ʱ��ṹ��
    struct tm *ptrTime;
    time_t t;
    t =time(NULL);
    ptrTime = localtime(&t);
    
    printf("���ɾ���Ķ����У�\n");
    printf("���к� �������                       Ԥ������          ���ر��  ʹ������    ԤԼʱ���\n");
    
    //ʹ�ú������������ʱ����Ԥ��ʹ��ʱ��֮���ʱ���
    for(m = 0;m <= j/3-1;m++){
        sum = total_year_day(ptrTime->tm_year + 1900,atoi(customer[m].year)) - total_day(ptrTime->tm_year + 1900,ptrTime->tm_mon + 1,ptrTime->tm_mday)
        + total_day(atoi(customer[m].year),atoi(customer[m].month),atoi(customer[m].day)) ;
        
        //ɸѡ����������ʱ�����һ���Ԥ��������Ϊ��ȡ������
        if(sum > 1){
            timeTransfer(user[m].timeInterval, interval);
            printf("%-6d %-30s %-17s %-9s %-11s %-10s\n",num, user[m].orderID, user[m].orderDate, user[m].siteID, substituteTime[m],
                   interval);
            
            //��¼�¿�ȡ���������û��ļ��������������������ض����
            count[k].option = num;
            count[k].row = m;
            num++;
            k++;
        }
    }
    if(k > 0){
        do{
            printf("��������Ҫɾ���Ķ������кţ�(����0���أ�");
            scanf("%s", choice);
            while(inputValidation(choice) != YES){
                printf("����������������롣\n");
                scanf("%s", choice);
            }
            wantCancel = atoi(choice);
            if(wantCancel == 0){
                return;
            }
            
            for(i = 0; i < num-1; i++){
                if(wantCancel == count[i].option){
                    orderCancel = count[i].row;
                }
            }
            printf("�Ƿ�ȷ��ɾ����1.ȷ�� 2.ȡ����");
            scanf("%s", cancelConfirm);
        }while (atoi(cancelConfirm) == 2);
        
        FILE *inFile;
        inFile = fopen(fileName, "w");
        if (inFile == NULL) {
            printf("�û��ļ���ʧ�ܡ�");
            exit(1);
        }
        
        //�����û��������ȡ����ţ��ڽ���Ϣд���û������ļ�ʱ������ѡ�����һ�е���Ϣ
        for(i=0;i<j/3;i++){
            if(i == orderCancel){
                continue;
            }
            fprintf(inFile, "%s %s %s %s %d %d %d\n", user[i].orderID, user[i].orderDate, user[i].siteID, substituteTime[i],
                    user[i].timeInterval, user[i].isOnTime, user[i].sex);
        }
        
        fclose(inFile);
        strcpy(idCancel, user[orderCancel].orderID);
        strcpy(siteFile, user[orderCancel].siteID);
        strcat(siteFile, "order.txt");
        outFile = fopen(siteFile, "r");
        if (outFile == NULL) {
            printf("�û��ļ���ʧ�ܡ�");
            exit(1);
        }
        for(i=0;feof(outFile)==0;i++) {
            
            fscanf(outFile, "%s %s %s %s %d %d %d", user[i].orderID, user[i].orderDate, user[i].siteID, user[i].useDate,
                   &user[i].timeInterval, &user[i].isOnTime, &user[i].sex);
        }
        fclose(outFile);
        
        inFile = fopen(siteFile, "w");
        if (inFile == NULL) {
            printf("�û��ļ���ʧ�ܡ�");
            exit(1);
        }
        
        //�ҵ����ض����ļ����û�ѡ��ɾ����������ͬ��һ��������д���ļ�ʱ������һ�е���Ϣ
        for(k=0;k<i;k++){
            if(strcmp(user[k].orderID, idCancel    )==0){
                continue;
            }
            fprintf(inFile, "%s %s %s %s %d %d %d\n", user[k].orderID, user[k].orderDate, user[k].siteID, substituteTime[k],
                    user[k].timeInterval, user[k].isOnTime, user[k].sex);
        }
        printf("ȡ���ɹ�\n");
    }
    else{
        printf("��û�п�ȡ���Ķ���\n");
    }
}

/* �ú������ڹ���Ա�ĵ�¼����δע�������ѡ��ע�ᡣͬʱ���Լ���Ƿ�Ϊ����Ա��¼����������ͨ�û�����ʹ��
 �ú�����һ��int���͵ķ���ֵ */
int admin_Login(void)
{
    FILE *outFile;
    int i=0;
    int loginSuccess = NO;
    char infoFileName[20];
    char inputPassword[20];
    ADMIN user;
    
    //��������û����Ƿ���ڡ��������ڣ������û�����ע�ᡣ
    if(checkInputUsername(2) == NO){
        printf("������Ĺ���Ա�û��������ڡ�\n");
        printf("��������µ�¼��\n");
        return loginSuccess;
    }
    
    sprintf(infoFileName, "%s.txt", username);            // �����ܵ���username�����ļ�infoFileName
    outFile = fopen(infoFileName, "r");
    if (outFile == NULL) {
        printf("�û��ļ���ʧ�ܡ�");
        exit(1);
    }
    fscanf(outFile, "%s %s %s %d %s %s %s", user.name, user.ID, user.password,
           &user.sex, user.phone, user.email, user.district);                        //������Ա��Ϣ��ȡ���������뵽���򿪵��ļ���
    fclose(outFile);
    do {                                                        // ��ѭ�����ڼ����Ƿ�Ϊ����Ա����ֹ��ͨ�û���¼
        printf("���������룺");
        scanf("%s", inputPassword);
        if(strcmp(user.password, inputPassword) == 0){
            loginSuccess = YES;
        }
        i++;
    }while(i<3 && loginSuccess == NO);
    return loginSuccess;
}

/* ���ڲ鿴�û���Ϣ�ҿ��������û��޸Ĳ�����Ϣ */
void admin_Change(void)
{
    ADMIN user;
    int isCorrect = YES;
    int isValid;
    int i = 0;
    int j = 0;
    char infoFileName[20];
    char oriPassword[20];
    char newPassword1[20];
    char newPassword2[20];
    char testPhone[20];
    char newEmail[20];
    
    FILE *outFile;
    sprintf(infoFileName, "%s.txt", username);
    outFile = fopen(infoFileName,"r");
    if (outFile == NULL) {
        printf("�û��ļ���ʧ�ܡ�");
        exit(1);
    }
    fscanf(outFile, "%s %s %s %d %s %s %s ", user.name, user.ID, user.password,
           &user.sex, user.phone, user.email, user.district);
    fclose(outFile);
    
    
    
    for(;;){
		printf("������%s\n�û�ID��%s\n�ֻ����룺%s\n�������䣺%s\n��ַ��%s\n",
           user.name, user.ID, user.phone, user.email, user.district);
        printf("       ===========================\n");
        printf("           ��ѡ����Ҫ�޸ĵ���Ŀ    \n");
        printf("       ===========================\n");
        printf("       1.����\n");
        printf("       2.�ֻ�����\n");
        printf("       3.����\n");
        printf("       4.������һ��\n");
        printf("       ===========================\n");
        printf("       \n");
        scanf("%s", choice);
        while(inputValidation(choice) != YES){
            printf("����������������롣\n");
            scanf("%s", choice);
        }
        switch(atoi(choice))
        {
            case 1:
            	system("cls");
                printf("������ԭ���룺");
                scanf("%s", oriPassword);
                while(strcmp(oriPassword,user.password)!=0 && i<3){
                    printf("������ԭ���벻��������������:");
                    scanf("%s", oriPassword);
                    i++;
                }
                if(i == 3){
                    return;
                }
                printf("�����������룺");
                scanf("%s", newPassword1);
                printf("���ٴ����������룺");
                scanf("%s", newPassword2);
                while (strcmp(newPassword1,newPassword2) != 0 && j < 2){
                    printf("�����������벻��ͬ������������:");
                    scanf("%s", newPassword2);
                    j++;
                }
                if (j == 2){
                    printf("�޸�ʧ�ܣ������������������ࡣ");
                    return;
                }else{
                    printf("�޸ĳɹ���\n");
                    strcpy(user.password, newPassword2);
                }
                Sleep(3000);
                break;
            case 2:
            	system("cls");
                do{
                    isCorrect = YES;
                    printf("���������ֻ�����:");
                    scanf("%s",testPhone);
                    for(i=0;i<11;i++) {
                        if(testPhone[i]>'9'  ||  testPhone[i]<'0'){
                            isCorrect = NO;
                            break;
                        }
                        if(strlen(testPhone) != 11){
                            isCorrect = NO;
                            break;
                        }
                    }
                    if(isCorrect == NO){
                        printf("����������������롣\n");
                    }
                }while(isCorrect == NO);
                printf("�޸ĳɹ���\n");
                strcpy(user.phone,testPhone);
                Sleep(3000);
                break;
            case 3:
            	system("cls");
                printf("�����������䣺");
                scanf("%s", newEmail);
                isValid = emailValid(newEmail);
                while(isValid == 0 && i < 2){
                    printf("�����ʽ����ȷ�����������룺");
                    scanf("%s", newEmail);
                    isValid = emailValid(newEmail);
                    i++;
                }
                if (i == 2 && isValid == 0){
                    return;
                }else{
                    printf("�޸ĳɹ�\n");
                    strcpy(user.email, newEmail);
                }
                Sleep(3000);
                break;
            case 4:
            	system("cls");
                return;
            default:
            	system("cls");
                printf("����������������롣\n");
                break; 
        }
        
        FILE* inFile;
        inFile = fopen(infoFileName,"w");
        if (inFile == NULL){
            printf("�޸�ʧ�ܣ��û��ļ���ʧ�ܡ�");
            exit(1);
        }
        
        fprintf(inFile, "%s %s %s %d %s %s %s ", user.name, user.ID, user.password,
                user.sex, user.phone, user.email, user.district);
        fclose(inFile);
    }
}

/* �ú���Ϊ����Ա�Ĺ��ܲ˵���ͨ�����¼������ĵ�����ʵ�ֶ��û�Ԥ���Ĺ���
 �ú����޷���ֵ */
void admin_Arrange1()
{
    for(;;){
        printf("                  ���˵�\n");
        printf("       ===========================\n");
        printf("       1.�鿴�û�Ԥ�����\n");
        printf("       2.ͳ���û�Ԥ����Ϣ\n");
        printf("       3.������һ��\n");
        printf("       ===========================\n");
        printf("       ��ѡ����һ��������");
        scanf("%s", choice);
        while(inputValidation(choice) != YES)                // ������
        {
            printf("����������������롣\n");
            scanf("%s", choice);
        }
        switch (atoi(choice))
        {
            case 1:
            	system("cls");
                admin_Search();                            // �ɲ鿴�û���Ԥ����Ϣ
                break;
            case 2:
            	system("cls");
                admin_Statistics();                        //  ���û�Ԥ����Ϣ���м���
                break;
            case 3:
            	system("cls");
                return;                                    // ������һ��
            default:
            	system("cls");
                printf("����������������룡\n");
                break;
        }
    }
}

/* �ú���Ϊ����Ա�Ĺ��ܲ˵���ͨ�����¼������ĵ�����ʵ�ֶԳ��صĹ���
 �ú����޷���ֵ */
void admin_Arrange2()
{
    for(;;){
        printf("                  ���˵�\n");
        printf("       ===========================\n");
        printf("       1.���ز�ѯ\n");
        printf("       2.�������\n");
        printf("       3.������һ��\n");
        printf("       ===========================\n");
        printf("       ��ѡ����һ��������");
        scanf("%s", choice);
        while(inputValidation(choice) != YES){            // ������
            printf("����������������롣\n");
            scanf("%s", choice);
        }
        switch (atoi(choice)) {
            case 1:
            	system("cls");
                admin_siteInformation();                // ����ĳ�����Ϣ��ѯ
                break;
            case 2:
            	system("cls");
                admin_addSite();                        // �������һ�����صĲ���
                break;
            case 3:
            	system("cls");
                return;                                 // ������һ��
             default:
			 	system("cls");
				printf("����������������룡\n");
				break; 
        }
    }
}

/* ������Ա�˺Ų鿴�û�Ԥ����� ���������ض����ļ��ж�ȡ������Ϣ */
void admin_Search()
{
    int op=0;
    int orderNum = 0;
    int j = 0;
    int sitesNum = 0;
    char sitesOrderFileName[20];
    FILE *adminRegistry = NULL;
    FILE *sitesOrderFile;
    SITE recordedSites[10];
    ORDER orders[50];
    
    if(strcmp("admin01",username)==0)//��������¼�Ĺ���Ա�˺�
    {
        op=1;
        adminRegistry = fopen("Registry_sites_admin01.txt", "r");
        if (adminRegistry == NULL){          //�����Ƿ�ɹ����ļ�
            printf("����ע����ʧ�ܡ�������\n");
            exit(1);
        }
    }
    else if(strcmp("admin02",username)==0)//��������¼�Ĺ���Ա�˺�
    {
        op=2;
        adminRegistry = fopen("Registry_sites_admin02.txt", "r");
        if (adminRegistry == NULL){          //�����Ƿ�ɹ����ļ�
            printf("����ע����ʧ�ܡ�������\n");
            exit(1);
        }
    }
    else if(strcmp("admin03",username)==0)//��������¼�Ĺ���Ա�˺�
    {
        op=3;
        adminRegistry = fopen("Registry_sites_admin03.txt", "r");
        if (adminRegistry == NULL){          //�����Ƿ�ɹ����ļ�
            printf("����ע����ʧ�ܡ�������\n");
            exit(1);
        }
    }
    
    while (fscanf(adminRegistry, "%s %s %s %s %s %d %d %d %d ",recordedSites[sitesNum].siteID, recordedSites[sitesNum].area, recordedSites[sitesNum].venue,recordedSites[sitesNum].sportType,recordedSites[sitesNum].intro,&recordedSites[sitesNum].minAge, &recordedSites[sitesNum].maxAge, &recordedSites[sitesNum].rent, &recordedSites[sitesNum].number) != EOF) {       //��ȡ����Ա�������еĳ�����
        sitesNum++;
    }
    fclose(adminRegistry);
    
    for (j = 0; j < sitesNum; j++) {
        sprintf(sitesOrderFileName, "%sorder.txt", recordedSites[j].siteID);
        sitesOrderFile = fopen(sitesOrderFileName, "r");
        if (sitesOrderFile == NULL){          //�����Ƿ�ɹ����ļ�
            printf("���ض����ļ���ʧ�ܡ�������\n");
            exit(1);
        }
        printf("%s�Ķ����У�\n", recordedSites[j].sportType);
        while (fscanf(sitesOrderFile, "%s %s %s %s %d %d %d", orders[orderNum].orderID, orders[orderNum].orderDate, orders[orderNum].siteID,orders[orderNum].useDate, &orders[orderNum].timeInterval, &orders[orderNum].isOnTime, &orders[orderNum].sex) !=EOF){
            printf("%s %s %s %s %d %d %d\n",orders[orderNum].orderID, orders[orderNum].orderDate, orders[orderNum].siteID,orders[orderNum].useDate, orders[orderNum].timeInterval,orders[orderNum].isOnTime,orders[orderNum].sex);//��ȡÿһ������
            orderNum++;//��¼��������
        }
        fclose(sitesOrderFile);
        if(orderNum==0){
            printf("û�ж���\n");
        }
        orderNum = 0;
    }
}

/* ������Ա�˺ţ�ͳ�ƶ���������о����ض��������������ð������Ԥ����Ӫҵ�� */
void admin_Statistics()
{
    int op = 0;
    int sitesNum = 0;
    int j = 0;
    int count = 0;
    int t,k,m;
    char flag;
    char filename[20];
    SITE recordedSites[10];
    FILE *adminRegistry = NULL;
    FILE *sitesOrder;
    
    if(strcmp("admin01",username)==0)//��������¼�Ĺ���Ա�˺�
    {
        op=1;
        adminRegistry = fopen("Registry_sites_admin01.txt", "r");
        if (adminRegistry == NULL){          //�����Ƿ�ɹ����ļ�
            printf("����ע����ʧ�ܡ�������\n");
            exit(1);
        }
    }
    else if(strcmp("admin02",username)==0)//��������¼�Ĺ���Ա�˺�
    {
        op=2;
        adminRegistry = fopen("Registry_sites_admin02.txt", "r");
        if (adminRegistry == NULL){          //�����Ƿ�ɹ����ļ�
            printf("����ע����ʧ�ܡ�������\n");
            exit(1);
        }
    }
    else if(strcmp("admin03",username)==0)//��������¼�Ĺ���Ա�˺�
    {
        op=3;
        adminRegistry = fopen("Registry_sites_admin03.txt", "r");
        if (adminRegistry == NULL){          //�����Ƿ�ɹ����ļ�
            printf("����ע����ʧ�ܡ�������\n");
            exit(1);
        }
    }
    
    while (fscanf(adminRegistry, "%s %s %s %s %s %d %d %d %d ",recordedSites[sitesNum].siteID, recordedSites[sitesNum].area,           recordedSites[sitesNum].venue,recordedSites[sitesNum].sportType,recordedSites[sitesNum].intro,&recordedSites[sitesNum].minAge, &recordedSites[sitesNum].maxAge, &recordedSites[sitesNum].rent, &recordedSites[sitesNum].number) != EOF) {       //��ȡ����Ա�������еĳ�����
        sitesNum++;
    }
    fclose(adminRegistry);
    
    for(;;){
    	
        int *num = (int *)malloc(sitesNum * sizeof(int));//������̬����
        int *snum = (int *)malloc(sitesNum * sizeof(int));
        for (j = 0; j < sitesNum; j++) {
            *(snum + j) = j;
        }
        printf("       ===========================\n");
        printf("       1.Ԥ��������\n");
        printf("       2.���ܻ�ӭ���˶���/Ů\n");
        printf("       3.Ӫҵ������\n");
        printf("       4.������һ��\n");
        printf("       ===========================\n");
        printf("       ��ѡ����һ��������");
        scanf("%s", choice);
        while(inputValidation(choice) != YES){
            printf("����������������롣\n");//������
            scanf("%s", choice);
        }
        switch(atoi(choice)){
            case 1:
            	system("cls");
                for (j = 0; j < sitesNum; j++){
                    sprintf(filename, "%sorder.txt", recordedSites[j].siteID);
                    sitesOrder = fopen(filename, "r");
                    if (sitesOrder == NULL){
                        printf("�ļ���ʧ�ܡ�\n");
                        exit(1);
                    }
                    while(!feof(sitesOrder)){
                        flag = fgetc(sitesOrder);
                        if(flag == '\n')
                            count++;//��ȡ����
                    }
                    *(num+j) = count;
                    count = 0;
                    fclose(sitesOrder);
                }
                
                for(m = 0; m < sitesNum-1; ++m){
                    for(j = 0;j < sitesNum - 1 - m; ++j){
                        if(num[j]>num[j+1]){
                            t=num[j];
                            k=snum[j];
                            num[j]=num[j+1];
                            snum[j]=snum[j+1];
                            num[j+1]=t;
                            snum[j+1]=k; //ð������
                        }
                    }
                }
                printf("��Ԥ�����ɵ͵�������Ϊ�� \n");
                
                for (j = 0; j < sitesNum; j++) {
                    printf("���أ�%-15s", recordedSites[*(snum + j)].sportType);
                    printf("Ԥ����Ϊ�� %d\n", num[j]);
                }
                
                free(num);//�ͷ��ڴ�
                free(snum);
                break;
                
            case 2:
            	system("cls");
                admin_SexStatistics();
                break;
            case 3:
            	system("cls");
                for (j = 0; j < sitesNum; j++){
                    sprintf(filename, "%sorder.txt", recordedSites[j].siteID);
                    sitesOrder = fopen(filename, "r");
                    if (sitesOrder == NULL){
                        printf("�ļ���ʧ�ܡ�\n");
                        exit(1);
                    }
                    while(!feof(sitesOrder)){
                        flag = fgetc(sitesOrder);
                        if(flag == '\n')
                            count++;
                    }
                    *(num+j) = count;
                    count = 0;
                    fclose(sitesOrder);
                }
                
                for(m = 0; m < sitesNum-1; ++m){//ð������
                    for(j = 0;j < sitesNum - 1 - m; ++j){
                        if(num[j] * recordedSites[snum[j]].rent > num[j+1]  * recordedSites[snum[j]].rent){
                            t=num[j];
                            k=snum[j];
                            num[j]=num[j+1];
                            snum[j]=snum[j+1];
                            num[j+1]=t;
                            snum[j+1]=k;
                        }
                    }
                }
                printf("��Ӫҵ���ɵ͵�������Ϊ�� \n");
                
                for (j = 0; j < sitesNum; j++) {
                    printf("���أ�%-15s", recordedSites[*(snum + j)].sportType);
                    printf("Ӫҵ��Ϊ�� %dԪ\n", num[j] * recordedSites[snum[j]].rent);
                }
                free(num);
                free(snum);//�ͷ��ڴ�
                break;
            case 4:
            	system("cls");
                return;
            default:
     		 	system("cls");
                printf("����������������룡\n");
        }
    }
}

/* �ֱ�ͳ����Ů������Ϣ��ʹ�����ֵ�����ҵ� ����Ů�Էֱ����Ԥ���ĳ��� */
void admin_SexStatistics()
{
    int ordersNum = 0;          //��Ӧ���صĶ�����
    int sitesNum = 0;           //���еĳ�����
    int i, j, k;
    int max1, max2, maxNum;
    int count = 0;                  //��¼ĳһ�Ա𶩵���Ϊ��ĳ�����
    char filename[20];
    SITE recordedSites[20];
    ORDER siteOrder[50];
    FILE *Registry = NULL;
    FILE *sitesOrderFile;
    
    Registry = fopen("Registry_sites.txt", "r");               //���ܵ�ע���
    if (Registry == NULL){          //�����Ƿ�ɹ����ļ�
        printf("����ע����ʧ�ܡ�������\n");
        exit(1);
    }
    
    while (fscanf(Registry, "%s %s %s %s %s %d %d %d %d ",recordedSites[sitesNum].siteID, recordedSites[sitesNum].area,           recordedSites[sitesNum].venue,recordedSites[sitesNum].sportType,recordedSites[sitesNum].intro,&recordedSites[sitesNum].minAge, &recordedSites[sitesNum].maxAge, &recordedSites[sitesNum].rent, &recordedSites[sitesNum].number) != EOF) {       //��ȡ����Ա�������еĳ�����
        sitesNum++;
    }
    fclose(Registry);
    
    int *mNum = (int *)malloc(sitesNum * sizeof(int));          //���ݵõ��ĳ�������������Ԥ������������
    int *fNum = (int *)malloc(sitesNum * sizeof(int));          //���ݵõ��ĳ���������Ů��Ԥ������������
    //    int *snum = (int *)malloc(sitesNum * sizeof(int));          //�����±�
    for (i = 0; i < sitesNum; i++) {
        mNum[i] = 0;
        fNum[i] = 0;
    }
    
    for ( i = 0; i < sitesNum; i++){
        sprintf(filename, "%sorder.txt", recordedSites[i].siteID);
        sitesOrderFile = fopen(filename, "r");
        if (sitesOrderFile == NULL){//�����Ƿ���ļ�
            printf("%s�����ļ���ʧ�ܡ�", recordedSites[i].siteID);
            exit(1);
        }
        
        while (fscanf(sitesOrderFile, "%s %s %s %s %d %d %d", siteOrder[ordersNum].orderID, siteOrder[ordersNum].orderDate, siteOrder[ordersNum].siteID, siteOrder[ordersNum].useDate, &siteOrder[ordersNum].timeInterval, &siteOrder[ordersNum].isOnTime, &siteOrder[ordersNum].sex) !=EOF){
            ordersNum++;
        }
        fclose(sitesOrderFile);
        if(sitesNum == 0){
            printf("%sû�ж���\n", recordedSites[i].sportType);
        }
        
        for(j = 0; j < ordersNum; j++){
            if (siteOrder[j].sex == 1) {
                mNum[i]++;//���Զ�������
            }
            else if (siteOrder[j].sex == 0) {
                fNum[i]++;//Ů�Զ�������
            }
        }
        ordersNum = 0;
    }
    
    /* �ҳ�������ĳ���:�ҳ�mNum[]����������Ӧ�ĳ��� */
    max1=mNum[0];
    maxNum = 0;
    for(k = 1; k < sitesNum; k++) {
        if( mNum[k]>=max1 ){
            max1 = mNum[k];
            maxNum = k;//�ҳ����ֵ������
        }
    }
    
    for (i = 0; i < sitesNum; i++) {
        if (mNum[i] == 0) {
            count++;//���Զ���������
        }
    }
    
    if(count < sitesNum){
        printf("���Կ�����ĳ����ǣ�%s\n", recordedSites[maxNum].sportType);
    } else {
        printf("û�����ԵĶ������޷�ͳ�Ʒ���������ĳ��ء�\n");
    }
    count = 0;          //ʹcount���㣬׼������Ů�Զ������ؼ���
    
    /* �ҳ�Ů����ĳ���:�ҳ�fNum[]����������Ӧ�ĳ��� */
    max2=fNum[0];
    maxNum = 0;
    for(k = 1; k < sitesNum; k++) {
        if( fNum[k] >= max2 ){
            max2 = fNum[k];
            maxNum = k;
        }
    }
    for (i = 0; i < sitesNum; i++) {
        if (fNum[i] == 0) {
            count++;//Ů�Զ���������
        }
    }
    
    if(count < sitesNum){
        printf("Ů�Կ�����ĳ����ǣ�%s\n", recordedSites[maxNum].sportType);
    } else {
        printf("û��Ů�ԵĶ������޷�ͳ�Ʒ���Ů����ĳ��ء�\n");
    }
}

/* ������Ϣ��ѯ���� */
void admin_siteInformation()
{
    FILE *adminRegistry = NULL;
    SITE sites[10];
    int op = 0;
    int i = 0;
    
    if(strcmp("admin01",username)==0)
    {
        op=1;
        adminRegistry = fopen("Registry_sites_admin01.txt", "r");
        if (adminRegistry == NULL){          //�����Ƿ�ɹ����ļ�
            printf("����ע����ʧ�ܡ�������\n");
            exit(1);
        }
    }
    else if(strcmp("admin02",username)==0)
    {
        op=2;
        adminRegistry = fopen("Registry_sites_admin02.txt", "r");
        if (adminRegistry == NULL){          //�����Ƿ�ɹ����ļ�
            printf("����ע����ʧ�ܡ�������\n");
            exit(1);
        }
    }
    else if(strcmp("admin03",username)==0)
    {
        op=3;
        adminRegistry = fopen("Registry_sites_admin03.txt", "r");
        if (adminRegistry == NULL){          //�����Ƿ�ɹ����ļ�
            printf("����ע����ʧ�ܡ�������\n");
            exit(1);
        }
    }
    
    printf("��������ĳ����У�\n");
    while(fscanf(adminRegistry,"%s %s %s %s %s %d %d %d %d", sites[i].siteID, sites[i].area, sites[i].venue, sites[i].sportType,
                 sites[i].intro, &sites[i].minAge, &sites[i].maxAge, &sites[i].rent, &sites[i].number) != EOF){//��ȡ�����ļ�
        printf("����%d\n", i+1);
        printf("���ر��: %s\n��������%s\n�������ݣ�%s\n�����ʺϵ��˶����ͣ�%s\n�ó����ʺϵ��˶���飺%s\n׼�����䣺%d-%d\n���%dRMB/2h\n",
               sites[i].siteID, sites[i].area, sites[i].venue, sites[i].sportType,
               sites[i].intro, sites[i].minAge, sites[i].maxAge, sites[i].rent);
        printf("\n");
        i++;
    }
    fclose(adminRegistry);
}

/* �����û����صĲ�ѯ�����е��� search_Site()��search_Gym()��search_District()��
 rentRank()��bookingRank() ��search_Hot()����ʵ�ֲ�ͬ��ʽ�Ĳ�ѯ���ܡ� */
void mainSearch(void)
{
    for(;;)
    {
        printf("       ===========================\n");
        printf("             ��ѡ��������ʽ     \n");
        printf("       ===========================\n");
        printf("       1.���������Ʋ�ѯ\n");
        printf("       2.���������Ʋ�ѯ\n");
        printf("       3.�����������ѯ\n");
        printf("       4.������������г���\n");
        printf("       5.��Ԥ�����������г���\n");
        printf("       6.���ų����Ƽ�\n");
        printf("       7.������һ��\n");
        printf("       ===========================\n");
        printf("       \n");
        
        scanf("%s", choice);
        while(inputValidation(choice) != YES)
        {
            printf("����������������롣\n");
            scanf("%s", choice);
        }
        switch(atoi(choice))
        {
            case 1:
            	system("cls");
                search_Site();
                break;
            case 2:
            	system("cls");
                search_Gym();
                break;
            case 3:
            	system("cls");
                search_District();
                break;
            case 4:
            	system("cls");
                rentRank();
                break;
            case 5:
            	system("cls");
                bookingRank();
                break;
            case 6:
            	system("cls");
                search_Hot();
                break;
            case 7:
            	system("cls");
                return;      //����forѭ�������ص��ú�����
            default:
            	system("cls");
                printf("�������\n");
                break;
        }
    }
}

/* �ú���������ʾ��һ�����������ĳһ�����ص���ϸ��Ϣ��ͬʱ������һ������screenAvalableInterval��Ϊ�û���ʾ��ǰ��Ԥ����ʱ�ε�ͬʱ���û�����ѡ�����Ԥ������ѡ���˳�
    �ú���û�з���ֵ */
void customer_getSiteInformation(char* siteID)
{
    
    SITE Site;
    char fileName[11];
    FILE* outFile = NULL;
    
    sprintf(fileName, "%s.txt", siteID);        // ���ļ���д��fileName����
    outFile = fopen(fileName, "r");
    
    fscanf(outFile,"%s %s %s %s %s %d %d %d %d", Site.siteID, Site.area, Site.venue, Site.sportType,
           Site.intro, &Site.minAge, &Site.maxAge, &Site.rent, &Site.number);                // ��������Ϣ���ļ��ж�ȡ����
    printf("���ر��: %s\n��������%s\n�������ݣ�%s\n�����ʺϵ��˶����ͣ�%s\n�ó����ʺϵ��˶���飺%s\n׼�����䣺%d-%d\n���%dRMB/2h\n",
           Site.siteID, Site.area, Site.venue, Site.sportType,Site.intro, Site.minAge, Site.maxAge, Site.rent);                    // ��������Ϣ��ӡ����Ļ��
    fclose(outFile);
    
    printf("����ʱ�������������: \n");
    screenAvalableInterval(siteID);            // ���ú��� screenAvalableInterval����ʾ�ó���Ԥ�����
    for(;;){
        printf("�����ԣ�\n");
        printf("1. �Կ���ʱ��ν���Ԥ��\n");
        printf("2. ������һ���˵�\n");
        printf("��ѡ������Ҫ�Ĳ�����");
        scanf("%s", choice);
        while(inputValidation(choice) != YES){
            printf("����������������롣\n");
            scanf("%s", choice);
        }
        switch (atoi(choice)) {
            case 1:
                customer_Order(&Site);
                return;
            case 2:
          		system("cls");
                return;
            default:
                printf("����������������롣\n");
        }
    }
}


/* �ú�������ʵ�ְ�������򳡵ع��ܡ� ���е��ò�ѯ������Ϣ��customer_getSiteInformation()�����͹��˲�ѯ�����search_filterSites������*/
void rentRank(void)
{
    int k,t;            //�����м����
    int m = 0;
    int i = 0;          //���ڼ�¼���еĳ�������
    int j = 0;
    FILE *siteRegistry;
    SITE recordedSites[20];
    
    //�򿪳���ע���
    siteRegistry = fopen("Registry_sites.txt", "r");
    while (siteRegistry == NULL) {
        printf("��ѯʧ�ܣ�����ע����ʧ�ܡ�\n");
    }
    while (fscanf(siteRegistry, "%s %s %s %s %s %d %d %d %d", recordedSites[i].siteID, recordedSites[i].area, recordedSites[i].venue, recordedSites[i].sportType,recordedSites[i].intro,&recordedSites[i].minAge, &recordedSites[i].maxAge, &recordedSites[i].rent, &recordedSites[i].number) != EOF) {       //�������г��ص�������Ϣ
        i++;                //��ȡ����ע����ļ������ݼ�¼������ȷ������������
    }
    fclose(siteRegistry);
    
    int *num = (int *)malloc(i*sizeof(int));            //���ݳ�������i������Ӧ��С�����飬������Ԫ��Ϊ�����ֵ ��
    int *snum = (int *)malloc(i*sizeof(int));           //������Ԫ��Ϊ���ص���š�
    for (j = 0; j < i; j++) {
        num[j] = recordedSites[j].rent;                 //��ÿ�����ص����������顣
    }
    for (j = 0; j < i; j++) {
        snum[j] = j;
    }
    
    //ð������
    for(m = 0; m < i-1; ++m){
        for(j = 0;j < i - 1 - m; ++j){
            if(num[j]>num[j+1]){
                t=num[j];               //���������ֵ��ͬʱ�������ص���š�
                k=snum[j];
                num[j]=num[j+1];
                snum[j]=snum[j+1];
                num[j+1]=t;
                snum[j+1]=k;
            }
        }
    }
    
mark1:              //ѡ�񳡵صķ��ص�
    //��������ĳ������Ƽ����
    printf("���ذ���������ɵ͵��ߣ�Ϊ��\n");
    for (j = 0; j < i; j++) {
        printf("����:%-15s���:%d\n", recordedSites[snum[j]].sportType, recordedSites[snum[j]].rent);
    }
    
    //�û�ѡ���Ƿ�鿴���ݾ�����Ϣ ��
    printf("    �Ƿ���Ҫ����ѯ��������޿�Ԥ��ʱ��ν���ɸѡ(��Ԥ��)��\n");
    printf("             1.��          2.�񣨷�����һ����         \n");
    scanf("%s", choice);
    while(inputValidation(choice) != YES){
        printf("����������������롣\n");
        printf("     �Ƿ���Ҫ����ѯ��������޿�Ԥ��ʱ��ν���ɸѡ����Ԥ������\n");
        printf("             1.��          2.�񣨷�����һ����        \n");
        scanf("%s", choice);
    }
    switch(atoi(choice))
    {
        case 1:
            search_filterSites(0);      //���ø����Ƿ��п�Ԥ��ʱ���ɸѡ���صĺ���
            goto mark1;         //�û�ѡ�񷵻���һ��ѡ�
        case 2:
            free(num);
            free(snum);
            system("cls");
            return;             //������һ����
        default:
            printf("�������\n");
            goto mark1;         //�û�������󣬷��ص�ѡ���Ƿ�鿴������Ϣ
    }
}

/* �ú������ڰ�Ԥ������ѯ���ܡ� ���е��ò�ѯ������Ϣ��customer_getSiteInformation()�����͹��˲�ѯ�����search_filterSites������ */
void bookingRank(void)
{
    int k,t;
    char flag;          //'\n'���
    char filename[20];
    int count = 0;      //����������������
    int i = 0;          //���ڼ�¼���еĳ�������
    int j = 0;
    int m = 0;
    FILE *siteRegistry;
    FILE *sitesOrder;
    SITE recordedSites[20];         //���ݽṹ������
    
    //�򿪳���ע���
    siteRegistry = fopen("Registry_sites.txt", "r");
    while (siteRegistry == NULL) {
        printf("��ѯʧ�ܣ�����ע����ʧ�ܡ�\n");
    }
    while (fscanf(siteRegistry, "%s %s %s %s %s %d %d %d %d", recordedSites[i].siteID, recordedSites[i].area, recordedSites[i].venue, recordedSites[i].sportType,recordedSites[i].intro,&recordedSites[i].minAge, &recordedSites[i].maxAge, &recordedSites[i].rent, &recordedSites[i].number) != EOF) {       //�������г��ص�������Ϣ
        i++;                //��¼������Ŀ
    }
    fclose(siteRegistry);
    
    int *num = (int *)malloc(i*sizeof(int));            //���ݳ�������i������Ӧ��С�����飬������Ԫ��ΪԤ���� ��
    int *snum = (int *)malloc(i*sizeof(int));           //������Ԫ��Ϊ���ص���š�
    for (j = 0; j < i; j++) {
        *(snum + j) = j;
    }
    
    for (j = 0; j < i; j++){
        sprintf(filename, "%sorder.txt", recordedSites[j].siteID);
        sitesOrder = fopen(filename, "r");
        if (sitesOrder == NULL){
            printf("�ļ���ʧ�ܡ�\n");
            exit(1);
        }
        while(!feof(sitesOrder)){               //ͳ���ļ���������ΪԤ����
            flag = fgetc(sitesOrder);           //��flag���
            if(flag == '\n')
                count++;
        }
        *(num+j) = count;
        count = 0;
        fclose(sitesOrder);
    }
    
    //ð������
    for(m = 0; m < i-1; ++m){
        for(j = 0;j < i - 1 - m; ++j){
            if(num[j]>num[j+1]){                //����Ԥ������ֵ��ͬʱ�����������
                t=num[j];
                k=snum[j];
                num[j]=num[j+1];
                snum[j]=snum[j+1];
                num[j+1]=t;
                snum[j+1]=k;
            }
        }
    }
    
    
    //������붨�������ĳ�������
mark1:               // ������󷵻ص�
    printf("��Ԥ�����ɵ͵�������Ϊ�� \n");
    for (j = 0; j < i; j++) {
        printf("���أ�%-15s", recordedSites[*(snum + j)].sportType);
        printf("Ԥ����Ϊ��%d\n", num[j]);
    }
    
    printf("    �Ƿ���Ҫ����ѯ��������޿�Ԥ��ʱ��ν���ɸѡ����Ԥ������\n");
    printf("             1.��          2.�񣨷�����һ����         \n");
    scanf("%s", choice);
    while(inputValidation(choice) != YES){
        printf("����������������롣\n");
        printf("     �Ƿ���Ҫ����ѯ��������޿�Ԥ��ʱ��ν���ɸѡ����Ԥ������\n");
        printf("             1.��          2.��(������һ��)         \n");
        scanf("%s", choice);
    }
    switch(atoi(choice))
    {
        case 1:
            search_filterSites(0);      //���ø����Ƿ��п�Ԥ��ʱ���ɸѡ���صĺ���
            goto mark1;
        case 2:
        	system("cls");
            free(num);              //�ͷŵ�������ڴ�ռ�
            free(snum);
            return;
        default:
            printf("�������\n");
            goto mark1;             //�û��������󣬷��ص�ѯ���û��Ƿ�鿴���ؾ�����Ϣ
    }
}

/* �ú�������ʵ�ְ����ز�ѯ���ܡ� ���е��ò�ѯ������Ϣ��customer_getSiteInformation()�����͹��˲�ѯ�����search_filterSites������ */
void search_Site(void)
{
    int i = 0;
    int j = 0;
    int option;
    FILE *siteRegistry;
    SITE recordedSites[20];         //���ؽṹ������
    
    siteRegistry = fopen("Registry_sites.txt", "r");
    while (siteRegistry == NULL) {
        printf("��ѯʧ�ܣ�����ע����ʧ�ܡ�\n");
    }
    while (fscanf(siteRegistry, "%s %s %s %s %s %d %d %d %d", recordedSites[i].siteID, recordedSites[i].area, recordedSites[i].venue, recordedSites[i].sportType,recordedSites[i].intro,&recordedSites[i].minAge, &recordedSites[i].maxAge, &recordedSites[i].rent, &recordedSites[i].number) != EOF) {       //�������г��ص�������Ϣ
        i++;                //��¼������Ŀ
    }
    fclose(siteRegistry);
    for(;;){
        printf("              ���г�������\n");
        printf("       ===========================\n");
        /* �����ṹ���������г��������û�ѡ�� */
        for (j = 0; j < i; j++) {           //ע��i�������ǳ��ݵ�������j��������±꣬��0��ʼ
            printf("       %d. %s\n", j+1, recordedSites[j].sportType);
        }
        printf("       ===========================\n");
        printf("�Ƿ���Ҫ����ѯ��������޿�Ԥ��ʱ��ν���ɸѡ����Ԥ������(y/n)");
        scanf("%s", choice);
        while(strcmp(choice, "y") != 0 && strcmp(choice, "n") != 0){
            printf("�������������'y'���ǣ���'n'����������ѡ��\n");
            printf("�Ƿ���Ҫ����ѯ��������޿�Ԥ��ʱ��ν���ɸѡ����Ԥ������(y/n)");
            scanf("%s", choice);
        }
        if (!strcmp("y", choice)){
            search_filterSites(0);          //���ú������Բ�ѯ�������ɸѡ��Ԥ��
        } else {
            printf("��ѡ�������һ���˽��Ԥ���ĳ���(�����롰0��������һ��):");
            scanf("%s", choice);
            while(inputValidation(choice) != YES || atoi(choice) > i){
                printf("����������������롣\n");
                printf("��ѡ�񳡵�: ");
                scanf("%s", choice);
            }
            option = atoi(choice);          //��ѡ��ת��Ϊ������Ϊ�����û�ѡ��ĳ�����Ϣ������
            if (option == 0){
            	system("cls");
                return;                     //����mainSearch()����
            }
            system("cls");
            customer_getSiteInformation(recordedSites[option - 1].siteID);          //�ҳ��û�ѡ�����Ӧ�����ڽṹ�����е�λ�ã��ѳ���ID���ݸ���һ������
        }
    }
}

/* �ú�������ʵ�ְ����ݲ�ѯ���ܡ� ���е��ò�ѯ������Ϣ��customer_getSiteInformation()�����͹��˲�ѯ�����search_filterSites������ */
void search_Gym(void)
{
    int i = 0;
    int j = 0;
    int option;
    FILE *siteRegistry;
    SITE recordedSites[20];
    
    for(;;)
    {
    mark1:
        printf("             ��ѡ�񳡹�     \n");
        printf("1.������������\n2.ɳ��������\n3.�긣������\n4.����\n");
        scanf("%s", choice);
        while(inputValidation(choice) != YES){
            printf("����������������롣\n");
            scanf("%s", choice);
        }
        switch(atoi(choice))
        {
            case 1:
            	system("cls");
                //�򿪳���ע����ļ�
                siteRegistry = fopen("Registry_sites_admin01.txt", "r");
                while (siteRegistry == NULL) {
                    printf("��ѯʧ�ܣ�����ע����ʧ�ܡ�\n");
                }
                while (fscanf(siteRegistry, "%s %s %s %s %s %d %d %d %d", recordedSites[i].siteID, recordedSites[i].area, recordedSites[i].venue, recordedSites[i].sportType,recordedSites[i].intro,&recordedSites[i].minAge, &recordedSites[i].maxAge, &recordedSites[i].rent, &recordedSites[i].number) != EOF) {       //�������г��ص�������Ϣ
                    i++;             //������������
                }
                fclose(siteRegistry);
            mark2:                   //�鿴���峡�ݵ���Ϣ��ķ��ص�
                printf("          �����������ݳ�������\n");
                printf("       ===========================\n");
                /* �����ṹ���������г��������û�ѡ�� */
                for (j = 0; j < i; j++) {           //ע��i�������ǳ��ݵ�������j��������±�
                    printf("       %d. %s\n", j+1, recordedSites[j].sportType);
                }
                printf("       ===========================\n");
                printf("�Ƿ���Ҫ����ѯ��������޿�Ԥ��ʱ��ν���ɸѡ����Ԥ������(y/n)");
                scanf("%s", choice);
                while(strcmp(choice, "y") != 0 && strcmp(choice, "n") != 0){
                    printf("�������������'y'���ǣ���'n'����������ѡ��\n");
                    printf("�Ƿ���Ҫ����ѯ��������޿�Ԥ��ʱ��ν���ɸѡ����Ԥ������(y/n)");
                    scanf("%s", choice);
                }
                if (!strcmp("y", choice)){
                    search_filterSites(1);          //���ú������Բ�ѯ�������ɸѡ��Ԥ��
                    goto mark2;
                } else {
                    printf("��ѡ�������һ���˽��Ԥ���ĳ���(�����롰0��������һ��):");
                    scanf("%s", choice);
                    while(inputValidation(choice) != YES || atoi(choice) > i){
                        printf("����������������롣\n");
                        printf("��ѡ�������һ���˽��Ԥ���ĳ���(�����롰0��������һ��):");
                        scanf("%s", choice);
                    }
                    option = atoi(choice);          //��ѡ��ת��Ϊ������Ϊ�����û�ѡ��ĳ�����Ϣ������
                    if (option == 0){
                        i = 0;         //������Ŀ����
                        system("cls");
                        goto mark1;       //���أ����½��г���ѡ��
                    }
                    system("cls");
                    customer_getSiteInformation(recordedSites[option - 1].siteID);          //�ҳ��û�ѡ�����Ӧ�����ڽṹ�����е�λ�ã��ѳ���ID���ݸ���һ������
                    goto mark2;
                }
                
            case 2:
            	system("cls");
                siteRegistry = fopen("Registry_sites_admin02.txt", "r");
                while (siteRegistry == NULL) {
                    printf("��ѯʧ�ܣ�����ע����ʧ�ܡ�\n");
                }
                while (fscanf(siteRegistry, "%s %s %s %s %s %d %d %d %d", recordedSites[i].siteID, recordedSites[i].area, recordedSites[i].venue, recordedSites[i].sportType,recordedSites[i].intro,&recordedSites[i].minAge, &recordedSites[i].maxAge, &recordedSites[i].rent, &recordedSites[i].number) != EOF) {       //�������г��ص�������Ϣ
                    i++;
                }
                fclose(siteRegistry);
                
            mark3:                  //���ص�
                printf("           ɳ�������ݳ�������\n");
                printf("       ===========================\n");
                /* �����ṹ���������г��������û�ѡ�� */
                for (j = 0; j < i; j++) {           //ע��i�������ǳ��ݵ�������j��������±�
                    printf("       %d. %s\n", j+1, recordedSites[j].sportType);
                }
                printf("       ===========================\n");
                printf("�Ƿ���Ҫ����ѯ��������޿�Ԥ��ʱ��ν���ɸѡ����Ԥ������(y/n)");
                scanf("%s", choice);
                while(strcmp(choice, "y") != 0 && strcmp(choice, "n") != 0){
                    printf("�������������'y'���ǣ���'n'����������ѡ��\n");
                    printf("�Ƿ���Ҫ����ѯ��������޿�Ԥ��ʱ��ν���ɸѡ����Ԥ������(y/n)");
                    scanf("%s", choice);
                }
                if (!strcmp("y", choice)){
                    search_filterSites(2);          //���ú������Բ�ѯ�������ɸѡ��Ԥ��
                    goto mark3;
                } else {
                    printf("��ѡ�������һ���˽��Ԥ���ĳ���(�����롰0��������һ��):");
                    scanf("%s", choice);
                    while(inputValidation(choice) != YES || atoi(choice) > i){
                        printf("����������������롣\n");
                        printf("��ѡ�������һ���˽��Ԥ���ĳ���(�����롰0��������һ��):");
                        scanf("%s", choice);
                    }
                    option = atoi(choice);          //��ѡ��ת��Ϊ������Ϊ�����û�ѡ��ĳ�����Ϣ������
                    if (option == 0){
                        i = 0;
                        system("cls");
                        goto mark1;
                    }
                    system("cls");
                    customer_getSiteInformation(recordedSites[option - 1].siteID);          //�ҳ��û�ѡ�����Ӧ�����ڽṹ�����е�λ�ã��ѳ���ID���ݸ���һ������
                    goto mark3;
                }
                
            case 3:
            	system("cls");
                siteRegistry = fopen("Registry_sites_admin03.txt", "r");
                while (siteRegistry == NULL) {
                    printf("��ѯʧ�ܣ�����ע����ʧ�ܡ�\n");
                }
                while (fscanf(siteRegistry, "%s %s %s %s %s %d %d %d %d", recordedSites[i].siteID, recordedSites[i].area, recordedSites[i].venue, recordedSites[i].sportType,recordedSites[i].intro,&recordedSites[i].minAge, &recordedSites[i].maxAge, &recordedSites[i].rent, &recordedSites[i].number) != EOF) {       //�������г��ص�������Ϣ
                    i++;
                }
                fclose(siteRegistry);
            mark4:
                /* �����ṹ���������г��������û�ѡ�� */
                printf("           �긣�����ݳ�������\n");
                printf("       ===========================\n");
                for (j = 0; j < i; j++) {           //ע��i�������ǳ��ݵ�������j��������±�
                    printf("       %d. %s\n", j+1, recordedSites[j].sportType);
                }
                printf("       ===========================\n");
                printf("�Ƿ���Ҫ����ѯ��������޿�Ԥ��ʱ��ν���ɸѡ(��Ԥ��)��(y/n)");
                scanf("%s", choice);
                while(strcmp(choice, "y") != 0 && strcmp(choice, "n") != 0){
                    printf("�������������'y'���ǣ���'n'����������ѡ��\n");
                    printf("�Ƿ���Ҫ����ѯ��������޿�Ԥ��ʱ��ν���ɸѡ(��Ԥ��)��(y/n)");
                    scanf("%s", choice);
                }
                if (!strcmp("y", choice)){
                    search_filterSites(3);          //���ú������Բ�ѯ�������ɸѡ��Ԥ��
                    goto mark4;
                } else {
                    printf("��ѡ�������һ���˽��Ԥ���ĳ���(�����롰0��������һ��):");
                    scanf("%s", choice);
                    while(inputValidation(choice) != YES || atoi(choice) > i){
                        printf("����������������롣\n");
                        printf("��ѡ�������һ���˽��Ԥ���ĳ���(�����롰0��������һ��):");
                        scanf("%s", choice);
                    }
                    option = atoi(choice);          //��ѡ��ת��Ϊ������Ϊ�����û�ѡ��ĳ�����Ϣ������
                    if (option == 0){
                        i = 0;
                        system("cls");
                        goto mark1;
                    }
                    system("cls");
                    customer_getSiteInformation(recordedSites[option - 1].siteID);          //�ҳ��û�ѡ�����Ӧ�����ڽṹ�����е�λ�ã��ѳ���ID���ݸ���һ������
                    goto mark4;
                }
            case 4:
            	system("cls");
                return;
            default:
            	system("cls");
                printf("�������\n");
                break;
        }
    }
}

/* �ú�������ʵ�ְ�������ѯ���ܡ� ���е��ò�ѯ������Ϣ��customer_getSiteInformation()�����͹��˲�ѯ�����search_filterSites������ */
void search_District(void)
{
    int i = 0;
    int j = 0;
    int option;
    FILE *siteRegistry;
    SITE recordedSites[20];
    
    for(;;)
    {
    mark1:
        printf("             ��ѡ������     \n");
        printf("1.������\n2.ɳ��\n3.�긣\n4.����\n");
        scanf("%s", choice);
        while(inputValidation(choice) != YES){
            printf("����������������롣\n");
            printf("             ��ѡ������     \n");
            printf("1.������\n2.ɳ��\n3.�긣\n4.����\n");
            scanf("%s", choice);
        }
        switch(atoi(choice))
        {
            case 1:
            	system("cls");
                //�򿪳���ע����ļ�
                siteRegistry = fopen("Registry_sites_admin01.txt", "r");
                while (siteRegistry == NULL) {
                    printf("��ѯʧ�ܣ�����ע����ʧ�ܡ�\n");
                }
                while (fscanf(siteRegistry, "%s %s %s %s %s %d %d %d %d", recordedSites[i].siteID, recordedSites[i].area, recordedSites[i].venue, recordedSites[i].sportType,recordedSites[i].intro,&recordedSites[i].minAge, &recordedSites[i].maxAge, &recordedSites[i].rent, &recordedSites[i].number) != EOF) {       //�������г��ص�������Ϣ
                    i++;            //������Ŀ����
                }
                fclose(siteRegistry);
            mark2:                  //���ص�
                /* �����ṹ���������г��������û�ѡ�� */
                printf("            �����������ݳ�������\n");
                printf("       ===========================\n");
                for (j = 0; j < i; j++) {           //ע��i�������ǳ��ݵ�������j��������±�
                    printf("       %d. %s\n", j+1, recordedSites[j].sportType);
                }
                printf("       ===========================\n");
                printf("�Ƿ���Ҫ����ѯ��������޿�Ԥ��ʱ��ν���ɸѡ(��Ԥ��)��(y/n)");
                scanf("%s", choice);
                while(strcmp(choice, "y") != 0 && strcmp(choice, "n") != 0){
                    printf("�������������'y'���ǣ���'n'����������ѡ��\n");
                    printf("�Ƿ���Ҫ����ѯ��������޿�Ԥ��ʱ��ν���ɸѡ����Ԥ������(y/n)");
                    scanf("%s", choice);
                }
                if (!strcmp("y", choice)){
                    search_filterSites(1);          //���ú������Բ�ѯ�������ɸѡ��Ԥ��
                    goto mark2;
                } else {
                    printf("��ѡ�������һ���˽��Ԥ���ĳ���(�����롰0��������һ��):");
                    scanf("%s", choice);
                    while(inputValidation(choice) != YES || atoi(choice) > i){
                        printf("����������������롣\n");
                        printf("��ѡ�������һ���˽��Ԥ���ĳ���(�����롰0��������һ��):");
                        scanf("%s", choice);
                    }
                    option = atoi(choice);          //��ѡ��ת��Ϊ������Ϊ�����û�ѡ��ĳ�����Ϣ������
                    if (option == 0){
                        i = 0;
                        system("cls");
                        goto mark1;
                    }
                    system("cls");
                    customer_getSiteInformation(recordedSites[option - 1].siteID);          //�ҳ��û�ѡ�����Ӧ�����ڽṹ�����е�λ�ã��ѳ���ID���ݸ���һ������
                    goto mark2;
                }
                
            case 2:
            	system("cls");
                siteRegistry = fopen("Registry_sites_admin02.txt", "r");
                while (siteRegistry == NULL) {
                    printf("��ѯʧ�ܣ�����ע����ʧ�ܡ�\n");
                }
                while (fscanf(siteRegistry, "%s %s %s %s %s %d %d %d %d", recordedSites[i].siteID, recordedSites[i].area, recordedSites[i].venue, recordedSites[i].sportType,recordedSites[i].intro,&recordedSites[i].minAge, &recordedSites[i].maxAge, &recordedSites[i].rent, &recordedSites[i].number) != EOF) {       //�������г��ص�������Ϣ
                    i++;
                }
                fclose(siteRegistry);
            mark3:
                printf("             ɳ�������ݳ�������\n");
                printf("       ===========================\n");
                /* �����ṹ���������г��������û�ѡ�� */
                for (j = 0; j < i; j++) {           //ע��i�������ǳ��ݵ�������j��������±�
                    printf("       %d. %s\n", j+1, recordedSites[j].sportType);
                }
                printf("       ===========================\n");
                printf("�Ƿ���Ҫ����ѯ��������޿�Ԥ��ʱ��ν���ɸѡ(��Ԥ��)��(y/n)");
                scanf("%s", choice);
                while(strcmp(choice, "y") != 0 && strcmp(choice, "n") != 0){
                    printf("�������������'y'���ǣ���'n'����������ѡ��\n");
                    printf("�Ƿ���Ҫ����ѯ��������޿�Ԥ��ʱ��ν���ɸѡ(��Ԥ��)��(y/n)");
                    scanf("%s", choice);
                }
                if (!strcmp("y", choice)){
                    search_filterSites(2);          //���ú������Բ�ѯ�������ɸѡ��Ԥ��
                    goto mark3;
                } else {
                    printf("��ѡ�������һ���˽��Ԥ���ĳ���(�����롰0��������һ��):");
                    scanf("%s", choice);
                    while(inputValidation(choice) != YES || atoi(choice) > i){
                        printf("����������������롣\n");
                        printf("��ѡ�������һ���˽��Ԥ���ĳ���(�����롰0��������һ��):");
                        scanf("%s", choice);
                    }
                    option = atoi(choice);          //��ѡ��ת��Ϊ������Ϊ�����û�ѡ��ĳ�����Ϣ������
                    if (option == 0){
                        i = 0;
                        system("cls");
                        goto mark1;
                    }
                    system("cls");
                    customer_getSiteInformation(recordedSites[option - 1].siteID);          //�ҳ��û�ѡ�����Ӧ�����ڽṹ�����е�λ�ã��ѳ���ID���ݸ���һ������
                    goto mark3;
                }
                
            case 3:
            	system("cls");
                siteRegistry = fopen("Registry_sites_admin03.txt", "r");
                while (siteRegistry == NULL) {
                    printf("��ѯʧ�ܣ�����ע����ʧ�ܡ�\n");
                }
                while (fscanf(siteRegistry, "%s %s %s %s %s %d %d %d %d", recordedSites[i].siteID, recordedSites[i].area, recordedSites[i].venue, recordedSites[i].sportType,recordedSites[i].intro,&recordedSites[i].minAge, &recordedSites[i].maxAge, &recordedSites[i].rent, &recordedSites[i].number) != EOF) {       //�������г��ص�������Ϣ
                    i++;
                }
                fclose(siteRegistry);
            mark4:
                printf("             �긣�����ݳ�������\n");
                printf("       ===========================\n");
                /* �����ṹ���������г��������û�ѡ�� */
                for (j = 0; j < i; j++) {           //ע��i�������ǳ��ݵ�������j��������±�
                    printf("       %d. %s\n", j+1, recordedSites[j].sportType);
                }
                printf("       ===========================\n");
                printf("�Ƿ���Ҫ����ѯ��������޿�Ԥ��ʱ��ν���ɸѡ(��Ԥ��)��(y/n)");
                scanf("%s", choice);
                while(strcmp(choice, "y") != 0 && strcmp(choice, "n") != 0){
                    printf("�������������'y'���ǣ���'n'����������ѡ��\n");
                    printf("�Ƿ���Ҫ����ѯ��������޿�Ԥ��ʱ��ν���ɸѡ(��Ԥ��)��(y/n)");
                    scanf("%s", choice);
                }
                if (!strcmp("y", choice)){
                    search_filterSites(3);          //���ú������Բ�ѯ�������ɸѡ��Ԥ��
                    goto mark4;
                } else {
                    printf("��ѡ�������һ���˽��Ԥ���ĳ���(�����롰0��������һ��):");
                    scanf("%s", choice);
                    while(inputValidation(choice) != YES || atoi(choice) > i){
                        printf("����������������롣\n");
                        printf("��ѡ�������һ���˽��Ԥ���ĳ���(�����롰0��������һ��):");
                        scanf("%s", choice);
                    }
                    option = atoi(choice);          //��ѡ��ת��Ϊ������Ϊ�����û�ѡ��ĳ�����Ϣ������
                    if (option == 0){
                        i = 0;
                        system("cls");
                        goto mark1;
                    }
                    system("cls");
                    customer_getSiteInformation(recordedSites[option - 1].siteID);          //�ҳ��û�ѡ�����Ӧ�����ڽṹ�����е�λ�ã��ѳ���ID���ݸ���һ������
                    goto mark4;
                }
                
            case 4:
            	system("cls");
                return;              //���� mianSearch()����
            default:
            	system("cls");
                printf("�������\n");
                break;
        }
    }
}

/* �ú�������ʵ�����ų����Ƽ����ܡ� ���е��ò�ѯ������Ϣ��customer_getSiteInformation()������ */
void search_Hot(void)
{
    int k,t;
    char flag;              //'\n'���
    char filename[20];
    int count = 0;      //����������������
    int m = 0;
    int i = 0;          //���ڼ�¼���еĳ�������
    int j = 0;
    FILE *siteRegistry;
    FILE *sitesOrder;
    SITE recordedSites[20];
    
    siteRegistry = fopen("Registry_sites.txt", "r");
    while (siteRegistry == NULL) {
        printf("��ѯʧ�ܣ�����ע����ʧ�ܡ�\n");
    }
    while (fscanf(siteRegistry, "%s %s %s %s %s %d %d %d %d", recordedSites[i].siteID, recordedSites[i].area, recordedSites[i].venue, recordedSites[i].sportType,recordedSites[i].intro,&recordedSites[i].minAge, &recordedSites[i].maxAge, &recordedSites[i].rent, &recordedSites[i].number) != EOF) {       //�������г��ص�������Ϣ
        i++;
    }
    fclose(siteRegistry);
    
    int *num = (int *)malloc(i*sizeof(int));                //���ݳ�������i������Ӧ��С�����飬������Ԫ��ΪԤ���� ��
    int *snum = (int *)malloc(i*sizeof(int));               //������Ԫ��Ϊ���ص���š�
    for (j = 0; j < i; j++) {
        *(snum + j) = j;
    }
    
    for (j = 0; j < i; j++){
        sprintf(filename, "%sorder.txt", recordedSites[j].siteID);
        sitesOrder = fopen(filename, "r");
        if (sitesOrder == NULL){
            printf("�ļ���ʧ�ܡ�\n");
            exit(1);
        }
        while(!feof(sitesOrder)){               //ͳ���ļ���������ΪԤ����
            flag = fgetc(sitesOrder);           //��flag���
            if(flag == '\n')
                count++;
        }
        *(num+j) = count;
        count = 0;
        fclose(sitesOrder);
    }
    
    //ð������
    for(m = 0; m < i-1; ++m){
        for(j = 0;j < i - 1 - m; ++j){
            if(num[j]>num[j+1]){                //����Ԥ������ֵ��ͬʱ�����������
                t=num[j];
                k=snum[j];
                num[j]=num[j+1];
                snum[j]=snum[j+1];
                num[j+1]=t;
                snum[j+1]=k;
            }
        }
    }
    
    printf("��ǰ���ų����ǣ� %s�� �Ѿ���%d��Ԥ�����ó��أ�\n", recordedSites[snum[i-1]].sportType, num[i-1]);
    customer_getSiteInformation(recordedSites[snum[i-1]].siteID);
    
    free(num);          //�ͷŵ�������ڴ�ռ�
    free(snum);
}

/* �ú������ڼ���û����룬����Ҫ�û�����������ѡ���ʱ����ã�ȷ���û�����������ֶ�û����������ĸ */
int inputValidation(char *input)
{
    int i;
    int isRightInput = NO;          //����ȷ�������Ƿ��д�ı�־����
    for (i = 0; input[i] != '\0'; i++) {    //��������Ƿ�ֻ��������
        if ((input[i] >= '0') && (input[i] <= '9')) {
            isRightInput = YES;
        }else{
            isRightInput = NO;
            break;
        }
    }
    
    return isRightInput;
}

/* �ú������ڼ���û���¼ʱ������û����Ƿ���Ч���Ѿ�ע��������ǵǼǵĳ��ݹ���Ա��
 �ú�����Ҫ����һ�������������ж����������͵ĵ�¼���Ӷ��򿪲�ͬ�ġ�ע��������
 �ú���������һ�����Ͳ�������YES����NO����������ȷ���û�������Ч�� */
int checkInputUsername(int type)
{
    int i = 0, j = 0;
    int isAnExistingUser = NO;          //����ȷ���û����Ƿ���ڵı�־
    char recordedNames[20][11];         //������ʱ������ע���û��û����Ķ�ά����
    FILE *Registry;
    if (type == 1){                     //�����¼����Ϊ��1������Ϊ�û���¼�����û��ġ�ע���
        Registry = fopen("Registry_users.txt","r");
        if (Registry == NULL){
            printf("�û�ע����ʧ�ܡ�������\n");
            exit(1);
        }
    } else {                            //�����¼����Ϊ��������2��������Ϊ����Ա��¼���򿪹���Ա�ġ�ע���
        Registry = fopen("Registry_admins.txt","r");
        if (Registry == NULL){
            printf("����Աע����ʧ�ܡ�������\n");
            exit(1);
        }
    }
    
    for (i = 0; feof(Registry) == 0; i++){          //��ȡ���е�ע������û���
        fscanf(Registry, "%s ", recordedNames[i]);
    }
    fclose(Registry);
    
    for (j = 0; j < i; j++){                        //�������û�����������ע���ע�������бȶԣ�ȷ��������û����Ƿ����
        if (strcmp(recordedNames[j], username) == 0){
            isAnExistingUser = YES;
            break;
        }
    }
    
    return isAnExistingUser;
}

//�������б��Ϊ1-7��ʱ���ת��Ϊֱ��ʱ�䲢�����ַ���ָ�룬������ֱ�Ϊʱ��α���Լ� �ַ���ָ��
void timeTransfer(int number, char *interval)
{
    switch(number){
        case 0:
            strcpy(interval, "06:00-08:00");
            break;
        case 1:
            strcpy(interval, "08:00-10:00");
            break;
        case 2:
            strcpy(interval, "10:00-12:00");
            break;
        case 3:
            strcpy(interval, "12:00-14:00");
            break;
        case 4:
            strcpy(interval, "14:00-16:00");
            break;
        case 5:
            strcpy(interval, "16:00-18:00");
            break;
        case 6:
            strcpy(interval, "18:00-20:00");
            break;
        case 7:
            strcpy(interval, "20:00-22:00");
            break;
    }
}

//���ڼ���û�����������Ƿ���ȷ�������Ϊ�û�����������䣬����ֵΪ�����ʽ�Ƿ���ȷ��0��1
int emailValid(char *email)
{
    char *ptrat;
    char *ptrdot;
    
    //��������������Ƿ���"@"���Լ�"@"��ǰ���Ƿ���Ӣ����ĸ������
    if (strchr(email, '@')== NULL){
        return 0;
    }
    else{
        ptrat = strchr(email, '@');
        if(!((*(ptrat+1)>= 'A' && *(ptrat+1)<= 'z') || (*(ptrat+1) <= '9' && *(ptrat+1) >= '0'))){
            return 0;
        }
        if(!((*(ptrat-1)>= 'A' && *(ptrat-1)<= 'z') || (*(ptrat-1) <= '9' && *(ptrat-1) >= '0'))){
            return 0;
        }
        
    }
    
    //��������������Ƿ���"."���Լ�"."��ǰ���Ƿ���Ӣ����ĸ������
    if (strchr(email, '.')== NULL){
        
        return 0;
    }
    else{
        ptrdot = strchr(email, '.');
        if(!((*(ptrdot+1)>= 'A' && *(ptrdot+1)<= 'z') || (*(ptrdot+1) <= '9' && *(ptrdot+1) >= '0'))){
            return 0;
        }
        if(!((*(ptrdot+1)>= 'A' && *(ptrdot+1)<= 'z') || (*(ptrdot+1) <= '9' && *(ptrdot+1) >= '0'))){
            return 0;
        }
    }
    return 1;
}

/* �ú������Ȼ�ȡ���ص�ʱ�䣬ת��Ϊ�淶����ʽ��֮���ļ���ƴ��Ϊ��������Ϣ�ӵ�ǰ�������ڵĹ淶�ļ���
 ͬʱ�ú����ܷ��ʾ�����ļ�����ȡ��Ϣ���������û���Ԥ���벻��Ԥ������Ϣ
 �ú���û�з���ֵ */
void screenAvalableInterval(char *siteID)
{
    int i = 0, j = 0;
    FILE* fp = NULL;
    FILE* TEMP;
    char str[20] = "1 1 1 1 1 1 1 1 ";                // ��ʼԤ�����
    char ch;
    char fileName[20];
    char year[10];
    char month[10];
    char day[10];
    char literalTime[20];
    struct tm *ptr;
    time_t t;
    t =time(NULL);
    t = t + AWEEK;
    ptr = localtime(&t);                            // ��ȡ����ʱ��
    sprintf(year, "%d" , ptr->tm_year + 1900);        // ����ݴ������ year
    sprintf(month, "%d" , ptr->tm_mon + 1);            // ���·ݴ������ month
    sprintf(day, "%d" , ptr->tm_mday);                // �����ڴ������ day
    
    if(atoi(month)<10 && atoi(month)>0)                // �� 1-9�¸�ʽ��Ϊ 01-09��
    {
        month[1]=month[0];
        month[0]='0';
        month[2]='\0';
    }
    
    if(atoi(day)<10 && atoi(day)>0)                    // �� 1-9�ո�ʽ��Ϊ 01-09��
    {
        day[1]=day[0];
        day[0]='0';
        day[2]='\0';
    }
    
    sprintf(fileName, "%s%s%s%s.txt", siteID, year, month, day);        // ���ļ���ƴ��
    
    fp = fopen(fileName, "r");
    TEMP = fopen("temp.txt","w+");
    if (fp == NULL){                    // �����һ�μ���������Ϣ�ļ������������򴴽�һ�����ļ�
        fclose(fp);
        fp = fopen(fileName, "w");
        fputs(str,fp);                    // ����ʼ����Ԥ����Ϣд������ļ���
        fclose(fp);
        fp = fopen(fileName, "r");
    }
    
    for(i=0;i<8;i++){                    // ɸѡ�����������ĳ���
        fscanf(fp,"%c ",&ch);
        if(ch == '1'){
            j++;
            timeTransfer(i, literalTime);
            printf("%d.    %s    ��Ԥ����\n", j, literalTime);
            fprintf(TEMP,"%d ",i);
        }
    }
    if (j == 0) {
        printf("�Բ��𣬸ó��ص������޿�Ԥ�����Ρ��뷵��ѡ���������ݡ�\n");
    }
    fclose(TEMP);
    fclose(fp);
}

//���ڼ��������·ݺ�����֮ǰ���������ֵΪ����·ݺ����ڣ�����ֵΪ������֮���������
int total_day(int year,int month,int day)
{
    int sum = 0;
    
    //������ռ�������������
    switch(month)
    {
        case 1:sum = day;
            break;
        case 2:sum = 31 + day;
            break;
        case 3:sum = 59 + day;
            break;
        case 4:sum = 90 + day;
            break;
        case 5:sum = 120 + day;
            break;
        case 6:sum = 151 + day;
            break;
        case 7:sum = 181 + day;
            break;
        case 8:sum = 212 + day;
            break;
        case 9:sum = 243 + day;
            break;
        case 10:sum = 273 + day;
            break;
        case 11:sum = 304 + day;
            break;
        case 12:sum = 334 + day;
        break;}
    
    //�жϸ����Ƿ�Ϊ���꣬Ϊ�������2�µ�������һ���Ӱ��
    if(month >2){
        if(((year % 4 == 0)&&(year % 100 !=0))||(year % 400) == 0){
            sum = sum + 1;
        }
    }
    return sum;
}

//����������֮ǰ�������� ����������Ƿֱ�Ҫ�����������ݣ�����ֵΪ����������
int total_year_day(int year1,int year2)
{
    int sum_year_day = 0;
    int i = 0;
    sum_year_day = (year2 - year1) * 365;
    for(i=year1 ; i<year2 ; i++)
    {
        if(((i % 4 == 0)&&(i % 100 !=0))||(i % 400) == 0){
            sum_year_day = sum_year_day + 1;
        }
    }
    return sum_year_day;
}

/* �ú��������ù���Ա���Լ�������ĳ�����ӳ��� */
void admin_addSite(void)
{
    int i = 0;
    int adminNum = 0;
    char adminRegistryName[30];
    char newSitesInfoFileName[20];
    char newSitesOrderFileName[20];
    FILE *Registry;
    FILE *adminRegistry;
    FILE *newSitesInfoFile;
    FILE *newSitesOrderFile;
    SITE newSite,recordedSites[15];
    
    /* ʶ�����Ա���õ������ĳ�����Ϣ */
    if (!strcmp(username, "admin01")) {
        adminNum = 1;
        strcpy(newSite.area, "������");
        strcpy(newSite.venue, "������������");
    } else if (!strcmp(username, "admin02")){
        adminNum = 2;
        strcpy(newSite.area, "ɳ��");
        strcpy(newSite.venue, "ɳ��������");
    } else if (!strcmp(username, "admin03")){
        adminNum = 3;
        strcpy(newSite.area, "�긣");
        strcpy(newSite.venue, "�긣������");
    }
    
    /* ����س���ע����ļ�����ȡ���г�����Ϣ�������³�����Ϣ */
    Registry = fopen("Registry_sites.txt", "r");
    if (Registry == NULL){          //�����Ƿ�ɹ����ļ�
        printf("����ע����ʧ�ܡ�������\n");
        exit(1);
    }
    while (fscanf(Registry, "%s %s %s %s %s %d %d %d %d ",recordedSites[i].siteID, recordedSites[i].area,           recordedSites[i].venue,recordedSites[i].sportType,recordedSites[i].intro,&recordedSites[i].minAge, &recordedSites[i].maxAge, &recordedSites[i].rent, &recordedSites[i].number) != EOF) {       //�����г��ؽ��м���
        i++;
    }
    newSite.number = i + 1;         //�����³��ر�ţ��³��ݱ��Ϊ���г��������˳��
    fclose(Registry);
    i = 0;      //ʹi��λ��0
    
    sprintf(adminRegistryName, "Registry_sites_%s.txt", username);      //���ɹ���Ա�����ݵ�ע����ļ���
    adminRegistry = fopen(adminRegistryName, "r");
    if (adminRegistry == NULL){
        printf("����Ա����ע����ʧ�ܡ�������\n");
        exit(1);
    }
    while (fscanf(adminRegistry, "%s %s %s %s %s %d %d %d %d ",recordedSites[i].siteID, recordedSites[i].area,           recordedSites[i].venue,recordedSites[i].sportType,recordedSites[i].intro,&recordedSites[i].minAge, &recordedSites[i].maxAge, &recordedSites[i].rent, &recordedSites[i].number) != EOF) {       //��ȡ����Ա�������еĳ�����
        i++;
    }
    switch (adminNum) {         //�����³���ID��Ϊ��ͬ����Ա�����������б�����˳��
        case 1:
            sprintf(newSite.siteID, "xtc00%d", i+1);
            break;
        case 2:
            sprintf(newSite.siteID, "shc00%d", i+1);
            break;
        case 3:
            sprintf(newSite.siteID, "hfc00%d", i+1);
            break;
    }
    fclose(adminRegistry);
    
    /* �����³��ػ�����Ϣ */
    printf("�������³��صĳ������� ");
    scanf("%s", newSite.sportType);
    getchar();
    printf("�������³����˶����͵���ؽ��ܣ� ");
    scanf("%[^\n]", newSite.intro);
    printf("�����볡�����Ƶ�������䣺 ");
    scanf("%d", &newSite.minAge);
    printf("�����볡�����Ƶ�������䣺 ");
    scanf("%d", &newSite.maxAge);
    printf("�����볡��ÿʱ�Σ�2Сʱ�������");
    scanf("%d", &newSite.rent);
    
    /* �����³��ص���Ϣ�ļ���д��ղŻ�õ���Ϣ�� */
    sprintf(newSitesInfoFileName, "%s.txt", newSite.siteID);
    newSitesInfoFile = fopen(newSitesInfoFileName, "w");
    if (newSitesInfoFile == NULL){
        printf("�³�����Ϣ�ļ�����ʧ�ܡ�������\n");
        exit(1);
    }
    fprintf(newSitesInfoFile, "%s %s %s %s %s %d %d %d %d ",
            newSite.siteID, newSite.area, newSite.venue, newSite.sportType, newSite.intro,
            newSite.minAge, newSite.maxAge, newSite.rent, newSite.number);
    fclose(newSitesInfoFile);
    
    /* �����³��صĶ����ļ� */
    sprintf(newSitesOrderFileName, "%sorder.txt", newSite.siteID);
    newSitesOrderFile = fopen(newSitesOrderFileName, "w");
    fclose(newSitesOrderFile);
    
    /* ���³���ID�ֱ�д�뵽�ܵ�ע����Լ�����Ա��Ӧ��ע��� */
    Registry = fopen("Registry_sites.txt", "a+");
    if (Registry == NULL){
        printf("����ע����ʧ�ܡ�������\n");
        exit(1);
    }
    adminRegistry = fopen(adminRegistryName, "a+");
    if (adminRegistry == NULL){
        printf("����Ա����ע����ʧ�ܡ�������\n");
        exit(1);
    }
    fprintf(Registry, "%s %s %s %s %s %d %d %d %d \n",
            newSite.siteID, newSite.area, newSite.venue, newSite.sportType, newSite.intro,
            newSite.minAge, newSite.maxAge, newSite.rent, newSite.number);
    fprintf(adminRegistry, "%s %s %s %s %s %d %d %d %d ",
            newSite.siteID, newSite.area, newSite.venue, newSite.sportType, newSite.intro,
            newSite.minAge, newSite.maxAge, newSite.rent, newSite.number);
    fclose(Registry);
    fclose(adminRegistry);
    
    printf("          ===========================\n");
    printf("                   ��ӳ��سɹ���       \n");
    printf("          ===========================\n");
    
}

/* �ú�������ɸѡ�û��ڳ��ز�ѯ�еõ��Ľ������ӡ������Ԥ���ĳ��ع��û��˽����鼰Ԥ��
 �ú�������һ������ֵ�������ж��û����ز�ѯ������ */
void search_filterSites(int searchType)
{
    int i, j;
    int option;         //���Ա����û���ѡ�����֣�
    int k = 0;
    int sitesNum = 0;           //�û���ѯ�ĳ�����
    int avaluableStatusNum = 0;         //���ؿ���ʱ�������
    char intervalStatus;            //��ʱ�ο��������״̬
    char str[20] = "1 1 1 1 1 1 1 1 ";          //ȫ��ʱ�ο���Ԥ���ĳ��ؿ���ʱ��״̬�ļ�������
    char avaluableIntervalFileName[30];         //����ʱ��״̬�ļ����ļ���
    char year[10];          //��Ԥ�������ڵ���
    char month[10];         //��Ԥ�����ڵ���
    char day[10];           //��Ԥ�����ڵ���
    SITE recordedSites[15];         //��ɸѡ�����г�����Ϣ
    SITE qualifiedSites[15];        //����Ԥ���ĳ���
    FILE *sitesInfoFile = NULL;     //������Ϣ�ļ�
    FILE *avaluableIntervalFile;    //����ʱ��״̬�ļ�
    struct tm *ptr;
    time_t t;
    
    if (searchType == 0) {              //�����û�Ҫ��ɸѡ�ĳ��أ�����ʱ�õ������򿪲�ͬ�ĳ�����Ϣ�ļ�
        sitesInfoFile = fopen("Registry_sites.txt", "r");
    } else if (searchType == 1) {
        sitesInfoFile = fopen("Registry_sites_admin01.txt", "r");
    } else if (searchType == 2) {
        sitesInfoFile = fopen("Registry_sites_admin02.txt", "r");
    } else if (searchType == 3) {
        sitesInfoFile = fopen("Registry_sites_admin03.txt", "r");
    }
    
    while (fscanf(sitesInfoFile, "%s %s %s %s %s %d %d %d %d ",recordedSites[sitesNum].siteID, recordedSites[sitesNum].area,           recordedSites[sitesNum].venue,recordedSites[sitesNum].sportType,recordedSites[sitesNum].intro,&recordedSites[sitesNum].minAge, &recordedSites[sitesNum].maxAge, &recordedSites[sitesNum].rent, &recordedSites[sitesNum].number) != EOF) {       //�����г��ؽ��м���
        sitesNum++;
    }
    fclose(sitesInfoFile);
    
    //��ȡ��Ԥ��ʱ������ڣ�Ϊ���ļ���׼��
    t =time(NULL);
    t = t + AWEEK;
    ptr = localtime(&t);
    sprintf(year, "%d" , ptr->tm_year + 1900);
    sprintf(month, "%d" , ptr->tm_mon + 1);
    sprintf(day, "%d" , ptr->tm_mday);
    
    if(atoi(month)<10 && atoi(month)>0)         //ȷ�����·ݡ�����λ
    {
        month[1]=month[0];
        month[0]='0';
        month[2]='\0';
    }
    
    if(atoi(day)<10 && atoi(day)>0)             //ȷ��������������λ
    {
        day[1]=day[0];
        day[0]='0';
        day[2]='\0';
    }
    
    printf("���³����п���ʱ��(�������)��Ԥ����\n");
    for(i = 0; i < sitesNum; i++){              //���μ��ɸѡ���صĿ�Ԥ�����
        sprintf(avaluableIntervalFileName, "%s%s%s%s.txt",  recordedSites[i].siteID, year, month, day);         //���ɳ��ݿ���ʱ���ļ���
        
        avaluableIntervalFile = fopen(avaluableIntervalFileName, "r");          //���Դ򿪳������ض����ڵĿ���ʱ��״̬�ļ�
        if (avaluableIntervalFile == NULL){                                     //����ʧ�ܣ������ڣ����򴴽�һ��������ʹ����״̬����
            fclose(avaluableIntervalFile);
            avaluableIntervalFile = fopen(avaluableIntervalFileName, "w");
            fputs(str,avaluableIntervalFile);
            fclose(avaluableIntervalFile);
            avaluableIntervalFile = fopen(avaluableIntervalFileName, "r");
        }
        
        for(j = 0; j < 8; j++){                         //���μ�鳡�صĿ�Ԥ��ʱ�������������
            fscanf(avaluableIntervalFile, "%c " ,&intervalStatus);
            if(intervalStatus == '1'){
                avaluableStatusNum++;
            }
        }
        
        if(avaluableStatusNum != 0){                    //����Ԥ��ʱ��������Ϊ0�����ӡ���ó��أ����û��Ժ�ѡ��
            qualifiedSites[k] = recordedSites[i];
            k++;
            printf("%d. %s\n", k, recordedSites[i].sportType);
        }
        avaluableStatusNum = 0;             //ʹ����ʱ���������㣬Ϊ�����һ��������׼��
    }
    
    printf("��ѡ�������˽���ϸ��Ϣ�ĳ��ݣ����롰0��������һ������");
    scanf("%s", choice);
    while(inputValidation(choice) != YES || atoi(choice) > i){
        printf("����������������롣\n");
        printf("��ѡ�������˽���ϸ��Ϣ�ĳ��ݣ����롰0��������һ������");
        scanf("%s", choice);
    }
    option = atoi(choice);          //��ѡ��ת��Ϊ������Ϊ�����û�ѡ��ĳ�����Ϣ������
    if (option == 0){
    	system("cls");
        return;
    }
    system("cls");
    customer_getSiteInformation(qualifiedSites[option - 1].siteID);          //�ҳ��û�ѡ�����Ӧ�����ڽṹ�����е�λ�ã��ѳ���ID���ݸ���һ������
}
