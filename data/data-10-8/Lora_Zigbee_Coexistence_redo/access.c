#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

/*
typedef int (*sqlite3_callback){
	void*,   //data provided in the 4th argument of sqlite3_exec()
	int, 	//The number of columns in row
	char**	//An array of strings representing fields in the rowstderr
	char**	//An array of strings representing column names
}
*/
int prr[100][100] = {0};


static int callback(void *data, int argc, char **argv, char **azColName){
	int i;
	//fprintf(stderr, "%s\n", (const char*)data);
	//for(i=0; i<argc; i++){
		//printf("%s = %s\n", azColName[i], argv[i] ? argv[i]: "NULL");
	//printf("%d %d",atoi(argv[0]), atoi(argv[1]));
	//}
	prr[atoi(argv[0])-100][atoi(argv[1])-100]++;
	//printf("\n");
	return 0;
}


int main(int argc, char const *argv[])
{
	/* code */
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;
	char sql[] = "SELECT * from topology";
	const char* data = "Callback function called";

	/* Open database */
	rc = sqlite3_open("sf9_1600khz", &db);
	if( rc ){
	  fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
	  exit(0);
	}else{
	  fprintf(stderr, "Opened database successfully\n");
	}

	/* Create SQL statement */
	//sql = "SELECT * from topology";

	/* Execute SQL statement */
	rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
	if( rc != SQLITE_OK ){
	  fprintf(stderr, "SQL error: %s\n", zErrMsg);
	  sqlite3_free(zErrMsg);
	}else{
	  fprintf(stdout, "Operation done successfully\n");
	}
	sqlite3_close(db);


	for(int i=0;i<100;i++){
		for(int j=0;j<100;j++){
			if(prr[i][j]!=0){
				//printf("%d %d %d\n",i+100,j+100,prr[i][j]);
				printf("%d\n",prr[i][j]);
			}
		}
	}


	return 0;
}