//Employee Management Sysstem with FIle Handling in C++
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <time.h>

using namespace std;
class admin //Admin class
{
private:
    int emp_id, sal, group_id;
    string name, address;

public:
    void menu();
    void insert();
    void display();
    void search_record();
    void modify();
    void del();
    void group();
    void search_group();
    void show_group();
    void check_attendence();
    void search_attendence();
};
class employee : public admin //Employee class
{
public:
    void login();
    void main_menu();
    void child_menu();
    void attendance();
} emp; //Creating object for employee class

void intro()
{
    system("cls");
    cout << "\n\n\n\n\n";
    cout << "\t\t\t\t---------------------------------------------";
    cout << "\n\t\t\t\t---------------------------------------------";
    cout << "\n\n\t\t\t\t\tWELCOME TO AADHAR CORPORATION!!";
    cout << "\n\n\t\t\t\t---------------------------------------------";
    cout << "\n\t\t\t\t---------------------------------------------";
    cout << "\n\n\n\n\t\t\t\t\t\tPress any Key to Continue...";
    getch();
    system("cls");
    cout << "\n\n\n\n\n\n";
    cout << "\t\t\t\t---------------------------------------------";
    cout << "\n\n\t\t\t\t\tEmployee Management System";
    cout << "\n\n\t\t\t\t\t\t\tVersion 1.0.1";
    cout << "\n\t\t\t\t---------------------------------------------";
    cout << "\n\n\n\n\t\t\t\t\t\tPress any Key to Continue...";
    getch();
}

void employee::login()
{
p:
    system("cls");
    char ch;
    int i = 0;
    string user, pass;
    cout << "\n\n\n\n\n\n";
    cout << "\t\t-----------------------------------------------------------------------------------";
    cout << "\n\n\t\t\t\t\t\tLOGIN";
    cout << "\n\t\tUsername: ";
    cin >> user;
    cout << "\n\t\tPassword: ";
    do
    {
        ch = getch();
        pass += ch;
        if (int(ch) != 8)
        {
            cout << "*";
            i++;
        }
    } while (i != 8);

    getch();
    cout << "\n\n\t\t-----------------------------------------------------------------------------------";
    if (user == "alhad_balak" && pass == "EmployeeSystem!")
    {
        cout << "\n\n\n\t\t\tCongratulation! Login Successfully";
        cout << "\n\n\n\t\t\tLoading";
        for (i = 1; i < 5; i++)
        {
            _sleep(500);
            cout << ".";
        }
        admin::menu();
    }
    else
    {
        cout << "\n\n\nEntered Ceredentials are incorrect... ";
        cout << "\nPlease try again...";
        char back;
        cout << "\n\nDo you want to go back on main menu? (Y/N): ";
        cin >> back;
        if (back == 'Y')
            main_menu();
        else
            goto p;
    }
}

void employee::main_menu()

{
p:
    system("cls");
    int choice;
    cout << "\n\n\t\t-----------------------------------------------------------------------------------";
    cout << "\n\n\t\t\t\t\t\tControl Panel ";
    cout << "\n\n 1. Admin";
    cout << "\n\n 2. Employee";
    cout << "\n\n 3. Exit";
    cout << "\n\n Enter Your Choice: ";
    cin >> choice;
    cout << "\n\n\t\t-----------------------------------------------------------------------------------";
    switch (choice)
    {
    case 1:
        login();
        break;
    case 2:
        child_menu();
        break;
    case 3:
        exit(0);
    default:
        cout << "\n\n Invalid... \nPlease Try Again...";
    }
    getch();
    goto p;
}
void employee::child_menu()
{
p:
    int choice;
    system("cls");
    cout << "\n\n\t\t-----------------------------------------------------------------------------------";
    cout << "\n\n\t\t\t\t\t\tEmployee Control Panel";
    cout << "\n\n1. Attendence";
    cout << "\n\n2. Check Details";
    cout << "\n\n3. Go Back";
    cout << "\n\nEnter Your Choice: ";
    cin >> choice;
    cout << "\n\n\t\t-----------------------------------------------------------------------------------";
    switch (choice)
    {
    case 1:
        attendance();
        break;
    case 2:
        admin::search_record();
        break;
    case 3:
        main_menu();
    default:

        cout << "\n\n Invalid... \nPlease Try Again...";
    }
    getch();

    goto p;
}

void admin::menu()
{
p:
    system("cls");
    int x;
    cout << "\n\n\t\t-----------------------------------------------------------------------------------";
    cout << "\n\n\t\t\t\t\t\tAdmin Control Panel";
    cout << "\n\n\n 1. Insert Record";
    cout << "\n 2. Display Record";
    cout << "\n 3. Check Attendence";
    cout << "\n 4. Search Attendence";
    cout << "\n 5. Search Record";
    cout << "\n 6. Modify Record";
    cout << "\n 7. Delete Record";
    cout << "\n 8. Group Record";
    cout << "\n 9. Search Group";
    cout << "\n 10. Show All Groups";
    cout << "\n 11. Go Back";
    cout << "\n\n Your Choice: ";
    cin >> x;
    cout << "\n\n\t\t-----------------------------------------------------------------------------------";
    switch (x)
    {
    case 1:
        insert();
        break;
    case 2:
        display();
        break;
    case 3:
        check_attendence();
        break;
    case 4:
        search_attendence();
        break;
    case 5:
        search_record();
        break;
    case 6:
        modify();
        break;
    case 7:
        del();
        break;
    case 8:
        group();
        break;
    case 9:
        search_group();
        break;
    case 10:
        show_group();
        break;
    case 11:
        emp.main_menu();
    default:
        cout << "\n\n Invalid Value...Please try Again...";
    }
    getch();
    goto p;
}

void employee::attendance()
{
    system("cls");
    fstream file;
    int test_id, found = 0;
    int a_day, a_date, a_month, a_year, t_id, a_hr, a_min, a_sec, count = 0;

    time_t x = time(NULL);
    cout << "\n\n\t\t-----------------------------------------------------------------------------------";
    cout << "\n\n\t\t\t\t\t\tEMPLOYEE ATTENDANCE";
    file.open("admin.txt", ios::in);

    if (!file)
    {
        cout << "\n\n File Opening Error....";
    }
    else
    {
        int emp_id, name, sal, address, group_id;
        cout << "\n\n Employee ID: ";
        cin >> test_id;
        file >> emp_id >> name >> sal >> address >> group_id;
        while (!file.eof())
        {
            if (test_id == emp_id)
            {
                found++;
            }
            file >> emp_id >> name >> sal >> address >> group_id;
            file.close();
            if (found > 0)
            {
                ctime(&x);
                file.open("attendance.txt", ios::in);
                if (!file)
                {
                    file.open("attendance.txt", ios::app | ios::out);
                    file << " " << test_id << " " << ctime(&x);
                   
                    file.close();
                    cout << "\n\n Your Attendence Added Successfully...";
                }
                else
                {
                    file >> t_id >> a_day >> a_date >> a_month >> a_hr >> a_min >> a_sec >> a_year;
                    while (file.eof())
                    {
                        if (test_id == t_id)
                        {
                            cout << "\n\n Your Attendence Already marked";
                            count++;
                        }
                        file >> t_id >> a_date >> a_month >> a_year;
                    }

                    file.close();

                    if (count == 0)
                    {
                        file.open("attendance.txt", ios::app | ios::out);
                        file << " " << test_id << " " << ctime(&x);
                
                        file.close();
                        cout << "\n\n Your Attendence Added Successfully...";
                    }
                    else
                        cout << "\n\n Invalid Employee ID....";
                }
            }
            else
            {
                cout << "\n\n Invalid Employee ID...";
            }
        }
    }
    cout << "\n\n\t\t-----------------------------------------------------------------------------------";
}

void admin::insert()
{
    system("cls");
    int test_id, found = 0;
    fstream file, file1;
    cout << "\n\n\t\t-----------------------------------------------------------------------------------";
    cout << "\n\n\t\t\t\t\t\tINSERTION OF DETAILS";
    cout << "\n\n\n Employee ID: ";
    cin >> emp_id;
    cout << "\n\nEmployee Name : ";
    cin >> name;
    cout << "\n\nEmployee Salary: ";
    cin >> sal;
    cout << "\n\nEmployee Address : ";
    cin >> address;
    cout << "\n\nEmployee Group ID: ";
    cin >> group_id;
    file.open("admin.txt", ios::out | ios::app);
    file << " " << emp_id << " " << name << " " << sal << " " << address << " " << group_id << "\n";
    file.close();
    file1.open("group.txt", ios::out | ios::app);
    file1 << " " << group_id << " " << emp_id << " " << sal << "\n";
    file1.close();
    file.open("groupid.txt", ios::in);
    if (!file)
    {
        file1.open("groupid.txt", ios::app | ios::out);
        file1 << " " << group_id << "\n";
        file1.close();
    }
    else
    {
        file >> test_id;
        while (!file.eof())
        {
            if (test_id == group_id)
                found++;

            file >> test_id;
        }
        file.close();
        if (found == 0)
        {
            file1.open("groupid.txt", ios::app | ios::out);
            file1 << " " << group_id << "\n";
            file1.close();
        }
    }
    cout << "\n\n\n\t\t\tNew Record Inserted Successfully...";
    cout << "\n\n\t\t-----------------------------------------------------------------------------------";
}

void admin::display()
{
    system("cls");
    fstream file;
    cout << "\n\n\t\t-----------------------------------------------------------------------------------";
    cout << "\n\n\t\t\t\t\t\tDETAILS OF AN EMPLOYEE";
    file.open("admin.txt", ios::in);
    if (!file)
    {
        cout << "\n\n File Openning Error...";
        getch();
        menu();
    }

    file >> emp_id >> name >> sal >> address >> group_id;
    while (!file.eof())
    {
        cout << "\n\n\n\n Employee ID: " << emp_id;
        cout << "\n\n\t\tEmployee Name: " << name;
        cout << "\n\n Employee Salary: " << sal;
        cout << "\n\n\t\tEmloyee Address : " << address;
        cout << "\n\n Group ID: " << group_id;
        file >> emp_id >> name >> sal >> address >> group_id;
    }
    file.close();
}

void admin::check_attendence()
{
    system("cls");
    fstream file, file1;
    int d, m, y, a_date, a_month, a_year, t_id, count = 0;
    cout << "\n\n\t\t-----------------------------------------------------------------------------------";
    cout << "\n\n\t\t\t\t\tCHECK THE ATTENDACE OF AN EMPLOYEE";
    file.open("admin.txt", ios::in);
    file1.open("attendance.txt", ios::in);
    if (!file || !file1)
        cout << "\n\n File Opening Error...";
    else
    {
        cout << "\n\n Date : ";
        cin >> d;
        cout << "\n Month: ";
        cin >> m;
        cout << "\n Year: ";
        cin >> y;
        file1.close();

        system("cls");
        cout << "\n\n\t\t\tCheck Employee Attendence";
        cout << "\n\n Employee ID\tPresents\tAbsents";
        file >> emp_id >> name >> sal >> address >> group_id;
        while (!file.eof())
        {
            file1.open("attendance.txt", ios::in);
            file1 >> t_id >> a_date >> a_month >> a_year;
            while (!file1.eof())
            {
                if (emp_id == t_id && d <= a_date && m == a_month && y == a_year)
                {
                    count++;
                }
                file1 >> t_id >> a_date >> a_month >> a_year;
            }
            file1.close();
            cout << "\n " << emp_id << "\t\t" << count << "\t\t" << 30 - count;
            count = 0;
            file >> emp_id >> name >> sal >> address >> group_id;
            file.close();
        }
    }
    cout << "\n\n\t\t-----------------------------------------------------------------------------------";
}

void admin::search_attendence()
{
    system("cls");
    fstream file, file1;
    int d, m, y, a_date, a_month, a_year, t_id, count = 0;
    cout << "\n\n\t\t-----------------------------------------------------------------------------------";
    cout << "\n\n\t\t\t\t\tSEARCH THE ATTENDANCE RECORD OF AN EMPLOYEE";
    file.open("admin.txt", ios::in);
    file1.open("attendance.txt", ios::in);
    if (!file || !file1)
        cout << "\n\n File Opening Error...";
    else
    {
        cout << "\n\n Employee ID : ";
        cin >> emp_id;
        cout << "\n\n Date : ";
        cin >> d;
        cout << "\n Month: ";
        cin >> m;
        cout << "\n Year: ";
        cin >> y;
        file.close();

        system("cls");
        cout << "\n\n\t\t\tCheck Employee Attendence";

        file1 >> t_id >> a_date >> a_month >> a_year;
        while (!file1.eof())
        {
            if (emp_id == t_id && d <= a_date && m == a_month && y == a_year)
                count++;

            file1 >> t_id >> a_date >> a_month >> a_year;
        }
        file1.close();
        if (count > 0)
        {
            cout << "\n\n Employee ID\tPresents\tAbsents";
            cout << "\n " << emp_id << "\t\t" << count << "\t\t" << 30 - count;
        }
        else
        {
            cout << "\n\n Employee ID not found....";
        }
    }
    cout << "\n\n\t\t-----------------------------------------------------------------------------------";
}

void admin::search_record()
{
    system("cls");
    fstream file;
    int emp_idd, found = 0;
    cout << "\n\n\t\t-----------------------------------------------------------------------------------";
    cout << "\n\n\t\t\t\t\t\tSEARCH THE DETAILS OF AN EMPLOYEE";
    file.open("admin.txt", ios::in);
    if (!file)
    {
        cout << "\n\n File Openning Error...";
    }
    else
    {
        cout << "\n\n Employee ID For Search: ";
        cin >> emp_idd;
        file >> emp_id >> name >> sal >> address >> group_id;
        while (!file.eof())
        {
            if (emp_idd == emp_id)
            {
                system("cls");
                cout << "\n\n\t\t\t\tSearch Record";
                cout << "\n\n Employee ID: " << emp_id;
                cout << "\n\n\t\tEmployee Name : " << name;
                cout << "\n\n Employee Salary: " << sal;
                cout << "\n\n\t\tEmloyee Address: " << address;
                cout << "\n\n Group ID: " << group_id;
                found++;
            }
            file >> emp_id >> name >> sal >> address >> group_id;
        }
        file.close();
        if (found == 0)
            cout << "\n\n Employee ID Can't Found...";
    }
    cout << "\n\n\t\t-----------------------------------------------------------------------------------";
}

void admin::modify()
{
    system("cls");
    int sall, test_id, found = 0;
    string name1, address1;
    fstream file, file1, file2, file3;
    cout << "\n\n\t\t-----------------------------------------------------------------------------------";
    cout << "\n\n\t\t\t\t\t\tMODIFY THE DETAILS OF AN EMPLOYEE";
    file.open("admin.txt", ios::in);
    file1.open("group.txt", ios::in);
    if (!file || !file1)
    {
        cout << "\n\n File Openning Error...";
        getch();
        menu();
    }

    cout << "\n\n Employee ID For Modify: ";
    cin >> test_id;

    file2.open("emp1.txt", ios::app | ios::out);
    file >> emp_id >> name >> sal >> address >> group_id;

    while (!file.eof())
    {
        if (test_id == emp_id)
        {
            system("cls");
            cout << "\n\n\t\t\t\tModify Record";
            cout << "\n\n\n Employee Name: ";
            cin >> name1;
            cout << "\n\n\t\tEmployee Salary: ";
            cin >> sall;
            cout << "\n\n Employee Address : ";
            cin >> address1;
            file2 << " " << emp_id << " " << name1 << " " << sall << " " << address1 << " " << group_id << "\n";
            found++;
        }

        else
        {
            file2 << " " << emp_id << " " << name << " " << sal << " " << address << " " << group_id << "\n ";
            file >> emp_id >> name >> sal >> address >> group_id;
        }

        file.close();
        file2.close();

        remove("admin.txt");
        rename("emp1.txt", "admin.txt");

        file3.open("group1.txt", ios::app | ios::out);
        file1 >> group_id >> emp_id >> sal;

        while (!file1.eof())
        {

            if (test_id == emp_id)
                file3 << " " << group_id << " " << emp_id << " " << sall << "\n";

            else
                file3 << " " << group_id << " " << emp_id << " " << sal << "\n";

            file1 >> group_id >> emp_id >> sal;
        }

        file1.close();
        file3.close();

        remove("group.txt");
        rename("group1.txt", "group.txt");

        if (found == 0)
            cout << "\n\n Employee ID Can't Found...";

        else
            cout << "\n\n\t\t\t Record Modify Successfully...";
    }
    cout << "\n\n\t\t-----------------------------------------------------------------------------------";
}

void admin::del()
{
    system("cls");
    int test_id, found = 0;
    fstream file, file1, file2, file3;
    cout << "\n\n\t\t-----------------------------------------------------------------------------------";
    cout << "\n\n\t\t\t\t\t\tDELETE THE DETAILS OF AN EMPLOYEE";
    file.open("admin.txt", ios::in);
    file1.open("group.txt", ios::in);

    if (!file || !file1)
    {
        cout << "\n\n File Openning Error...";
        getch();
        menu();
    }

    cout << "\n\n Employee ID For Delete: ";
    cin >> test_id;

    file2.open("emp1.txt", ios::app | ios::out);
    file >> emp_id >> name >> sal >> address >> group_id;

    while (!file.eof())
    {

        if (test_id == emp_id)
        {
            cout << "\n\n Record Deleted Successfully...";
            found++;
        }

        else

        {
            file2 << " " << emp_id << " " << name << " " << sal << " " << address << " " << group_id << "\n ";
        }
        file >> emp_id >> name >> sal >> address >> group_id;
    }
    file.close();
    file2.close();

    remove("admin.txt");
    rename("emp1.txt", "admin.txt");

    file3.open("group1.txt", ios::app | ios::out);

    file1 >> group_id >> emp_id >> sal;
    while (!file1.eof())
    {
        if (test_id != emp_id)
            file3 << " " << group_id << " " << emp_id << " " << sal << "\n";

        file1 >> group_id >> emp_id >> sal;
    }

    file1.close();
    file3.close();

    remove("group.txt");
    rename("group1.txt", "group.txt");

    if (found == 0)
        cout << "\n\n Employee ID Can't Found...";
    cout << "\n\n\t\t-----------------------------------------------------------------------------------";
}

void admin::group()
{
    system("cls");
    fstream file;
    cout << "\n\n\t\t-----------------------------------------------------------------------------------";
    cout << "\n\n\t\t\t\t\t\tDETAILS OF EMPLOYEES GROUP-WISE";
    file.open("group.txt", ios::in);
    if (!file)
    {
        cout << "\n\n File Openning Error...";
        getch();
        menu();
    }

    file >> group_id >> emp_id >> sal;

    while (!file.eof())
    {
        cout << "\n\n\n\n Group ID: " << group_id;
        cout << "\n\n\t\t Employee ID: " << emp_id;
        cout << "\n\n Employee Salary: " << sal;
        file >> group_id >> emp_id >> sal;
    }

    file.close();
    cout << "\n\n\t\t-----------------------------------------------------------------------------------";
}

void admin::search_group()
{
    system("cls");
    int test_id, found = 0, emp_count = 0, sal_count = 0;
    fstream file;
    cout << "\n\n\t\t-----------------------------------------------------------------------------------";
    cout << "\n\n\t\t\t\t\t\tSEARCH FOR THE DETAILS OF EMPLOYEES GROUP-WISE";
    file.open("group.txt", ios::in);

    if (!file)
    {
        cout << "\n\n File Openning Error...";
        getch();
        menu();
    }

    cout << "\n\n Group ID For Search: ";
    cin >> test_id;
    system("cls");
    cout << "\n\n\t\t\t\tSearch Group Record";
    file >> group_id >> emp_id >> sal;

    while (!file.eof())
    {
        if (test_id == group_id)
        {
            cout << "\n\n\n Group ID: " << group_id;
            cout << "\n\n\t\tEmployee ID: " << emp_id;
            cout << "\n\n Employee Salary: " << sal;
            found++;
            emp_count++;
            sal_count += sal;
        }

        file >> group_id >> emp_id >> sal;
    }

    file.close();

    if (found != 0)
    {
        cout << "\n\n\n Group ID: " << test_id;
        cout << "\n\n\t\tTotal Employee: " << emp_count;
        cout << "\n\n Total Salary: " << sal_count;
    }
    else
        cout << "\n\n Group ID Can't Found...";
    cout << "\n\n\t\t-----------------------------------------------------------------------------------";
}

void admin::show_group()
{
    system("cls");
    int test_id, emp_count = 0, sal_count = 0, emp_total = 0, sal_total = 0;
    fstream file, file1;
    cout << "\n\n\t\t-----------------------------------------------------------------------------------";
    cout << "\n\n\t\t\t\t\t\tDETAILS IN GROUP-WISE";
    file.open("groupid.txt", ios::in);

    if (!file)
    {
        cout << "\n\n File Openning Error...";
        getch();
        menu();
    }

    file >> test_id;

    while (!file.eof())
    {
        file1.open("group.txt", ios::in);
        file1 >> group_id >> emp_id >> sal;

        while (!file1.eof())
        {
            if (test_id == group_id)
            {
                emp_count++;
                sal_count += sal;
                emp_total++;
                sal_total += sal;
            }
            file1 >> group_id >> emp_id >> sal;
        }
        file1.close();

        cout << "\n\n\n\n Group ID: " << test_id;
        cout << "\n\n Total Salary: " << sal_count;
        cout << "\n\n\t\t Total Employee: " << emp_count;

        emp_count = 0;
        sal_count = 0;
        file >> test_id;
    }

    file.close();

    cout << "\n\n\n\n Over All Employee: " << emp_total;
    cout << "\n\n\t\tOver All Salary: " << sal_total;
    cout << "\n\n\t\t-----------------------------------------------------------------------------------";
}

int main()
{
    intro();
    emp.main_menu();
    return 0;
}
