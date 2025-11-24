#include<stdio.h>
#include<string.h>

struct Employee{
	char empId[20];
	char name[50];
	char position[15];
	double baseSalary;
	int workDay = 0 ; 
	
};
struct timesheet{
	char logId[20];
	char empAccID[20];
	char date[20];
	char status[10];
	
};
void bubblesortmenu(){
	printf("1.Tang dan\n");
	printf("2. Giam dan\n");
}
void showmenu(){
	printf("\n-----------MENU-------------\n");
	printf("1. Them nhan vien moi\n");
	printf("2. cap nhat ho so\n");
	printf("3. Xoa nhan vien\n");
	printf("4. Hien thi danh sach\n");
	printf("5. Tim kiem\n");
	printf("6. Sap xep danh sach\n");
	printf("9. Thoat chuong trinh\n");
	printf("\n-----------------------------\n")
}



int main(){
    int choice;
	struct Employee person[100];
	int size; 
	printf("nhap so nhan vien ma ban muon nhap ban dau\n");
	scanf("%d", &size );
	getchar();
	
	
	for (int i = 0 ; i < size ; i++){
		// base ban dau
		printf("\n-------------------------------\n");
		printf("Nhap TEN nhan vien thu %d : ", i + 1  );
		fgets(person[i].name , sizeof(person[i].name),stdin );
		person[i].name[strcspn(person[i].name,"\n")] = '\0';
		
		printf("Nhap CHUC VU cua nhan vien thu %d : " , i + 1  );
		fgets(person[i].position , sizeof(person[i].position),stdin );
		person[i].position[strcspn(person[i].position , "\n")] = '\0';
		
		printf("Nhap LUONG cua nhan vien thu %d : ", i + 1  );
		scanf("%lf" , &person[i].baseSalary );
		getchar();
		
		printf("Nhap ID cua nhan vien thu %d : " , i + 1  );
		fgets(person[i].empId , sizeof(person[i].empId),stdin);
		person[i].empId[strcspn(person[i].empId,"\n")] = '\0';
	//	printf("\n-------------------------------\n");	
		
		printf("nhap NGAY LAM nhan vien %d : " , i + 1  );
	    scanf("%d",&person[i].workDay );
	    getchar();
	    printf("\n-------------------------------\n");	
	}
	
	do { 
     	showmenu();
     	printf("\n lua chon cua ban la gi?\n");
    
	       scanf("%d", &choice );
	       getchar();
    
    switch(choice){
    	case 1 :
    		     
    			for (int i = size ; i < size + 1 ; i++){
    				// them nhan vien moi thi bat dau tu size 
	             	printf("\n-------------------------------\n");
	              	printf("Nhap TEN nhan vien thu %d : ", size + 1  );
		            fgets(person[size].name , sizeof(person[size].name),stdin );
		            person[size].name[strcspn(person[size].name,"\n")] = '\0';
		
	             	printf("Nhap CHUC VU cua nhan vien thu %d : " , size + 1  );
		            fgets(person[size].position , sizeof(person[size].position),stdin );
		            person[size].position[strcspn(person[size].position , "\n")] = '\0';
		
		            printf("Nhap LUONG cua nhan vien thu %d : ", size + 1  );
		            scanf("%lf" , &person[size].baseSalary );
		            getchar();
		
	               	printf("Nhap ID cua nhan vien thu %d : " , size + 1  );
	             	fgets(person[size].empId , sizeof(person[size].empId),stdin);
	            	person[size].empId[strcspn(person[size].empId,"\n")] = '\0';
	            		
	            	
	            	printf("nhap NGAY LAM nhan vien %d : " , size + 1  );
	             //	printf("nhap NGAY LAM %d : " , i + 1  );
	                scanf("%d",&person[i].workDay );
	                getchar();
	            	printf("\n-------------------------------\n");	
	            	printf("\n-------------------------------\n");
		
               	}
               size++;
               break;
     case 2:
     {
    char targetID[50];
    int found = 0;

    printf("\nNhap ID nhan vien ban muon cap nhat: ");
    fgets(targetID, sizeof(targetID), stdin);
    targetID[strcspn(targetID, "\n")] = '\0';

    for (int i = 0; i < size; i++) {
        if (strcmp(person[i].empId, targetID) == 0) {
            found = 1;

            printf("\n--- CAP NHAT HO SO ---\n");

            // ten
            printf("Nhap ten moi  ");
            char newName[50];
            fgets(newName, sizeof(newName), stdin);
            newName[strcspn(newName, "\n")] = '\0';
            if (strlen(newName) > 0)
                strcpy(person[i].name, newName); // khong nhap gi giu nguyen

          // chuc vu
            printf("Nhap chuc vu moi  ");
            char newPos[50];
            fgets(newPos, sizeof(newPos), stdin);
            newPos[strcspn(newPos, "\n")] = '\0';
            if (strlen(newPos) > 0)
                strcpy(person[i].position, newPos);  // khong nhap gi giu nguyen

            // luong
            printf("Nhap luong moi : ");
            double newSalary;
            scanf("%lf", &newSalary);  // -1 giu nguyen  , nhap khong cap nhat la -1 thi la khong dung voi if thi khong doi
            getchar();
            if (newSalary >= 0)
                person[i].baseSalary = newSalary;

            // ID
            printf("Nhap ID moi : ");   // khong nhap gi giu nguyen
            char newID[50];
            fgets(newID, sizeof(newID), stdin);
            newID[strcspn(newID, "\n")] = '\0';
            if (strlen(newID) > 0)
                strcpy(person[i].empId, newID);

            printf("\nCap nhat thanh cong!\n\n");
            break;
        }
    }

    if (!found) {
        printf("\nKhong tim thay ID nhan vien!\n");
    }
}
break;
          
       case 3: 
        {
        char targetter[50];
        int found = 0;

        printf("\n Nhap ID vao day de sa thai nguoi do!\n");
        fgets(targetter, 50, stdin);
        targetter[strcspn(targetter, "\n")] = '\0';

        for (int i = 0; i < size; i++){
           if (strcmp(person[i].empId, targetter) == 0){ // compare
              for (int j = i; j < size - 1; j++){
                  person[j] = person[j + 1];
              }
                  size--;
                  found = 1;
                  printf("\nDA SA THAI nhan vien %s co ID %s\n", person[i].name,targetter);
                break;
            }
          }

            if (!found)
            printf("Khong tim thay ID!\n");
            }
            break;

	    case 4:

	    	// print ra thoi
               printf("\n===== DANH SACH =====\n");

              if (size == 0) {
                 printf("khong co nhan vien!\n");
                 break;
            }

                for (int i = 0; i < size; i++) {
                   printf("\n----------------------------\n");
                   printf("\nNhan vien thu %d:\n", i + 1);
                   printf("Ten: %s\n", person[i].name);
                   printf("Chuc vu: %s\n", person[i].position);
                   printf("Luong: %.2lf\n", person[i].baseSalary);
                   printf("ID: %s\n", person[i].empId);
                   printf("----------------------------\n");
                   }
            break;
            
        case 5 : 
		             {
                       char targetter[50];
                       int found = 0;

                        printf("\n Nhap ID vao day de TIM NGUOI DO!\n");
                        fgets(targetter, 50, stdin);
                        targetter[strcspn(targetter, "\n")] = '\0';

                     for (int i = 0; i < size; i++){
                         if (strcmp(person[i].empId, targetter) == 0){ // compare
                             for (int j = i; j < size - 1; j++){
                                 person[j] = person[j + 1];
                      }
                               size--;
                               found = 1;
                               printf("\n----------------------------\n");
                     
					           printf("\n NHAN VIEN %s \n ID : %s \n LUONG cua nhan vien %.2lf \n CHU VU cua nhan vien %s \n  \n", person[i].name,targetter ,person[i].baseSalary , person[i].position );
				            	printf("\n----------------------------\n");
                                break;
                    }
                        }

                       if (!found)
                               printf("Khong tim thay ID!\n");
                          }
                             break;       
           
           
        case 6 : 
                int bubblechoice ; // chon tang dan giam dan
                if (size == 1 ){
                	printf("\n \nnhap truoc da!\n");
                	break;
				}
                bubblesortmenu();
                printf("nhap lua chon cua ban : ");
                scanf("%d" , &bubblechoice );
                getchar(); 
                
                // vi person indexer khong phai char , int , float , nen dung struct thi MOI NHAN DUOC TEMP!!!!
                if (bubblechoice == 1 ){
                	printf("da chon tang dan \n ");
                	for ( int times = 0 ; times < size  - 1 ; times++ ){
                		for (int indexer = 0 ; indexer < size - times - 1 ; indexer++){
                			if (person[indexer].baseSalary > person[indexer + 1 ].baseSalary){
                				struct Employee temp = person[indexer];
                				person[indexer] = person[indexer + 1];
                				person[indexer + 1 ] = temp;
							}
						}
					}
				}
				if (bubblechoice == 2 ){
					printf("da chon giam dan \n ");
                	for ( int times = 0 ; times < size  - 1 ; times++ ){
                		for (int indexer = 0 ; indexer < size - times - 1 ; indexer++){
                			if (person[indexer].baseSalary < person[indexer + 1 ].baseSalary){
                				struct Employee temp = person[indexer];
                				person[indexer] = person[indexer + 1];
                				person[indexer + 1 ] = temp;
							}
						}
					}
				}
                break;
        
	         } //switch 
       }  while(choice != 9 );  // menu loop
} // int main

