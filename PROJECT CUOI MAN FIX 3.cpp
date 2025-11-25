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

void deleteEmployeev2(struct Employee list[], int *n) {
    char deleteEmpId[20];
    int pos = -1;

         if (*n == 0) {
             printf("DANH SACH RONG! KHONG THE XOA!\n");
             return;
        }

   
          while (1) {
          printf("MA NHAN VIEN MUON XOA: ");
          fgets(deleteEmpId, 20, stdin);
          deleteEmpId[strcspn(deleteEmpId, "\n")] = '\0';

    // validate trong
         if (strlen(deleteEmpId) == 0) {
            printf("Ma nhan vien khong duoc de trong.\n");
             continue;
           }

    // exist?
        pos = -1;
        for (int i = 0; i < *n; i++) {
         if (strcmp(list[i].empId, deleteEmpId) == 0) {
             pos = i;
             break;
          }
       }

       if (pos == -1) {
            printf("KHONG tim thay nhan vien co ma %s. Nhap lai!\n", deleteEmpId);
           continue;  // NHAP MA
         }

         break;  // 
    }

    // confirm? 
    int confirm;
    while (1) {
        printf("Ban co chac chan muon XOA nhan vien %s? (1 = Co .  2 = Khong): ",deleteEmpId);
        if (scanf("%d", &confirm) != 1) {
            while (getchar() != '\n');
            printf("Lua chon khong hop le!\n");
            continue;
        }
        while (getchar() != '\n');

        if (confirm == 1) {
            // ======= xoa nv =======
            for (int i = pos; i < (*n) - 1; i++) {
                list[i] = list[i + 1];
            }
            (*n)--;

            printf("xoa nhan vien %s thanh cong.\n", deleteEmpId);
            return;

        } else if (confirm == 2) {
            printf(" thao tac xoa da duoc huy.\n");
            return;

        } else {
            printf("khong hop le.... NHAP LAI\n");
        }
    }
}
void addEmployee(struct Employee list[], int *n){
    char id[20];

    // nhap ma nhan vien 
    while (1) {
        printf("Nhap ma nhan vien: ");
        fgets(id,20,stdin);
        id[strcspn(id,"\n")] = '\0';

        if (strlen(id) == 0) {
            printf("Ma nhan vien khong duoc trong!\n");
            continue;
        }

        int flag = 0;
        for (int i = 0; i < *n; i++) {
            if (strcmp(list[i].empId, id) == 0) {
                flag = 1;   // 1 = ton tai
                break;
            }
        }
        if (flag == 1) {
            printf("Ma nhan vien da ton tai! Nhap lai.\n");
            continue;
        }

        break; 
    }

    strcpy(list[*n].empId, id);

    // kiem tra nhap ten
    while (1) {
        printf("Ten nhan vien: ");
        fgets(list[*n].name, 50, stdin);
        list[*n].name[strcspn(list[*n].name,"\n")] = '\0';

        if (strlen(list[*n].name) == 0) {
            printf("Ten nhan vien khong duoc de trong!\n");
            continue;
        }
        break;
    }

    // kiem tra nhap chuc vu
    while (1) {
        printf("Chuc vu nhan vien: ");
        fgets(list[*n].position, 15, stdin);
        list[*n].position[strcspn(list[*n].position,"\n")] = '\0';

        if (strlen(list[*n].position) == 0) {
            printf("Chuc vu khong duoc de trong!\n");
            continue;
        }
        break;
    }

    // ktra nhap luong 
    while (1) {
        printf("Luong co ban: ");
        if (scanf("%lf", &list[*n].baseSalary) != 1) {
            printf("Nhap sai dinh dang!\n");
            while (getchar() != '\n'); // Xoa toan bo buffer
            continue;
        }
        if (list[*n].baseSalary <= 0) {
            printf("Luong khong hop le! Nhap lai.\n");
            continue;
        }
        break;
    }

    // cho phep nhap ngay cong
    while (1) {
        printf("Nhap ngay cong: ");
        if (scanf("%d", &list[*n].workDay) != 1) {
            printf("Nhap sai dinh dang!\n");
            getchar();
            continue;
        }

        if (list[*n].workDay < 0 || list[*n].workDay > 31) {
            printf("Ngay cong phai tu 0 den 31!\n");
            continue;
        }

        if(list[*n].workDay == 0){
        	printf("Khong duoc de ngay cong trong! Nhap lai");
        	continue;
		}
		break; 
    }

    (*n)++;

    printf("Them nhan vien thanh cong!\n");
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
        printf("Nhap luong co ban moi: ");
        if (scanf("%lf", &list[pos].baseSalary) != 1) {
            printf("Dinh dang sai! Hay nhap so.\n");
            while (getchar() != '\n');
            continue;
        }

        if (list[pos].baseSalary <= 0) {
            printf("Luong phai lon hon 0!\n");
            continue;
        }

        while (getchar() != '\n'); 
        break;
    }

    // ===== CẬP NHẬT NGÀY CÔNG =====
    while (1) {
        printf("Nhap ngay cong moi: ");
        if (scanf("%d", &list[pos].workDay) != 1) {
            printf("Dinh dang sai! Hay nhap so.\n");
            while (getchar() != '\n');
            continue;
        }

        if (list[pos].workDay < 0 || list[pos].workDay > 31) {
            printf("Ngay cong phai tu 0 - 31!\n");
            continue;
        }

        while (getchar() != '\n');
        break;
    }

    printf("Cap nhat thong tin thanh cong!\n");
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
//--------------------------------------
int main(){
	struct Employee list[100] = {
		{"NV01", "Nguyen Van A", "Truong phong", 5000000, 10},
		{"NV02", "Tran Thi B", "Nhan vien", 7000000, 12},
		{"NV03", "Le Van C", "Ke toan", 6000000, 8}
	};
	int n = 3; 
	int choice;

	do{
		printf("\n =============================================\n");
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

		printf("Moi ban nhap lua chon: ");
		scanf("%d",&choice);
		getchar(); 

		switch(choice){
			case 1:
				addEmployee(list,&n);
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


