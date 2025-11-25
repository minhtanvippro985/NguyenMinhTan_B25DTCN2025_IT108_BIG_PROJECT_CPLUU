#include<stdio.h>
#include<string.h>
struct Employee{
	char empId[20];
	char name[50];
	char position[15];
	double baseSalary;
	int workDay;
};

struct TimeSheet{
	char logId[20];
	char empId[20];
	char date[20];
	char status[10];
};
void add_people(struct Employee list[], int *n);
void updateEmployee(struct Employee list[], int *n);
void deleteEmployeev2(struct Employee list[], int *n);
void displayEmployeeList(struct Employee list[], int n);

int EMPTYCHECKER(char *str) {
    
    str[strcspn(str, "\n")] = '\0';
/// len = 0 trong
    if (strlen(str) == 0)
        return 1;

    // null
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' && str[i] != '\t')
            return 0;  // hop le khong trong
    }

    return 1; // trong
}
void showmenu(){
     	printf("|        QUAN LY NHAN VIEN VA CHAM CONG       |");
	    printf("\n| ==========================================  |\n");
	    printf("|  1.Them nhan vien moi                       |\n");
	    printf("|  2.Cap nhat ho so nhan vien                 |\n");                 
	    printf("|  3.Xoa ho so nhan vien                      |\n");
	    printf("|  4.Hien thi danh sach nhan vien             |\n");
	    printf("|  5.Tim kiem nhan vien                       |\n");
	    printf("|  6.Sap xep nhan vien                        |\n");
	    printf("|  7.Cham cong ngay nhan vien                 |\n");
	    printf("|  8.Xem bang cong nhan vien                  |\n");
	    printf("|  9.Thoat                                    |\n");
	    printf(" =============================================\n");

}
//--------------------------------------
int main(){
	struct Employee list[100] ;
	int n = 0; 
	int choice;

	do{
       showmenu();
		printf("Moi ban nhap lua chon: ");
		scanf("%d",&choice);
		getchar(); 

		switch(choice){
			case 1:
				add_people(list,&n);
				break;
			case 2:
				updateEmployee(list,&n);
				break;
			case 3:
			//	deleteEmployee(list , &n);
		     	deleteEmployeev2(list , &n);
		     
				break;
			case 4:
				displayEmployeeList(list,n);
				break;
			case 5 : 
			    printf("ss");
				break;	
			default:
				printf("Khong hop le!");
		}
	}while(choice != 9);


	return 0;
}
void displayEmployeeList(struct Employee list[], int n) {
    if (n == 0) {
        printf("Danh sach nhan vien hien dang trong!\n");
        return;
    }

    printf("\n====================== DANH SACH NHAN VIEN ======================\n");
    printf("%-10s | %-20s | %-12s | %-10s | %-5s\n",
           "Ma NV", "Ten NV", "Chuc vu", "Luong", "Cong");
    printf("-------------------------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        printf("%-10s | %-20s | %-12s | %-10.0lf | %-5d\n",
               list[i].empId,
               list[i].name,
               list[i].position,
               list[i].baseSalary,
               list[i].workDay);
    }

    printf("Hien thi danh sach thanh cong!\n");
}

void updateEmployee(struct Employee list[], int *n){
    char id[20];
    int pos = -1;

    // ID
    while (1) {
        printf("Nhap ID nhan vien can cap nhat: ");
        fgets(id, 20, stdin);
        id[strcspn(id, "\n")] = '\0';

        if (strlen(id) == 0) {
            printf("ID khong duoc de trong!\n");
            continue;
        }

        // tim vi tri
        pos = -1;
        for (int i = 0; i < *n; i++) {
            if (strcmp(list[i].empId, id) == 0) {
                pos = i;
                break;
            }
        }

        if (pos == -1) {
            printf("Khong tim thay ID! Nhap lai.\n");
            continue;
        }

        break;
    }

    printf("\n--- Cap nhat thong tin cho nhan vien %s ---\n", list[pos].name);

    // ===== CHUC VU=====
    while (1) {
        printf("Nhap CHUC VU");
        fgets(list[pos].position, 15, stdin);
        list[pos].position[strcspn(list[pos].position, "\n")] = '\0';

        if (strlen(list[pos].position) == 0) {
            printf("Chuc vu khong duoc de trong!\n");
            continue;
        }

        break;
    }

    // ===== CAP NHAT LUONG =====
     while (1) {
        char buffer[50];
        printf("Nhap luong co ban moi: ");
        fgets(buffer, sizeof(buffer), stdin);

        if (strlen(buffer) == 0 || buffer[0] == '\n') {
            printf("Luong khong duoc de trong!\n");
            continue;
        }

        double salary;
        if (sscanf(buffer, "%lf", &salary) != 1) {
            printf("Nhap sai dinh dang! Hay nhap so.\n");
            continue;
        }

        if (salary <= 0) {
            printf("Luong phai lon hon 0!\n");
            continue;
        }

        list[pos].baseSalary = salary;
        break;
    }

    // ===== NGAY CONG =====
    while (1) {
        char buffer[50];
        printf("Nhap ngay cong moi: ");
        fgets(buffer, sizeof(buffer), stdin);

        if (strlen(buffer) == 0 || buffer[0] == '\n') {
            printf("Ngay cong khong duoc de trong!\n");
            continue;
        }

        int days;
        if (sscanf(buffer, "%d", &days) != 1) {
            printf("Nhap sai dinh dang! Hay nhap so.\n");
            continue;
        }

        if (days < 0 || days > 31) {
            printf("Ngay cong phai tu 0 den 31!\n");
            continue;
        }

        list[pos].workDay = days;
        break;
    }

    printf("Cap nhat thong tin thanh cong!\n");
}

void add_people(struct Employee list[], int *n) {
    if (*n >= 10) {  // CHECK MANG
        printf("Danh sach nhan vien da day, khong the them!\n");
        return;
    }

    char buffer[100];  // generic buffer , luu de copy ra cho khac

    // ID ---
    while (1) {
        printf("Nhap ma nhan vien: ");
        fgets(buffer, sizeof(buffer), stdin);

        if (EMPTYCHECKER(buffer)) {
            printf("Ma nhan vien khong duoc trong!\n");
            continue;
        }

        int exists = 0;
        for (int i = 0; i < *n; i++) {
            if (strcmp(list[i].empId, buffer) == 0) {
                exists = 1;
                break;
            }
        }
        if (exists) {
            printf("Ma nhan vien da ton tai! Nhap lai.\n");
            continue;
        }

        strcpy(list[*n].empId, buffer);
        break;
    }

    // --- NHAP TEN ---
    while (1) {
        printf("Ten nhan vien: ");
        fgets(list[*n].name, sizeof(list[*n].name), stdin);

        if (EMPTYCHECKER(list[*n].name)) {
            printf("Ten nhan vien khong duoc de trong!\n");
            continue;
        }
        break;
    }

    // --- CHUC VU ---
    while (1) {
        printf("Chuc vu nhan vien: ");
        fgets(list[*n].position, sizeof(list[*n].position), stdin);

        if (EMPTYCHECKER(list[*n].position)) {
            printf("Chuc vu khong duoc de trong!\n");
            continue;
        }
        break;
    }

    // --- NHAP LUONG ---
    while (1) {
        printf("Luong co ban: ");
        fgets(buffer, sizeof(buffer), stdin);

        if (EMPTYCHECKER(buffer)) {
            printf("Luong khong duoc de trong! Nhap lai.\n");
            continue;
        }

        double salary;
        if (sscanf(buffer, "%lf", &salary) != 1) {
            printf("Nhap sai dinh dang! Nhap lai.\n");
            continue;
        }

        if (salary <= 0) {
            printf("Luong khong hop le! Nhap lai.\n");
            continue;
        }

        list[*n].baseSalary = salary;
        break;
    }

    // --- NHAP SO NGAY CONG ---
    while (1) {
        printf("Nhap ngay cong (de trong = 0): ");
        fgets(buffer, sizeof(buffer), stdin);

        if (EMPTYCHECKER(buffer)) {
            list[*n].workDay = 0;
            break;
        }

        int days;
        if (sscanf(buffer, "%d", &days) != 1) {
            printf("Nhap sai dinh dang! Nhap lai.\n");
            continue;
        }

        if (days < 0 || days > 31) {
            printf("Ngay cong phai tu 0 den 31!\n");
            continue;
        }

        list[*n].workDay = days;
        break;
    }

    (*n)++;
    printf("Them nhan vien thanh cong!\n");
}

void deleteEmployeev2(struct Employee list[], int *n) {
    char deleteEmpId[20];
    int pos = -1;

    if (*n == 0) {
        printf("DANH SACH RONG! KHONG THE XOA!\n");
        return;
    }

    // NHAP NHAN VIEN
    while (1) {
        printf("MA NHAN VIEN MUON XOA: ");
        fgets(deleteEmpId, 20, stdin);
        deleteEmpId[strcspn(deleteEmpId, "\n")] = '\0';

        if (strlen(deleteEmpId) == 0) {
            printf("Ma nhan vien khong duoc de trong.\n");
            continue;
        }

        pos = -1;
        for (int i = 0; i < *n; i++) {
            if (strcmp(list[i].empId, deleteEmpId) == 0) {
                pos = i;
                break;
            }
        }

        if (pos == -1) {
            printf("KHONG tim thay nhan vien co ma %s. Nhap lai!\n", deleteEmpId);
            continue;
        }

        break;  
    }

    
    for (int i = pos; i < (*n) - 1; i++) {
        list[i] = list[i + 1];
    }
    (*n)--;

    printf("Xoa nhan vien %s thanh cong.\n", deleteEmpId);
}


