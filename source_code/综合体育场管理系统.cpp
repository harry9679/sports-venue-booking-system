//
//  综合体育场管理系统 
//
//  Created by Group 46. 
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h> 

#define AWEEK 604800		//一个星期的秒数，用于处理订单时的时间计算 
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
}CUSTOMER;				//用于保存顾客信息的结构 

typedef struct {
    char name[20];
    char ID[20];
    char password[20];
    int sex;
    char phone[12];
    char email[25];
    char district[20];
}ADMIN;					//用于保存管理员信息的结构 

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
}SITE;					//用于保存场地信息的结构 

typedef struct {
    char orderID[50];
    char orderDate[20];
    char siteID[20];
    char useDate[20];
    int timeInterval;
    int isOnTime;
    int sex;
}ORDER;					//用于保存订单信息的结构 

//主菜单函数
void Customer(void);
void Admin(void);
int Registration(void);

//用户功能函数
int customer_Login(void);
void customer_Change(void);
void customer_Order(SITE *);
void customer_Search(void);
void customer_Cancel(void);
void customer_getSiteInformation(char *);

//管理员功能函数
int admin_Login(void);
void admin_Change(void);
void admin_Search(void);
void admin_Arrange1(void);
void admin_Arrange2(void);
void admin_Statistics(void);
void admin_SexStatistics(void);
void admin_siteInformation(void);
void admin_addSite(void);

//用户查询功能函数
void mainSearch(void);
void rentRank(void);
void bookingRank(void);
void search_Site(void);
void search_Gym(void);
void search_District(void);
void search_Hot(void);
void search_filterSites(int);

//验证、转化、过滤等功能函数
int inputValidation(char *);
int checkInputUsername(int);
void timeTransfer(int, char *);
int emailValid(char *);
void screenAvalableInterval(char *);
int total_day(int, int ,int);
int total_year_day(int ,int);


char choice[5];             //用于读入用户的对选项的选择和输入校验
char username[20];          //用于保存用户的登录用户名
int orderTimes;             //用于保存单个用户单次登录的预定次数

/* 包含进入系统的主菜单，可选择“用户登录”、“管理员登录”、“用户注册”以及“退出系统”，然后跳转到不同的相应函数进行后续操作 */
int main()
{
    for(;;){
        printf("       ===========================\n");
        printf("           综合体育场馆管理系统      \n");
        printf("       ===========================\n");
        printf("       1.顾客登录                  \n");
        printf("       2.管理员登录                \n");
        printf("       3.顾客注册                  \n");
        printf("       4.退出系统                  \n");
        printf("       ===========================\n");
        printf("\n");
        printf("       请选择您需要的操作:");
        
        scanf("%s", choice);
        while(inputValidation(choice) != YES){      //调用inputValidation()函数来确保输入正确
            printf("输入错误，请重新输入。\n");
            scanf("%s", choice);
        }
        switch (atoi(choice)) {
            case 1:
            	system("cls");
                Customer();         //跳转用户的主菜单
                break;
            case 2:
            	system("cls");
                Admin();            //跳转管理员的主菜单
                break;
            case 3:
            	system("cls");
                printf("请输入你想注册的用户名(6-10位字母和数字组合)：");           //引导用户进行注册，调用Registration（）函数来完成
                scanf("%s", username);
                while(Registration() == NO){
                    printf("请输入你想注册的用户名(6-10位字母和数字组合)：");
                    scanf("%s", username);
                }
                printf("注册成功！请继续登陆来进行进一步操作。\n");
                break;
            case 4:
            	system("cls");
            	printf("       ================================\n");
        		printf("        感谢您使用综合体育场馆管理系统  \n");
        		printf("       ================================\n");
                exit(1);            //结束运行，退出程序
            default:
            	system("cls");
                printf("输入错误，请重新输入。\n");            //没有输入可选的的四个选项，则给出提示，要求重新选择
        }
    }
    
    return 0;
}

/* 用户的主菜单，首先进行登录（调用customer_Login（）函数），
 然后打出用户可以做的所有基本大的操作，根据用户选择，跳转到对应的函数或下一级菜单进行后续操作 */
void Customer(void)
{
	printf ("用户登录\n");
    printf("请输入用户名：");
    scanf("%s", username);
    if (customer_Login() == NO){            //调用customer_Login（）来完成登录操作
        printf("登录失败，请重试。\n");
        return;
    }
    orderTimes = 0;             //登录成功后，使预定次数归零，确保用户可以预定
    system("cls");
    printf("       ===========================\n");
    printf("                 登录成功！         \n");
    printf("       ===========================\n");
    for(;;){
    	mark1:
        printf("                  主菜单\n");
        printf("       ===========================\n");
        printf("       1.场地查询及预定\n");
        printf("       2.订单查询\n");
        printf("       3.个人信息管理\n");
        printf("       4.退出登录\n");
        printf("       ===========================\n");
        printf("       请选择下一步操作：");
        scanf("%s", choice);
        while(inputValidation(choice) != YES){               //调用inputValidation()函数来确保输入正确
            printf("输入错误，请重新输入。\n");
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
                printf("        请选择您要进行的下一步操作     \n");
                printf("       ===========================\n");
                printf("       1.查询已有订单\n");
                printf("       2.取消订单\n");
                printf("       3.返回上一级\n");
                printf("       ===========================\n");
                printf("       \n");
                scanf("%s", choice);
                while(inputValidation(choice) != YES){
                    printf("输入错误，请重新输入。\n");
                    scanf("%s", choice);
                }
                switch(atoi(choice)){
                    case 1:
                    	system("cls");
                        customer_Search ();             //调用customer_Search（）函数来查询已有的订单
                        goto mark2; 
                        break;
                    case 2:
                    	system("cls");
                        customer_Cancel ();             //调用customer_Cancel（）函数来查询可取消的订单，并可以选择取消
                        goto mark2;
                        break;
                    case 3:
                    	system("cls");
                    	goto mark1;
                    	break;
                    default:
             		 	system("cls");
                        printf("输入错误，请重新输入。\n");
                        goto mark2;
                }
                break;
            case 3:
            	system("cls");
                customer_Change();                      //调用customer_Change（）函数来查看当先的个人信息，以及可以选择修改个人信息
                break;
            case 4:
            	system("cls");
                return;
            default:
				system("cls");
				printf("输入错误，请重新输入。\n") ; 
        }
    }
}

/* 管理员的主菜单，首先进行登录（调用admin_Login（）函数），
 然后打出用户可以做的所有基本大的操作，根据用户选择，跳转到对应的函数或下一级菜单进行后续操作 */
void Admin(void)
{
	printf ("管理员登录\n");
    printf("请输入用户名：");
    scanf("%s", username);
    if (admin_Login() == NO){               //调用admin_Login（）函数来进行登录操作
        printf("登录失败，请重试。\n");
        return;
    }
    system("cls");
    printf("       ===========================\n");
    printf("                 登录成功！         \n");
    printf("       ===========================\n");
    for(;;){
    	
        printf("                  主菜单\n");
        printf("       ===========================\n");
        printf("       1.预定管理\n");
        printf("       2.场地管理\n");
        printf("       3.个人信息管理\n");
        printf("       4.退出登录\n");
        printf("       ===========================\n");
        printf("       请选择下一步操作：");
        scanf("%s", choice);
        while(inputValidation(choice) != YES){               //调用inputValidation()函数来确保输入正确
            printf("输入错误，请重新输入。\n");
            scanf("%s", choice);
        }
        switch (atoi(choice)) {
            case 1:
            	system("cls");
                admin_Arrange1();               //跳转进入预定管理菜单
                break;
            case 2:
            	system("cls");
                admin_Arrange2();               //跳转进入场地管理菜单
                break;
            case 3:
            	system("cls");
                admin_Change();                 //调用admin_Change函数来查看当前的用户信息和选择修改部分用户信息
                break;
            case 4:
            	system("cls");
                return;
             default:
             system("cls");
             printf("输入错误，请重新输入。\n");
             	
        }
    }
}

/* 该函数用于给用户注册，获取用户的基本信息并写入到新的用户信息文件中，同时生成空的用户订单文件
 该函数会在登录时检测出用户名不存在且用户希望注册时被调用，或在主菜单中选中了用户注册后直接调用
 该函数返回一个整型值（“YES”或“NO”）,用于确认注册是否成功 */
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
    
    //检查用户名位数是否符合要求
    if (strlen(username) > 10 || strlen(username) < 6){
        printf("用户名过长或过短，请选择6-10位的用户名重试。\n");
        registerSuccess = NO;
        return registerSuccess;
    }
    
    //检查用户名是否只包含字母和数字
    for (i = 0; username[i] != '\0'; i++){
        if (!((username[i] >= '0' && username[i] <= '9') ||
              (username[i] >= 'A' && username[i] <= 'Z') ||
              (username[i] >= 'a' && username[i] <= 'z'))){
            printf("用户名包含了除字母和数字以外的字符，请重试。\n");
            registerSuccess = NO;
            return registerSuccess;
        }
    }
    
    //检查是否有重复的用户名
    Registry = fopen("Registry_users.txt","r");
    if (Registry == NULL){
        printf("用户注册表打开失败。请重试\n");
        exit(1);
    }
    for (i = 0; feof(Registry) == 0; i++){
        fscanf(Registry, "%s ", recordedNames[i]);
    }
    fclose(Registry);
    for (j = 0; j < i; j++){
        if (strcmp(recordedNames[j], username) == 0){
            printf("用户名已存在！注册失败，请重试。\n");
            registerSuccess = NO;
            return registerSuccess;
        }
    }
    
    //检查通过，开始获取用户信息进行完善
    //录入用户名
    sprintf(newUser.ID, "%s", username);
    
    //录入密码并检查
    printf("请设置您的密码：");
    scanf("%s", password1);
    printf("请再次输入您的密码：");
    scanf("%s", password2);
    while (strcmp(password1,password2) != 0){
        printf("两次输入密码不一致，请重新输入:");
        scanf("%s", password2);
    }
    sprintf(newUser.password, "%s", password2);
    
    //获取姓名
    printf("请输入您的姓名：");
    scanf("%s", newUser.name);
    
    //获取性别
    printf("请输入您的性别(男/女)：");
    scanf("%s", inputSex);
    if (!strcmp(inputSex, "男")){
        newUser.sex = 1;
    } else {
        newUser.sex = 0;
    }
    
    //获取年龄
    printf("请输入您的年龄：");
    scanf("%d", &newUser.age);
    
    //获取电话号码
    do{
        isCorrect = YES;
        printf("请输入您的手机号码：");
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
            printf("手机号码格式有误，请重新输入。\n");
        }
    }while(isCorrect == NO);
    sprintf(newUser.phone, "%s", inputPhonenum);
    
    //获取邮箱地址
    printf("请输入您的电子邮箱地址：");
    scanf("%s", inputEmail);
    isCorrect = emailValid(inputEmail);         //调取emailValid（）来校验输入的邮箱地址是否符合要求
    while(isCorrect == NO){
        printf("电子邮箱格式不正确，请重新输入：");
        scanf("%s", inputEmail);
        isCorrect = emailValid(inputEmail);
    }
    sprintf(newUser.email, "%s", inputEmail);
    
    //获取所在区域信息
    printf("请输入您的所在区域：");
    scanf("%s", newUser.district);
    
    //假设新注册用户需充值500元（保证新注册用户亦能进行预定）
    newUser.money = 500.00;
    
    //创建用户所需要的信息文件及订单文件，并在用户注册表中加入新用户用户名
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

/* 该函数用于用户的登录校验，先调用checkInputUsername(int)函数（传入值为1）来检查用户名是否有效
 若改用户不存在，则引导用户进行注册（调用Registration函数）
 若用户存在，则调取用户信息文件对输入的密码进行校验，共三次机会，三次输入有误后，将直接进行提示并返回主菜单
 该函数返回一个整型值（“YES”或“NO”），用于确认登录是否成功*/
int customer_Login(void)
{
    FILE *outFile;
    int i=0;
    int loginSuccess = NO;              //用于确认登录是否成功的变量
    char inputPassword[20];
    char infoFileName[20];
    CUSTOMER user;
    
    //检查输入用户名是否存在。若不存在，引导用户进行注册。
    if(checkInputUsername(1) == NO){
        printf("您输入的用户名不存在。\n");
        printf("是否需要注册成为新用户？（y/n）");
        scanf("%s", choice);
        while(strcmp(choice, "y") != 0 && strcmp(choice, "n") != 0){            //校验用户输入的是否是‘y’或‘n‘的其中一个
            printf("输入错误，请输入'y'（是）或'n'（否）来进行选择。\n");
            printf("是否需要注册成为新用户？（y/n）");
            scanf("%s", choice);
        }
        
        if (strcmp(choice, "y") == 0){
            while(Registration() == NO){                    //如果用户选择要注册，则调用Registration（）函数来完成注册
                printf("请输入你想注册的用户名(6-10位字母和数字组合)：");
                scanf("%s", username);
            }
            printf("注册成功，请继续进行登录。\n");
        }else{
            return loginSuccess;
        }
    }
    
    sprintf(infoFileName, "%s.txt", username);              //依照特定的格式生成相应的用户信息文件名，打开它，读出里面的信息，与用户输入的密码做比对
    outFile = fopen(infoFileName, "r");
    if (outFile == NULL) {
        printf("用户文件打开失败。");
        exit(1);
    }
    fscanf(outFile, "%s %s %s %d %d %s %s %f %s", user.name, user.ID, user.password,
           &user.sex, &user.age, user.phone, user.email, &user.money, user.district);
    fclose(outFile);
    do {
        printf("请输入您的密码：");
        scanf("%s", inputPassword);
        if(strcmp(user.password, inputPassword) == 0){
            loginSuccess = YES;                 //若密码正确，则结束循环，登录成功
        }
        i++;                //i记录密码输入错误的次数
    } while (i<3 && loginSuccess == NO);    //若i大于3，则密码错误次数过多，登录失败
    return loginSuccess;
}

/* 用于查看用户信息且可以允许用户修改部分信息 */
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
    
    //打开用户文件且检查用户文件是否成功打开
    sprintf(infoFileName, "%s.txt", username);
    outFile = fopen(infoFileName,"r");
    if (outFile == NULL) {
        printf("用户文件打开失败。");
        exit(1);
    }
    
    //读取此用户的信息
    fscanf(outFile, "%s %s %s %d %d %s %s %f %s", user.name, user.ID, user.password,
           &user.sex, &user.age, user.phone, user.email, &user.money, user.district);
    fclose(outFile);
    
    for(;;){
		printf("姓名：%s\n用户ID：%s\n手机号码：%s\n电子邮箱：%s\n地址：%s\n余额：%.2f元\n",
           user.name, user.ID, user.phone, user.email, user.district,user.money); 
        printf("       ===========================\n");
        printf("           请选择想要修改的项目     \n");
        printf("       ===========================\n");
        printf("       1.密码\n");
        printf("       2.手机号码\n");
        printf("       3.邮箱\n");
        printf("       4.地址\n");
        printf("       5.返回上一级\n");
        printf("       ===========================\n");
        printf("       \n");
        
        scanf("%s", choice);
        while(inputValidation(choice) != YES){
            printf("输入错误，请重新输入。\n");
            scanf("%s", choice);
        }
        switch (atoi(choice)) {
                
                //检查用户所输入密码是否与原密码相同，输错3次是返回上一级
            case 1:
            	system("cls");
                printf("请输入原密码：");
                scanf("%s", oriPassword);
                while(strcmp(oriPassword,user.password)!=0 && i<3){
                    printf("密码与原密码不符，请重新输入:");
                    scanf("%s", oriPassword);
                    i++;
                }
                if(i == 3){
                    return;
                }
                
                //检查两次输入的新密码是否相同 ，输错三次时返回上一级
                printf("请输入新密码：");
                scanf("%s", newPassword1);
                printf("请再次输入新密码：");
                scanf("%s", newPassword2);
                while (strcmp(newPassword1,newPassword2) != 0 && j < 2){
                    printf("两次输入密码不相同，请重新输入:");
                    scanf("%s", newPassword2);
                    j++;
                }
                if (j == 2){
                    printf("修改失败：密码输入错误次数过多。");
                    return;
                } else {
                    printf("修改成功！\n");
                    strcpy(user.password, newPassword2);
                }
                Sleep(3000);
                break;
            case 2:
     		 	system("cls");
                do{
                    isCorrect = YES;
                    printf("请输入新手机号码:");
                    scanf("%s",testPhone);
                    
                    //检查用户输入的手机号码是否全为数字
                    for(i=0;i<11;i++) {
                        if(testPhone[i]>'9'  ||  testPhone[i]<'0'){
                            isCorrect = NO;
                            break;
                        }
                        
                        //检查用户输入的手机号码长度是否为11位
                        if(strlen(testPhone) != 11){
                            isCorrect = NO;
                            break;
                        }
                    }
                    if(isCorrect == NO){
                        printf("输入错误，请重新输入。\n");
                    }
                }while(isCorrect == NO);
                printf("修改成功！\n");
                strcpy(user.phone,testPhone);
                Sleep(3000);
                break;
            case 3:
            	system("cls");
                printf("请输入新邮箱：");
                scanf("%s", newEmail);
                isValid = emailValid(newEmail);
                while(isValid == 0 && i < 2){
                    printf("邮箱格式不正确，请重新输入：");
                    scanf("%s", newEmail);
                    isValid = emailValid(newEmail);
                    i++;
                }
                
                //输入三次格式不正确的邮箱返回上一级
                if (i == 2 && isValid == 0){
                    return;
                }else{
                    printf("修改成功\n");
                    strcpy(user.email, newEmail);
                }
                Sleep(3000);
                break;
            case 4:
            	system("cls");
                printf("请输入新地址：");
                scanf("%s", address);
                strcpy(user.district, address);
                printf("修改成功\n");
                Sleep(3000);
                break;
            case 5:
            	system("cls");
                return;
            default:
            	system("cls");
                printf("输入错误，请重新输入。\n");
				break;
        }
        
        FILE* inFile;
        inFile = fopen(infoFileName,"w");
        if (inFile == NULL) {
            printf("修改失败：用户文件打开失败。");
            exit(1);
        }
        fprintf(inFile, "%s %s %s %d %d %s %s %.2f %s", user.name, user.ID, user.password,
                user.sex, user.age, user.phone, user.email, user.money, user.district);
        fclose(inFile);
    }
}

/* 该函数用于检查用户是否满足预定条件和用户下订单，由customer_getSiteInformation（）函数调用（或被自身调用），
 用于用户在了解了场地信息和可用时段之后对可用时段进行预定
 接受一个SITE的类型指针，用于获得用户预定的场地信息。每次可以对一个场地的一个时段进行预定，预定成功后可再次检查相同场地的可用时段进行再次预定，对自身进行调用 */
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
    char year1[10], month1[10], day1[10], hour1[10], minute1[10];           //用于保存预定时间的时间数据
    char year2[10], month2[10], day2[10];               //用于保存使用时间的时间数据
    FILE *sitesOrderFile;               //场馆的订单信息文件
    FILE *usersOrderFile;               //用户个人的订单信息文件
    FILE *usersInfoFile;                //用户信息文件
    FILE *TEMP;                         //由screenAvalableInterval()产生的临时文件，按顺序保存着可预定时段的时段编号
    FILE *timeSituation;                //场地可用时段状态文件
    CUSTOMER user;
    ORDER order;
    ORDER oldOrder[30];
    time_t orderTime, useTime;
    struct tm *ptr1, *ptr2;
    
    //准备需要用到的文件
    sprintf(usersOrderFileName, "%sorder.txt", username);
    sprintf(usersInfoFileName, "%s.txt", username);
    sprintf(sitesOrderFileName, "%sorder.txt", siteInfo->siteID);
    
    sitesOrderFile = fopen(sitesOrderFileName, "a+");
    if (sitesOrderFile == NULL) {
        printf("场地订单文件打开失败。\n");
        exit(1);
    }
    usersOrderFile = fopen(usersOrderFileName, "a+");
    if (usersOrderFile == NULL) {
        printf("用户订单文件打开失败。\n");
        exit(1);
    }
    usersInfoFile = fopen(usersInfoFileName, "r");
    if (usersInfoFile == NULL) {
        printf("用户信息文件打开失败。");
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
    
    //检查是否符合预定条件
    //检查单次登陆预定数量
    if (orderTimes >= 3){
        printf("对不起，每个用户每次仅能预约三次。\n");
        canOrder = NO;
    }
    
    //检查失信次数
    for (j = 0; j < i-1; j++) {
        if (oldOrder[j].isOnTime == 0) {
            notOnTime++;
        }
    }
    if (notOnTime >= 3) {
        printf("对不起，您的失信次数已达到3次。无法再进行预约。\n");
        canOrder = NO;
    }
    
    //检查账户余额是否够预约此场馆
    if (user.money < siteInfo->rent) {
        printf("对不起，您的账户余额不足，无法对该场馆的进行预约。\n");
        canOrder = NO;
    }
    
    //检查用户年龄是否满足年龄限制
    if (user.age < siteInfo->minAge || user.age > siteInfo->maxAge) {
        printf("对不起，您的年龄不符合该场馆的年龄限制要求，无法对该场馆进行预约。\n");
        canOrder = NO;
    }
    
    //检查是否可以预定，若不可以，则提示用户并推出函数运行。
    if (canOrder == NO) {
        printf("                     ===========================\n");
        printf("                               预约失败！         \n");
        printf("                     ===========================\n");
        Sleep(3000);
        system("cls");
        return;
    }
    
    //从文件中读出可预定的场次情况
    TEMP = fopen("temp.txt", "r");
    for (i = 0; feof(TEMP) == 0; i++){
        fscanf(TEMP, "%d ", &intervalNum[i]);
    }
    
    printf("请选择您要预约的场次（或输入0返回上一级）：");
    scanf("%s", choice);
    while(inputValidation(choice) != YES || atoi(choice) > i){
        printf("输入错误，请重新选择。\n");
        printf("请选择您要预约的场次（或输入0返回上一级）：");
        scanf("%s", choice);
    }
    if(atoi(choice) == 0){
    	system("cls"); 
    	return;
    } 
    system("cls");
    
    //生成订单信息
    //转换保存选择的时段
    option = atoi(choice);
    chosenInterval = intervalNum[option - 1];
    
    //根据格式生成场地使用时间
    orderTime = time(NULL);             //获得预定时的系统时间
    ptr1 = localtime(&orderTime);       //把系统时间转化拆分成可以使用的时间结构
    sprintf(year1, "%d" , ptr1->tm_year + 1900);
    sprintf(month1, "%d" , ptr1->tm_mon + 1);
    sprintf(day1, "%d" , ptr1->tm_mday);
    sprintf(hour1, "%d", ptr1->tm_hour);
    sprintf(minute1, "%d", ptr1->tm_min);
    //检查月份、日期、小时、分钟是否为两位。若不是则用‘0’将第一位补齐
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
    
    //根据格式生成场地使用时间
    useTime = orderTime + AWEEK;            //使用时间为预定时间的一周之后那一天
    ptr2 = localtime(&useTime);
    sprintf(year2, "%d" , ptr2->tm_year + 1900);
    sprintf(month2, "%d" , ptr2->tm_mon + 1);
    sprintf(day2, "%d" , ptr2->tm_mday);
    
    //检查月份和日期是否为两位
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
        printf("预定失败：场地可用时段检查文件打开失败。\n");
        exit(1);
    }
    
    //把订单信息拷贝进入订单结构，并在用户和场馆的订单记录文件当中录入信息
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
            printf("对不起当前时段您已预约了别的场地，无法再进行预约。\n");
            break;
        }
    }
    
    //检查是否可以预定，若不可以，则提示用户并推出函数运行。
    if (canOrder == NO) {
        printf("                     ===========================\n");
        printf("                              预约失败！         \n");
        printf("                     ===========================\n");
        printf("以下是该场馆可用时段，请尝试预定其他场馆：\n");				//由于用户是因为时段冲突而预定失败， 
        screenAvalableInterval(siteInfo->siteID);
        customer_Order(siteInfo);
        system("cls");
        return;
    }
    
    //将预定信息分别写入用户和场地的订单文件中
    fprintf(usersOrderFile, "%s %s %s %s %d %d %d\n", order.orderID, order.orderDate,
            order.siteID, order.useDate, order.timeInterval, order.isOnTime, order.sex);
    fprintf(sitesOrderFile, "%s %s %s %s %d %d %d\n", order.orderID, order.orderDate,
            order.siteID, order.useDate, order.timeInterval, order.isOnTime, order.sex);
    fclose(usersOrderFile);
    fclose(sitesOrderFile);
    
    //更改场馆时段的可用状态
    for (i = 0; feof(timeSituation) == 0; i++){
        fscanf(timeSituation, "%d ", &timeInterval[i]);
    }
    fclose(timeSituation);
    
    timeInterval[chosenInterval] = 0;
    
    timeSituation = fopen(sitesTimeIntervalName, "w");
    if (timeSituation == NULL) {
        printf("预定失败：场地可用时段检查文件打开失败。\n");
        exit(1);
    }
    for (i = 0; i < 8; i++) {
        fprintf(timeSituation, "%d ", timeInterval[i]);
    }
    fclose(timeSituation);
    
    //扣除用户账户中的钱
    user.money -= siteInfo->rent;
    usersInfoFile = fopen(usersInfoFileName, "w");
    if (usersInfoFile == NULL) {
        printf("预定失败：用户信息文件打开失败。");
        exit(1);
    }
    fprintf(usersInfoFile, "%s %s %s %d %d %s %s %.2f %s", user.name, user.ID, user.password,
            user.sex, user.age, user.phone, user.email, user.money, user.district);
    fclose(usersInfoFile);
    
    //把预定信息打印出来给用户做展示
    char literalInterval[20];
    timeTransfer(order.timeInterval, literalInterval);
    printf("                     ===========================\n");
    printf("                               预约成功！         \n");
    printf("                     ===========================\n");
    printf("                            以下是您的预约信息：\n\n");
    printf("订单编号                       预定日期          场地编号  使用日期    预约时间段\n");
    printf("%-30s %-17s %-9s %-11s %-10s\n",
           order.orderID, order.orderDate, order.siteID, order.useDate, literalInterval);
    orderTimes++;
    
    //询问用户是否要继续预定同一场地当天的其他可用时段，若用户选择‘y’，则再次调用screenAvaluable（）函数和自身，再次对可用时段进行预定
    printf("是否需要继续预约该场地其他场次？(y/n)");
    scanf("%s", choice);
    while(strcmp(choice, "y") != 0 && strcmp(choice, "n") != 0){
        printf("输入错误，请输入'y'（是）或'n'（否）来进行选择。\n");
        printf("是否需要继续预约该场地其他场次？(y/n)");
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

/* 用于用户查询预定信息，其传入函数的参数为用户铭，用于打开该用户对应的文件 */
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
        printf("用户文件打开失败。");
        exit(1);
    }
    printf("你的订单信息为：\n");
    printf("订单编号                       预定日期          场地编号  使用日期    预约时间段\n");
    
    while (fscanf(outFile, "%s %s %s %s %d %d %d\n", user[i].orderID, user[i].orderDate, user[i].siteID, user[i].useDate,
                  &user[i].timeInterval, &user[i].isOnTime, &user[i].sex) != EOF) {
        
        timeTransfer(user[i].timeInterval, interval);
        printf("%-30s %-17s %-9s %-11s %-10s\n", user[i].orderID, user[i].orderDate, user[i].siteID, user[i].useDate,
               interval);
        i++;
    }
    fclose(outFile);
}

/* 用于用户删除预定信息，其传入函数的参数为用户铭，用于打开该用户对应的文件 */
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
        printf("用户文件打开失败。");
        exit(1);
    }
    
    for(i=0;feof(outFile)==0;i++) {
        
        fscanf(outFile, "%s %s %s %s %d %d %d\n", user[i].orderID, user[i].orderDate, user[i].siteID, user[i].useDate,
               &user[i].timeInterval, &user[i].isOnTime, &user[i].sex);
        
        strcpy(substituteTime[i], user[i].useDate);
        ptrDate = strtok(user[i].useDate, ":");
        
        //将所需用到的使用时间按照字符串格式读出后将字符串拆分为年月日，并将其拷贝到新的字符串数组中
        while (ptrDate != NULL){
            strcpy(splitDate[j], ptrDate);
            j++;
            ptrDate = strtok(NULL, ":");
        }
    }
    fclose(outFile);
    
    //将字符串数组写入结构
    i = 0;
    while(i < j-1){
        strcpy(customer[k].year, splitDate[i]);
        strcpy(customer[k].month, splitDate[i+1]);
        strcpy(customer[k].day, splitDate[i+2]);
        k++;
        i = i+3;
    }
    
    k = 0;//重新初始化k的值
    
    //创建时间结构指针并读取现在的系统时间将其存入时间结构中
    struct tm *ptrTime;
    time_t t;
    t =time(NULL);
    ptrTime = localtime(&t);
    
    printf("你可删除的订单有：\n");
    printf("序列号 订单编号                       预定日期          场地编号  使用日期    预约时间段\n");
    
    //使用函数计算出现在时间与预定使用时间之间的时间差
    for(m = 0;m <= j/3-1;m++){
        sum = total_year_day(ptrTime->tm_year + 1900,atoi(customer[m].year)) - total_day(ptrTime->tm_year + 1900,ptrTime->tm_mon + 1,ptrTime->tm_mday)
        + total_day(atoi(customer[m].year),atoi(customer[m].month),atoi(customer[m].day)) ;
        
        //筛选出距离现在时间大于一天的预定订单，为可取消订单
        if(sum > 1){
            timeTransfer(user[m].timeInterval, interval);
            printf("%-6d %-30s %-17s %-9s %-11s %-10s\n",num, user[m].orderID, user[m].orderDate, user[m].siteID, substituteTime[m],
                   interval);
            
            //记录下可取消订单在用户文件中所处的行数并给其特定编号
            count[k].option = num;
            count[k].row = m;
            num++;
            k++;
        }
    }
    if(k > 0){
        do{
            printf("请输入想要删除的订单序列号：(输入0返回）");
            scanf("%s", choice);
            while(inputValidation(choice) != YES){
                printf("输入错误，请重新输入。\n");
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
            printf("是否确认删除（1.确认 2.取消）");
            scanf("%s", cancelConfirm);
        }while (atoi(cancelConfirm) == 2);
        
        FILE *inFile;
        inFile = fopen(fileName, "w");
        if (inFile == NULL) {
            printf("用户文件打开失败。");
            exit(1);
        }
        
        //根据用户所输入的取消编号，在将信息写入用户订单文件时跳过其选择的那一行的信息
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
            printf("用户文件打开失败。");
            exit(1);
        }
        for(i=0;feof(outFile)==0;i++) {
            
            fscanf(outFile, "%s %s %s %s %d %d %d", user[i].orderID, user[i].orderDate, user[i].siteID, user[i].useDate,
                   &user[i].timeInterval, &user[i].isOnTime, &user[i].sex);
        }
        fclose(outFile);
        
        inFile = fopen(siteFile, "w");
        if (inFile == NULL) {
            printf("用户文件打开失败。");
            exit(1);
        }
        
        //找到场地订单文件中用户选择删除项订单编号相同的一条，重新写入文件时跳过那一行的信息
        for(k=0;k<i;k++){
            if(strcmp(user[k].orderID, idCancel    )==0){
                continue;
            }
            fprintf(inFile, "%s %s %s %s %d %d %d\n", user[k].orderID, user[k].orderDate, user[k].siteID, substituteTime[k],
                    user[k].timeInterval, user[k].isOnTime, user[k].sex);
        }
        printf("取消成功\n");
    }
    else{
        printf("你没有可取消的订单\n");
    }
}

/* 该函数用于管理员的登录，若未注册则可以选择注册。同时可以检查是否为管理员登录，而不让普通用户串号使用
 该函数有一个int类型的返回值 */
int admin_Login(void)
{
    FILE *outFile;
    int i=0;
    int loginSuccess = NO;
    char infoFileName[20];
    char inputPassword[20];
    ADMIN user;
    
    //检查输入用户名是否存在。若不存在，引导用户进行注册。
    if(checkInputUsername(2) == NO){
        printf("您输入的管理员用户名不存在。\n");
        printf("请检查后重新登录。\n");
        return loginSuccess;
    }
    
    sprintf(infoFileName, "%s.txt", username);            // 将接受到的username赋予文件infoFileName
    outFile = fopen(infoFileName, "r");
    if (outFile == NULL) {
        printf("用户文件打开失败。");
        exit(1);
    }
    fscanf(outFile, "%s %s %s %d %s %s %s", user.name, user.ID, user.password,
           &user.sex, user.phone, user.email, user.district);                        //将管理员信息提取出来，输入到所打开的文件中
    fclose(outFile);
    do {                                                        // 改循环用于检验是否为管理员，防止普通用户登录
        printf("请输入密码：");
        scanf("%s", inputPassword);
        if(strcmp(user.password, inputPassword) == 0){
            loginSuccess = YES;
        }
        i++;
    }while(i<3 && loginSuccess == NO);
    return loginSuccess;
}

/* 用于查看用户信息且可以允许用户修改部分信息 */
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
        printf("用户文件打开失败。");
        exit(1);
    }
    fscanf(outFile, "%s %s %s %d %s %s %s ", user.name, user.ID, user.password,
           &user.sex, user.phone, user.email, user.district);
    fclose(outFile);
    
    
    
    for(;;){
		printf("姓名：%s\n用户ID：%s\n手机号码：%s\n电子邮箱：%s\n地址：%s\n",
           user.name, user.ID, user.phone, user.email, user.district);
        printf("       ===========================\n");
        printf("           请选择想要修改的项目    \n");
        printf("       ===========================\n");
        printf("       1.密码\n");
        printf("       2.手机号码\n");
        printf("       3.邮箱\n");
        printf("       4.返回上一级\n");
        printf("       ===========================\n");
        printf("       \n");
        scanf("%s", choice);
        while(inputValidation(choice) != YES){
            printf("输入错误，请重新输入。\n");
            scanf("%s", choice);
        }
        switch(atoi(choice))
        {
            case 1:
            	system("cls");
                printf("请输入原密码：");
                scanf("%s", oriPassword);
                while(strcmp(oriPassword,user.password)!=0 && i<3){
                    printf("密码与原密码不符，请重新输入:");
                    scanf("%s", oriPassword);
                    i++;
                }
                if(i == 3){
                    return;
                }
                printf("请输入新密码：");
                scanf("%s", newPassword1);
                printf("请再次输入新密码：");
                scanf("%s", newPassword2);
                while (strcmp(newPassword1,newPassword2) != 0 && j < 2){
                    printf("两次输入密码不相同，请重新输入:");
                    scanf("%s", newPassword2);
                    j++;
                }
                if (j == 2){
                    printf("修改失败：密码输入错误次数过多。");
                    return;
                }else{
                    printf("修改成功！\n");
                    strcpy(user.password, newPassword2);
                }
                Sleep(3000);
                break;
            case 2:
            	system("cls");
                do{
                    isCorrect = YES;
                    printf("请输入新手机号码:");
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
                        printf("输入错误，请重新输入。\n");
                    }
                }while(isCorrect == NO);
                printf("修改成功！\n");
                strcpy(user.phone,testPhone);
                Sleep(3000);
                break;
            case 3:
            	system("cls");
                printf("请输入新邮箱：");
                scanf("%s", newEmail);
                isValid = emailValid(newEmail);
                while(isValid == 0 && i < 2){
                    printf("邮箱格式不正确，请重新输入：");
                    scanf("%s", newEmail);
                    isValid = emailValid(newEmail);
                    i++;
                }
                if (i == 2 && isValid == 0){
                    return;
                }else{
                    printf("修改成功\n");
                    strcpy(user.email, newEmail);
                }
                Sleep(3000);
                break;
            case 4:
            	system("cls");
                return;
            default:
            	system("cls");
                printf("输入错误，请重新输入。\n");
                break; 
        }
        
        FILE* inFile;
        inFile = fopen(infoFileName,"w");
        if (inFile == NULL){
            printf("修改失败：用户文件打开失败。");
            exit(1);
        }
        
        fprintf(inFile, "%s %s %s %d %s %s %s ", user.name, user.ID, user.password,
                user.sex, user.phone, user.email, user.district);
        fclose(inFile);
    }
}

/* 该函数为管理员的功能菜单，通过对下级函数的调用来实现对用户预订的管理
 该函数无返回值 */
void admin_Arrange1()
{
    for(;;){
        printf("                  主菜单\n");
        printf("       ===========================\n");
        printf("       1.查看用户预定情况\n");
        printf("       2.统计用户预定信息\n");
        printf("       3.返回上一级\n");
        printf("       ===========================\n");
        printf("       请选择下一步操作：");
        scanf("%s", choice);
        while(inputValidation(choice) != YES)                // 输入检测
        {
            printf("输入错误，请重新输入。\n");
            scanf("%s", choice);
        }
        switch (atoi(choice))
        {
            case 1:
            	system("cls");
                admin_Search();                            // 可查看用户的预订信息
                break;
            case 2:
            	system("cls");
                admin_Statistics();                        //  对用户预订信息进行检索
                break;
            case 3:
            	system("cls");
                return;                                    // 返回上一级
            default:
            	system("cls");
                printf("输入错误，请重新输入！\n");
                break;
        }
    }
}

/* 该函数为管理员的功能菜单，通过对下级函数的调用来实现对场地的管理
 该函数无返回值 */
void admin_Arrange2()
{
    for(;;){
        printf("                  主菜单\n");
        printf("       ===========================\n");
        printf("       1.场地查询\n");
        printf("       2.场地添加\n");
        printf("       3.返回上一级\n");
        printf("       ===========================\n");
        printf("       请选择下一步操作：");
        scanf("%s", choice);
        while(inputValidation(choice) != YES){            // 输入检测
            printf("输入错误，请重新输入。\n");
            scanf("%s", choice);
        }
        switch (atoi(choice)) {
            case 1:
            	system("cls");
                admin_siteInformation();                // 具体的场地信息查询
                break;
            case 2:
            	system("cls");
                admin_addSite();                        // 进行添加一个场地的操作
                break;
            case 3:
            	system("cls");
                return;                                 // 返回上一级
             default:
			 	system("cls");
				printf("输入错误，请重新输入！\n");
				break; 
        }
    }
}

/* 检测管理员账号查看用户预定情况 打开所属场地订单文件夹读取订单信息 */
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
    
    if(strcmp("admin01",username)==0)//检验所登录的管理员账号
    {
        op=1;
        adminRegistry = fopen("Registry_sites_admin01.txt", "r");
        if (adminRegistry == NULL){          //检验是否成功打开文件
            printf("场地注册表打开失败。请重试\n");
            exit(1);
        }
    }
    else if(strcmp("admin02",username)==0)//检验所登录的管理员账号
    {
        op=2;
        adminRegistry = fopen("Registry_sites_admin02.txt", "r");
        if (adminRegistry == NULL){          //检验是否成功打开文件
            printf("场地注册表打开失败。请重试\n");
            exit(1);
        }
    }
    else if(strcmp("admin03",username)==0)//检验所登录的管理员账号
    {
        op=3;
        adminRegistry = fopen("Registry_sites_admin03.txt", "r");
        if (adminRegistry == NULL){          //检验是否成功打开文件
            printf("场地注册表打开失败。请重试\n");
            exit(1);
        }
    }
    
    while (fscanf(adminRegistry, "%s %s %s %s %s %d %d %d %d ",recordedSites[sitesNum].siteID, recordedSites[sitesNum].area, recordedSites[sitesNum].venue,recordedSites[sitesNum].sportType,recordedSites[sitesNum].intro,&recordedSites[sitesNum].minAge, &recordedSites[sitesNum].maxAge, &recordedSites[sitesNum].rent, &recordedSites[sitesNum].number) != EOF) {       //读取管理员名下已有的场地数
        sitesNum++;
    }
    fclose(adminRegistry);
    
    for (j = 0; j < sitesNum; j++) {
        sprintf(sitesOrderFileName, "%sorder.txt", recordedSites[j].siteID);
        sitesOrderFile = fopen(sitesOrderFileName, "r");
        if (sitesOrderFile == NULL){          //检验是否成功打开文件
            printf("场地订单文件打开失败。请重试\n");
            exit(1);
        }
        printf("%s的订单有：\n", recordedSites[j].sportType);
        while (fscanf(sitesOrderFile, "%s %s %s %s %d %d %d", orders[orderNum].orderID, orders[orderNum].orderDate, orders[orderNum].siteID,orders[orderNum].useDate, &orders[orderNum].timeInterval, &orders[orderNum].isOnTime, &orders[orderNum].sex) !=EOF){
            printf("%s %s %s %s %d %d %d\n",orders[orderNum].orderID, orders[orderNum].orderDate, orders[orderNum].siteID,orders[orderNum].useDate, orders[orderNum].timeInterval,orders[orderNum].isOnTime,orders[orderNum].sex);//读取每一个订单
            orderNum++;//记录订单数量
        }
        fclose(sitesOrderFile);
        if(orderNum==0){
            printf("没有订单\n");
        }
        orderNum = 0;
    }
}

/* 检测管理员账号，统计订单情况，感觉场地多少声明数组进行冒泡排序预定量营业额 */
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
    
    if(strcmp("admin01",username)==0)//检验所登录的管理员账号
    {
        op=1;
        adminRegistry = fopen("Registry_sites_admin01.txt", "r");
        if (adminRegistry == NULL){          //检验是否成功打开文件
            printf("场地注册表打开失败。请重试\n");
            exit(1);
        }
    }
    else if(strcmp("admin02",username)==0)//检验所登录的管理员账号
    {
        op=2;
        adminRegistry = fopen("Registry_sites_admin02.txt", "r");
        if (adminRegistry == NULL){          //检验是否成功打开文件
            printf("场地注册表打开失败。请重试\n");
            exit(1);
        }
    }
    else if(strcmp("admin03",username)==0)//检验所登录的管理员账号
    {
        op=3;
        adminRegistry = fopen("Registry_sites_admin03.txt", "r");
        if (adminRegistry == NULL){          //检验是否成功打开文件
            printf("场地注册表打开失败。请重试\n");
            exit(1);
        }
    }
    
    while (fscanf(adminRegistry, "%s %s %s %s %s %d %d %d %d ",recordedSites[sitesNum].siteID, recordedSites[sitesNum].area,           recordedSites[sitesNum].venue,recordedSites[sitesNum].sportType,recordedSites[sitesNum].intro,&recordedSites[sitesNum].minAge, &recordedSites[sitesNum].maxAge, &recordedSites[sitesNum].rent, &recordedSites[sitesNum].number) != EOF) {       //读取管理员名下已有的场地数
        sitesNum++;
    }
    fclose(adminRegistry);
    
    for(;;){
    	
        int *num = (int *)malloc(sitesNum * sizeof(int));//声明动态数组
        int *snum = (int *)malloc(sitesNum * sizeof(int));
        for (j = 0; j < sitesNum; j++) {
            *(snum + j) = j;
        }
        printf("       ===========================\n");
        printf("       1.预定量排序\n");
        printf("       2.最受欢迎的运动男/女\n");
        printf("       3.营业额排序\n");
        printf("       4.返回上一级\n");
        printf("       ===========================\n");
        printf("       请选择下一步操作：");
        scanf("%s", choice);
        while(inputValidation(choice) != YES){
            printf("输入错误，请重新输入。\n");//输入检测
            scanf("%s", choice);
        }
        switch(atoi(choice)){
            case 1:
            	system("cls");
                for (j = 0; j < sitesNum; j++){
                    sprintf(filename, "%sorder.txt", recordedSites[j].siteID);
                    sitesOrder = fopen(filename, "r");
                    if (sitesOrder == NULL){
                        printf("文件打开失败。\n");
                        exit(1);
                    }
                    while(!feof(sitesOrder)){
                        flag = fgetc(sitesOrder);
                        if(flag == '\n')
                            count++;//读取行数
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
                            snum[j+1]=k; //冒泡排序
                        }
                    }
                }
                printf("按预订量由低到高排序为： \n");
                
                for (j = 0; j < sitesNum; j++) {
                    printf("场地：%-15s", recordedSites[*(snum + j)].sportType);
                    printf("预定量为： %d\n", num[j]);
                }
                
                free(num);//释放内存
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
                        printf("文件打开失败。\n");
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
                
                for(m = 0; m < sitesNum-1; ++m){//冒泡排序
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
                printf("按营业额由低到高排序为： \n");
                
                for (j = 0; j < sitesNum; j++) {
                    printf("场地：%-15s", recordedSites[*(snum + j)].sportType);
                    printf("营业额为： %d元\n", num[j] * recordedSites[snum[j]].rent);
                }
                free(num);
                free(snum);//释放内存
                break;
            case 4:
            	system("cls");
                return;
            default:
     		 	system("cls");
                printf("输入错误，请重新输入！\n");
        }
    }
}

/* 分别统计男女订单信息，使用最大值排序找到 男性女性分别最多预定的场地 */
void admin_SexStatistics()
{
    int ordersNum = 0;          //对应场地的订单数
    int sitesNum = 0;           //已有的场地数
    int i, j, k;
    int max1, max2, maxNum;
    int count = 0;                  //记录某一性别订单数为零的场地数
    char filename[20];
    SITE recordedSites[20];
    ORDER siteOrder[50];
    FILE *Registry = NULL;
    FILE *sitesOrderFile;
    
    Registry = fopen("Registry_sites.txt", "r");               //打开总的注册表
    if (Registry == NULL){          //检验是否成功打开文件
        printf("场地注册表打开失败。请重试\n");
        exit(1);
    }
    
    while (fscanf(Registry, "%s %s %s %s %s %d %d %d %d ",recordedSites[sitesNum].siteID, recordedSites[sitesNum].area,           recordedSites[sitesNum].venue,recordedSites[sitesNum].sportType,recordedSites[sitesNum].intro,&recordedSites[sitesNum].minAge, &recordedSites[sitesNum].maxAge, &recordedSites[sitesNum].rent, &recordedSites[sitesNum].number) != EOF) {       //读取管理员名下已有的场地数
        sitesNum++;
    }
    fclose(Registry);
    
    int *mNum = (int *)malloc(sitesNum * sizeof(int));          //根据得到的场地数申请男性预定者数量数组
    int *fNum = (int *)malloc(sitesNum * sizeof(int));          //根据得到的场地数申请女性预定者数量数组
    //    int *snum = (int *)malloc(sitesNum * sizeof(int));          //场地下标
    for (i = 0; i < sitesNum; i++) {
        mNum[i] = 0;
        fNum[i] = 0;
    }
    
    for ( i = 0; i < sitesNum; i++){
        sprintf(filename, "%sorder.txt", recordedSites[i].siteID);
        sitesOrderFile = fopen(filename, "r");
        if (sitesOrderFile == NULL){//检验是否打开文件
            printf("%s订单文件打开失败。", recordedSites[i].siteID);
            exit(1);
        }
        
        while (fscanf(sitesOrderFile, "%s %s %s %s %d %d %d", siteOrder[ordersNum].orderID, siteOrder[ordersNum].orderDate, siteOrder[ordersNum].siteID, siteOrder[ordersNum].useDate, &siteOrder[ordersNum].timeInterval, &siteOrder[ordersNum].isOnTime, &siteOrder[ordersNum].sex) !=EOF){
            ordersNum++;
        }
        fclose(sitesOrderFile);
        if(sitesNum == 0){
            printf("%s没有订单\n", recordedSites[i].sportType);
        }
        
        for(j = 0; j < ordersNum; j++){
            if (siteOrder[j].sex == 1) {
                mNum[i]++;//男性订单计数
            }
            else if (siteOrder[j].sex == 0) {
                fNum[i]++;//女性订单计数
            }
        }
        ordersNum = 0;
    }
    
    /* 找出男性最爱的场地:找出mNum[]中数量最大对应的场地 */
    max1=mNum[0];
    maxNum = 0;
    for(k = 1; k < sitesNum; k++) {
        if( mNum[k]>=max1 ){
            max1 = mNum[k];
            maxNum = k;//找出最大值的排序
        }
    }
    
    for (i = 0; i < sitesNum; i++) {
        if (mNum[i] == 0) {
            count++;//男性订单数计数
        }
    }
    
    if(count < sitesNum){
        printf("男性客人最爱的场地是：%s\n", recordedSites[maxNum].sportType);
    } else {
        printf("没有男性的订单，无法统计分析男性最爱的场地。\n");
    }
    count = 0;          //使count归零，准备给空女性订单场地计数
    
    /* 找出女性最爱的场地:找出fNum[]中数量最大对应的场地 */
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
            count++;//女性订单数计数
        }
    }
    
    if(count < sitesNum){
        printf("女性客人最爱的场地是：%s\n", recordedSites[maxNum].sportType);
    } else {
        printf("没有女性的订单，无法统计分析女性最爱的场地。\n");
    }
}

/* 场地信息查询函数 */
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
        if (adminRegistry == NULL){          //检验是否成功打开文件
            printf("场地注册表打开失败。请重试\n");
            exit(1);
        }
    }
    else if(strcmp("admin02",username)==0)
    {
        op=2;
        adminRegistry = fopen("Registry_sites_admin02.txt", "r");
        if (adminRegistry == NULL){          //检验是否成功打开文件
            printf("场地注册表打开失败。请重试\n");
            exit(1);
        }
    }
    else if(strcmp("admin03",username)==0)
    {
        op=3;
        adminRegistry = fopen("Registry_sites_admin03.txt", "r");
        if (adminRegistry == NULL){          //检验是否成功打开文件
            printf("场地注册表打开失败。请重试\n");
            exit(1);
        }
    }
    
    printf("您所管理的场地有：\n");
    while(fscanf(adminRegistry,"%s %s %s %s %s %d %d %d %d", sites[i].siteID, sites[i].area, sites[i].venue, sites[i].sportType,
                 sites[i].intro, &sites[i].minAge, &sites[i].maxAge, &sites[i].rent, &sites[i].number) != EOF){//读取场地文件
        printf("场地%d\n", i+1);
        printf("场地编号: %s\n所属区域：%s\n所属场馆：%s\n场地适合的运动类型：%s\n该场地适合的运动简介：%s\n准入年龄：%d-%d\n租金：%dRMB/2h\n",
               sites[i].siteID, sites[i].area, sites[i].venue, sites[i].sportType,
               sites[i].intro, sites[i].minAge, sites[i].maxAge, sites[i].rent);
        printf("\n");
        i++;
    }
    fclose(adminRegistry);
}

/* 用于用户场地的查询。其中调用 search_Site()，search_Gym()，search_District()，
 rentRank()，bookingRank() ，search_Hot()函数实现不同方式的查询功能。 */
void mainSearch(void)
{
    for(;;)
    {
        printf("       ===========================\n");
        printf("             请选择搜索方式     \n");
        printf("       ===========================\n");
        printf("       1.按场地名称查询\n");
        printf("       2.按场馆名称查询\n");
        printf("       3.按所属区域查询\n");
        printf("       4.按租金排序所有场地\n");
        printf("       5.按预定量排序所有场地\n");
        printf("       6.热门场地推荐\n");
        printf("       7.返回上一级\n");
        printf("       ===========================\n");
        printf("       \n");
        
        scanf("%s", choice);
        while(inputValidation(choice) != YES)
        {
            printf("输入错误，请重新输入。\n");
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
                return;      //跳出for循环，返回调用函数。
            default:
            	system("cls");
                printf("输入错误！\n");
                break;
        }
    }
}

/* 该函数用于显示上一级函数所需的某一个场地的详细信息，同时调用下一级函数screenAvalableInterval，为用户显示当前可预订的时段的同时让用户可以选择继续预订或者选择退出
    该函数没有返回值 */
void customer_getSiteInformation(char* siteID)
{
    
    SITE Site;
    char fileName[11];
    FILE* outFile = NULL;
    
    sprintf(fileName, "%s.txt", siteID);        // 将文件名写入fileName数组
    outFile = fopen(fileName, "r");
    
    fscanf(outFile,"%s %s %s %s %s %d %d %d %d", Site.siteID, Site.area, Site.venue, Site.sportType,
           Site.intro, &Site.minAge, &Site.maxAge, &Site.rent, &Site.number);                // 将场地信息从文件中读取出来
    printf("场地编号: %s\n所属区域：%s\n所属场馆：%s\n场地适合的运动类型：%s\n该场地适合的运动简介：%s\n准入年龄：%d-%d\n租金：%dRMB/2h\n",
           Site.siteID, Site.area, Site.venue, Site.sportType,Site.intro, Site.minAge, Site.maxAge, Site.rent);                    // 将场地信息打印在屏幕上
    fclose(outFile);
    
    printf("各个时间段租借情况如下: \n");
    screenAvalableInterval(siteID);            // 调用函数 screenAvalableInterval来显示该场地预订情况
    for(;;){
        printf("您可以：\n");
        printf("1. 对可用时间段进行预定\n");
        printf("2. 返回上一级菜单\n");
        printf("请选择您需要的操作：");
        scanf("%s", choice);
        while(inputValidation(choice) != YES){
            printf("输入错误，请重新输入。\n");
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
                printf("输入错误，请重新输入。\n");
        }
    }
}


/* 该函数用于实现按租金排序场地功能。 其中调用查询场地信息的customer_getSiteInformation()函数和过滤查询结果的search_filterSites函数。*/
void rentRank(void)
{
    int k,t;            //排序中间变量
    int m = 0;
    int i = 0;          //用于记录已有的场馆数量
    int j = 0;
    FILE *siteRegistry;
    SITE recordedSites[20];
    
    //打开场地注册表
    siteRegistry = fopen("Registry_sites.txt", "r");
    while (siteRegistry == NULL) {
        printf("查询失败：场地注册表打开失败。\n");
    }
    while (fscanf(siteRegistry, "%s %s %s %s %s %d %d %d %d", recordedSites[i].siteID, recordedSites[i].area, recordedSites[i].venue, recordedSites[i].sportType,recordedSites[i].intro,&recordedSites[i].minAge, &recordedSites[i].maxAge, &recordedSites[i].rent, &recordedSites[i].number) != EOF) {       //读出已有场地的所有信息
        i++;                //读取场地注册表文件，根据记录的条数确定场馆数量。
    }
    fclose(siteRegistry);
    
    int *num = (int *)malloc(i*sizeof(int));            //根据场馆数量i定义相应大小的数组，数组中元素为租金数值 。
    int *snum = (int *)malloc(i*sizeof(int));           //数组中元素为场地的序号。
    for (j = 0; j < i; j++) {
        num[j] = recordedSites[j].rent;                 //将每个场地的租金存入数组。
    }
    for (j = 0; j < i; j++) {
        snum[j] = j;
    }
    
    //冒泡排序
    for(m = 0; m < i-1; ++m){
        for(j = 0;j < i - 1 - m; ++j){
            if(num[j]>num[j+1]){
                t=num[j];               //交换租金数值的同时交换场地的序号。
                k=snum[j];
                num[j]=num[j+1];
                snum[j]=snum[j+1];
                num[j+1]=t;
                snum[j+1]=k;
            }
        }
    }
    
mark1:              //选择场地的返回点
    //输出排序后的场地名称及租金。
    printf("场地按租金排序（由低到高）为：\n");
    for (j = 0; j < i; j++) {
        printf("场地:%-15s租金:%d\n", recordedSites[snum[j]].sportType, recordedSites[snum[j]].rent);
    }
    
    //用户选择是否查看场馆具体信息 。
    printf("    是否需要将查询结果按有无可预定时间段进行筛选(并预定)？\n");
    printf("             1.是          2.否（返回上一级）         \n");
    scanf("%s", choice);
    while(inputValidation(choice) != YES){
        printf("输入错误，请重新输入。\n");
        printf("     是否需要将查询结果按有无可预定时间段进行筛选（并预定）？\n");
        printf("             1.是          2.否（返回上一级）        \n");
        scanf("%s", choice);
    }
    switch(atoi(choice))
    {
        case 1:
            search_filterSites(0);      //调用根据是否有可预定时间段筛选场地的函数
            goto mark1;         //用户选择返回上一级选项。
        case 2:
            free(num);
            free(snum);
            system("cls");
            return;             //返回上一级。
        default:
            printf("输入错误！\n");
            goto mark1;         //用户输入错误，返回到选择是否查看场地信息
    }
}

/* 该函数用于按预定量查询功能。 其中调用查询场地信息的customer_getSiteInformation()函数和过滤查询结果的search_filterSites函数。 */
void bookingRank(void)
{
    int k,t;
    char flag;          //'\n'标记
    char filename[20];
    int count = 0;      //订单数量计数变量
    int i = 0;          //用于记录已有的场馆数量
    int j = 0;
    int m = 0;
    FILE *siteRegistry;
    FILE *sitesOrder;
    SITE recordedSites[20];         //场馆结构体数组
    
    //打开场地注册表
    siteRegistry = fopen("Registry_sites.txt", "r");
    while (siteRegistry == NULL) {
        printf("查询失败：场地注册表打开失败。\n");
    }
    while (fscanf(siteRegistry, "%s %s %s %s %s %d %d %d %d", recordedSites[i].siteID, recordedSites[i].area, recordedSites[i].venue, recordedSites[i].sportType,recordedSites[i].intro,&recordedSites[i].minAge, &recordedSites[i].maxAge, &recordedSites[i].rent, &recordedSites[i].number) != EOF) {       //读出已有场地的所有信息
        i++;                //记录场地数目
    }
    fclose(siteRegistry);
    
    int *num = (int *)malloc(i*sizeof(int));            //根据场馆数量i定义相应大小的数组，数组中元素为预定量 。
    int *snum = (int *)malloc(i*sizeof(int));           //数组中元素为场地的序号。
    for (j = 0; j < i; j++) {
        *(snum + j) = j;
    }
    
    for (j = 0; j < i; j++){
        sprintf(filename, "%sorder.txt", recordedSites[j].siteID);
        sitesOrder = fopen(filename, "r");
        if (sitesOrder == NULL){
            printf("文件打开失败。\n");
            exit(1);
        }
        while(!feof(sitesOrder)){               //统计文件的行数作为预订量
            flag = fgetc(sitesOrder);           //用flag标记
            if(flag == '\n')
                count++;
        }
        *(num+j) = count;
        count = 0;
        fclose(sitesOrder);
    }
    
    //冒泡排序
    for(m = 0; m < i-1; ++m){
        for(j = 0;j < i - 1 - m; ++j){
            if(num[j]>num[j+1]){                //交换预定量数值的同时交换场地序号
                t=num[j];
                k=snum[j];
                num[j]=num[j+1];
                snum[j]=snum[j+1];
                num[j+1]=t;
                snum[j+1]=k;
            }
        }
    }
    
    
    //输出按与定量排序后的场地名称
mark1:               // 输入错误返回点
    printf("按预订量由低到高排序为： \n");
    for (j = 0; j < i; j++) {
        printf("场地：%-15s", recordedSites[*(snum + j)].sportType);
        printf("预定量为：%d\n", num[j]);
    }
    
    printf("    是否需要将查询结果按有无可预定时间段进行筛选（并预定）？\n");
    printf("             1.是          2.否（返回上一级）         \n");
    scanf("%s", choice);
    while(inputValidation(choice) != YES){
        printf("输入错误，请重新输入。\n");
        printf("     是否需要将查询结果按有无可预定时间段进行筛选（并预定）？\n");
        printf("             1.是          2.否(返回上一级)         \n");
        scanf("%s", choice);
    }
    switch(atoi(choice))
    {
        case 1:
            search_filterSites(0);      //调用根据是否有可预定时间段筛选场地的函数
            goto mark1;
        case 2:
        	system("cls");
            free(num);              //释放掉申请的内存空间
            free(snum);
            return;
        default:
            printf("输入错误！\n");
            goto mark1;             //用户输入错误后，返回到询问用户是否查看场地具体信息
    }
}

/* 该函数用于实现按场地查询功能。 其中调用查询场地信息的customer_getSiteInformation()函数和过滤查询结果的search_filterSites函数。 */
void search_Site(void)
{
    int i = 0;
    int j = 0;
    int option;
    FILE *siteRegistry;
    SITE recordedSites[20];         //场地结构体数组
    
    siteRegistry = fopen("Registry_sites.txt", "r");
    while (siteRegistry == NULL) {
        printf("查询失败：场地注册表打开失败。\n");
    }
    while (fscanf(siteRegistry, "%s %s %s %s %s %d %d %d %d", recordedSites[i].siteID, recordedSites[i].area, recordedSites[i].venue, recordedSites[i].sportType,recordedSites[i].intro,&recordedSites[i].minAge, &recordedSites[i].maxAge, &recordedSites[i].rent, &recordedSites[i].number) != EOF) {       //读出已有场地的所有信息
        i++;                //记录场地数目
    }
    fclose(siteRegistry);
    for(;;){
        printf("              所有场地名单\n");
        printf("       ===========================\n");
        /* 遍历结构数组打出所有场地名供用户选择 */
        for (j = 0; j < i; j++) {           //注意i的数量是场馆的数量，j是数组的下标，从0开始
            printf("       %d. %s\n", j+1, recordedSites[j].sportType);
        }
        printf("       ===========================\n");
        printf("是否需要将查询结果按有无可预定时间段进行筛选（并预定）？(y/n)");
        scanf("%s", choice);
        while(strcmp(choice, "y") != 0 && strcmp(choice, "n") != 0){
            printf("输入错误，请输入'y'（是）或'n'（否）来进行选择。\n");
            printf("是否需要将查询结果按有无可预定时间段进行筛选（并预定）？(y/n)");
            scanf("%s", choice);
        }
        if (!strcmp("y", choice)){
            search_filterSites(0);          //调用函数，对查询结果进行筛选，预定
        } else {
            printf("请选择您想进一步了解和预定的场地(或输入“0”返回上一级):");
            scanf("%s", choice);
            while(inputValidation(choice) != YES || atoi(choice) > i){
                printf("输入错误，请重新输入。\n");
                printf("请选择场地: ");
                scanf("%s", choice);
            }
            option = atoi(choice);          //把选项转化为数字作为查找用户选择的场馆信息的依据
            if (option == 0){
            	system("cls");
                return;                     //返回mainSearch()函数
            }
            system("cls");
            customer_getSiteInformation(recordedSites[option - 1].siteID);          //找出用户选择的相应场馆在结构数组中的位置，把场馆ID传递给下一个函数
        }
    }
}

/* 该函数用于实现按场馆查询功能。 其中调用查询场地信息的customer_getSiteInformation()函数和过滤查询结果的search_filterSites函数。 */
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
        printf("             请选择场馆     \n");
        printf("1.西土城体育馆\n2.沙河体育馆\n3.宏福体育馆\n4.返回\n");
        scanf("%s", choice);
        while(inputValidation(choice) != YES){
            printf("输入错误，请重新输入。\n");
            scanf("%s", choice);
        }
        switch(atoi(choice))
        {
            case 1:
            	system("cls");
                //打开场地注册表文件
                siteRegistry = fopen("Registry_sites_admin01.txt", "r");
                while (siteRegistry == NULL) {
                    printf("查询失败：场地注册表打开失败。\n");
                }
                while (fscanf(siteRegistry, "%s %s %s %s %s %d %d %d %d", recordedSites[i].siteID, recordedSites[i].area, recordedSites[i].venue, recordedSites[i].sportType,recordedSites[i].intro,&recordedSites[i].minAge, &recordedSites[i].maxAge, &recordedSites[i].rent, &recordedSites[i].number) != EOF) {       //读出已有场地的所有信息
                    i++;             //场地数量计数
                }
                fclose(siteRegistry);
            mark2:                   //查看具体场馆的信息后的返回点
                printf("          西土城体育馆场地名单\n");
                printf("       ===========================\n");
                /* 遍历结构数组打出所有场地名供用户选择 */
                for (j = 0; j < i; j++) {           //注意i的数量是场馆的数量，j是数组的下标
                    printf("       %d. %s\n", j+1, recordedSites[j].sportType);
                }
                printf("       ===========================\n");
                printf("是否需要将查询结果按有无可预定时间段进行筛选（并预定）？(y/n)");
                scanf("%s", choice);
                while(strcmp(choice, "y") != 0 && strcmp(choice, "n") != 0){
                    printf("输入错误，请输入'y'（是）或'n'（否）来进行选择。\n");
                    printf("是否需要将查询结果按有无可预定时间段进行筛选（并预定）？(y/n)");
                    scanf("%s", choice);
                }
                if (!strcmp("y", choice)){
                    search_filterSites(1);          //调用函数，对查询结果进行筛选，预定
                    goto mark2;
                } else {
                    printf("请选择您想进一步了解和预定的场地(或输入“0”返回上一级):");
                    scanf("%s", choice);
                    while(inputValidation(choice) != YES || atoi(choice) > i){
                        printf("输入错误，请重新输入。\n");
                        printf("请选择您想进一步了解和预定的场地(或输入“0”返回上一级):");
                        scanf("%s", choice);
                    }
                    option = atoi(choice);          //把选项转化为数字作为查找用户选择的场馆信息的依据
                    if (option == 0){
                        i = 0;         //场馆数目清零
                        system("cls");
                        goto mark1;       //返回，重新进行场馆选择。
                    }
                    system("cls");
                    customer_getSiteInformation(recordedSites[option - 1].siteID);          //找出用户选择的相应场馆在结构数组中的位置，把场馆ID传递给下一个函数
                    goto mark2;
                }
                
            case 2:
            	system("cls");
                siteRegistry = fopen("Registry_sites_admin02.txt", "r");
                while (siteRegistry == NULL) {
                    printf("查询失败：场地注册表打开失败。\n");
                }
                while (fscanf(siteRegistry, "%s %s %s %s %s %d %d %d %d", recordedSites[i].siteID, recordedSites[i].area, recordedSites[i].venue, recordedSites[i].sportType,recordedSites[i].intro,&recordedSites[i].minAge, &recordedSites[i].maxAge, &recordedSites[i].rent, &recordedSites[i].number) != EOF) {       //读出已有场地的所有信息
                    i++;
                }
                fclose(siteRegistry);
                
            mark3:                  //返回点
                printf("           沙河体育馆场地名单\n");
                printf("       ===========================\n");
                /* 遍历结构数组打出所有场地名供用户选择 */
                for (j = 0; j < i; j++) {           //注意i的数量是场馆的数量，j是数组的下标
                    printf("       %d. %s\n", j+1, recordedSites[j].sportType);
                }
                printf("       ===========================\n");
                printf("是否需要将查询结果按有无可预定时间段进行筛选（并预定）？(y/n)");
                scanf("%s", choice);
                while(strcmp(choice, "y") != 0 && strcmp(choice, "n") != 0){
                    printf("输入错误，请输入'y'（是）或'n'（否）来进行选择。\n");
                    printf("是否需要将查询结果按有无可预定时间段进行筛选（并预定）？(y/n)");
                    scanf("%s", choice);
                }
                if (!strcmp("y", choice)){
                    search_filterSites(2);          //调用函数，对查询结果进行筛选，预定
                    goto mark3;
                } else {
                    printf("请选择您想进一步了解和预定的场地(或输入“0”返回上一级):");
                    scanf("%s", choice);
                    while(inputValidation(choice) != YES || atoi(choice) > i){
                        printf("输入错误，请重新输入。\n");
                        printf("请选择您想进一步了解和预定的场地(或输入“0”返回上一级):");
                        scanf("%s", choice);
                    }
                    option = atoi(choice);          //把选项转化为数字作为查找用户选择的场馆信息的依据
                    if (option == 0){
                        i = 0;
                        system("cls");
                        goto mark1;
                    }
                    system("cls");
                    customer_getSiteInformation(recordedSites[option - 1].siteID);          //找出用户选择的相应场馆在结构数组中的位置，把场馆ID传递给下一个函数
                    goto mark3;
                }
                
            case 3:
            	system("cls");
                siteRegistry = fopen("Registry_sites_admin03.txt", "r");
                while (siteRegistry == NULL) {
                    printf("查询失败：场地注册表打开失败。\n");
                }
                while (fscanf(siteRegistry, "%s %s %s %s %s %d %d %d %d", recordedSites[i].siteID, recordedSites[i].area, recordedSites[i].venue, recordedSites[i].sportType,recordedSites[i].intro,&recordedSites[i].minAge, &recordedSites[i].maxAge, &recordedSites[i].rent, &recordedSites[i].number) != EOF) {       //读出已有场地的所有信息
                    i++;
                }
                fclose(siteRegistry);
            mark4:
                /* 遍历结构数组打出所有场地名供用户选择 */
                printf("           宏福体育馆场地名单\n");
                printf("       ===========================\n");
                for (j = 0; j < i; j++) {           //注意i的数量是场馆的数量，j是数组的下标
                    printf("       %d. %s\n", j+1, recordedSites[j].sportType);
                }
                printf("       ===========================\n");
                printf("是否需要将查询结果按有无可预定时间段进行筛选(并预定)？(y/n)");
                scanf("%s", choice);
                while(strcmp(choice, "y") != 0 && strcmp(choice, "n") != 0){
                    printf("输入错误，请输入'y'（是）或'n'（否）来进行选择。\n");
                    printf("是否需要将查询结果按有无可预定时间段进行筛选(并预定)？(y/n)");
                    scanf("%s", choice);
                }
                if (!strcmp("y", choice)){
                    search_filterSites(3);          //调用函数，对查询结果进行筛选，预定
                    goto mark4;
                } else {
                    printf("请选择您想进一步了解和预定的场地(或输入“0”返回上一级):");
                    scanf("%s", choice);
                    while(inputValidation(choice) != YES || atoi(choice) > i){
                        printf("输入错误，请重新输入。\n");
                        printf("请选择您想进一步了解和预定的场地(或输入“0”返回上一级):");
                        scanf("%s", choice);
                    }
                    option = atoi(choice);          //把选项转化为数字作为查找用户选择的场馆信息的依据
                    if (option == 0){
                        i = 0;
                        system("cls");
                        goto mark1;
                    }
                    system("cls");
                    customer_getSiteInformation(recordedSites[option - 1].siteID);          //找出用户选择的相应场馆在结构数组中的位置，把场馆ID传递给下一个函数
                    goto mark4;
                }
            case 4:
            	system("cls");
                return;
            default:
            	system("cls");
                printf("输入错误！\n");
                break;
        }
    }
}

/* 该函数用于实现按地区查询功能。 其中调用查询场地信息的customer_getSiteInformation()函数和过滤查询结果的search_filterSites函数。 */
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
        printf("             请选择区域     \n");
        printf("1.西土城\n2.沙河\n3.宏福\n4.返回\n");
        scanf("%s", choice);
        while(inputValidation(choice) != YES){
            printf("输入错误，请重新输入。\n");
            printf("             请选择区域     \n");
            printf("1.西土城\n2.沙河\n3.宏福\n4.返回\n");
            scanf("%s", choice);
        }
        switch(atoi(choice))
        {
            case 1:
            	system("cls");
                //打开场地注册表文件
                siteRegistry = fopen("Registry_sites_admin01.txt", "r");
                while (siteRegistry == NULL) {
                    printf("查询失败：场地注册表打开失败。\n");
                }
                while (fscanf(siteRegistry, "%s %s %s %s %s %d %d %d %d", recordedSites[i].siteID, recordedSites[i].area, recordedSites[i].venue, recordedSites[i].sportType,recordedSites[i].intro,&recordedSites[i].minAge, &recordedSites[i].maxAge, &recordedSites[i].rent, &recordedSites[i].number) != EOF) {       //读出已有场地的所有信息
                    i++;            //场地数目计数
                }
                fclose(siteRegistry);
            mark2:                  //返回点
                /* 遍历结构数组打出所有场地名供用户选择 */
                printf("            西土城体育馆场地名单\n");
                printf("       ===========================\n");
                for (j = 0; j < i; j++) {           //注意i的数量是场馆的数量，j是数组的下标
                    printf("       %d. %s\n", j+1, recordedSites[j].sportType);
                }
                printf("       ===========================\n");
                printf("是否需要将查询结果按有无可预定时间段进行筛选(并预定)？(y/n)");
                scanf("%s", choice);
                while(strcmp(choice, "y") != 0 && strcmp(choice, "n") != 0){
                    printf("输入错误，请输入'y'（是）或'n'（否）来进行选择。\n");
                    printf("是否需要将查询结果按有无可预定时间段进行筛选（并预定）？(y/n)");
                    scanf("%s", choice);
                }
                if (!strcmp("y", choice)){
                    search_filterSites(1);          //调用函数，对查询结果进行筛选，预定
                    goto mark2;
                } else {
                    printf("请选择您想进一步了解和预定的场地(或输入“0”返回上一级):");
                    scanf("%s", choice);
                    while(inputValidation(choice) != YES || atoi(choice) > i){
                        printf("输入错误，请重新输入。\n");
                        printf("请选择您想进一步了解和预定的场地(或输入“0”返回上一级):");
                        scanf("%s", choice);
                    }
                    option = atoi(choice);          //把选项转化为数字作为查找用户选择的场馆信息的依据
                    if (option == 0){
                        i = 0;
                        system("cls");
                        goto mark1;
                    }
                    system("cls");
                    customer_getSiteInformation(recordedSites[option - 1].siteID);          //找出用户选择的相应场馆在结构数组中的位置，把场馆ID传递给下一个函数
                    goto mark2;
                }
                
            case 2:
            	system("cls");
                siteRegistry = fopen("Registry_sites_admin02.txt", "r");
                while (siteRegistry == NULL) {
                    printf("查询失败：场地注册表打开失败。\n");
                }
                while (fscanf(siteRegistry, "%s %s %s %s %s %d %d %d %d", recordedSites[i].siteID, recordedSites[i].area, recordedSites[i].venue, recordedSites[i].sportType,recordedSites[i].intro,&recordedSites[i].minAge, &recordedSites[i].maxAge, &recordedSites[i].rent, &recordedSites[i].number) != EOF) {       //读出已有场地的所有信息
                    i++;
                }
                fclose(siteRegistry);
            mark3:
                printf("             沙河体育馆场地名单\n");
                printf("       ===========================\n");
                /* 遍历结构数组打出所有场地名供用户选择 */
                for (j = 0; j < i; j++) {           //注意i的数量是场馆的数量，j是数组的下标
                    printf("       %d. %s\n", j+1, recordedSites[j].sportType);
                }
                printf("       ===========================\n");
                printf("是否需要将查询结果按有无可预定时间段进行筛选(并预定)？(y/n)");
                scanf("%s", choice);
                while(strcmp(choice, "y") != 0 && strcmp(choice, "n") != 0){
                    printf("输入错误，请输入'y'（是）或'n'（否）来进行选择。\n");
                    printf("是否需要将查询结果按有无可预定时间段进行筛选(并预定)？(y/n)");
                    scanf("%s", choice);
                }
                if (!strcmp("y", choice)){
                    search_filterSites(2);          //调用函数，对查询结果进行筛选，预定
                    goto mark3;
                } else {
                    printf("请选择您想进一步了解和预定的场地(或输入“0”返回上一级):");
                    scanf("%s", choice);
                    while(inputValidation(choice) != YES || atoi(choice) > i){
                        printf("输入错误，请重新输入。\n");
                        printf("请选择您想进一步了解和预定的场地(或输入“0”返回上一级):");
                        scanf("%s", choice);
                    }
                    option = atoi(choice);          //把选项转化为数字作为查找用户选择的场馆信息的依据
                    if (option == 0){
                        i = 0;
                        system("cls");
                        goto mark1;
                    }
                    system("cls");
                    customer_getSiteInformation(recordedSites[option - 1].siteID);          //找出用户选择的相应场馆在结构数组中的位置，把场馆ID传递给下一个函数
                    goto mark3;
                }
                
            case 3:
            	system("cls");
                siteRegistry = fopen("Registry_sites_admin03.txt", "r");
                while (siteRegistry == NULL) {
                    printf("查询失败：场地注册表打开失败。\n");
                }
                while (fscanf(siteRegistry, "%s %s %s %s %s %d %d %d %d", recordedSites[i].siteID, recordedSites[i].area, recordedSites[i].venue, recordedSites[i].sportType,recordedSites[i].intro,&recordedSites[i].minAge, &recordedSites[i].maxAge, &recordedSites[i].rent, &recordedSites[i].number) != EOF) {       //读出已有场地的所有信息
                    i++;
                }
                fclose(siteRegistry);
            mark4:
                printf("             宏福体育馆场地名单\n");
                printf("       ===========================\n");
                /* 遍历结构数组打出所有场地名供用户选择 */
                for (j = 0; j < i; j++) {           //注意i的数量是场馆的数量，j是数组的下标
                    printf("       %d. %s\n", j+1, recordedSites[j].sportType);
                }
                printf("       ===========================\n");
                printf("是否需要将查询结果按有无可预定时间段进行筛选(并预定)？(y/n)");
                scanf("%s", choice);
                while(strcmp(choice, "y") != 0 && strcmp(choice, "n") != 0){
                    printf("输入错误，请输入'y'（是）或'n'（否）来进行选择。\n");
                    printf("是否需要将查询结果按有无可预定时间段进行筛选(并预定)？(y/n)");
                    scanf("%s", choice);
                }
                if (!strcmp("y", choice)){
                    search_filterSites(3);          //调用函数，对查询结果进行筛选，预定
                    goto mark4;
                } else {
                    printf("请选择您想进一步了解和预定的场地(或输入“0”返回上一级):");
                    scanf("%s", choice);
                    while(inputValidation(choice) != YES || atoi(choice) > i){
                        printf("输入错误，请重新输入。\n");
                        printf("请选择您想进一步了解和预定的场地(或输入“0”返回上一级):");
                        scanf("%s", choice);
                    }
                    option = atoi(choice);          //把选项转化为数字作为查找用户选择的场馆信息的依据
                    if (option == 0){
                        i = 0;
                        system("cls");
                        goto mark1;
                    }
                    system("cls");
                    customer_getSiteInformation(recordedSites[option - 1].siteID);          //找出用户选择的相应场馆在结构数组中的位置，把场馆ID传递给下一个函数
                    goto mark4;
                }
                
            case 4:
            	system("cls");
                return;              //返回 mianSearch()函数
            default:
            	system("cls");
                printf("输入错误！\n");
                break;
        }
    }
}

/* 该函数用于实现热门场地推荐功能。 其中调用查询场地信息的customer_getSiteInformation()函数。 */
void search_Hot(void)
{
    int k,t;
    char flag;              //'\n'标记
    char filename[20];
    int count = 0;      //订单数量计数变量
    int m = 0;
    int i = 0;          //用于记录已有的场馆数量
    int j = 0;
    FILE *siteRegistry;
    FILE *sitesOrder;
    SITE recordedSites[20];
    
    siteRegistry = fopen("Registry_sites.txt", "r");
    while (siteRegistry == NULL) {
        printf("查询失败：场地注册表打开失败。\n");
    }
    while (fscanf(siteRegistry, "%s %s %s %s %s %d %d %d %d", recordedSites[i].siteID, recordedSites[i].area, recordedSites[i].venue, recordedSites[i].sportType,recordedSites[i].intro,&recordedSites[i].minAge, &recordedSites[i].maxAge, &recordedSites[i].rent, &recordedSites[i].number) != EOF) {       //读出已有场地的所有信息
        i++;
    }
    fclose(siteRegistry);
    
    int *num = (int *)malloc(i*sizeof(int));                //根据场馆数量i定义相应大小的数组，数组中元素为预定量 。
    int *snum = (int *)malloc(i*sizeof(int));               //数组中元素为场地的序号。
    for (j = 0; j < i; j++) {
        *(snum + j) = j;
    }
    
    for (j = 0; j < i; j++){
        sprintf(filename, "%sorder.txt", recordedSites[j].siteID);
        sitesOrder = fopen(filename, "r");
        if (sitesOrder == NULL){
            printf("文件打开失败。\n");
            exit(1);
        }
        while(!feof(sitesOrder)){               //统计文件的行数作为预订量
            flag = fgetc(sitesOrder);           //用flag标记
            if(flag == '\n')
                count++;
        }
        *(num+j) = count;
        count = 0;
        fclose(sitesOrder);
    }
    
    //冒泡排序
    for(m = 0; m < i-1; ++m){
        for(j = 0;j < i - 1 - m; ++j){
            if(num[j]>num[j+1]){                //交换预定量数值的同时交换场地序号
                t=num[j];
                k=snum[j];
                num[j]=num[j+1];
                snum[j]=snum[j+1];
                num[j+1]=t;
                snum[j+1]=k;
            }
        }
    }
    
    printf("当前热门场地是： %s。 已经有%d人预定过该场地！\n", recordedSites[snum[i-1]].sportType, num[i-1]);
    customer_getSiteInformation(recordedSites[snum[i-1]].siteID);
    
    free(num);          //释放掉申请的内存空间
    free(snum);
}

/* 该函数用于检测用户输入，在需要用户输入数字来选择的时候调用，确保用户输入的是数字而没有其他的字母 */
int inputValidation(char *input)
{
    int i;
    int isRightInput = NO;          //用于确定输入是否有错的标志变量
    for (i = 0; input[i] != '\0'; i++) {    //检查输入是否只包含数字
        if ((input[i] >= '0') && (input[i] <= '9')) {
            isRightInput = YES;
        }else{
            isRightInput = NO;
            break;
        }
    }
    
    return isRightInput;
}

/* 该函数用于检查用户登录时输入的用户名是否有效（已经注册过或者是登记的场馆管理员）
 该函数需要传入一个参数，用于判断是哪种类型的登录，从而打开不同的“注册表”来检查
 该函数还返回一个整型参数（“YES”或“NO”），用于确认用户名的有效性 */
int checkInputUsername(int type)
{
    int i = 0, j = 0;
    int isAnExistingUser = NO;          //用于确认用户名是否存在的标志
    char recordedNames[20][11];         //用于临时保存已注册用户用户名的二维数组
    FILE *Registry;
    if (type == 1){                     //如果登录类型为“1”，则为用户登录，打开用户的“注册表”
        Registry = fopen("Registry_users.txt","r");
        if (Registry == NULL){
            printf("用户注册表打开失败。请重试\n");
            exit(1);
        }
    } else {                            //如果登录类型为其他（“2”），则为管理员登录，打开管理员的“注册表”
        Registry = fopen("Registry_admins.txt","r");
        if (Registry == NULL){
            printf("管理员注册表打开失败。请重试\n");
            exit(1);
        }
    }
    
    for (i = 0; feof(Registry) == 0; i++){          //读取所有的注册过的用户名
        fscanf(Registry, "%s ", recordedNames[i]);
    }
    fclose(Registry);
    
    for (j = 0; j < i; j++){                        //把输入用户名和所有已注册的注册名进行比对，确定输入的用户名是否存在
        if (strcmp(recordedNames[j], username) == 0){
            isAnExistingUser = YES;
            break;
        }
    }
    
    return isAnExistingUser;
}

//将订单中编号为1-7的时间段转化为直观时间并赋给字符串指针，其参数分别为时间段编号以及 字符串指针
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

//用于检查用户输入的邮箱是否正确，其参数为用户所输入的邮箱，返回值为代表格式是否正确的0或1
int emailValid(char *email)
{
    char *ptrat;
    char *ptrdot;
    
    //检查输入邮箱中是否有"@"，以及"@"的前后是否有英文字母或数字
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
    
    //检查输入邮箱中是否有"."，以及"."的前后是否有英文字母或数字
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

/* 该函数首先获取本地的时间，转化为规范的形式，之后将文件名拼合为：场地信息加当前具体日期的规范文件名
 同时该函数能访问具体的文件并读取信息，反馈给用户可预订与不可预订的信息
 该函数没有返回值 */
void screenAvalableInterval(char *siteID)
{
    int i = 0, j = 0;
    FILE* fp = NULL;
    FILE* TEMP;
    char str[20] = "1 1 1 1 1 1 1 1 ";                // 初始预订情况
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
    ptr = localtime(&t);                            // 获取本地时间
    sprintf(year, "%d" , ptr->tm_year + 1900);        // 将年份存入变量 year
    sprintf(month, "%d" , ptr->tm_mon + 1);            // 将月份存入变量 month
    sprintf(day, "%d" , ptr->tm_mday);                // 将日期存入变量 day
    
    if(atoi(month)<10 && atoi(month)>0)                // 将 1-9月格式改为 01-09月
    {
        month[1]=month[0];
        month[0]='0';
        month[2]='\0';
    }
    
    if(atoi(day)<10 && atoi(day)>0)                    // 将 1-9日格式改为 01-09日
    {
        day[1]=day[0];
        day[0]='0';
        day[2]='\0';
    }
    
    sprintf(fileName, "%s%s%s%s.txt", siteID, year, month, day);        // 将文件名拼合
    
    fp = fopen(fileName, "r");
    TEMP = fopen("temp.txt","w+");
    if (fp == NULL){                    // 程序第一次检索场地信息文件，若不存在则创建一个新文件
        fclose(fp);
        fp = fopen(fileName, "w");
        fputs(str,fp);                    // 将初始场地预订信息写入该新文件中
        fclose(fp);
        fp = fopen(fileName, "r");
    }
    
    for(i=0;i<8;i++){                    // 筛选出符合条件的场地
        fscanf(fp,"%c ",&ch);
        if(ch == '1'){
            j++;
            timeTransfer(i, literalTime);
            printf("%d.    %s    可预订！\n", j, literalTime);
            fprintf(TEMP,"%d ",i);
        }
    }
    if (j == 0) {
        printf("对不起，该场地当天已无可预定场次。请返回选择其他场馆。\n");
    }
    fclose(TEMP);
    fclose(fp);
}

//用于计算两个月份和日期之前的天数差，传值为年份月份和日期，返回值为其月日之间的天数差
int total_day(int year,int month,int day)
{
    int sum = 0;
    
    //算出月日加起来的总天数
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
    
    //判断该年是否为闰年，为闰年则对2月的天数有一天的影响
    if(month >2){
        if(((year % 4 == 0)&&(year % 100 !=0))||(year % 400) == 0){
            sum = sum + 1;
        }
    }
    return sum;
}

//计算年与年之前的天数差 ，传入参数是分别要计算的两个年份，返回值为其相差的天数
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

/* 该函数用于让管理员对自己所管理的场馆添加场地 */
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
    
    /* 识别管理员，得到其管理的场馆信息 */
    if (!strcmp(username, "admin01")) {
        adminNum = 1;
        strcpy(newSite.area, "西土城");
        strcpy(newSite.venue, "西土城体育馆");
    } else if (!strcmp(username, "admin02")){
        adminNum = 2;
        strcpy(newSite.area, "沙河");
        strcpy(newSite.venue, "沙河体育馆");
    } else if (!strcmp(username, "admin03")){
        adminNum = 3;
        strcpy(newSite.area, "宏福");
        strcpy(newSite.venue, "宏福体育馆");
    }
    
    /* 打开相关场地注册表文件，读取已有场地信息，生成新场地信息 */
    Registry = fopen("Registry_sites.txt", "r");
    if (Registry == NULL){          //检验是否成功打开文件
        printf("场地注册表打开失败。请重试\n");
        exit(1);
    }
    while (fscanf(Registry, "%s %s %s %s %s %d %d %d %d ",recordedSites[i].siteID, recordedSites[i].area,           recordedSites[i].venue,recordedSites[i].sportType,recordedSites[i].intro,&recordedSites[i].minAge, &recordedSites[i].maxAge, &recordedSites[i].rent, &recordedSites[i].number) != EOF) {       //对已有场地进行计数
        i++;
    }
    newSite.number = i + 1;         //生成新场地编号：新场馆编号为已有场地数向后顺延
    fclose(Registry);
    i = 0;      //使i复位变0
    
    sprintf(adminRegistryName, "Registry_sites_%s.txt", username);      //生成管理员管理场馆的注册表文件名
    adminRegistry = fopen(adminRegistryName, "r");
    if (adminRegistry == NULL){
        printf("管理员场地注册表打开失败。请重试\n");
        exit(1);
    }
    while (fscanf(adminRegistry, "%s %s %s %s %s %d %d %d %d ",recordedSites[i].siteID, recordedSites[i].area,           recordedSites[i].venue,recordedSites[i].sportType,recordedSites[i].intro,&recordedSites[i].minAge, &recordedSites[i].maxAge, &recordedSites[i].rent, &recordedSites[i].number) != EOF) {       //读取管理员名下已有的场地数
        i++;
    }
    switch (adminNum) {         //生成新场地ID：为不同管理员所处场馆已有编号向后顺延
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
    
    /* 读入新场地基本信息 */
    printf("请输入新场地的场地名： ");
    scanf("%s", newSite.sportType);
    getchar();
    printf("请输入新场地运动类型的相关介绍： ");
    scanf("%[^\n]", newSite.intro);
    printf("请输入场地限制的最低年龄： ");
    scanf("%d", &newSite.minAge);
    printf("请输入场地限制的最高年龄： ");
    scanf("%d", &newSite.maxAge);
    printf("请输入场地每时段（2小时）的租金：");
    scanf("%d", &newSite.rent);
    
    /* 创建新场地的信息文件，写入刚才获得的信息。 */
    sprintf(newSitesInfoFileName, "%s.txt", newSite.siteID);
    newSitesInfoFile = fopen(newSitesInfoFileName, "w");
    if (newSitesInfoFile == NULL){
        printf("新场地信息文件创建失败。请重试\n");
        exit(1);
    }
    fprintf(newSitesInfoFile, "%s %s %s %s %s %d %d %d %d ",
            newSite.siteID, newSite.area, newSite.venue, newSite.sportType, newSite.intro,
            newSite.minAge, newSite.maxAge, newSite.rent, newSite.number);
    fclose(newSitesInfoFile);
    
    /* 创建新场地的订单文件 */
    sprintf(newSitesOrderFileName, "%sorder.txt", newSite.siteID);
    newSitesOrderFile = fopen(newSitesOrderFileName, "w");
    fclose(newSitesOrderFile);
    
    /* 把新场地ID分别写入到总的注册表以及管理员对应的注册表 */
    Registry = fopen("Registry_sites.txt", "a+");
    if (Registry == NULL){
        printf("场地注册表打开失败。请重试\n");
        exit(1);
    }
    adminRegistry = fopen(adminRegistryName, "a+");
    if (adminRegistry == NULL){
        printf("管理员场地注册表打开失败。请重试\n");
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
    printf("                   添加场地成功！       \n");
    printf("          ===========================\n");
    
}

/* 该函数用于筛选用户在场地查询中得到的结果，打印出可以预定的场地供用户了解详情及预订
 该函数接受一个整型值，用于判断用户场地查询的类型 */
void search_filterSites(int searchType)
{
    int i, j;
    int option;         //用以保存用户的选择（数字）
    int k = 0;
    int sitesNum = 0;           //用户查询的场地数
    int avaluableStatusNum = 0;         //场地可用时间的数量
    char intervalStatus;            //各时段可用情况的状态
    char str[20] = "1 1 1 1 1 1 1 1 ";          //全部时段可以预定的场地可用时段状态文件的内容
    char avaluableIntervalFileName[30];         //可用时段状态文件的文件名
    char year[10];          //可预定的日期的年
    char month[10];         //可预定日期的月
    char day[10];           //可预定日期的日
    SITE recordedSites[15];         //待筛选的所有场地信息
    SITE qualifiedSites[15];        //可以预定的场地
    FILE *sitesInfoFile = NULL;     //场地信息文件
    FILE *avaluableIntervalFile;    //可用时段状态文件
    struct tm *ptr;
    time_t t;
    
    if (searchType == 0) {              //根据用户要求筛选的场地（调用时得到），打开不同的场地信息文件
        sitesInfoFile = fopen("Registry_sites.txt", "r");
    } else if (searchType == 1) {
        sitesInfoFile = fopen("Registry_sites_admin01.txt", "r");
    } else if (searchType == 2) {
        sitesInfoFile = fopen("Registry_sites_admin02.txt", "r");
    } else if (searchType == 3) {
        sitesInfoFile = fopen("Registry_sites_admin03.txt", "r");
    }
    
    while (fscanf(sitesInfoFile, "%s %s %s %s %s %d %d %d %d ",recordedSites[sitesNum].siteID, recordedSites[sitesNum].area,           recordedSites[sitesNum].venue,recordedSites[sitesNum].sportType,recordedSites[sitesNum].intro,&recordedSites[sitesNum].minAge, &recordedSites[sitesNum].maxAge, &recordedSites[sitesNum].rent, &recordedSites[sitesNum].number) != EOF) {       //对已有场地进行计数
        sitesNum++;
    }
    fclose(sitesInfoFile);
    
    //获取可预定时间的日期，为打开文件作准备
    t =time(NULL);
    t = t + AWEEK;
    ptr = localtime(&t);
    sprintf(year, "%d" , ptr->tm_year + 1900);
    sprintf(month, "%d" , ptr->tm_mon + 1);
    sprintf(day, "%d" , ptr->tm_mday);
    
    if(atoi(month)<10 && atoi(month)>0)         //确保“月份”是两位
    {
        month[1]=month[0];
        month[0]='0';
        month[2]='\0';
    }
    
    if(atoi(day)<10 && atoi(day)>0)             //确保“天数”是两位
    {
        day[1]=day[0];
        day[0]='0';
        day[2]='\0';
    }
    
    printf("以下场地有空余时段(七天后当天)供预定：\n");
    for(i = 0; i < sitesNum; i++){              //依次检查筛选场地的可预定情况
        sprintf(avaluableIntervalFileName, "%s%s%s%s.txt",  recordedSites[i].siteID, year, month, day);         //生成场馆可用时段文件名
        
        avaluableIntervalFile = fopen(avaluableIntervalFileName, "r");          //尝试打开场地在特定日期的可用时段状态文件
        if (avaluableIntervalFile == NULL){                                     //若打开失败（不存在），则创建一个，并且使所有状态可用
            fclose(avaluableIntervalFile);
            avaluableIntervalFile = fopen(avaluableIntervalFileName, "w");
            fputs(str,avaluableIntervalFile);
            fclose(avaluableIntervalFile);
            avaluableIntervalFile = fopen(avaluableIntervalFileName, "r");
        }
        
        for(j = 0; j < 8; j++){                         //依次检查场地的可预定时段情况，并计数
            fscanf(avaluableIntervalFile, "%c " ,&intervalStatus);
            if(intervalStatus == '1'){
                avaluableStatusNum++;
            }
        }
        
        if(avaluableStatusNum != 0){                    //若可预定时段数量不为0，则打印出该场地，供用户稍后选择
            qualifiedSites[k] = recordedSites[i];
            k++;
            printf("%d. %s\n", k, recordedSites[i].sportType);
        }
        avaluableStatusNum = 0;             //使可用时段数量归零，为检查下一个场馆作准备
    }
    
    printf("请选择您想了解详细信息的场馆（输入“0”返回上一级）：");
    scanf("%s", choice);
    while(inputValidation(choice) != YES || atoi(choice) > i){
        printf("输入错误，请重新输入。\n");
        printf("请选择您想了解详细信息的场馆（输入“0”返回上一级）：");
        scanf("%s", choice);
    }
    option = atoi(choice);          //把选项转化为数字作为查找用户选择的场馆信息的依据
    if (option == 0){
    	system("cls");
        return;
    }
    system("cls");
    customer_getSiteInformation(qualifiedSites[option - 1].siteID);          //找出用户选择的相应场馆在结构数组中的位置，把场馆ID传递给下一个函数
}
