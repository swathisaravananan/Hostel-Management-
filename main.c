#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//global variables
int i,j,main_exit;




void menu();
void new_entry();
void edit();
void view_list();
void erase();
void see();
void sorter();
void messmenu();
void report();
void closer();


//defining structures
struct duedt{
    int mon,day,yr;
};
struct date{
    int month,day,year;
};
struct {


    char name[60];
    int age;
    char city[60];
    char mail_id[30];
    char room_no[8];
    char father_name[60];
    int father_phone;
    int phone;
    int fee;
    struct duedt due;
    char hostel_name[6];
    char roll_no[10];
    struct date dob;
    }add,upd,check,rem,sort;
struct staff_entry
    {
        char name[10];
        char dob[10];
        char blood_group[5];
        char phone_num[11];
        char section[20];
        char address[50];
        char father_name[10];
        char empdate[10];
    }new1,edit1,del;
void fee()
{
    system("cls");
    printf("**********FEE**********");
    FILE *fp1;
    char roll[10];
    int dt,mon,diff,yr,fine,total,a=1;
    printf("\n\nEnter roll number:");
    scanf("%s",roll);
    fp1=fopen("record.txt","r");
    printf("\nENTER TODAY'S DATE: ");
    scanf("%d/%d/%d",&dt,&mon,&yr);
    while(fscanf(fp1,"%s %s %d/%d/%d %d %s %d %s %s %d %s %s %d %d/%d/%d\n",add.roll_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.city, &add.phone, add.mail_id, add.father_name, &add.father_phone, add.room_no, add.hostel_name,&add.fee,&add.due.day,&add.due.mon,&add.due.yr)!=EOF)
    {
        if(strcmp(add.roll_no,roll)==0)
            {
                a=0;
                diff=abs(add.due.mon-mon);
                if(mon>add.due.mon || yr>add.due.yr)
                {
                    fine=diff*500;
                    total=fine+add.fee;
                    printf("\n\n Due date: %d/%d/%d",add.due.day,add.due.mon,add.due.yr);
                    printf("\n\n Fine: %d.00",fine);
                    printf("\n\n Total Amount to be paid(Mess Charges + Accomodation Charges): Rs. %d.00",total);
                }
                else
                {
                    printf("\n\n Due date: %d/%d/%d",add.due.day,add.due.mon,add.due.yr);
                    printf("\n\n Fine: 0.00");
                    printf("\n\n Total Amount to be paid(Mess Charges + Accomodation Charges): Rs.%d.00",add.fee);


                }
            }
        }
        if (a==1)
            printf("\n\nRECORD NOT FOUND");
        fclose(fp1);
        add_invalid:
    printf("\n\n\n\t\tEnter 2 to try again, 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    if (main_exit==1)
        menu();
    else if(main_exit==0)
            closer();
    else if(main_exit==2)
            fee();
    else
        {
            printf("\nInvalid!\a");
            goto add_invalid;
        }
    }
void block_info()
{
    printf("**********BH-1***********\n");
    FILE *fp1,*fp2,*fp3,*fp4;
    int count_BH1=0,count_BH2=0,count_BH3=0,count_GH1=0;
    char a,b,c,d;
    fp1 = fopen("BH-1.txt", "r");
    for(c=getc(fp1);c!=EOF;c=getc(fp1))
        if (c == '\n')
            count_BH1++;


    fclose(fp1);
    printf("NO. OF FLOORS: 5");
    printf("\nNO. OF ROOMS PER FLOOR: 20");
    printf("\nNO. OF MAXIMUM OCCUPANTS PER ROOM: 4");
    printf("\nBATHROOM: Attached");
    printf("\nOCCUPIED ROOMS:%d out of 100",count_BH1/4);
    printf("\nAVAILABLE ROOMS:%d out of 100",100-(count_BH1/4));
    printf("\nFEES: ₹60,000");
    printf("\n\n**********BH-2**********");
    fp2 = fopen("BH-2.txt", "r");
    for (a = getc(fp2); a != EOF; a = getc(fp2))
        if (a == '\n')
            count_BH2++;
    fclose(fp1);
    printf("\nNO. OF FLOORS: 7");
    printf("\nNO. OF ROOMS PER FLOOR: 25");
    printf("\nNO. OF MAXIMUM OCCUPANTS PER ROOM: 3");
    printf("\nBATHROOM: Attached");
    printf("\nOCCUPIED ROOMS: %d out of 175",count_BH2/3);
    printf("\nAVAILABLE ROOMS: %d out of 175",175-(count_BH2/3));
    printf("\nFEES: ₹82,000");
    printf("\n\n**********BH-3**********");
    fp3 = fopen("BH-3.txt", "r");
    for (b = getc(fp3); b != EOF; b = getc(fp3))
        if (b == '\n')
            count_BH3++;
    fclose(fp3);
    printf("\nNO. OF FLOORS: 4");
    printf("\nNO. OF ROOMS PER FLOOR: 15");
    printf("\nNO. OF MAXIMUM OCCUPANTS PER ROOM: 6");
    printf("\nBATHROOM: Not Attached");
    printf("\nOCCUPIED ROOMS: %d out of 60",count_BH3/6);
    printf("\nAVAILABLE ROOMS: %d out of 60",60-(count_BH3/6));
    printf("\nFEES: ₹40,000");
    printf("\n\n**********GH-1**********");
    fp4 = fopen("GH-1.txt", "r");
    for (d = getc(fp4); d != EOF; d = getc(fp4))
        if (d == '\n')
            count_GH1++;
    fclose(fp4);
    printf("NO. OF FLOORS: 8");
    printf("\nNO. OF ROOMS PER FLOOR: 30");
    printf("\nNO. OF MAXIMUM OCCUPANTS PER ROOM: 2");
    printf("\nBATHROOM: Attached");
    printf("\nOCCUPIED ROOMS: %d out of 240",count_GH1/2);
    printf("\nAVAILABLE ROOMS: %d out of 240",240-(count_GH1/2));
    printf("\nFEES: ₹85,000");
    view_list_invalid:
     printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);


        if (main_exit==1)
            menu();
        else if(main_exit==0)
            closer();
        else
        {
            printf("\nInvalid!\a");
            goto view_list_invalid;
        }
}
void staff_delete()
{
    system("CLS");
    FILE *old,*newrec;
    char del_name[10];
    old=fopen("staff_record.txt","r");
    newrec=fopen("staff_new.txt","a+");
    printf("Enter the name of staff whose data you want to delete:");
    scanf("%s",&del_name);
    rewind(old);
    while ((fread(&new1, sizeof(new1), 1, old)) > 0)
    {
        if (new1.name != del_name)
        {
            fwrite(&new1, sizeof(new1), 1, newrec);
        }
    }
    fclose(old);
    fclose(newrec);
    remove("staff_record.txt");
    rename("staff_new.txt","staff_record.txt");
    printf("Record Deleted");
    erase_invalid:
        printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
        scanf("%d",&main_exit);
        if (main_exit==1)
            menu();
        else if (main_exit==2)
            closer();
        else if(main_exit==0)
            erase();
        else
        {
                printf("\nInvalid!\a");
            goto erase_invalid;
                }
}


void staff_entry()
{


    system("CLS");
    FILE *ptr,*sec;
    ptr=fopen("staff_record.txt","a+");
    struct staff_entry new1;
    printf("\t\t\t\xB2\xB2\xB2 ADD STAFF DATA  \xB2\xB2\xB2\xB2");
    printf("\n Name :");
    scanf("%s",new1.name);
    printf("\n Date of Birth :");
    scanf("%s",new1.dob);
    printf("\n Phone number : ");
    scanf("%S",new1.phone_num);
    printf("\n Blood group :");
    scanf("%s",new1.blood_group);
    printf("\n Father's name :");
    scanf("%s",new1.father_name);
    printf("\n City :");
    scanf("%s",new1.address);
    printf("\n Enter Assigned Section\n\tEnter: Hostel Cleaning\n\t\tHostel Office \n\t\tGardener\n\t\tMess\n\t\tSecurity\n\t\tLaundry\n\t\tSweeper:");
    scanf("%s",new1.section);
    printf("\n Enter Date of Employment:");
    scanf("%s",new1.empdate);
    fprintf(ptr,"NAME: %s\nDOB: %s\nPHONE NO:%s\nBLOOD GROUP: %s\nFATHER'S NAME: %s\nEMPLOYED: %s\nSECTION:%s\nCITY: %s\n\n",new1.name, new1.dob, new1.phone_num, new1.blood_group, new1.father_name, new1.empdate, new1.section, new1.address);
    if(strcmp(new1.section,"Hostel Cleaning")==0)
        {
                sec=fopen("hostel_cleaning.dat","a+");
                fprintf(sec,"%s\n", new1.name);
                fclose(sec);
        }
        else if(strcmp(new1.section,"Hostel Office")==0)
        {
                sec=fopen("Hostel_Office.dat","a+");
                fprintf(sec, "%s\n", new1.name);
                fclose(sec);
        }
        else if(strcmp(new1.section,"Gardener")==0)
        {
                sec=fopen("gardener.dat","a+");
                fprintf(sec, "%s\n", new1.name);
                fclose(sec);
        }
        else if(strcmp(new1.section,"Sweeper")==0)
        {
                sec=fopen("Sweeper.dat","a+");
                fprintf(sec, "%s\n", new1.name);
                fclose(sec);
        }
        else if(strcmp(new1.section,"Mess")==0)
        {
                sec=fopen("Mess.dat","a+");
                fprintf(sec, "%s\n", new1.name);
                fclose(sec);
        }
        else if(strcmp(new1.section,"Security")==0)
        {
                sec=fopen("Security.dat","a+");
        fprintf(sec, "%s\n", new1.name);
                fclose(sec);
        }
        else if(strcmp(new1.section,"Laundry")==0)
        {
                sec=fopen("laundry.dat","a+");
                fprintf(sec, "%s\n", new1.name);
                fclose(sec);
        }
    fclose(ptr);
    printf("\nData entered successfully!");
    add_invalid:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);


    if (main_exit==1)


        menu();
    else if(main_exit==0)
            closer();
    else
        {
            printf("\nInvalid!\a");
            goto add_invalid;
        }
}
void staff_view()
{
    system("CLS");
    FILE *view;
    char c;
    int count_staff=0,test=0,count_hostel_office=0,count_sweeper=0,count_gardener=0,count_security=0,count_mess=0,count_laundry=0,count_hostelclean=0;
    view=fopen("staff_record.txt","r");
    while((c=getc(view))!= EOF)
    {
        printf("%c",c);
        test++;
    }
    fclose(view);


    if (test==0)
        {
            printf("\nNO RECORDS!!\n");}


    view_list_invalid:
     printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);


        if (main_exit==1)
            menu();
        else if(main_exit==0)
            closer();
        else
        {
            printf("\nInvalid!\a");
            goto view_list_invalid;
        }
}
//main function
int main()
{
        pass();
  menu();
  return 0;
}




//menu function
void menu()
{
system("CLS");
    int choice;
    printf("\n\n\t\t\tHOSTEL MANAGEMENT SYSTEM");
    printf("\n\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t1>> Enter new Student's data\n\t\t2>> Update information of existing account\n\t\t3>> Check the details of existing account\n\t\t4>> View all Students of a particular Hostel\n\t\t5>> Removing existing account\n\t\t6>> View all students list\n\t\t7>> Enter staff details\n\t\t8>> Delete staff details\n\t\t9>> View staff details\n\t\t10>>View Block Information\n\t\t11>>View mess menu\n\t\t12>>View Fee Details of a Student\n\t\t13>>Report\n\n\n\n\t\t Enter your choice:");
    scanf("%d",&choice);


    switch(choice)
    {


        case 1:new_entry();
        break;
        case 2:edit();
        break;
        case 3:see();
        break;
        case 4:sorter();
        break;
        case 5:erase();
        break;
        case 6:view_list();
        break;
        case 7:staff_entry();
        break;
        case 8:staff_delete();
        break;
        case 9:staff_view();
        break;
        case 10:block_info();
        break;
        case 11:messmenu();
        break;
        case 12:fee();
        break;
        case 13:report();
        break;
        case 14:closer();
        break;
        default:menu();
    }
}


//------------------------------------------------------------------------------------------------------------------
//function to display all students of a hostel
void sorter()
{
        system("CLS");
    int choice,test=0;


    printf("Enter year choice:\n\n\t\t1. BH-1 \n\t\t2. BH-2 \n\t\t3. BH-3 \n\t\t4. GH-1 \n\n");
    scanf("%d",&choice);


    FILE *fp, *hostel;
    switch(choice)
    {
            case 1: hostel=fopen("BH-1.txt","a+");break;
            case 2: hostel=fopen("BH-2.txt","a+");break;
            case 3: hostel=fopen("BH-3.txt","a+");break;
            case 4: hostel=fopen("GH-1.txt","a+");break;
            default: sorter();
    }
    while(fscanf(hostel,"%s\n",check.roll_no)!=EOF)
    {
               fp=fopen("record.txt","r");
    while(fscanf(fp,"%s %s %d/%d/%d %d %s %d %s %s %d %s %s %d %d/%d/%d\n",add.roll_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.city, &add.phone, add.mail_id, add.father_name, &add.father_phone, add.room_no, add.hostel_name,&add.fee,&add.due.day,&add.due.mon,&add.due.yr)!=EOF)
            {
                    if(strcmp(check.roll_no,sort.roll_no)==0)
                    {
                            if(test==0)
                            {
                                    printf("\t\tFollowing is the list of requested students:");
                            printf("\n\tROLL NO.\tNAME\tROOM NO.\n");
                            }
                            printf("\n\t%8s\t %8s\t %s", sort.roll_no, sort.room_no, sort.name);
                           test++;
                    }
            }
    }


    fclose(fp);
    if (test==0)
        printf("\nNO RECORDS!!\n");


    sort_list_invalid:
    printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);


    if (main_exit==1)
        menu();
    else if(main_exit==0)
        closer();
    else
    {
        printf("\nInvalid!\a");
        goto sort_list_invalid;
    }


}


//------------------------------------------------------------------------------------------------------------------
//new entry function
void new_entry()
{
        system("CLS");


    FILE *ptr,*hostel;
    int dt,mon,yr,fake_month;
    ptr=fopen("record.txt","a+");
    roll_no:


    printf("\t\t\t\xB2\xB2\xB2 ADD STUDENTS DATA  \xB2\xB2\xB2\xB2");
    printf("\nEnter your roll number:");
    scanf("%s",check.roll_no);
    while(fscanf(ptr,"%s %s %d/%d/%d %d %s %d %s %s %d %s %s %d %d/%d/%d\n",add.roll_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.city, &add.phone, add.mail_id, add.father_name, &add.father_phone, add.room_no, add.hostel_name,&add.fee,&add.due.day,&add.due.mon,&add.due.yr)!=EOF)
    {
        if (strcmp(check.roll_no,add.roll_no)==0)
            {printf("Students roll no. already in use!");
             goto roll_no;
        }
    }


    strcpy(add.roll_no,check.roll_no);
    printf("\nEnter the name:");
    scanf("%s",add.name);
    printf("\nEnter the date of birth(mm/dd/yyyy):");
    scanf("%d/%d/%d",&add.dob.month,&add.dob.day,&add.dob.year);
    printf("\nEnter the age:");
    scanf("%d",&add.age);
    printf("\nEnter the city:");
    scanf("%s",add.city);
    printf("\nEnter the phone number: ");
    scanf("%d",&add.phone);
    printf("\n Enter your email id :");
    scanf("%s",add.mail_id);
    printf("\n Enter your Father's name:");
    scanf("%s",add.father_name);
    printf("\n Enter your Father's phone no.:");
    scanf("%d",&add.father_phone);
    printf("\n Enter your room no.:");
    scanf("%s",add.room_no);
    printf("\n Enter your hostel name from BH-1, BH-2, BH-3, GH-1 :");
    scanf("%s",add.hostel_name);
                //adding student roll no. to hostels' list
        if(strcmp(add.hostel_name,"BH-1")==0)
        {
                hostel=fopen("BH-1.txt","a+");
                fprintf(hostel, "%s\n", add.roll_no);
                fclose(hostel);
                add.fee=80000;
        }
        else if(strcmp(add.hostel_name,"BH-2")==0)
        {
                hostel=fopen("BH-2.txt","a+");
                fprintf(hostel, "%s\n", add.roll_no);
                fclose(hostel);
                add.fee=102000;
        }
        else if(strcmp(add.hostel_name,"BH-3")==0)
        {
                hostel=fopen("BH-3.txt","a+");
                fprintf(hostel, "%s\n", add.roll_no);
                fclose(hostel);
                add.fee=60000;
        }
        else if(strcmp(add.hostel_name,"GH-1")==0)
        {
                hostel=fopen("GH-1.txt","a+");
                fprintf(hostel, "%s\n", add.roll_no);
                fclose(hostel);
                add.fee=105000;
        }
        printf("\n\nENTER TODAY'S DATE (dd/mm/yyyy):");
    scanf("%d/%d/%d",&dt,&mon,&yr);


    fake_month=mon+4;
    if(fake_month>=13)
    {
        add.due.day=dt;
        add.due.mon=fake_month-12;
        add.due.yr=yr+1;
    }
    else
    {
       add.due.day=dt;
       add.due.mon=fake_month;
        add.due.yr=yr;


    }
    printf("\n\n DATE OF PAYEMENT OF FEES:%d/%d/%d",add.due.day,add.due.mon,add.due.yr);
                fprintf(ptr,"%s %s %d/%d/%d %d %s %d %s %s %d %s %s %d %d/%d/%d\n",add.roll_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.city, add.phone, add.mail_id, add.father_name, add.father_phone, add.room_no, add.hostel_name,add.fee,add.due.day,add.due.mon,add.due.yr);
                //----------------------------------------


    fclose(ptr);
    printf("\nStudent added successfully!");
    add_invalid:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);


    if (main_exit==1)


        menu();
    else if(main_exit==0)
            closer();
    else
        {
            printf("\nInvalid!\a");
            goto add_invalid;
        }
}


//function to view all students
void view_list()
{
        system("CLS");
    FILE *view;
    view=fopen("record.txt","r");
    int test=0;


    printf("\nROLL NO.\tNAME\t\t\tcity\t\t\tPHONE\n");


    while(fscanf(view,"%s %s %d/%d/%d %d %s %d %s %s %d %s %s %d %d/%d/%d\n",add.roll_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.city, &add.phone, add.mail_id, add.father_name, &add.father_phone, add.room_no, add.hostel_name,&add.fee,&add.due.day,&add.due.mon,&add.due.yr)!=EOF)
       {
           printf("\n%8s\t %10s\t\t\t %10s\t\t %d",add.roll_no,add.name,add.city,add.phone);
           test++;
       }
    fclose(view);


    if (test==0)
        {
            printf("\nNO RECORDS!!\n");}


    view_list_invalid:
     printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);


        if (main_exit==1)
            menu();
        else if(main_exit==0)
            closer();
        else
        {
            printf("\nInvalid!\a");
            goto view_list_invalid;
        }
}


//------------------------------------------------------------------------------------------------------------------
//function to view all data of 1 student
void see()
{
        system("CLS");
    FILE *ptr;
    int test=0;
    int choice;
    ptr=fopen("record.txt","r");
    printf("Do you want to check by\n1.Roll no\n2.Name\nEnter your choice:");
    scanf("%d",&choice);
    if (choice==1)
    {   printf("\n\nEnter the roll number:");
        scanf("%s",check.roll_no);


    while(fscanf(ptr,"%s %s %d/%d/%d %d %s %d %s %s %d %s %s %d %d/%d/%d\n",add.roll_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.city, &add.phone, add.mail_id, add.father_name, &add.father_phone, add.room_no, add.hostel_name,&add.fee,&add.due.day,&add.due.mon,&add.due.yr)!=EOF)


            {
                test=1;
            if(strcmp(add.roll_no,check.roll_no)==0)


                printf("\nROLL NO.:%s\nName:%s \nDOB:%d/%d/%d \nAge:%d \ncity:%s \nPhone number:%d \nE-Mail id:%s \nFather's name:%s \n Father's Phone No.:%d \nRoom No:%s \nHostel:%s \n",add.roll_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.city, add.phone, add.mail_id, add.father_name, add.father_phone, add.room_no, add.hostel_name);
            }
        }


    else if (choice==2)
    {   printf("\n\nEnter the name:");
        scanf("%s",check.name);
        while(fscanf(ptr,"%s %s %d/%d/%d %d %s %d %s %s %d %s %s %d %d/%d/%d\n",add.roll_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.city, &add.phone, add.mail_id, add.father_name, &add.father_phone, add.room_no, add.hostel_name,&add.fee,&add.due.day,&add.due.mon,&add.due.yr)!=EOF)
        {
            if(strcmp(add.name,check.name)==0)
            {
                test=1;
                printf("\nROLL NO.:%s\nName:%s \nDOB:%d/%d/%d \nAge:%d \ncity:%s \nPhone number:%d \nE-Mail id:%s \nFather's name:%s \n Father's Phone No.:%d \nRoom No:%s \nHostel:%s \n",add.roll_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.city, add.phone, add.mail_id, add.father_name, add.father_phone, add.room_no, add.hostel_name);
            }
        }
    }


    fclose(ptr);
     if(test!=1)
             printf("\nRecord not found!!\a\a\a");
    see_invalid:
        printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
        scanf("%d",&main_exit);
        if (main_exit==1)
            menu();
        else if (main_exit==2)
            closer();
        else if(main_exit==0)
            see();
        else
        {
                printf("\nInvalid!\a");
            goto see_invalid;
                }
}


//------------------------------------------------------------------------------------------------------------------
//function to update student info
void edit()
{
        system("CLS");
    int choice,test=0;
    FILE *old,*newrec;
    old=fopen("record.txt","r");
    newrec=fopen("new.txt","w");


    printf("\nEnter the roll no. of the student whose info you want to change:");
    scanf("%s",upd.roll_no);
    while(fscanf(old,"%s %s %d/%d/%d %d %s %d %s %s %d %s %s %d %d/%d/%d\n",add.roll_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.city, &add.phone, add.mail_id, add.father_name, &add.father_phone, add.room_no, add.hostel_name,&add.fee,&add.due.day,&add.due.mon,&add.due.yr)!=EOF)


    {
        if (strcmp(add.roll_no,upd.roll_no)==0)
        {   test=1;
            printf("\nWhich information do you want to change?\n1.Room no.\n2.Phone\n\nEnter your choice(1 for room no. and 2 for phone ):");
            scanf("%d",&choice);


            if(choice==1)
                {printf("Enter the new room no.:");
                scanf("%s",upd.room_no);
                fprintf(newrec,"%s %s %d/%d/%d %d %s %d %s %s %d %s %s\n",add.roll_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.city, add.phone, add.mail_id, add.father_name, add.father_phone, upd.room_no, add.hostel_name);
                printf("Changes saved!");
                }
            else if(choice==2)
                {
                    printf("Enter the new phone number:");
                scanf("%d",&upd.phone);
                fprintf(newrec,"%s %s %d/%d/%d %d %s %d %s %s %d %s %s\n",add.roll_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.city, upd.phone, add.mail_id, add.father_name, add.father_phone, add.room_no, add.hostel_name);
                printf("Changes saved!");
                }


        }
        else
            fprintf(newrec,"%s %s %d/%d/%d %d %s %d %s %s %d %s %s\n",add.roll_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.city, add.phone, add.mail_id, add.father_name, add.father_phone, add.room_no, add.hostel_name);
    }
    fclose(old);
    fclose(newrec);
    remove("record.txt");
    rename("new.txt","record.txt");


        if(test!=1)
        printf("\nRecord not found!!\a\a\a");


    edit_invalid:
                printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
        scanf("%d",&main_exit);
        if (main_exit==1)
                        menu();
        else if (main_exit==2)
            closer();
        else if(main_exit==0)
            edit();
        else
        {
                printf("\nInvalid!\a");
            goto edit_invalid;
        }


}


//------------------------------------------------------------------------------------------------------------------
//cpfunction to delete records
void erase()
{
        system("CLS");
    FILE *old,*newrec;
    int test=0;
    old=fopen("record.txt","r");
    newrec=fopen("new.txt","w");
    printf("Enter the roll np. of student whose data you want to delete:");
    scanf("%s",rem.roll_no);
    printf("%s",rem.roll_no);
    while(fscanf(old,"%s %s %d/%d/%d %d %s %d %s %s %d %s %s %d %d/%d/%d\n",add.roll_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.city, &add.phone, add.mail_id, add.father_name, &add.father_phone, add.room_no, add.hostel_name,&add.fee,&add.due.day,&add.due.mon,&add.due.yr)!=EOF)
   {
        if(strcmpi(add.roll_no,rem.roll_no)!=0)
            fprintf(newrec,"%s %s %d/%d/%d %d %s %d %s %s %d %s %s\n",add.roll_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.city, add.phone, add.mail_id, add.father_name, add.father_phone, add.room_no, add.hostel_name);


        else
            {test++;
            printf("\nRecord deleted successfully!\n");
            }
    }
    fclose(old);
    fclose(newrec);
    remove("record.txt");
    rename("new.txt","record.txt");
    if(test==0)
            printf("\nRecord not found!!\a\a\a");
    erase_invalid:
        printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
        scanf("%d",&main_exit);
        if (main_exit==1)
            menu();
        else if (main_exit==2)
            closer();
        else if(main_exit==0)
            erase();
        else
        {
                printf("\nInvalid!\a");
            goto erase_invalid;
                 }
}
void messmenu()
{
    int week;
    printf("enter the no.of week to which menu is to be found");
    scanf("%d",&week);
    switch(week)
    {
    case 1:
        printf("breakfast:dosa and savoury \n lunch:carrot rice \n dinner: roti n subzi");
        break;


    case 2:
        printf("breakfast:rava idli and upma \n lunch:mixed rice \n dinner: hakka noodles");
        break;
    case 3:
        printf("breakfast:poori n gravy \n lunch:veg biriyani \n dinner: phulka and paneer");
        break;
    default:
        printf("oops wait for the next month for update");
        break;




    }
}
void report()
{
    FILE *fp1,*fp2,*fp3,*fp4;
    int count_BH1=0,count_BH2=0,count_BH3=0,count_GH1=0;
    char a,b,c,d;
    fp1 = fopen("BH-1.txt", "r");
    for(c=getc(fp1);c!=EOF;c=getc(fp1))
        if (c == '\n')
            count_BH1++;


    fclose(fp1);
    fp2 = fopen("BH-2.txt", "r");
    for(b=getc(fp2);b!=EOF;b=getc(fp2))
        if (b == '\n')
            count_BH2++;


    fclose(fp2);
    fp3 = fopen("BH-3.txt", "r");
    for(c=getc(fp3);c!=EOF;c=getc(fp3))
        if (c == '\n')
            count_BH3++;


    fclose(fp3);
    fp4 = fopen("GH-1.txt", "r");
    for(d=getc(fp4);d!=EOF;d=getc(fp4))
        if (d == '\n')
            count_GH1++;


    fclose(fp4);
   int week;
   printf("Total no.of students in BH-1=%d\nTotal no.of students in BH-2=%d\nTotal no.of students in BH-3=%d\nTotal no.of students in GH-1=%d\n\t\t ENTER THE WEEK TO KNOW WHO IS THE SUPERVISOR",count_BH1,count_BH2,count_BH3,count_GH1);
   scanf("%d",&week);
   switch(week)
   {


   case 1:
    printf("BH-1:MR.Ponvannan\n BH-2:Mr.Raja\n BH-3:Mr.Roy\n GH-1:Mrs.Meena");
    break;
   case 2:
    printf("BH-1:MR.Raghuram\n BH-2:Mr.Roy\n BH-3:Mr.Roy\n GH-1:Mrs.Vani");
    break;
   case 3:
    printf("BH-1:MR.Prem\n BH-2:Mr.Ponvannan\n BH-3:Mr.Roy\n GH-1:Mrs.vanathi");
    break;
   default:
    printf("wait for updates");
    break;
   }


}




//------------------------------------------------------------------------------------------------------------------
//function denoting the mgmt. we took
void closer()
{
        system("CLS");
    printf("PSG TECH HOSTELS");
}


int pass(void)
{
   int a=0,i=0;
    char uname[10],c=' ';
    char pword[10],code[10];
    char user[10]="user";
    char pass[10]="psgtech";
    do
{
        system("cls");


    printf("\n  **************************  LOGIN FORM  **************************  ");
    printf(" \n                       ENTER USERNAME:-");
        scanf("%s", &uname);
        printf(" \n                       ENTER PASSWORD:-");
        while(i<10)
        {
            pword[i]=getch();
            c=pword[i];
            if(c==13) break;
            else printf("*");
            i++;
        }
        pword[i]='\0';
        //char code=pword;
        i=0;
        //scanf("%s",&pword);
                if(strcmp(uname,user)==0 && strcmp(pword,pass)==0)
        {
        printf("  \n\n\n       WELCOME !!!! LOGIN IS SUCCESSFUL\n");
        system("PAUSE");
        break;
        }
        else
        {
                printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL\n");
                system("PAUSE");
                a++;


                getch();


        }
}
        while(a<=2);
        if (a>2)
        {
                printf("\nSorry you have entered the wrong username and password for four times!!!");


                getch();


                }
                system("cls");
}
